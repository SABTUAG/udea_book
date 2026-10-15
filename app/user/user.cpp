#include "user.h"
#include "console.h"

User::User(): 
    _id(-1), 
    _nameID(""), 
    _birthDate(),
    _email(""), 
    _password(""),
    _city(""), 
    _country(""), 
    _registrationDate(),
    _friends(),
    _chats(), 
    _gallery() {}

User::User(
    int id, const str& nameID, 
    const str& birthDate, 
    const str& email,
    const str& password, 
    const str& city, 
    const str& country,
    const str& registrationDate
):  
    _id(id), 
    _nameID(nameID), 
    _birthDate(birthDate), 
    _email(email),
    _password(password), 
    _city(city), 
    _country(country),
    _registrationDate(registrationDate),
    _friends(), 
    _chats(), 
    _gallery() {}

/*
void User::showProfile() const {
    std::cout << "=== Perfil de " << _nameID << " (ID " << _id << ") ===\n";
    std::cout << "Ciudad: " << _city << "\n";
    std::cout << "País: " << _country << "\n";
    std::cout << "Amigos: " << _friends.getFriends().getCount() << "\n";
    std::cout << "Álbumes: " << _gallery.getAlbums().getSize() << "\n";
    std::cout << "Chats: " << _chats.getChats().getSize() << "\n";
}
*/
std::ostream& operator<<(std::ostream& os, const User& u) {
    os << u._nameID << " (ID " << u._id << ")";
    return os;
}