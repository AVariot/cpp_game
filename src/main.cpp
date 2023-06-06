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
    clock.restart();
    // Init other class
    mc = create_mc_c_class();
    map = create_map_c_class();
}

// Create class

all_c *create_all_c_class(void)
{
    all_c *new_all_c = new all_c();
    new_all_c->init_all_c_class();
    return new_all_c;
}

// Loop Game

int all_c::loop_game(void) {
    // std::thread collisionThread([&]() {
    //     map->check_collision(std::ref(mc->sprite));
    // });

    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
                return 0;
            }
            mc->event_mc_c(event);
        }
        window.clear(sf::Color::Black);
        map->display_map(window, clock);
        map->print_obstacle(window);
        mc->display_mc(window, clock, map->floor);
        map->check_collision(std::ref(mc->sprite));
        window.setView(mc->view);
        window.display();
        clock.restart();
    }

    // collisionThread.join(); // Attendre la fin de l'exécution du thread

    return 0;
}

int main(void)
{
    all_c *all = create_all_c_class();
    all->map->act_map = all->map->get_file_info("assets/map/map_txt/first.txt");
    all->map->init_obstacle();
    all->loop_game();
    return 0;
}
