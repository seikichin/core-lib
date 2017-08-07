//*****************************************************************************
// Copyright (c) 2017 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************

/////////////////////////////////////////////////////////////////////////////
private string convertString(string input)
{
    string ret = input;
    if (!stringp(input))
    {
        ret = "";
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask mapping getFactions(int playerId, int dbHandle)
{
    mapping ret = ([
        "factions":([
        ]),
        "memberOfFactions": ({ })
    ]);

    string query = sprintf("select * from factions "
        "where playerid = '%d'", playerId);
    db_exec(dbHandle, query);

    mixed result;

    do
    {
        result = db_fetch(dbHandle);
        if (result)
        {
            ret["factions"][result[2]] = ([
                "disposition":convertString(result[3]),
                "reputation": to_int(result[4]),
                "last interaction": to_int(result[5]),
                "number of interactions": to_int(result[6]),
                "disposition time": to_int(result[7]),
            ]);

            if (stringp(result[8]) && (to_int(result[8]) == 1))
            {
                ret["memberOfFactions"] += ({ result[2] });
            }
        }
    } while (result);

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void saveFactions(int dbHandle, int playerId, mapping playerData)
{
    if (member(playerData, "factions") && sizeof(playerData["factions"]))
    {
        string *factions = m_indices(playerData["factions"]);
        foreach(string faction in factions)
        {
            string query = sprintf("call saveFaction("
                "%d,'%s','%s',%d,%d,%d,%d,%d);",
                playerId,
                db_conv_string(faction),
                db_conv_string(playerData["factions"][faction]["disposition"]),
                playerData["factions"][faction]["reputation"],
                playerData["factions"][faction]["last interaction"],
                playerData["factions"][faction]["number of interactions"],
                playerData["factions"][faction]["disposition time"],
                (member(playerData["memberOfFactions"], faction) > -1)
            );
            db_exec(dbHandle, query);
            mixed result = db_fetch(dbHandle);
        }
    }
}
