#include "event.h"

namespace dd
{
	std::unordered_map<SDL_EventType, std::vector<EventObject*>> EventHandler::eventListeners;

	void EventHandler::AddEventListener(EventObject *object, SDL_EventType eventType)
	{
		if (eventListeners.find(eventType) == eventListeners.end())
		{
			eventListeners[eventType] = std::vector<EventObject*>();
		}

		eventListeners[eventType].push_back(object);
	}

	void EventHandler::Handle()
	{
		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			for (auto &i : eventListeners[(SDL_EventType)event.type]) i->OnEvent(event);
		}
	}
}