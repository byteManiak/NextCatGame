#pragma once

#include <SDL.h>
#include <string>
#include <unordered_map>
#include "common.h"

namespace dd
{
	class TextureManager;

	class Texture
	{
	private:
		SDL_Texture *texture = nullptr;
		friend class TextureManager;

	public:
		Texture(SDL_Renderer *renderer, std::string path);
		~Texture();
	};


	class TextureManager
	{
	private:
		SDL_Renderer *renderer;
		std::unordered_map<std::string, Texture*> textures;

#if defined(DEBUG)
		uint64_t debugTextureCounter = 1;
#endif

		/**
		 * @brief Make a default 2x2 Source engine-style "missing texture"
		 */
		SDL_Texture* MakeDefaulTexture();

	public:
		TextureManager(SDL_Renderer *renderer);

		/**
		 * @brief Load a texture from the given path, and save it internally with a name identifier
		 * 
		 * @param path Path to load the texture from
		 * @param name Name identifier for the texture
		 */
		void LoadTexture(std::string path, std::string name);

		/**
		 * @brief Draw a texture at the specific coordinates and sizes
		 * 
		 * @param name Name identifier of the texture
		 * @param x Base X coordinate to draw the texture at
		 * @param y Base Y coordinate to draw the texture at
		 * @param w Width of the draw output
		 * @param h Height of the draw output
		 */
		void DrawTexture(std::string name, i32 x, i32 y, i32 w, i32 h);

		/**
		 * @brief Delete a texture object from memory
		 * 
		 * @param name Name identifier of the texture
		 */
		void DeleteTexture(std::string name);

#if defined(DEBUG)
		/**
		 * @brief With a debug build, texture names are highlighted by an
		 *        ImGui window with the texture's name as the title.
		 *        In order for ImGui to draw windows with the same title,
		 *        it needs to append "##X" at the end of each window name,
		 *        where X is a unique integer >= 1. A counter is held in the
		 *        texture manager which keeps track of this X value. This is
		 *        reset on every frame so it does not overflow (unlikely as it may be).
		 */
		void ResetDebugTextureCounter();
#endif
	};
}