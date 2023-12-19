#include "knight.h"
#include "dragon.h"
#include "elf.h"

Knight::Knight(int x, int y, const std::string& name)
    : NPC(KnightType, x, y, name) {}

Knight::Knight(std::istream& is)
    : NPC(KnightType, is) {}

void Knight::print() const {
    std::cout << "Рыцарь: " << *this << std::endl;
}

bool Knight::fight(std::shared_ptr<class Dragon> other) {
    fightNotify(other, false);
    return false;  // Рыцарь проигрывает драконам
}

bool Knight::fight(std::shared_ptr<Knight> other) {
    fightNotify(other, false);
    return false;  // Рыцари не могут победить друг друга
}

bool Knight::fight(std::shared_ptr<class Elf> other) {
    fightNotify(other, false);
    return false;  // Рыцарь проигрывает эльфам
}

void Knight::save(std::ostream& os) const {
    os << KnightType << " ";
    NPC::save(os);
}

std::ostream& operator<<(std::ostream& os, const Knight& knight) {
    os << "Рыцарь: " << *static_cast<const NPC*>(&knight);
    return os;
}