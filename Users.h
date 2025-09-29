#ifndef USERS_H
#define USERS_H

#include <string>
#include <vector>

using namespace std;

class ChatRoom;
class Command;

class Users
{
protected:
    vector<ChatRoom*> chatRooms;
    string name;
    vector<Command*> commandQueue;

public:
    Users(string userName) : name(userName) {}
    
    virtual ~Users() {} 
    
    void send(string message, ChatRoom* room);
    void receive(string message, Users* fromUser, ChatRoom* room);
    void addCommand(Command* command);
    void executeAll();
    
    string getName() const;
};

#endif