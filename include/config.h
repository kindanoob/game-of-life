#ifndef CONFIG_H_
#define CONFIG_H_

#include <string>
#include <vector>


const int kWindowWidthInPixels = 1200;
const int kWindowHeightInPixels = 800;



const std::string kWIndowTitle = "Game of life";

const int kMapWidthInTiles = 200;
const int kMapHeightInTiles = 200;
const int kMapWidthInPixels = kWindowHeightInPixels;
const int kMapHeightInPixels = kWindowHeightInPixels;
const int kTileWidthInPixels = kMapWidthInPixels / kMapWidthInTiles;
const int kTileHeightInPixels = kMapHeightInPixels / kMapHeightInTiles;
const int kOffsetX = 1 * (kWindowWidthInPixels - kMapWidthInPixels) / 2;
const int kOffsetY = 1 * (kWindowHeightInPixels - kMapHeightInPixels) / 2;
const int kMapFillPercentage = 50;
const int kTurnDelayInMicroseconds = 100000;
const int kGenerateButtonPressedDelay = 300000;//in microseconds

const sf::Color kExploredSquareColor = sf::Color(155, 255, 155);
const sf::Color kGenerateButtonDefaultColor = sf::Color(200, 200, 200);


//buttons
const int kButtonWidth = 120;
const int kButtonHeight = 50;
const sf::Vector2f kButtonSize = sf::Vector2f(kButtonWidth, kButtonHeight);
const int kButtonCharacterSize = 25;
const sf::Color kButtonTextColor = sf::Color(0, 0, 0);
const sf::Color kButtonColor = sf::Color(200, 200, 200);
const int kButtonOutlineThickness = 3;
const sf::Color kButtonOutlineColor = sf::Color(0, 0, 0);


const int kGenerateButtonPositionX = 50;
const int kGenerateButtonPositionY = 600;
const sf::Vector2f kGenerateButtonPosition = sf::Vector2f(kGenerateButtonPositionX, kGenerateButtonPositionY);
const std::string kGenerateButtonString = "generate";

const int kSimulateButtonPositionX = 50;
const int kSimulateButtonPositionY = 600 + kButtonOutlineThickness + kButtonHeight;
const sf::Vector2f kSimulateButtonPosition = sf::Vector2f(kSimulateButtonPositionX, kSimulateButtonPositionY);
const std::string kSimulateButtonString = "simulate";




const double kAlpha = 0.46;// determines the initial spawn region, the closer it is to zero the larger the region is

const std::vector<int> kBirthValues = {3};// if dead cell has number of neighbors that
                                          // belongs to this set of values, it becomes alive, o/w it stays dead

const std::vector<int> kSurviveValues = {2,3};// if alive cell has number of neighbors that
                                              // belongs to this set, it stays alive, o/w it becomes dead


///Examples of cellular automata:
//---B3/S23 - Conway's Game of Life
//---B23/S36 - HighLife

//---https://en.wikipedia.org/wiki/Life-like_cellular_automaton
//---B5678/S45678 - default
//---B5678/S345678 - 25...55
//---B5678/S2345678 - 15...55
//---B5678/S12345678 - 10...40
//---B678/S12345678 - 10...80
//---B78/S12345678 - 40
//---B678/S35678 - 60, 65, 70, 75, 80
//---B35678/S35678 - 10, 15, 20,25
//---B35678/S235678 - 1...10
//---B5678/S25678 - 65, 70
//---B678/S2567
//---B4678/S35678 - Anneal - 45...55
//---B35678/S5678 - Diamoeba - 40...45
//---B3678/S34678 - Day & Night 20...40

//---B368/S245 - Morley
//---B36/S125 - 2x2
//---B/S1
//---B/S12
//---B/S14
//---B/S23
//---B/S24
//---B123/S
//---B13/S

#endif // CONFIG_H_
