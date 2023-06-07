/*
        R&A
*/

#ifndef mc_hpp
    #define mc_hpp

    #include <SFML/Graphics.hpp>

    #define _MAX_HEIGTH_JUMP_   -200

    class mc_c {
        public:
            //fonction
            void display_mc(sf::RenderWindow &window, sf::Clock clock, sf::FloatRect floor);
            void init_mc_c_class(void);
            void apply_gravity(sf::Clock clock, sf::FloatRect floor);
            void event_mc_c(sf::Event event);
            void jump_effect(sf::Clock clock, sf::FloatRect floor);
            //variables
            int gravity;
            bool is_jumping;
            bool is_jump_up;
            sf::Sprite sprite;
            sf::View view;

        private:
            sf::Texture texture;
            sf::Vector2f pos;
            float speed;
    };

    // Prototypes

    mc_c *create_mc_c_class(void);

#endif // !mc_hpp
