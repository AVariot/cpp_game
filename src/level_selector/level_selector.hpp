/*
        R&A
*/

#pragma once
#include <SFML/Graphics.hpp>

class level_c {
    public:
        void init_level();
        void display_level(sf::RenderWindow &window);
        sf::Sprite quit_spr;
        sf::Sprite play_spr;
    private:
        sf::Texture background_txt;
        sf::Sprite background_spr;
        sf::Texture play_txt;
        sf::Texture quit_txt;
        sf::RectangleShape rect;
        sf::Text text;
        sf::Font font;
};

level_c create_levels(void);