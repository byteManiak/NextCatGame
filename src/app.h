#pragma once

#include <SDL.h>
#include "video.h"
#include "input.h"

namespace dd
{
	enum AppExitReason {
		APP_EXIT_NO_ERROR,
		/* Errors during initialization */
		APP_EXIT_SDL_INIT_ERROR,
		APP_EXIT_VIDEO_INIT_ERROR,
		APP_EXIT_INPUT_INIT_ERROR,
		/* Events triggering game exit */
		APP_EXIT_WINDOW_CLOSED,

		APP_EXIT_IO_ERROR,
		APP_EXIT_UNDEFINED,
	};

	class App
	{
	private:
		VideoState* videoState = new VideoState();
		InputHandler* inputHandler = new InputHandler();
		u64 ticks = 0;

		AppExitReason Init();
		void Teardown();

	public:
		AppExitReason Run(i32, char**);
	};
}
