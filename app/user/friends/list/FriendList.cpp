#include "FriendList.h"

FriendList::FriendList(): 
    _friends() {}

FriendList::FriendList(const List<str>& friends):
    _friends(friends) {}


const List<str>& FriendList::getNameIDs() const {
    return _friends;
}
List<str>& FriendList::getNameIDs(){
    return _friends;
}



bool FriendList::contains(const str& nameID) const {
    return _friends.search(nameID);
}
bool FriendList::add(const str& nameID){
    return _friends.add(nameID);
}
bool FriendList::remove(const str& nameID){
    return _friends.remove(nameID);
}


std::ostream& operator<<(
    std::ostream& output, 
    const FriendList& friendlist
){
    int n = 1; 
    output<<"- Amigos -\n"; 
    friendlist._friends.forEach(
        [&](const str& nameID){
            output<<n++<<") "<<nameID<<"\n"; 
        }
    ); 
    return output; 
}