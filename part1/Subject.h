//
// Created by Max on 31/01/2025.
//

#ifndef WET_5_SUBJECT_H
#define WET_5_SUBJECT_H

#include "Observer.h"
#include "OOP5EventException.h"
#include <vector>

template <class T>
class Subject {
public:
    Subject() = default;
    void notify(const T&);
    void addObserver(Observer<T>&);
    void removeObserver(Observer<T>&);
    Subject<T>& operator+=(Observer<T>&);
    Subject<T>& operator-=(Observer<T>&);
    Subject<T>& operator()(const T&);
private:
    std::vector<Observer<T>*> observers;
};

/*
 * Notify all observers of the subject calling to handleEvent method
 */
template<class T>
void Subject<T>::notify(const T &param)
{
    for (auto observer : observers) {
        observer->handleEvent(param);
    }
}

/*
 * Add an observer to the subject
 * @param observer - the observer to add
 * @throws ObserverAlreadyKnownToSubject - if the observer is already in the subject
 */
template<class T>
void Subject<T>::addObserver(Observer<T> &observer)
{
    if (std::find(observers.begin(), observers.end(), &observer) != observers.end()) {
        throw ObserverAlreadyKnownToSubject();
    }
    observers.push_back(&observer);
}

/*
 * Remove an observer from the subject
 * @param observer - the observer to remove
 * @throws ObserverUnknownToSubject - if the observer is not in the subject
 */
template<class T>
void Subject<T>::removeObserver(Observer<T> &observer)
{
    auto it = std::find(observers.begin(), observers.end(), &observer);
    if (it == observers.end()) {
        throw ObserverUnknownToSubject();
    }
    observers.erase(it);
}

/*
 * Add an observer to the subject (using addObserver method)
 * @param observer - the observer to add
 * @return the subject
 * @throws ObserverAlreadyKnownToSubject - if the observer is already in the subject
 */
template<class T>
Subject<T> &Subject<T>::operator+=(Observer<T> &observer)
{
    addObserver(observer);
    return *this;
}

/*
 * Remove an observer from the subject (using removeObserver method)
 * @param observer - the observer to remove
 * @return the subject
 * @throws ObserverUnknownToSubject - if the observer is not in the subject
 */
template<class T>
Subject<T> &Subject<T>::operator-=(Observer<T> &observer)
{
    removeObserver(observer);
    return *this;
}

/*
 * Notify all observers of the subject (using notify method)
 * @param param - the parameter to send to the observers
 * @return the subject
 */
template<class T>
Subject<T> &Subject<T>::operator()(const T &param)
{
    notify(param);
    return *this;
}

#endif //WET_5_SUBJECT_H
