//*****************************************************************************
// Copyright (c) 2017 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

#include "/lib/include/inventory.h"

object Player;

/////////////////////////////////////////////////////////////////////////////
void Init()
{
    setRestoreCaller(this_object());
    object database = clone_object("/lib/tests/modules/secure/fakeDatabase.c");
    database->PrepDatabase();

    object dataAccess = clone_object("/lib/modules/secure/dataAccess.c");
    dataAccess->savePlayerData(database->Gorthaur());

    destruct(dataAccess);
    destruct(database);
}

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    Player = clone_object("/lib/realizations/player.c");
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    // Need to clean up database stuff and the cost of doing a PrepDatabase for each
    // test is pretty high.
    object *items = all_inventory(Player);
    if (sizeof(items))
    {
        foreach(object item in items)
        {
            item->unequip(item->query("name"), 1);
            destruct(item);
        }
        Player->save();
    }
    destruct(Player);
}

/////////////////////////////////////////////////////////////////////////////
void PlayerMaterialAttributesRestored()
{
    Player->restore("gorthaur");
    ExpectEq("Gorthaur", Player->Name());
    ExpectEq("male", Player->GenderDesc());
    ExpectEq(1, Player->Age());
    ExpectEq(0, Player->Ghost());
    ExpectEq(0, Player->Invisibility());
    ExpectEq("is now here", Player->MessageIn());
    ExpectEq("leaves", Player->MessageOut());
    ExpectEq("blah", Player->MagicalMessageIn());
    ExpectEq("de-blahs", Player->MagicalMessageOut());
    ExpectEq("blarg", Player->MessageHome());
    ExpectEq("does stuff", Player->MessageClone());
    ExpectEq("the title-less", Player->Title());
    ExpectEq("Weasel Lord", Player->Pretitle());
    ExpectEq("blah", Player->short());
    ExpectEq("This is a long description", Player->description());
}

/////////////////////////////////////////////////////////////////////////////
void PlayerAttributesRestored()
{
    Player->restore("gorthaur");
    ExpectEq(13, Player->Str());
    ExpectEq(12, Player->Int());
    ExpectEq(13, Player->Dex());
    ExpectEq(13, Player->Wis());
    ExpectEq(13, Player->Con());
    ExpectEq(16, Player->Chr());
    ExpectEq(1, Player->attributePoints());
}

/////////////////////////////////////////////////////////////////////////////
void PlayerBiologicalAttributesRestored()
{
    Player->restore("gorthaur");
    ExpectEq(5, Player->Intoxicated());
    ExpectEq(2, Player->Soaked());
    ExpectEq(4, Player->Stuffed());
    ExpectEq(3, Player->Drugged());
    ExpectEq(1, Player->haveHeadache());
}

/////////////////////////////////////////////////////////////////////////////
void PlayerCombatAttributesRestored()
{
    Player->restore("gorthaur");
    ExpectEq(100, Player->hitPoints());
    ExpectEq(188, Player->maxHitPoints());
    ExpectEq(120, Player->spellPoints());
    ExpectEq(230, Player->maxSpellPoints());
    ExpectEq(140, Player->staminaPoints());
    ExpectEq(228, Player->maxStaminaPoints());
    ExpectEq(70, Player->Wimpy());
    ExpectTrue(Player->onKillList());
}

/////////////////////////////////////////////////////////////////////////////
void PlayerGuildsRestored()
{
    Player->restore("gorthaur");
    ExpectEq(({ "mage" }), Player->memberOfGuilds());
    ExpectEq(21, Player->effectiveLevel());
    ExpectEq(120133, Player->effectiveExperience());
    ExpectEq(16, Player->guildLevel("mage"));
    ExpectEq(133, Player->guildExperience("mage"));
    ExpectEq("acolyte", Player->guildRank("mage"));
    ExpectEq("the blah blah", Player->guildTitle("mage"));
    ExpectEq("Mage", Player->guildPretitle("mage"));
    ExpectFalse(Player->isAnathema("mage"));
    ExpectEq(2333, Player->ageWhenRankAdvanced("mage"));

    // Even though the guild level for fighter is 5, since they left,
    // it's effectively 0.
    ExpectEq(0, Player->guildLevel("fighter"));
    ExpectTrue(Player->isAnathema("fighter"));
}

/////////////////////////////////////////////////////////////////////////////
void PlayerQuestsRestored()
{
    Player->restore("gorthaur");
    ExpectEq(({ "lib/tests/support/quests/testQuestItem.c" }), Player->activeQuests());

    object quest = load_object("/lib/tests/support/quests/testQuestItem.c");
    ExpectEq(sprintf("[0;36m%s[0m", "I've been asked to meet the king! I met King Tantor the Unclean of Thisplace. He seems to like me. The king asked me - ME - to be his personal manservant. Yay me!"),
        Player->questStory("lib/tests/support/quests/testQuestItem.c"));
}

