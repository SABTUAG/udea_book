#ifndef USER_H
#define USER_H

#include <string>
#include "listTemplate.h"
#include "console.h"
#include "str.h"

#include "date.h"
#include "friends.h"
#include "image.h"
#include "message.h"

/**
 * @brief Para representar un usuario 
 */
class User {
private:
    int _id; 
    str _nameID;
    Date _birthDate;
    str _email;
    str _password;
    str _city;
    str _country;
    Date _registrationDate;
    FriendshipManagement _networkOfFriends;
    Chats _chats;
    Gallery _gallery;

public:
    // Constructor
    User(); 

    // Cargar operadores
    bool operator==(const User& otherUser) const {
        return _nameID == otherUser._nameID; 
    }
    bool operator!=(const User& otherUser) const {
        return !(*this==otherUser); 
    }

    // Getters
    const str& getNameID() const { return _nameID; } 
    const str& getEmail() const { return _email; }
    const str& getCity() const { return _city; }
    const str& getCountry() const { return _country; }
    
    //Setters
    void setEmail(const str& newEmail){
        _email = newEmail; 
    }
    void setCity(const str& newCity){
        _city = newCity; 
    }
    void setCountry(const str& newCountry){
        _country = newCountry; 
    }

    // Acciones del usuario 
    void showProfile(){
        std::cout<<" "<<getNameID()<<std::endl; 
        _gallery.showGallery(); 
    }

    //Configurar manual 
    void editProfile(){
        std::cout<<"-- Edit profile --"<<std::endl; 
        std::cout<<"1. Change city"<<std::endl; 
        std::cout<<"2. Change country"<<std::endl; 
        std::cout<<"3. "<<std::endl; 
        //...
    }

};

#endif
