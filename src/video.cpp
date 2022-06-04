#include "video.h"

namespace dd
{
	VideoInitError VideoState::InitWindowAndRenderer()
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
			return VIDEO_INIT_CREATE_WINDOW;
		}

		SDL_Renderer* newRenderer = SDL_CreateRenderer(newWindow, -1, SDL_RENDERER_ACCELERATED);

		if (!newRenderer)
		{
			SDL_DestroyWindow(newWindow);
			return VIDEO_INIT_CREATE_RENDERER;
		}

		this->window = newWindow;
		this->renderer = newRenderer;
		return VIDEO_INIT_NO_ERROR;
	}

	VideoInitError VideoState::Init()
	{
		return this->InitWindowAndRenderer();
	}

	i32 VideoState::Update(u64 ticks)
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

		return 0;
	}

	void VideoState::Teardown()
	{
		SDL_DestroyRenderer(this->renderer);
		SDL_DestroyWindow(this->window);
	}
}
