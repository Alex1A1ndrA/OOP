#include "dungeon_location.h"
#include "npc.h"
#include "dragon.h"
#include "knight.h"
#include "elf.h"
#include "game_controller.h"

int main() {
    // Создаем контроллер игры
    GameController gameController;

    // Инициализируем и запускаем игру
    gameController.initializeGame();

    // Даем время для выполнения задач в других потоках
    std::this_thread::sleep_for(std::chrono::seconds(30));

    // Останавливаем игру и выводим список выживших
    gameController.stopGame();

    return 0;
}