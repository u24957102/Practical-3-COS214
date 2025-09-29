/**
 * @file Users.h
 * @brief Users class implementing Observer pattern
 * @author Paul hofmeyr & Mutombo Kabau
 */

#ifndef USERS_H
#define USERS_H

#include <string>
#include <vector>
#include "Observer.h"

using namespace std;

class ChatRoom;
class Command;

/**
 * @class Users
 * @brief Base user class that acts as Colleague (Mediator), Invoker (Command), and Observer
 * 
 * This class participates in multiple patterns:
 * - Colleague: Communicates through ChatRoom mediator (Mediator pattern)
 * - Invoker: Creates and executes commands (Command pattern)
 * - Observer: Receives notifications from chat rooms (Observer pattern)
 */
class Users : public Observer
{
protected:
    vector<ChatRoom*> chatRooms;
    string name;
    vector<Command*> commandQueue;
    vector<string> notifications; // Store notifications for this user

public:
    /**
     * @brief Constructor
     * @param userName The name of the user
     */
    Users(string userName) : name(userName) {}
    
    /**
     * @brief Virtual destructor
     */
    virtual ~Users() {} 
    
    /**
     * @brief Send a message to a chat room (Invoker in Command pattern)
     * @param message The message to send
     * @param room The chat room to send the message to
     */
    void send(string message, ChatRoom* room);
    
    /**
     * @brief Receive a message from another user (Colleague in Mediator pattern)
     * @param message The message content
     * @param fromUser The user who sent the message
     * @param room The chat room where the message was sent
     */
    void receive(string message, Users* fromUser, ChatRoom* room);
    
    /**
     * @brief Add a command to the queue
     * @param command The command to add
     */
    void addCommand(Command* command);
    
    /**
     * @brief Execute all commands in the queue
     */
    void executeAll();
    
    /**
     * @brief Get the user's name
     * @return The user's name
     */
    string getName() const;
    
    /**
     * @brief Update method for Observer pattern - receives notifications
     * @param message The notification message
     * @param roomName The name of the room that sent the notification
     */
    void update(const string& message, const string& roomName) override;
    
    /**
     * @brief Get all notifications for this user
     * @return Vector of notification strings
     */
    vector<string> getNotifications() const;
    
    /**
     * @brief Clear all notifications
     */
    void clearNotifications();
    
    /**
     * @brief Add a chat room to this user's list
     * @param room The chat room to add
     */
    void addChatRoom(ChatRoom* room);
    
    /**
     * @brief Get all chat rooms this user is part of
     * @return Vector of chat room pointers
     */
    vector<ChatRoom*> getChatRooms() const;
};
#endif