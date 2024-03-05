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

enum Tasks
{
    NONE = 0,
    IDLE = 1,
    DELAY = 2,
    RESET = 4,
    TOGGLE = 8
};

class EventManager
{
public:
    void triggerEvent(Event eventType, long count = 0);
};

#endif
