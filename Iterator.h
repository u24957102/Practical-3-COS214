/**
 * @file Iterator.h
 * @brief Iterator pattern implementation for traversing chat history and user lists
 * @author Mutombo Kabau
 */

#ifndef ITERATOR_H
#define ITERATOR_H

#include <string>
#include <vector>
#include "Users.h"

using namespace std;

/**
 * @class Iterator
 * @brief Abstract iterator interface for traversing collections
 * @tparam T The type of elements to iterate over
 */
template <typename T>
class Iterator {
public:
    virtual ~Iterator() {}
    
    /**
     * @brief Check if there are more elements to iterate
     * @return true if more elements exist, false otherwise
     */
    virtual bool hasNext() = 0;
    
    /**
     * @brief Get the next element in the collection
     * @return The next element
     */
    virtual T next() = 0;
    
    /**
     * @brief Reset iterator to the beginning
     */
    virtual void reset() = 0;
};

/**
 * @class ChatHistoryIterator
 * @brief Concrete iterator for traversing chat history messages
 * Role: ConcreteIterator in Iterator pattern
 */
class ChatHistoryIterator : public Iterator<string> {
private:
    vector<string>* messages;
    size_t currentPosition;
    
public:
    /**
     * @brief Constructor
     * @param msgs Pointer to the vector of messages
     */
    ChatHistoryIterator(vector<string>* msgs) 
        : messages(msgs), currentPosition(0) {}
    
    /**
     * @brief Check if there are more messages
     * @return true if more messages exist
     */
    bool hasNext() override {
        return currentPosition < messages->size();
    }
    
    /**
     * @brief Get the next message
     * @return The next message string
     */
    string next() override {
        if (hasNext()) {
            return (*messages)[currentPosition++];
        }
        return "";
    }
    
    /**
     * @brief Reset iterator to start
     */
    void reset() override {
        currentPosition = 0;
    }
};

/**
 * @class UserListIterator
 * @brief Concrete iterator for traversing user lists
 * Role: ConcreteIterator in Iterator pattern
 */
class UserListIterator : public Iterator<Users*> {
private:
    vector<Users*>* users;
    size_t currentPosition;
    
public:
    /**
     * @brief Constructor
     * @param usrList Pointer to the vector of users
     */
    UserListIterator(vector<Users*>* usrList) 
        : users(usrList), currentPosition(0) {}
    
    /**
     * @brief Check if there are more users
     * @return true if more users exist
     */
    bool hasNext() override {
        return currentPosition < users->size();
    }
    
    /**
     * @brief Get the next user
     * @return Pointer to the next user
     */
    Users* next() override {
        if (hasNext()) {
            return (*users)[currentPosition++];
        }
        return nullptr;
    }
    
    /**
     * @brief Reset iterator to start
     */
    void reset() override {
        currentPosition = 0;
    }
};

#endif // ITERATOR_H