#ifndef ALBUM_H
#define ALBUM_H

#include <iostream>
#include "str.h"
#include "listTemplate.h"
#include "image.h"

/**
 * @brief Representa un álbum de fotos.
 */
class Album {

private:
    str _name;              
    str _filePath;        
    str _privacy;       
    List<Image> _images;    

public:
    Album(); 
    Album(
        const str& name, 
        const str& filepath, 
        const str& privacy
    );
    Album(const str& block); 

    const str& getName() const;
    const str& getFilePath() const;
    const str& getPrivacy() const;
    const List<Image>& getImages() const;
    List<Image>& getImages();

    void setName(const str& name);
    void setPrivacy(const str& privacy);

    bool addImage(const Image& image);
    bool removeImage(const Image& image);
    void carrusel(); 

    /**
     * @brief Verifica si una imagen pertenece al álbum.
     */
    bool containsImage(const Image& image) const;

    bool operator==(const Album& otherAlbum) const;
    bool operator!=(const Album& otherAlbum) const;
    bool operator<(const Album& otherAlbum) const;

    friend std::ostream& operator<<(
        std::ostream& output, 
        const Album& album
    );
};

std::ostream& operator<<(
    std::ostream& output, 
    const Album& album
);

#endif