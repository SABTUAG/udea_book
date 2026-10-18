#include "console.h"
#include <iostream>

void Console::clear(int lines)
{
while (lines>0){
    std::cout<<"\033[A\033[2K\r";
    lines--;
}
}

char Console::inputChar(
    const char* prompt, 
    const str& validChars
){  
unsigned int lenValidChars=validChars.len(); 
char character;
bool valid = false;
while (!valid) {
    std::cout << prompt;
    std::cin >> character;
    std::cin.clear();
    std::cin.ignore(1000, '\n');
    for(unsigned int n=0; n<lenValidChars; n++){
        if (character==validChars[n]){
            valid=true; 
            break; 
        }
    }
    Console::clear();
}
return character;
}

str Console::inputStr(
    const char* prompt, 
    const str& validChars, 
    int maxLength
){
str input;
bool isValid = false;
while (!isValid){
    std::cout<<prompt;
    getline(std::cin, input);
    isValid=true; 
    if (input.len()>maxLength){
        std::cout<<"Error: Texto demasiado largo.\n";
        isValid=false;
    } 
    else {
        for (int i=0; i<input.len(); i++){
            if (validChars.find(input[i]) ==str::NPOS){
                std::cout<<"Caracter invalido: "<<input[i]<<"\n";
                isValid = false;
                break; 
            }
        }
    }
    if (!isValid){
        std::cout<<"Presione Enter para intentar de nuevo...";
        std::cin.get(); 
        Console::clear(4);
    } else Console::clear(); 
}
return input;
}

int Console::inputInt(
    const char* prompt, 
    int min, 
    int max
){
int num = min-1;
while (num<min || num>max){
    std::cout<<prompt;
    std::cin>>num;
    std::cin.clear();
    std::cin.ignore(1000,'\n');
    Console::clear();
}
return num;
} 