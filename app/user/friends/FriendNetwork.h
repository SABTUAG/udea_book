#ifndef NETWORK_OF_FRIENDS_H
#define NETWORK_OF_FRIENDS_H

#include <iostream>
#include "../tools/str.h"
#include "list/FriendList.h"
#include "requests/FriendRequestHandler.h"

/**
 * @brief Gestiona la red de amigos del usuario: amigos y solicitudes.
 * 
 * Actúa como una fachada que centraliza la actividad 
 * social del usuario. Agrupa dos subsistemas: la lista de 
 * amigos confirmados y las solicitudes de amistad recibidas. 
 * 
 * Los subsistemas se almacenan por composición. Esto 
 * significa que si el usuario es destruido, su red de 
 * amigos también lo será, liberando la memoria asociada 
 * de forma automática.
 * 
 * Delegar esta responsabilidad en FriendNetwork permite que 
 * la clase User se mantenga enfocada únicamente en los datos 
 * personales. Actualmente agrupa amigos y solicitudes, pero 
 * se deja el espacio preparado para incorporar un motor de 
 * sugerencias de amistad en el futuro sin afectar al resto.
 */
class FriendNetwork {

private:
    FriendList _friends;
    FriendRequests _requests;

public:
    FriendNetwork();
    FriendNetwork(const str& block); 

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
