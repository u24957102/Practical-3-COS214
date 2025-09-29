/**
 * @file Dogorithm.h
 * @brief Dogorithm chat room concrete mediator
 * @author Paul hofmeyr  & Mutombo Kabau
 */

#ifndef DOGORITHM_H
#define DOGORITHM_H

#include "ChatRoom.h"

/**
 * @class Dogorithm
 * @brief Concrete mediator for the Dogorithm chat room
 * Role: ConcreteMediator, ConcreteSubject
 */
class Dogorithm : public ChatRoom
{
public:
    /**
     * @brief Constructor - initializes with room name "Dogorithm"
     */
    Dogorithm() : ChatRoom("Dogorithm") {}
    
    void registerUser(Users* user) override;
    void removeUser(Users* user) override;
    void sendMessage(string message, Users* fromUser) override;
    void saveMessage(string message, Users* fromUser) override;
};

#endif
