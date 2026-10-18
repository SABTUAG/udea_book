#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H

#include "../tools/str.h"
#include "../tools/listTemplate.h"

/**
 * @brief Utilidades para lectura y escritura de archivos txt.
 */
class FileManager {

public: 
    /**
     * @brief Lee un archivo y guarda cada bloque { ... } como un elemento.
     * @param filePath Ruta del archivo.
     * @param elements Lista donde se agregan los bloques leídos.
     * @return true si el archivo se leyó correctamente, false en caso contrario.
     * @note Ignora todo lo que esté fuera de las llaves { }.
     * @warning No soporta bloques anidados { { } }.
     */
    static bool read(
        const str& filePath, 
        List<str>& elements
    );

    /**
     * @brief Sobrescribe el archivo con los elementos de la lista.
     * @param filePath Ruta del archivo.
     * @param elements Lista de bloques a escribir.
     * @return true si se escribió correctamente, false en caso contrario.
     * @note Envuelve cada elemento entre { y } al escribirlo.
     */
    static bool update(
        const str& filePath, 
        const List<str>& elements
    ); 
};

#endif