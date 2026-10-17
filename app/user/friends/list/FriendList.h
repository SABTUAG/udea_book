#ifndef FRIEND_LIST_H
#define FRIEND_LIST_H

#include <iostream>
#include "listTemplate.h"

/**
 * @brief Gestiona los amigos del usuario por IDs.
 */
class FriendList {
    
private:
    List<int> _friendIDs;

public:
    FriendList();

    const List<int>& getIDs() const;
    List<int>& getIDs();

    bool contains(int id) const;
    bool add(int id);
    bool remove(int id);

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