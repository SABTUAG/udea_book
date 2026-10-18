#include "image.h"

Image::Image(): 
    _publicationDate(""), 
    _size(0), _filePath(""), 
    _likes(0) {}
Image::Image(
    const str& filePath, 
    const str& publicationDate,
    int size, 
    int likes
): 
    _publicationDate(publicationDate), 
    _size(size),
    _filePath(filePath), 
    _likes(likes) {}


const str& Image::getPublicationDate() const {
    return _publicationDate;
}
int Image::getSize() const {
    return _size;
}
const str& Image::getFilePath() const {
    return _filePath;
}
int Image::getLikes() const {
    return _likes;
}


void Image::addLike(){
    _likes++;
}
void Image::removeLike(){
    if (_likes > 0) _likes--;
}


bool Image::operator==(const Image& otherImg) const {
    return _filePath == otherImg._filePath;
}
bool Image::operator!=(const Image& otherImg) const {
    return !(*this == otherImg);
}
bool Image::operator<(const Image& otherImg) const {
    return _publicationDate < otherImg._publicationDate;
}


std::ostream& operator<<(
    std::ostream& output, 
    const Image& img
){
    output <<img._filePath;
    return output;
}