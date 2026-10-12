#ifndef MESSAGE_H
#define MESSAGE_H

#include <string>

#include "listTemplate.h"

// Mensajes únicamente entre amigos.
class Message {
private:
    std::string _message;
    std::string _shippingDate;
    bool _read;

public:
    Message(std::string message, bool read) : _message(message), _read(read) {}
    std::string getMessage() const;
    bool getRead() const;
    bool setRead() const;
};

class Chat {
private:
    std::string _userName;
    std::string _friendName;
    List<Message> _messages;

public:
    List<Message> getMessages() const;
    bool sendMessage();
};

class Chats {
private:
    List<Chat> _friends;
    // Las conversaciones se organizan en una lista de chats.
};

#endif
