#ifndef FRIEND_REQUESTS_HANDLER_H
#define FRIEND_REQUESTS_HANDLER_H

#include "listTemplate.h"
#include "FriendRequest.h"

/**
 * @brief Gestiona las solicitudes de amistad enviadas y recibidas de un usuario.
 */
class FriendRequests {
private:
    List<FriendRequest> _sent;       
    List<FriendRequest> _received;   

public:
    FriendRequests();

    const List<FriendRequest>& getSent() const { return _sent; }
    const List<FriendRequest>& getReceived() const { return _received; }

    // Consultas
    bool hasSentTo(int recipientID) const;
    bool hasReceivedFrom(int senderID) const;
    //bool hasSentAny() const { return _sent.getSize() > 0; }
    //bool hasReceivedAny() const { return _received.getSize() > 0; }

    bool addSent(const FriendRequest& r) { return _sent.add(r); }
    bool addReceived(const FriendRequest& r) { return _received.add(r); }
    bool removeSent(int recipientID);
    bool removeReceived(int senderID);

    void showReceived() const;
};

#endif