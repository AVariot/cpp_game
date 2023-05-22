/*
        R&A
*/

#include "../main.hpp"

void mc_c::init_mc_c_class(void)
{
    if (!texture.loadFromFile("assets/mc/base_mc.png")) {
        printf("Err: impossible to load the base_mc.png from assets/mc\n");
        exit(84);
    }
    pos = {200, 200};
    speed = 1;

    sprite.setTexture(texture);
    sprite.setPosition(pos);
    sprite.setScale({0.1, 0.1});
}

mc_c *create_mc_c_class(void)
{
    mc_c *new_mc_c = new mc_c();
    new_mc_c->init_mc_c_class();
    return new_mc_c;
}

void mc_c::move_mc(sf::Clock clock)
{
    pos.x += (speed * clock.getElapsedTime().asMilliseconds());
    pos.x += (speed);
    sprite.setPosition(pos);
}

void mc_c::display_mc(sf::RenderWindow &window, sf::Clock clock)
{
    move_mc(clock);
    window.draw(sprite);
}
