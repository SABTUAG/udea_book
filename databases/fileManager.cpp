#include "FileManager.h"
#include <fstream>

bool FileManager::read(
    const str& filePath, 
    List<str>& elements
){
    std::ifstream file(filePath.c_str());
    if (!file.is_open()) return false;
    char letter;
    bool insideBlock = false;
    str buffer;
    while (file.get(letter)) {
        if (letter == '{') {
            insideBlock = true;
            buffer = "";
        } 
        else if (letter == '}'){
            if (insideBlock){
                elements.add(buffer);  
                insideBlock = false;
            }
        } 
        else if (insideBlock){
            char temp[2];
            temp[0] =letter;
            temp[1] ='\0';
            buffer += str(temp);
        }
    }
    file.close();
    return true;
}


bool FileManager::update(
    const str& filePath, 
    const List<str>& elements
){
    std::ofstream file(filePath.c_str());
    if (!file.is_open()) return false;
    elements.forEach(
        [&](const str& element){
            file<< "{\n" 
                << element.c_str() 
                << "\n}\n";
        }
    );
    file.close();
    return true;
}

