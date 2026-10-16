#include "FriendRequest.h"

FriendRequest::FriendRequest(
    int senderID, int receiverID
): 
    _senderID(senderID), 
    _receiverID(receiverID) {}


int FriendRequest::getSenderID() const {
    return _senderID;
}
int FriendRequest::getReceiverID() const {
    return _receiverID;
}


bool FriendRequest::operator==(
    const FriendRequest& anotherRequest
) const {
    return (_senderID == anotherRequest._senderID) &&
           (_receiverID == anotherRequest._receiverID);
}
bool FriendRequest::operator!=(
    const FriendRequest& anotherRequest
) const {
    return !(*this == anotherRequest);
}


std::ostream& operator<<(
    std::ostream& output, 
    const FriendRequest& requestN
) {
    output << requestN._senderID; 
    return output;
}