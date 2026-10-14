#include "networkOfFriends.h"

FriendRequest::FriendRequest(): 
    _senderNameID(""), 
    _recipientNameID("") {}

FriendRequest::FriendRequest(const str& sender, const str& recipient)
    : _senderNameID(sender), _recipientNameID(recipient) {}

std::ostream& operator<<(std::ostream& os, const FriendRequest& r) {
    os << r._senderNameID << " -> " << r._recipientNameID;
    return os;
}