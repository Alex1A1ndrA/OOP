#include "game_controller.h"

GameController::GameController() {}

GameController::~GameController() {
    if (moveNpcThread.joinable())
        moveNpcThread.join();
    if (battleThread.joinable())
        battleThread.join();
}

void GameController::initializeGame() {
    // Создаем локацию подземелья
    dungeon.addRandomNPCs(50);  // Добавляем 50 случайных NPC

    // Запускаем поток для перемещения NPC
    moveNpcThread = std::thread(&GameController::moveNpcsTask, this);

    // Запускаем поток для боевого режима
    battleThread = std::thread(&GameController::battleTask, this);
}

void GameController::stopGame() {
    // Останавливаем потоки и выводим список выживших
    moveNpcThread.join();
    battleThread.join();

    dungeon.printObjects();
}

void GameController::moveNpcsTask() {
    while (true) {
        // Имитация передвижения NPC
        std::unique_lock<std::mutex> lock(mutex);
        dungeon.moveNPCs();
        lock.unlock();

        // Пауза перед следующим перемещением
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

void GameController::battleTask() {
    while (true) {
        // Имитация боевого режима
        std::unique_lock<std::mutex> lock(mutex);
        dungeon.startBattleModeAsync(30);
        lock.unlock();

        // Пауза перед следующим боевым режимом
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}