#ifndef NETWORK_OF_FRIENDS_H
#define NETWORK_OF_FRIENDS_H

#include "list/FriendList.h"
#include "requests/FriendRequestHandler.h"
#include "suggestions/FriendSuggestions.h"

class User;

/**
 * @brief Representa la red de amigos del usuario solicitudes recibidas y sugerencias. 
 * @details Gestiona los amigos, las sugerencias de amistad, las solicitudes recibidas. 
 */
class FriendNetwork {
private: 
    FriendList _friends; 
    FriendRequests _requests; 
    FriendSuggestions _suggestions; 

public: 
    FriendNetwork();
};
    
#endif

