#pragma once

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
