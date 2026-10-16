#include "message.h"

Message::Message(
    int senderID,
    int receiverID,
    const str& message,
    const str& shippingDate,
    bool read
): 
    _senderID(senderID), 
    _receiverID(receiverID),
    _message(message), 
    _shippingDate(shippingDate), 
    _read(read) {}


int Message::getSenderID() const {
    return _senderID;
}
int Message::getReceiverID() const {
    return _receiverID;
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


void Message::setRead(bool marked) {
    _read = marked;
}


bool Message::operator==(const Message& otherMsg) const {
    return (
        (_senderID == otherMsg._senderID) &&
        (_receiverID == otherMsg._receiverID) &&
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
    const Message& msgN
){
    output << "[" << msgN._shippingDate << "] "
       << msgN._senderID << " -> "
       << ": " << msgN._message;
    return output;
}