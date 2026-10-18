#ifndef FRIEND_REQUEST_H
#define FRIEND_REQUEST_H

#include <iostream>
#include "str.h"

/**
 * @brief Solicitud de amistad enviada por un usuario a otro.
 * 
 * Representa una petición de amistad pendiente. 
 * Almacena únicamente el nameID del emisor, ya que la 
 * solicitud siempre vive dentro de la bandeja de entrada 
 * (FriendRequests) del receptor. Por lo tanto, el receptor 
 * ya se conoce por el contexto y no necesita guardarse aquí.
 * 
 * Al igual que otras relaciones en el sistema, se guarda 
 * el nombre del emisor (str) en lugar de un puntero al 
 * objeto User, lo que evita dependencias circulares y 
 * facilita la carga desde archivo.
 * 
 * Es una entidad inmutable: una vez creada no cambia, pues 
 * su ciclo de vida termina cuando es aceptada (se mueve a 
 * FriendList) o rechazada (se elimina de la lista).
 */
class FriendRequest {

private:
    str _sender; 

public:
    FriendRequest(const str& nameID);

    const str& getSender() const;

    bool operator==(const FriendRequest& anotherRequest) const;
    bool operator!=(const FriendRequest& anotherRequest) const;

    friend std::ostream& operator<<(
        std::ostream& output, 
        const FriendRequest& request
    );
};

std::ostream& operator<<(
    std::ostream& output, 
    const FriendRequest& request
);

#endif