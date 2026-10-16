#ifndef MESSAGE_HANDLING_H
#define MESSAGE_HANDLING_H

#include "listTemplate.h"
#include "str.h"
#include "message.h"

/**
 * @brief Gestiona los mensajes enviados y recibidos de un usuario.
 */
class MessageHandling {

private:
    List<Message> _sent;       
    List<Message> _received;   

public:
    MessageHandling();
    MessageHandling(int ownerID, const str& content);

    const List<Message>& getSent() const;
    List<Message>& getSent();
    const List<Message>& getReceived() const;
    List<Message>& getReceived();

    bool addSent(const Message& msg);
    bool addReceived(const Message& msg);

    /**
     * @brief Marca todos los mensajes recibidos como leídos.
     */
    int markAllReceivedAsRead();
    /**
     * @brief Cuenta los mensajes recibidos no leídos.
     */
    int countUnread() const;
    /**
     * @brief Verifica si hay mensajes no leídos.
     */
    bool hasUnread() const;
    /**
     * @brief Filtra los mensajes recibidos en un rango de fecha.
     * @param inicio Fecha de inicio (inclusive, formato ISO).
     * @param fin Fecha de fin (inclusive).
     * @return Lista de mensajes en el rango.
     * @pre inicio <= fin
     * @note Complejidad: O(n).
     */
    List<Message> filterReceivedByDateRange(
        const str& start, 
        const str& end
    ) const;
};

#endif