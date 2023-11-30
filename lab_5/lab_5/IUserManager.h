#pragma once
#include "User.h"

__interface IUserManager
{
public:
    virtual void signIn(User& user) = 0;
    virtual void signOut(User& user) = 0;
    virtual bool isAuthorized() = 0;
};
