#ifndef FRIEND_REQUESTS_HANDLER_H
#define FRIEND_REQUESTS_HANDLER_H

#include <iostream>
#include "listTemplate.h"
#include "FriendRequest.h"

/**
 * @brief Gestiona las solicitudes de amistad recibidas.
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
    bool hasReceivedFrom(const str& sender) const;
    // Revisar despues
    const FriendRequest& getAt(int index) const;

    bool addReceived(const FriendRequest& request);
    bool removeReceived(const str& sender);

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