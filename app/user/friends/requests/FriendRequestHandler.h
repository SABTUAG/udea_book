#ifndef FRIEND_REQUESTS_HANDLER_H
#define FRIEND_REQUESTS_HANDLER_H

#include <iostream>
#include "listTemplate.h"
#include "FriendRequest.h"

/**
 * @brief Gestiona las solicitudes de amistad recibidas.
 * 
 * Almacena y administra las solicitudes de amistad 
 * que otros usuarios le han enviado a este usuario. Actúa 
 * como una "bandeja de entrada" de invitaciones pendientes.
 * 
 * Utiliza una List<FriendRequest> para mantener el orden de 
 * llegada. Las solicitudes permanecen aquí hasta que el 
 * usuario decida aceptarlas (momento en el que se mueven a 
 * la FriendList) o rechazarlas (momento en el que se 
 * eliminan de esta lista).
 * 
 * Al igual que la lista de amigos, es un subsistema de 
 * FriendNetwork y se apoya en el nameID para identificar 
 * a los emisores, evitando acoplamientos por punteros.
 */
class FriendRequests {

private:   
    List<FriendRequest> _received;   

public:
    FriendRequests();
    FriendRequests(
        const List<FriendRequest>& receivedRequestsRecovered
    );

    const List<FriendRequest>& getReceived() const;
    int getCount() const;

    bool hasReceivedAny() const;
    bool hasReceivedFrom(const str& nameID) const;
    // Revisar despues
    const FriendRequest& getAt(int requestIndex) const;

    bool add(const FriendRequest& request);
    bool remove(const str& nameID);

    friend std::ostream& operator<<(
        std::ostream& output, 
        const FriendRequests& requests
    );
};

std::ostream& operator<<(
    std::ostream& output, 
    const FriendRequests& requests
);

#endif 