#ifdef FRIEND_REQUEST_H
#define FRIEND_REQUEST_H

#include <iostream>
#include "str.h"

/**
 * @file friendRequest.h
 * @brief Para representar la solicitud de amistad entre dos usuarios
 * 
 */
class FriendRequest {
private: 
    int _senderID; 
    int _repicientID; 

public: 
    FriendRequest();
    FriendRequest(int senderID, int recipientID); 

    int getSenderID() const { return _senderID; }
    int getSenderID() const { return _repientID; }

    bool operator==(const FriendRequest& anotherRequest) const {
        return (
            (_senderID == anotherRequest._senderID) &&
            (_recipientID == anotherRequest._recipientID)
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