#include <filesystem>
#include <cstdlib>

#include "include/include.hpp"
#include "include/WorldLister.hpp"

namespace fs = std::filesystem;

int main(){
    while (true)
    {
        std::string entry = "Create World [0] - Use Existing World [1]";
        int client;

        std::cout << entry << " :";
        std::cin >> client;

        if(client == 1){
            std::vector<fs::path> worlds = WorldLister();

            int world;
            std::cout << "World's index: ";
            std::cin >> world;

            world -= 1;

            int min;
            std::cout << "Minimum Ram: ";
            std::cin >> min;

            int max;
            std::cout << "Maximum Ram: ";
            std::cin >> max;

            // java -Xms{}G -Xmx{}G -jar server.jar nogui
            std::string worldPath = worlds[world];
            std::stringstream cmd;

            fs::current_path(worldPath);
            
            cmd << "java -Xmx" << max << "G -Xms" << min
                <<"G @user_jvm_args.txt @libraries/net/minecraftforge/forge/1.20.1-47.4.21/unix_args.txt";
            
            std::system(cmd.str().c_str());
        }
    }

    return 0;
}