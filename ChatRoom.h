/**
 * @file ChatRoom.h
 * @brief ChatRoom class with Mediator, Observer, and Iterator patterns
 * @author paul hofmeyr  & Mutombo Kabau
 */

#ifndef CHATROOM_H
#define CHATROOM_H

#include <string>
#include <vector>
#include "Users.h"
#include "Observer.h"
#include "Iterator.h"

using namespace std;

/**
 * @class ChatRoom
 * @brief Abstract mediator that also acts as Subject for notifications
 * 
 * This class participates in multiple patterns:
 * - Mediator: Manages communication between users (Mediator)
 * - Subject: Notifies subscribed users of events (Observer pattern)
 * - Aggregate: Provides iterators for users and chat history (Iterator pattern)
 */
class ChatRoom : public Subject
{
protected:
    vector<Users*> users;
    vector<string> chatHistory;
    string roomName;

public:
    /**
     * @brief Constructor
     * @param name The name of the chat room
     */
    ChatRoom(const string& name) : roomName(name) {}
    
    /**
     * @brief Virtual destructor
     */
    virtual ~ChatRoom() {} 
    
    /**
     * @brief Register a user to the chat room
     * @param user The user to register
     */
    virtual void registerUser(Users* user) = 0;
    
    /**
     * @brief Remove a user from the chat room
     * @param user The user to remove
     */
    virtual void removeUser(Users* user) = 0;
    
    /**
     * @brief Send a message to all users in the room (Mediator pattern)
     * @param message The message content
     * @param fromUser The user sending the message
     */
    virtual void sendMessage(string message, Users* fromUser) = 0;
    
    /**
     * @brief Save a message to chat history (Command pattern)
     * @param message The message content
     * @param fromUser The user who sent the message
     */
    virtual void saveMessage(string message, Users* fromUser) = 0;
    
    /**
     * @brief Get the list of users
     * @return Reference to the users vector
     */
    vector<Users*>& getUsers() {
        return users;
    }
    
    /**
     * @brief Get the chat history
     * @return Reference to the chat history vector
     */
    vector<string>& getChatHistory() {
        return chatHistory;
    }
    
    /**
     * @brief Create iterator for user list (Iterator pattern)
     * @return Pointer to UserListIterator
     */
    Iterator<Users*>* createUserIterator() {
        return new UserListIterator(&users);
    }
    
    /**
     * @brief Create iterator for chat history (Iterator pattern)
     * @return Pointer to ChatHistoryIterator
     */
    Iterator<string>* createChatHistoryIterator() {
        return new ChatHistoryIterator(&chatHistory);
    }
    
    /**
     * @brief Get the room name
     * @return The name of the chat room
     */
    string getRoomName() const {
        return roomName;
    }
};

#endif