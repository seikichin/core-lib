//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/weapon.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg) 
{
    if (!arg) 
    {
        set("name", "Wakisashi");
        set("short", "Wakisashi");
        set("aliases", ({ "sword", "short sword", "wakisashi" }));
        set("blueprint", "wakisashi");
    }
}
