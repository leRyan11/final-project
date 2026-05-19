#include "GameMap.h"

GameMap::GameMap() {
    stationName = "Embarcadero";
    width = 10;
    height = 10;
}

GameMap::GameMap(const std::string& name, int mapWidth, int mapHeight) {
    stationName = name;
    width = mapWidth;
    height = mapHeight;
}

std::string GameMap::getStationName() const {
    return stationName;
}

int GameMap::getWidth() const {
    return width;
}

int GameMap::getHeight() const {
    return height;
}
