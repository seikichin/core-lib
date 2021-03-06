//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addTopic("first conversation", "@S@`Get up, damn it!' @D@says Galadhel through clenched "
        "teeth, the anger - or fear - apparent on her face. @S@`I swear... if "
        "you're dead, ##ActorName##, I will kill you!'");
    addTopicEvent("first conversation", "berenarInterjects");
}
