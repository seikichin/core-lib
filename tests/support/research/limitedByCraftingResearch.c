//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        passiveResearchItem::reset(arg);
        addSpecification("name", "Craft Swords");
        addSpecification("source", "crafting");
        addSpecification("description", "This skill provides the user with the "
            "knowledge required to craft knives, daggers, and swords out of "
            "typical bladed weapon materials such as iron, bronze, and steel.");
        addSpecification("research type", "granted");
        addSpecification("limited by", (["crafting type":"sword"]));
        addSpecification("bonus weapon smithing", 30);
    }
}

