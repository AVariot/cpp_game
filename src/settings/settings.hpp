/*
        R&A
*/

#pragma once
#include <SFML/Graphics.hpp>
#include <fstream>

class settings_c {
    public:
        void init_settings();
        void display_settings(sf::RenderWindow &window);
        sf::Sprite quit_spr;
        float volumeLevel;
        sf::RectangleShape volumeBar;
        sf::RectangleShape volumeHandler;
        bool isDragging;
        float buttonLeftLimit;
        float buttonRightLimit;

    private:
        sf::Sprite background_spr;
        sf::Texture background_txt;
        sf::Texture quit_txt;
};

settings_c *create_settings(void);