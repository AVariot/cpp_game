/*
        R&A
*/

#include "main.hpp"


// Create class

all_c create_all_c_class(void)
{
    all_c nall = all_c();
    nall.init_all_c_class();
    return nall;
}

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

// Loop Game

int loop_game(void)
{
    all_c nall;
    nall = create_all_c_class();
    if (!nall.window.isOpen())
        printf("ABCD\n");
    std::ifstream file("ressources/volume.txt");
    if (!file.is_open()) {
        std::cout << "Erreur lors de l'ouverture du fichier." << std::endl;
        return -1;
    }
    file >> nall.settings.volumeLevel;
    file.close();
    sf::SoundBuffer music_buffer;
    nall.music_buffer.loadFromFile("ressources/ICE_geo_.save.wav");
    sf::Sound music;
    nall.music.setBuffer(music_buffer);
    nall.music.setLoop(true);
    nall.music.setVolume(nall.settings.volumeLevel);
    nall.music.play();
    nall.mc = create_mc_c_class();
    nall.map = create_map_c_class();
    while (nall.window.isOpen()) {
        while (nall.window.pollEvent(nall.event)) {
            if (nall.event.type == sf::Event::MouseButtonPressed){
                nall.scene_handler();
            }
            nall.settings_menu();
            if (nall.event.type == sf::Event::Closed) {
               nall.window.close();
                return 0;
            }
            nall.mc.event_mc_c(nall.event);
        }
        //-------------------------------------------------- fin poll event ----------------
        std::ofstream file("ressources/volume.txt");
        if (file.is_open()) {
            file << nall.settings.volumeLevel;
            file.close();
        }
        nall.window.clear(sf::Color::Black);
        nall.window.draw(nall.settings.volumeHandler);
        if (nall.scene == SETTINGS)
            nall.settings.display_settings(nall.window);
        if (nall.scene == MENU)
            nall.menu.display_menu(nall.window);
        if (nall.scene == LEVEL)
            nall.level.display_level(nall.window);
        if (nall.is_playing == 0)
            nall.game(nall.map, nall.mc, nall.clock, nall.window);
        nall.window.display();
        nall.clock.restart();
    }
    nall.music.stop();
    return 0;
}

void all_c::settings_menu(void)
{
    if (scene == SETTINGS){
        if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left) {
            float barWidth = settings.volumeBar.getSize().x;
            float mouseX = event.mouseButton.x - 500;
            settings.volumeLevel = (mouseX / barWidth) * 100;
            music.setVolume(settings.volumeLevel);
        }
        if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
            if (settings.volumeHandler.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                settings.isDragging = true;
            }
        }
        if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left) {
            settings.isDragging = false;
        }
        if (event.type == sf::Event::MouseMoved) {
            if (settings.isDragging) {
                float mouseX = event.mouseMove.x;
                float buttonWidth = settings.volumeHandler.getSize().x;
                float newPosition = mouseX - buttonWidth / 2;
                if (newPosition < settings.buttonLeftLimit) {
                    newPosition = settings.buttonLeftLimit;
                }
                if (newPosition > settings.buttonRightLimit - buttonWidth) {
                    newPosition = settings.buttonRightLimit - buttonWidth;
                }
                settings.volumeHandler.setPosition(newPosition, settings.volumeHandler.getPosition().y);
            }
        }
    }
}
void all_c::scene_handler(void)
{
    if (event.mouseButton.button == sf::Mouse::Left){
        sf::Vector2i mousPos = sf::Mouse::getPosition(window);
        sf::Vector2f worldPos = window.mapPixelToCoords(mousPos);
        if (menu.settings_spr.getGlobalBounds().contains(worldPos)){
            scene = SETTINGS;
        }
        if (scene == SETTINGS){
            if (settings.quit_spr.getGlobalBounds().contains(worldPos))
                scene = MENU;
        }
        if (scene == LEVEL){
            if (level.quit_spr.getGlobalBounds().contains(worldPos))
                scene = MENU;
            if (level.play_spr.getGlobalBounds().contains(worldPos)){
                window.clear(sf::Color::Black);
                is_playing = 0;
                music_buffer.loadFromFile("ressources/deep_124_.save.wav");
                music.setBuffer(music_buffer);
                music.setVolume(settings.volumeLevel);
                music.play();
            }
        }
        if (scene == MENU){
            if (menu.quit_spr.getGlobalBounds().contains(worldPos))
                window.close();
        }
        if (menu.play_spr.getGlobalBounds().contains(worldPos)){
            scene = LEVEL;
        }
    }
}
void all_c::game(map_c map, mc_c mc, sf::Clock clock, sf::RenderWindow &window)
{
    // map.setposX(map.getPosX() -1);
    map.display_map(window, clock);
    map.print_obstacle(window);
    mc.display_mc(window, clock, map.floor);
    map.check_collision(std::ref(mc.sprite));
}

int main(void)
{
    loop_game();
    return 0;
}
