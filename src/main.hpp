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

    class all_c {
        public:
            // Fonction all_c
            int loop_game(void);
            void init_all_c_class(void);
            //variables
            sf::RenderWindow window;
            sf::Event event;

        private:
            sf::VideoMode mode;
    };

#endif // !main_hpp
