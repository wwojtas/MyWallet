#ifndef FILEWITHUSERS_H
#define FILEWITHUSERS_H

#include <iostream>
#include <vector>

#include "User.h"
#include "AuxiliaryMethods.h"
#include "Markup.h"

using namespace std;

class FileWithUsers {

    vector <User> users;
    const string NAME_OF_FILE_WITH_USERS;
    int loggedInUserId;
    string getNameOfFileWithUsers();

public:

    FileWithUsers( string nameOfFileWithUsers )
        : NAME_OF_FILE_WITH_USERS( nameOfFileWithUsers ) {
    };
    void addUserToFile( User user );
    vector <User> loadUsersFromFile();
    void changePassword( int, string );
};

#endif
