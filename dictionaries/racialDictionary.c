//*****************************************************************************
// Class: racialDictionary
// File Name: racialDictionary.c
//
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
#include "/lib/include/itemFormatters.h"
#include "/lib/dictionaries/races/eyes.h"
#include "/lib/dictionaries/races/hair.h"
#include "/lib/dictionaries/races/races.h"

private string SubraceRoot = "/lib/modules/traits/racial/";
private string TraitRoot = "/lib/modules/traits/%s/";

/////////////////////////////////////////////////////////////////////////////
public nomask int isValidRace(string race)
{
    return (races && member(races, race) &&
            mappingp(races[race]));
}

/////////////////////////////////////////////////////////////////////////////
public nomask int isCreatureRace(string race)
{
    return (isValidRace(race) && (member(filter(m_indices(races),
        (: races[$1]["playable"] == 0 :)), race) > -1));
}

/////////////////////////////////////////////////////////////////////////////
private nomask int lookUpBonus(string race, string bonus)
{
    int ret = 0;
    
    if(isValidRace(race) && member(races[race], bonus) &&
       intp(races[race][bonus]))
    {
        ret = races[race][bonus];
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask int lookUpSkillBonus(string race, string skill)
{
    int ret = 0;
 
    if(isValidRace(race) && member(races[race], "skills") &&
       mappingp(races[race]["skills"]) && 
       member(races[race]["skills"], skill) && 
       intp(races[race]["skills"][skill]))
    {
        ret = races[race]["skills"][skill];
    }
    else if (isValidRace(race) && member(races[race], skill) &&
        intp(races[race][skill]))
    {
        ret = races[race][skill];
    }
    return ret;    
}
    
/////////////////////////////////////////////////////////////////////////////
public nomask int MaxHitPoints(string race)
{
    return lookUpBonus(race, "hit points");
}

/////////////////////////////////////////////////////////////////////////////
public nomask int MaxSpellPoints(string race)
{
    return lookUpBonus(race, "spell points");
}

/////////////////////////////////////////////////////////////////////////////
public nomask int MaxStaminaPoints(string race)
{
    return lookUpBonus(race, "stamina points");
}

/////////////////////////////////////////////////////////////////////////////
public nomask int DefendAttackBonus(string race)
{
    return lookUpBonus(race, "defend attack");
}

/////////////////////////////////////////////////////////////////////////////
public nomask int AttackBonus(string race)
{
    return lookUpBonus(race, "attack");
}

/////////////////////////////////////////////////////////////////////////////
public nomask int DefenseBonus(string race)
{
    return lookUpBonus(race, "defense");
}

/////////////////////////////////////////////////////////////////////////////
public nomask int DamageBonus(string race)
{
    return lookUpBonus(race, "damage");
}

/////////////////////////////////////////////////////////////////////////////
public nomask int BonusHealHitPoints(string race)
{
    return lookUpBonus(race, "bonus heal hit points");
}

/////////////////////////////////////////////////////////////////////////////
public nomask int BonusHealSpellPoints(string race)
{
    return lookUpBonus(race, "bonus heal spell points");
}

/////////////////////////////////////////////////////////////////////////////
public nomask int BonusHealStamina(string race)
{
    return lookUpBonus(race, "bonus heal stamina points");
}

/////////////////////////////////////////////////////////////////////////////
public nomask int BonusHealHitPointsRate(string race)
{
    return lookUpBonus(race, "bonus heal hit points rate");
}

/////////////////////////////////////////////////////////////////////////////
public nomask int BonusHealSpellPointsRate(string race)
{
    return lookUpBonus(race, "bonus heal spell points rate");
}

/////////////////////////////////////////////////////////////////////////////
public nomask int BonusHealStaminaRate(string race)
{
    return lookUpBonus(race, "bonus heal stamina rate");
}

/////////////////////////////////////////////////////////////////////////////
public nomask int RecoverSpellPoints(string race)
{
    return lookUpBonus(race, "recover spell points");
}

/////////////////////////////////////////////////////////////////////////////
public nomask int ReduceSpellPoints(string race)
{
    return lookUpBonus(race, "reduce spell points");
}

/////////////////////////////////////////////////////////////////////////////
public nomask int RecoverStaminaPoints(string race)
{
    return lookUpBonus(race, "recover stamina points");
}

/////////////////////////////////////////////////////////////////////////////
public nomask int ReduceStaminaPoints(string race)
{
    return lookUpBonus(race, "reduce stamina points");
}

/////////////////////////////////////////////////////////////////////////////
public nomask int BonusSkillModifier(string race, string skill)
{
    return lookUpSkillBonus(race, skill);
}

/////////////////////////////////////////////////////////////////////////////
public nomask int StrengthBonus(string race)
{
    return lookUpBonus(race, "strength");
}

/////////////////////////////////////////////////////////////////////////////
public nomask int IntelligenceBonus(string race)
{
    return lookUpBonus(race, "intelligence");
}

/////////////////////////////////////////////////////////////////////////////
public nomask int DexterityBonus(string race)
{
    return lookUpBonus(race, "dexterity");
}

/////////////////////////////////////////////////////////////////////////////
public nomask int WisdomBonus(string race)
{
    return lookUpBonus(race, "wisdom");
}

/////////////////////////////////////////////////////////////////////////////
public nomask int ConstitutionBonus(string race)
{
    return lookUpBonus(race, "constitution");
}

/////////////////////////////////////////////////////////////////////////////
public nomask int CharismaBonus(string race)
{
    return lookUpBonus(race, "charisma");
}

/////////////////////////////////////////////////////////////////////////////
public nomask mapping *extraAttacks(string race)
{
    mapping *ret = ({});
    if (member(races, race) && member(races[race], "attacks"))
    {
        foreach(string attack in m_indices(races[race]["attacks"]))
        {
            ret += ({ ([
                "attack type": attack,
                "damage": races[race]["attacks"][attack], 
                "to hit": 75 ]) });
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask string *researchTrees(string race)
{
    string *ret = ({ });
    if(isValidRace(race) && member(races[race], "research trees") &&
       races[race]["research trees"] && 
       pointerp(races[race]["research trees"]))
    {
        ret = races[race]["research trees"];
    }
    return ret + ({ });
}

/////////////////////////////////////////////////////////////////////////////
public nomask int canUseEquipmentOfType(object actor, object equipment)
{
    // TODO: Add equipment prohibition to races
    return 1;
}

/////////////////////////////////////////////////////////////////////////////
private nomask string startingSkillsAndTraits(string race)
{
    string ret = "";

    if (member(races[race], "starting skill points"))
    {
        ret += sprintf("\t\x1b[0;32mStarting skill points:\x1b[0m \x1b[0;34;1m%d\x1b[0m\n",
            races[race]["starting skill points"]);
    }
    if (member(races[race], "background trait value"))
    {
        ret += sprintf("\t\x1b[0;32mBonus to trait selection:\x1b[0m \x1b[0;34;1m%d\x1b[0m\n",
            races[race]["background trait value"]);
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask string bonusAttributeDescription(string race)
{
    string ret = "";

    string *attributes = ({ "strength", "intelligence", "wisdom", "dexterity",
        "constitution", "charisma" });

    foreach(string attribute in attributes)
    {
        if (member(races[race], attribute))
        {
            ret += sprintf("\t\x1b[0;32m%-12s\x1b[0m " +
                ((races[race][attribute] > 0) ? "\x1b[0;34;1m+%d\x1b[0m\n" : "\x1b[0;31m%d\x1b[0m\n"),
                capitalize(attribute), races[race][attribute]);
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask string bonusSkillDescription(string race)
{
    string ret = "";

    if (member(races[race], "skills"))
    {
        string *skills = sort_array(m_indices(races[race]["skills"]),
            (: $1 > $2 :));

        foreach(string skill in skills)
        {
            ret += sprintf("\t\x1b[0;32mBonus %s skill\x1b[0m " +
                ((races[race]["skills"][skill] > 0) ? 
                    "\x1b[0;34;1m+%d\x1b[0m\n" : "\x1b[0;31m%d\x1b[0m\n"),
                capitalize(skill), races[race]["skills"][skill]);
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask string otherBonusesDescription(string race)
{
    string ret = "";
    string *bonuses = m_indices(races[race]) -
        ({ "strength", "intelligence", "wisdom", "dexterity", "playable",
        "constitution", "charisma", "description", "starting skill points",
        "background trait value", "skills", "research trees", "subraces" });

    bonuses = sort_array(bonuses, (: $1 > $2 :));

    foreach(string bonus in bonuses)
    {
        if (member(races[race], bonus))
        {
            ret += sprintf("\t\x1b[0;32m%-12s\x1b[0m " +
                ((races[race][bonus] > 0) ? "\x1b[0;34;1m+%d\x1b[0m\n" : "\x1b[0;31m%d\x1b[0m\n"),
                capitalize(bonus), races[race][bonus]);
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask string racialDescription(string race)
{
    string ret = races[race]["description"] + "\n" +
        sprintf("\nThe %s race incurs the following in-game bonuses/penalties:\n",
            race) +
        startingSkillsAndTraits(race) + 
        bonusAttributeDescription(race) +
        otherBonusesDescription(race) +
        bonusSkillDescription(race);

    if (member(races[race], "research trees"))
    {
        ret += "\t\x1b[0;34;1mA special research tree only available to "
            "this race is unlocked.\x1b[0m\n";
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask mapping characterCreationRaces()
{
    mapping selection = ([]);

    string *raceList = sort_array(filter(m_indices(races),
        (: races[$1]["playable"] == 1 :)), (: $1 > $2 :));

    int i = 1;
    foreach(string race in raceList)
    {
        selection[to_string(i)] = ([
            "name": capitalize(race),
            "description": racialDescription(race)
        ]);
        i++;
    }
    return selection;
}

/////////////////////////////////////////////////////////////////////////////
public nomask mapping characterCreationSubraces(string race)
{
    mapping selection = ([]);

    if (member(races, race) && member(races[race], "subraces"))
    {
        string *raceList = sort_array(m_indices(races[race]["subraces"]), (: $1 > $2 :));
        int i = 1;
        object traitDictionary = load_object("/lib/dictionaries/traitsDictionary.c");

        foreach(string subrace in raceList)
        {
            string path = SubraceRoot + races[race]["subraces"][subrace];
            object traitObj = traitDictionary->traitObject(path);

            if(traitObj)
            {
                selection[to_string(i)] = ([
                    "name":capitalize(subrace),
                    "description": traitDictionary->traitDetailsFromFile(path),
                    "file": path
                ]);
                i++;
            }
        }
        selection[to_string(i)] = ([
            "name": "Do not add a subrace",
            "description": "This option does not add a subrace to the player.\n",
            "file": "none"
        ]);
    }
    return selection;
}

/////////////////////////////////////////////////////////////////////////////
private nomask mapping characterCreationTraitOfType(string type,
    string race, mapping data)
{
    mapping selection = ([]);

    string *dataList = sort_array(filter(m_indices(data),
        (: return(member($3[$1]["exclude"], $2) == -1); :), race, data),
        (: $1 > $2 :));

    int i = 1;
    object traitDictionary = load_object("/lib/dictionaries/traitsDictionary.c");
    foreach(string item in dataList)
    {
        string path = sprintf(TraitRoot, type) + data[item]["file"];
        object traitObj = traitDictionary->traitObject(path);

        if (traitObj)
        {
            selection[to_string(i)] = ([
                "name": capitalize(item),
                "description" : traitDictionary->traitDetailsFromFile(path),
                "file": path
            ]);
            i++;
        }
    }
    return selection;
}

/////////////////////////////////////////////////////////////////////////////
public nomask mapping characterCreationHair(string race)
{
    mapping selection = characterCreationTraitOfType("hair", race, hairColors);

    selection[to_string(sizeof(selection) + 1)] = ([
        "name": "Do not add a hair color",
        "description" : "This option does not add a hair color to the player.\n",
        "file" : "none"
    ]);
    return selection;
}

/////////////////////////////////////////////////////////////////////////////
public nomask mapping characterCreationEyes(string race)
{
    mapping selection = characterCreationTraitOfType("eyes", race, eyeColors);

    selection[to_string(sizeof(selection) + 1)] = ([
        "name": "Do not add an eye color",
        "description" : "This option does not add an eye color to the player.\n",
        "file" : "none"
    ]);
    return selection;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int startingSkillPoints(string race)
{
    int ret = 0;

    if (member(races[race], "starting skill points"))
    {
        ret = races[race]["starting skill points"];
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int backgroundTraitPoints(string race)
{
    int ret = 0;

    if (member(races[race], "background trait value"))
    {
        ret = races[race]["background trait value"];
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask string raceDetails(object person)
{
    string race = person->Race();
    string subrace = 0;

    if (member(races, race) && member(races[race], "subraces"))
    {
        string *subraces = m_indices(races[race]["subraces"]);
        foreach(string subraceCheck in subraces)
        {
            if (person->isTraitOf(SubraceRoot +
                races[race]["subraces"][subraceCheck]))
            {
                subrace = capitalize(subraceCheck);
                break;
            }
        }
    }
    return sprintf("%s%s", race ? capitalize(race) : "Unknown",
        subrace ? " (" + subrace + ")" : "");
}
