#ifndef GALLERY_H
#define GALLERY_H

#include "image.h"
#include "album.h"
#include "listTemplate.h"

/**
/users/(sub-ruta-X-fija)/juanito76/albums/Cartagena2026/Malecon2612.png
/users/(sub-ruta-X-fija)/juanito76/albums/Cartagena2026/Bocagrande1.png
/users/(sub-ruta-X-fija)/juanito76/albums/profile.png

 */
/**
 * @brief Para representar la galeria de un usuario
 */
class Gallery {
private:
    Image _profilePicture;
    List<Album> _albums;

public:
    Gallery();
    Gallery(const Image& profilePicture, const List<Album>& albums);

    // Getters
    const Image& getProfilePicture() const;
    const List<Album>& getAlbums() const;
    List<Album>& getAlbums();   // para modificar likes en las fotos

    int getAlbumCount() const;

    // Presentación
    void showGallery() const;

    // Debug
    friend std::ostream& operator<<(std::ostream& os, const Gallery& g);
};

#endif