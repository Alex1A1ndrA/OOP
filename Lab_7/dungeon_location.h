#pragma once

#include <set>
#include <iostream>
#include <memory>
#include <mutex>  // Добавим заголовок для std::mutex
#include "npc.h"

// Класс локации подземелья
class DungeonLocation {
public:
    DungeonLocation();

    void addNPC(std::shared_ptr<NPC> npc);
    void saveToFile(const std::string& filename) const;
    void loadFromFile(const std::string& filename);
    void printObjects() const;
    // Метод запуска боевого режима
    void startBattleMode(size_t distance) const {
        // Реализация метода
        // Например, вы можете использовать ваш существующий код
        startBattleModeAsync(distance);
    }

    void moveNPCs();

    // Добавляем метод для получения NPCs
    const std::set<std::shared_ptr<NPC>>& getNPCs() const;

    // Добавим метод для добавления случайных NPC
    void addRandomNPCs(int count);

    // Метод запуска боевого режима асинхронно
    void startBattleModeAsync(size_t distance) const;

private:
    mutable std::set<std::shared_ptr<NPC>> npcs;
    mutable std::mutex npcsMutex;  // Добавим мьютекс для безопасного доступа к npcs
    std::vector<std::shared_ptr<IFightObserver>> observers;
};