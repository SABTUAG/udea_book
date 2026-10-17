#include "FriendRequest.h"

FriendRequest::FriendRequest(
    const str& sender, const str& receiver
): 
    _sender(sender), 
    _receiver(receiver) {}


const str& FriendRequest::getSender() const {
    return _sender;
}
const str& FriendRequest::getReceiver() const {
    return _receiver; 
}


bool FriendRequest::operator==(
    const FriendRequest& anotherRequest
) const {
    return (
        (_sender == anotherRequest._sender) &&
        (_receiver == anotherRequest._receiver)
    );
}
bool FriendRequest::operator!=(
    const FriendRequest& anotherRequest
) const {
    return !(*this == anotherRequest);
}


std::ostream& operator<<(
    std::ostream& output, 
    const FriendRequest& request
) {
    output << request._sender; 
    return output;
}