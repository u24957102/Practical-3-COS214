/**
 * @file CtrlCat.h
 * @brief CtrlCat chat room concrete mediator
 * @author Paul hofmeyr  & Mutombo Kabau
 */

#ifndef CTRLCAT_H
#define CTRLCAT_H

#include "ChatRoom.h"

/**
 * @class CtrlCat
 * @brief Concrete mediator for the CtrlCat chat room
 * Role: ConcreteMediator, ConcreteSubject
 */
class CtrlCat : public ChatRoom
{
public:
    /**
     * @brief Constructor - initializes with room name "CtrlCat"
     */
    CtrlCat() : ChatRoom("CtrlCat") {}
    
    void registerUser(Users* user) override;
    void removeUser(Users* user) override;
    void sendMessage(string message, Users* fromUser) override;
    void saveMessage(string message, Users* fromUser) override;
};

#endif