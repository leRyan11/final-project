#ifndef GAME_MAP_H
#define GAME_MAP_H

#include <string>

class GameMap {
private:
    std::string stationName;
    int width;
    int height;

public:
    GameMap();
    GameMap(const std::string& name, int mapWidth, int mapHeight);

    std::string getStationName() const;
    int getWidth() const;
    int getHeight() const;
};

#endif
