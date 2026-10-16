#include "User.h"

User::User(
    int id, 
    const str& nameID, 
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
    _messages(), 
    _gallery() {}


int User::getID() const {
    return _id;
}

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

FriendNetwork& User::getFriends() {
    return _friends;
}

const FriendNetwork& User::getFriends() const {
    return _friends;
}

MessageHandling& User::getMessages() {
    return _messages;
}

const MessageHandling& User::getChats() const {
    return _messages;
}

Gallery& User::getGallery() {
    return _gallery;
}

const Gallery& User::getGallery() const {
    return _gallery;
}



void User::setEmail(const str& email) {
    _email = email;
}

void User::setCity(const str& city) {
    _city = city;
}

void User::setCountry(const str& country) {
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
    const User& userN
){
    output << userN._nameID;
    return output;
}