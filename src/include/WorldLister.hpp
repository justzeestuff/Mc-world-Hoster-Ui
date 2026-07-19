#include <filesystem>
#include "include.hpp"

namespace fs = std::filesystem;

std::vector<fs::path> WorldLister(){
    std::vector<fs::path> dirs = {};
    fs::path path = "/home/zee/Desktop/McServer";    

    int i = 0;
    for(const auto& item : fs::directory_iterator(path)){
        i++;
        std::cout << i << '.' << item.path().filename() << '\n';

        dirs.push_back({item.path()});
    }
    return dirs;
}