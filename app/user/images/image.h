#ifndef IMAGE_H
#define IMAGE_H

#include <string>

#include "listTemplate.h"
#include "console.h"

/**
 * User photos are PNG files stored at absolute paths, for example:
 * /users/<fixed-subpath>/juanito76/albums/Cartagena2026/Malecon2612.png
 * /users/<fixed-subpath>/juanito76/albums/profile.png
 */

/**
 * @brief Para representar un like 
 */
class Like {
private: 
    std::string _userName; 

public: 
    Like(std::string userName): _userName(userName) {}
    std::string getUserName() const { return _userName; }
};

/**
 * @brief Para representar una imagen
 */
class Image {
    // Cada imagen pertenece a un solo álbum y usa formato PNG
private:
    std::string _publicationDate;
    int _size;
    std::string _filePath;
    int _likes;
    List<std::string> _likedBy; 

public: 
    // Constructor
    Image(std::string filePath, int likes, List<std::string> likedBy): 
        _filePath(filePath), _likes(likes), _likedBy(likedBy) {}

    // Getters
    std::string getPublicationDate() const {
        return _publicationDate; 
    }
    int getSize() const {
        return _size; 
    }
    std::string getFilePath() const {
        return _filePath;
    }
    int getLikes() const {
        return _likes; 
    }
    List<std::string> getLikedBy() const {
        return _likedBy; 
    }

    // Setters
    void setLikes(int updatedQuantity) {
        _likes = updatedQuantity; 
    }
    //void setLikedBy() {}

};


/**
 * @brief Para representar la galeria de un usuario
 */
class Gallery {
private:
    // Guarda la ruta de la foto de perfil.
    Image _profilePictureFilePath;
    List<Album> _albums;

public:
    // Constructor
    Gallery();

    //Getters
    Image getProfilePictureFilePath(){
        return _profilePictureFilePath; 
    }
    List<Album> getAlbums(){
        return _albums; 
    }

    // Setters
    void setProfilePictureFilePath(Image newImageProfile){
        _profilePictureFilePath = newImageProfile;
    }

    // Acciones de Galeria
    bool addAlbum(){
    };

    bool removeAlbum(Album albumToRemove){
        _albums.remove(albumToRemove); 
    }
    bool showGallery(){ 
        std::cout<<"-- Gallery --"<<std::endl;
        _albums.forEach([](const Album& album){
            std::cout<<album.getFilePath()<<std::endl;
        });
        std::cout<<_profilePictureFilePath.getFilePath()<<std::endl;
    };

    // Interaccion manual
    void editGallery(){
        std::cout<<"-- Edit Gallery --"<<std::endl; 
        std::cout<<"1.Change profile picture"<<std::endl; 
        std::cout<<"2.Add new album"<<std::endl; 
        std::cout<<"3.Remove album"<<std::endl; 
        int action = Console::inputValidInt("Option: ", 1, 2);
        Console::clear(4); 
        switch(action){
        case 1: 
            std::cout<<" - New Profile Picture -"<<std::endl; 
            break; 
        case 2: 
            std::cout<<" - New Album -"<<std::endl;
            break;
        case 3: 
            std::cout<<" - Remove album -"<<std::endl; 
            break; 
        }
    }
};

#endif
