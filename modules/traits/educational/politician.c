//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        addSpecification("type", "educational");
        addSpecification("name", "politician");
        addSpecification("description", "You are a beaurocrat through and through.");
        addSpecification("root", "educated");
        addSpecification("opposing root", "uneducated");
        addSpecification("opinion", 25);
        addSpecification("opposing opinion", 10);
        addSpecification("bonus charisma", 1);
        addSpecification("bonus ancient history", 2);
        addSpecification("bonus local history", 2);
        addSpecification("bonus etiquette", 2);
        addSpecification("bonus persuasion", 2);
        addSpecification("bonus barter", 2);
        addSpecification("bonus diplomacy", 2);
        addSpecification("cost", 1);
        "baseTrait"::reset(arg);
    }
}

