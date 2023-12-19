#pragma once

#include "npc.h"

// Класс рыцаря
class Knight : public NPC {
public:
    Knight(int x, int y, const std::string& name);
    Knight(std::istream& is);

    void print() const override;

    bool fight(std::shared_ptr<class Dragon> other) override;
    bool fight(std::shared_ptr<Knight> other) override;
    bool fight(std::shared_ptr<class Elf> other) override;

    void save(std::ostream& os) const override;

    friend std::ostream& operator<<(std::ostream& os, const Knight& knight);
};