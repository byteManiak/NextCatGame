#pragma once

#include <SDL.h>
#include "video.h"
#include "input.h"

namespace dd
{
	class App
	{
	private:
		VideoState* videoState = new VideoState();
		SDLEventHandler* sdlEventHandler = new SDLEventHandler();
		u64 ticks = 0;

		bool quit = false;
		i32 Init();
		void Teardown();

	public:
		i32 Run(i32, char**);
	};
}
