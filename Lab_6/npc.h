#pragma once

#include <iostream>
#include <fstream>
#include <set>
#include <cmath>
#include <memory>
#include <vector>
#include <string>

// Перечисление для типов NPC
enum NpcType {
    Unknown = 0,
    DragonType = 1,
    KnightType = 2,
    ElfType = 3
};

class NPC;

// Интерфейс для наблюдателя за боем
class IFightObserver {
public:
    virtual ~IFightObserver() = default;
    virtual void onFight(const std::shared_ptr<NPC>& attacker, const std::shared_ptr<NPC>& defender, bool win) = 0;
};

// Базовый класс NPC
class NPC : public std::enable_shared_from_this<NPC> {
public:
    NPC(NpcType t, int _x, int _y, const std::string& _name);
    NPC(NpcType t, std::istream& is);

    virtual ~NPC() = default;

    void subscribe(std::shared_ptr<IFightObserver> observer);
    void fightNotify(const std::shared_ptr<NPC>& defender, bool win);
    void clearObservers();
    virtual bool isClose(const std::shared_ptr<NPC>& other, size_t distance) const;
    
    virtual bool isDragon() const;
    virtual bool isKnight() const;
    virtual bool isElf() const;

    virtual bool fight(std::shared_ptr<class Dragon> other) = 0;
    virtual bool fight(std::shared_ptr<class Knight> other) = 0;
    virtual bool fight(std::shared_ptr<class Elf> other) = 0;
    
    virtual void print() const = 0;
    virtual void save(std::ostream& os) const;

    friend std::ostream& operator<<(std::ostream& os, const NPC& npc);
    static std::shared_ptr<NPC> factory(std::istream& is);

    // Виртуальный метод для получения имени NPC
    virtual std::string getName() const = 0;

protected:
    NpcType type;
    int x{ 0 };
    int y{ 0 };
    std::string name;
    std::vector<std::shared_ptr<IFightObserver>> observers;
};

// Наблюдатель за боем, записывающий в файл
class FileObserver : public IFightObserver {
public:
    FileObserver(const std::string& filename);
    void onFight(const std::shared_ptr<NPC>& attacker, const std::shared_ptr<NPC>& defender, bool win) override;

private:
    std::ofstream logfile;
};

// Боевой наблюдатель, записывающий в консоль
class BattleObserver : public IFightObserver {
private:
    static BattleObserver *_instance;
public:
    static BattleObserver *get_instance()
    {
        // double null check для 7 лабы
        if (_instance == nullptr)
        {
            _instance = new BattleObserver();
        }
        return _instance;
    }
private:
    BattleObserver() = default;
public:
    void onFight(const std::shared_ptr<NPC>& attacker, const std::shared_ptr<NPC>& defender, bool win) override;
};