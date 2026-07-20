#include <filesystem>
#include <cstdlib>

#include "include/include.hpp"
#include "include/world/List.hpp"
#include "include/world/Start.hpp"

namespace fs = std::filesystem;

int main(){
    while (true)
    {
        std::string entry = "Create World [0] - Use Existing World [1]";
        int client;

        std::cout << entry << " :";
        std::cin >> client;

        if(client == 1){

        }
    }

    return 0;
}