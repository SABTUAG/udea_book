#ifndef MESSAGE_HANDLING_H
#define MESSAGE_HANDLING_H

#include <string>
#include "listTemplate.h"
#include "str.h"
#include "console.h"
#include "message.h"

/**
 * @brief Representa los mensajes enviados y recibidos de cada usuario. 
 */
class MessageHandling {
private:
    List<Message> _sent;  
    List<Message> _received; 

public:
    MessageHandling(); 

    List<Message>& getSent();  

};

#endif
