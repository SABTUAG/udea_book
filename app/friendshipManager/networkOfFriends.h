#ifndef NETWORK_OF_FRIENDS_H
#define NETWORK_OF_FRIENDS_H

#include <iostream>
#include <string>
#include "listTemplate.h"
#include "str.h"
#include "console.h"

#include "friendRequest.h"

class User;

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