/////////////////////////////////////////////////////////////////////////////
void PlayerRaceRestored()
{
    Player->restore("gorthaur");
    ExpectEq("elf", Player->Race());
}

/////////////////////////////////////////////////////////////////////////////
void PlayerResearchRestored()
{
    Player->restore("gorthaur");
    ExpectEq(3, Player->researchPoints());
    ExpectTrue(Player->isResearched("/lib/tests/support/research/testGrantedResearchItem.c"));
    ExpectEq(({ "/lib/tests/support/research/testSecondResearchTree.c" }), Player->availableResearchTrees());
    ExpectTrue(Player->selectResearchChoice("/lib/tests/support/research/testPersistedActiveTraitResearch.c",
        "Test"));
}

/////////////////////////////////////////////////////////////////////////////
void PlayerSkillsRestored()
{
    Player->restore("gorthaur");
    ExpectEq(16, Player->getSkill("long sword"));
}

/////////////////////////////////////////////////////////////////////////////
void PlayerTraitsRestored()
{
    Player->restore("gorthaur");
    ExpectEq(({ "/lib/tests/support/traits/testTrait.c", "/lib/tests/support/traits/testTraitWithDuration.c" }), 
        Player->Traits());
}

/////////////////////////////////////////////////////////////////////////////
void PlayerMaterialAttributesSaved()
{
    Player->restore("gorthaur");
    Player->Invisibility(1);
    Player->Gender(2);
    Player->MessageIn("a");
    Player->MessageOut("b");
    Player->MagicalMessageIn("c");
    Player->MagicalMessageOut("d");
    Player->MessageHome("e");
    Player->MessageClone("f");
    Player->Title("g");
    Player->Pretitle("h");
    Player->short("i");
    Player->description("j");
    Player->save();

    destruct(Player);
    Player = clone_object("/lib/realizations/player.c");
    Player->restore("gorthaur");
    ExpectEq("Gorthaur", Player->Name());
    ExpectEq("female", Player->GenderDesc());
    ExpectTrue(Player->Invisibility());
    ExpectEq("a", Player->MessageIn());
    ExpectEq("b", Player->MessageOut());
    ExpectEq("c", Player->MagicalMessageIn());
    ExpectEq("d", Player->MagicalMessageOut());
    ExpectEq("e", Player->MessageHome());
    ExpectEq("f", Player->MessageClone());
    ExpectEq("g", Player->Title());
    ExpectEq("h", Player->Pretitle());
    Player->Invisibility(1);
    ExpectEq("i", Player->short());
    ExpectEq("j", Player->description());
}

/////////////////////////////////////////////////////////////////////////////
void PlayerAttributesSaved()
{
    Player->restore("gorthaur");
    Player->Str(6);
    Player->Int(7);
    Player->Dex(8);
    Player->Wis(9);
    Player->Con(10);
    Player->Chr(11);
    Player->addAttributePointsToSpend(4);
    Player->save();

    destruct(Player);
    Player = clone_object("/lib/realizations/player.c");
    Player->restore("gorthaur");

    ExpectEq(9, Player->Str());
    ExpectEq(8, Player->Int());
    ExpectEq(9, Player->Dex());
    ExpectEq(9, Player->Wis());
    ExpectEq(9, Player->Con());
    ExpectEq(12, Player->Chr());
    ExpectEq(5, Player->attributePoints());
}

/////////////////////////////////////////////////////////////////////////////
void PlayerBiologicalAttributesSaved()
{
    Player->restore("gorthaur");
    Player->addIntoxication(2);
    Player->addStuffed(2);
    Player->addDrugged(2);
    Player->addSoaked(2);
    Player->save();

    destruct(Player);
    Player = clone_object("/lib/realizations/player.c");
    Player->restore("gorthaur");
    ExpectEq(7, Player->Intoxicated());
    ExpectEq(4, Player->Soaked());
    ExpectEq(6, Player->Stuffed());
    ExpectEq(5, Player->Drugged());
}

/////////////////////////////////////////////////////////////////////////////
void PlayerCombatAttributesSaved()
{
    Player->restore("gorthaur");
    ExpectEq(100, Player->hitPoints());
    ExpectEq(120, Player->spellPoints());
    ExpectEq(140, Player->staminaPoints());
    ExpectEq(70, Player->Wimpy());
    ExpectTrue(Player->onKillList());
    Player->hitPoints(10);
    Player->spellPoints(10);
    Player->staminaPoints(10);
    Player->Wimpy("40");
    Player->toggleKillList();
    Player->save();

    destruct(Player);
    Player = clone_object("/lib/realizations/player.c");
    Player->restore("gorthaur");
    ExpectEq(110, Player->hitPoints());
    ExpectEq(130, Player->spellPoints());
    ExpectEq(150, Player->staminaPoints());
    ExpectEq(40, Player->Wimpy());
    ExpectFalse(Player->onKillList());
}

