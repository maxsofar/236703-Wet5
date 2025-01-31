//
// Created by Max on 31/01/2025.
//

#ifndef WET_5_OBSERVER_H
#define WET_5_OBSERVER_H

template <class T>
class Observer {
public:
    Observer() = default;
    virtual void handleEvent(const T&) = 0;
};

#endif //WET_5_OBSERVER_H
