#ifndef FRIEND_REQUEST_H
#define FRIEND_REQUEST_H

#include <iostream>
#include "str.h"

/**
 * @brief Solicitud de amistad enviada por un usuario a otro. 
 * 
 */
class FriendRequest {
private: 
    int _senderID; 
    int _receiverID; 

public: 
    FriendRequest();
    FriendRequest(int senderID, int receiverID); 

    int getSenderID() const { return _senderID; }
    int getReceiverID() const { return _receiverID; }

    bool operator==(const FriendRequest& anotherRequest) const {
        return (
            (_senderID == anotherRequest._senderID) &&
            (_receiverID == anotherRequest._receiverID)
        );
    }
    bool operator!=(const FriendRequest& anotherRequest) const {
        return !(*this == anotherRequest);
    }
    // para amigos
    friend std::ostream& operator<<(std::ostream& os, const FriendRequest& show);
};

// Emisor -> receptor, para pruebas 
std::ostream& operator<<(std::ostream& os, const FriendRequest& show);

#endif