#include <iostream>
#include "tools/listTemplate.h"
#include "tools/str.h"
#include "databases/fileManager.h"

int main(){
    str database = "databases/users.txt"; 
    List<str> info; 
    FileManager::read(database, info); 
    int n = info.getLen(); 

    for(int k=0; k<n; k++){
        std::cout<<info[k]<<std::endl; 
    }

    

    return 0; 
}