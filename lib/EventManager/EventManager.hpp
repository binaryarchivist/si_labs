#ifndef EVENTMANAGER_HPP
#define EVENTMANAGER_HPP

enum Event
{
    EVENT_NONE = 0,
    INCREMENT_EVENT = 1,
    DECREMENT_EVENT = 2,
    RESET_EVENT = 4,
    TOGGLE_EVENT = 8
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
    void triggerEvent(byte eventType, long count = 0);
};

#endif
