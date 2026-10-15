#ifndef PLATAFORM_H
#define PLATAFORM_H

#include <string>

#include "user/user.h"
#include "listTemplate.h"
#include "console.h"
#include "fileManagement.h"

/**
 * @brief Para representar la plaforma donde interactuan los usuarios
 */
class Plataform {
private:
    List<User*> _users;
public:
    Plataform();

    void readDB(); 
    void start(); 
};

#endif
