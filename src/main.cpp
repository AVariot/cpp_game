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
    music_buffer.loadFromFile("ressources/ICE_geo_.save.wav");
    sf::Sound music;
    music.setBuffer(music_buffer);
    music.setLoop(true);
    music.setVolume(nall.settings.volumeLevel);
    music.play();
    nall.mc = create_mc_c_class();
    nall.map = create_map_c_class();
    while (nall.window.isOpen()) {
        while (nall.window.pollEvent(nall.event)) {
            if (nall.event.type == sf::Event::MouseButtonPressed){
                if (nall.event.mouseButton.button == sf::Mouse::Left){
                    sf::Vector2i mousPos = sf::Mouse::getPosition(nall.window);
                    sf::Vector2f worldPos = nall.window.mapPixelToCoords(mousPos);
                    if (nall.menu.settings_spr.getGlobalBounds().contains(worldPos)){
                        nall.scene = SETTINGS;
                    }
                    if (nall.scene == SETTINGS){
                        if (nall.settings.quit_spr.getGlobalBounds().contains(worldPos))
                            nall.scene = MENU;
                    }
                    if (nall.scene == LEVEL){
                        if (nall.level.quit_spr.getGlobalBounds().contains(worldPos))
                            nall.scene = MENU;
                        if (nall.level.play_spr.getGlobalBounds().contains(worldPos)){
                            nall.window.clear(sf::Color::Black);
                            nall.is_playing = 0;
                            music_buffer.loadFromFile("ressources/deep_124_.save.wav");
                            music.setBuffer(music_buffer);
                            music.setVolume(nall.settings.volumeLevel);
                            music.play();
                        }
                    }
                    if (nall.scene == MENU){
                        if (nall.menu.quit_spr.getGlobalBounds().contains(worldPos))
                            nall.window.close();
                    }
                    if (nall.menu.play_spr.getGlobalBounds().contains(worldPos)){
                        nall.scene = LEVEL;
                    }
                }
            }
            if (nall.scene == SETTINGS){
                if (nall.event.type == sf::Event::MouseButtonReleased && nall.event.mouseButton.button == sf::Mouse::Left) {
                    float barWidth = nall.settings.volumeBar.getSize().x;
                    float mouseX = nall.event.mouseButton.x - 500;
                    nall.settings.volumeLevel = (mouseX / barWidth) * 100;
                    music.setVolume(nall.settings.volumeLevel);
                }
                if (nall.event.type == sf::Event::MouseButtonPressed && nall.event.mouseButton.button == sf::Mouse::Left) {
                    if (nall.settings.volumeHandler.getGlobalBounds().contains(nall.event.mouseButton.x, nall.event.mouseButton.y)) {
                        nall.settings.isDragging = true;
                    }
                }
                if (nall.event.type == sf::Event::MouseButtonReleased && nall.event.mouseButton.button == sf::Mouse::Left) {
                    nall.settings.isDragging = false;
                }
                if (nall.event.type == sf::Event::MouseMoved) {
                    if (nall.settings.isDragging) {
                        float mouseX = nall.event.mouseMove.x;
                        float buttonWidth = nall.settings.volumeHandler.getSize().x;
                        float newPosition = mouseX - buttonWidth / 2;
                        if (newPosition < nall.settings.buttonLeftLimit) {
                            newPosition = nall.settings.buttonLeftLimit;
                        }
                        if (newPosition > nall.settings.buttonRightLimit - buttonWidth) {
                            newPosition = nall.settings.buttonRightLimit - buttonWidth;
                        }
                        nall.settings.volumeHandler.setPosition(newPosition, nall.settings.volumeHandler.getPosition().y);
                    }
                }
            }
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
    // music.stop();

    return 0;
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
