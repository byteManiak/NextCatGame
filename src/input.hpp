#ifndef INPUT_HPP
#define INPUT_HPP

#include <SDL_events.h>
#include "common.hpp"

namespace dd
{
	class SDLEventHandler
	{
	private:
		SDL_Event event;

	public:
		i32 Handle();
	};
}

#endif
