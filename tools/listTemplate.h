#ifndef LIST_TEMPLATE_H
#define LIST_TEMPLATE_H
/**
 * @file listTemplate.h
 * @brief Plantilla de lista enlazada. 
 */

/**
 * @brief Nodo indivual de la lista enlazada.
 * @tparam Object Tipo de dato almacenado en el nodo
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
 * @warning No libera la memoria la memoria apuntada
 */
template <typename Object>
class List {
private:
    Node<Object>* _head;
    int _size; 

public:

    List(): _head(nullptr) {}

    ~List() {
        Node<Object>* current = _head;
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
        if (_head == nullptr) {
            _head = newElement;
            return true;
        }

        Node<Object>* current = _head;
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
        if (_head == nullptr) return false;
        if (_head->value == element) {
            Node<Object>* headDelete = _head;
            _head = _head->next;
            delete headDelete;
            return true;
        }

        Node<Object>* current = _head;
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

    /**
     * @brief Para buscar un elemento especifico dentro de la lista
     * @param element Elemento que se buscara en la lista
     * @warning No usar en listas grandes, la peor forma de buscar algo
     * @return True si el elemento se encuentra en la lista, False si no se se encuentra en la lista
     */
    bool search(const Object& element) const {
        Node<Object>* current = _head;
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
        Node<Object>* current = _head;
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
        Node<Object>* current = _head;
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
        Node<Object>* current = _head;
        while (current != nullptr) {
            action(current->value);
            current = current->next;
        }
    }  
};

#endif
