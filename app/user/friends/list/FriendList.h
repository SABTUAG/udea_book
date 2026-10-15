#ifndef FRIEND_LIST_H
#define FRIEND_LIST_H

#include "listTemplate.h"

/**
 * @brief Gestiona los amigos del usuario por IDs
 */
class FriendList {
private:
    List<int> _friendIDs;  

public:
    FriendList();

    const List<int>& getIDs() const { return _friendIDs; }
    List<int>& getIDs() { return _friendIDs; }
    //int getCount() const { return _friendIDs.getSize(); }

    // Mejorar despues para busquedas más rapida con tools
    bool contains(int id) const { 
        return _friendIDs.search(id); 
    }
    bool add(int id) { 
        return _friendIDs.add(id); 
    }
    bool remove(int id) { 
        return _friendIDs.remove(id); 
    }
};

#endif