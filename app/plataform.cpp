#include "plataform.h"

Plataform::Plataform(const str& database){
    FileManager::read(database, _usersInfo); 
}
