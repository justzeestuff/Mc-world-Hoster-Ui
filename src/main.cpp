#include <filesystem>
#include <cstdlib>

#include "include/include.hpp"
#include "include/WorldManager.hpp"

namespace fs = std::filesystem;

int main(){
    fs::path tempPath = "/home/zee/Desktop/McServer"; 
    while (true)
    {
        std::string entry = "Create World [0] - Use Existing World [1]";
        int client;

        std::cout << entry << " :";
        std::cin >> client;

        if(client == 1){
            std::vector<fs::path> worlds = WorldLister(tempPath);
            StartWorld(worlds);
        }
    }

    return 0;
}