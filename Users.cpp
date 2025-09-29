/**
 * @file Users.cpp
 * @brief Implementation of Users class with Observer pattern
 * @author Paul hofmeyr & Mutombo Kabau
 */

#include "Users.h"
#include "ChatRoom.h"
#include "Command.h"
#include "SendMessageCommand.h"
#include "LogMessageCommand.h"
#include <iostream>

using namespace std;

void Users::send(string message, ChatRoom *room)
{
    // Create commands for sending and saving the message
    Command* sendCmd = new SendMessageCommand(room, message, this);
    Command* saveCmd = new LogMessageCommand(room, message, this);
    
    // Add commands to the queue
    addCommand(sendCmd);
    addCommand(saveCmd);
    
    // Execute all commands
    executeAll();
}

void Users::receive(string message, Users *fromUser, ChatRoom *room)
{
    // Display the received message
    cout << "[" << name << " received]: " << fromUser->getName() 
         << " says: " << message << endl;
}

void Users::addCommand(Command *command)
{
    // Add command to the queue
    commandQueue.push_back(command);
}

void Users::executeAll()
{
    // Execute all commands in the queue
    for (Command* cmd : commandQueue)
    {
        cmd->execute();
        delete cmd; // Clean up after execution
    }
    
    // Clear the queue after execution
    commandQueue.clear();
}

string Users::getName() const
{
    return name;
}

void Users::update(const string& message, const string& roomName)
{
    // Receive notification from subscribed chat room (Observer pattern)
    string notification = "[NOTIFICATION from " + roomName + "]: " + message;
    notifications.push_back(notification);
    cout << "[" << name << " - Notification]: " << message << " (from " << roomName << ")" << endl;
}

vector<string> Users::getNotifications() const
{
    return notifications;
}

void Users::clearNotifications()
{
    notifications.clear();
}

void Users::addChatRoom(ChatRoom* room)
{
    chatRooms.push_back(room);
}

vector<ChatRoom*> Users::getChatRooms() const
{
    return chatRooms;
}