#pragma once

#include <SDL_events.h>
#include "common.h"

namespace dd
{
	enum InputHandlerResult {
		INPUT_HANDLER_RESULT_CONTINUE,
		INPUT_HANDLER_RESULT_QUIT,
	};

	class InputHandler
	{
	private:
		SDL_Event event;

	public:
		SDL_FPoint pointerLocation;
		bool IsPointerInWindow(i32, i32);
		i32 SetCaptureMouse(bool);

		InputHandlerResult Handle();
	};
}
