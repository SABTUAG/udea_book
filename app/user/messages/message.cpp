#include "message.h"

Message::Message(
    const str& sender,
    const str& receiver,
    const str& message,
    const str& shippingDate,
    bool read
): 
    _sender(sender), 
    _receiver(receiver),
    _message(message), 
    _shippingDate(shippingDate), 
    _read(read) {}


const str& Message::getSender() const {
    return _sender;
}
const str& Message::getReceiver() const {
    return _receiver;
}
const str& Message::getMessage() const {
    return _message;
}
const str& Message::getShippingDate() const {
    return _shippingDate;
}
bool Message::getRead() const {
    return _read;
}


void Message::setRead(bool marked){
    _read = marked;
}


bool Message::operator==(const Message& otherMsg) const {
    return (
        (_sender == otherMsg._sender) &&
        (_receiver == otherMsg._receiver) &&
        (_shippingDate == otherMsg._shippingDate)
    );
}
bool Message::operator!=(const Message& otherMsg) const {
    return !(*this == otherMsg);
}
bool Message::operator<(const Message& otherMsg) const {
    return _shippingDate < otherMsg._shippingDate;
}


std::ostream& operator<<(
    std::ostream& output, 
    const Message& msg
){
    output << "[" << msg._shippingDate << "] "
       << msg._sender << " -> "
       << ": " << msg._message;
    return output;
}