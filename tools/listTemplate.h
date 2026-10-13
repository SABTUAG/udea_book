#ifndef LIST_TEMPLATE_H
#define LIST_TEMPLATE_H

#include <iostream>
#include <initializer_list> // TEMPORAL, para pruebas con inicialización de datos

/**
 * @brief Nodo
 */
template <typename Object>
class Node {
public:
    Object value;
    Node<Object>* next;

    Node(Object initialValue) : value(initialValue), next(nullptr) {}
};

/**
 * @brief Plantilla de lista con cuatro funcionalidades soportadas
 * @details Cinco funcionalidade soportadas
 */
template <typename Object>
class List {
private:
    Node<Object>* head;

public:

    List() : head(nullptr) {}
    // Temporal
    List(std::initializer_list<Object> values) : head(nullptr) {
        for (const Object& value : values) {
            add(value);
        }
    }

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
     */
    bool add(Object element) {
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
    bool remove(Object element) {
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

    /**
     * @brief Para cambiar un elemento por otro
     * @param oldValue Elemento que se desea cambiar
     * @param newValue Nuevo elemento para cambiar
     * @note El elemento que se desea cambiar, se elimina de forma definitiva
     * @return True si se puede realizar el cambio, False si no se puede
     */
    bool replace(Object oldValue, Object newValue) const {
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

    /**
     * @brief Para buscar un elemento especifico dentro de la lista
     * @param element Elemento que se buscara en la lista
     * @return True si el elemento se encuentra en la lista, False si no se se encuentra en la lista
     */
    bool search(Object element) const {
        Node<Object>* current = head;
        while (current != nullptr) {
            if (current->value == element) return true;
            current = current->next;
        }
        return false;
    }

    /**
     * @brief Aplica un proceso de busqueda especifico utilizando una función 
     * @param action Funcion que se utiliza en la busqueda especial
     * @warning Cuidado con las funciones que se utiliza 
     */
    void forEach(Function action) const {
        Node<Object>* current = head;
        while (current != nullptr) {
            action(current->value);
            current = current->next;
        }
    }

    /**
     * @brief Para mostrar todos los elementos de la lista
     * @bug SIN SOPORTE 
     */
    void show() {
        Node<Object>* current = head;
        while (current != nullptr) {
            std::cout << current->value;
            if (current->next != nullptr) std::cout << ", ";
            current = current->next;
        }
        std::cout << '\n';
    }
};

#endif
