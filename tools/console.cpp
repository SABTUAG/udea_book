#include <iostream>
using namespace std;

// -- REVISAR inputValidChar e inputValidInt -- 
// FALLAS ESCONDIDAS: saltos de linea continua y espacios puedes 
// romper la lógica de visualización en consola. 
class Console {

    public: 

        static void clear(int lines = 1){ 
            while (lines > 0){
                cout << "\033[A\33[2K\r";
                lines--; 
            }    
        }
        
        template <unsigned int lengthValidChars>
        static char inputValidChar(
            const char* prompt, 
            const char (&validChars)[lengthValidChars]
        ){
            char character; 
            bool valid = false;
            while (!valid) {
                cout << prompt;
                cin >> character; 
                cin.clear(); 
                cin.ignore(1000, '\n'); 
                for (int n = 0; n < lengthValidChars; n++) {
                    if (character == validChars[n]) {
                        valid = true; 
                        break; 
                    }
                }
                Console::clear(); 
            }
            return character; 
        }

        static int inputValidInt(const char* prompt, int min, int max ){
            int num = min-1; 
            while (num < min || num > max) {
                cout << prompt;
                cin >> num; 
                cin.clear(); 
                cin.ignore(1000, '\n'); 
                Console::clear();        
            }
            return num; 
        }
}; 
