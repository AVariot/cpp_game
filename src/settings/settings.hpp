/*
        R&A
*/

#pragma once
#include <SFML/Graphics.hpp>

class settings_c {
    public:
        void init_settings();
        void display_settings(sf::RenderWindow &window);

    private:
        sf::Sprite background_spr;
        sf::Texture background_txt;
};

settings_c *create_settings(void);