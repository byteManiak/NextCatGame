#include "video.h"
#include "log.h"
#include "imgui.h"
#include "imgui_impl_sdl.h"
#include "imgui_impl_sdlrenderer.h"

namespace dd
{
	VideoInitResult VideoState::InitWindowAndRenderer()
	{
		Log(LOG_MESSAGE, "Video", "Creating SDL window");
		SDL_Window* newWindow = SDL_CreateWindow(
			"NextCatGame",
			SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED,
			this->windowWidth,
			this->windowHeight,
			SDL_WINDOW_SHOWN
		);

		if (!newWindow)
		{
			Log(LOG_ERROR, "Video", "Failed to create SDL window");
			return VIDEO_INIT_CREATE_WINDOW_ERROR;
		}

		Log(LOG_MESSAGE, "Video", "Creating SDL renderer");
		SDL_Renderer* newRenderer = SDL_CreateRenderer(newWindow, -1, SDL_RENDERER_ACCELERATED);

		if (!newRenderer)
		{
			Log(LOG_ERROR, "Video", "Failed to create SDL renderer");
			SDL_DestroyWindow(newWindow);
			return VIDEO_INIT_CREATE_RENDERER_ERROR;
		}

		this->window = newWindow;
		this->renderer = newRenderer;

		IMGUI_CHECKVERSION();
		ImGuiContext *context = ImGui::CreateContext();
		if (!context)
		{
			Log(LOG_ERROR, "Video", "Failed to create ImGui context");
			SDL_DestroyRenderer(newRenderer);
			SDL_DestroyWindow(newWindow);
			return VIDEO_INIT_CREATE_IMGUI_CTX_ERROR;
		}

		ImGui_ImplSDL2_InitForSDLRenderer(this->window, this->renderer);
		ImGui_ImplSDLRenderer_Init(this->renderer);

		return VIDEO_INIT_OK;
	}

	VideoInitResult VideoState::Init()
	{
		VideoInitResult result = this->InitWindowAndRenderer();
		SDL_ShowCursor(SDL_DISABLE);
		return result;
	}

	i32 VideoState::Update(u64 ticks, InputHandler* inputHandler)
	{
		if (ticks - this->lastUpdated > (1000 / this->maxFps))
		{
			SDL_SetRenderDrawColor(this->renderer, 0, 0, 0, 0);
			SDL_RenderClear(this->renderer);

			ImGui_ImplSDLRenderer_NewFrame();
			ImGui_ImplSDL2_NewFrame();
			ImGui::NewFrame();

			SDL_SetRenderDrawColor(this->renderer, 0, 0xff, 0xff, 0xff);
			u64 theTicks = ticks;
			for (u8 i = 0; i < 64; i += 1)
			{
				if (theTicks & 0x1)
				{
					SDL_FRect rect = {
						(f32) this->windowWidth - 4 - ((f32) i * 4.f),
						(f32) this->windowHeight - 4, 4.f, 4.f
					};
					SDL_RenderFillRectF(this->renderer, &rect);
				}
				theTicks >>= 1;
			}

			SDL_SetRenderDrawColor(this->renderer, 0xff, 0, 0, 0xff);
			bool isPointerInWindow = inputHandler->IsPointerInWindow(this->windowWidth, this->windowHeight);
			inputHandler->SetCaptureMouse(isPointerInWindow);
			if (isPointerInWindow) {
				SDL_RenderDrawPointF(this->renderer, inputHandler->pointerLocation.x, inputHandler->pointerLocation.y);
				SDL_RenderDrawPointF(this->renderer, inputHandler->pointerLocation.x - 1, inputHandler->pointerLocation.y);
				SDL_RenderDrawPointF(this->renderer, inputHandler->pointerLocation.x + 1, inputHandler->pointerLocation.y);
				SDL_RenderDrawPointF(this->renderer, inputHandler->pointerLocation.x, inputHandler->pointerLocation.y - 1);
				SDL_RenderDrawPointF(this->renderer, inputHandler->pointerLocation.x, inputHandler->pointerLocation.y + 1);
			}

			ImGui::Render();
			ImGui_ImplSDLRenderer_RenderDrawData(ImGui::GetDrawData());
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
