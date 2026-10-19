#include "Album.h"
#include "console.h"

Album::Album(
    const str& name, 
    const str& filepath, 
    const str& privacy
):
    _name(name), 
    _filePath(filepath), 
    _privacy(privacy), 
    _images() {}

// "Nombre|Privacidad|Ruta|Foto1~Fecha~Size~Likes;Foto2..."
Album::Album(const str& block) {
    List<str> parts = block.split('|');
    if (parts.getLen() >= 4){
        _name = parts[0].strip();
        _privacy = parts[1].strip();
        _filePath = parts[2].strip();
        List<str> imagenesStr = parts[3].split(';');
        imagenesStr.forEach(
            [&](const str& imgStr){
                List<str> imageAtributes = imgStr.split('~');
                if (imageAtributes.getLen() == 4){
                    int size = str::toInt(imageAtributes[2].c_str());
                    int likes = str::toInt(imageAtributes[3].c_str());
                    Image img(
                        imageAtributes[0].strip(), 
                        imageAtributes[1].strip(), 
                        size,
                        likes
                    );
                    _images.add(img);
                }
            }
        );
    }
}  


const str& Album::getName() const {
    return _name;
}
const str& Album::getFilePath() const {
    return _filePath;
}
const str& Album::getPrivacy() const {
    return _privacy;
}
const List<Image>& Album::getImages() const {
    return _images;
}
List<Image>& Album::getImages() {
    return _images;
}


void Album::setName(const str& name){
    _name = name;
}
void Album::setPrivacy(const str& privacy){
    _privacy = privacy;
}


bool Album::addImage(const Image& image){
    return _images.add(image);
}
bool Album::removeImage(const Image& image){
    return _images.remove(image);
}
// Para refactorizar
void Album::carrusel() {
    if (_images.getLen()==0){
        std::cout<<"El album "<<getName()<<" esta vacio.\n";
        return;
    }
    int currentPhotoIndex=0;
    bool running=true;
    while (running){
        Image& img = _images[currentPhotoIndex];
        std::cout<<"\n Foto "<<currentPhotoIndex+1<<": "<<img<<"\n";
        std::cout<<"[ Fecha: "<<img.getPublicationDate()<<" ] [Likes: "<<img.getLikes()<<" ]\n";
        char c = Console::inputChar(
            "\ns = siguiente, a = anterior, l = dar like, i = quitar like, q = salir: ", 
            "saliq"
        );
        if (c=='s'){
            currentPhotoIndex=(currentPhotoIndex  + 1)%_images.getLen();
        } 
        else if (c=='a'){
            currentPhotoIndex=(currentPhotoIndex-1+_images.getLen())%_images.getLen();
        } 
        else if (c=='i') img.removeLike(); 
        else if (c=='l') img.addLike();
        else if (c=='q') running = false;
    }
}


bool Album::containsImage(const Image& image) const {
    return _images.search(image);
}


bool Album::operator==(const Album& otherAlbum) const {
    return _name == otherAlbum._name;
}
bool Album::operator!=(const Album& otherAlbum) const {
    return !(*this == otherAlbum);
}
bool Album::operator<(const Album& otherAlbum) const {
    return _name < otherAlbum._name;
}


std::ostream& operator<<(
    std::ostream& output, 
    const Album& album
){
    output << album._filePath;
    return output;
}