#ifndef IOBSERVER_H
#define IOBSERVER_H

enum class characteristic;

class CharacterizationObservable;

class IObserver
{
public:
    virtual void handle_event(characteristic changed_characteristic, int delta) = 0;

    virtual ~IObserver() = default;
};

#endif // IOBSERVER_H
