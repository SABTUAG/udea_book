#ifndef CONSOLE_H
#define CONSOLE_H

#include <iostream>
#include <string>
#include "str.h"
#include "listTemplate.h"

/**
 * @brief Para facilitar acciones con la consola. 
 * @details Contiene funciones para limpiar consola y recibir entradas validas
 */
class Console {
public:
    /**
     * @brief Para borrar una cantidad de lineas.
     * @param lines Cantidad de lineas que se eliminaran.
     */
    static void clear(int lines = 1) {
        while (lines > 0) {
            std::cout << "\033[A\33[2K\r";
            lines--;
        }
    }

    /**
     * @brief Para solicita un caracter y
     * @param prompt La instruccion que se mostrara al usuario.
     * @param ValidChars Los valores que acepta la funcion.
     * @post La función se ejecutara indefinidamente hasta que se ingrese un caracter valido.
     * @warning Si el usuario ingresa un espacio seguido de un salto de linea. 
     * @return character
     */
    // Revisar el manejo de saltos de línea y espacios en las entradas.
    static char inputValidChar(str prompt, List<char> validChars) {
        char character;
        bool valid = false;
        while (!valid) {
            std::cout << prompt;
            std::cin >> character;
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            valid = validChars.search(character);
            Console::clear();
        }
        return character;
    }

    /**
     * @brief Para 
     */
    static std::string inputValidString(std::string prompt) {
        std::string text;
        bool valid = false;
        while (!valid) {
            std::cout << prompt;
            std::getline(std::cin, text);
            std::cin.clear();
            valid = text.find(' ') == std::string::npos;
            Console::clear();
        }
        return text;
    }

    /**
     * @brief Para recibir un numero valido dentro de un rango definido
     * @param prompt Instruccion para el usuario
     * @param min El valor minimo que recibe la funcion
     * @param max El valor maximo que recibe la funcion 
     */
    static int inputValidInt(std::string prompt, int min, int max) {
        int num = min - 1;
        while (num < min || num > max) {
            std::cout << prompt;
            std::cin >> num;
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            Console::clear();
        }
        return num;
    }
};

#endif
