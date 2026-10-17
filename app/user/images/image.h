#ifndef IMAGE_H
#define IMAGE_H

#include <iostream>
#include "str.h"

/**
 * @brief Representa una imagen.
 */
class Image {

private:
    str _publicationDate;
    int _size;
    str _filePath;
    int _likes;

public:
    Image(
        const str& filepath,
        const str& publicationDate,
        int size,
        int likes
    );

    const str& getPublicationDate() const;
    int getSize() const;
    const str& getFilePath() const;
    int getLikes() const;

    void addLike();
    void removeLike();

    bool operator==(const Image& otherImg) const;
    bool operator!=(const Image& otherImg) const;
    bool operator<(const Image& otherImg) const;

    friend std::ostream& operator<<(
        std::ostream& output, 
        const Image& img
    );
};

std::ostream& operator<<(
    std::ostream& output, 
    const Image& img
);

#endif