/*
        R&A
*/

#include "../main.hpp"

void mc_c::init_mc_c_class(void)
{
    if (!texture.loadFromFile("assets/mc/base_mc.png")) {
        printf("Err: impossible to load the base_mc.png from assets/mc\n");
        exit(84);
    }
    pos = {200, 690};
    speed = 0.5;
    gravity = -1;

    is_jumping = false;
    is_jump_up = true;

    sprite.setTexture(texture);
    sprite.setPosition(pos);
    sprite.setScale({0.1, 0.1});

    view.setSize((sf::Vector2f){1920, 1080});
    view.setCenter((sf::Vector2f){1920 / 2, 1080 / 2});
}

mc_c *create_mc_c_class(void)
{
    mc_c *new_mc_c = new mc_c();
    new_mc_c->init_mc_c_class();
    return new_mc_c;
}

void mc_c::apply_gravity(sf::Clock clock, sf::FloatRect floor)
{
    if (!sprite.getGlobalBounds().intersects(floor))
        pos.y -= (gravity * (clock.getElapsedTime().asMilliseconds() / 100));
}

void mc_c::jump_effect(sf::Clock clock, sf::FloatRect floor)
{
    pos.x += 0.5;
    if (is_jump_up) {
        if (gravity > _MAX_HEIGTH_JUMP_)
            (pos.y -= 2 * (clock.getElapsedTime().asMicroseconds() / 100)), gravity--;
        else
            is_jump_up = false;
    } else {
        if (!sprite.getGlobalBounds().intersects(floor))
            (pos.y += 2 * (clock.getElapsedTime().asMicroseconds() / 100));
        else {
            is_jumping = false;
            gravity = -1;
        }
    }
    sprite.setPosition(pos);
}

void mc_c::display_mc(sf::RenderWindow &window, sf::Clock clock, sf::FloatRect floor)
{
    pos.x++;
    view.setCenter((sf::Vector2f){pos.x, view.getCenter().y});
    sprite.setPosition(pos);
    if (is_jumping)
        jump_effect(clock, floor);
    else
        apply_gravity(clock, floor);
    window.draw(sprite);
}

void mc_c::event_mc_c(sf::Event event)
{
    if (event.type == sf::Event::KeyPressed) {
        if (!is_jumping && event.key.code == sf::Keyboard::Space) {
            is_jumping = true;
            is_jump_up = true;
        }
    }
}
