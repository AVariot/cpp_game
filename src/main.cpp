/*
        R&A
*/

#include "main.hpp"

// Init all_c class

void all_c::init_all_c_class(void)
{
    mode = sf::VideoMode::getDesktopMode();
    window.create(mode, "Geometry doush");
    window.setKeyRepeatEnabled(false);
    scene = MENU;
    menu = create_menu();
}

// Create class

all_c *create_all_c_class(void)
{
    all_c *new_all_c = new all_c();
    new_all_c->init_all_c_class();
    return new_all_c;
}

// Loop Game

int all_c::loop_game(void)
{
    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::MouseButtonPressed){
                if (event.mouseButton.button == sf::Mouse::Left){
                    sf::Vector2i mousPos = sf::Mouse::getPosition(window);
                    sf::Vector2f worldPos = window.mapPixelToCoords(mousPos);
                    if (menu->settings_spr.getGlobalBounds().contains(worldPos)){
                        scene = SETTINGS;
                    }
                }
            }

            if (event.key.code == sf::Keyboard::Escape)
                window.close();
            if (event.type == sf::Event::Closed) {
                window.close();
                return 0;
            }
        }
        window.clear(sf::Color::Black);
        menu->display_menu(window);
        window.display();
    }
    return 0;
}

int main(void)
{
    all_c *all = create_all_c_class();
    all->loop_game();
    return 0;
}
