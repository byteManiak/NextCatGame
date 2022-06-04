#pragma once

#include <SDL_events.h>
#include "common.h"

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
