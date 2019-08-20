#ifndef OBSERVER_H
#define OBSERVER_H

enum class characteristic;

class CharacterizationObservable;

class Observer
{
public:
    virtual void handle_event(characteristic changed_characteristic, int delta) = 0;

    virtual ~Observer() = default;
};

#endif // OBSERVER_H
