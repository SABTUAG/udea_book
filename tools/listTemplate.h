#ifndef LIST_TEMPLATE_H
#define LIST_TEMPLATE_H


/**
 * @brief Nodo indivual de la lista enlazada.
 * @tparam Object Tipo de dato almacenado en el nodo. 
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
 * @brief Lista enlazada. 
 * @tparam Object Tipo de dato almacenado en cada nodo.
 */
template <typename Object>
class List {

private:
    Node<Object>* _head;
    int _len; 

    // Iteración común para forEach
    template <typename Function>
    void forEachNode(Function action){
        Node<Object>* current = _head;
        while (current != nullptr){
            action (current->value);
            current = current->next;
        }
    }

public:

    List(): _head(nullptr), _len(0) {}

    ~List() {
        Node<Object>* current = _head;
        while (current != nullptr){
            Node<Object>* next = current->next;
            delete current;
            current = next;
        }
    }

    int getLen() const { 
        return _len; 
    }

    Object& operator[](int index){
        Node<Object>* current = _head;
        for (int i = 0; i < index; i++){
            current = current->next;
        }
        return current->value;
    }

    const Object& operator[](int index) const {
        Node<Object>* current = _head;
        for (int i = 0; i < index; i++){
            current = current->next;
        }
        return current->value;
    }

    bool add(const Object& element){
        if (search(element)) return false;
        Node<Object>* newElement = new Node<Object>(element);
        if (_head==nullptr) _head = newElement;
        else {
            Node<Object>* current = _head;
            while (current->next != nullptr){
                current = current->next;
            }
            current->next = newElement;
        }
        _len++; 
        return true;
    }

    bool remove(const Object& element){
        if (_head==nullptr) return false;
        if (_head->value == element){
            Node<Object>* headDelete = _head;
            _head = _head->next;
            delete headDelete;
            _len--; 
            return true;
        }
        Node<Object>* current=_head;
        while (
            (current->next != nullptr) && 
            !(current->next->value == element)
        ){
            current = current->next;
        }
        if (current->next != nullptr){
            Node<Object>* elementDelete = current->next;
            current->next = current->next->next;
            delete elementDelete;
            _len--; 
            return true;
        }
        return false;
    }

    /**
     * @brief Buscar un elemento dentro de la lista. 
     * @param element Elemento a buscar.
     * @return true si el elemento esta, false en caso contrario.
     * 
     * @note Metodo de busqueda secuencial. 
     * @warning No utilizar en listas grandes. (TEMPORAL)
     */
    bool search(const Object& element) const {
        Node<Object>* current = _head;
        while (current != nullptr){
            if (current->value == element) return true;
            current = current->next;
        }
        return false;
    }

    /**
     * @brief Aplica una función a cada elemento. 
     * @tparam Function Tipo invocable con firma. 
     * @param action Función que se aplica a cada elemento.
     * @note **Versión no-const**: Se invoca en listas mutables. 
     */
    template <typename Function>
    void forEach(Function action){
        forEachNode(action); 
    }

    /**
     * @note **Versión const**: Se invoca en listas no mutables. 
     */
//    template <typename Function>
//    void forEach(Function action) const {
//        forEachNode(action); 
//    }  
};

#endif
