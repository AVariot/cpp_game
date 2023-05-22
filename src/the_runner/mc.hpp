/*
        R&A
*/

#ifndef mc_hpp
    #define mc_hpp

    #include <SFML/Graphics.hpp>

    class mc_c {
        public:
            //fonction
            void display_mc(sf::RenderWindow &window, sf::Clock clock);
            void init_mc_c_class(void);
            void move_mc(sf::Clock clock);

        private:
            sf::Sprite sprite;
            sf::Texture texture;
            sf::Vector2f pos;
            float speed;
    };

    // Prototypes

    mc_c *create_mc_c_class(void);

#endif // !mc_hpp