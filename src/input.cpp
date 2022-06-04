#include "input.h"

namespace dd
{
	InputHandler::InputHandler()
	{
		EventHandler::AddEventListener(this, SDL_QUIT);
		EventHandler::AddEventListener(this, SDL_MOUSEMOTION);
	}

	bool InputHandler::IsPointerInWindow(i32 windowWidth, i32 windowHeight) {
		return (
			(this->pointerLocation.x >= 0 && this->pointerLocation.x < (f32) windowWidth)
			&& (this->pointerLocation.y >= 0 && this->pointerLocation.y < (f32) windowHeight)
		);
	}

	void InputHandler::OnEvent(SDL_Event event)
	{
		switch (event.type)
		{
			case SDL_QUIT:
				this->handlerResult = INPUT_HANDLER_RESULT_QUIT;
				return;
			case SDL_MOUSEMOTION:
				this->pointerLocation = {
					(f32) event.motion.x,
					(f32) event.motion.y,
				};
				break;
			default:
				break;
		}

		this->handlerResult = INPUT_HANDLER_RESULT_CONTINUE;
	}

	i32 InputHandler::SetCaptureMouse(bool captured) {
		return SDL_CaptureMouse(captured ? SDL_TRUE : SDL_FALSE);
	}

	InputHandlerResult InputHandler::Handle() {
		return handlerResult;
	}
}
