#include "FriendNetwork.h"
#include "../tools/parser.h"

FriendNetwork::FriendNetwork(): 
    _friends(), 
    _requests() {}


FriendNetwork::FriendNetwork(const str& block) {
    // 1. Parsear Amigos: FRIENDS: (carlos_m;ana_p);
    str friendsStr = extractParens(block, "FRIENDS:");
    if (friendsStr.len() > 0) {
        List<str> listF = friendsStr.split(';');
        listF.forEach([&](const str& name) {
            _friends.add(name.strip());
        });
    }
    // 2. Parsear Solicitudes: REQUESTS: (pedro_12)
    str requestsStr = extractParens(block, "REQUESTS:");
    if (requestsStr.len() > 0) {
        List<str> listR = requestsStr.split(';');
        listR.forEach([&](const str& name) {
            _requests.add(FriendRequest(name.strip()));
        });
    }
}


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
    output << "*** Red de amistades ***\n";
    output << network._friends;
    output << network._requests;
    return output;
}