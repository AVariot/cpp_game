/*
        R&A
*/

#ifndef map_hpp
    #define map_hpp

    #include <SFML/Graphics.hpp>
    #include <iostream>
    #include <list>
    #include <fstream>
    #include <string>
    #include <fstream>

    class obstacle_c {
        public:
            sf::Sprite sprite;
            sf::Texture texture;
            sf::Vector2f pos;
    };

    class map_c {
        public:
            // Prototypes
            void init_map_c_class(void);
            void display_map(sf::RenderWindow &window, sf::Clock clock);
            std::string get_file_info(std::string file);
            void init_obstacle(void);
            obstacle_c init_obs_instance(sf::Vector2f pos);
            void print_obstacle(sf::RenderWindow &window);
            void move_obstacle(void);
            void check_collision(sf::Sprite spr);
            void setposX(float tmp) {pos.x = tmp;};
            float getPosX() {return pos.x;};
            // Variables
            sf::Sprite sprite;
            // std::pair < int,int > position;
            sf::FloatRect floor;
            std::vector<obstacle_c> obs;
            std::string act_map;

        private:
            sf::Vector2f pos = {0, 0};
            sf::Texture texture;

    };

    // Prototypes

    map_c create_map_c_class(void);

#endif // !map_hpp
