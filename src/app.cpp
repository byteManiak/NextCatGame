#include "app.h"

namespace dd
{
	AppExitReason App::Init()
	{
		if (SDL_Init(SDL_INIT_EVERYTHING))
		{
			return APP_EXIT_SDL_INIT_ERROR;
		}

		if (this->videoState->Init() != VIDEO_INIT_OK)
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
			inputResult = this->inputHandler->Handle();
			if (inputResult != INPUT_HANDLER_RESULT_CONTINUE)
			{
				if (inputResult != INPUT_HANDLER_RESULT_QUIT)
				{
					exitReason = APP_EXIT_IO_ERROR;
				}
				break;
			}

			outputResult = this->videoState->Update(this->ticks, this->inputHandler);
			if (outputResult != 0)
			{
				exitReason = APP_EXIT_IO_ERROR;
				break;
			}
		}

		this->Teardown();
		return exitReason;
	}
}
