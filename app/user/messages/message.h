#ifndef MESSAGE_H
#define MESSAGE_H

#include <iostream>
#include "str.h"

/**
 * @brief Representa un mensaje enviado por un usuario a otro usuario.
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