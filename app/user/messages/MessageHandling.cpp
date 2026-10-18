#include "MessageHandling.h"

MessageHandling::MessageHandling(): 
    _sent(), 
    _received() {}
MessageHandling::MessageHandling(
    const str& ownerNameID, 
    const str& content
): 
    _sent(), 
    _received() 
{
    List<str> lineas = content.split('\n');
    lineas.forEach([&](const str& lineaOriginal) {
        str linea = lineaOriginal.strip(); // Quita \r y espacios
        if (linea.len() == 0) return;

        // Formato esperado: sender|receiver|texto|fecha|read
        List<str> campos = linea.split('|');
        
        if (campos.getLen() >= 5) {
            str sender = campos[0].strip();
            str receiver = campos[1].strip();
            str texto = campos[2].strip();
            str fecha = campos[3].strip();
            bool read = (campos[4].strip() == "1" || campos[4].strip() == "true");

            Message msg(sender, receiver, texto, fecha, read);

            // Si el dueño es el emisor, va a enviados. Si es el receptor, a recibidos.
            if (sender == ownerNameID) {
                _sent.add(msg);
            } else if (receiver == ownerNameID) {
                _received.add(msg);
            }
        }
    });
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