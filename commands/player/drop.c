//*****************************************************************************
// Copyright (c) 2017 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/commands/baseCommand.c";

private string TargetString;

/////////////////////////////////////////////////////////////////////////////
public nomask void reset(int arg)
{
    if (!arg)
    {
        addCommandTemplate("drop [(-a|-f)+] ##Item##");
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask int execute(string command, object initiator)
{
    int ret = 0;

    object *targets = ({});
    TargetString = getTargetString(initiator, command);

    if (TargetString == "all")
    {
        targets += filter_array(all_inventory(initiator),
            (: function_exists("drop", $1) && 
                !$1->query("undroppable") :));
    }
    else if (sizeof(regexp(({ command }), "-a")))
    {
        targets += filter_array(all_inventory(initiator),
            (: function_exists("drop", $1) && 
                !$1->query("undroppable") &&
                $1->id(TargetString) :));
    }
    else
    {
        targets += ({ getTarget(initiator, command) });
    }
    targets -= ({ 0 });

    if (sizeof(targets) && canExecuteCommand(command))
    {
        ret = 1;
        foreach(object target in targets)
        {
            if (!initiator->isEquipped(target) ||
                sizeof(regexp(({ command }), "-f")))
            {
                target->drop();
            }
        }
    }
    return ret;
}