/////////////////////////////////////////////////////////////////////////////
void PlayerGuildsSaved()
{
    object dict = load_object("/lib/dictionaries/guildsDictionary.c");
    object mage = load_object("/lib/tests/support/guilds/mageGuild.c");
    mage->init();
    object guild = load_object("/lib/tests/support/guilds/testGuild.c");
    guild->init();

    Player->restore("gorthaur");
    ExpectTrue(Player->joinGuild("test"));
    Player->addExperience(2000);
    Player->save();
    ExpectTrue(Player->memberOfGuild("test"));

    destruct(Player);
    Player = clone_object("/lib/realizations/player.c");
    Player->restore("gorthaur");

    ExpectEq(121927, Player->effectiveExperience());
    ExpectTrue(Player->memberOfGuild("test"));
    ExpectEq(1,Player->guildLevel("test"));
    ExpectEq("neophyte", Player->guildRank("test"));
    ExpectEq(106, Player->guildExperience("test"));
}

/////////////////////////////////////////////////////////////////////////////
void PlayerQuestsSaved()
{
    Player->restore("gorthaur");
    Player->advanceQuestState("lib/tests/support/quests/testQuestItem.c", "king is dead");
    Player->save();

    destruct(Player);
    Player = clone_object("/lib/realizations/player.c");
    Player->restore("gorthaur");

    ExpectEq(({ "lib/tests/support/quests/testQuestItem.c" }), Player->completedQuests());

    object quest = load_object("/lib/tests/support/quests/testQuestItem.c");
    ExpectEq(sprintf("[0;36m%s[0m[0;31m%s[0m", "I've been asked to meet the king! I met King Tantor the Unclean of Thisplace. He seems to like me. The king asked me - ME - to be his personal manservant. Yay me! I must lay off the sauce - and the wenches. King Tantor is dead because of my night of debauchery.", " [Failure]"),
        Player->questStory("lib/tests/support/quests/testQuestItem.c"));
}

/////////////////////////////////////////////////////////////////////////////
void PlayerRaceSaved()
{
    Player->restore("gorthaur");
    ExpectEq("elf", Player->Race());
    Player->Race("dwarf");
    Player->save();

    destruct(Player);
    Player = clone_object("/lib/realizations/player.c");
    Player->restore("gorthaur");
    ExpectEq("dwarf", Player->Race());
}

/////////////////////////////////////////////////////////////////////////////
void PlayerResearchSaved()
{
    Player->restore("gorthaur");
    ExpectEq(4, Player->researchPoints());
    ExpectTrue(Player->isResearched("/lib/tests/support/research/testGrantedResearchItem.c"));
    ExpectEq(({ "/lib/tests/support/research/testSecondResearchTree.c" }), Player->availableResearchTrees());
    ExpectTrue(Player->selectResearchChoice("/lib/tests/support/research/testPersistedActiveTraitResearch.c",
        "Test"));
    Player->initiateResearch("/lib/tests/support/research/testPointsResearchItem.c");
    Player->save();

    destruct(Player);
    Player = clone_object("/lib/realizations/player.c");
    Player->restore("gorthaur");
    ExpectEq(3, Player->researchPoints());
    ExpectTrue(Player->isResearched("/lib/tests/support/research/testPointsResearchItem.c"));
    ExpectTrue(Player->isResearched("/lib/tests/support/research/testPersistedActiveTraitResearch.c"));
}

/////////////////////////////////////////////////////////////////////////////
void PlayerSkillsSaved()
{
    Player->restore("gorthaur");
    ExpectEq(21, Player->getSkill("long sword"));
    ExpectEq(7, Player->AvailableSkillPoints());
    Player->addSkillPoints(40);
    Player->advanceSkill("long sword", 5);
    Player->save();

    destruct(Player);
    Player = clone_object("/lib/realizations/player.c");
    Player->restore("gorthaur");
    ExpectEq(26, Player->getSkill("long sword"));
    ExpectEq(42, Player->AvailableSkillPoints());
}

/////////////////////////////////////////////////////////////////////////////
void PlayerTraitsSaved()
{
    Player->restore("gorthaur");
    ExpectEq(({ "/lib/tests/support/traits/testTrait.c", "/lib/tests/support/traits/testTraitWithDuration.c" }),
        Player->Traits());
    Player->addTrait("/lib/modules/traits/abrasive.c");
    Player->save();

    destruct(Player);
    Player = clone_object("/lib/realizations/player.c");
    Player->restore("gorthaur");
    ExpectEq(({ "/lib/modules/traits/abrasive.c", "/lib/tests/support/traits/testTrait.c", "/lib/tests/support/traits/testTraitWithDuration.c" }),
        Player->Traits());
}

