#ifndef STR_H
#define STR_H

#include <iostream>

class str {
private: 
    char* _text; 
    int _len; 

    static int len(const char* text){
        int i=0; 
        while (text[i] != '\0') i++; 
        return i; 
    }

    static char* copy(const char* text){
        int n = len(text);
        char* whereToCopy = new char[n+1]; 
        for (int i=0; i<n; i++){
            whereToCopy[i] = text[i]; 
        }
        whereToCopy[n] = '\0';
        return whereToCopy; 
    }

public: 
    //Constructores y destructor
    str(): _len(0) {
        _text = new char[1]; 
        _text[0] = '\0';
    }
    str(const char* text){
        _len = len(text); 
        _text = copy(text); 
    }
    str(const str& other){
        _len = other._len; 
        _text = copy(other._text); 
    }
    ~str() {
        delete[] _text;
    }

    // Sobrecargar operadores
    str& operator=(const char* text){
        delete[] _text; 
        _len = len(text); 
        _text = copy(text); 
        return *this; 
    }
    str& operator=(const str& other){
        if (this == &other) return *this; 
        delete[] _text; 
        _len = other._len; 
        _text = copy(other._text); 
        return *this; 
    }

    //Getters
    const char* c_str() const { return _text; }
    int len() const { return _len; }
    char operator[](int i) const { return _text[i]; }
    char& operator[](int i) { return _text[i]; }

    // Acciones de str
    bool operator==(const str& other) const {
        if (_len != other._len) return false; 
        for (int i=0; i<_len; i++){
            if (_text[i] != other._text[i]) return false; 
        }
        return true; 
    }
    bool operator==(const char* other) const {
        int n = len(other); 
        if (_len != n) return false; 
        for (int i=0; i<_len; i++){
            if(_text[i] != other[i]) return false; 
        }
        return true; 
    }
    // Revisar despues 
    bool operator<(const str& other) const {
        int minLen = (_len < other._len) ? _len : other._len;
        for (int i = 0; i < minLen; i++) {
            if (_text[i] != other._text[i]) return (_text[i] < other._text[i]);
        }
        return _len < other._len;
    }
    bool operator!=(const str& other) const { return !(*this == other); }
    bool operator>(const str& other) const { return other < *this; }
    bool operator<=(const str& other) const { return !(other < *this); }
    bool operator>=(const str& other) const { return !(*this < other); }
    str operator+(const str& other) const {
        str newText; 
        delete[] newText._text; 
    }
};

#endif