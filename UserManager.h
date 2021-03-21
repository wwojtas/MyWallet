#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include <vector>

#include "User.h"
#include "FileWithUsers.h"
#include "AuxiliaryMethods.h"

using namespace std;

class UserManager {

    FileWithUsers fileWithUsers;
    int loggedInUserId;
    vector <User> users;

    User enterNewUserDetails();
    int getNewUserId();
    bool ifLoginExists(string login);

public:

    UserManager( string nameOfFileWithUsers )
        : fileWithUsers( nameOfFileWithUsers ) {
        loggedInUserId = 0;
        users = fileWithUsers.loadUsersFromFile();
    };
    void registrationUser();
    int getLoggedInUserID();
    int loggingUser();
    void changingPasswordOfLoggedInUser();
    int logoutUser();
};

#endif
