#include <iostream>
#include "tools/listTemplate.h"
#include "tools/str.h"
#include "databases/fileManager.h"

int main(){
    str database = "databases/users.txt"; 
    List<str> info; 
    FileManager::read(database, info); 
    
    return 0; 
}