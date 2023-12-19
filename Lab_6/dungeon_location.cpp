#include "dungeon_location.h"
#include <iostream>
#include <fstream>  // Добавим для ifstream
#include <memory> 
#include "npc.h" 
#include "dragon.h"
#include "knight.h"
#include "elf.h"

// Конструктор по умолчанию
DungeonLocation::DungeonLocation() {}

// Метод добавления NPC в локацию
void DungeonLocation::addNPC(std::shared_ptr<NPC> npc) {
    npcs.insert(npc);
}

// Метод сохранения локации в файл
void DungeonLocation::saveToFile(const std::string& filename) const {
    // Открываем файл для записи
    std::ofstream fs(filename);
    if (fs.is_open()) {
        // Записываем количество NPC в локации
        fs << npcs.size() << std::endl;
        // Записываем каждого NPC в файл
        for (const auto& npc : npcs) {
            npc->save(fs);
        }
        // Закрываем файл
        fs.close();
    } else {
        // Если файл не удалось открыть, выводим сообщение об ошибке
        std::cerr << "Ошибка: Не удалось открыть файл для записи: " << filename << std::endl;
    }
}

// Метод загрузки локации из файла
void DungeonLocation::loadFromFile(const std::string& filename) {
    // Открываем файл для чтения
    std::ifstream fs(filename);
    if (fs.is_open()) {
        // Очищаем текущий список NPC
        npcs.clear();
        // Считываем количество NPC из файла
        int count;
        fs >> count;
        // Создаем и добавляем NPC в локацию
        for (int i = 0; i < count; ++i) {
            auto npc = NPC::factory(fs);
            addNPC(npc);
        }
        // Закрываем файл
        fs.close();
    } else {
        // Если файл не удалось открыть, выводим сообщение об ошибке
        std::cerr << "Ошибка: Не удалось открыть файл для чтения: " << filename << std::endl;
    }
}

// Метод вывода информации о NPC в локации
void DungeonLocation::printObjects() const {
    // Выводим информацию о каждом NPC в локации
    for (const auto& npc : npcs) {
        npc->print();
    }
}

// Метод запуска боевого режима
void DungeonLocation::startBattleMode(size_t distance) const {
    auto it = npcs.begin();
    while (it != npcs.end()) {
        auto attacker = *it;
        auto defenderIt = it;
        ++defenderIt;

        while (defenderIt != npcs.end()) {
            auto defender = *defenderIt;

            if (attacker->isClose(defender, distance)) {
                bool success = false;
                // Определяем тип защитника и запускаем бой
                if (defender->isDragon()) {
                    success = attacker->fight(std::static_pointer_cast<Dragon>(std::dynamic_pointer_cast<NPC>(defender)));
                } else if (defender->isKnight()) {
                    success = attacker->fight(std::static_pointer_cast<Knight>(std::dynamic_pointer_cast<NPC>(defender)));
                } else if (defender->isElf()) {
                    success = attacker->fight(std::static_pointer_cast<Elf>(std::dynamic_pointer_cast<NPC>(defender)));
                }

                // Если бой успешен, удаляем защитника из локации
                if (success) {
                    it = npcs.erase(defenderIt++);
                } else {
                    ++defenderIt;
                }
            } else {
                ++defenderIt;
            }
        }

        ++it;
    }
}

// Метод получения списка NPC в локации
const std::set<std::shared_ptr<NPC>>& DungeonLocation::getNPCs() const {
    return npcs;
}
