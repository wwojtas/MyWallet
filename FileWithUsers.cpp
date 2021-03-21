#include "FileWithUsers.h"

string FileWithUsers::getNameOfFileWithUsers() {

    return NAME_OF_FILE_WITH_USERS;
}

void FileWithUsers::addUserToFile(User user) {

    CMarkup xml;

    bool fileExists = xml.Load( getNameOfFileWithUsers() );

    if ( !fileExists ) {
        xml.SetDoc( "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n" );
        xml.AddElem( "Users" );
    }
    xml.FindElem( "Users" );
    xml.IntoElem();
    xml.AddElem( "User" );
    xml.IntoElem();
    xml.AddElem( "userId", user.getUserId() );
    xml.AddElem( "login", user.getLogin() );
    xml.AddElem( "password", user.getPassword() );
    xml.AddElem( "name", user.getName() );
    xml.AddElem( "surname", user.getSurname() );

    if ( xml.Save( getNameOfFileWithUsers() )) {
        cout << endl << "The user has been added to the file" << endl;
    } else {
        cout << "Error. User not entered in file" << endl;
    }
}

vector <User> FileWithUsers::loadUsersFromFile() {

    CMarkup xml;
    User user;
    vector <User> users;

    bool fileExists = xml.Load( getNameOfFileWithUsers() );

    if ( fileExists ) {
        xml.FindElem( "Users" );
        xml.IntoElem();
        while( xml.FindElem( "User" )) {

            xml.IntoElem();
            xml.FindElem( "userId" );
            user.setUserId( atoi( xml.GetData().c_str() ) );
            xml.FindElem( "login" );
            user.setLogin( xml.GetData() );
            xml.FindElem( "password" );
            user.setPassword( xml.GetData() );
            xml.FindElem( "name" );
            user.setName( xml.GetData());
            xml.FindElem( "surname" );
            user.setSurname( xml.GetData() );
            xml.OutOfElem();
            users.push_back( user );
        }
    }
    return users;
}

void FileWithUsers::changePassword( int loggedInUserId, string newPassword ) {
    CMarkup xml;

    bool fileExists = xml.Load( getNameOfFileWithUsers() );

    if ( fileExists ) {
        xml.FindElem( "Users" );
        xml.IntoElem();

        while(xml.FindElem( "User" )) {
            xml.IntoElem();
            xml.FindElem( "userId" );

            if( loggedInUserId == atoi( xml.GetData().c_str())) {
                xml.FindElem( "password" );
                xml.SetData( newPassword );
                break;
            }
            xml.OutOfElem();
        }
        xml.Save( getNameOfFileWithUsers() );
    }
}
