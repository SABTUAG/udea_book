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

/**
 * @brief Representa la plataforma donde interactúan los usuarios.
 * 
 * Actúa como el orquestador principal del sistema 
 * Ude@Book. Es la única clase con acceso global a todos 
 * los usuarios (la List<User>), lo que le permite resolver 
 * operaciones que cruzan múltiples cuentas.
 * 
 * Gestiona el ciclo de vida del sistema: carga inicial de 
 * datos desde el archivo, inicio de sesión y el 
 * bucle principal del menú de consola.
 * 
 * Delega la lógica de dominio a las clases correspondientes 
 * (como User, FriendNetwork y MessageHandling), encargándose 
 * únicamente de coordinar la interacción entre el usuario 
 * activo y los demás subsistemas.
 * 
 * Además, integra la clase Efficiency para medir el consumo 
 * de recursos (iteraciones y memoria) en cada una de las 
 * funcionalidades del menú, cumpliendo con el punto VII 
 * exigido en el desafío.
 */
class Plataform {

private:
    List<User> _users; 
    User* _currentUser;
    bool _profilePicsUpdated; 

    void loadUsers(const str& database);
    User* findUserByName(const str& nameID); 
    bool loginUser(); 
    
    //friendship management menu
    void FriendShipManagementMenu();
    void menuMensajes();
    void menuSugerencias();
    void visitarPerfil();
    void mostrarFotosPerfil();
    void carruselFotos(Album& album);

public:
    Plataform(const str& databasePath); 
    
    void start(); 
};

#endif