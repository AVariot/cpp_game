/*
        R&A
*/

#pragma once
#include <SFML/Graphics.hpp>

class level_c {
    public:
        void init_level();
        void display_level(sf::RenderWindow &window);
    private:
        sf::Texture background_txt;
        sf::Sprite background_spr;
        sf::RectangleShape rect;
};

level_c *create_levels(void);