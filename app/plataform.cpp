#include "plataform.h"
#include <cstdlib>
#include <ctime>


void Plataform::loadUsers(const str& database){
    List<str> blocks; 
    if (!FileManager::read(database,blocks)) return; 
    blocks.forEach(
        [&](const str& block){
            User newUser(block); 
            _users.add(newUser);
        }
    ); 
}
User* Plataform::findUserByName(const str& nameID){
    User* found = nullptr;
    _users.forEach(
        [&](User& user){
            if (user.getNameID()==nameID) found=&user;
        }
    );
    return found;
}
bool Plataform::loginUser() {
    std::cout<<"** Iniciar sesion **\n";
    str nameID=Console::inputStr(
        "Usuario: ",
        "abcdefghijklmnopqrstuvwxyz0123456789",
        50
    );
    User* user=findUserByName(nameID);
    if (user==nullptr){
        std::cout<<"Usuario no encontrado.\n";
        return false;
    }
    str pass = Console::inputStr(
        "Contrasena: ",
        "abcdefghijklmnopqrstuvwxyz0123456789",
        50
    );
    if (user->getPassword()!=pass) {
        std::cout<<"Contrasena incorrecta.\n";
        return false;
    }
    _currentUser=user;
    return true;
}


Plataform::Plataform(const str& databasePath): 
    _currentUser(nullptr), 
    _profilePicsUpdated(false)
{
    srand(time(0)); 
    loadUsers(databasePath); 
}
