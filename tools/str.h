#ifndef STR_H
#define STR_H

#include <iostream>

/**
 * @brief Cadena de caracteres (string propia).
 * @warning No soporta caracteres multibyte (UTF-8).Se asume ASCII.
 */
class str {

private:
    char* _text;   
    int _len;       

    static int len(const char* text);
    static char* copy(const char* text);

public:
    static const int NPOS= -1;

    str();
    str(const char* text);
    str(const str& other);
    ~str();
    int len() const;
    const char* c_str() const; 

    str& operator=(const char* text);
    str& operator=(const str& other);
    char operator[](int i) const;
    char& operator[](int i);
    bool operator==(const str& other) const;
    bool operator==(const char* other) const;
    bool operator!=(const str& other) const;
    bool operator<(const str& other) const;
    bool operator>(const str& other) const;
    bool operator<=(const str& other) const;
    bool operator>=(const str& other) const;
    str operator+(const str& other) const;
    str& operator+=(const str& other);

    /**
     * @brief Busca una subcadena.
     * @param substr Subcadena a buscar.
     * @return Índice de la primera ocurrencia, NPOS si no se encuentra.
     * @note Complejidad: O(n*m) peor caso.
     */
    int find(const str& substr) const;

    /**
     * @brief Busca un carácter.
     * @param c Carácter a buscar.
     * @return Índice de la primera ocurrencia, NPOS si no se encuentra.
     * @note Complejidad: O(n).
     */
    int find(char c) const;

    friend std::ostream& operator<<(
        std::ostream& output, 
        const str& chars
    );
    friend std::istream& operator>>(
        std::istream& input, 
        str& chars
    );
};

std::ostream& operator<<(
    std::ostream& output, 
    const str& chars
);

/**
 * @brief Lee una palabra (token) desde un flujo de entrada.
 * @note Se detiene en el primer whitespace. NO consume el '\n' final.
 * @warning No mezclar con getline sin limpiar el buffer antes.
 */
std::istream& operator>>(
    std::istream& input, 
    str& chars
);

/**
 * @brief Lee una línea completa desde un flujo de entrada.
 * @param input Flujo de entrada.
 * @param s Cadena destino.
 * @return El mismo flujo, para encadenamiento.
 * @note Consume el '\n' final. Si la lectura falla, la cadena queda vacía.
 */
std::istream& getline(
    std::istream& input, 
    str& chars
);

#endif