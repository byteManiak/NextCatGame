#include "input.h"

namespace dd
{
	bool InputHandler::IsPointerInWindow(i32 windowWidth, i32 windowHeight) {
		return (
			(this->pointerLocation.x >= 0 && this->pointerLocation.x < (f32) windowWidth)
			&& (this->pointerLocation.y >= 0 && this->pointerLocation.y < (f32) windowHeight)
		);
	}

	InputHandlerResult InputHandler::Handle()
	{
		while (SDL_PollEvent(&this->event))
		{
			switch (this->event.type)
			{
				case SDL_QUIT:
					return INPUT_HANDLER_RESULT_QUIT;
				case SDL_MOUSEMOTION:
					this->pointerLocation = {
						(f32) this->event.motion.x,
						(f32) this->event.motion.y,
					};
					break;
				default:
					break;
			}
		}

		return INPUT_HANDLER_RESULT_CONTINUE;
	}

	i32 InputHandler::SetCaptureMouse(bool captured) {
		return SDL_CaptureMouse(captured ? SDL_TRUE : SDL_FALSE);
	}
}
