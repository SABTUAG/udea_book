#include "tools/listTemplate.h"
#include "tools/str.h"
#include "databases/fileManager.h"
#include <iostream>

int main(){
    str database = "databases/users.txt"; 
    List<str> info; 
    FileManager::read(database, info); 
    
    return 0; 
}