#ifndef VIDEO_HPP
#define VIDEO_HPP

#include <SDL_render.h>
#include "common.hpp"

namespace didi::video
{
	class State
	{
	private:
		SDL_Window* window = nullptr;
		SDL_Renderer* renderer = nullptr;
		u64 lastUpdated = 0;
		i32 InitWindowAndRenderer();

	public:
		const u8 maxFps = 30;
		i32 Init();
		void Update(u64);
		void Teardown();
	};
}

#endif
