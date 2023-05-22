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
    // Init other class
    mc = create_mc_c_class();
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
            if (event.type == sf::Event::Closed) {
                window.close();
                return 0;
            }
        }
        window.clear(sf::Color::Black);
        mc->display_mc(window, clock);
        window.display();
        clock.restart();
    }
    return 0;
}

int main(void)
{
    all_c *all = create_all_c_class();
    all->loop_game();
    return 0;
}
