#pragma once
#include <SDL_render.h>
#include "common.h"
#include "input.h"

namespace dd
{
	enum VideoInitResult {
		VIDEO_INIT_OK,
		VIDEO_INIT_CREATE_WINDOW_ERROR,
		VIDEO_INIT_CREATE_RENDERER_ERROR,
	};

	enum VideoUpdateResult {

	};

	class VideoState
	{
	private:
		SDL_Window* window = nullptr;
		SDL_Renderer* renderer = nullptr;
		u64 lastUpdated = 0;
		VideoInitResult InitWindowAndRenderer();

	public:
		const u8 maxFps = 30;
		const i32 windowWidth = 640;
		const i32 windowHeight = 480;
		VideoInitResult Init();
		i32 Update(u64, InputHandler*);
		void Teardown();
	};
}
