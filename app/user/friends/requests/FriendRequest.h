#ifndef FRIEND_REQUEST_H
#define FRIEND_REQUEST_H

#include <iostream>
//#include "str.h"

/**
 * @brief Solicitud de amistad enviada por un usuario a otro.
 */
class FriendRequest {

private:
    int _senderID;
    int _receiverID;

public:
    FriendRequest();
    FriendRequest(int senderID, int receiverID);

    int getSenderID() const;
    int getReceiverID() const;

    bool operator==(const FriendRequest& anotherRequest) const;
    bool operator!=(const FriendRequest& anotherRequest) const;

    friend std::ostream& operator<<(
        std::ostream& output, 
        const FriendRequest& requestN
    );
};

std::ostream& operator<<(
    std::ostream& output, 
    const FriendRequest& requestN
);

#endif