#ifndef OBSERVER_H
#define OBSERVER_H

class CharacterizationObservable;

class Observer
{
public:
    virtual void handle_event(const CharacterizationObservable* o) = 0;
    virtual ~Observer() = default;
};

#endif // OBSERVER_H
