#ifndef FILE_MANAGEMENT_H
#define FILE_MANAGEMENT_H

#include "../tools/str.h"
#include "../tools/listTemplate.h"

/**
 * @brief Utilidades para lectura y escritura de archivos txt
 */
class FileManager {

public: 


/**
 * @brief Lee todas las líneas de un archivo txt. 
 * @param filePath Ruta del archivo. 
 * @param lines Donde se agregan las líneas.
 * @return true si el archivo se leyo correctamente, false en el caso contrario. 
 */
static bool read(const str& filePath, List<str>&lines);



};


#endif
