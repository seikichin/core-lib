//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/sustainedResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        sustainedResearchItem::reset(arg);
        addSpecification("name", "Shock Blade");
        addSpecification("source", "Scion of Dhuras Guild");
        addSpecification("description", "This research provides the user with the "
            "knowledge of the shock blade technique. By means of this, the "
            "Scion is able to emit a constant electrical current from their "
            "sword. Doing so is wearying and will decrease available stamina.");

        addSpecification("limited by", (["equipment":({
            "long sword", "hand and a half sword", "two-handed sword" })]));

        addPrerequisite("lib/guilds/scion/paths/sword/root.c",
            (["type":"research"]));
        addPrerequisite("lib/guilds/scion/paths/sword/electricity/root.c",
            (["type":"research"]));

        addSpecification("modifiers", ({ 
            ([
                "type":"research",
                "research item": "lib/guilds/scion/paths/sword/electricity/sweeping-shock.c",
                "name" : "sweeping shock",
                "formula" : "additive",
                "base value" : 2,
                "rate": 1.0
            ]),
            ([
                "type":"research",
                "research item": "lib/guilds/scion/paths/sword/electricity/shock-brand.c",
                "name" : "shock brand",
                "formula" : "additive",
                "base value" : 2,
                "rate": 1.0
            ]),
            ([
                "type":"research",
                "research item": "lib/guilds/scion/paths/sword/electricity/energized-blade.c",
                "name" : "energized blade",
                "formula" : "additive",
                "base value" : 2,
                "rate": 1.0
            ]),
            ([
                "type":"research",
                "research item": "lib/guilds/scion/paths/sword/electricity/shocking-edge.c",
                "name" : "shocking edge",
                "formula" : "additive",
                "base value" : 2,
                "rate": 1.0
            ]),
            ([
                "type":"research",
                "research item": "lib/guilds/scion/paths/sword/electricity/thunders-pommel.c",
                "name" : "Thunder's Pommel",
                "formula" : "additive",
                "base value" : 5,
                "rate": 1.0
            ]),
        }));

        addSpecification("scope", "self");
        addSpecification("research type", "points");
        addSpecification("research cost", 1);
        addSpecification("cooldown", 30);
        addSpecification("spell point cost", 10);
        addSpecification("stamina point cost", 50);
        addSpecification("command template", "shock blade");
        addSpecification("bonus electricity enchantment", 3);
        addSpecification("bonus resist electricity", 3);

        addSpecification("use ability activate message", "Thin tendrils of "
            "electricity wrap around ##InitiatorPossessive::Name## sword.");
        addSpecification("use ability deactivate message", "The thin tendrils of "
            "electricity around ##InitiatorPossessive::Name## sword subside.");
    }
}
