#ifndef USER_H
#define USER_H

#include <iostream>
#include "../../tools/str.h"
#include "../../tools/Console.h"
#include "friends/FriendNetwork.h"
#include "images/Gallery.h"
#include "messages/MessageHandling.h"

/**
 * @brief Representa un usuario en la red social.
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
    MessageHandling _messages;
    Gallery _gallery;

public:
    User(); 
    User(
        int id, 
        const str& nameID, 
        const str& birthDate, 
        const str& email,
        const str& password, 
        const str& city, 
        const str& country,
        const str& registrationDate
    );

    int getID() const;
    const str& getNameID() const;
    const str& getBirthDate() const;
    const str& getEmail() const;
    const str& getCity() const;
    const str& getCountry() const;
    const str& getRegistrationDate() const;
    FriendNetwork& getFriends();
    const FriendNetwork& getFriends() const;
    MessageHandling& getMessages();
    const MessageHandling& getChats() const;
    Gallery& getGallery();
    const Gallery& getGallery() const;
   

    void setEmail(const str& email); 
    void setCity(const str& city);
    void setCountry(const str& country);

    bool operator==(const User& otherUser) const;
    bool operator!=(const User& otherUser) const;
    bool operator<(const User& otherUser) const;

    friend std::ostream& operator<<(
        std::ostream& output, 
        const User& u
    );

};

std::ostream& operator<<(
    std::ostream& output, 
    const User& userN
);

#endif
