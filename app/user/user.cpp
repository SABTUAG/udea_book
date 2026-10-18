#include "User.h"

str extractValue(
    const str& block, 
    const str& key)
{
    int pos=block.find(key);
    if (pos == str::NPOS) return "";
    int start = pos + key.len();
    int end = start;
    
    // Avanzamos hasta encontrar un ';', un salto de línea o un corchete
    while (
        (end < block.len()) && 
        (block[end] != ';') && 
        (block[end] != '\n') && 
        (block[end] != '[')
    ) end++;
    
    str result = "";
    for (int i=start; i<end; i++){
        if (block[i]!='\r' && block[i]!=' '){
            result+=block[i];
        }
    }
    return result;
}


User::User(const str& block){
    // 1. Extraer los datos básicos
    str nameID = extractValue(block, "NAMEID:");
    str birthDate = extractValue(block, "BIRTHDATE:");
    str email = extractValue(block, "EMAIL:");
    str password = extractValue(block, "PASSWORD:");
    str city = extractValue(block, "CITY:");
    str country = extractValue(block, "COUNTRY:");
    str regDate = extractValue(block, "REGISTRATIONDATE:");
    _nameID = nameID;
    _birthDate = birthDate;
    _email = email;
    _password = password;
    _city = city;
    _country = country;
    _registrationDate = regDate;
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
    _birthDate(birthDate), 
    _email(email),
    _password(password), 
    _city(city), 
    _country(country),
    _registrationDate(registrationDate),
    _friends(), 
    _messages(), 
    _gallery() {}


const str& User::getNameID() const {
    return _nameID;
}
const str& User::getBirthDate() const {
    return _birthDate;
}
const str& User::getEmail() const {
    return _email;
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



bool User::operator==(const User& otherUser) const {
    return _nameID == otherUser._nameID;
}
bool User::operator!=(const User& otherUser) const {
    return !(*this == otherUser);
}
bool User::operator<(const User& otherUser) const {
    return _id < otherUser._id;
}


std::ostream& operator<<(
    std::ostream& output, 
    const User& user
){
    output << user._nameID;
    return output;
}