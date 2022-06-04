#include "app.hpp"

namespace dd
{
	i32 App::Init()
	{
		if (SDL_Init(SDL_INIT_EVERYTHING))
		{
			return 1;
		}

		if (this->videoState->Init())
		{
			return 2;
		}

		return 0;
	}

	void App::Teardown()
	{
		this->videoState->Teardown();
		SDL_Quit();
	}

	i32 App::Run(i32 argc, char **argv)
	{
		if (this->Init())
		{
			return 1;
		}

		i32 inputResult;
		i32 outputResult;
		i32 exitCode = 0;

		while (true)
		{
			this->ticks = SDL_GetTicks64();
			inputResult = this->sdlEventHandler->Handle();
			if (inputResult != 0)
			{
				if (inputResult != 1)
				{
					exitCode = 2;
				}
				break;
			}

			outputResult = this->videoState->Update(this->ticks);
			if (outputResult != 0)
			{
				exitCode = 3;
				break;
			}
		}

		this->Teardown();
		return exitCode;
	}
}
