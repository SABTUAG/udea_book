#ifndef LIST_TEMPLATE_H
#define LIST_TEMPLATE_H

#include <iostream>
#include <initializer_list> // TEMPORAL, para pruebas con inicialización de datos

template <typename Object>
class Node {
public:
    Object value;
    Node<Object>* next;

    Node(Object initialValue) : value(initialValue), next(nullptr) {}
};

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

    bool add(Object element) {
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

    bool remove(Object element) const {
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

    // temporal aqui
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

    bool search(Object element) const {
        Node<Object>* current = head;
        while (current != nullptr) {
            if (current->value == element) return true;
            current = current->next;
        }
        return false;
    }

    //temporal aqui 
    void show() const {
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
