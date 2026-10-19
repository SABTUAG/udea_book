#include "MessageHandling.h"
#include "../tools/parser.h"


MessageHandling::MessageHandling(): 
    _sent(), 
    _received() {}

MessageHandling::MessageHandling(
    const str& ownerNameID, 
    const str& block
){
    str sentStr = extractParens(block, "SENT:");
    if (sentStr.len() > 0){
        List<str> msgs = sentStr.split(';');
        msgs.forEach(
            [&](const str& msg){
                List<str> msgAtributes = msg.split('|');
                if (msgAtributes.getLen()>= 3){
                    _sent.add(
                        Message(
                            ownerNameID, 
                            msgAtributes[0].strip(), 
                            msgAtributes[1].strip(), 
                            msgAtributes[2].strip(), 
                            true
                        )
                    );
                }
            }
        );
    }
    str recvStr = extractParens(block, "RECEIVER:");
    if (recvStr.len() > 0) {
        List<str> msgs = recvStr.split(';');
        msgs.forEach(
            [&](const str& msg) {
                List<str> msgAtributes = msg.split('|');
                if (msgAtributes.getLen() >= 3){
                    _received.add(
                        Message(
                            msgAtributes[0].strip(), 
                            ownerNameID, 
                            msgAtributes[1].strip(), 
                            msgAtributes[2].strip(), 
                            false
                        )
                    );
                }
            }
        );
    }
}


const List<Message>& MessageHandling::getSent() const {
    return _sent;
}
List<Message>& MessageHandling::getSent(){
    return _sent;
}
const List<Message>& MessageHandling::getReceived() const {
    return _received;
}
List<Message>& MessageHandling::getReceived(){
    return _received;
}


bool MessageHandling::addSent(const Message& msg){
    return _sent.add(msg);
}
bool MessageHandling::addReceived(const Message& msg){
    return _received.add(msg);
}
int MessageHandling::markAllReceivedAsRead(){
    int marked = 0;
    _received.forEach(
        [&](Message& msg){
            if (!msg.getRead()){
                msg.setRead(true);
                marked++;
            }
        }
    );
    return marked;
}


int MessageHandling::countUnread() const {
    int count = 0;
    _received.forEach(
        [&](const Message& msgN){
            if (!msgN.getRead()) count++;
        }
    );
    return count;
}
bool MessageHandling::hasUnread() const {
    return countUnread()>0;
}
List<Message> MessageHandling::filterReceivedByDateRange(
    const str& start, 
    const str& end
) const {
    List<Message> result;
    _received.forEach([&](
        const Message& msgN){
            const str& date = msgN.getShippingDate();
            if (date >= start && date <= end){
                result.add(msgN);
            }
        }
    );
    return result;
}