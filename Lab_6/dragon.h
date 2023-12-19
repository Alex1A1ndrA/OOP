#pragma once

#include "npc.h"

// Класс дракона
class Dragon : public NPC {
public:
    Dragon(int x, int y, const std::string& name);
    Dragon(std::istream& is);

    void print() const override;

    bool fight(std::shared_ptr<Dragon> other) override;
    bool fight(std::shared_ptr<class Knight> other) override;
    bool fight(std::shared_ptr<class Elf> other) override;

    void save(std::ostream& os) const override;

    friend std::ostream& operator<<(std::ostream& os, const Dragon& dragon);
};