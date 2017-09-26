//*****************************************************************************
// Class: racialDictionary
// File Name: racialDictionary.c
//
// Copyright (c) 2017 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
#include "/lib/include/itemFormatters.h"

private mapping personalityQuestionnaire = ([
    "1":([
        "question": "You have been invited to attend a grand ball. All of the nobility\n"
            "will be there, though you do not know any of them. You are expected to\n"
            "mingle with them. Does this",
        "answers": ([
            "1": ([
                "name": "Excite and energize you. This is, after all, your element and you\n"
                    "\t      love meeting new people.\n",
                "type": "extravert"
            ]),
            "2": ([
                "name": "Fill you with a sense of dread. People suck and you really would\n"
                    "\t      rather stay home doing something far more interesting\n"
                    "\t      like rearranging your sock drawer. The thought of\n"
                    "\t      listening to the bemoanings of all these self-absorbed\n"
                    "\t      assholes you'll never see again just doesn't excite you.\n",
                "type": "introvert"
            ])
        ])
    ]),
    "2":([
        "question": "Your instructor likes to torment his students with inane activites. Today,\n"
            "he has assigned the task of adding all numbers from 1 to 1000. Do you",
        "answers": ([
            "1": ([
                "name": "Get on with it. If you hurry up and work through the problem as\n"
                    "\t      convention dictates, it shouldn't take too long ere you're done\n"
                    "\t      and able to move on to more enjoyable activities.\n",
                "type": "sensing"
            ]),
            "2": ([
                "name": "Reject convention. If you think about the problem for a while,\n"
                    "\t      you may well come up with a better way of solving the problem. Of\n"
                    "\t      course, maybe you won't and you could end up wasting time\n"
                    "\t      needlessly.\n",
                "type": "intuition"
            ])
        ])
    ]),
    "3":([
        "question": "You have gone to a village meeting wherein you are discussing two projects\n"
            "that are competing for the same resources: the building of a new well for\n"
            "irrigation or erecting a statue of Sir Whatshisname Of Whocares. Most there\n"
            "seem inclined to build the statue - he was the village founder, after all -\n"
            "but you think the well is the only sensible idea. Do you",
        "answers": ([
            "1": ([
                "name": "Thoroughly discuss all of the pros and cons of both projects and\n"
                    "\t      clearly detail why the well is the only logical choice.\n",
                "type": "thinking"
            ]),
            "2": ([
                "name": "Seek to understand why the others want the statue and work toward\n"
                    "\t      the consensus opinion in the end.\n",
                "type": "feeling"
            ])
        ])
    ]),
    "4":([
        "question": "As the leader of an expeditionary force, you have come across an enemy\n"
            "encampment. Through your reconnaissance, you have been able to clearly\n"
            "determine that they are planning to lead a campaign to loot and pillage\n"
            "your leige's lands. Do you",
        "answers": ([
            "1": ([
                "name": "Meticulously and methodically organize your plan of attack. You\n"
                    "\t      will only get one chance, so this had best be perfect.\n",
                "type": "judging"
            ]),
            "2": ([
                "name": "Prepare for the attack with those resources you have on hand. The\n"
                    "\t      plan may not be perfect, but it is not rigid and you trust in\n"
                    "\t      yourself to adapt as new information comes your way.\n",
                "type": "perceiving"
            ])
        ])
    ]),
    "5":([
        "question": "You have been hired by the local lord to track down and apprehend a war\n"
            "criminal. In time, you find the man - one of your old comrades-in-arms. As you\n"
            "are in the process of taking him back for judgement, you discover that his\n"
            "'crimes' involved turning on his lord when ordered to raze a town and butcher\n"
            "its citizens whose only crime was refusing to surrender their harvest to this\n"
            "lord's armies. He and four others defected and protected the townsfolk. In the\n"
            "ensuing melee, he was victorious though his companions all perished. Do you",
        "answers": ([
            "1": ([
                "name": "Honor your contract and bring the man to justice knowing that he\n"
                    "\t      faces executioner for acting with compassion and honor in\n"
                    "\t      protecting innocents.\n",
                "type": "loyal"
            ]),
            "2": ([
                "name": "Free him knowing that, at best, your quest will fail and at worst,\n"
                    "\t      your duplicity will be discovered.\n",
                "type": "compassionate"
            ]),
            "3": ([
                "name": "Take up arms against the local lord and bring him to justice\n"
                    "\t      before the king, knowing full well that the king would judge his\n"
                    "\t      deed the act of a criminal.\n",
                "type": "just"
            ]),
            "4": ([
                "name": "Inform the local lord that you have uncovered the true nature of\n"
                    "\t      the man's crimes and that you still intend to bring the man in but\n"
                    "\t      require additional money lest you inadvertently mention this\n"
                    "\t      episode to the king.\n",
                "type": "corrupt"
            ]),
        ])
    ]),
    "6":([
        "question": "Your travels have led you to a crypt. After vanquishing a wight, you\n"
            "find a vast, opulent treasure that will easily set you up for life. You take\n"
            "all you can and congratulate yourself for your good fortune. The next day while\n"
            "you are smugly sipping an ale in the local tavern, you hear that the local\n"
            "constable has arrested a man for ransacking the crypt. Do you",
        "answers": ([
            "1": ([
                "name": "Silently offer a toast to yourself. It appears that the treasure\n"
                    "\t      really is all yours!\n",
                "type": "dishonest"
            ]),
            "2": ([
                "name": "Turn yourself in. If you tell the constable what happened and\n"
                    "\t      return the treasure, it's no harm, no foul, right? They wouldn't\n"
                    "\t      execute you for this, would they? Regardless, you can't let that\n"
                    "\t      poor soul pay for your crime.\n",
                "type": "honest"
            ]),
            "3": ([
                "name": "You realize that life will be short for you if you're caught,\n"
                    "\t      but you can't let that poor bastard take the fall for you so... there's\n"
                    "\t      nothing for it but to plot a daring rescue. The jail doesn't look all\n"
                    "\t      that sturdy.\n",
                "type": "greedy"
            ])
        ])
    ]),
    "7":([
        "question": "You are a lord and have a long-standing dispute with a fellow noble - \n"
            "Ser Osis of D'Liver. She has gone to the king complaining about how she has been\n"
            "inconvenienced and insulted by you because you did not have your servant\n"
            "whipped when they accidentally spilled her glass of wine on the table. She\n"
            "demands an apology. You respond",
        "answers": ([
            "1": ([
                "name": "Ser Osis of D'Liver can kiss my arse. That wretched dung-beast spilled her\n"
                    "\t      own wine!\n",
                "type": "vulgar"
            ]),
            "2": ([
                "name": "Ser Osis of D'Liver is a drunkard and a buffoon. I will not punish others\n"
                    "\t      for her inability to hold her liquor.\n",
                "type": "abrasive"
            ]),
            "3": ([
                "name": "The kind of woman who wants to enforce her ideas on others is\n"
                    "\t      the kind of woman whose ideas are idiotic.\n",
                "type": "witty"
            ]),
            "4": ([
                "name": "Ser Osis of D'Liver believes in the ideal that her birthright allows her to\n"
                    "\t      step on others. An idealist is one who, on noticing that a rose smells\n"
                    "\t      better than a cabbage, concludes that it also makes a better soup.\n",
                "type": "orator"
            ])

        ])
    ]),
]);

/////////////////////////////////////////////////////////////////////////////
public nomask mapping personalityQuestionnaire()
{
    return personalityQuestionnaire + ([]);
}

/////////////////////////////////////////////////////////////////////////////
private nomask void setPersonalityArchetype(object user, string *results)
{
    string trait = "";
    foreach(string result in results)
    {
        trait += result[0..0];
    }
    
    user->addTrait(sprintf("lib/modules/traits/archetypes/%s.c", trait));
}

/////////////////////////////////////////////////////////////////////////////
public nomask void updateUserPersonality(object user, string *results)
{
    setPersonalityArchetype(user, results[0..3]);
    results = results[4..];

    foreach(string result in results)
    {
        user->addTrait(sprintf("lib/modules/traits/personality/%s.c", result));
    }
}