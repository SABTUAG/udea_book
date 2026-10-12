#ifndef PASSWORD_H
#define PASSWORD_H

#include <string>

class Password {
private:
    std::string _password;
    std::string _messageToRecover;

public:
    Password(std::string password);
    Password(std::string password, std::string messageToRecover);
};

#endif
