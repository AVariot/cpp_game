/*
        R&A
*/

#ifndef map_hpp
    #define map_hpp

    #include <SFML/Graphics.hpp>

    class map_c {
        public:
            // Prototypes
            void init_map_c_class(void);
            void display_map(sf::RenderWindow &window);
            // Variables
            sf::Sprite sprite;
            sf::Vector2f pos;
            sf::FloatRect floor;

        private:
            sf::Texture texture;

    };

    // Prototypes

    map_c *create_map_c_class(void);

#endif // !map_hpp
