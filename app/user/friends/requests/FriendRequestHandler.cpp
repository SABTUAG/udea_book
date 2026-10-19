#include "FriendRequestHandler.h"

FriendRequests::FriendRequests(): 
    _received() {}
FriendRequests::FriendRequests(
    const List<FriendRequest>& receivedRequestsRecovered
): 
    _received(receivedRequestsRecovered) {}


const List<FriendRequest>& FriendRequests::getReceived() const {
    return _received;
}
int FriendRequests::getCount() const {
    return _received.getLen();
}


bool FriendRequests::hasReceivedAny() const {
    return _received.getLen() > 0;
}
bool FriendRequests::hasReceivedFrom(
    const str& nameID
) const {
    bool found = false;
    _received.forEach(
        [&](const FriendRequest& request){
            if (request.getSender()==nameID){
                found = true;
            }
        }
    );
    return found;
}
const FriendRequest& FriendRequests::getAt(int requestIndex) const {
    return _received[requestIndex];
}
bool FriendRequests::add(const FriendRequest& request){
    return _received.add(request);
}
bool FriendRequests::remove(const str& nameID){
    bool removed = false;
    List<FriendRequest> nuevaLista;
    _received.forEach(
        [&](const FriendRequest& request){
            if (request.getSender()==nameID){
                removed = true;
            } else{
                nuevaLista.add(request);
            }
        }   
    );
    if (removed) _received = nuevaLista;
    return removed;
}


std::ostream& operator<<(
    std::ostream& output, 
    const FriendRequests& requests
){
    int n = 1;
    output<<"- Solicitudes de amistad -\n";
    requests._received.forEach(
        [&](const FriendRequest& request){
            output<<n++<<") "<<request<<"\n"; 
        }
    );
    return output;
}