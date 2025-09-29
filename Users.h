#ifndef USERS_H
#define USERS_H

#include <string>

#include "ChatRoom.h"
#include "Command.h"

using namespace std;

class Users
{
protected:
    ChatRoom *chatRooms;
    string name;
    Command *commandQueue;

public:
    void send(string message, ChatRoom room);
    void receive(string message, Users fromUser, ChatRoom room);
    void addCommand(Command command);
    void executeAll();
};

#endif