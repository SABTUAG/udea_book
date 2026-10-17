#include "Album.h"

Album::Album(
    const str& name, 
    const str& filepath, 
    const str& privacy
):
    _name(name), 
    _filePath(filepath), 
    _privacy(privacy), 
    _images() {}


const str& Album::getName() const {
    return _name;
}
const str& Album::getFilePath() const {
    return _filePath;
}
const str& Album::getPrivacy() const {
    return _privacy;
}
const List<Image>& Album::getImages() const {
    return _images;
}
List<Image>& Album::getImages() {
    return _images;
}


void Album::setName(const str& name){
    _name = name;
}
void Album::setPrivacy(const str& privacy){
    _privacy = privacy;
}


bool Album::addImage(const Image& image){
    return _images.add(image);
}
bool Album::removeImage(const Image& image){
    return _images.remove(image);
}


bool Album::containsImage(const Image& image) const {
    return _images.search(image);
}


bool Album::operator==(const Album& otherAlbum) const {
    return _name == otherAlbum._name;
}
bool Album::operator!=(const Album& otherAlbum) const {
    return !(*this == otherAlbum);
}
bool Album::operator<(const Album& otherAlbum) const {
    return _name < otherAlbum._name;
}


std::ostream& operator<<(
    std::ostream& output, 
    const Album& album
){
    output << album._filePath;
    return output;
}