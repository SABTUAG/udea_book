#include "plataform.h"

Plataform::Plataform(const str& databasePath){
    // 1. Llamamos a loadUsers pasándole la ruta del archivo
    loadUsers(databasePath); 
}

void Plataform::loadUsers(const str& database){
    List<str> blocks; 
    
    // 2. Intentamos leer el archivo. Si falla, salimos.
    if (!FileManager::read(database, blocks)) return; 
    
    // 3. Por cada bloque { ... } leído...
    blocks.forEach([&](const str& block){
        // El constructor de User ya sabe extraer la info del bloque
        User newUser(block); 
        
        // Lo agregamos a la lista global de la plataforma
        _users.add(newUser);
    }); 
}

User* Plataform::findUserByName(const str& nameID){
    User* found = nullptr;
    
    // Recorremos la lista de usuarios
    _users.forEach([&](User& user){
        if (user.getNameID() == nameID){
            // Guardamos la dirección de memoria del usuario encontrado
            found = &user; 
        }
    });
    
    return found;
}