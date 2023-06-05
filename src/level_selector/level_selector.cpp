/*
        R&A
*/

#include "../main.hpp"

void level_c::init_level(void)
{
    background_txt.loadFromFile("src/menu/bck.jpg");
    background_spr.setTexture(background_txt);
    rect.setPosition(sf::Vector2f{550, 150});
    rect.setFillColor(sf::Color::Blue);
    rect.setSize(sf::Vector2f{800, 450});
    rect.setOutlineColor(sf::Color::Black);
    rect.setOutlineThickness(10.0);
}

level_c *create_levels(void)
{
        level_c *n_level = new level_c();
        n_level->init_level();
        return n_level;
}

void level_c::display_level(sf::RenderWindow &window)
{
        window.draw(background_spr);
        window.draw(rect);
}