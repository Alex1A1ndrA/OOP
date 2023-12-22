#pragma once

#include "npc.h"

// Класс эльфа
class Elf : public NPC {
public:
    static constexpr size_t MovementDistance = 10;
    static constexpr size_t KillingDistance = 50;

    Elf(int x, int y, const std::string& name);
    Elf(std::istream& is);

    void print() const override;

    bool fight(std::shared_ptr<class Dragon> other) override;
    bool fight(std::shared_ptr<class Knight> other) override;
    bool fight(std::shared_ptr<Elf> other) override;

    void save(std::ostream& os) const override;

    friend std::ostream& operator<<(std::ostream& os, const Elf& elf);

    // Реализация виртуального метода из базового класса NPC
    std::string getName() const override {
        return name;
    }

    size_t getMovementDistance() const override {
        return MovementDistance;
    }

    size_t getKillingDistance() const override {
        return KillingDistance;
    }
};