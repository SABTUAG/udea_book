#include <iostream>
#include "tools/listTemplate.h"
#include "tools/str.h"
#include "databases/fileManager.h"
#include "app/plataform.h"

int main(){
    const str database = "databases/users.txt"; 
    Plataform udeabook(database); 

    return 0; 
}