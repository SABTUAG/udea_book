#ifndef MESSAGE_H
#define MESSAGE_H

#include <iostream>
#include "str.h"

/**
 * @brief Representa un mensaje enviado entre dos usuarios.
 * 
 * Almacena el nameID del emisor y del receptor, el 
 * texto del mensaje, la fecha de envío y su estado de lectura.
 * 
 * Es necesario guardar tanto al emisor como al receptor porque 
 * el mensaje se registra en dos lugares distintos: en el 
 * historial de enviados del emisor y en la bandeja de 
 * recibidos del receptor. Al mostrar la bandeja, se requiere 
 * saber quién envió el mensaje.
 * 
 * El estado de lectura solo aplica para los mensajes recibidos, 
 * permitiendo identificar cuáles son nuevos.
 */
class Message {

private:
    str _sender;
    str _receiver;
    str _message;
    str _shippingDate;
    bool _read;

public:
    Message();
    Message(
        const str& senderID,
        const str& receiverID,
        const str& message,
        const str& shippingDate,
        bool read
    );

    const str& getSender() const;
    const str& getReceiver() const;
    const str& getMessage() const;
    const str& getShippingDate() const;
    bool getRead() const;

    void setRead(bool marked);

    bool operator==(const Message& otherMsg) const;
    bool operator!=(const Message& otherMsg) const;
    bool operator<(const Message& otherMsg) const;

    friend std::ostream& operator<<(
        std::ostream& output, 
        const Message& msg
    );
};

std::ostream& operator<<(
    std::ostream& output, 
    const Message& msg
);

#endif