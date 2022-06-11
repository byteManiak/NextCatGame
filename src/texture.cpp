#include "texture.h"

#include <SDL_image.h>
#include "log.h"

namespace dd
{
	Texture::Texture(SDL_Renderer *renderer, std::string path)
	{
		SDL_Surface *surface = IMG_Load(path.c_str());
		this->texture = SDL_CreateTextureFromSurface(renderer, surface);

		SDL_FreeSurface(surface);
	}

	Texture::~Texture()
	{
		SDL_DestroyTexture(this->texture);
	}


	TextureManager::TextureManager(SDL_Renderer *renderer) : renderer{renderer} {}

	SDL_Texture* TextureManager::MakeDefaulTexture()
	{
		u8 defaultTexturePixels[] = {
			0, 0, 0,     255, 0, 255,
			255, 0, 255, 0, 0, 0
		};

		SDL_Surface *texData = SDL_CreateRGBSurfaceWithFormatFrom(defaultTexturePixels, 2, 2, 24, 6, SDL_PIXELFORMAT_RGB24);
		SDL_Texture *texture = SDL_CreateTextureFromSurface(this->renderer, texData);
		SDL_FreeSurface(texData);

		return texture;
	}

	void TextureManager::LoadTexture(std::string path, std::string name)
	{
		Texture *tex = new Texture(this->renderer, path);
		if (!tex->texture)
		{
			Log(LOG_ERROR, "Texture", "Could not load texture \"" + path + "\"");
			tex->texture = MakeDefaulTexture();
		}

		this->textures[name] = tex;
	}

	void TextureManager::DrawTexture(std::string name, i32 x, i32 y, i32 w, i32 h)
	{
		Texture *tex = this->textures[name];
		if (tex)
		{
			SDL_Texture *t = tex->texture;
			const SDL_Rect r = {x, y, w, h};
			SDL_RenderCopy(this->renderer, t, NULL, &r);
		}
	}

	void TextureManager::DeleteTexture(std::string name)
	{
		delete(this->textures[name]);
		this->textures.erase(name);
	}
}