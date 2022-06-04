#ifndef APP_HPP
#define APP_HPP

#include <SDL.h>
#include "video.hpp"
#include "input.hpp"

namespace didi
{
	class App
	{
	private:
		video::State* videoState = new video::State();
		input::SDLEventHandler* sdlEventHandler = new input::SDLEventHandler();
		u64 ticks = 0;

		bool quit = false;
		i32 Init();
		void Teardown();

	public:
		i32 Run(i32, char**);
	};
}


#endif
