#include "Gallery.h"

Gallery::Gallery(): 
    _profilePicture(), 
    _albums() {}

Gallery::Gallery(
    const Image& profilePicture, 
    const List<Album>& albums
): 
    _profilePicture(profilePicture), 
    _albums(albums) {}


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
    std::ostream& output, const Gallery& galleryN
){
    int n = 1;
    galleryN._albums.forEach([&](const Album& album) {
        output << n++ << ") " << album << "\n";
    });
    output << n++ << ") " << galleryN._profilePicture<< "\n";
    return output;
}