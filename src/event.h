#pragma once

#include <SDL.h>
#include <unordered_map>
#include <vector>

namespace dd
{
	using std::unordered_map;
	using std::vector;

	class EventObject
	{
	public:
		virtual void OnEvent(SDL_Event event) = 0;
	};

	class EventHandler
	{
	private:
		static unordered_map<SDL_EventType, vector<EventObject*>> eventListeners;

	public:
		static void AddEventListener(EventObject *object, SDL_EventType eventType);
        static void Handle();
	};
}