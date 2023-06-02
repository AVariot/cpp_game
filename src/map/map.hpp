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
            obstacle_c *init_obs_instance(sf::Vector2f pos);
            void print_obstacle(sf::RenderWindow &window);
            void move_obstacle(void);
            // Variables
            sf::Sprite sprite;
            sf::Vector2f pos;
            sf::FloatRect floor;
            std::list<obstacle_c> *obs;
            std::string act_map;

        private:
            sf::Texture texture;

    };

    // Prototypes

    map_c *create_map_c_class(void);

#endif // !map_hpp
