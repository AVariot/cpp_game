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
    #include <list>
    #include "menu/menu.hpp"
    #include "settings/settings.hpp"
    #include "level_selector/level_selector.hpp"

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
            //variables
            sf::RenderWindow window;
            sf::Event event;
            menu_c *menu;
            settings_c *settings;
            level_c *level;

        private:
            sf::VideoMode mode;
    };

#endif // !main_hpp
