/*
        R&A
*/

#include "../main.hpp"

void settings_c::init_settings(void)
{
    background_txt.loadFromFile("src/menu/bck.jpg");
    background_spr.setTexture(background_txt);
    quit_txt.loadFromFile("src/menu/close.png");
    quit_spr.setTexture(quit_txt);
    quit_spr.setScale(sf::Vector2f{0.6, 0.6});
    quit_spr.setPosition(sf::Vector2f{200, 100});
    background_spr.setScale(sf::Vector2f{1, 1});
    volumeLevel = 50.0f;
    volumeBar.setSize(sf::Vector2f(900 * 0.5, 30));
    volumeBar.setPosition(sf::Vector2f{500, 400});
    volumeBar.setFillColor(sf::Color::Green);
    volumeHandler.setSize(sf::Vector2f{50, 40});
    volumeHandler.setPosition(sf::Vector2f{500, 395});
    volumeHandler.setFillColor(sf::Color::Yellow);
    isDragging = false;
    buttonLeftLimit = 500.0f;
    buttonRightLimit = 950.0f;
}

settings_c create_settings(void)
{
    settings_c n_settings = settings_c();
    n_settings.init_settings();
    return n_settings;
}

void settings_c::display_settings(sf::RenderWindow &window)
{
    window.draw(background_spr);
    window.draw(quit_spr);
    window.draw(volumeBar);
    window.draw(volumeHandler);
}
