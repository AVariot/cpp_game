/*
        R&A
*/

#include "main.hpp"

// Init all_c class

void all_c::init_all_c_class(void)
{
    mode = sf::VideoMode::getDesktopMode();
    window.create(mode, "Geometry doush");
    window.setKeyRepeatEnabled(false);
    scene = MENU;
    menu = create_menu();
    settings = create_settings();
}

// Create class

all_c *create_all_c_class(void)
{
    all_c *new_all_c = new all_c();
    new_all_c->init_all_c_class();
    return new_all_c;
}

// Loop Game

int all_c::loop_game(void)
{
    std::ifstream file("ressources/volume.txt");
    if (!file.is_open()) {
        std::cout << "Erreur lors de l'ouverture du fichier." << std::endl;
        return -1;
    }
    file >> settings->volumeLevel;
    file.close();
    sf::SoundBuffer music_buffer;
    music_buffer.loadFromFile("ressources/ICE_geo_.save.wav");
    sf::Sound music;
    music.setBuffer(music_buffer);
    music.setLoop(true);
    music.setVolume(settings->volumeLevel);
    printf("%f\n", settings->volumeLevel);
    music.play();
    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::MouseButtonPressed){
                if (event.mouseButton.button == sf::Mouse::Left){
                    sf::Vector2i mousPos = sf::Mouse::getPosition(window);
                    sf::Vector2f worldPos = window.mapPixelToCoords(mousPos);
                    if (menu->settings_spr.getGlobalBounds().contains(worldPos)){
                        scene = SETTINGS;
                    }
                    if (settings->quit_spr.getGlobalBounds().contains(worldPos)){
                        scene = MENU;
                    }
                }
            }
            if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left) {
                float barWidth = settings->volumeBar.getSize().x;
                float mouseX = event.mouseButton.x - 500;
                settings->volumeLevel = (mouseX / barWidth) * 100;
                music.setVolume(settings->volumeLevel);
            }
            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                if (settings->volumeHandler.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                    settings->isDragging = true;
                }
            }
            if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left) {
                settings->isDragging = false;
            }
            if (event.type == sf::Event::MouseMoved) {
                if (settings->isDragging) {
                    float mouseX = event.mouseMove.x;
                    float buttonWidth = settings->volumeHandler.getSize().x;
                    float newPosition = mouseX - buttonWidth / 2;
                    if (newPosition < settings->buttonLeftLimit) {
                        newPosition = settings->buttonLeftLimit;
                    }
                    if (newPosition > settings->buttonRightLimit - buttonWidth) {
                        newPosition = settings->buttonRightLimit - buttonWidth;
                    }
                    settings->volumeHandler.setPosition(newPosition, settings->volumeHandler.getPosition().y);
                }
            }
            if (event.key.code == sf::Keyboard::Escape)
                window.close();
            if (event.type == sf::Event::Closed) {
                window.close();
                return 0;
            }
        }
        std::ofstream file("ressources/volume.txt");
        if (file.is_open()) {
            file << settings->volumeLevel;
            file.close();
        }
        window.clear(sf::Color::Black);
        window.draw(settings->volumeHandler);
        if (scene == SETTINGS)
            settings->display_settings(window);
        if (scene == MENU)
            menu->display_menu(window);
        window.display();
    }
    music.stop();
    return 0;
}

int main(void)
{
    all_c *all = create_all_c_class();
    all->loop_game();
    return 0;
}
