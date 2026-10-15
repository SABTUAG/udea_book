#ifndef FRIENDS_SUGGESTIONS_H
#define FRIENDS_SUGGESTIONS_H

#include "listTemplate.h"
#include "str.h"

class User; 
class Platform; 

/** @brief Gestiona las sugerencias de amistad para un usuario. 
 * 
 */
class FriendSuggestions {
private:
    List<int> _suggestedIDs;
    List<int> _commonFriendsCount;

public:
    FriendSuggestions(); 

    const List<int>& getIDs() const { return _suggestedIDs; }
    //int getCount() const { return _suggestedIDs.getSize(); }
    /**
     * @brief Devuelve cuántos amigos en común tiene una sugerencia.
     * @param index Índice en la lista de sugerencias.
     * @return Cantidad de amigos en común.
     */
    int getCommonFriends(int index) const;

    /**
     * @brief Calcula las sugerencias para un usuario dado.
     * @param userID ID del usuario.
     * @param platform Referencia a la plataforma para acceder a todos
     *                 los usuarios y sus listas de amigos.
     * @note Complejidad: O(n²) en el peor caso, donde n es el número
     *       de usuarios.
     */
    void calculate(int userID, Platform* platform);

    /**
     * @brief Ordena las sugerencias por amigos en común (descendente).
     * @note Complejidad: O(k log k) usando merge sort, donde k es el
     *       número de sugerencias.
     */
    void sortByCommonFriends();

    /**
     * @brief Devuelve las K mejores sugerencias.
     * @param n Cantidad de sugerencias a retornar.
     * @return Lista con los IDs de las K mejores.
     */
    List<int> getTop(int n) const;

};

#endif