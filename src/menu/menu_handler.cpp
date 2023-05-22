/*
        R&A
*/

#include "../main.hpp"

void menu_c::init_menu(void)
{
        background_txt.loadFromFile("src/menu/bck.jpg");
        background_spr.setTexture(background_txt);
        background_spr.setScale(sf::Vector2f{1, 1});
        background_spr.setPosition(sf::Vector2f{0, 0});
        play_txt.loadFromFile("src/menu/play_btn.png");
        play_spr.setTexture(play_txt);
        play_spr.setScale(sf::Vector2f{0.5, 0.5});
        play_spr.setPosition(sf::Vector2f{750, 500});
        font.loadFromFile("src/menu/PUSAB___.otf");
        title.setFont(font);
        title.setString("Geometry doush");
        title.setCharacterSize(80);
        title.setPosition(sf::Vector2f{575, 200});
}

menu_c *create_menu(void)
{
        menu_c *n_menu = new menu_c();
        n_menu->init_menu();
        return n_menu;
}

void menu_c::display_menu(sf::RenderWindow &window)
{
    window.draw(background_spr);
    window.draw(play_spr);
    window.draw(title);
}

void button_c::init_button(sf::Vector2f size, sf::Vector2f pos, sf::String str, int idd)
{
        rect.setFillColor(sf::Color(255,255,255,128));
        rect.setPosition(pos);
        rect.setSize(size);
        font.loadFromFile("src/menu/PUSAB___.otf");
        text.setFont(font);
        text.setString(str);
        text.setFillColor(sf::Color::Black);
        text.setCharacterSize(12);
        text.setPosition((sf::Vector2f){pos.x + 30, pos.y + 40});
        text.setCharacterSize(50);
        hitbox = rect.getGlobalBounds();
        id = idd;
}

button_c *create_button(void)
{
        button_c *n_button = new button_c();
        return n_button;
}

void menu_c::display_button(sf::RenderWindow &window)
{
    auto l = button.begin();

    while (l != button.end()) {
        window.draw(l->rect);
        window.draw(l->text);
        ++l;
    }
}

void menu_c::button_event(sf::Event event, sf::RenderWindow &window)
{
    if (event.type == sf::Event::MouseButtonPressed) {
        auto l = button.begin();
        while (l != button.end()) {
                sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
                sf::Vector2f mousePositionFloat(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y));
                float mouseX = mousePositionFloat.x;
                float mouseY = mousePositionFloat.y;
            if (l->hitbox.contains({mouseX, mouseY})) {
                if (l->id == 2)
                    window.close();
            }
            ++l;
        }
    }
}
