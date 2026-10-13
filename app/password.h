#ifndef PASSWORD_H
#define PASSWORD_H

#include <string>
#include "console.h"

class Password {
private:
    std::string _password;
    std::string _messageToRecover;

public:
    // constructor
    Password(std::string password);
    Password(std::string password, std::string messageToRecover);

    //getters
    std::string getPassword() const {
        return _password; 
    }
    std::string getMessageToRecover() const {
        return _messageToRecover; 
    }

    //setters
    void setPassword(std::string newPassword){
        _password = newPassword; 
    }
    void setMessageToRecover(std::string newMessageToRecover){
        _messageToRecover = newMessageToRecover; 
    }

    //Acciones con contraseña
    
    //Configurar manual
    void editPassword(){
        std::cout<<"-- Config Password --"<<std::endl; 
        std::cout<<"1. Change password"<<std::endl; 
        std::cout<<"2. Change message to recover password"<<std::endl; 
        std::cout<<"3. Exit"<<std::endl; 
        int action = Console::inputValidInt("Option", 1,3); 
        Console::clear(4); 
        switch (action) {
        case 1: {
            std::string newPassword;
            std::cout << "-- Change password --" << std::endl;
            std::cout << "New password: ";
            std::getline(std::cin, newPassword);
            setPassword(newPassword);
            return;
        }
        case 2: {
            std::string newMessageToRecover;
            std::cout << "-- Change recovery message --" << std::endl;
            std::cout << "New recovery message: ";
            std::getline(std::cin, newMessageToRecover);
            setMessageToRecover(newMessageToRecover);
            return;
        }
        case 3:
            return;
        }
    }
};

#endif
