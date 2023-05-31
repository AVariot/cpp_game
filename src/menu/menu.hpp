/*
        R&A
*/

#pragma once
#include <SFML/Graphics.hpp>
#include <list>

class button_c {
    public:
        void init_button(sf::Vector2f size, sf::Vector2f pos, sf::String str, int id);
        sf::RectangleShape rect;
        sf::Text text;
        int id;
        sf::FloatRect hitbox;

    private:
        sf::Font font;
};

class menu_c {
    public:
        void init_menu();
        void display_menu(sf::RenderWindow &window);
        void display_button(sf::RenderWindow &window);
        std::list<button_c> button;
        sf::Sprite settings_spr;

    private:
        sf::Texture play_txt;
        sf::Sprite play_spr;
        sf::Sprite background_spr;
        sf::Texture background_txt;
        sf::FloatRect settings_hitbox;
        sf::Texture settings_txt;
        sf::Text title;
        sf::Font font;
};

menu_c *create_menu(void);
button_c *create_button(void);
