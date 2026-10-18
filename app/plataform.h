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
#include "user/friends/suggestions/suggestions.h"
#include "user/images/gallery.h"
#include "user/messages/MessageHandling.h"
#include "user/user.h"

class Plataform {
private:
    List<User> _users; 
    User* _currentUser;
    bool _profilePicsUpdated; // Para permitir actualizar fotos solo 1 vez

    void loadUsers(const str& database);
    bool loginUser(); 
    
    // Funcionalidades internas
    void menuAmistades();
    void menuMensajes();
    void menuSugerencias();
    void visitarPerfil();
    void mostrarFotosPerfil();
    void carruselFotos(Album& album);

public:
    Plataform(const str& databasePath); 
    
    void start(); // El bucle principal
    User* findUserByName(const str& nameID); 
};

#endif