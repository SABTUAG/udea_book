#ifndef CONSOLE_H
#define CONSOLE_H

#include <iostream>

#include "listTemplate.h"

class Console {
public:
    static void clear(int lines = 1) {
        while (lines > 0) {
            std::cout << "\033[A\33[2K\r";
            lines--;
        }
    }

    // Revisar el manejo de saltos de línea y espacios en las entradas.
    static char inputValidChar(const char* prompt, List<char> validChars) {
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

    static int inputValidInt(const char* prompt, int min, int max) {
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
