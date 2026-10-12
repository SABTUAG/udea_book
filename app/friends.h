#ifndef FRIENDS_H
#define FRIENDS_H

#include <string>

#include "listTemplate.h"

class User;

// No se requiere eliminar amistades.
class FriendRequest {

};

class Friendship {
private:
    std::string _nameUser;
    std::string _nameFriend;
};

class Friends {
private:
    List<User> _friends;
    List<Friendship> _requestsSent;
    List<FriendRequest> _requestsReceived;
    // Manejo de solicitudes.
};

#endif
