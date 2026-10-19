#include "plataform.h"
#include <cstdlib>
#include <ctime>


void Plataform::loadUsers(const str& database){
    List<str> blocks; 
    if (!FileManager::read(database,blocks)) return; 
    blocks.forEach(
        [&](const str& block){
            User newUser(block); 
            _users.add(newUser);
        }
    ); 
}
User* Plataform::findUserByName(const str& nameID){
    User* found = nullptr;
    _users.forEach(
        [&](User& user){
            if (user.getNameID()==nameID) found=&user;
        }
    );
    return found;
}
bool Plataform::loginUser() {
    std::cout<<"** Iniciar sesion **\n";
    str nameID=Console::inputStr(
        "Usuario: ",
        "abcdefghijklmnopqrstuvwxyz0123456789",
        50
    );
    User* user=findUserByName(nameID);
    if (user==nullptr){
        std::cout<<"Usuario no encontrado.\n";
        return false;
    }
    str pass = Console::inputStr(
        "Contrasena: ",
        "abcdefghijklmnopqrstuvwxyz0123456789",
        50
    );
    if (user->getPassword()!=pass) {
        std::cout<<"Contrasena incorrecta.\n";
        return false;
    }
    _currentUser=user;
    return true;
}


Plataform::Plataform(const str& databasePath): 
    _currentUser(nullptr), 
    _profilePicsUpdated(false)
{
    srand(time(0)); 
    loadUsers(databasePath); 
}


// ==========================================
// MENÚ PRINCIPAL (LOGIN Y BUCLE)
// ==========================================
void Plataform::start() {
    if (!loginUser()) return;
    
    // Funcionalidad II: Mostrar 3 fotos de amigos
    mostrarFotosPerfil();
    int option = 0;
    while (option != 7){
        std::cout << "\nMENU DE OPCIONES\n";
        std::cout << "1. Administrar amistades\n";
        std::cout << "2. Visitar perfil de un amigo\n";
        std::cout << "3. Ver sugerencias de amistad\n";
        std::cout << "4. Administrar mensajes\n";
        std::cout << "5. Actualizar fotos de amigos (Solo 1 vez)\n";
        std::cout << "7. Cerrar sesion\n";
        option = Console::inputInt("Opcion: ", 1, 7);
        switch (option) {
            case 1: FriendShipManagementMenu(); break;
            case 2: visitarPerfil(); break;
            case 3: menuSugerencias(); break;
            case 4: menuMensajes(); break;
            case 5: 
                if (!_profilePicsUpdated) {
                    mostrarFotosPerfil();
                    _profilePicsUpdated = true;
                } else {
                    std::cout<<"Ya actualizaste las fotos anteriormente.\n";
                }
                break;
            case 7: std::cout<<"Cerrando sesion...\n"; break;
        }
    }
}

// ==========================================
// FUNCIONALIDAD II: FOTOS DE PERFIL PONDERADAS
// ==========================================
void Plataform::mostrarFotosPerfil() {
    const List<str>& friends = _currentUser->getFriends().getFriends().getNameIDs();
    int numFriends = friends.getLen();
    
    if (numFriends==0){
        std::cout<<"No tienes amigos para mostrar.\n";
        return;
    }

    int mostrados = 0;
    // Algoritmo de selección aleatoria con peso basado en AMIGOS EN COMÚN
    for (int i=0; (i<numFriends) && (mostrados<3); i++) {
        User* amigo = findUserByName(friends[i]);
        if (amigo){
            // 1. Calcular amigos en común reales
            int commonFriends = 0;
            List<str> amigoFriends = amigo->getFriends().getFriends().getNameIDs();
            amigoFriends.forEach(
                [&](const str& f) {
                    if (_currentUser->getFriends().getFriends().contains(f)) {
                        commonFriends++;
                    }
                }
            );

            // 2. Asignar el peso según el PDF
            int weight = 1;
            if (commonFriends>20) weight=4;      // 3.5x prioridad
            else if (commonFriends>10) weight=3; // 2.5x prioridad
            // 3. Probabilidad de mostrarse (rand() % 5 da un máximo de 4)
            if (rand()%5< weight){
                std::cout<< amigo->getGallery().getProfilePicture().getFilePath()<< "\n";
                mostrados++;
            }
        }
    }
    
    // Si por azar no se mostraron 3, mostramos los que falten
    while (mostrados<3 && mostrados<numFriends) {
        User* amigo = findUserByName(friends[mostrados]);
        if (amigo) {
            std::cout<<amigo->getGallery().getProfilePicture().getFilePath()<< "\n";
        }
        mostrados++;
    }
}

