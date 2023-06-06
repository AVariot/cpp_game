/*
        R&A
*/

#ifndef main_hpp
    #define main_hpp

    #include <SFML/Audio.hpp>
    #include <SFML/Graphics.hpp>
    #include <SFML/Main.hpp>
    #include <SFML/System.hpp>
    #include <SFML/Window.hpp>
    #include <cmath>
    #include <dirent.h>
    #include <string>
    #include <fstream>
    #include <iostream>
    #include <iterator>
    #include <stdbool.h>
    #include <list>
    #include "menu/menu.hpp"
    #include "settings/settings.hpp"
    #include "level_selector/level_selector.hpp"
    #include <future>
    #include <iostream>
    #include <thread>
    #include "the_runner/mc.hpp"
    #include "map/map.hpp"

    enum SCENE {
        MENU,
        GAME,
        SETTINGS,
        LEVEL
    };

    class all_c {
        public:
            enum SCENE scene;
            // Fonction all_c
            int loop_game(void);
            void init_all_c_class(void);
            // Variables
            sf::RenderWindow window;
            sf::Event event;
            menu_c *menu;
            settings_c *settings;
            level_c *level;
            sf::Clock clock;
            // Other class
            mc_c *mc;
            map_c *map;
            int is_playing;

        private:
            sf::VideoMode mode;
    };

void game(map_c *map, mc_c *mc, sf::Clock clock, sf::RenderWindow &window);
#endif // !main_hpp
