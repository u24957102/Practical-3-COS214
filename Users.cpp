#include "Users.h"
#include "ChatRoom.h"
#include "Command.h"
#include "SendMessageCommand.h"
#include "LogMessageCommand.h"
#include <iostream>

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