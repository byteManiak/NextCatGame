#include "event.h"

namespace dd
{
	std::unordered_map<SDL_EventType, std::vector<std::function<void(SDL_Event)>>> EventHandler::eventListeners;

	void EventHandler::AddEventListener(EventObject *object, SDL_EventType eventType)
	{
		if (eventListeners.find(eventType) == eventListeners.end())
		{
			eventListeners[eventType] = std::vector<std::function<void(SDL_Event)>>();
		}

		eventListeners[eventType].push_back(std::bind(&EventObject::OnEvent, object, std::placeholders::_1));
	}

	void EventHandler::Handle()
	{
		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			for (auto &&f : eventListeners[(SDL_EventType)event.type]) f(event);
		}
	}
}