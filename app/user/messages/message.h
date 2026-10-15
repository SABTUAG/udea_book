#ifndef MESSAGE_H
#define MESSAGE_H

#include <string>
#include "listTemplate.h"
#include "str.h"
#include "console.h"

/**
 * @brief Representa un mensaje enviado por un usuario a otro usuario. 
 */
class Message {
private:
    int _senderID; 
    int _receiverID; 
    str _message;
    str _shippingDate;
    bool _read;

public:
    Message(
        int senderID,
        int receiverID,
        const str& message, 
        bool read
    ): 
        _message(message), 
        _read(read) {}

    str getMessage() const { 
        return _message; 
    }
    str getShippingDate() const { 
        return _shippingDate; 
    }
    bool getRead() const {
        return _read; 
    }

    bool setRead(bool marked) {
        _read = marked; 
    }

};


#endif
