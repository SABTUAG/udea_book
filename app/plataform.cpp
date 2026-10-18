#include "plataform.h"

Plataform::Plataform(const str& databasePath){
    FileManager::read(databasePath+"users.txt"); 
}

void Plataform::loadUsers(const str& database){
    List<str> block; 
    if (!FileManager::read(database,block)) return; 
    block.forEach(
        [&](const str& block){
            str cleanBlock = ""; 
            for(int n=0; n<block.len(); n++){
                if (block[n] != '\n' && block[n] != '\r'){
                    cleanBlock += str(block[n]); 
                }
            }
        }
    ); 
}