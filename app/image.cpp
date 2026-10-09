#include <string>
using namespace std; 

/**
 * Las fotos de cada usuario se guardan en formato .png, y se encuentran
almacenados en una ubicación externa expresada como una ruta absoluta en
notación linux.
 * /users/(sub-ruta-X-fija)/juanito76/albums/Cartagena2026/Malecon2612.png
/users/(sub-ruta-X-fija)/juanito76/albums/Cartagena2026/Bocagrande1.png
* 
/users/(sub-ruta-X-fija)/juanito76/albums/profile.png -> la subruta asociada al perfil del usuario.
 */

class Image {
    // solo puede pertenecer a un único album
    // formato .png
    private: 
        string _publicationDate; 
        int _size; 
        string _filePath; 
        int _likes; 
    public:
        void getLikes() const {} ;
        void clickLike(); 
}; 

class album {
    // cero o más fotos
    private: 
        string _name; 
        string _filePath = "/udeaebook/users/.."; 
        string _privacySettings; // privado-publico-solo amigos
        string _images; 
    public: 

        bool viewPhotos(); 

}; 