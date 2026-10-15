#include "images/image.h"
#include "str.h"

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

std::ostream& operator<<(std::ostream& output, const Image& img){
    output <<img._filePath;
    return output;
}