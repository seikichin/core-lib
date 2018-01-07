//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/core/baseSelector.c";

private object Dictionary;
private object SubselectorObj;
private string CraftingItem;
private string CraftingType;
private string CraftingSubType;
private object Item;

/////////////////////////////////////////////////////////////////////////////
public nomask void setItem(string item)
{
    CraftingItem = item;
}

/////////////////////////////////////////////////////////////////////////////
public nomask void setType(string type)
{
    CraftingType = type;
}

/////////////////////////////////////////////////////////////////////////////
public nomask void setSubType(string type)
{
    CraftingSubType = type;
}

/////////////////////////////////////////////////////////////////////////////
public nomask void reset(int arg)
{
    if(!arg)
    {
        AllowUndo = 0;
        SuppressColon = 1;
        Dictionary = load_object("/lib/dictionaries/craftingDictionary.c");
        Data = ([]);
    }
}

/////////////////////////////////////////////////////////////////////////////
private nomask void getItemToCraft()
{
    if (!Item)
    {
        string file = sprintf("/lib/instances/items/%s/%s/%s.c",
            CraftingType, CraftingSubType, regreplace(CraftingItem, " ", "-"));
        Item = clone_object(file);
        Item->set("identified");
    }
}

/////////////////////////////////////////////////////////////////////////////
private nomask string getDescription()
{
    string ret = load_object("/lib/dictionaries/materialsDictionary.c")->
        getEquipmentStatistics(Item, 0);
    ret = regreplace(ret, ".*Material[^\n]*(.*)", "\\1", 1);
    return sprintf("From this menu, you will select the\ncomponents that "
        "will be used to craft your %s. The relative statistics\nfor the item "
        "you are creating are:", CraftingItem) + ret;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void setUpUserForSelection()
{
    if (!CraftingItem || !CraftingType)
    {
        raise_error("ERROR: selectMaterialsSelector.c - The type has not been "
            "set.\n");
    }
    getItemToCraft();

    Description = getDescription();
    Type = "Craft " + capitalize(CraftingItem);

    Data = Dictionary->getCraftingDataForItem(CraftingType, CraftingItem, User);

    Data[to_string(sizeof(Data) + 1)] = ([
        "name": sprintf("Exit Craft %s Menu", capitalize(CraftingItem)),
        "type": "exit",
        "description": "This option lets you exit this crafting menu.\n"
    ]);
}

/////////////////////////////////////////////////////////////////////////////
protected nomask int processSelection(string selection)
{
    int ret = -1;
    if (User)
    {
        ret = (Data[selection]["type"] == "exit");
        if (!ret)
        {
            SubselectorObj = clone_object(sprintf("/lib/modules/crafting/%sSelector.c",
                Data[selection]["selector"]));
            SubselectorObj->setItem(Data[selection]["type"]);
            SubselectorObj->setCraftingItem(Item);
            SubselectorObj->setDetails(Data[selection]["details"]);
            move_object(SubselectorObj, User);
            SubselectorObj->registerEvent(this_object());
            SubselectorObj->initiateSelector(User);
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask void onSelectorCompleted(object caller)
{
    if (User)
    {
        setUpUserForSelection();
        tell_object(User, displayMessage());
    }
    caller->cleanUp();
}

/////////////////////////////////////////////////////////////////////////////
protected nomask int suppressMenuDisplay()
{
    return objectp(SubselectorObj);
}
