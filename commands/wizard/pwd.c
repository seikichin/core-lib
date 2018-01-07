//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/commands/baseCommand.c";

/////////////////////////////////////////////////////////////////////////////
public nomask void reset(int arg)
{
    if (!arg)
    {
        addCommandTemplate("pwd");
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask int execute(string command, object initiator)
{
    int ret = 0;

    if (canExecuteCommand(command) && function_exists("pwd", initiator) &&
        initiator->hasExecuteAccess("pwd"))
    {
        ret = 1;
        tell_object(initiator, sprintf("%s\n", initiator->pwd()));
    }
    return ret;
}
