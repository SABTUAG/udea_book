#include "Gallery.h"

Gallery::Gallery(): 
    _profilePicture(), 
    _albums() {}

str extractParens(const str& text, const str& key) {
    int pos = text.find(key);
    if (pos == str::NPOS) return "";
    
    // Recortamos el texto para buscar desde la palabra clave
    str subText = text.substr(pos, text.len() - pos);
    
    int start = subText.find('(');
    int end = subText.find(')');
    
    if (start == str::NPOS || end == str::NPOS) return "";
    return subText.substr(start + 1, end - start - 1);
}

Gallery::Gallery(
    const Image& profilePicture, 
    const List<Album>& albums
): 
    _profilePicture(profilePicture), 
    _albums(albums) {}
Gallery::Gallery(const str& block) {
    // 1. Álbumes: ALBUMS: (Album1|publico|/ruta; Album2|privado);
    str albumsStr = extractParens(block, "ALBUMS:");
    if (albumsStr.len() > 0) {
        List<str> albs = albumsStr.split(';');
        albs.forEach([&](const str& a) {
            List<str> f = a.split('|');
            if (f.getLen() >= 2) { // Asumiendo nombre|privacidad|ruta o similar
                _albums.add(Album(f[0].strip(), f.getLen() > 2 ? f[2].strip() : "", f[1].strip()));
            }
        });
    }

    // 2. Foto de perfil: IMAGEPROFILE: (/ruta/profile.png)
    str profileStr = extractParens(block, "IMAGEPROFILE:");
    if (profileStr.len() > 0) {
        _profilePicture = Image(profileStr.strip(), "", 0, 0);
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