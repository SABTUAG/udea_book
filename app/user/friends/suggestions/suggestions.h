#ifndef FRIEND_SUGGESTIONS_H
#define FRIEND_SUGGESTIONS_H

#include "str.h"

/**
 * @brief Representa a un usuario que ser sugerido como amigo.
 * 
 * Almacena el nameID del usuario para la sugerencia y la 
 * cantidad de amigos en común que tiene con el usuario que 
 * está buscando sugerencias. Se utiliza un operador < para 
 * que la lista pueda ordenarse de mayor a menor.
 */
class FriendSuggestion {

private:
    str _nameID;
    int _commonFriends;

public:
    FriendSuggestion();
    FriendSuggestion(const str& nameID, int commonFriends);

    const str& getNameID() const;
    int getCommonFriends() const;

    void incrementCommonFriends();

    bool operator==(const FriendSuggestion& other) const;
    bool operator<(const FriendSuggestion& other) const;
};

#endif