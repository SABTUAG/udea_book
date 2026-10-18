#include "FriendRequest.h"

FriendRequest::FriendRequest(const str& nameID): 
    _sender(nameID){}


const str& FriendRequest::getSender() const {
    return _sender;
}


bool FriendRequest::operator==(
    const FriendRequest& anotherRequest
) const {
    return _sender == anotherRequest._sender;
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