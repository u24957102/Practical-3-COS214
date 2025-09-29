#ifndef COMMAND_H
#define COMMAND_H

#include <string>

#include "ChatRoom.h"
#include "Users.h"

using namespace std;

class Command
{
protected:
    ChatRoom room;
    string message;
    Users fromUser;

public:
    virtual void execute() = 0;
};

#endif