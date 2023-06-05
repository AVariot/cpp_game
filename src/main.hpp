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
    #include <iterator>
    #include <list>
    #include <future>
    #include <iostream>
    #include <thread>

    #include "the_runner/mc.hpp"
    #include "map/map.hpp"

    enum SCENE {
        MENU,
        GAME,
        SETTINGS
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
            sf::Clock clock;
            // Other class
            mc_c *mc;
            map_c *map;

        private:
            sf::VideoMode mode;
    };

#endif // !main_hpp
