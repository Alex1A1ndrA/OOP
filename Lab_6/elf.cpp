#include "elf.h"
#include "dragon.h"
#include "knight.h"

Elf::Elf(int x, int y, const std::string& name)
    : NPC(ElfType, x, y, name) {}

Elf::Elf(std::istream& is)
    : NPC(ElfType, is) {}

void Elf::print() const {
    std::cout << "Эльф: " << *this << std::endl;
}

bool Elf::fight(std::shared_ptr<class Dragon> other) {
    fightNotify(other, false);
    return false;  // Эльф проигрывает драконам
}

bool Elf::fight(std::shared_ptr<class Knight> other) {
    fightNotify(other, false);
    return false;  // Эльф проигрывает рыцарям
}

bool Elf::fight(std::shared_ptr<Elf> other) {
    fightNotify(other, false);
    return false;  // Эльфы не могут победить друг друга
}

void Elf::save(std::ostream& os) const {
    os << ElfType << " ";
    NPC::save(os);
}

std::ostream& operator<<(std::ostream& os, const Elf& elf) {
    os << "Эльф: " << *static_cast<const NPC*>(&elf);
    return os;
}
