#include "UserManager.h"

int UserManager::getLoggedInUserID() {

    return loggedInUserId;
}

void UserManager::registrationUser() {

    User user = enterNewUserDetails();
    users.push_back( user );
    fileWithUsers.addUserToFile( user );

    cout << "Account successfully created" << endl << endl;
    system("pause");
}

User UserManager::enterNewUserDetails() {

    User user;
    user.setUserId( getNewUserId() );
    string login, password, name, surname;
    do {
        cout << endl << "Enter login: ";
        login = AuxiliaryMethods::loadLines();
        user.setLogin( login );
    } while ( ifLoginExists( user.getLogin() ) == true);

    cout << "Enter password: ";
    password = AuxiliaryMethods::loadLines();
    user.setPassword( password );

    cout << "Enter name: ";
    name = AuxiliaryMethods::replaceFirstLetterToUppercaseAndAllOthersToLowercase( AuxiliaryMethods::loadLines() );
    user.setName( name );

    cout << "Enter surname: ";
    surname = AuxiliaryMethods::replaceFirstLetterToUppercaseAndAllOthersToLowercase( AuxiliaryMethods::loadLines() );
    user.setSurname( surname );

    return user;
}

int UserManager::getNewUserId() {

    if ( users.empty()) return 1;
    else return ( users.back().getUserId()+1 );
}

bool UserManager::ifLoginExists( string login ) {

    for ( int i = 0; i < users.size(); i++ ) {

        if ( users[i].getLogin() == login ) {
            cout << endl << "There is a user with this login." << endl;
            return true;
        }
    }
    return false;
}

int UserManager::loggingUser() {

    string enteredLogin = "", enteredPassword = "";

    cout << endl << " ==== LOG IN MENU ==== \n";
    cout << "\n ==== Enter login: ";
    enteredLogin = AuxiliaryMethods::loadLines();

    for ( int i = 0; i < users.size(); i++ ) {

        if ( users[i].getLogin() == enteredLogin) {
            for (int numberOfTrials = 3; numberOfTrials > 0; numberOfTrials--) {
                cout << "Enter password. Remaining trials: " << numberOfTrials << ": ";
                enteredPassword = AuxiliaryMethods::loadLines();

                if ( users[i].getPassword() == enteredPassword ) {
                    cout << endl << "You logged in." << endl << endl;
                    system("pause");
                    loggedInUserId = users[i].getUserId();

                    return loggedInUserId;
                }
            }
            cout << "Wrong password entered 3 times." << endl;
            system("pause");
            return 0;
        }
    }
    cout << "There is no user with this login" << endl << endl;
    system("pause");
    return 0;
}

void UserManager::changingPasswordOfLoggedInUser() {

    string newPassword = "";
    cout << "Enter new password: ";
    newPassword = AuxiliaryMethods::loadLines();

    for ( int i = 0; i < users.size(); i++ ) {

        if ( users[i].getUserId() == loggedInUserId ) {
            users[i].setPassword( newPassword );
            fileWithUsers.changePassword( loggedInUserId, newPassword);
            cout << "Password has been changed." << endl << endl;
            system("pause");
        }
    }
}

int UserManager::logoutUser() {

    loggedInUserId = 0;
    return loggedInUserId;
}
