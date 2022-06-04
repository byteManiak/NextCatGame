#pragma once

#include <SDL_render.h>
#include "common.hpp"

namespace dd
{
	class VideoState
	{
	private:
		SDL_Window* window = nullptr;
		SDL_Renderer* renderer = nullptr;
		u64 lastUpdated = 0;
		i32 InitWindowAndRenderer();

	public:
		const u8 maxFps = 30;
		i32 Init();
		i32 Update(u64);
		void Teardown();
	};
}
