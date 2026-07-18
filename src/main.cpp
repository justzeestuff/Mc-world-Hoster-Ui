#include <filesystem>

// hand written includes
#include "include/include.hpp"
#include "include/WorldLister.hpp"

int main(){
    while (true)
    {
        std::string entry = "Create World [0] - Use Existing World [1]";
        int client;

        std::cout << entry << " :";
        std::cin >> client;
        
        if(client == 1){
            WorldLister();
        }
    }
    
    return 0;
}