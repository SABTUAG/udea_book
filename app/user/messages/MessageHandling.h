#ifndef MESSAGE_HANDLING_H
#define MESSAGE_HANDLING_H

#include <string>
#include "listTemplate.h"
#include "str.h"
#include "console.h"
#include "message.h"

/**
 * @brief Representa el gestor de los mensajes recibidos de cada usuario. 
 */
class MessageHandling {
private:
    List<Message> _received; 

public:
    MessageHandling(); 

    List<Message>& getReceived(){
        return _received; 
    };  

};

#endif
