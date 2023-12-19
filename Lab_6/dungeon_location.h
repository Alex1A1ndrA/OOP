#pragma once

#include <set>
#include <iostream>
#include <memory>
#include "npc.h"

// Класс локации подземелья
class DungeonLocation {
public:
    DungeonLocation();

    void addNPC(std::shared_ptr<NPC> npc);
    void saveToFile(const std::string& filename) const;
    void loadFromFile(const std::string& filename);
    void printObjects() const;
    void startBattleMode(size_t distance) const;

    // Добавляем метод для получения NPCs
    const std::set<std::shared_ptr<NPC>>& getNPCs() const;

private:
    mutable std::set<std::shared_ptr<NPC>> npcs;
    std::vector<std::shared_ptr<IFightObserver>> observers;
};