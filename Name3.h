#ifndef NAME3_H
#define NAME3_H

#include "Users.h"

class Name3 : public Users
{
public:
    Name3(string userName) : Users(userName) {}
};

#endif