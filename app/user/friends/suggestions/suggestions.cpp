#include "suggestions.h"

FriendSuggestion::FriendSuggestion(): 
    _nameID(""), 
    _commonFriends(0) {}
FriendSuggestion::FriendSuggestion(
    const str& nameID, 
    int commonFriends
): 
    _nameID(nameID), 
    _commonFriends(commonFriends) {}


const str& FriendSuggestion::getNameID() const {
    return _nameID;
}
int FriendSuggestion::getCommonFriends() const {
    return _commonFriends;
}
void FriendSuggestion::incrementCommonFriends(){
    _commonFriends++;
}


bool FriendSuggestion::operator==(
    const FriendSuggestion& other
) const {
    return _nameID == other._nameID;
}
bool FriendSuggestion::operator<(
    const FriendSuggestion& other
) const {
    return _commonFriends > other._commonFriends;
}