//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        knowledgeResearchItem::reset(arg);
        addSpecification("name", "Plasma Eruption");
        addSpecification("source", "Scion of Dhuras Guild");
        addSpecification("description", "This research provides the user with the "
            "knowledge of the plasma eruption technique. This form enhances "
            "the Scion's offensive spells.");

        addPrerequisite("level", 
            (["type":"level", 
              "guild": "Scion of Dhuras",
              "value": 39 ]));
        addPrerequisite("lib/guilds/scion/paths/sword/electricity/enhanced-discharge.c",
            (["type":"research"]));

        addSpecification("limited by", (["equipment":({
            "long sword", "hand and a half sword", "two-handed sword" })]));

        addSpecification("research type", "points");
        addSpecification("research cost", 1);
        addSpecification("affected research", (["Lightning":10,
            "Lightning Blast" : 10,
            "Maelstrom" : 10,
            "Plasma Ball" : 30
        ]));
    }
}
