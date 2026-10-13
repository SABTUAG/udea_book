#ifndef FRIENDS_H
#define FRIENDS_H

#include <string>

#include "listTemplate.h"
#include "console.h"

class User;
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

// friends.h
class FriendshipManagement {
private:
    List<User*> _friends;              // ← punteros, no strings
    List<FriendRequest> _requestsSent;
    List<FriendRequest> _requestsReceived;

public:
    void addFriend(User* u) { _friends.add(u); }
    bool isFriend(const User* u) const { return _friends.search(u); }
    List<User*>& getFriends() { return _friends; }  // referencia, no copia
    // ...
};
    


#endif

