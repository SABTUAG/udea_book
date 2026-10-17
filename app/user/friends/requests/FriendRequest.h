#ifndef FRIEND_REQUEST_H
#define FRIEND_REQUEST_H

#include <iostream>
#include "str.h"

/**
 * @brief Solicitud de amistad enviada por un usuario a otro.
 */
class FriendRequest {

private:
    str _sender; 
    str _receiver; 

public:
    FriendRequest(const str& sender, const str& receiver);

    const str& getSender() const;
    const str& getReceiver() const;

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