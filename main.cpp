

#ifndef STR_H
#define STR_H

#include <iostream>

/**
 * @brief Para emular la clase string 
 * @warning Falta agregar soporte, integrar en cantidades minimas
 */
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

    const char* c_str() const { 
        return _text; 
    }
    int len() const { 
        return _len; 
    }
    char operator[](int i) const { 
        return _text[i]; 
    }
    char& operator[](int i) { 
        return _text[i]; 
    }

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
    bool operator<(const str& other) const {
        int minLen = (_len < other._len) ? _len : other._len;
        for (int i = 0; i < minLen; i++) {
            if (_text[i] != other._text[i]) {
                return (_text[i] < other._text[i]);
            }
        }
        return _len < other._len;
    }
    bool operator!=(const str& other) const { 
        return !(*this == other); 
    }
    bool operator>(const str& other) const { 
        return other < *this; 
    }
    bool operator<=(const str& other) const { 
        return !(other < *this); 
    }
    bool operator>=(const str& other) const { 
        return !(*this < other); 
    }
    str operator+(const str& other) const {
        str newText; 
        delete[] newText._text; 
        newText._len = _len + other._len; 
        newText._text = new char[newText._len+1]; 
        for (int i=0; i<_len; i++){
            newText._text[i] = _text[i]; 
        }
        for (int i=0; i<other._len; i++){
            newText._text[_len+i] = other._text[i]; 
        }
        newText._text[newText._len] = '\0'; 
        return newText; 
    }
    str& operator+=(const str& other){
        *this = *this + other; 
        return *this; 
    }
    int find(const str& substr) const {
        if (substr._len == 0) return 0; 
        if (substr._len > _len) return -1; 
        for (int i=0; i<=(_len-substr._len); i++){
            bool substrInStr = true; 
            for(int n=0; n<substr._len; n++) {
                if (_text[i+n] != substr._text[n]){
                    substrInStr = false; 
                    break; 
                }
            }
            if (substrInStr) return i; 
        }
        return -1; 
    }

    friend std::ostream& operator<<(std::ostream& output, const str& strToShow) {
        output << strToShow._text;
        return output; 
    }
    friend std::istream& operator>>(std::istream& input, str& strDestination) {
        char buffer[512]; 
        input >> buffer; 
        strDestination = buffer; 
        return input; 
    }
    inline std::istream& getline(std::istream& input, str& strInputLine) {
        char buffer[512]; 
        input.getline(buffer, 512); 
        strInputLine = buffer; 
        return input; 
    }
};

#endif