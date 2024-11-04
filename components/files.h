#ifndef FILES_H
#define FILES_H

#include <string>

class PixelFile {
    public:
    int x;
    int y;
    PixelFile(int x, int y) : x(x), y(y) {} // for new projects
    PixelFile(std::string path); // loading old projects
    void FileSave(std::string name);
};

#endif 