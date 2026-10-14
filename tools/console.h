#ifndef CONSOLE_H
#define CONSOLE_H

#include <iostream>
#include <string>
#include "str.h"
#include "listTemplate.h"


/**
 * @brief Para facilitar acciones con la consola
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
     * @bug Sin soporte para class str, No usar
     * @return character
     */
    // Revisar el manejo de saltos de línea y espacios en las entradas.
    //static char input(const str& prompt, List<char>& validChars) {
    static char inputChar(const str& prompt, const str& validChars) {
        char character;
        bool valid = false;
        while (!valid) {
            std::cout << prompt;
            std::cin >> character;
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            for(int n=0; n< validChars.len(); n++){
                if (character == validChars[n]){
                    valid = true; 
                    break; 
                }
            }
            Console::clear();
        }
        return character;
    }

    /**
     * @brief Para 
     * @bug No integrar, fallas en todo
     */
    static std::string inputStr(
        const std::string& prompt, 
        const str& unacceptableValues
    ) {
        std::string text;
        bool valid = false;
        while (!valid) {
            std::cout << prompt;
            getline(std::cin, text);
            std::cin.clear();
            valid = true; 
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
    static int inputInt(const str& prompt, int min, int max) {
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
