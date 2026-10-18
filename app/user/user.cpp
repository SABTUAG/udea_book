#include "User.h"

// ==========================================
// FUNCIONES AUXILIARES DE PARSEO
// ==========================================

// Extrae el valor de algo como "NAMEID:juanito76;"
static str extractValue(const str& block, const str& key) {
    int pos = block.find(key);
    if (pos == str::NPOS) return "";
    
    int start = pos + key.len();
    int end = start;
    
    // Avanzamos hasta encontrar un ';', un salto de línea o un corchete
    while (
        (end < block.len()) && 
        (block[end] != ';') && 
        (block[end] != '\n') && 
        (block[end] != '[')
    ) {
        end++;
    }
    
    // Extraemos el texto y le quitamos espacios en blanco de los bordes
    str rawValue = block.substr(start, end - start);
    return rawValue.strip();
}

// Extrae el texto que está entre corchetes: FRIENDNETWORK[ ... ]
static str extractBlock(const str& block, const str& key) {
    int pos = block.find(key);
    if (pos == str::NPOS) return "";
    
    // Recortamos el bloque para empezar a buscar desde la palabra clave
    str subBlock = block.substr(pos, block.len() - pos);
    
    int start = subBlock.find('[');
    int end = subBlock.find(']');
    
    if (start == str::NPOS || end == str::NPOS) return "";
    return subBlock.substr(start + 1, end - start - 1);
}

// ==========================================
// CONSTRUCTORES
// ==========================================

User::User(): 
    _nameID(""), 
    _birthDate(""), 
    _email(""), 
    _password(""), 
    _city(""), 
    _country(""), 
    _registrationDate(""),
    _friends(), 
    _messages(), 
    _gallery() {}

User::User(const str& block) {
    // 1. Extraer datos básicos
    _nameID = extractValue(block, "NAMEID:");
    _birthDate = extractValue(block, "BIRTHDATE:");
    _email = extractValue(block, "EMAIL:");
    _password = extractValue(block, "PASSWORD:");
    _city = extractValue(block, "CITY:");
    _country = extractValue(block, "COUNTRY:");
    _registrationDate = extractValue(block, "REGISTRATIONDATE:");

    // 2. Extraer los sub-bloques [ ... ]
    str friendsBlock = extractBlock(block, "FRIENDNETWORK");
    str messagesBlock = extractBlock(block, "MESSAGESHANDLING");
    str galleryBlock = extractBlock(block, "GALLERY");

    // 3. Construir los subsistemas pasándoles su texto
    // (Asumiendo que ya agregaste los constructores que reciben str en cada uno)
    _friends = FriendNetwork(friendsBlock);
    _messages = MessageHandling(_nameID, messagesBlock);
    _gallery = Gallery(galleryBlock);
}

User::User(
    const str& nameID, 
    const str& birthDate, 
    const str& email,
    const str& password, 
    const str& city, 
    const str& country,
    const str& registrationDate
): 
    _nameID(nameID),
    _birthDate(birthDate), 
    _email(email),
    _password(password), 
    _city(city), 
    _country(country),
    _registrationDate(registrationDate),
    _friends(), 
    _messages(), 
    _gallery() {}

// ==========================================
// GETTERS Y SETTERS
// ==========================================

const str& User::getNameID() const {
    return _nameID;
}
const str& User::getBirthDate() const {
    return _birthDate;
}
const str& User::getEmail() const {
    return _email;
}
const str& User::getPassword() const {
    return _password; 
}
const str& User::getCity() const {
    return _city;
}
const str& User::getCountry() const {
    return _country;
}
const str& User::getRegistrationDate() const {
    return _registrationDate;
}
FriendNetwork& User::getFriends(){
    return _friends;
}
const FriendNetwork& User::getFriends() const {
    return _friends;
}
MessageHandling& User::getMessages(){
    return _messages;
}
const MessageHandling& User::getMessages() const {
    return _messages;
}
Gallery& User::getGallery(){
    return _gallery;
}
const Gallery& User::getGallery() const {
    return _gallery;
}

void User::setEmail(const str& email){
    _email = email;
}
void User::setCity(const str& city){
    _city = city;
}
void User::setCountry(const str& country){
    _country = country;
}

// ==========================================
// OPERADORES
// ==========================================

bool User::operator==(const User& otherUser) const {
    return _nameID == otherUser._nameID;
}
bool User::operator!=(const User& otherUser) const {
    return !(*this == otherUser);
}
bool User::operator<(const User& otherUser) const {
    return _registrationDate < otherUser._registrationDate;
}

std::ostream& operator<<(
    std::ostream& output, 
    const User& user
){
    output << user._nameID;
    return output;
}