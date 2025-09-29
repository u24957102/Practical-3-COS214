#ifndef CHATROOM_H
#define CHATROOM_H

#include <string>
#include <vector>
#include "Users.h"

using namespace std;

class ChatRoom
{
protected:
    vector<Users*> users;
    vector<string> chatHistory;

public:
    virtual ~ChatRoom() {} 
    
    virtual void registerUser(Users* user) = 0;
    virtual void removeUser(Users* user) = 0;
    
    virtual void sendMessage(string message, Users* fromUser) = 0;
    virtual void saveMessage(string message, Users* fromUser) = 0;
    
    vector<Users*>& getUsers() { return users; }
    vector<string>& getChatHistory() { return chatHistory; }
};

#endif