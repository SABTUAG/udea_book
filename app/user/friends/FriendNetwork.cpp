#include "FriendNetwork.h"

FriendNetwork::FriendNetwork(): 
    _friends(), 
    _requests() {}


FriendList& FriendNetwork::getFriends(){
    return _friends;
}
const FriendList& FriendNetwork::getFriends() const {
    return _friends;
}
FriendRequests& FriendNetwork::getRequests(){
    return _requests;
}
const FriendRequests& FriendNetwork::getRequests() const {
    return _requests;
}


std::ostream& operator<<(
    std::ostream& output, 
    const FriendNetwork& network
){
    output << "*** Red de amistad ***\n";
    output << network._friends;
    output << network._requests;
    return output;
}