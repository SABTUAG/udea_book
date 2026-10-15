#ifndef FRIEND_REQUESTS_HANDLER_H
#define FRIEND_REQUESTS_HANDLER_H

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
    FriendRequests(const List<FriendRequest>& receivedRequestsRecovered): 
        _received(receivedRequestsRecovered) {}
        
    const List<FriendRequest>& getReceived() const { return _received; }
    // Consultas
    bool hasSentTo(int recipientID) const;
    bool hasReceivedFrom(int senderID) const;
    //bool hasReceivedAny() const { return _received.getSize() > 0; }

    bool addReceived(const FriendRequest& r) { return _received.add(r); }
    bool removeReceived(int senderID); 
    void showReceived() const;
};

#endif