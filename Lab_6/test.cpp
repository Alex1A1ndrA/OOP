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
}

TEST(DungeonLocationTest, StartBattleMode) {
    DungeonLocation dungeon;
    auto dragon = std::make_shared<Dragon>(10, 20, "FireDrake");
    auto knight = std::make_shared<Knight>(30, 40, "SirLancelot");
    dungeon.addNPC(dragon);
    dungeon.addNPC(knight);

    // Запускаем боевой режим и проверяем результат
    dungeon.startBattleMode(30);
    EXPECT_EQ(dungeon.getNPCs().size(), 1);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}