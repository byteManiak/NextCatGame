#pragma once

#include <SDL_events.h>
#include "common.h"
#include "event.h"

namespace dd
{
	enum InputHandlerResult {
		INPUT_HANDLER_RESULT_CONTINUE,
		INPUT_HANDLER_RESULT_QUIT,
	};

	class InputHandler : public EventObject
	{
	private:
		InputHandlerResult handlerResult;

	public:
		InputHandler();
		void OnEvent(SDL_Event event);

		SDL_FPoint pointerLocation;
		bool IsPointerInWindow(i32, i32);
		i32 SetCaptureMouse(bool);

		InputHandlerResult Handle();
	};
}
