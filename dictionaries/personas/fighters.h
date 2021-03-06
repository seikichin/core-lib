//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************

private nosave mapping fighterBlueprints = ([
    "swordsman":([
        "category": "fighters",
        "primary skills": ({ "parry", "dodge", "shield", "long sword",
            "hand and a half sword", "short sword", "dagger",
            "two-handed sword", "plate armor", "splint armor",
            "chainmail", "scalemail", "hard leather", "soft leather",
            "no armor" }),
        "secondary skills": ({ "anatomy and physiology", "perception",
            "listen", "spot", "common", "dual wield" }),
        "traits": ({ }),
        "potential traits": ({ }),
        "equipment": ([ 
            "weapons":({ "swords" }),
            "armor": ({ "light-armor", "medium-armor", "heavy-armor" }),
            "armor/accessories": ({ "belt", "boots", "coif", "gauntlets", "gloves", 
                "helm", "helmet", "ring", "sabaton" })
        ]),
        "base hit points": 100,
        "base spell points": 10,
        "base stamina points": 50
    ]),
    "knifeman":([
        "category": "fighters",
        "primary skills": ({ "parry", "dodge", "shield", "short sword", "dagger",
            "chainmail", "scalemail", "hard leather", "soft leather",
            "no armor" }),
        "secondary skills": ({ "anatomy and physiology", "perception",
            "listen", "spot", "common", "dual wield" }),
        "traits": ({ }),
        "potential traits": ({ }),
        "equipment": ([ 
            "weapons":({ "daggers" }),
            "armor": ({ "light-armor", "medium-armor" }),
            "armor/accessories": ({ "belt", "boots", "coif", "gloves", 
                "helmet", "ring", "sabaton" })
        ]),
        "base hit points": 100,
        "base spell points": 10,
        "base stamina points": 50
    ]),
    "axeman":([
        "category": "fighters",
        "primary skills": ({ "parry", "dodge", "shield", "axe", 
            "plate armor", "splint armor",
            "chainmail", "scalemail", "hard leather", "soft leather",
            "no armor" }),
        "secondary skills": ({ "anatomy and physiology", "perception",
            "listen", "spot", "common", "dual wield" }),
        "traits": ({ }),
        "potential traits": ({ }),
        "equipment": ([ 
            "weapons":({ "axes" }),
            "armor": ({ "medium-armor", "heavy-armor" }),
            "armor/accessories": ({ "belt", "boots", "coif", "gauntlets", "gloves", 
                "helm", "helmet", "ring", "sabaton" })
        ]),
        "base hit points": 100,
        "base spell points": 10,
        "base stamina points": 50
    ]),
    "maceman":([
        "category": "fighters",
        "primary skills": ({ "parry", "dodge", "shield", "mace", 
            "plate armor", "splint armor",
            "chainmail", "scalemail", "hard leather", "soft leather",
            "no armor" }),
        "secondary skills": ({ "anatomy and physiology", "perception",
            "listen", "spot", "common", "dual wield" }),
        "traits": ({ }),
        "potential traits": ({ }),
        "equipment": ([ 
            "weapons":({ "maces" }),
            "armor": ({ "light-armor", "medium-armor", "heavy-armor" }),
            "armor/accessories": ({ "belt", "boots", "coif", "gauntlets", "gloves", 
                "helm", "helmet", "ring", "sabaton" })
        ]),
        "base hit points": 100,
        "base spell points": 10,
        "base stamina points": 50
    ]),
    "hammerman":([
        "category": "fighters",
        "primary skills": ({ "parry", "dodge", "shield", "hammer", 
            "plate armor", "splint armor",
            "chainmail", "scalemail", "hard leather", "soft leather",
            "no armor" }),
        "secondary skills": ({ "anatomy and physiology", "perception",
            "listen", "spot", "common", "dual wield" }),
        "traits": ({ }),
        "potential traits": ({ }),
        "equipment": ([ 
            "weapons":({ "hammers" }),
            "armor": ({ "light-armor", "medium-armor", "heavy-armor" }),
            "armor/accessories": ({ "belt", "boots", "coif", "gauntlets", "gloves", 
                "helm", "helmet", "ring", "sabaton" })
        ]),
        "base hit points": 100,
        "base spell points": 10,
        "base stamina points": 50
    ]),
    "flail man":([
        "category": "fighters",
        "primary skills": ({ "parry", "dodge", "shield", "flail", 
            "plate armor", "splint armor",
            "chainmail", "scalemail", "hard leather", "soft leather",
            "no armor" }),
        "secondary skills": ({ "anatomy and physiology", "perception",
            "listen", "spot", "common", "dual wield" }),
        "traits": ({ }),
        "potential traits": ({ }),
        "equipment": ([ 
            "weapons":({ "flails" }),
            "armor": ({ "light-armor", "medium-armor", "heavy-armor" }),
            "armor/accessories": ({ "belt", "boots", "coif", "gauntlets", "gloves", 
                "helm", "helmet", "ring", "sabaton" })
        ]),
        "base hit points": 100,
        "base spell points": 10,
        "base stamina points": 50
    ]),
    "staff man":([
        "category": "fighters",
        "primary skills": ({ "parry", "dodge", "shield", "staff", 
            "plate armor", "splint armor",
            "chainmail", "scalemail", "hard leather", "soft leather",
            "no armor" }),
        "secondary skills": ({ "anatomy and physiology", "perception",
            "listen", "spot", "common", "dual wield" }),
        "traits": ({ }),
        "potential traits": ({ }),
        "equipment": ([ 
            "weapons":({ "staffs" }),
            "armor": ({ "light-armor", "medium-armor" }),
            "armor/accessories": ({ "belt", "boots", "coif", "gauntlets", "gloves", 
                "helmet", "ring", "sabaton" })
        ]),
        "base hit points": 100,
        "base spell points": 10,
        "base stamina points": 50
    ]),
    "halberdier":([
        "category": "fighters",
        "primary skills": ({ "parry", "dodge", "pole arm", 
            "plate armor", "splint armor", "chainmail", "scalemail" }),
        "secondary skills": ({ "anatomy and physiology", "perception",
            "listen", "spot", "common" }),
        "traits": ({ }),
        "potential traits": ({ }),
        "equipment": ([ 
            "weapons":({ "pole-arms/halberd" }),
            "armor": ({ "heavy-armor" }),
            "armor/accessories": ({ "belt", "boots", "coif", "gauntlets", "gloves", 
                "helm", "helmet", "ring", "sabaton" })
        ]),
        "base hit points": 100,
        "base spell points": 10,
        "base stamina points": 50
    ]),
    "spearman":([
        "category": "fighters",
        "primary skills": ({ "parry", "dodge", "pole arm", 
            "plate armor", "splint armor",
            "chainmail", "scalemail", "hard leather", "soft leather",
            "no armor" }),
        "secondary skills": ({ "anatomy and physiology", "perception",
            "listen", "spot", "common" }),
        "traits": ({ }),
        "potential traits": ({ }),
        "equipment": ([ 
            "weapons":({ "pole-arms/spear" }),
            "armor": ({ "light-armor", "medium-armor" }),
            "armor/accessories": ({ "belt", "boots", "coif", "gauntlets", "gloves", 
                "helmet", "ring" })
        ]),
        "base hit points": 100,
        "base spell points": 10,
        "base stamina points": 50
    ]),
    "guisarmier":([
        "category": "fighters",
        "primary skills": ({ "parry", "dodge", "pole arm", 
            "plate armor", "splint armor",
            "chainmail", "scalemail", "hard leather", "soft leather",
            "no armor" }),
        "secondary skills": ({ "anatomy and physiology", "perception",
            "listen", "spot", "common" }),
        "traits": ({ }),
        "potential traits": ({ }),
        "equipment": ([ 
            "weapons":({ "pole-arms" }),
            "armor": ({ "light-armor", "medium-armor", "heavy-armor" }),
            "armor/accessories": ({ "belt", "boots", "coif", "gauntlets", "gloves", 
                "helm", "helmet", "ring", "sabaton" })
        ]),
        "base hit points": 100,
        "base spell points": 10,
        "base stamina points": 50
    ]),
    "brawler":([
        "category": "fighters",
        "primary skills": ({ "parry", "dodge", "unarmed", 
            "plate armor", "splint armor",
            "chainmail", "scalemail", "hard leather", "soft leather",
            "no armor" }),
        "secondary skills": ({ "anatomy and physiology", "perception",
            "listen", "spot", "common" }),
        "traits": ({ }),
        "potential traits": ({ }),
        "equipment": ([
            "armor": ({ "light-armor", "medium-armor" }),
            "armor/accessories": ({ "belt", "boots", "coif", "gauntlets", "gloves", 
                "helm", "helmet", "ring", "sabaton" })
        ]),
        "base hit points": 100,
        "base spell points": 10,
        "base stamina points": 50
    ]),
    "archer":([
        "category": "fighters",
        "primary skills": ({ "parry", "dodge", "shield", "bow", 
            "plate armor", "splint armor",
            "chainmail", "scalemail", "hard leather", "soft leather",
            "no armor" }),
        "secondary skills": ({ "anatomy and physiology", "perception",
            "listen", "spot", "common", "bowyer and fletcher" }),
        "traits": ({ }),
        "potential traits": ({ }),
        "equipment": ([ 
            "weapons":({ "bows" }),
            "armor": ({ "light-armor", "medium-armor" }),
            "armor/accessories": ({ "belt", "boots", "coif", "gloves", 
                "helmet", "ring" })
        ]),
        "base hit points": 100,
        "base spell points": 10,
        "base stamina points": 50
    ]),
    "crossbowman":([
        "category": "fighters",
        "primary skills": ({ "parry", "dodge", "shield", "crossbow", 
            "plate armor", "splint armor",
            "chainmail", "scalemail", "hard leather", "soft leather",
            "no armor" }),
        "secondary skills": ({ "anatomy and physiology", "perception",
            "listen", "spot", "common", "bowyer and fletcher" }),
        "traits": ({ }),
        "potential traits": ({ }),
        "equipment": ([ 
            "weapons":({ "crossbows" }),
            "armor": ({ "light-armor", "medium-armor" }),
            "armor/accessories": ({ "belt", "boots", "coif", "gloves", 
                "helmet", "ring" })
        ]),
        "base hit points": 100,
        "base spell points": 10,
        "base stamina points": 50
    ]),
    "auxiliary":([
        "category": "fighters",
        "primary skills": ({ "parry", "dodge", "shield", "sling", 
            "thrown", "plate armor", "splint armor",
            "chainmail", "scalemail", "hard leather", "soft leather",
            "no armor" }),
        "secondary skills": ({ "anatomy and physiology", "perception",
            "listen", "spot", "common", "bowyer and fletcher" }),
        "traits": ({ }),
        "potential traits": ({ }),
        "equipment": ([ 
            "weapons":({ "thrown", "slings" }),
            "armor": ({ "light-armor", "medium-armor" }),
            "armor/accessories": ({ "belt", "boots", "coif", "gloves", 
                "helmet", "ring" })
        ]),
        "base hit points": 100,
        "base spell points": 10,
        "base stamina points": 50
    ]),
    "knight of the storm":([
        "category": "fighters",
        "primary skills": ({ "parry", "dodge", "shield", "long sword",
            "hand and a half sword", "short sword", "dagger",
            "two-handed sword", "plate armor", "splint armor",
            "chainmail", "scalemail", "elemental air" }),
        "secondary skills": ({ "anatomy and physiology", "perception",
            "listen", "spot", "common", "dual wield", "magical essence",
            "spellcraft", "evocation" }),
        "traits": ({ }),
        "potential traits": ({ }),
        "equipment": ([ 
            "weapons":({ "swords" }),
            "armor": ({ "medium-armor", "heavy-armor" }),
            "armor/accessories": ({ "belt", "boots", "coif", "gauntlets", "gloves", 
                "helm", "helmet", "ring", "sabaton" })
        ]),
        "research": ([
            "lightning": 1,
        ]),
        "base hit points": 150,
        "base spell points": 100,
        "base stamina points": 50
    ]),

]);
