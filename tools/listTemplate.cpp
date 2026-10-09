
// REVISAR ERRORES AQUI,
template <typename Object>
class Node {
public: 
    Object dato; 
    Node<Object>* next; 

    Node(Object value) : dato(value), next(nullptr) {}
}; 

template <typename J>
class LinkedList {
private: 
    Node<J>* head; 

public: 
    LinkedList() : head(nullptr) {}

    ~LinkedList() {
        Node<J>* current = head; 
        while (current != nullptr) {
            Node<J>* next = current->next; 
            delete current; 
            current = next; 
        }
    }
    bool add(J element) {
        Node<J>* newElement = new Node<J>(element); 
        if (head == nullptr) {
            head = newElement; 
            return true; 
        }
        Node<J>* current = head; 
        while (current->next != nullptr) {
            current = current->next; 
        }
        current->next = newElement; 
        return true; 
    }

    bool remove(J element) {
        if (head == nullptr) return false; 
        if (head->dato == element) {
            Node<J>* headDelete = head; 
            head = head->next; 
            delete headDelete; 
            return true; 
        }
        Node<J>* current = head; 
        while (current->next != nullptr && !(current->next->dato == element)) {
            current = current->next; 
        }
        if (current->next != nullptr) {
            Node<J>* elementDelete = current->next;
            current->next = current->next->next; 
            delete elementDelete;                                
            return true;
        }
        return false; 
    }
    
    bool replace(J valorAntiguo, J valorNuevo) {
        Node<J>* current = head;
        while (current != nullptr) {
            if (current->dato == valorAntiguo) {
                current->dato = valorNuevo;
                return true;
            }
            current = current->next;
        }
        return false; 
    }

    bool search()
}; 
