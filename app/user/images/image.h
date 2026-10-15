#ifndef IMAGE_H
#define IMAGE_H

#include "str.h"

/**
 * @brief Representa una imagen 
 */
class Image {
    // Cada imagen pertenece a un solo álbum y usa formato PNG
private:
    str _publicationDate;
    int _size;
    str _filePath;
    int _likes;

public: 
    Image(); 
    Image(
        const str& filepath, 
        const str& publicationDate,
        int size,
        int likes
    ); 

    const str& getPublicationDate() const {
        return _publicationDate; 
    }
    int getSize() const {
        return _size; 
    }
    const str& getFilePath() const {
        return _filePath;
    }
    int getLikes() const {
        return _likes; 
    }

    void addLike(){
        _likes++; 
    }
    void removeLike(){
        if (_likes>0) _likes--; 
    }

    bool operator==(const Image& otherImg) const {
        return _filePath == otherImg._filePath;
    }
    bool operator!=(const Image& otherImg) const { 
        return !(*this == otherImg); 
    }
    // para ordenar por fecha, pero recordar que fecha agregar
    // el que permite ver que fecha es mayor
    bool operator<(const Image& otherImg) const {
        return _publicationDate < otherImg._publicationDate; 
    }

    friend std::ostream& operator<<(std::ostream& os, const Image& img);
};

std::ostream& operator<<(std::ostream& os, const Image& img);

#endif
