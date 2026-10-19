#include "User.h"
#include "../../tools/Parser.h"

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

User::User(const str& block){
    _nameID = extractValue(block, "NAMEID:");
    _birthDate = extractValue(block, "BIRTHDATE:");
    _email = extractValue(block, "EMAIL:");
    _password = extractValue(block, "PASSWORD:");
    _city = extractValue(block, "CITY:");
    _country = extractValue(block, "COUNTRY:");
    _registrationDate = extractValue(block, "REGISTRATIONDATE:");
    str friendsBlock = extractBlock(block, "FRIENDNETWORK");
    str messagesBlock = extractBlock(block, "MESSAGESHANDLING");
    str galleryBlock = extractBlock(block, "GALLERY");
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