/*
        R&A
*/

#include "../main.hpp"

void settings_c::init_settings(void)
{
    background_txt.loadFromFile("src/menu/bck.jpg");
    background_spr.setTexture(background_txt);
    background_spr.setScale(sf::Vector2f{1, 1});
}

settings_c *create_settings(void)
{
    settings_c *n_settings = new settings_c();
    n_settings->init_settings();
    return n_settings;
}

void settings_c::display_settings(sf::RenderWindow &window)
{
    window.draw(background_spr);
}
