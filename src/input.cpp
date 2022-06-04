#include "input.h"

namespace dd
{
	i32 SDLEventHandler::Handle()
	{
		while (SDL_PollEvent(&this->event))
		{
			switch (this->event.type)
			{
				case SDL_QUIT:
					return 1;
				case SDL_MOUSEMOTION:
					break;
				default:
					break;
			}
		}

		return 0;
	}
}
