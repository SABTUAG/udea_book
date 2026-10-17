#ifndef FRIEND_LIST_H
#define FRIEND_LIST_H

#include <iostream>
#include "str.h"
#include "listTemplate.h"

/**
 * @brief Gestiona los amigos del usuario por nameIDs.
 */
class FriendList {
    
private:
    List<str> _friends; 

public:
    FriendList();
    FriendList(const List<str>& friends); 

    const List<str>& getNameIDs() const;
    List<str>& getNameIDs();

    bool contains(const str& nameID) const;
    bool add(const str& nameID);
    bool remove(const str& nameID);

    friend std::ostream& operator<<(
        std::ostream& output, 
        const FriendList& friendlist
    ); 
};

std::ostream& operator<<(
    std::ostream& output, 
    const FriendList& friendlist
);

#endif