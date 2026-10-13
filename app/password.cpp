#include "password.h"

Password::Password(std::string password)
    : _password(password) {
}

Password::Password(std::string password, std::string messageToRecover)
    : _password(password), _messageToRecover(messageToRecover) {
}