// ==========================================
// FUNCIONALIDAD III: ADMINISTRAR AMISTADES
// ==========================================
void Plataform::FriendShipManagementMenu() {
    Efficiency::reset();
    int opt = 0;
    while (opt != 3) {
        std::cout << "\n1. Enviar solicitud\n2. Aceptar solicitud\n3. Volver\n";
        opt = Console::inputInt("Opcion: ", 1, 3);

        if (opt == 1) {
            str targetName = Console::inputStr("Nombre de usuario a invitar: ", "abcdefghijklmnopqrstuvwxyz0123456789", 50);
            User* target = findUserByName(targetName);
            
            if (!target || target->getNameID() == _currentUser->getNameID()){
                std::cout << "Usuario invalido.\n"; continue;
            }
            if (_currentUser->getFriends().getFriends().contains(targetName)){
                std::cout << "Ya son amigos.\n"; continue;
            }
            if (_currentUser->getFriends().getRequests().hasReceivedFrom(targetName)){
                std::cout << "Ese usuario ya te envio una solicitud. Aceptala.\n"; continue;
            }

            // Enviar solicitud
            target->getFriends().getRequests().add(FriendRequest(_currentUser->getNameID()));
            std::cout << "Solicitud enviada a " << targetName << ".\n";
        } 
        else if (opt == 2) {
            FriendRequests& reqs = _currentUser->getFriends().getRequests();
            if (!reqs.hasReceivedAny()) {
                std::cout << "No tienes solicitudes pendientes.\n"; continue;
            }

            std::cout << reqs; // Imprime la lista de solicitudes
            int index = Console::inputInt("Numero de solicitud a aceptar: ", 1, reqs.getCount());
            
            str senderName = reqs.getAt(index - 1).getSender();
            
            // Hacerlos amigos mutuamente
            _currentUser->getFriends()
            .getFriends()
            .add(senderName);
            User* sender = findUserByName(senderName);
            if (sender) sender->getFriends()
            .getFriends()
            .add(_currentUser->getNameID());

            // Borrar solicitud
            reqs.remove(senderName);
            std::cout<<"Ahora eres amigo de "<<senderName<< "!\n";
        }
    }
    Efficiency::showMetrics("Administrar Amistades");
}

// ==========================================
// FUNCIONALIDAD IV: VISITAR PERFIL (CARRUSEL)
// ==========================================
void Plataform::visitarPerfil() {
    Efficiency::reset();
    str targetName = Console::inputStr("Nombre del amigo a visitar: ", "abcdefghijklmnopqrstuvwxyz0123456789", 50);
    User* amigo = findUserByName(targetName);

    if (!amigo || !_currentUser->getFriends().getFriends().contains(targetName)) {
        std::cout << "No es tu amigo o no existe.\n";
        return;
    }

    std::cout << "\n--- Perfil de " << amigo->getNameID() << " ---\n";
    const List<Album>& albums = amigo->getGallery().getAlbums();
    
    int validAlbums[50]; // Guardar índices de álbumes visibles
    int count = 0;
    
    for (int i = 0; i < albums.getLen(); i++) {
        const str& priv = albums[i].getPrivacy();
        if (priv == "publico" || priv == "amigos") {
            std::cout << count + 1 << ". " << albums[i].getName() << "\n";
            validAlbums[count++] = i;
        }
    }

    if (count == 0) {
        std::cout << "No hay albumes publicos.\n";
        return;
    }

    int opt = Console::inputInt("Elige un album (0 para salir): ", 0, count);
    if (opt > 0) {
        carruselFotos(const_cast<Album&>(albums[validAlbums[opt - 1]]));
    }
    Efficiency::showMetrics("Visitar Perfil");
}

