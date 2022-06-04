#include "input.hpp"

namespace didi::input
{
	void SDLEventHandler::Handle(bool *quit)
	{
		while (SDL_PollEvent(&this->event))
		{
			switch (this->event.type)
			{
				case SDL_QUIT:
					*quit = true;
					break;
				default:
					break;
			}
		}
	}
}
