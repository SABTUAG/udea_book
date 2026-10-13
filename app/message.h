#ifndef MESSAGE_H
#define MESSAGE_H

#include <string>

#include "listTemplate.h"
#include "console.h"

// Mensajes únicamente entre amigos.
class Message {
private:
    std::string _message;
    std::string _shippingDate;
    bool _read;

public:
    // Constructores
    Message(std::string message, bool read) : _message(message), _read(read) {}

    // Getters
    std::string getMessage() const {
        return _message;
    };
    std::string getShippingDate() const {
        return _shippingDate; 
    }
    bool getRead() const {
        return _read; 
    };

    // Setters
    bool setRead(bool marked) {
        _read = marked; 
    }
    // Acciones de mensajes
};

class Chat {
private:
    //::string _userName;
    std::string _friendName;
    List<Message> _messagesReceived;
    List<Message> _messagesSend;

public:
    // Constructor

    // Getters
    std::string getFriendName() const {
        return _friendName; 
    }
    List<Message> getMessagesReceived() const {
        return _messagesReceived; 
    }
    List<Message> getMessagesSend() const {
        return _messagesSend; 
    }
    
    // Acciones que se pueden hacer en el chat
    bool addMessage(){
        //...
    }

    bool deleteMessages(){
        //...
    }

    // Configuracion manual 
    void editChat(){
        return;
    }
    
};

class Chats {
private:
    List<Chat> _chats;
    // Las conversaciones se organizan en una lista de chats.
    // 
public:
    // constructor

    //Getters
    List<Chat> getChats() const {
        return _chats; 
    }

    // Acciones de chats
    bool startNewChat(std::string FriendName){
        // ...
    }
    bool deleteChat(std::string FriendName){
        //...
    }

};

#endif