void Plataform::carruselFotos(Album& album) {
    List<Image>& imgs = album.getImages();
    if (imgs.getLen() == 0) {
        std::cout << "Album vacio.\n"; return;
    }

    int idx = 0;
    bool running = true;
    while (running) {
        Image& img = imgs[idx];
        std::cout << "\nFoto " << idx + 1 << "/" << imgs.getLen() << "\n";
        std::cout << "Ruta: " << img.getFilePath() << "\n";
        std::cout << "Likes: " << img.getLikes() << "\n";
        std::cout << "[s]iguiente, [a]nterior, [l]ike, [q]uit: ";
        
        str opcion = Console::inputStr("", "sSalLqQ", 1);
        char c = opcion[0];
        
        if (c == 's' || c == 'S') idx = (idx + 1) % imgs.getLen();
        else if (c == 'a' || c == 'A') idx = (idx - 1 + imgs.getLen()) % imgs.getLen();
        else if (c == 'l' || c == 'L') img.addLike();
        else if (c == 'q' || c == 'Q') running = false;
    }
}

// ==========================================
// FUNCIONALIDAD V: SUGERENCIAS
// ==========================================
void Plataform::menuSugerencias() {
    Efficiency::reset();
    int K = Console::inputInt("Cuantas sugerencias deseas (1-20): ", 1, 20);
    
    List<FriendSuggestion> candidates;

    // Algoritmo: amigos de mis amigos
    _currentUser->getFriends().getFriends().getNameIDs().forEach([&](const str& myFriendName) {
        User* myFriend = findUserByName(myFriendName);
        if (!myFriend) return;

        myFriend->getFriends().getFriends().getNameIDs().forEach([&](const str& candidateName) {
            if (candidateName == _currentUser->getNameID()) return; // Soy yo
            if (_currentUser->getFriends().getFriends().contains(candidateName)) return; // Ya es amigo

            bool found = false;
            candidates.forEach([&](FriendSuggestion& c) {
                if (c.getNameID() == candidateName) {
                    c.incrementCommonFriends();
                    found = true;
                }
            });
            if (!found) candidates.add(FriendSuggestion(candidateName, 1));
        });
    });

    // Ordenar (Usa el operator< de FriendSuggestion)
    candidates.sort([](const FriendSuggestion& a, const FriendSuggestion& b) {
        return a < b;
    });

    std::cout << "\n--- Sugerencias ---\n";
    int count = 0;
    for (int i = 0; i < candidates.getLen() && count < K; i++) {
        std::cout << count + 1 << ". " << candidates[i].getNameID() 
                  << " (" << candidates[i].getCommonFriends() << " amigos en comun)\n";
        count++;
    }

    Efficiency::showMetrics("Ver Sugerencias");
}

// ==========================================
// FUNCIONALIDAD VI: MENSAJES
// ==========================================
void Plataform::menuMensajes() {
    Efficiency::reset();
    int opt = 0;
    while (opt != 4) {
        std::cout << "\n1. Enviar mensaje\n2. Leer nuevos\n3. Buscar por fecha\n4. Volver\n";
        opt = Console::inputInt("Opcion: ", 1, 4);

        if (opt == 1) {
            str dest = Console::inputStr("Para: ", "abcdefghijklmnopqrstuvwxyz0123456789", 50);
            if (!_currentUser->getFriends().getFriends().contains(dest)) {
                std::cout << "Solo puedes enviar mensajes a amigos.\n"; continue;
            }
            str txt = Console::inputStr("Mensaje: ", "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789 .,?!", 500);
            
            Message msg(_currentUser->getNameID(), dest, txt, Date::today(), false);
            _currentUser->getMessages().addSent(msg);
            
            User* target = findUserByName(dest);
            if (target) target->getMessages().addReceived(msg);
            std::cout << "Mensaje enviado.\n";
        }
        else if (opt == 2) {
            int unread = _currentUser->getMessages().countUnread();
            std::cout << "Tienes " << unread << " mensajes sin leer:\n";
            _currentUser->getMessages().getReceived().forEach([](const Message& m) {
                if (!m.getRead()) std::cout << m << "\n";
            });
            _currentUser->getMessages().markAllReceivedAsRead();
        }
        else if (opt == 3) {
            str start = Console::inputStr("Fecha inicio (YYYY-MM-DD): ", "0123456789-", 10);
            str end = Console::inputStr("Fecha fin (YYYY-MM-DD): ", "0123456789-", 10);
            
            List<Message> res = _currentUser->getMessages().filterReceivedByDateRange(start, end);
            std::cout << "Mensajes encontrados: " << res.getLen() << "\n";
            res.forEach([](const Message& m) { std::cout << m << "\n"; });
        }
    }
    Efficiency::showMetrics("Administrar Mensajes");
}