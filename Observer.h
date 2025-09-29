/**
 * @file Observer.h
 * @brief Observer pattern implementation for chat room notifications
 * @author Mutombo Kabau
 * @date 29-09-2025
 */

#ifndef OBSERVER_H
#define OBSERVER_H

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Forward declarations
class ChatRoom;

/**
 * @class Observer
 * @brief Abstract observer interface for receiving notifications
 * Role: Observer in Observer pattern
 */
class Observer {
public:
    /**
     * @brief Virtual destructor
     */
    virtual ~Observer() {}
    
    /**
     * @brief Update method called when notification occurs
     * @param message The notification message
     * @param roomName The name of the chat room that triggered the notification
     */
    virtual void update(const string& message, const string& roomName) = 0;
};

/**
 * @class Subject
 * @brief Abstract subject interface for managing observers
 * Role: Subject in Observer pattern
 */
class Subject {
protected:
    vector<Observer*> observers;
    
public:
    /**
     * @brief Virtual destructor
     */
    virtual ~Subject() {}
    
    /**
     * @brief Subscribe an observer to notifications
     * @param observer The observer to add
     */
    virtual void subscribe(Observer* observer) {
        // Check if observer already exists
        auto it = find(observers.begin(), observers.end(), observer);
        if (it == observers.end()) {
            observers.push_back(observer);
        }
    }
    
    /**
     * @brief Unsubscribe an observer from notifications
     * @param observer The observer to remove
     */
    virtual void unsubscribe(Observer* observer) {
        auto it = find(observers.begin(), observers.end(), observer);
        if (it != observers.end()) {
            observers.erase(it);
        }
    }
    
    /**
     * @brief Notify all subscribed observers
     * @param message The notification message
     * @param roomName The name of the room sending the notification
     */
    virtual void notify(const string& message, const string& roomName) {
        for (Observer* observer : observers) {
            observer->update(message, roomName);
        }
    }
    
    /**
     * @brief Get the list of observers
     * @return Reference to the observers vector
     */
    vector<Observer*>& getObservers() {
        return observers;
    }
};

#endif // OBSERVER_H