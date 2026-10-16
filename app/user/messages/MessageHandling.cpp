#include "MessageHandling.h"

MessageHandling::MessageHandling(): 
    _sent(), 
    _received() {}

/* Revisar constructor 
MessageHandling::MessageHandling(
    int ownerID, 
    const str& content
): 
    _sent(), 
    _received() 
{
    // Dividir el contenido por líneas ('\n') y procesar cada una
    int start = 0;
    for (int i = 0; i <= content.len(); i++) {
        if (i == content.len() || content[i] == '\n') {
            // Extraer línea actual
            str linea;
            for (int j = start; j < i; j++) {
                linea += str(content[j]);
            }
            start = i + 1;

            if (linea.len() == 0) continue;   // línea vacía

            // Parsear campos: senderID;receiverID;texto;date;read
            int senderID = extraerCampoInt(linea, 0);
            int receiverID = extraerCampoInt(linea, 1);
            str texto = extraerCampoStr(linea, 2);
            str date = extraerCampoStr(linea, 3);
            bool read = (extraerCampoStr(linea, 4) == "1");

            Message msg(senderID, receiverID, texto, date, read);

            if (senderID == ownerID) {
                _sent.add(msg);
            } else if (receiverID == ownerID) {
                _received.add(msg);
            }
        }
    }
}
*/


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
        [&](Message& msgN){
            if (!msgN.getRead()){
                msgN.setRead(true);
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