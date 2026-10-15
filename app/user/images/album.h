#ifndef ALBUM_H
#define ALBUM_H

#include <iostream>
#include <string>
#include "image.h"

/**
 * @brief Para representar un album
 */
class Album {
    // Un álbum contiene cero o más fotos.
private:
    std::string _name;
    std::string _filePath;
    std::string _privacySettings = "public"; // privado, público o solo amigos
    List<Image> _images;

public:
    // Constructor
    Album(std::string name, std::string filepath, std::string privacy);

    // Getters
    std::string getName() const {
        return _name;
    }
    std::string getFilePath() const {
        return _filePath; 
    }
    std::string getPrivacySettings() const {
        return _privacySettings; 
    }
    List<Image> getImages() const {
        return _images; 
    }

    // Setters
    void setPrivacySettings(std::string privacy) {
        _privacySettings = privacy; 
    }

    // acciones de albums
    bool addImage(Image newImage){
        if (_images.search(newImage)) return false; 
        _images.add(newImage); 
    };
    bool removeImage(Image imageToDelete){
        if (_images.search(imageToDelete)) _images.remove(imageToDelete); 
    }
    void showPhotos(){
        std::cout<<"Album: "<<getName()<<std::endl; 
        _images.forEach([](const Image& image){
            std::cout<<image.getFilePath()<<std::endl;
        });
    }

    // Interaccion manual
    void editAlbum(){
        std::cout<<"-- Edit Album --"<<std::endl; 
        std::cout<<"1. Change privacy"<<std::endl; 
        std::cout<<"2. Add image"<<std::endl; 
        std::cout<<"3. Remove image"<<std::endl; 
        int action = Console::inputValidInt("Option: ", 1,3);
        Console::clear(4); 
        switch(action){
        case 1: 
            std::cout<<"- Change privacy -"<<std::endl; 
            std::cout<<"1. public "<<std::endl; 
            std::cout<<"2. private "<<std::endl; 
            std::cout<<"3. Only friends"<<std::endl; 
            int newConfig = Console::inputValidInt("Option: ", 1,3); 
            Console::clear(4); 
            return;
        case 2: 
            std::cout<<"- Add Image -"<<std::endl; 
            // ...
            return;
        case 3:
            std::cout<<"- Remove Image -"<<std::endl; 
            // ...
            return;
        }
    }
};

#endif