#ifndef PLATAFORM_H
#define PLATAFORM_H

#include <string>

#include "listTemplate.h"
#include "console.h"

class Plataform {
private:
    List<std::string> _namesUsers;

public:
    Plataform();

    // El registro y la eliminación de cuentas corresponden a User.
    bool addUser();
    bool authenticateUser();
};

#endif
