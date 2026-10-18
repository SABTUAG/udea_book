#include "Gallery.h"
#include "../tools/parser.h"

Gallery::Gallery(): 
    _profilePicture(), 
    _albums() {}


Gallery::Gallery(
    const Image& profilePicture, 
    const List<Album>& albums
): 
    _profilePicture(profilePicture), 
    _albums(albums) {}
Gallery::Gallery(const str& block) {
    // 1. Parsear Álbumes
    str albumsStr = extractParens(block, "ALBUMS:");
    if (albumsStr.len() > 0) {
        List<str> albs = albumsStr.split(';');
        albs.forEach([&](const str& a) {
            // Pasamos el bloque de texto al nuevo constructor de Album
            _albums.add(Album(a)); 
        });
    }

    // 2. Parsear Foto de Perfil (también tiene fecha, tamaño, likes)
    str profileStr = extractParens(block, "IMAGEPROFILE:");
    if (profileStr.len() > 0) {
        List<str> f = profileStr.split('~');
        if (f.getLen() == 4) {
    // Correcto: toInt retorna el entero y se lo asignas a la variable
    int size = str::toInt(f[2].c_str());
    int likes = str::toInt(f[3].c_str());
    
    _profilePicture = Image(f[0].strip(), f[1].strip(), size, likes);
}
    }
}


const Image& Gallery::getProfilePicture() const {
    return _profilePicture;
}
const List<Album>& Gallery::getAlbums() const {
    return _albums;
}
List<Album>& Gallery::getAlbums(){
    return _albums;
}
int Gallery::getAlbumCount() const {
    return _albums.getLen();
}


std::ostream& operator<<(
    std::ostream& output, const Gallery& gallery
){
    int n = 1;
    gallery._albums.forEach(
        [&](const Album& album){
            output<<n++<<") "<<album<<"\n";
        }
    );
    output<<n++<< ") "<<gallery._profilePicture<<"\n";
    return output;
}