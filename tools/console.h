#ifndef CONSOLE_H
#define CONSOLE_H

#include "str.h"

/**
 * @brief Utilidades que facilitan que optimizan el uso consola.
 */
class Console {
public:

    /**
     * @brief Borra una cantidad de lineas de la terminal.
     * @param lines Cantidad de lineas a borrar. 
     */
    static void clear(int lines = 1); 

    /**
     * @brief Solicita un carácter valido. 
     * @param prompt Instruccioón al usuario
     * @param validCahars Caracteres aceptados.
     * @return El carácter ingresado.
     */
    static char inputChar(
        const char* prompt, 
        const str& validChars
    ); 

    /**
     * @brief Solicita una cadena. 
     * @bug Sin soporte, NO usar. 
     */
    static str inputStr(
        const char* prompt, 
        const str& validChars, 
        int maxLength
    ); 

    /**
     * @brief Solicita un entero valido dentro de un rango.
     * @param prompt Instrucción al usuario.
     * @param min Valor mínimo aceptado.
     * @param max Valor máximo aceptado.
     */
    static int inputInt(
        const char* prompt, 
        int min, 
        int max
    ); 
};

#endif
