#ifndef FRIENDS_H
#define FRIENDS_H

#include <string>

#include "listTemplate.h"
#include "console.h"

/**
 * @brief Para representar una solicitud de amistad 
 */
class FriendRequest {
private:
    std::string _senderNameID;
    std::string _recipientNameID;
    std::string _state; // accept // Denege // Undefined

public:
    // Constructores
    FriendRequest(std::string sender, std::string recipient); 

    // Getters
    std::string getSenderNameID() const {
        return _senderNameID; 
    }
    std::string getRecipientNameID() const {
        return _recipientNameID;
    }
    std::string getState() const {
        return _state;
    }

    // Setters
    std::string setState(std::string newState){
        _state = newState; 
    }
};

/**
 * @brief Para representar y manejar la red de amigos, solicitudes recibidas y sugerencias
 */
class FriendshipManagement {
private:
    List<std::string> _friendsNames;
    List<FriendRequest> _requestsSent;
    List<std::string> _requestsReceived;

public:
    // Constructor

    //Getters
    List<std::string> getFriendsNames() const {
        return _friendsNames; 
    }
    List<FriendRequest> getRequestsSent() const {
        return _requestsSent;
    }
    List<std::string> getRequestsReceived() const {
        return _requestsReceived;
    }

    // 

    // Acciones del gestor de amistades 
    bool sendFriendRequest(std::string nameID){
        //...
    }
    bool deleteFriend(std::string nameFriend){
        //...
    }
    void deleteReceivedRequest(std::string nameSender){
        // ...
    }
    void showReceivedRequests(){
        // ...
    }
        
    // Interactuar
    void editFriendshipManagement(){
        std::cout<<"-- Edit red of friends --"<<std::endl;
        std::cout<<"1. See all my friends"<<std::endl;
        std::cout<<"2. View received requests"<<std::endl;
        std::cout<<"3. View friend suggestions"<<std::endl;
        int action = Console::inputValidInt("Option: ",1,3); 
        Console::clear(4); 

    }
};

#endif
