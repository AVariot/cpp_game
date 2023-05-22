/*
        R&A
*/

#include "../main.hpp"

void menu_c::init_menu(void)
{
        background_txt.loadFromFile("src/menu/bck.jpg");
        background_spr.setTexture(background_txt);
        background_spr.setScale(sf::Vector2f{1, 1});
        background_spr.setPosition(sf::Vector2f{0, 0});
}

menu_c *create_menu(void)
{
        menu_c *n_menu = new menu_c();
        n_menu->init_menu();
        return n_menu;
}

void menu_c::display_menu(sf::RenderWindow &window)
{
    window.draw(background_spr);
}
