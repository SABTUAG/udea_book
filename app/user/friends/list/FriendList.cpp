#include "FriendList.h"

FriendList::FriendList(): 
    _friendIDs() {}


const List<int>& FriendList::getIDs() const {
    return _friendIDs;
}
List<int>& FriendList::getIDs() {
    return _friendIDs;
}


bool FriendList::contains(int id) const {
    return _friendIDs.search(id);
}
bool FriendList::add(int id) {
    return _friendIDs.add(id);
}
bool FriendList::remove(int id) {
    return _friendIDs.remove(id);
}