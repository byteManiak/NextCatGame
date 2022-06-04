#pragma once
#include <SDL_render.h>
#include "common.h"

namespace dd
{
	enum VideoInitError {
		VIDEO_INIT_NO_ERROR,
		VIDEO_INIT_CREATE_WINDOW,
		VIDEO_INIT_CREATE_RENDERER
	};

	class VideoState
	{
	private:
		SDL_Window* window = nullptr;
		SDL_Renderer* renderer = nullptr;
		u64 lastUpdated = 0;
		VideoInitError InitWindowAndRenderer();

	public:
		const u8 maxFps = 30;
		VideoInitError Init();
		i32 Update(u64);
		void Teardown();
	};
}
