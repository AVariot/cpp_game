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
    level = create_levels();
    clock.restart();
    // Init other class
    mc = create_mc_c_class();
    map = create_map_c_class();
    is_playing = 1;
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
                    if (scene == SETTINGS){
                        if (settings->quit_spr.getGlobalBounds().contains(worldPos))
                            scene = MENU;
                    }
                    if (scene == LEVEL){
                        if (level->quit_spr.getGlobalBounds().contains(worldPos))
                            scene = MENU;
                        if (level->play_spr.getGlobalBounds().contains(worldPos)){
                            window.clear(sf::Color::Black);
                            mc = create_mc_c_class();
                            map = create_map_c_class();
                            is_playing = 0;
                            music_buffer.loadFromFile("ressources/deep_124_.save.wav");
                            music.setBuffer(music_buffer);
                            music.setVolume(settings->volumeLevel);
                            music.play();
                            scene = GAME;
                        }
                    }
                    if (scene == MENU){
                        if (menu->quit_spr.getGlobalBounds().contains(worldPos))
                            window.close();
                    }
                    if (menu->play_spr.getGlobalBounds().contains(worldPos)){
                        scene = LEVEL;
                    }
                }
            }
            if (scene == SETTINGS){
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
            }
            if (event.type == sf::Event::Closed) {
                window.close();
                return 0;
            }
            mc->event_mc_c(event);
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
        if (scene == LEVEL)
            level->display_level(window);
        if (is_playing == 0)
            game(map, mc, clock, window);
        window.display();
        clock.restart();
    }
    music.stop();

    // collisionThread.join(); // Attendre la fin de l'exécution du thread
    return 0;
}

void game(map_c *map, mc_c *mc, sf::Clock clock, sf::RenderWindow &window)
{
    map->display_map(window, clock);
    map->print_obstacle(window);
    mc->display_mc(window, clock, map->floor);
    map->check_collision(std::ref(mc->sprite));
    // window.setView(mc->view);
}

int main(void)
{
    all_c *all = create_all_c_class();
    all->map->act_map = all->map->get_file_info("assets/map/map_txt/first.txt");
    all->map->init_obstacle();
    all->loop_game();
    return 0;
}