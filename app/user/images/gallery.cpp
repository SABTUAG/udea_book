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

Gallery::Gallery(const str& block){
    str albumsStr = extractParens(block, "ALBUMS:");
    if (albumsStr.len() > 0){
        List<str> albs = albumsStr.split(';');
        albs.forEach(
            [&](const str& album){
                _albums.add(Album(album)); 
            }
        );
    }
    str profileStr = extractParens(block, "IMAGEPROFILE:");
    if (profileStr.len() > 0) {
        List<str> profileAtributes = profileStr.split('~');
        if (profileAtributes.getLen() == 4) {
            int size = str::toInt(profileAtributes[2].c_str());
            int likes = str::toInt(profileAtributes[3].c_str());
            _profilePicture = Image(
                profileAtributes[0].strip(), 
                profileAtributes[1].strip(), 
                size, likes
            );
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