#include "npc.h"
#include "dragon.h"
#include "knight.h"
#include "elf.h"

BattleObserver *BattleObserver::_instance = nullptr;

std::shared_ptr<NPC> NPC::factory(std::istream& is) {
    int type;
    is >> type;
    switch (static_cast<NpcType>(type)) {
        case DragonType:
            return std::make_shared<Dragon>(is);
        case KnightType:
            return std::make_shared<Knight>(is);
        case ElfType:
            return std::make_shared<Elf>(is);
        default:
            return nullptr;
    }
}

NPC::NPC(NpcType t, int _x, int _y, const std::string& _name)
    : type(t), x(_x), y(_y), name(_name) {}

NPC::NPC(NpcType t, std::istream& is)
    : type(t) {
    is >> x;
    is >> y;
    is >> name;
}

void NPC::move() {
    // Имитация перемещения
    x += rand() % 5 - 2;  // Случайное изменение координаты x
    y += rand() % 5 - 2;  // Случайное изменение координаты y
}

void NPC::subscribe(std::shared_ptr<IFightObserver> observer) {
    observers.push_back(observer);
}

void NPC::fightNotify(const std::shared_ptr<NPC>& defender, bool win) {
    for (auto& o : observers)
        o->onFight(shared_from_this(), defender, win);
}

bool NPC::isClose(const std::shared_ptr<NPC>& other, size_t distance) const {
    return std::pow(x - other->x, 2) + std::pow(y - other->y, 2) <= std::pow(distance, 2);
}

bool NPC::isDragon() const {
    return false;
}

bool NPC::isKnight() const {
    return false;
}

bool NPC::isElf() const {
    return false;
}

void NPC::save(std::ostream& os) const {
    os << x << " " << y << " " << name << std::endl;
}

std::ostream& operator<<(std::ostream& os, const NPC& npc) {
    os << "{ x:" << npc.x << ", y:" << npc.y << ", name:" << npc.name << "} ";
    return os;
}

FileObserver::FileObserver(const std::string& filename) {
    logfile.open(filename);
}

void FileObserver::onFight(const std::shared_ptr<NPC>& attacker, const std::shared_ptr<NPC>& defender, bool win) {
    if (win) {
        logfile << "Убийство --------" << std::endl;
        logfile << *attacker;
        logfile << *defender;
    }
}

// Определение метода clearObservers
void NPC::clearObservers() {
    observers.clear();
}