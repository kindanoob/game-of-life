#ifndef GAME_MAP_H_
#define GAME_MAP_H_

#include "node.h"
#include <vector>
#include <SFML/Graphics.hpp>

class GameMap {
public:
    std::vector<std::vector<Node> > char_map_;
    int width_ = 0;
    int height_ = 0;
    int map_fill_percentage_ = 0;
    int tile_width_in_pixels_ = 0;
    int tile_height_in_pixels_ = 0;

    GameMap(int width, int height, int map_fill_percentage,
             int tile_width_in_pixels, int tile_height_in_pixels,
             sf::RenderWindow& window);
    void Reset();
    void UpdateMap();
    void RandomizeMap(int map_fill_percent);
    void PrintMapToConsole();
    int CountNeighborWalls(int row, int col);
    bool IsValidCell(int row, int col);
    void DrawMap(sf::RenderWindow& window, double offset_x, double offset_y);
    int Width() const;
    int Height() const;
};


#endif //GAME_MAP_H_
