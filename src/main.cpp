#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include "game_map.h"
#include "config.h"
#include "button.h"


int main() {
    sf::RenderWindow window(sf::VideoMode(kWindowWidthInPixels, kWindowHeightInPixels), kWIndowTitle);
    window.setVerticalSyncEnabled(true);
    window.setKeyRepeatEnabled(false);

    std::unique_ptr<GameMap> game_map = std::make_unique<GameMap>(kMapWidthInTiles, kMapHeightInTiles,
                                      kMapFillPercentage, kTileWidthInPixels,
                                      kTileHeightInPixels, window);

    sf::Font font;
    if (!font.loadFromFile("resources/fonts/ubuntu.ttf")) {
        std::cout << "Error. Font failed to load." << std::endl;
    }

    sf::RectangleShape controls_rect_shape;
    controls_rect_shape.setSize(sf::Vector2f(125, 100));
    controls_rect_shape.setPosition(sf::Vector2f(150, 10));
    controls_rect_shape.setFillColor(sf::Color(255, 255, 255));

    sf::Text keyboard_controls_text;
    keyboard_controls_text.setFont(font);
    keyboard_controls_text.setCharacterSize(25);
    keyboard_controls_text.setColor(sf::Color(0, 0, 0));
    std::string keyboard_controls_string = "Keyboard controls: \n\nG - generate new population\nS - start simulation";
    keyboard_controls_text.setString(keyboard_controls_string);
    auto keyboard_controls_text_rect = keyboard_controls_text.getGlobalBounds();
    keyboard_controls_text.setOrigin(sf::Vector2f(keyboard_controls_text_rect.width / 2,
                                                keyboard_controls_text_rect.height / 2));
    keyboard_controls_text.setPosition(controls_rect_shape.getPosition() +
                                     sf::Vector2f(controls_rect_shape.getSize().x / 2,
                                                  controls_rect_shape.getSize().y / 2));

    

    std::unique_ptr<Button> generate_button = std::make_unique<Button>(
                                         kButtonSize,
                                         kGenerateButtonPosition,
                                         kButtonColor,
                                         kButtonOutlineThickness,
                                         kButtonOutlineColor,
                                         font,
                                         kGenerateButtonString,
                                         kButtonCharacterSize,
                                         kButtonTextColor);

    std::unique_ptr<Button> simulate_button = std::make_unique<Button>(
                                         kButtonSize,
                                         kSimulateButtonPosition,
                                         kButtonColor,
                                         kButtonOutlineThickness,
                                         kButtonOutlineColor,
                                         font,
                                         kSimulateButtonString,
                                         kButtonCharacterSize,
                                         kButtonTextColor);

    sf::Text mouse_controls_text;
    mouse_controls_text.setFont(font);
    mouse_controls_text.setCharacterSize(25);
    mouse_controls_text.setColor(sf::Color(0, 0, 0));
    std::string mouse_controls_string = "Mouse controls:";
    mouse_controls_text.setString(mouse_controls_string);
    mouse_controls_text.setPosition(kGenerateButtonPosition + sf::Vector2f(0, -kButtonHeight));


    sf::Clock clock;
    sf::Clock clock_pressed;
    int dt = kTurnDelayInMicroseconds;//to draw the map right after the start
    int generate_button_pressed_delay = kGenerateButtonPressedDelay;
    int simulate_button_pressed_delay = kGenerateButtonPressedDelay;
    bool start_simulation = false;


    while (window.isOpen()) {
        sf::Event e;
        while (window.pollEvent(e)) {
            if (e.type == sf::Event::Closed) {
                window.close();
            }
            if (e.type == sf::Event::KeyPressed) {
                if (e.key.code == sf::Keyboard::Escape) {
                    window.close();
                }
            }
            if (e.type == sf::Event::KeyPressed) {
                if (e.key.code == sf::Keyboard::S) {
                    start_simulation = true;
                }
            }
            if (e.type == sf::Event::KeyPressed) {
                if (e.key.code == sf::Keyboard::G) {
                    game_map->Reset();
                    game_map->RandomizeMap(kMapFillPercentage);
                    start_simulation = false;
                }
            }
            if (e.type == sf::Event::MouseButtonPressed) {
                if (e.mouseButton.button == sf::Mouse::Left) {
                    auto mouse_pos = sf::Mouse::getPosition(window);
                    if (generate_button->RectShape().getGlobalBounds().contains(mouse_pos.x, mouse_pos.y)) {
                        game_map->Reset();
                        game_map->RandomizeMap(kMapFillPercentage);
                        start_simulation = false;
                        generate_button_pressed_delay = 0;
                    } else if (simulate_button->RectShape().getGlobalBounds().contains(mouse_pos.x, mouse_pos.y)) {                        
                        start_simulation = true;
                        simulate_button_pressed_delay = 0;
                    }
                }
            }
        }

        if (generate_button_pressed_delay < kGenerateButtonPressedDelay) {
            generate_button_pressed_delay += clock_pressed.getElapsedTime().asMicroseconds();
            generate_button->RectShape().setFillColor(sf::Color::Yellow);
            generate_button->ButtonText().setStyle(sf::Text::Bold);
        } else {
            generate_button->RectShape().setFillColor(kGenerateButtonDefaultColor);
            generate_button->ButtonText().setStyle(sf::Text::Regular);
        }

        if (simulate_button_pressed_delay < kGenerateButtonPressedDelay) {
            simulate_button_pressed_delay += clock_pressed.getElapsedTime().asMicroseconds();
            simulate_button->RectShape().setFillColor(sf::Color::Yellow);
            simulate_button->ButtonText().setStyle(sf::Text::Bold);
        } else {
            simulate_button->RectShape().setFillColor(kGenerateButtonDefaultColor);
            simulate_button->ButtonText().setStyle(sf::Text::Regular);
        }

        if (start_simulation) {
            dt += clock.getElapsedTime().asMicroseconds();
            clock.restart();
            if (dt < kTurnDelayInMicroseconds) {
                continue;
            }
            dt = 0;
            game_map->UpdateMap();
        }
        window.clear(sf::Color(255, 255, 255));
        game_map->DrawMap(window, kOffsetX, kOffsetY);
        window.draw(keyboard_controls_text);
        window.draw(mouse_controls_text);
        window.draw(generate_button->RectShape());
        window.draw(generate_button->ButtonText());
        window.draw(simulate_button->RectShape());
        window.draw(simulate_button->ButtonText());
        window.display();
    }
    return 0;
}
