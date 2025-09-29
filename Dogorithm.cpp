#include "Dogorithm.h"
#include <algorithm>
#include <iostream>

void Dogorithm::registerUser(Users *user)
{
    // Check if user is already registered
    auto it = find(users.begin(), users.end(), user);
    if (it == users.end())
    {
        users.push_back(user);
        cout << "[Dogorithm]: " << user->getName() << " has joined the room!" << endl;
    }
}

void Dogorithm::removeUser(Users *user)
{
    // Find and remove the user
    auto it = find(users.begin(), users.end(), user);
    if (it != users.end())
    {
        cout << "[Dogorithm]: " << user->getName() << " has left the room." << endl;
        users.erase(it);
    }
}

void Dogorithm::sendMessage(string message, Users *fromUser)
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

void Dogorithm::saveMessage(string message, Users *fromUser)
{
    // Save message to chat history
    string historyEntry = fromUser->getName() + ": " + message;
    chatHistory.push_back(historyEntry);
    cout << "[Dogorithm - Message Saved]: " << historyEntry << endl;
}
