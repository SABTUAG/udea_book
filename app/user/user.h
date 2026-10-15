#ifndef USER_H
#define USER_H

#include <string>
#include "listTemplate.h"
#include "console.h"
#include "str.h"

#include "friends/FriendNetwork.h"
#include "images/gallery.h"
#include "images/image.h"
#include "messages/message.h"

/**
 * @brief Representa un usuario en la red social
 */
class User {
private:
    int _id; 
    str _nameID;
    str _birthDate;
    str _email;
    str _password;
    str _city;
    str _country;
    str _registrationDate;
    FriendNetwork _friends;
    Chats _chats;
    Gallery _gallery;

public:
    User(); 
    User(
        int id, const str& nameID, 
        const str& birthDate, 
        const str& email,
        const str& password, 
        const str& city, 
        const str& country,
        const str& registrationDate
    );

    bool operator==(const User& otherUser) const {
        return _nameID == otherUser._nameID; 
    }
    bool operator!=(const User& otherUser) const {
        return !(*this==otherUser); 
    }

    int getID() const { return _id; }
    const str& getNameID() const { return _nameID; }
    const str& getBirthDate() const { return _birthDate; }
    const str& getEmail() const { return _email; }
    const str& getCity() const { return _city; }
    const str& getCountry() const { return _country; }
    const str& getRegistrationDate() const { return _registrationDate; }
    
    void setID(int id){ 
        _id = id; 
    }
    void setNameID(const str& nameID){ 
        _nameID = nameID; 
    }
    void setBirthDate(const str& birthDate){ 
        _birthDate = birthDate; 
    }
    void setEmail(const str& email){ 
        _email = email; 
    }
    void setPassword(const str& password){ 
        _password = password; 
    }
    void setCity(const str& city){ 
        _city = city; 
    }
    void setCountry(const str& country){ 
        _country = country; 
    }
    void setRegistrationDate(const str& registrationDate){
        _registrationDate = registrationDate;
    }

    void showProfile() const; 

    friend std::ostream& operator<<(std::ostream& os, const User& u);

};

std::ostream& operator<<(std::ostream& os, const User& u);

#endif
