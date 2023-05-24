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

    sprite.setTexture(texture);
//     sprite.setScale({5, 5});
    sprite.setPosition(pos);
}

map_c *create_map_c_class(void)
{
    map_c *new_map = new map_c();
    new_map->init_map_c_class();
    return new_map;
}

void map_c::display_map(sf::RenderWindow &window)
{
//     pos.x -= 2;
//     if (pos.x <= -3840)
//         pos.x = 0;
//     sprite.setPosition(pos);
    window.draw(sprite);
}
