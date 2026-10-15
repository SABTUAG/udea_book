#include "FriendRequest.h"

FriendRequest::FriendRequest():
    _senderID(-1), _receiverID(-1) {}

FriendRequest::FriendRequest(int senderID, int receiverID): 
    _senderID(senderID), _receiverID(receiverID) {}

// [ID emisor -> ID receptor]
std::ostream& operator<<(std::ostream& os, const FriendRequest& r) {
    os << "[" << r._senderID << " -> " << r._receiverID << "]";
    return os;
}