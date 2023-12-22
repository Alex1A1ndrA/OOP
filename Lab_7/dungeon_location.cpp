#include "dungeon_location.h"
#include <iostream>
#include <fstream>  // Добавим для ifstream
#include <memory> 
#include <future>
#include <vector>
#include <functional>
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

// Метод добавления случайных NPC в локацию
void DungeonLocation::addRandomNPCs(int count) {
    // Генерация и добавление случайных NPC в локацию
    for (int i = 0; i < count; ++i) {
        // Генерируем случайный тип NPC (Dragon, Knight, Elf)
        NpcType randomType = static_cast<NpcType>(1 + rand() % 3);

        // Генерируем случайные координаты
        int randomX = rand() % 100;
        int randomY = rand() % 100;

        // Генерируем случайное имя
        std::string randomName = "RandomNPC" + std::to_string(i);

        // Создаем и добавляем NPC в локацию
        std::shared_ptr<NPC> randomNPC;
        switch (randomType) {
            case DragonType:
                randomNPC = std::make_shared<Dragon>(randomX, randomY, randomName);
                break;
            case KnightType:
                randomNPC = std::make_shared<Knight>(randomX, randomY, randomName);
                break;
            case ElfType:
                randomNPC = std::make_shared<Elf>(randomX, randomY, randomName);
                break;
            default:
                // В случае неизвестного типа NPC, ничего не добавляем
                continue;
        }

        // Добавляем случайного NPC в локацию
        addNPC(randomNPC);
    }
}

void DungeonLocation::moveNPCs() {
    for (auto& npc : npcs) {
        // Имитация перемещения NPC
        npc->move();
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
void DungeonLocation::startBattleModeAsync(size_t distance) const {
    std::vector<std::future<void>> futures;

    for (auto it = npcs.begin(); it != npcs.end(); ++it) {
        if (*it) {
            auto attacker = *it;
            auto defenderIt = std::next(it);

            while (defenderIt != npcs.end()) {
                auto defender = *defenderIt;

                futures.emplace_back(std::async(std::launch::async, std::bind([this, attacker, defender, distance](auto it) {
                    if (attacker && defender) {
                        bool success = attacker->isClose(defender, distance);

                        if (success) {
                            std::cout << " (Успешно)" << std::endl;
                            std::lock_guard<std::mutex> lock(npcsMutex);
                            it = npcs.erase(it);
                        } else {
                            std::cout << " (Неудачно)" << std::endl;
                            ++it;
                        }
                    } else {
                        // Handle the case where either attacker or defender is null
                        ++it;
                    }
                }, defenderIt)));
                ++defenderIt;
            }
        }
    }

    for (auto& future : futures) {
        future.get();
    }
}


// Метод получения списка NPC в локации
const std::set<std::shared_ptr<NPC>>& DungeonLocation::getNPCs() const {
    return npcs;
}
