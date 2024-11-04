#include "files.h"
#include <string>
#include <fstream>

PixelFile::PixelFile(std::string path) {
    if (path.length() < 4) {
        return;
    }
    if (path.substr(path.length() - 4) != ".txt") {
        return;
    }
}

void PixelFile::FileSave(std::string name) {
    if (name.substr(name.length() - 4) != ".txt") {
        name += ".txt";
    }
    std::ofstream File(name);

    

    File.close();
}