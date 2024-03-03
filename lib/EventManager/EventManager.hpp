#ifndef EVENTMANAGER_HPP
#define EVENTMANAGER_HPP

enum Event
{
    EVENT_NONE,
    INCREMENT_EVENT,
    DECREMENT_EVENT,
    RESET_EVENT,
    TOGGLE_EVENT
};

class EventManager
{
public:
    void triggerEvent(Event eventType, long count = 0);
};

#endif
