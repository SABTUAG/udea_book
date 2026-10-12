#ifndef IMAGE_H
#define IMAGE_H

#include <string>

#include "listTemplate.h"

/**
 * User photos are PNG files stored at absolute paths, for example:
 * /users/<fixed-subpath>/juanito76/albums/Cartagena2026/Malecon2612.png
 * /users/<fixed-subpath>/juanito76/albums/profile.png
 */
class Image {
    // Cada imagen pertenece a un solo álbum y usa formato PNG.
private:
    std::string _publicationDate;
    int _size;
    std::string _filePath;
    int _likes;
};

class Album {
    // Un álbum contiene cero o más fotos.
private:
    std::string _name;
    std::string _filePath = "/udeaebook/users/..";
    std::string _privacySettings; // privado, público o solo amigos
    List<Image> _images;

public:
    Album(std::string name, std::string filepath, std::string privacy);
    bool addImage(std::string nameImage);
    bool showPhotos();
    bool removeImage();
    bool editAlbum();
};

class Gallery {
private:
    // Guarda la ruta de la foto de perfil.
    Image _profilePictureFilePath;
    List<Album> _albums;

public:
    bool addAlbum();
    bool showGallery();
    bool removeAlbum();
};

#endif
