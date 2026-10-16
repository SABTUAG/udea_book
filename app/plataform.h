#ifndef PLATAFORM_H
#define PLATAFORM_H

#include "listTemplate.h"
#include "fileManagement.h"
#include "console.h"
#include "str.h"
#include "FriendNetwork.h"
#include "gallery.h"
#include "album.h"
#include "message.h"

/**
 * @brief Representa la plataforma donde interactuan los usuarios
 */
class Plataform {
private:
    List<User*> _users;
public:
    Plataform();
};

#endif
