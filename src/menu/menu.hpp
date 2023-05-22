/*
        R&A
*/

#pragma once
#include <SFML/Graphics.hpp>

class menu_c {
    public:
        void init_menu();
        void display_menu(sf::RenderWindow &window);

    private:
        sf::Sprite background_spr;
        sf::Texture background_txt;
};

menu_c *create_menu(void);
