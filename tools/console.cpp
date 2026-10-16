#include "console.h"
#include <iostream>

void Console::clear(int lines){
    while (lines>0){
        std::cout << "\033[A\033[2K\r";
        lines--;
    }
}

char Console::inputChar(
    const char* prompt, 
    const str& validChars
){
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

int Console::inputInt(
    const char* prompt, 
    int min, 
    int max
){
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