//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/material.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg) 
{
    if (!arg) 
    {
        set("name", "Aquamarine");
        set("short", "Aquamarine");
        set("aliases", ({ "gem", "aquamarine" }));
        set("blueprint", "aquamarine");
    }
}
