#include <gtest/gtest.h>
#include "dungeon_location.h"
#include "npc.h"
#include "dragon.h"
#include "knight.h"
#include "elf.h"

TEST(DungeonLocationTest, AddNPC) {
    DungeonLocation dungeon;
    auto dragon = std::make_shared<Dragon>(10, 20, "FireDrake");
    dungeon.addNPC(dragon);
    
    // Проверяем, что NPC был успешно добавлен в локацию
    EXPECT_EQ(dungeon.getNPCs().size(), 1);

    // Проверяем, что добавленный NPC совпадает с созданным
    auto firstNPC = *(dungeon.getNPCs().begin());
    EXPECT_EQ(firstNPC, dragon);
}

TEST(DungeonLocationTest, StartBattleMode) {
    DungeonLocation dungeon;
    auto dragon = std::make_shared<Dragon>(10, 20, "FireDrake");
    auto knight = std::make_shared<Knight>(30, 40, "SirLancelot");
    dungeon.addNPC(dragon);
    dungeon.addNPC(knight);

    // Сохраняем изначальное количество NPC
    size_t initialNPCCount = dungeon.getNPCs().size();

    dungeon.startBattleMode(30);

    auto remainingNPCs = dungeon.getNPCs();
    std::cout << "Remaining NPCs:" << std::endl;
    for (const auto& npc : remainingNPCs) {
        std::cout << "- " << npc->getName() << std::endl;
    }

    // Проверяем, что количество NPC уменьшилось
    ASSERT_LT(remainingNPCs.size(), initialNPCCount);

    for (const auto& npc : remainingNPCs) {
        // Проверяем, что NPC не близки друг к другу
        for (const auto& other : remainingNPCs) {
            if (npc != other) {
                EXPECT_FALSE(npc->isClose(other, 30));
            }
        }

        // Проверяем, что бой проходит корректно
        if (npc->isDragon()) {
            EXPECT_TRUE(dragon->fight(std::static_pointer_cast<Dragon>(npc)));
        } else if (npc->isKnight()) {
            EXPECT_TRUE(knight->fight(std::static_pointer_cast<Knight>(npc)));
        }
    }
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
