#ifndef FILE_MANAGEMENT_H
#define FILE_MANAGEMENT_H

#include <string>

class File {
private:
    std::string _name;
    std::string _path;

public:
    File();
    ~File();

    void read() {}
    void write() {}
};

class Directory {
};

#endif
