#include "video.hpp"


namespace didi
{
	namespace video
	{
		i32 State::InitWindowAndRenderer()
		{
			SDL_Window* newWindow = SDL_CreateWindow(
				"NextCatGame",
				SDL_WINDOWPOS_CENTERED,
				SDL_WINDOWPOS_CENTERED,
				640,
				480,
				SDL_WINDOW_SHOWN
			);

			if (!newWindow)
			{
				return 1;
			}

			SDL_Renderer* newRenderer = SDL_CreateRenderer(newWindow, -1, SDL_RENDERER_ACCELERATED);

			if (!newRenderer)
			{
				return 2;
			}

			this->window = newWindow;
			this->renderer = newRenderer;
			return 0;
		}

		i32 State::Init()
		{
			return this->InitWindowAndRenderer();
		}

		void State::Update(u64 ticks)
		{
			if (ticks - this->lastUpdated > (1000 / this->maxFps))
			{
				SDL_SetRenderDrawColor(this->renderer, 0, 0, 0, 0);
				SDL_RenderClear(this->renderer);

				SDL_SetRenderDrawColor(this->renderer, 0, 0xff, 0xff, 0);
				u64 theTicks = ticks;
				for (u8 i = 0; i < 64; i += 1)
				{
					if (theTicks & 0x1)
					{
						SDL_FRect rect = { 640 - 4 - (i * 4.f), 480 - 4, 4.f, 4.f };
						SDL_RenderFillRectF(this->renderer, &rect);
					}
					theTicks >>= 1;
				}

				SDL_RenderPresent(renderer);
				this->lastUpdated = ticks;
			}
		}

		void State::Teardown()
		{
			SDL_DestroyRenderer(this->renderer);
			SDL_DestroyWindow(this->window);
		}
	}
}
