#ifndef USER_H
#define USER_H

#include <string>

#include "date.h"
#include "console.h"
#include "friends.h"
#include "image.h"
#include "listTemplate.h"
#include "message.h"
#include "password.h"

class User {
private:
    std::string _nameID;
    Date _birthDate;
    std::string _email;
    Password _password;
    std::string _city;
    std::string _country;
    Date _registrationDate;
    FriendshipManagement _friends;
    Chats _chats;
    Gallery _gallery;

public:
    // Constructor
    User(); 

    // Getters
    std::string getNameID() const {
        return _nameID;
    } 
    std::string getEmail() const {
        return _email; 
    }
    std::string getCity() const {
        return _city; 
    }
    std::string getCountry() const {
        return _country; 
    }
    
    //Setters
    void setEmail(std::string newEmail){
        _email = newEmail; 
    }
    void setCity(std::string newCity){
        _city = newCity; 
    }
    void setCountry(std::string newCountry){
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
