#pragma once

#include <SDL.h>
#include "video.h"
#include "input.h"

namespace dd
{
	enum AppExitReason {
		APP_EXIT_NO_ERROR = 0,
		/* Errors during initialization */
		APP_EXIT_SDL_INIT_ERROR,
		APP_EXIT_VIDEO_INIT_ERROR,
		/* Events triggering game exit */
		APP_EXIT_WINDOW_CLOSED,

		APP_EXIT_UNDEFINED
	};

	class App
	{
	private:
		VideoState* videoState = new VideoState();
		SDLEventHandler* sdlEventHandler = new SDLEventHandler();
		u64 ticks = 0;

		bool quit = false;
		AppExitReason Init();
		void Teardown();

	public:
		AppExitReason Run(i32, char**);
	};
}
