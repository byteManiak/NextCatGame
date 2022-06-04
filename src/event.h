#pragma once

#include <SDL.h>
#include <functional>
#include <unordered_map>
#include <vector>

namespace dd
{
	using std::unordered_map;
	using std::vector;
	using std::function;

	class EventObject
	{
	public:
		virtual void OnEvent(SDL_Event event) = 0;
	};

	class EventHandler
	{
	private:
		static unordered_map<SDL_EventType, vector<function<void(SDL_Event)>>> eventListeners;

	public:
		static void AddEventListener(EventObject *object, SDL_EventType eventType);
        static void Handle();
	};
}