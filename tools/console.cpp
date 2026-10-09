#include <iostream>
using namespace std;

// -- REVISAR inputValidChar e inputValidInt -- 
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
                //cin >> character; 
                cin.get(character); 
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

        // pro 
        static char inputChar(const char* prompt){
            try{
                cout << prompt; 
                char character; 
                if (!cin.get(character)){
                    Console::clear(); 
                    throw; 
                }
                cin.ignore(1000, '\n'); 
                return character; 
            }
            catch(...){
                cin.clear(); 
                Console::clear(); 
                return ' '; 
            }
        }

        template <unsigned int lengthValidChars>
        static char inputValidCharPro(
            const char* prompt, 
            const char (&validChars)[lengthValidChars]
        ){
            
            bool valid = false;
            while (!valid) {
                character = Console::inputChar(prompt); 
                for (int n = 0; n < lengthValidChars; n++) {
                    if (character == validChars[n]) {
                        valid = true; 
                        break; 
                    }
                }
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


int main(){
    //char dos[2] = {'a', 'b'}; 
    //Console::inputValidCharPro("Ingresa a-b: ", dos); 
    return 0;
}