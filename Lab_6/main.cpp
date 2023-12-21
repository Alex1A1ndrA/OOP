#include "dungeon_location.h"
#include "npc.h"
#include "dragon.h"
#include "knight.h"
#include "elf.h"

int main() {
    // Создаем локацию подземелья
    DungeonLocation dungeon;

    // Создаем персонажей: дракона, рыцаря и эльфа
    auto dragon = std::make_shared<Dragon>(10, 20, "FireDrake");
    auto knight = std::make_shared<Knight>(30, 40, "SirLancelot");
    auto elf = std::make_shared<Elf>(50, 60, "Legolas");

    // Добавляем персонажей в локацию
    dungeon.addNPC(dragon);
    dungeon.addNPC(knight);
    dungeon.addNPC(elf);

    // Выводим информацию о персонажах в локации
    dungeon.printObjects();

    // Запускаем боевой режим с различными дистанциями
    for (size_t distance = 20; (distance <= 100) && !dungeon.getNPCs().empty(); distance += 10) {
        dungeon.startBattleMode(distance);
        std::cout << "Боевой режим на расстоянии: " << distance << std::endl;
        dungeon.printObjects();
    }

    // Сохраняем состояние локации в файл
    dungeon.saveToFile("savefile.txt");

    return 0;
}