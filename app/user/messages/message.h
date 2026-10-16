#ifndef MESSAGE_H
#define MESSAGE_H

#include <iostream>
#include "str.h"

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
    Message();
    Message(
        int senderID,
        int receiverID,
        const str& message,
        const str& shippingDate,
        bool read
    );

    int getSenderID() const;
    int getReceiverID() const;
    const str& getMessage() const;
    const str& getShippingDate() const;
    bool getRead() const;

    void setRead(bool marked);

    bool operator==(const Message& otherMsg) const;
    bool operator!=(const Message& otherMsg) const;
    bool operator<(const Message& otherMsg) const;

    friend std::ostream& operator<<(
        std::ostream& output, 
        const Message& msgN
    );
};

std::ostream& operator<<(
    std::ostream& output, 
    const Message& msgN
);

#endif