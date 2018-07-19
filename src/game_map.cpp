#include "game_map.h"
#include "rng.h"
#include "config.h"
#include "node.h"
#include <vector>
#include <iostream>


GameMap::GameMap(int width, int height, int map_fill_percentage,
                   int tile_width_in_pixels, int tile_height_in_pixels,
                   sf::RenderWindow& window):
                    width_(width), height_(height),
                    map_fill_percentage_(map_fill_percentage),
                    tile_width_in_pixels_(tile_width_in_pixels),
                    tile_height_in_pixels_(tile_height_in_pixels) {

    char_map_ = std::vector<std::vector<Node> >(height, std::vector<Node>(width));
    RandomizeMap(kMapFillPercentage);
}


void GameMap::Reset() {
    char_map_ = std::vector<std::vector<Node> >(Width(), std::vector<Node>(Height()));
}

void GameMap::PrintMapToConsole() {
    std::cout << "PrintMapToConsole()" << std::endl;
    std::cout << std::endl;
    for (size_t i = 0; i < char_map_.size(); ++i) {
        std::cout << " ";
        for (size_t j = 0; j < char_map_[0].size(); ++j) {
            std::cout << char_map_[i][j].data_;
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}


void GameMap::RandomizeMap(int map_fill_percent) {
    for (int i = char_map_.size() * kAlpha; i < char_map_.size() * (1 - kAlpha); ++i) {
        for (int j = char_map_[0].size() * kAlpha; j < char_map_[0].size() * (1 - kAlpha); ++j) {
            int rand_int = Rng::IntInRange(0, 100);
            if (rand_int < map_fill_percent) {
                char_map_[i][j].data_ = '1';
                char_map_[i][j].visited_ = true;
            } else {
                char_map_[i][j].data_ = '0';
            }
        }
    }
}


bool GameMap::IsValidCell(int i, int j) {
    return (i >= 0) && (i < Height()) && (j >= 0) && (j < Width());
}


int GameMap::CountNeighborWalls(int i, int j) {
    int cnt = 0;
    for (int dx = -1; dx < 2; ++dx) {
        for (int dy = -1; dy < 2; ++dy) {
            if ((dx == 0) && (dy == 0)) {
                continue;
            }
            if (IsValidCell(i + dy, j + dx) && (char_map_[i + dy][j + dx].data_ == '1')) {
                ++cnt;
            }
        }
    }
    return cnt;
}


void GameMap::UpdateMap() {
    std::vector<std::vector<Node> > map_copy = char_map_;
    for (int row = 0; row < Height(); ++row) {
        for (int col = 0; col < Width(); ++col) {
            Node curr = char_map_[row][col];
            int cnt = CountNeighborWalls(row, col);
            if (curr.data_ == '0') {//if the cell is dead
                if (std::find(begin(kBirthValues), end(kBirthValues), cnt) != end(kBirthValues)) {
                    map_copy[row][col].data_ = '1';
                    char_map_[row][col].visited_ = true;
                }
            } else {//if the cell is alive
                if (std::find(begin(kSurviveValues), end(kSurviveValues), cnt) == end(kSurviveValues)) {
                    map_copy[row][col].data_ = '0';
                }
            }
        }
    }
    for (int row = 0; row < Height(); ++row) {
        for (int col = 0; col < Width(); ++col) {
            char_map_[row][col].data_ = map_copy[row][col].data_;
        }
    }
}


void GameMap::DrawMap(sf::RenderWindow& window, double offset_x, double offset_y) {
    for (int row = 0; row < Height(); ++row) {
        for (int col = 0; col < Width(); ++col) {
            Node curr = char_map_[row][col];
            sf::RectangleShape rect;
            rect.setSize(sf::Vector2f(tile_width_in_pixels_, tile_height_in_pixels_));
            rect.setPosition(sf::Vector2f(offset_x + col * tile_width_in_pixels_, offset_y + row * tile_height_in_pixels_));
            if (curr.data_ == '1') {
                rect.setFillColor(sf::Color::Black);
            } else {
                if (curr.visited_) {
                    rect.setFillColor(kExploredSquareColor);
                } else {
                    rect.setFillColor(sf::Color::White);
                }
            }
            window.draw(rect);
        }
    }
}


int GameMap::Height() const {
    return height_;
}


int GameMap::Width() const {
    return width_;
}
