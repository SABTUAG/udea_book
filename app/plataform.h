#ifndef PLATAFORM_H
#define PLATAFORM_H

#include <iostream>
#include "../databases/fileManager.h"
#include "../tools/console.h"
#include "../tools/date.h"
#include "../tools/efficiency.h"
#include "../tools/listTemplate.h"
#include "../tools/str.h"
#include "user/friends/FriendNetwork.h"
#include "user/images/gallery.h"
#include "user/messages/MessageHandling.h"
#include "user/user.h"

/**
 * @brief Representa la plataforma donde interactuan los usuarios.
 */
class Plataform {

private:
    List<User> _users; 
    void loadUsers(const str& database); 

public:
    Plataform(const str& databasePath); 
    
    User* findUserByName(const str& nameID); 
};

#endif
