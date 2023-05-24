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
    pos = {200, 200};
    speed = 0.5;
    gravity = -1;

    is_jumping = false;
    is_jump_up = true;

    sprite.setTexture(texture);
    sprite.setPosition(pos);
    sprite.setScale({0.1, 0.1});
}

mc_c *create_mc_c_class(void)
{
    mc_c *new_mc_c = new mc_c();
    new_mc_c->init_mc_c_class();
    return new_mc_c;
}

void mc_c::apply_gravity(sf::Clock clock)
{
    // pos.y -= (gravity * clock.getElapsedTime().asMilliseconds());
    if (pos.y < 700) {
        pos.y -= (gravity);
        sprite.setPosition(pos);
    }
}

void mc_c::jump_effect(sf::Clock clock)
{
    // pos.x += 0.7;
    if (is_jump_up) {
        if (gravity > _MAX_HEIGTH_JUMP_)
            (pos.y -= 3 * (clock.getElapsedTime().asMicroseconds() / 100)), gravity--;
        else
            is_jump_up = false;
    } else {
        if (gravity < -1)
            (pos.y += 3 * (clock.getElapsedTime().asMicroseconds() / 100)), gravity++;
        else
            is_jumping = false;
    }
    sprite.setPosition(pos);
}

void mc_c::display_mc(sf::RenderWindow &window, sf::Clock clock)
{
    if (is_jumping)
        jump_effect(clock);
    else
        apply_gravity(clock);
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
