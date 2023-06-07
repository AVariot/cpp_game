/*
        R&A
*/

#include "../main.hpp"

void level_c::init_level(void)
{
    background_txt.loadFromFile("src/menu/bck.jpg");
    background_spr.setTexture(background_txt);
    play_txt.loadFromFile("src/menu/play_btn.png");
    play_spr.setTexture(play_txt);
    play_spr.setPosition(sf::Vector2f{1125, 375});
    play_spr.setScale(sf::Vector2f{0.3, 0.3});
    quit_txt.loadFromFile("src/menu/close.png");
    quit_spr.setTexture(quit_txt);
    quit_spr.setPosition(sf::Vector2f{150, 100});
    quit_spr.setScale(sf::Vector2f{0.6, 0.6});
    rect.setPosition(sf::Vector2f{550, 150});
    rect.setFillColor(sf::Color::Blue);
    rect.setSize(sf::Vector2f{800, 450});
    rect.setOutlineColor(sf::Color::Black);
    rect.setOutlineThickness(10.0);
    font.loadFromFile("src/menu/PUSAB___.otf");
    text.setFont(font);
    text.setString("Eliott je t'aime <3\n\n\nDifficulte :\n\n\nFacile");
    text.setCharacterSize(70);
    text.setFillColor(sf::Color::White);
    text.setPosition(sf::Vector2f{600, 200});
}

level_c create_levels(void)
{
        level_c n_level = level_c();
        n_level.init_level();
        return n_level;
}

void level_c::display_level(sf::RenderWindow &window)
{
        window.draw(background_spr);
        window.draw(rect);
        window.draw(text);
        window.draw(play_spr);
        window.draw(quit_spr);
}