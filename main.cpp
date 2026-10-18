#include <iostream>
#include "tools/str.h"
#include "app/plataform.h"

int main(){
    const str database="databases/users.txt"; 
    Plataform udeabook(database); 
    udeabook.start(); 

    return 0; 
}