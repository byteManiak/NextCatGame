#ifndef INPUT_HPP
#define INPUT_HPP

#include <SDL_events.h>

namespace didi::input
{
	class SDLEventHandler
	{
	private:
		SDL_Event event;

	public:
		void Handle(bool*);
	};
}

#endif
