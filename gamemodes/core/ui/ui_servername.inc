new Text:NamaServerTD[22],
	Text:ServerClockTD[2],
    Text:ServerLoadScs;

CreateServerNameTD()
{
    ServerLoadScs = TextDrawCreate(-7.000000, -23.000000, "loadsc13:loadsc13");
	TextDrawFont(ServerLoadScs, 4);
	TextDrawLetterSize(ServerLoadScs, 0.600000, 2.000000);
	TextDrawTextSize(ServerLoadScs, 654.500000, 486.000000);
	TextDrawSetOutline(ServerLoadScs, 1);
	TextDrawSetShadow(ServerLoadScs, 0);
	TextDrawAlignment(ServerLoadScs, 1);
	TextDrawColor(ServerLoadScs, -1);
	TextDrawBackgroundColor(ServerLoadScs, 255);
	TextDrawBoxColor(ServerLoadScs, 50);
	TextDrawUseBox(ServerLoadScs, 1);
	TextDrawSetProportional(ServerLoadScs, 1);
	TextDrawSetSelectable(ServerLoadScs, 0); 
    
	NamaServerTD[0] = TextDrawCreate(313.000, 2.000, "/");
	TextDrawLetterSize(NamaServerTD[0], 0.724, 2.299);
	TextDrawTextSize(NamaServerTD[0], 400.000, 17.000);
	TextDrawAlignment(NamaServerTD[0], true);
	TextDrawColor(NamaServerTD[0], -260013825);
	TextDrawSetShadow(NamaServerTD[0], false);
	TextDrawSetOutline(NamaServerTD[0], false);
	TextDrawBackgroundColor(NamaServerTD[0], -1);
	TextDrawFont(NamaServerTD[0], true);
	TextDrawSetProportional(NamaServerTD[0], true);

	NamaServerTD[1] = TextDrawCreate(318.000, 3.000, "\\");
	TextDrawLetterSize(NamaServerTD[1], 0.829, 1.649);
	TextDrawTextSize(NamaServerTD[1], 400.000, 17.000);
	TextDrawAlignment(NamaServerTD[1], true);
	TextDrawColor(NamaServerTD[1], -260013825);
	TextDrawSetShadow(NamaServerTD[1], false);
	TextDrawSetOutline(NamaServerTD[1], false);
	TextDrawBackgroundColor(NamaServerTD[1], -1);
	TextDrawFont(NamaServerTD[1], true);
	TextDrawSetProportional(NamaServerTD[1], true);

	NamaServerTD[2] = TextDrawCreate(324.000, 7.000, "/");
	TextDrawLetterSize(NamaServerTD[2], 0.795, 2.299);
	TextDrawTextSize(NamaServerTD[2], 400.000, 17.000);
	TextDrawAlignment(NamaServerTD[2], true);
	TextDrawColor(NamaServerTD[2], -260013825);
	TextDrawSetShadow(NamaServerTD[2], false);
	TextDrawSetOutline(NamaServerTD[2], false);
	TextDrawBackgroundColor(NamaServerTD[2], -1);
	TextDrawFont(NamaServerTD[2], true);
	TextDrawSetProportional(NamaServerTD[2], true);

	NamaServerTD[3] = TextDrawCreate(319.000, 15.000, "\\");
	TextDrawLetterSize(NamaServerTD[3], 0.774, 1.500);
	TextDrawTextSize(NamaServerTD[3], 400.000, 17.000);
	TextDrawAlignment(NamaServerTD[3], true);
	TextDrawColor(NamaServerTD[3], -260013825);
	TextDrawSetShadow(NamaServerTD[3], false);
	TextDrawSetOutline(NamaServerTD[3], false);
	TextDrawBackgroundColor(NamaServerTD[3], -1);
	TextDrawFont(NamaServerTD[3], true);
	TextDrawSetProportional(NamaServerTD[3], true);

	NamaServerTD[4] = TextDrawCreate(311.000, 2.000, "/");
	TextDrawLetterSize(NamaServerTD[4], 0.724, 2.299);
	TextDrawTextSize(NamaServerTD[4], 400.000, 17.000);
	TextDrawAlignment(NamaServerTD[4], true);
	TextDrawColor(NamaServerTD[4], -260013825);
	TextDrawSetShadow(NamaServerTD[4], false);
	TextDrawSetOutline(NamaServerTD[4], false);
	TextDrawBackgroundColor(NamaServerTD[4], -1);
	TextDrawFont(NamaServerTD[4], true);
	TextDrawSetProportional(NamaServerTD[4], true);

	NamaServerTD[5] = TextDrawCreate(320.000, 16.000, "\\");
	TextDrawLetterSize(NamaServerTD[5], 0.666, 1.350);
	TextDrawTextSize(NamaServerTD[5], 400.000, 17.000);
	TextDrawAlignment(NamaServerTD[5], true);
	TextDrawColor(NamaServerTD[5], -7232257);
	TextDrawSetShadow(NamaServerTD[5], false);
	TextDrawSetOutline(NamaServerTD[5], false);
	TextDrawBackgroundColor(NamaServerTD[5], -1);
	TextDrawFont(NamaServerTD[5], true);
	TextDrawSetProportional(NamaServerTD[5], true);

	NamaServerTD[6] = TextDrawCreate(325.000, 7.000, "/");
	TextDrawLetterSize(NamaServerTD[6], 0.795, 2.299);
	TextDrawTextSize(NamaServerTD[6], 400.000, 17.000);
	TextDrawAlignment(NamaServerTD[6], true);
	TextDrawColor(NamaServerTD[6], -260013825);
	TextDrawSetShadow(NamaServerTD[6], false);
	TextDrawSetOutline(NamaServerTD[6], false);
	TextDrawBackgroundColor(NamaServerTD[6], -1);
	TextDrawFont(NamaServerTD[6], true);
	TextDrawSetProportional(NamaServerTD[6], true);

	NamaServerTD[7] = TextDrawCreate(312.000, 3.000, "/");
	TextDrawLetterSize(NamaServerTD[7], 0.699, 2.149);
	TextDrawTextSize(NamaServerTD[7], 400.000, 17.000);
	TextDrawAlignment(NamaServerTD[7], true);
	TextDrawColor(NamaServerTD[7], -7232257);
	TextDrawSetShadow(NamaServerTD[7], false);
	TextDrawSetOutline(NamaServerTD[7], false);
	TextDrawBackgroundColor(NamaServerTD[7], -1);
	TextDrawFont(NamaServerTD[7], true);
	TextDrawSetProportional(NamaServerTD[7], true);

	NamaServerTD[8] = TextDrawCreate(325.000, 8.000, "/");
	TextDrawLetterSize(NamaServerTD[8], 0.699, 2.149);
	TextDrawTextSize(NamaServerTD[8], 400.000, 17.000);
	TextDrawAlignment(NamaServerTD[8], true);
	TextDrawColor(NamaServerTD[8], -7232257);
	TextDrawSetShadow(NamaServerTD[8], false);
	TextDrawSetOutline(NamaServerTD[8], false);
	TextDrawBackgroundColor(NamaServerTD[8], -1);
	TextDrawFont(NamaServerTD[8], true);
	TextDrawSetProportional(NamaServerTD[8], true);

	NamaServerTD[9] = TextDrawCreate(299.000, 31.000, "T");
	TextDrawLetterSize(NamaServerTD[9], 0.248, 1.399);
	TextDrawTextSize(NamaServerTD[9], -23.500, -24.000);
	TextDrawAlignment(NamaServerTD[9], true);
	TextDrawColor(NamaServerTD[9], -1);
	TextDrawSetShadow(NamaServerTD[9], false);
	TextDrawSetOutline(NamaServerTD[9], false);
	TextDrawBackgroundColor(NamaServerTD[9], 255);
	TextDrawFont(NamaServerTD[9], 2);
	TextDrawSetProportional(NamaServerTD[9], true);

	NamaServerTD[10] = TextDrawCreate(306.000, 31.000, "H");
	TextDrawLetterSize(NamaServerTD[10], 0.248, 1.399);
	TextDrawTextSize(NamaServerTD[10], -23.500, -24.000);
	TextDrawAlignment(NamaServerTD[10], true);
	TextDrawColor(NamaServerTD[10], -1);
	TextDrawSetShadow(NamaServerTD[10], false);
	TextDrawSetOutline(NamaServerTD[10], false);
	TextDrawBackgroundColor(NamaServerTD[10], 255);
	TextDrawFont(NamaServerTD[10], 2);
	TextDrawSetProportional(NamaServerTD[10], true);

	NamaServerTD[11] = TextDrawCreate(315.000, 33.800, "ld_dual:white");
	TextDrawLetterSize(NamaServerTD[11], 0.308, 1.700);
	TextDrawTextSize(NamaServerTD[11], 5.000, 1.500);
	TextDrawAlignment(NamaServerTD[11], true);
	TextDrawColor(NamaServerTD[11], -1);
	TextDrawSetShadow(NamaServerTD[11], false);
	TextDrawSetOutline(NamaServerTD[11], false);
	TextDrawBackgroundColor(NamaServerTD[11], 255);
	TextDrawFont(NamaServerTD[11], 4);
	TextDrawSetProportional(NamaServerTD[11], true);

	NamaServerTD[12] = TextDrawCreate(315.000, 37.500, "ld_dual:white");
	TextDrawLetterSize(NamaServerTD[12], 0.308, 1.700);
	TextDrawTextSize(NamaServerTD[12], 5.000, 1.500);
	TextDrawAlignment(NamaServerTD[12], true);
	TextDrawColor(NamaServerTD[12], -1);
	TextDrawSetShadow(NamaServerTD[12], false);
	TextDrawSetOutline(NamaServerTD[12], false);
	TextDrawBackgroundColor(NamaServerTD[12], 255);
	TextDrawFont(NamaServerTD[12], 4);
	TextDrawSetProportional(NamaServerTD[12], true);

	NamaServerTD[13] = TextDrawCreate(315.000, 41.000, "ld_dual:white");
	TextDrawLetterSize(NamaServerTD[13], 0.308, 1.700);
	TextDrawTextSize(NamaServerTD[13], 5.000, 1.500);
	TextDrawAlignment(NamaServerTD[13], true);
	TextDrawColor(NamaServerTD[13], -1);
	TextDrawSetShadow(NamaServerTD[13], false);
	TextDrawSetOutline(NamaServerTD[13], false);
	TextDrawBackgroundColor(NamaServerTD[13], 255);
	TextDrawFont(NamaServerTD[13], 4);
	TextDrawSetProportional(NamaServerTD[13], true);

	NamaServerTD[14] = TextDrawCreate(319.000, 5.000, "\\");
	TextDrawLetterSize(NamaServerTD[14], 0.666, 1.350);
	TextDrawTextSize(NamaServerTD[14], 400.000, 17.000);
	TextDrawAlignment(NamaServerTD[14], true);
	TextDrawColor(NamaServerTD[14], -7232257);
	TextDrawSetShadow(NamaServerTD[14], false);
	TextDrawSetOutline(NamaServerTD[14], false);
	TextDrawBackgroundColor(NamaServerTD[14], -1);
	TextDrawFont(NamaServerTD[14], true);
	TextDrawSetProportional(NamaServerTD[14], true);

	NamaServerTD[15] = TextDrawCreate(321.000, 46.000, "V");
	TextDrawLetterSize(NamaServerTD[15], 0.248, -1.549);
	TextDrawTextSize(NamaServerTD[15], -34.500, 69.000);
	TextDrawAlignment(NamaServerTD[15], true);
	TextDrawColor(NamaServerTD[15], -1);
	TextDrawSetShadow(NamaServerTD[15], false);
	TextDrawSetOutline(NamaServerTD[15], false);
	TextDrawBackgroundColor(NamaServerTD[15], 255);
	TextDrawFont(NamaServerTD[15], 2);
	TextDrawSetProportional(NamaServerTD[15], true);

	NamaServerTD[16] = TextDrawCreate(324.000, 39.500, "ld_dual:white");
	TextDrawLetterSize(NamaServerTD[16], 0.308, 1.700);
	TextDrawTextSize(NamaServerTD[16], 2.000, 1.500);
	TextDrawAlignment(NamaServerTD[16], true);
	TextDrawColor(NamaServerTD[16], -1);
	TextDrawSetShadow(NamaServerTD[16], false);
	TextDrawSetOutline(NamaServerTD[16], false);
	TextDrawBackgroundColor(NamaServerTD[16], 255);
	TextDrawFont(NamaServerTD[16], 4);
	TextDrawSetProportional(NamaServerTD[16], true);

	NamaServerTD[17] = TextDrawCreate(327.000, 31.000, "T");
	TextDrawLetterSize(NamaServerTD[17], 0.248, 1.399);
	TextDrawTextSize(NamaServerTD[17], -23.500, -24.000);
	TextDrawAlignment(NamaServerTD[17], true);
	TextDrawColor(NamaServerTD[17], -1);
	TextDrawSetShadow(NamaServerTD[17], false);
	TextDrawSetOutline(NamaServerTD[17], false);
	TextDrawBackgroundColor(NamaServerTD[17], 255);
	TextDrawFont(NamaServerTD[17], 2);
	TextDrawSetProportional(NamaServerTD[17], true);

	NamaServerTD[18] = TextDrawCreate(335.000, 33.800, "ld_dual:white");
	TextDrawLetterSize(NamaServerTD[18], 0.308, 1.700);
	TextDrawTextSize(NamaServerTD[18], 5.000, 1.500);
	TextDrawAlignment(NamaServerTD[18], true);
	TextDrawColor(NamaServerTD[18], -1);
	TextDrawSetShadow(NamaServerTD[18], false);
	TextDrawSetOutline(NamaServerTD[18], false);
	TextDrawBackgroundColor(NamaServerTD[18], 255);
	TextDrawFont(NamaServerTD[18], 4);
	TextDrawSetProportional(NamaServerTD[18], true);

	NamaServerTD[19] = TextDrawCreate(335.000, 37.500, "ld_dual:white");
	TextDrawLetterSize(NamaServerTD[19], 0.308, 1.700);
	TextDrawTextSize(NamaServerTD[19], 5.000, 1.500);
	TextDrawAlignment(NamaServerTD[19], true);
	TextDrawColor(NamaServerTD[19], -1);
	TextDrawSetShadow(NamaServerTD[19], false);
	TextDrawSetOutline(NamaServerTD[19], false);
	TextDrawBackgroundColor(NamaServerTD[19], 255);
	TextDrawFont(NamaServerTD[19], 4);
	TextDrawSetProportional(NamaServerTD[19], true);

	NamaServerTD[20] = TextDrawCreate(335.000, 41.000, "ld_dual:white");
	TextDrawLetterSize(NamaServerTD[20], 0.308, 1.700);
	TextDrawTextSize(NamaServerTD[20], 5.000, 1.500);
	TextDrawAlignment(NamaServerTD[20], true);
	TextDrawColor(NamaServerTD[20], -1);
	TextDrawSetShadow(NamaServerTD[20], false);
	TextDrawSetOutline(NamaServerTD[20], false);
	TextDrawBackgroundColor(NamaServerTD[20], 255);
	TextDrawFont(NamaServerTD[20], 4);
	TextDrawSetProportional(NamaServerTD[20], true);

	NamaServerTD[21] = TextDrawCreate(342.000, 31.000, "R");
	TextDrawLetterSize(NamaServerTD[21], 0.278, 1.399);
	TextDrawTextSize(NamaServerTD[21], -23.500, -24.000);
	TextDrawAlignment(NamaServerTD[21], true);
	TextDrawColor(NamaServerTD[21], -1);
	TextDrawSetShadow(NamaServerTD[21], false);
	TextDrawSetOutline(NamaServerTD[21], false);
	TextDrawBackgroundColor(NamaServerTD[21], 255);
	TextDrawFont(NamaServerTD[21], 2);
	TextDrawSetProportional(NamaServerTD[21], true);
    

	ServerClockTD[0] = TextDrawCreate(577.000000, 8.000000, "30 Desember 2025");
	TextDrawFont(ServerClockTD[0], 1);
	TextDrawLetterSize(ServerClockTD[0], 0.266665, 1.299998);
	TextDrawTextSize(ServerClockTD[0], 400.000000, 102.000000);
	TextDrawSetOutline(ServerClockTD[0], 1);
	TextDrawSetShadow(ServerClockTD[0], 0);
	TextDrawAlignment(ServerClockTD[0], 2);
	TextDrawColor(ServerClockTD[0], -1);
	TextDrawBackgroundColor(ServerClockTD[0], 255);
	TextDrawBoxColor(ServerClockTD[0], 50);
	TextDrawUseBox(ServerClockTD[0], 0);
	TextDrawSetProportional(ServerClockTD[0], 1);
	TextDrawSetSelectable(ServerClockTD[0], 0);

	ServerClockTD[1] = TextDrawCreate(579.000000, 20.000000, "23:59:54");
	TextDrawFont(ServerClockTD[1], 1);
	TextDrawLetterSize(ServerClockTD[1], 0.354166, 1.799998);
	TextDrawTextSize(ServerClockTD[1], 400.000000, 72.000000);
	TextDrawSetOutline(ServerClockTD[1], 1);
	TextDrawSetShadow(ServerClockTD[1], 0);
	TextDrawAlignment(ServerClockTD[1], 2);
	TextDrawColor(ServerClockTD[1], -1);
	TextDrawBackgroundColor(ServerClockTD[1], 255);
	TextDrawBoxColor(ServerClockTD[1], 50);
	TextDrawUseBox(ServerClockTD[1], 0);
	TextDrawSetProportional(ServerClockTD[1], 1);
	TextDrawSetSelectable(ServerClockTD[1], 0);
}

