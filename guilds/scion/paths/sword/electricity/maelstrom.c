//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        instantaneousActiveResearchItem::reset(arg);
        addSpecification("name", "Maelstrom");
        addSpecification("source", "Scion of Dhuras Guild");
        addSpecification("description", "This research provides the user with the "
            "knowledge of the maelstrom technique. By means of this, the "
            "Scion is able to use their sword as a conduit for sending balls "
            "of plasma at all foes in the area.");

        addSpecification("limited by", (["equipment":({
            "long sword", "hand and a half sword", "two-handed sword" })]));

        addPrerequisite("lib/guilds/scion/paths/sword/root.c",
            (["type":"research"]));
        addPrerequisite("lib/guilds/scion/paths/sword/electricity/lightning-blast.c",
            (["type":"research"]));
        addPrerequisite("level",
            (["type":"level",
                "guild": "Scion of Dhuras",
                "value": 37
            ]));

        addSpecification("scope", "area");
        addSpecification("research type", "points");
        addSpecification("research cost", 1);
        addSpecification("spell point cost", 250);

        addSpecification("damage hit points", ({ ([
                "probability":90,
                "base damage" : 40,
                "range" : 80
            ]),
            ([
                "probability": 10,
                "base damage": 75,
                "range" : 125
            ])
        }));
        addSpecification("damage spell points", ({ ([
                "probability":90,
                "base damage" : 25,
                "range" : 50
            ]),
            ([
                "probability": 10,
                "base damage": 50,
                "range" : 100
            ])
        }));
        addSpecification("damage type", "electricity");

        addSpecification("modifiers", ({ 
            ([
                "type":"research",
                "research item": "lib/guilds/scion/paths/sword/electricity/static-charge.c",
                "name" : "Static Charge",
                "formula" : "additive",
                "base value" : 5,
                "rate": 1.0
            ]),
            ([
                "type":"research",
                "research item": "lib/guilds/scion/paths/sword/electricity/electrostatic-induction.c",
                "name" : "Electrostatic Induction",
                "formula" : "additive",
                "base value" : 5,
                "rate": 1.0
            ]),
            ([
                "type":"research",
                "research item": "lib/guilds/scion/paths/sword/electricity/ionization.c",
                "name" : "Ionization",
                "formula" : "additive",
                "base value" : 5,
                "rate": 1.0
            ]),
            ([
                "type":"research",
                "research item": "lib/guilds/scion/paths/sword/electricity/enhanced-discharge.c",
                "name" : "Enhanced Discharge",
                "formula" : "additive",
                "base value" : 10,
                "rate": 1.0
            ]),
            ([
                "type":"research",
                "research item": "lib/guilds/scion/paths/sword/electricity/plasma-eruption.c",
                "name" : "Plasma Eruption",
                "formula" : "additive",
                "base value" : 10,
                "rate": 1.0
            ]),
            ([
                "type":"skill",
                "name" : "long sword",
                "formula" : "additive",
                "rate" : 1.05
            ]),
            ([
                "type":"skill",
                "name" : "elemental air",
                "formula" : "additive",
                "rate" : 1.10
            ]),
            ([
                "type":"skill",
                "name" : "spellcraft",
                "formula" : "logarithmic",
                "rate" : 1.05
            ]),
            ([
                "type":"level",
                "name" : "level",
                "formula" : "logarithmic",
                "rate" : 1.05
            ]),
            ([
                "type":"attribute",
                "name" : "intelligence",
                "formula" : "additive",
                "rate" : 1.05
            ]) 
        }));

        addSpecification("cooldown", 180);
        addSpecification("event handler", "maelstromEvent");
        addSpecification("command template", "maelstrom");
        addSpecification("use ability message",  "Intense balls of plasma "
            "erupt from ##InitiatorPossessive::Name## sword.");
    }
}
