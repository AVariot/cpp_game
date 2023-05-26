/*
        R&A
*/

#include "../main.hpp"

void map_c::init_map_c_class(void)
{
    if (!texture.loadFromFile("assets/map/back.png")) {
        printf("Err: impossible to load the back.png from assets/map\n");
        exit(84);
    }
    pos = {0, 0};
    float y = 810;
    floor = {0, y, 1920, 1080 - y};

    sprite.setTexture(texture);
    sprite.setPosition(pos);
}

map_c *create_map_c_class(void)
{
    map_c *new_map = new map_c();
    new_map->init_map_c_class();
    return new_map;
}

void map_c::display_map(sf::RenderWindow &window, sf::Clock clock)
{
    pos.x -= 2;
    if (pos.x <= -3840)
        pos.x = 0;
    sprite.setPosition(pos);
    window.draw(sprite);
}

std::string map_c::get_file_info(std::string file)
{
    std::ifstream inputFile;
    inputFile.open(file);

    if (inputFile.is_open()) {
        std::string fileContent;
        std::string line;
        
        while (std::getline(inputFile, line)) {
            fileContent += line + "\n";
        }

        inputFile.close();

        // Afficher le contenu du fichier
        std::cout << fileContent << std::endl;
        return fileContent;
    } else {
        std::cout << "Échec de l'ouverture du fichier." << std::endl;
        return NULL;
    }
}
