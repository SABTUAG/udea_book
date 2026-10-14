#ifndef FILE_MANAGEMENT_H
#define FILE_MANAGEMENT_H

#include <iostream>
#include <string>
#include <fstream>
#include <stdexcept>
#include "../tools/listTemplate.h"

/**
 * @brief Para manejar el archivo txt
 */
class File {
public: 
    /**
     * @brief Para leer el contenido de un archivo txt
     */
    static bool read(std::string filePath) {
        std::string line;
        std::ifstream inputFile(filePath); 
        while (std::getline(inputFile, line)) {
            std::cout << line << '\n';
        }
        return true; 
    }

    /**
     * @brief Para escribir en el archivo txt
     */
    static bool write() {
        // ..
    }
};


#endif
