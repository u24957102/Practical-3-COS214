#ifndef COMMAND_H
#define COMMAND_H

#include <string>

using namespace std;

class ChatRoom;
class Users;

class Command
{
protected:
    ChatRoom* room;
    string message;
    Users* fromUser;

public:
    virtual ~Command() {} 
    
    Command(ChatRoom* chatRoom, string msg, Users* user)
        : room(chatRoom), message(msg), fromUser(user) {}
    
    virtual void execute() = 0;
};

#endif