#ifndef USER_H
#define USER_H

#include <iostream>
#include "../../tools/str.h"
#include "../../tools/date.h"
#include "friends/FriendNetwork.h"
#include "images/Gallery.h"
#include "messages/MessageHandling.h"

/**
 * @brief Representa un usuario en la red Social udeabook.
 * 
 * Almacena los datos personales del usuario y se
 * compone por subistemas que modelan su actividad en la 
 * plataforma. Los subsistemas son: red de amigos, gestor de 
 * mensajes y galería de imágenes.
 * 
 * Los usuarios se identifican por un id numérico único, y las 
 * relaciones entre ellos se guardan por medio de estos ids, no 
 * por punteros. Esto simplifica la carga desde archivo y evita 
 * dependencias circulares entre clases.
 * 
 * Los subsistemas se almacenan por composición: si la cuenta
 * del usuario es destruida, sus subsistemas también, 
 * liberando toda la memoria asociada de forma automática.
 */
class User {

private: 
    str _nameID;
    str _birthDate;
    str _email;
    str _password;
    str _city;
    str _country;
    str _registrationDate;
    FriendNetwork _friends;
    MessageHandling _messages;
    Gallery _gallery;

public:
    User(const str& block);
    User( 
        const str& nameID, 
        const str& birthDate, 
        const str& email,
        const str& password, 
        const str& city, 
        const str& country,
        const str& registrationDate
    );
    User(); 

    
    const str& getNameID() const;
    const str& getBirthDate() const;
    const str& getEmail() const;
    const str& getCity() const;
    const str& getCountry() const;
    const str& getRegistrationDate() const;
    FriendNetwork& getFriends();
    const FriendNetwork& getFriends() const;
    MessageHandling& getMessages();
    const MessageHandling& getMessages() const;
    Gallery& getGallery();
    const Gallery& getGallery() const;
   

    void setEmail(const str& email); 
    void setCity(const str& city);
    void setCountry(const str& country);

    bool operator==(const User& otherUser) const;
    bool operator!=(const User& otherUser) const;
    bool operator<(const User& otherUser) const;

    friend std::ostream& operator<<(
        std::ostream& output, 
        const User& user
    );

};

std::ostream& operator<<(
    std::ostream& output, 
    const User& user
);

#endif
