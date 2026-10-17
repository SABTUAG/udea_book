#ifndef NETWORK_OF_FRIENDS_H
#define NETWORK_OF_FRIENDS_H

#include <iostream>
#include "list/FriendList.h"
#include "requests/FriendRequestHandler.h"

/**
 * @brief Gestiona la red de amigos del usuario: amigos y solicitudes.
 * @details Agrupa dos subsistemas: la lista de amigos confirmados y las
 *          solicitudes de amistad recibidas. Se deja espacio para
 *          incorporar un motor de sugerencias en el futuro.
 */
class FriendNetwork {

private:
    FriendList _friends;
    FriendRequests _requests;

public:
    FriendNetwork();

    FriendList& getFriends();
    const FriendList& getFriends() const;
    FriendRequests& getRequests();
    const FriendRequests& getRequests() const;

    friend std::ostream& operator<<(
        std::ostream& output, 
        const FriendNetwork& network
    );
};

std::ostream& operator<<(
    std::ostream& output, 
    const FriendNetwork& network
);

#endif
