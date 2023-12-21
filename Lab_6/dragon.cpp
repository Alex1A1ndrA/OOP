#include "dragon.h"
#include "knight.h"
#include "elf.h"

Dragon::Dragon(int x, int y, const std::string& name)
    : NPC(DragonType, x, y, name) {}

Dragon::Dragon(std::istream& is)
    : NPC(DragonType, is) {}

void Dragon::print() const {
    std::cout << "Дракон: " << *this << std::endl;
}

bool Dragon::fight(std::shared_ptr<Dragon> other) {
    std::cout << "Dragon vs. Dragon battle" << std::endl;
    fightNotify(other, true);
    return true;  // Дракон всегда побеждает других драконов
}

bool Dragon::fight(std::shared_ptr<class Knight> other) {
    std::cout << "Dragon vs. Knight battle" << std::endl;
    fightNotify(other, true);
    return true;  // Дракон побеждает рыцарей
}

bool Dragon::fight(std::shared_ptr<class Elf> other) {
    fightNotify(other, true);
    return true;  // Дракон побеждает эльфов
}

void Dragon::save(std::ostream& os) const {
    os << DragonType << " ";
    NPC::save(os);
}

std::ostream& operator<<(std::ostream& os, const Dragon& dragon) {
    os << "Дракон: " << *static_cast<const NPC*>(&dragon);
    return os;
}
