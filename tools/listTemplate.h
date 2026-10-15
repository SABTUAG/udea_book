#ifndef LIST_TEMPLATE_H
#define LIST_TEMPLATE_H

/**
 * @brief Nodo indivual de la lista enlazada.
 * @tparam Object Tipo de dato almacenado en el nodo
 */
template <typename Object>
class Node {
public:
    Object value;
    Node<Object>* next;
    Node(const Object& initialValue): 
        value(initialValue), 
        next(nullptr) {}
};

/**
 * @brief Para una lista enlazada
 * @warning No libera la memoria la memoria apuntada
 */
template <typename Object>
class List {
private:
    Node<Object>* _head;
    int _len; 

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

    int getLen() const { 
        return _len; 
    }

    Object& operator[](int index) {
        Node<Object>* current = _head;
        for (int i = 0; i < index; i++) {
            current = current->next;
    }
        return current->value;
    }
    Object& operator[](int index) const {
        Node<Object>* current = _head;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
    return current->value;
    }

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
