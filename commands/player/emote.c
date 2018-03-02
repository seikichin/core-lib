//******************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/commands/baseCommand.c";
#include <mtypes.h>

/////////////////////////////////////////////////////////////////////////////
public nomask void reset(int arg)
{
    if (!arg)
    {
        CommandType = "emote / soul";
        addCommandTemplate("emote [.*]");
        addCommandTemplate(": [.*]");
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask int execute(string command, object initiator)
{
    int ret = 0;

    if (canExecuteCommand(command) || (command[0] == ':'))
    {
        // This is stripping out escape characters and the command.
        string message = initiator->Name() + " " + 
            regreplace(command, "^(emote|:) ", "", 1);
        message -= "";

        if (environment(initiator))
        {
            foreach(object person in all_inventory(environment(initiator)))
            {
                if (person && objectp(person))
                {
                    tell_object(person, formatText(message, C_EMOTES,
                        person));
                }
            }
        }
        ret = 1;
    }
    return ret;
}
