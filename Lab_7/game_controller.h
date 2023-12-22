#pragma once

#include "dungeon_location.h"
#include <thread>
#include <mutex>

class GameController {
public:
    GameController();
    ~GameController();

    void initializeGame();
    void stopGame();

private:
    DungeonLocation dungeon;
    std::thread moveNpcThread;
    std::thread battleThread;
    std::mutex mutex;

    void moveNpcsTask();
    void battleTask();
};