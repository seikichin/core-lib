//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/treasure.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        set("name", "rune of endurance");
        set("short", "Rune of Endurance");
        set("aliases", ({ "rune", "rune of endurance", "endurance" }));
        set("long", "A fist-sized slab of amethyst has some intricately carved "
            "runes on it. You can distinguish the Khazdic symbol for the word "
            "'endurance' and see the words, [0;35;3mPushed past endurance[0m "
            "next to it.\n");
    }
}

/////////////////////////////////////////////////////////////////////////////
public int isObedienceRune()
{
    return 1;
}

/////////////////////////////////////////////////////////////////////////////
public string getRuneType()
{
    return "endurance";
}
