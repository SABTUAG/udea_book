#ifndef USER_H
#define USER_H

#include <string>

#include "friends.h"
#include "image.h"
#include "listTemplate.h"
#include "message.h"
#include "password.h"

class User {
private:
    std::string _nameID;
    std::string _birthDate;
    std::string _email;
    Password _password;
    std::string _city;
    std::string _country;
    std::string _registrationDate;

    List<Friends> _friends; // otros usuarios - relación mutua de amistad
    List<Chats> _chats;
    List<Gallery> _gallery;

public:
    User(std::string nameID, Password password);
    User(
        std::string nameID,
        std::string birthDate,
        std::string email,
        Image profilePicture,
        Password password,
        std::string city,
        std::string country,
        std::string registrationDate,
        List<Friends> friends,
        List<Chats> messages,
        List<Gallery> gallery
    );
};

#endif
