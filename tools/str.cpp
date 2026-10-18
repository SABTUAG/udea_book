#include "str.h"

int str::len(const char* text){
    int i=0;
    while (text[i] != '\0') i++;
    return i;
}
char* str::copy(const char* text){
    int n = len(text);
    char* whereToCopy = new char[n+1];
    for (int i = 0; i < n; i++){
        whereToCopy[i]=text[i];
    }
    whereToCopy[n]='\0';
    return whereToCopy;
}


str::str(): _len(0){
    _text = new char[1];
    _text[0] = '\0';
}
str::str(const char* text){
    _len = len(text);
    _text = copy(text);
}
str::str(const str& other){
    _len = other._len;
    _text = copy(other._text);
}
str::~str() {
    delete[] _text;
}


int str::len() const {
    return _len;
}
const char* str::c_str() const {
    return _text;
}


str& str::operator=(const char* text){
    if (_text == text) return *this; 
    delete[] _text;
    _len = len(text);
    _text = copy(text);
    return *this;
}
str& str::operator=(const str& other){
    if (this == &other) return *this;
    delete[] _text;
    _len = other._len;
    _text = copy(other._text);
    return *this;
}
char str::operator[](int i) const {
    return _text[i];
}
char& str::operator[](int i){
    return _text[i];
}
bool str::operator==(const str& other) const {
    if (_len != other._len) return false;
    for (int i = 0; i < _len; i++) {
        if (_text[i] != other._text[i]) return false;
    }
    return true;
}
bool str::operator==(const char* other) const {
    int n = len(other);
    if (_len != n) return false;
    for (int i = 0; i < _len; i++) {
        if (_text[i] != other[i]) return false;
    }
    return true;
}
bool str::operator!=(const str& other) const {
    return !(*this == other);
}
bool str::operator<(const str& other) const {
    int minLen = (_len < other._len)?_len:other._len;
    for (int i = 0; i < minLen; i++){
        if (_text[i] != other._text[i]){
            return (_text[i] < other._text[i]);
        }
    }
    return _len < other._len;
}
bool str::operator>(const str& other) const {
    return other < *this;
}
bool str::operator<=(const str& other) const {
    return !(other < *this);
}
bool str::operator>=(const str& other) const {
    return !(*this < other);
}
str str::operator+(const str& other) const {
    str newText;
    delete[] newText._text;
    newText._len = _len + other._len;
    newText._text = new char[newText._len + 1];
    for (int i = 0; i < _len; i++){
        newText._text[i] = _text[i];
    }
    for (int i = 0; i < other._len; i++) {
        newText._text[_len + i] = other._text[i];
    }
    newText._text[newText._len] = '\0';
    return newText;
}
str& str::operator+=(const str& other){
    *this = *this + other;
    return *this;
}
str& str::operator+=(char c){
    // Aquí creas un nuevo buffer con un espacio más y agregas el char
    char* newText=new char[_len+2];
    for (int i = 0; i<_len; i++){
        newText[i] = _text[i];
    }
    newText[_len]=c;
    newText[_len+1]='\0';
    delete[] _text;
    _text = newText;
    _len++;
    return *this;
}


int str::find(const str& substr) const {
    if (substr._len==0) return 0;
    if (substr._len > _len) return NPOS;
    for (int i=0; i<=(_len-substr._len); i++){
        bool substrInStr = true;
        for (int n=0; n<substr._len; n++){
            if (_text[i+n] != substr._text[n]){
                substrInStr = false;
                break;
            }
        }
        if (substrInStr) return i;
    }
    return NPOS;
}
int str::find(char c) const {
    for (int i=0; i<_len; i++){
        if (_text[i] == c) return i;
    }
    return NPOS;
}
str str::substr(int start, int length) const {
    if (start<0) start=0;
    if (start>=_len) return str();
    if (start+length > _len) length=_len-start;
    char* buffer=new char[length + 1];
    for (int i=0; i<length; i++){
        buffer[i]=_text[start+i];
    }
    buffer[length]='\0';
    str result(buffer);
    delete[] buffer; 
    return result;
}
List<str> str::split(char delimiter) const {
    List<str> result;
    int start=0;
    for (int i=0; i<=_len; i++){
        if ((i==_len) || (_text[i]==delimiter)){
            result.add(substr(start, i-start));
        }
    }
    return result;
}
str str::strip() const {
    unsigned int start=0; 
    unsigned int end= _len - 1;  
    while (
        (start<_len) &&
        (
            (_text[start]==' ')||
            (_text[start]=='\t')||
            (_text[start]=='\n')|| 
            (_text[start]=='\r')
        )
    ){
        start++;
    }
    while (
        (end>=start) &&
        (
            (_text[end]==' ')||
            (_text[end]=='\t')||
            (_text[end]=='\n')|| 
            (_text[end]=='\r')
        )
    ){
        end--;
    }
    if (start>end) return str(); 
    return substr(start, end-start+1); 
}

std::ostream& operator<<(
    std::ostream& output, 
    const str& string
){
    output << string._text;
    return output;
}

std::istream& operator>>(
    std::istream& input, 
    str& string
){
    char buffer[512];
    buffer[0]='\0'; 
    if (input>>buffer) string=buffer;
    else string = "";
    return input;
}

std::istream& getline(
    std::istream& input, 
    str& string
){
    char buffer[512];
    buffer[0] = '\0';
    if (input.getline(buffer, 512)) string=buffer;
    else {
        string = "";
        input.clear();
    }
    return input;
}