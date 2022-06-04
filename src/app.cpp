#include "app.h"

namespace dd
{
	AppExitReason App::Init()
	{
		if (SDL_Init(SDL_INIT_EVERYTHING))
		{
			return APP_EXIT_SDL_INIT_ERROR;
		}

		if (this->videoState->Init() != VIDEO_INIT_NO_ERROR)
		{
			return APP_EXIT_VIDEO_INIT_ERROR;
		}

		return APP_EXIT_NO_ERROR;
	}

	void App::Teardown()
	{
		this->videoState->Teardown();
		SDL_Quit();
	}

	AppExitReason App::Run(i32 argc, char **argv)
	{
		AppExitReason exitReason = this->Init();
		if (exitReason != APP_EXIT_NO_ERROR) return exitReason;

		i32 inputResult;
		i32 outputResult;

		while (true)
		{
			this->ticks = SDL_GetTicks64();
			inputResult = this->sdlEventHandler->Handle();
			if (inputResult != 0)
			{
				if (inputResult != 1)
				{
					exitReason = APP_EXIT_WINDOW_CLOSED;
				}
				break;
			}

			outputResult = this->videoState->Update(this->ticks);
			if (outputResult != 0)
			{
				exitReason = APP_EXIT_UNDEFINED;
				break;
			}
		}

		this->Teardown();
		return exitReason;
	}
}
