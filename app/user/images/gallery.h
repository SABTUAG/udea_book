#ifndef GALLERY_H
#define GALLERY_H

#include <iostream>
#include "image.h"
#include "album.h"
#include "listTemplate.h"

/**
/users/(sub-ruta-X-fija)/juanito76/albums/Cartagena2026/Malecon2612.png
/users/(sub-ruta-X-fija)/juanito76/albums/Cartagena2026/Bocagrande1.png
/users/(sub-ruta-X-fija)/juanito76/albums/profile.png

 */
/**
 * @brief Para representar la galeria de un usuario.
 */
class Gallery {

private:
    Image _profilePicture;
    List<Album> _albums;

public:
    Gallery();
    Gallery(
        const Image& profilePicture, 
        const List<Album>& albums
    );

    const Image& getProfilePicture() const;
    const List<Album>& getAlbums() const;
    List<Album>& getAlbums();   
    int getAlbumCount() const;

    friend std::ostream& operator<<(
        std::ostream& output, 
        const Gallery& gallery
    );
};

std::ostream& operator<<(
    std::ostream& output, 
    const Gallery& gallery
);

#endif