/////////////////////////////////////////////////////////////////////////////
void PlayerInventorySaved()
{
    Player->restore("gorthaur");

    move_object(clone_object("/lib/tests/support/items/testSword.c"), Player);
    Player->save();
    destruct(Player);
    Player = clone_object("/lib/realizations/player.c");
    ExpectFalse(present("Sword of Weasels", Player));
    Player->restore("gorthaur");
    ExpectTrue(present("Sword of Weasels", Player)); 
}

/////////////////////////////////////////////////////////////////////////////
void PlayerCanSaveMultiplesOfSameBlueprint()
{
    Player->restore("gorthaur");

    ExpectEq(0, sizeof(all_inventory(Player)));
    move_object(clone_object("/lib/tests/support/items/testSword.c"), Player);
    move_object(clone_object("/lib/tests/support/items/testSword.c"), Player);
    Player->save();
    ExpectEq(2, sizeof(all_inventory(Player)));
    destruct(Player);
    Player = clone_object("/lib/realizations/player.c");
    ExpectEq(0, sizeof(all_inventory(Player)));
    Player->restore("gorthaur");

    object *items = all_inventory(Player);
    ExpectEq(2, sizeof(items));
    ExpectEq("lib/tests/support/items/testSword.c", items[0]);
    ExpectEq("lib/tests/support/items/testSword.c", items[1]);
}

/////////////////////////////////////////////////////////////////////////////
void ModifierObjectsAreSavedAndRestored()
{
    Player->restore("gorthaur");
    object modifier = clone_object("/lib/items/modifierObject");
    modifier->set("fully qualified name", "blah");
    modifier->set("bonus hit points", 6);

    ExpectEq(({}), Player->registeredInventoryObjects());
    ExpectEq(1, modifier->set("registration list", ({ Player })), "registration list can be set");
    ExpectEq(({"lib/items/modifierObject.c"}), Player->registeredInventoryObjects());
    Player->save();

    destruct(Player);
    Player = clone_object("/lib/realizations/player.c");
    ExpectEq(({}), Player->registeredInventoryObjects());
    Player->restore("gorthaur");

    ExpectEq(({"lib/items/modifierObject.c"}), Player->registeredInventoryObjects());
    object item = Player->registeredInventoryObject("blah");
    ExpectTrue(item);
    ExpectEq(6, item->query("bonus hit points"));
}

/////////////////////////////////////////////////////////////////////////////
void PlayerInventoryMaintainsWieldedAndWornStateWhenEquippedAtSave()
{
    Player->restore("gorthaur");

    object weapon = clone_object("/lib/tests/support/items/testSword.c");
    move_object(weapon, Player);
    ExpectTrue(weapon->equip("Sword of Weasels"));
    ExpectTrue(Player->isEquipped(weapon));

    object shield = clone_object("/lib/items/weapon");
    shield->set("name", "Shield of Weasels");
    shield->set("defense class", 1);
    shield->set("material", "steel");
    shield->set("craftsmanship", 20);
    shield->set("weapon type", "shield");
    move_object(shield, Player);
    ExpectTrue(shield->equip("Shield of Weasels"));
    ExpectTrue(Player->isEquipped(shield));

    object armor = clone_object("/lib/items/armor");
    armor->set("name", "Armor of Weasels");
    armor->set("bonus hit points", 4);
    armor->set("armor class", 5);
    armor->set("armor type", "chainmail");
    move_object(armor, Player);
    ExpectTrue(armor->equip("Armor of Weasels"));
    ExpectTrue(Player->isEquipped(armor));

    Player->save();

    destruct(armor);
    destruct(weapon);
    destruct(shield);
    destruct(Player);
    Player = clone_object("/lib/realizations/player.c");
    ExpectFalse(present("Sword of Weasels", Player));
    Player->restore("gorthaur");
    ExpectTrue(present("Sword of Weasels", Player));
    ExpectEq("lib/tests/support/items/testSword.c",
        Player->equipmentInSlot("wielded primary"));

    shield = Player->equipmentInSlot("wielded offhand");
    ExpectEq("lib/items/weapon.c", shield);
    // It's also important that the "generic" items maintain set data!
    ExpectEq("Shield of Weasels", shield->query("name"));

    armor = Player->equipmentInSlot("armor");
    ExpectEq("lib/items/armor.c", armor);
    // It's also important that the "generic" items maintain set data!
    ExpectEq("Armor of Weasels", armor->query("name"));
}