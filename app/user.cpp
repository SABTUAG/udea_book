#include <iostream>
#include "listTemplate.h"
#include <string>
using namespace std; 

class User {

    private: 
        string _nameID; 
        string _birthDate; 
        string _email; 
        string _profilePicture; 
        string _password; 
        string _city; 
        string _country; 
        string _registrationDate; 

        List<string> _friends; // otros usuarios - relacion mutua amistad
        List<string> _messages; //
        List<string> _albums; 

    public: 
        

}; 