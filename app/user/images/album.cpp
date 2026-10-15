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

void Album::showPhotos() const {
    std::cout << "Álbum: " << _name 
              << " (" << _images.getLen() << " fotos)\n";
    _images.forEach([](const Image& image) {
        std::cout << "  - " << image.getFilePath() << "\n";
    });
}
/*
std::ostream& operator<<(std::ostream& os, const Album& a) {
    os << "Album[" << a._name << " | ";
    switch (a._privacy) {
        case Privacy::PUBLIC:  os << "público";   break;
        case Privacy::PRIVATE: os << "privado";   break;
        case Privacy::FRIENDS: os << "amigos";    break;
    }
    os << " | " << a._images.getSize() << " fotos]";
    return os;
}*/