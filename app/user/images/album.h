#ifndef ALBUM_H
#define ALBUM_H

#include "str.h"
#include "listTemplate.h"
#include "image.h"

/**
 * @brief Representa un álbum de fotos.
 * @details Cada álbum pertenece a un usuario y contiene cero o más
 *          imágenes. Tiene un nivel de privacidad que determina quién
 *          puede verlo.
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

    const str& getName() const { 
        return _name; 
    }
    const str& getFilePath() const { 
        return _filePath; 
    }
    const str& getPrivacy() const { 
        return _privacy; 
    }
    const List<Image>& getImages() const { 
        return _images; 
    }
    List<Image>& getImages(){ 
        return _images; 
    }
    //int getImageCount() const { return _images.getSize(); }

    void setName(const str& name){ 
        _name = name; 
    }
    void setFilePath(const str& path){ 
        _filePath = path; 
    }
    void setPrivacy(const str& privacy){ 
        _privacy = privacy; 
    }

    bool addImage(const Image& image){ 
        return _images.add(image); 
    }
    bool removeImage(const Image& image){ 
        return _images.remove(image); 
    }

    /**
     * @brief Verifica si una imagen pertenece al álbum.
     */
    bool containsImage(const Image& image) const {
        return _images.search(image);
    }

    bool operator==(const Album& ohterAlbum) const {
        return _name == ohterAlbum._name;
    }

    bool operator!=(const Album& ohterAlbum) const { 
        return !(*this == ohterAlbum); 
    }

    // Temporal
    bool operator<(const Album& ohterAlbum) const {
        return _name < ohterAlbum._name;
    }

    void showPhotos() const;

    friend std::ostream& operator<<(std::ostream& os, const Album& a);
};

std::ostream& operator<<(std::ostream& os, const Album& a);

#endif