#include "app.hpp"

namespace didi
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

		while (true)
		{
			this->ticks = SDL_GetTicks64();
			this->sdlEventHandler->Handle(&quit);

			if (this->quit)
			{
				break;
			}

			this->videoState->Update(this->ticks);
		}

		this->Teardown();
		return 0;
	}
}
