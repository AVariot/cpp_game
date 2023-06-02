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
    obs = new std::list<obstacle_c>();
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

obstacle_c *map_c::init_obs_instance(sf::Vector2f pos)
{
    obstacle_c *obs = new obstacle_c();
    obs->texture.loadFromFile("assets/map/triangle.png");
    obs->sprite.setTexture(obs->texture);
    obs->pos = pos;
    obs->sprite.setPosition(obs->pos);
    obs->sprite.setScale((sf::Vector2f){0.09, 0.09});
    return obs;
}

void map_c::init_obstacle(void)
{
    float j = 0;
    for (int i = 0; i < act_map.length(); i++, j++) {
        if (act_map[i] == '<') {
            obstacle_c *ob = init_obs_instance((sf::Vector2f){14 * j, 300});
            obs->push_back(*ob);
        }
    }
}

void map_c::move_obstacle(void)
{
    for (auto ob = obs->begin(); ob != obs->end(); ob++) {
        ob->pos.x -= 1;
        ob->sprite.setPosition(ob->pos);
    }
}

void map_c::print_obstacle(sf::RenderWindow &window)
{
    move_obstacle();
    for (auto ob = obs->begin(); ob != obs->end(); ob++) {
        std::cout << ob->pos.x << std::endl;
        window.draw(ob->sprite);
    }
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

        std::cout << fileContent << std::endl;
        return fileContent;
    } else {
        std::cout << "Échec de l'ouverture du fichier." << std::endl;
        return NULL;
    }
}
