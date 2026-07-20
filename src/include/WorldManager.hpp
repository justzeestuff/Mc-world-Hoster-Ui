#include "include.hpp"
#include <filesystem>
#include <cctype>

namespace fs = std::filesystem;

int StartWorld(std::vector<fs::path> worlds)
{
    size_t index;
    std::cout << "World's index: ";
    std::cin >> index;

    if(index == 1 || index > worlds.size()){
        std::cerr << "The index cannot select nonExistant worlds please try again.\n";
        return 1;
    }
    index -= 1;

    size_t minRam, maxRam;
    std::cout << "Minimum RAM: ";
    std::cin >> minRam;
    std::cout << "Maximum RAM: ";
    std::cin >> maxRam;

    // Check if minRam and maxRam are actual Numbers
    if (!(std::cin >> minRam) || !(std::cin >> maxRam)) {
       std::cerr << "RAM cannot be nothing other than a digit.\n";
       return 1;
    }

    // Check if minRam is larger than maxRam
    if(minRam > maxRam) {
        std::swap(minRam, maxRam);
        std::cout << "minimum amount of RAM cannot be larger than the maximum dedicated RAM." << " \n the program automatically switched Minimum and Maximum RAM places";
    }
    

    fs::path worldPath = worlds[index];
    std::stringstream cmd;

    fs::current_path(worldPath);

    cmd << "java -Xmx" << maxRam 
        << "G -Xms"    << minRam
        << "G @user_jvm_args.txt @libraries/net/minecraftforge/forge/1.20.1-47.4.21/unix_args.txt";

    std::system(cmd.str().c_str());
    return 0;
}

std::vector<fs::path> WorldLister(fs::path path){
    std::vector<fs::path> dirs = {};    
    int i = 0;

    for(const auto& item : fs::directory_iterator(path)){
        i++;
        std::cout << i << '.' << item.path().filename() << '\n';

        dirs.push_back({item.path()});
    }
    return dirs;
}