ShowServerNameTD(playerid)
{
	for(new x; x < 22; x++)
    {
    	TextDrawShowForPlayer(playerid, NamaServerTD[x]);
	}
}

HideServerNameTD(playerid)
{
    for(new x; x < 22; x++)
    {
        TextDrawHideForPlayer(playerid, NamaServerTD[x]);
    }
}

ShowClockTD(playerid)
{
	TextDrawShowForPlayer(playerid, ServerClockTD[0]);
	TextDrawShowForPlayer(playerid, ServerClockTD[1]);
}

ShowRandomLoadScreen(playerid)
{
    new randsc = random(8);
    
    switch(randsc)
    {
        case 0:
        {
            TextDrawSetString(ServerLoadScs, "loadsc13:loadsc13");
            TextDrawShowForPlayer(playerid, ServerLoadScs);
        }
        case 1:
        {
            TextDrawSetString(ServerLoadScs, "loadsc9:loadsc9");
            TextDrawShowForPlayer(playerid, ServerLoadScs);
        }
        case 2:
        {
            TextDrawSetString(ServerLoadScs, "loadsc8:loadsc8");
            TextDrawShowForPlayer(playerid, ServerLoadScs);
        }
        case 3:
        {
            TextDrawSetString(ServerLoadScs, "loadsc12:loadsc12");
            TextDrawShowForPlayer(playerid, ServerLoadScs);
        }
        case 4:
        {
            TextDrawSetString(ServerLoadScs, "loadsc11:loadsc11");
            TextDrawShowForPlayer(playerid, ServerLoadScs);
        }
        case 5:
        {
            TextDrawSetString(ServerLoadScs, "loadsc7:loadsc7");
            TextDrawShowForPlayer(playerid, ServerLoadScs);
        }
        case 6:
        {
            TextDrawSetString(ServerLoadScs, "loadsc6:loadsc6");
            TextDrawShowForPlayer(playerid, ServerLoadScs);
        }
        case 7:
        {
            TextDrawSetString(ServerLoadScs, "loadsc5:loadsc5");
            TextDrawShowForPlayer(playerid, ServerLoadScs);
        }
    }
}

HideRandomLoadScreen(playerid)
{
    TextDrawHideForPlayer(playerid, ServerLoadScs);
}