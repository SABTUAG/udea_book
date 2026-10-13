#ifndef LIST_TEMPLATE_H
#define LIST_TEMPLATE_H

// #include <iostream> Se usaba con el metodo .show()
//#include <initializer_list> // TEMPORAL, para pruebas con inicialización de datos

/**
 * @brief Para un Nodo indivual de lista enlazada
 */
template <typename Object>
class Node {
public:
    Object value;
    Node<Object>* next;

    Node(const Object& initialValue) : value(initialValue), next(nullptr) {}
};

/**
 * @brief Para una lista enlazada
 * @warning No olvidar liberar la memoria manualmente
 */
template <typename Object>
class List {
private:
    Node<Object>* head;

public:

    List(): head(nullptr) {}

    ~List() {
        Node<Object>* current = head;
        while (current != nullptr) {
            Node<Object>* next = current->next;
            delete current;
            current = next;
        }
    }

    /**
     * @brief Permite añadir un nuevo elemento al final de la lista
     * @param element Elemento que se desea añadir a la lista
     * @return True si se agrega el nuevo elemento, False si ya existe en la lista
     * @pre El objeto debe soportar operator==
     */
    bool add(const Object& element) {
        if (search(element)) return false;

        Node<Object>* newElement = new Node<Object>(element);
        if (head == nullptr) {
            head = newElement;
            return true;
        }

        Node<Object>* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newElement;
        return true;
    }

    /**
     * @brief Para eliminar un elemento especifico de la lista
     * @param element Elemento que se desea eliminar
     * @return True si se elimina el elemento , False si no se elimina
     */
    bool remove(const Object& element) {
        if (head == nullptr) return false;
        if (head->value == element) {
            Node<Object>* headDelete = head;
            head = head->next;
            delete headDelete;
            return true;
        }

        Node<Object>* current = head;
        while (current->next != nullptr && !(current->next->value == element)) {
            current = current->next;
        }
        if (current->next != nullptr) {
            Node<Object>* elementDelete = current->next;
            current->next = current->next->next;
            delete elementDelete;
            return true;
        }
        return false;
    }

    /*
     * @brief Para cambiar un elemento por otro
     * @param oldValue Elemento que se desea cambiar
     * @param newValue Nuevo elemento para cambiar
     * @warning OBSOLETO,creaba copias innecesarias. Reemplazado por forEach combinado con setters
     * @note El elemento que se desea cambiar, se elimina de forma definitiva
     * @return True si se puede realizar el cambio, False si no se puede
     */
    /* 
    bool replace(Object oldValue, Object newValue) {
        Node<Object>* current = head;
        while (current != nullptr) {
            if (current->value == oldValue) {
                current->value = newValue;
                return true;
            }
            current = current->next;
        }
        return false;
    }
    */

    /**
     * @brief Para buscar un elemento especifico dentro de la lista
     * @param element Elemento que se buscara en la lista
     * @warning No usar en listas grandes, la peor forma de buscar algo
     * @return True si el elemento se encuentra en la lista, False si no se se encuentra en la lista
     */
    bool search(const Object& element) const {
        Node<Object>* current = head;
        while (current != nullptr) {
            if (current->value == element) return true;
            current = current->next;
        }
        return false;
    }

    /*
     * @brief Para mostrar todos los elementos de la lista
     * @bug SIN SOPORTE he inncesario, requiere sobrecargar el operator<< en cada clase construida
     */
    /*
    void show() {
        Node<Object>* current = head;
        while (current != nullptr) {
            std::cout << current->value;
            if (current->next != nullptr) std::cout << ", ";
            current = current->next;
        }
        std::cout << '\n';
    } 
    */

    /**
     * @brief Aplica una función a cada elemento permitiendo modificarlo.
     */
    template <typename Function>
    void forEach(Function action) {
        Node<Object>* current = head;
        while (current != nullptr) {
            action(current->value);
            current = current->next;
        }
    }

    /**
     * @brief Aplica una función a cada elemento, pero no lo modifica.
     * @note para listas definidas como const
     */
    template <typename Function>
    void forEach(Function action) const {
        Node<Object>* current = head;
        while (current != nullptr) {
            action(current->value);
            current = current->next;
        }
    }  
};

#endif
