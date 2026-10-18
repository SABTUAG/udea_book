#ifndef FRIEND_LIST_H
#define FRIEND_LIST_H

#include <iostream>
#include "str.h"
#include "listTemplate.h"

/**
 * @brief Gestiona los amigos del usuario por nameIDs.
 * 
 * Almacena una colección de cadenas que representan 
 * los nombres de usuario (nameID) de los amigos confirmados. 
 * Encapsula una List<str> propia para ofrecer una interfaz 
 * específica de gestión de amistades (agregar, eliminar y 
 * verificar existencia).
 * 
 * Al guardar los amigos por su nameID en lugar de punteros 
 * a User, se evitan dependencias circulares entre clases y 
 * se simplifica la carga desde el almacenamiento permanente.
 * 
 * Esta clase es un subsistema de FriendNetwork, por lo que
 * su ciclo de vida está atado a la red de amigos del usuario.
 */
class FriendList {
    
private:
    List<str> _friends; 

public:
    FriendList();
    FriendList(const List<str>& friends); 

    const List<str>& getNameIDs() const;
    List<str>& getNameIDs();

    bool contains(const str& nameID) const;
    bool add(const str& nameID);
    bool remove(const str& nameID);

    friend std::ostream& operator<<(
        std::ostream& output, 
        const FriendList& friendlist
    ); 
};

std::ostream& operator<<(
    std::ostream& output, 
    const FriendList& friendlist
);

#endif