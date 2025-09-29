#include "CtrlCat.h"
#include <algorithm>
#include <iostream>

void CtrlCat::registerUser(Users *user)
{
    // Check if user is already registered
    auto it = find(users.begin(), users.end(), user);
    if (it == users.end())
    {
        users.push_back(user);
        cout << "[CtrlCat]: " << user->getName() << " has joined the room!" << endl;
    }
}

void CtrlCat::removeUser(Users *user)
{
    // Find and remove the user
    auto it = find(users.begin(), users.end(), user);
    if (it != users.end())
    {
        cout << "[CtrlCat]: " << user->getName() << " has left the room." << endl;
        users.erase(it);
    }
}

void CtrlCat::sendMessage(string message, Users *fromUser)
{
    // Send message to all users except the sender (Mediator pattern)
    for (Users* user : users)
    {
        if (user != fromUser)
        {
            user->receive(message, fromUser, this);
        }
    }
}

void CtrlCat::saveMessage(string message, Users *fromUser)
{
    // Save message to chat history
    string historyEntry = fromUser->getName() + ": " + message;
    chatHistory.push_back(historyEntry);
    cout << "[CtrlCat - Message Saved]: " << historyEntry << endl;
}