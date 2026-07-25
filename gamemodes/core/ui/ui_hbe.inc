new Text:HBE[20],
    PlayerText:PHBE[MAX_PLAYERS][10],
    Text:SpeedoTD[19],
    PlayerText:PlayerSpeedoTD[MAX_PLAYERS][3],
    Text:StressTD;

CreateHBETextdraw()
{
	//V1
    HBE[0] = TextDrawCreate(36.500000, 431.000000, "ld_dual:white");
	TextDrawFont(HBE[0], 4);
	TextDrawLetterSize(HBE[0], 0.600000, 2.000000);
	TextDrawTextSize(HBE[0], 27.000000, 1.000000);
	TextDrawSetOutline(HBE[0], 1);
	TextDrawSetShadow(HBE[0], 0);
	TextDrawAlignment(HBE[0], 1);
	TextDrawColor(HBE[0], 0xff91a4ff);
	TextDrawBackgroundColor(HBE[0], 255);
	TextDrawBoxColor(HBE[0], 50);
	TextDrawUseBox(HBE[0], 1);
	TextDrawSetProportional(HBE[0], 1);
	TextDrawSetSelectable(HBE[0], 0);

	HBE[1] = TextDrawCreate(66.000000, 431.000000, "ld_dual:white");
	TextDrawFont(HBE[1], 4);
	TextDrawLetterSize(HBE[1], 0.600000, 2.000000);
	TextDrawTextSize(HBE[1], 1.000000, 14.500000);
	TextDrawSetOutline(HBE[1], 1);
	TextDrawSetShadow(HBE[1], 0);
	TextDrawAlignment(HBE[1], 1);
	TextDrawColor(HBE[1], 0xff91a4ff);
	TextDrawBackgroundColor(HBE[1], 255);
	TextDrawBoxColor(HBE[1], 50);
	TextDrawUseBox(HBE[1], 1);
	TextDrawSetProportional(HBE[1], 1);
	TextDrawSetSelectable(HBE[1], 0);

	HBE[2] = TextDrawCreate(67.000000, 444.500000, "ld_dual:white");	
	TextDrawFont(HBE[2], 4);
	TextDrawLetterSize(HBE[2], 0.600000, 2.000000);
	TextDrawTextSize(HBE[2], 14.000000, 1.000000);
	TextDrawSetOutline(HBE[2], 1);
	TextDrawSetShadow(HBE[2], 0);
	TextDrawAlignment(HBE[2], 1);
	TextDrawColor(HBE[2], 0xff91a4ff);
	TextDrawBackgroundColor(HBE[2], 255);
	TextDrawBoxColor(HBE[2], 50);
	TextDrawUseBox(HBE[2], 1);
	TextDrawSetProportional(HBE[2], 1);
	TextDrawSetSelectable(HBE[2], 0);

	HBE[3] = TextDrawCreate(67.000000, 431.000000, "ld_dual:white");
	TextDrawFont(HBE[3], 4);
	TextDrawLetterSize(HBE[3], 0.600000, 2.000000);
	TextDrawTextSize(HBE[3], 14.000000, 1.000000);
	TextDrawSetOutline(HBE[3], 1);
	TextDrawSetShadow(HBE[3], 0);
	TextDrawAlignment(HBE[3], 1);
	TextDrawColor(HBE[3], 0xff91a4ff);
	TextDrawBackgroundColor(HBE[3], 255);
	TextDrawBoxColor(HBE[3], 50);
	TextDrawUseBox(HBE[3], 1);
	TextDrawSetProportional(HBE[3], 1);
	TextDrawSetSelectable(HBE[3], 0);

	HBE[4] = TextDrawCreate(81.000000, 431.000000, "ld_dual:white");
	TextDrawFont(HBE[4], 4);
	TextDrawLetterSize(HBE[4], 0.600000, 2.000000);
	TextDrawTextSize(HBE[4], 1.000000, 14.500000);
	TextDrawSetOutline(HBE[4], 1);
	TextDrawSetShadow(HBE[4], 0);
	TextDrawAlignment(HBE[4], 1);
	TextDrawColor(HBE[4], 0xff91a4ff);
	TextDrawBackgroundColor(HBE[4], 255);
	TextDrawBoxColor(HBE[4], 50);
	TextDrawUseBox(HBE[4], 1);
	TextDrawSetProportional(HBE[4], 1);
	TextDrawSetSelectable(HBE[4], 0);

	HBE[5] = TextDrawCreate(6.000000, 431.000000, "ld_dual:white");
	TextDrawFont(HBE[5], 4);
	TextDrawLetterSize(HBE[5], 0.600000, 2.000000);
	TextDrawTextSize(HBE[5], 27.000000, 1.000000);
	TextDrawSetOutline(HBE[5], 1);
	TextDrawSetShadow(HBE[5], 0);
	TextDrawAlignment(HBE[5], 1);
	TextDrawColor(HBE[5], 0xff91a4ff);
	TextDrawBackgroundColor(HBE[5], 255);
	TextDrawBoxColor(HBE[5], 50);
	TextDrawUseBox(HBE[5], 1);
	TextDrawSetProportional(HBE[5], 1);
	TextDrawSetSelectable(HBE[5], 0);

	HBE[6] = TextDrawCreate(6.000000, 444.500000, "ld_dual:white");
	TextDrawFont(HBE[6], 4);
	TextDrawLetterSize(HBE[6], 0.600000, 2.000000);
	TextDrawTextSize(HBE[6], 27.000000, 1.000000);
	TextDrawSetOutline(HBE[6], 1);
	TextDrawSetShadow(HBE[6], 0);
	TextDrawAlignment(HBE[6], 1);
	TextDrawColor(HBE[6], 0xff91a4ff);
	TextDrawBackgroundColor(HBE[6], 255);
	TextDrawBoxColor(HBE[6], 50);
	TextDrawUseBox(HBE[6], 1);
	TextDrawSetProportional(HBE[6], 1);
	TextDrawSetSelectable(HBE[6], 0);

	HBE[7] = TextDrawCreate(33.000000, 431.000000, "ld_dual:white");
	TextDrawFont(HBE[7], 4);
	TextDrawLetterSize(HBE[7], 0.600000, 2.000000);
	TextDrawTextSize(HBE[7], 1.000000, 14.500000);
	TextDrawSetOutline(HBE[7], 1);
	TextDrawSetShadow(HBE[7], 0);
	TextDrawAlignment(HBE[7], 1);
	TextDrawColor(HBE[7], 0xff91a4ff);
	TextDrawBackgroundColor(HBE[7], 255);
	TextDrawBoxColor(HBE[7], 50);
	TextDrawUseBox(HBE[7], 1);
	TextDrawSetProportional(HBE[7], 1);
	TextDrawSetSelectable(HBE[7], 0);

	HBE[8] = TextDrawCreate(5.000000, 431.000000, "ld_dual:white");
	TextDrawFont(HBE[8], 4);
	TextDrawLetterSize(HBE[8], 0.600000, 2.000000);
	TextDrawTextSize(HBE[8], 1.000000, 14.500000);
	TextDrawSetOutline(HBE[8], 1);
	TextDrawSetShadow(HBE[8], 0);
	TextDrawAlignment(HBE[8], 1);
	TextDrawColor(HBE[8], 0xff91a4ff);
	TextDrawBackgroundColor(HBE[8], 255);
	TextDrawBoxColor(HBE[8], 50);
	TextDrawUseBox(HBE[8], 1);
	TextDrawSetProportional(HBE[8], 1);
	TextDrawSetSelectable(HBE[8], 0);

	HBE[9] = TextDrawCreate(36.500000, 444.500000, "ld_dual:white");
	TextDrawFont(HBE[9], 4);
	TextDrawLetterSize(HBE[9], 0.600000, 2.000000);
	TextDrawTextSize(HBE[9], 27.000000, 1.000000);
	TextDrawSetOutline(HBE[9], 1);
	TextDrawSetShadow(HBE[9], 0);
	TextDrawAlignment(HBE[9], 1);
	TextDrawColor(HBE[9], 0xff91a4ff);
	TextDrawBackgroundColor(HBE[9], 255);
	TextDrawBoxColor(HBE[9], 50);
	TextDrawUseBox(HBE[9], 1);
	TextDrawSetProportional(HBE[9], 1);
	TextDrawSetSelectable(HBE[9], 0);

	HBE[10] = TextDrawCreate(35.500000, 431.000000, "ld_dual:white");
	TextDrawFont(HBE[10], 4);
	TextDrawLetterSize(HBE[10], 0.600000, 2.000000);
	TextDrawTextSize(HBE[10], 1.000000, 14.500000);
	TextDrawSetOutline(HBE[10], 1);
	TextDrawSetShadow(HBE[10], 0);
	TextDrawAlignment(HBE[10], 1);
	TextDrawColor(HBE[10], 0xff91a4ff);
	TextDrawBackgroundColor(HBE[10], 255);
	TextDrawBoxColor(HBE[10], 50);
	TextDrawUseBox(HBE[10], 1);
	TextDrawSetProportional(HBE[10], 1);
	TextDrawSetSelectable(HBE[10], 0);

	HBE[11] = TextDrawCreate(63.500000, 431.000000, "ld_dual:white");
	TextDrawFont(HBE[11], 4);
	TextDrawLetterSize(HBE[11], 0.600000, 2.000000);
	TextDrawTextSize(HBE[11], 1.000000, 14.500000);
	TextDrawSetOutline(HBE[11], 1);
	TextDrawSetShadow(HBE[11], 0);
	TextDrawAlignment(HBE[11], 1);
	TextDrawColor(HBE[11], 0xff91a4ff);
	TextDrawBackgroundColor(HBE[11], 255);
	TextDrawBoxColor(HBE[11], 50);
	TextDrawUseBox(HBE[11], 1);
	TextDrawSetProportional(HBE[11], 1);
	TextDrawSetSelectable(HBE[11], 0);

	HBE[12] = TextDrawCreate(83.500000, 431.000000, "ld_dual:white");
	TextDrawFont(HBE[12], 4);
	TextDrawLetterSize(HBE[12], 0.600000, 2.000000);
	TextDrawTextSize(HBE[12], 1.000000, 14.500000);
	TextDrawSetOutline(HBE[12], 1);
	TextDrawSetShadow(HBE[12], 0);
	TextDrawAlignment(HBE[12], 1);
	TextDrawColor(HBE[12], 0xff91a4ff);
	TextDrawBackgroundColor(HBE[12], 255);
	TextDrawBoxColor(HBE[12], 50);
	TextDrawUseBox(HBE[12], 1);
	TextDrawSetProportional(HBE[12], 1);
	TextDrawSetSelectable(HBE[12], 0);

	HBE[13] = TextDrawCreate(84.500000, 431.000000, "ld_dual:white");
	TextDrawFont(HBE[13], 4);
	TextDrawLetterSize(HBE[13], 0.600000, 2.000000);
	TextDrawTextSize(HBE[13], 14.000000, 1.000000);
	TextDrawSetOutline(HBE[13], 1);
	TextDrawSetShadow(HBE[13], 0);
	TextDrawAlignment(HBE[13], 1);
	TextDrawColor(HBE[13], 0xff91a4ff);
	TextDrawBackgroundColor(HBE[13], 255);
	TextDrawBoxColor(HBE[13], 50);
	TextDrawUseBox(HBE[13], 1);
	TextDrawSetProportional(HBE[13], 1);
	TextDrawSetSelectable(HBE[13], 0);

	HBE[14] = TextDrawCreate(84.500000, 444.500000, "ld_dual:white");
	TextDrawFont(HBE[14], 4);
	TextDrawLetterSize(HBE[14], 0.600000, 2.000000);
	TextDrawTextSize(HBE[14], 14.000000, 1.000000);
	TextDrawSetOutline(HBE[14], 1);
	TextDrawSetShadow(HBE[14], 0);
	TextDrawAlignment(HBE[14], 1);
	TextDrawColor(HBE[14], 0xff91a4ff);
	TextDrawBackgroundColor(HBE[14], 255);
	TextDrawBoxColor(HBE[14], 50);
	TextDrawUseBox(HBE[14], 1);
	TextDrawSetProportional(HBE[14], 1);
	TextDrawSetSelectable(HBE[14], 0);

	HBE[15] = TextDrawCreate(98.500000, 431.000000, "ld_dual:white");
	TextDrawFont(HBE[15], 4);
	TextDrawLetterSize(HBE[15], 0.600000, 2.000000);
	TextDrawTextSize(HBE[15], 1.000000, 14.500000);
	TextDrawSetOutline(HBE[15], 1);
	TextDrawSetShadow(HBE[15], 0);
	TextDrawAlignment(HBE[15], 1);
	TextDrawColor(HBE[15], 0xff91a4ff);
	TextDrawBackgroundColor(HBE[15], 255);
	TextDrawBoxColor(HBE[15], 50);
	TextDrawUseBox(HBE[15], 1);
	TextDrawSetProportional(HBE[15], 1);
	TextDrawSetSelectable(HBE[15], 0);

	HBE[16] = TextDrawCreate(101.000000, 431.000000, "ld_dual:white");
	TextDrawFont(HBE[16], 4);
	TextDrawLetterSize(HBE[16], 0.600000, 2.000000);
	TextDrawTextSize(HBE[16], 1.000000, 14.500000);
	TextDrawSetOutline(HBE[16], 1);
	TextDrawSetShadow(HBE[16], 0);
	TextDrawAlignment(HBE[16], 1);
	TextDrawColor(HBE[16], 0xff91a4ff);
	TextDrawBackgroundColor(HBE[16], 255);
	TextDrawBoxColor(HBE[16], 50);
	TextDrawUseBox(HBE[16], 1);
	TextDrawSetProportional(HBE[16], 1);
	TextDrawSetSelectable(HBE[16], 0);

	HBE[17] = TextDrawCreate(102.000000, 431.000000, "ld_dual:white");
	TextDrawFont(HBE[17], 4);
	TextDrawLetterSize(HBE[17], 0.600000, 2.000000);
	TextDrawTextSize(HBE[17], 14.000000, 1.000000);
	TextDrawSetOutline(HBE[17], 1);
	TextDrawSetShadow(HBE[17], 0);
	TextDrawAlignment(HBE[17], 1);
	TextDrawColor(HBE[17], 0xff91a4ff);
	TextDrawBackgroundColor(HBE[17], 255);
	TextDrawBoxColor(HBE[17], 50);
	TextDrawUseBox(HBE[17], 1);
	TextDrawSetProportional(HBE[17], 1);
	TextDrawSetSelectable(HBE[17], 0);

	HBE[18] = TextDrawCreate(102.000000, 444.500000, "ld_dual:white");
	TextDrawFont(HBE[18], 4);
	TextDrawLetterSize(HBE[18], 0.600000, 2.000000);
	TextDrawTextSize(HBE[18], 14.000000, 1.000000);
	TextDrawSetOutline(HBE[18], 1);
	TextDrawSetShadow(HBE[18], 0);
	TextDrawAlignment(HBE[18], 1);
	TextDrawColor(HBE[18], 0xff91a4ff);
	TextDrawBackgroundColor(HBE[18], 255);
	TextDrawBoxColor(HBE[18], 50);
	TextDrawUseBox(HBE[18], 1);
	TextDrawSetProportional(HBE[18], 1);
	TextDrawSetSelectable(HBE[18], 0);

	HBE[19] = TextDrawCreate(116.000000, 431.000000, "ld_dual:white");
	TextDrawFont(HBE[19], 4);
	TextDrawLetterSize(HBE[19], 0.600000, 2.000000);
	TextDrawTextSize(HBE[19], 1.000000, 14.500000);
	TextDrawSetOutline(HBE[19], 1);
	TextDrawSetShadow(HBE[19], 0);
	TextDrawAlignment(HBE[19], 1);
	TextDrawColor(HBE[19], 0xff91a4ff);
	TextDrawBackgroundColor(HBE[19], 255);
	TextDrawBoxColor(HBE[19], 50);
	TextDrawUseBox(HBE[19], 1);
	TextDrawSetProportional(HBE[19], 1);
	TextDrawSetSelectable(HBE[19], 0);
}

CreateHBEProgressBarTD(playerid)
{
	//v1
    PHBE[playerid][0] = CreatePlayerTextDraw(playerid, 6.000000, 432.000000, "ld_dual:white"); //darah
	PlayerTextDrawFont(playerid, PHBE[playerid][0], 4);
	PlayerTextDrawLetterSize(playerid, PHBE[playerid][0], 0.600000, 2.000000);
	PlayerTextDrawTextSize(playerid, PHBE[playerid][0], 27.000000, 12.500000);
	PlayerTextDrawSetOutline(playerid, PHBE[playerid][0], 1);
	PlayerTextDrawSetShadow(playerid, PHBE[playerid][0], 0);
	PlayerTextDrawAlignment(playerid, PHBE[playerid][0], 1);
	PlayerTextDrawColor(playerid, PHBE[playerid][0], -1358954241);
	PlayerTextDrawBackgroundColor(playerid, PHBE[playerid][0], 255);
	PlayerTextDrawBoxColor(playerid, PHBE[playerid][0], 50);
	PlayerTextDrawUseBox(playerid, PHBE[playerid][0], 1);
	PlayerTextDrawSetProportional(playerid, PHBE[playerid][0], 1);
	PlayerTextDrawSetSelectable(playerid, PHBE[playerid][0], 0);

	PHBE[playerid][1] = CreatePlayerTextDraw(playerid, 36.500000, 432.000000, "ld_dual:white"); //armor
	PlayerTextDrawFont(playerid, PHBE[playerid][1], 4);
	PlayerTextDrawLetterSize(playerid, PHBE[playerid][1], 0.600000, 2.000000);
	PlayerTextDrawTextSize(playerid, PHBE[playerid][1], 27.000000, 12.500000);
	PlayerTextDrawSetOutline(playerid, PHBE[playerid][1], 0);
	PlayerTextDrawSetShadow(playerid, PHBE[playerid][1], 0);
	PlayerTextDrawAlignment(playerid, PHBE[playerid][1], 1);
	PlayerTextDrawColor(playerid, PHBE[playerid][1], 255);
	PlayerTextDrawBackgroundColor(playerid, PHBE[playerid][1], 255);
	PlayerTextDrawBoxColor(playerid, PHBE[playerid][1], 50);
	PlayerTextDrawUseBox(playerid, PHBE[playerid][1], 1);
	PlayerTextDrawSetProportional(playerid, PHBE[playerid][1], 1);
	PlayerTextDrawSetSelectable(playerid, PHBE[playerid][1], 0);
	
	PHBE[playerid][2] = CreatePlayerTextDraw(playerid, 67.000000, 444.500000, "ld_dual:white"); //makan
	PlayerTextDrawFont(playerid, PHBE[playerid][2], 4);
	PlayerTextDrawLetterSize(playerid, PHBE[playerid][2], 0.600000, 2.000000);
	PlayerTextDrawTextSize(playerid, PHBE[playerid][2], 14.000000, -12.500000);
	PlayerTextDrawSetOutline(playerid, PHBE[playerid][2], 1);
	PlayerTextDrawSetShadow(playerid, PHBE[playerid][2], 0);
	PlayerTextDrawAlignment(playerid, PHBE[playerid][2], 1);
	PlayerTextDrawColor(playerid, PHBE[playerid][2], -1133968897);
	PlayerTextDrawBackgroundColor(playerid, PHBE[playerid][2], 255);
	PlayerTextDrawBoxColor(playerid, PHBE[playerid][2], 50);
	PlayerTextDrawUseBox(playerid, PHBE[playerid][2], 1);
	PlayerTextDrawSetProportional(playerid, PHBE[playerid][2], 1);
	PlayerTextDrawSetSelectable(playerid, PHBE[playerid][2], 0);
	
	PHBE[playerid][3] = CreatePlayerTextDraw(playerid, 84.500000, 444.500000, "ld_dual:white"); //minum
	PlayerTextDrawFont(playerid, PHBE[playerid][3], 4);
	PlayerTextDrawLetterSize(playerid, PHBE[playerid][3], 0.600000, 2.000000);
	PlayerTextDrawTextSize(playerid, PHBE[playerid][3], 14.000000, -12.500000);
	PlayerTextDrawSetOutline(playerid, PHBE[playerid][3], 1);
	PlayerTextDrawSetShadow(playerid, PHBE[playerid][3], 0);
	PlayerTextDrawAlignment(playerid, PHBE[playerid][3], 1);
	PlayerTextDrawColor(playerid, PHBE[playerid][3], 1296825855);
	PlayerTextDrawBackgroundColor(playerid, PHBE[playerid][3], 255);
	PlayerTextDrawBoxColor(playerid, PHBE[playerid][3], 50);
	PlayerTextDrawUseBox(playerid, PHBE[playerid][3], 1);
	PlayerTextDrawSetProportional(playerid, PHBE[playerid][3], 1);
	PlayerTextDrawSetSelectable(playerid, PHBE[playerid][3], 0);

	PHBE[playerid][4] = CreatePlayerTextDraw(playerid, 102.000000, 444.500000, "ld_dual:white"); //stress
	PlayerTextDrawFont(playerid, PHBE[playerid][4], 4);
	PlayerTextDrawLetterSize(playerid, PHBE[playerid][4], 0.600000, 2.000000);
	PlayerTextDrawTextSize(playerid, PHBE[playerid][4], 14.000000, -12.500000);
	PlayerTextDrawSetOutline(playerid, PHBE[playerid][4], 1);
	PlayerTextDrawSetShadow(playerid, PHBE[playerid][4], 0);
	PlayerTextDrawAlignment(playerid, PHBE[playerid][4], 1);
	PlayerTextDrawColor(playerid, PHBE[playerid][4], -420462081);
	PlayerTextDrawBackgroundColor(playerid, PHBE[playerid][4], 255);
	PlayerTextDrawBoxColor(playerid, PHBE[playerid][4], 50);
	PlayerTextDrawUseBox(playerid, PHBE[playerid][4], 1);
	PlayerTextDrawSetProportional(playerid, PHBE[playerid][4], 1);
	PlayerTextDrawSetSelectable(playerid, PHBE[playerid][4], 0);

	PHBE[playerid][5] = CreatePlayerTextDraw(playerid, 10.000000, 434.500000, "HUD:radar_girlfriend");
	PlayerTextDrawFont(playerid, PHBE[playerid][5], 4);
	PlayerTextDrawLetterSize(playerid, PHBE[playerid][5], 0.600000, 2.000000);
	PlayerTextDrawTextSize(playerid, PHBE[playerid][5], 7.500000, 8.000000);
	PlayerTextDrawSetOutline(playerid, PHBE[playerid][5], 1);
	PlayerTextDrawSetShadow(playerid, PHBE[playerid][5], 0);
	PlayerTextDrawAlignment(playerid, PHBE[playerid][5], 1);
	PlayerTextDrawColor(playerid, PHBE[playerid][5], -1);
	PlayerTextDrawBackgroundColor(playerid, PHBE[playerid][5], 255);
	PlayerTextDrawBoxColor(playerid, PHBE[playerid][5], 50);
	PlayerTextDrawUseBox(playerid, PHBE[playerid][5], 1);
	PlayerTextDrawSetProportional(playerid, PHBE[playerid][5], 1);
	PlayerTextDrawSetSelectable(playerid, PHBE[playerid][5], 0);

	PHBE[playerid][6] = CreatePlayerTextDraw(playerid, 40.500000, 434.500000, "HUD:radar_tshirt");
	PlayerTextDrawFont(playerid, PHBE[playerid][6], 4);
	PlayerTextDrawLetterSize(playerid, PHBE[playerid][6], 0.600000, 2.000000);
	PlayerTextDrawTextSize(playerid, PHBE[playerid][6], 7.500000, 8.000000);
	PlayerTextDrawSetOutline(playerid, PHBE[playerid][6], 1);
	PlayerTextDrawSetShadow(playerid, PHBE[playerid][6], 0);
	PlayerTextDrawAlignment(playerid, PHBE[playerid][6], 1);
	PlayerTextDrawColor(playerid, PHBE[playerid][6], -1);
	PlayerTextDrawBackgroundColor(playerid, PHBE[playerid][6], 255);
	PlayerTextDrawBoxColor(playerid, PHBE[playerid][6], 50);
	PlayerTextDrawUseBox(playerid, PHBE[playerid][6], 1);
	PlayerTextDrawSetProportional(playerid, PHBE[playerid][6], 1);
	PlayerTextDrawSetSelectable(playerid, PHBE[playerid][6], 0);

	PHBE[playerid][7] = CreatePlayerTextDraw(playerid, 70.199996, 434.500000, "HUD:radar_pizza");
	PlayerTextDrawFont(playerid, PHBE[playerid][7], 4);
	PlayerTextDrawLetterSize(playerid, PHBE[playerid][7], 0.600000, 2.000000);
	PlayerTextDrawTextSize(playerid, PHBE[playerid][7], 7.500000, 8.000000);
	PlayerTextDrawSetOutline(playerid, PHBE[playerid][7], 1);
	PlayerTextDrawSetShadow(playerid, PHBE[playerid][7], 0);
	PlayerTextDrawAlignment(playerid, PHBE[playerid][7], 1);
	PlayerTextDrawColor(playerid, PHBE[playerid][7], -1);
	PlayerTextDrawBackgroundColor(playerid, PHBE[playerid][7], 255);
	PlayerTextDrawBoxColor(playerid, PHBE[playerid][7], 50);
	PlayerTextDrawUseBox(playerid, PHBE[playerid][7], 1);
	PlayerTextDrawSetProportional(playerid, PHBE[playerid][7], 1);
	PlayerTextDrawSetSelectable(playerid, PHBE[playerid][7], 0);

	PHBE[playerid][8] = CreatePlayerTextDraw(playerid, 87.800003, 434.500000, "HUD:radar_centre");
	PlayerTextDrawFont(playerid, PHBE[playerid][8], 4);
	PlayerTextDrawLetterSize(playerid, PHBE[playerid][8], 0.600000, 2.000000);
	PlayerTextDrawTextSize(playerid, PHBE[playerid][8], 7.500000, 8.000000);
	PlayerTextDrawSetOutline(playerid, PHBE[playerid][8], 1);
	PlayerTextDrawSetShadow(playerid, PHBE[playerid][8], 0);
	PlayerTextDrawAlignment(playerid, PHBE[playerid][8], 1);
	PlayerTextDrawColor(playerid, PHBE[playerid][8], -1);
	PlayerTextDrawBackgroundColor(playerid, PHBE[playerid][8], 255);
	PlayerTextDrawBoxColor(playerid, PHBE[playerid][8], 50);
	PlayerTextDrawUseBox(playerid, PHBE[playerid][8], 1);
	PlayerTextDrawSetProportional(playerid, PHBE[playerid][8], 1);
	PlayerTextDrawSetSelectable(playerid, PHBE[playerid][8], 0);

	PHBE[playerid][9] = CreatePlayerTextDraw(playerid, 105.500000, 434.000000, "HUD:radar_waypoint");
	PlayerTextDrawFont(playerid, PHBE[playerid][9], 4);
	PlayerTextDrawLetterSize(playerid, PHBE[playerid][9], 0.600000, 2.000000);
	PlayerTextDrawTextSize(playerid, PHBE[playerid][9], 7.500000, 8.000000);
	PlayerTextDrawSetOutline(playerid, PHBE[playerid][9], 1);
	PlayerTextDrawSetShadow(playerid, PHBE[playerid][9], 0);
	PlayerTextDrawAlignment(playerid, PHBE[playerid][9], 1);
	PlayerTextDrawColor(playerid, PHBE[playerid][9], -1);
	PlayerTextDrawBackgroundColor(playerid, PHBE[playerid][9], 255);
	PlayerTextDrawBoxColor(playerid, PHBE[playerid][9], 50);
	PlayerTextDrawUseBox(playerid, PHBE[playerid][9], 1);
	PlayerTextDrawSetProportional(playerid, PHBE[playerid][9], 1);
	PlayerTextDrawSetSelectable(playerid, PHBE[playerid][9], 0);
}

CreateSpeedoTD()
{
    SpeedoTD[0] = TextDrawCreate(116.500, 367.000, "LD_BEAT:chit");
	TextDrawTextSize(SpeedoTD[0], 33.000, 41.000);
	TextDrawAlignment(SpeedoTD[0], 1);
	TextDrawColor(SpeedoTD[0], -1);
	TextDrawSetShadow(SpeedoTD[0], 0);
	TextDrawSetOutline(SpeedoTD[0], 0);
	TextDrawBackgroundColor(SpeedoTD[0], 255);
	TextDrawFont(SpeedoTD[0], 4);
	TextDrawSetProportional(SpeedoTD[0], 1);

	SpeedoTD[1] = TextDrawCreate(119.000, 369.500, "LD_BEAT:chit");
	TextDrawTextSize(SpeedoTD[1], 28.000, 36.000);
	TextDrawAlignment(SpeedoTD[1], 1);
	TextDrawColor(SpeedoTD[1], 255);
	TextDrawSetShadow(SpeedoTD[1], 0);
	TextDrawSetOutline(SpeedoTD[1], 0);
	TextDrawBackgroundColor(SpeedoTD[1], 255);
	TextDrawFont(SpeedoTD[1], 4);
	TextDrawSetProportional(SpeedoTD[1], 1);

	SpeedoTD[2] = TextDrawCreate(124.500, 394.299, "LD_BEAT:chit");
	TextDrawTextSize(SpeedoTD[2], 16.500, 8.299);
	TextDrawAlignment(SpeedoTD[2], 1);
	TextDrawColor(SpeedoTD[2], 255);
	TextDrawSetShadow(SpeedoTD[2], 0);
	TextDrawSetOutline(SpeedoTD[2], 0);
	TextDrawBackgroundColor(SpeedoTD[2], 255);
	TextDrawFont(SpeedoTD[2], 4);
	TextDrawSetProportional(SpeedoTD[2], 1);

	SpeedoTD[3] = TextDrawCreate(126.000, 391.500, "/");
	TextDrawLetterSize(SpeedoTD[3], 0.338, 0.799);
	TextDrawAlignment(SpeedoTD[3], 1);
	TextDrawColor(SpeedoTD[3], 255);
	TextDrawSetShadow(SpeedoTD[3], 1);
	TextDrawSetOutline(SpeedoTD[3], 1);
	TextDrawBackgroundColor(SpeedoTD[3], 0);
	TextDrawFont(SpeedoTD[3], 1);
	TextDrawSetProportional(SpeedoTD[3], 1);

	SpeedoTD[4] = TextDrawCreate(126.000, 391.500, "/");
	TextDrawLetterSize(SpeedoTD[4], 0.338, 0.799);
	TextDrawAlignment(SpeedoTD[4], 1);
	TextDrawColor(SpeedoTD[4], 255);
	TextDrawSetShadow(SpeedoTD[4], 1);
	TextDrawSetOutline(SpeedoTD[4], 1);
	TextDrawBackgroundColor(SpeedoTD[4], 0);
	TextDrawFont(SpeedoTD[4], 1);
	TextDrawSetProportional(SpeedoTD[4], 1);

	SpeedoTD[5] = TextDrawCreate(136.000, 386.000, "LD_BUM:blkdot");
	TextDrawTextSize(SpeedoTD[5], 8.000, 4.000);
	TextDrawAlignment(SpeedoTD[5], 1);
	TextDrawColor(SpeedoTD[5], 255);
	TextDrawSetShadow(SpeedoTD[5], 0);
	TextDrawSetOutline(SpeedoTD[5], 0);
	TextDrawBackgroundColor(SpeedoTD[5], 255);
	TextDrawFont(SpeedoTD[5], 4);
	TextDrawSetProportional(SpeedoTD[5], 1);

	SpeedoTD[6] = TextDrawCreate(132.500, 384.000, "LD_BEAT:chit");
	TextDrawTextSize(SpeedoTD[6], 22.000, 26.000);
	TextDrawAlignment(SpeedoTD[6], 1);
	TextDrawColor(SpeedoTD[6], -1);
	TextDrawSetShadow(SpeedoTD[6], 0);
	TextDrawSetOutline(SpeedoTD[6], 0);
	TextDrawBackgroundColor(SpeedoTD[6], 255);
	TextDrawFont(SpeedoTD[6], 4);
	TextDrawSetProportional(SpeedoTD[6], 1);

	SpeedoTD[7] = TextDrawCreate(134.500, 386.000, "LD_BEAT:chit");
	TextDrawTextSize(SpeedoTD[7], 18.000, 22.000);
	TextDrawAlignment(SpeedoTD[7], 1);
	TextDrawColor(SpeedoTD[7], 255);
	TextDrawSetShadow(SpeedoTD[7], 0);
	TextDrawSetOutline(SpeedoTD[7], 0);
	TextDrawBackgroundColor(SpeedoTD[7], 255);
	TextDrawFont(SpeedoTD[7], 4);
	TextDrawSetProportional(SpeedoTD[7], 1);

	SpeedoTD[8] = TextDrawCreate(135.500, 398.000, "LD_BUM:blkdot");
	TextDrawTextSize(SpeedoTD[8], 15.000, 2.500);
	TextDrawAlignment(SpeedoTD[8], 1);
	TextDrawColor(SpeedoTD[8], 255);
	TextDrawSetShadow(SpeedoTD[8], 0);
	TextDrawSetOutline(SpeedoTD[8], 0);
	TextDrawBackgroundColor(SpeedoTD[8], 255);
	TextDrawFont(SpeedoTD[8], 4);
	TextDrawSetProportional(SpeedoTD[8], 1);

	SpeedoTD[9] = TextDrawCreate(132.500, 388.500, "KMH");
	TextDrawLetterSize(SpeedoTD[9], 0.119, 0.540);
	TextDrawAlignment(SpeedoTD[9], 2);
	TextDrawColor(SpeedoTD[9], -1);
	TextDrawSetShadow(SpeedoTD[9], 1);
	TextDrawSetOutline(SpeedoTD[9], 1);
	TextDrawBackgroundColor(SpeedoTD[9], 0);
	TextDrawFont(SpeedoTD[9], 1);
	TextDrawSetProportional(SpeedoTD[9], 1);

	SpeedoTD[10] = TextDrawCreate(138.800, 396.500, "LD_BEAT:chit");
	TextDrawTextSize(SpeedoTD[10], 13.500, 9.300);
	TextDrawAlignment(SpeedoTD[10], 1);
	TextDrawColor(SpeedoTD[10], 255);
	TextDrawSetShadow(SpeedoTD[10], 0);
	TextDrawSetOutline(SpeedoTD[10], 0);
	TextDrawBackgroundColor(SpeedoTD[10], 255);
	TextDrawFont(SpeedoTD[10], 4);
	TextDrawSetProportional(SpeedoTD[10], 1);

	SpeedoTD[11] = TextDrawCreate(134.800, 396.500, "LD_BEAT:chit");
	TextDrawTextSize(SpeedoTD[11], 13.500, 9.300);
	TextDrawAlignment(SpeedoTD[11], 1);
	TextDrawColor(SpeedoTD[11], 255);
	TextDrawSetShadow(SpeedoTD[11], 0);
	TextDrawSetOutline(SpeedoTD[11], 0);
	TextDrawBackgroundColor(SpeedoTD[11], 255);
	TextDrawFont(SpeedoTD[11], 4);
	TextDrawSetProportional(SpeedoTD[11], 1);

	SpeedoTD[12] = TextDrawCreate(135.800, 398.500, "LD_BEAT:chit");
	TextDrawTextSize(SpeedoTD[12], 15.500, 9.000);
	TextDrawAlignment(SpeedoTD[12], 1);
	TextDrawColor(SpeedoTD[12], 255);
	TextDrawSetShadow(SpeedoTD[12], 0);
	TextDrawSetOutline(SpeedoTD[12], 0);
	TextDrawBackgroundColor(SpeedoTD[12], 255);
	TextDrawFont(SpeedoTD[12], 4);
	TextDrawSetProportional(SpeedoTD[12], 1);

	SpeedoTD[13] = TextDrawCreate(154.000, 405.299, "LD_BUM:blkdot");
	TextDrawTextSize(SpeedoTD[13], 4.000, -15.000);
	TextDrawAlignment(SpeedoTD[13], 1);
	TextDrawColor(SpeedoTD[13], 255);
	TextDrawSetShadow(SpeedoTD[13], 0);
	TextDrawSetOutline(SpeedoTD[13], 0);
	TextDrawBackgroundColor(SpeedoTD[13], 255);
	TextDrawFont(SpeedoTD[13], 4);
	TextDrawSetProportional(SpeedoTD[13], 1);

	SpeedoTD[14] = TextDrawCreate(141.299, 393.399, "LD_BUM:blkdot");
	TextDrawTextSize(SpeedoTD[14], 4.000, 7.000);
	TextDrawAlignment(SpeedoTD[14], 1);
	TextDrawColor(SpeedoTD[14], -1);
	TextDrawSetShadow(SpeedoTD[14], 0);
	TextDrawSetOutline(SpeedoTD[14], 0);
	TextDrawBackgroundColor(SpeedoTD[14], 255);
	TextDrawFont(SpeedoTD[14], 4);
	TextDrawSetProportional(SpeedoTD[14], 1);

	SpeedoTD[15] = TextDrawCreate(140.799, 400.399, "LD_BUM:blkdot");
	TextDrawTextSize(SpeedoTD[15], 5.500, 0.500);
	TextDrawAlignment(SpeedoTD[15], 1);
	TextDrawColor(SpeedoTD[15], -1);
	TextDrawSetShadow(SpeedoTD[15], 0);
	TextDrawSetOutline(SpeedoTD[15], 0);
	TextDrawBackgroundColor(SpeedoTD[15], 255);
	TextDrawFont(SpeedoTD[15], 4);
	TextDrawSetProportional(SpeedoTD[15], 1);

	SpeedoTD[16] = TextDrawCreate(141.799, 394.399, "LD_BUM:blkdot");
	TextDrawTextSize(SpeedoTD[16], 3.000, 2.500);
	TextDrawAlignment(SpeedoTD[16], 1);
	TextDrawColor(SpeedoTD[16], 255);
	TextDrawSetShadow(SpeedoTD[16], 0);
	TextDrawSetOutline(SpeedoTD[16], 0);
	TextDrawBackgroundColor(SpeedoTD[16], 255);
	TextDrawFont(SpeedoTD[16], 4);
	TextDrawSetProportional(SpeedoTD[16], 1);

	SpeedoTD[17] = TextDrawCreate(144.799, 397.399, "LD_BUM:blkdot");
	TextDrawTextSize(SpeedoTD[17], 1.500, 0.500);
	TextDrawAlignment(SpeedoTD[17], 1);
	TextDrawColor(SpeedoTD[17], -1);
	TextDrawSetShadow(SpeedoTD[17], 0);
	TextDrawSetOutline(SpeedoTD[17], 0);
	TextDrawBackgroundColor(SpeedoTD[17], 255);
	TextDrawFont(SpeedoTD[17], 4);
	TextDrawSetProportional(SpeedoTD[17], 1);

	SpeedoTD[18] = TextDrawCreate(145.800, 395.500, "LD_BUM:blkdot");
	TextDrawTextSize(SpeedoTD[18], 0.500, 3.500);
	TextDrawAlignment(SpeedoTD[18], 1);
	TextDrawColor(SpeedoTD[18], -1);
	TextDrawSetShadow(SpeedoTD[18], 0);
	TextDrawSetOutline(SpeedoTD[18], 0);
	TextDrawBackgroundColor(SpeedoTD[18], 255);
	TextDrawFont(SpeedoTD[18], 4);
	TextDrawSetProportional(SpeedoTD[18], 1);
}

CreateStressTD()
{
    StressTD = TextDrawCreate(322.000000, -1.000000, "_");
    TextDrawFont(StressTD, true);
    TextDrawLetterSize(StressTD, 0.600000, 56.800003);
    TextDrawTextSize(StressTD, 298.500000, 675.000000);
    TextDrawSetOutline(StressTD, true);
    TextDrawSetShadow(StressTD, false);
    TextDrawAlignment(StressTD, 2);
    TextDrawColor(StressTD, -1);
    TextDrawBackgroundColor(StressTD,  155);
    TextDrawBoxColor(StressTD, 35634);
    TextDrawUseBox(StressTD, true);
    TextDrawSetProportional(StressTD, true);
    TextDrawSetSelectable(StressTD, false);
}

CreatePlayerSpeedoTD(playerid)
{
    PlayerSpeedoTD[playerid][0] = CreatePlayerTextDraw(playerid, 133.000, 379.000, "200");
	PlayerTextDrawLetterSize(playerid, PlayerSpeedoTD[playerid][0], 0.180, 0.999);
	PlayerTextDrawAlignment(playerid, PlayerSpeedoTD[playerid][0], 2);
	PlayerTextDrawColor(playerid, PlayerSpeedoTD[playerid][0], -1);
	PlayerTextDrawSetShadow(playerid, PlayerSpeedoTD[playerid][0], 1);
	PlayerTextDrawSetOutline(playerid, PlayerSpeedoTD[playerid][0], 1);
	PlayerTextDrawBackgroundColor(playerid, PlayerSpeedoTD[playerid][0], 0);
	PlayerTextDrawFont(playerid, PlayerSpeedoTD[playerid][0], 1);
	PlayerTextDrawSetProportional(playerid, PlayerSpeedoTD[playerid][0], 1);

	PlayerSpeedoTD[playerid][1] = CreatePlayerTextDraw(playerid, 154.500, 404.799, "LD_BUM:blkdot");
	PlayerTextDrawTextSize(playerid, PlayerSpeedoTD[playerid][1], 3.000, -13.500);
	PlayerTextDrawAlignment(playerid, PlayerSpeedoTD[playerid][1], 1);
	PlayerTextDrawColor(playerid, PlayerSpeedoTD[playerid][1], 16711935);
	PlayerTextDrawSetShadow(playerid, PlayerSpeedoTD[playerid][1], 0);
	PlayerTextDrawSetOutline(playerid, PlayerSpeedoTD[playerid][1], 0);
	PlayerTextDrawBackgroundColor(playerid, PlayerSpeedoTD[playerid][1], 255);
	PlayerTextDrawFont(playerid, PlayerSpeedoTD[playerid][1], 4);
	PlayerTextDrawSetProportional(playerid, PlayerSpeedoTD[playerid][1], 1);

	PlayerSpeedoTD[playerid][2] = CreatePlayerTextDraw(playerid, 122.000, 412.000, "Barat Daya l Los Santos International Airport");
	PlayerTextDrawLetterSize(playerid, PlayerSpeedoTD[playerid][2], 0.160, 0.900);
	PlayerTextDrawAlignment(playerid, PlayerSpeedoTD[playerid][2], 1);
	PlayerTextDrawColor(playerid, PlayerSpeedoTD[playerid][2], -1);
	PlayerTextDrawSetShadow(playerid, PlayerSpeedoTD[playerid][2], 1);
	PlayerTextDrawSetOutline(playerid, PlayerSpeedoTD[playerid][2], 1);
	PlayerTextDrawBackgroundColor(playerid, PlayerSpeedoTD[playerid][2], 0);
	PlayerTextDrawFont(playerid, PlayerSpeedoTD[playerid][2], 1);
	PlayerTextDrawSetProportional(playerid, PlayerSpeedoTD[playerid][2], 1);
}

//V1
ShowHBETD(playerid)
{
    for(new x; x < 20; x++)
	{
        TextDrawShowForPlayer(playerid, HBE[x]);
    }
    for(new x; x < 10; x++)
    {
        PlayerTextDrawShow(playerid, PHBE[playerid][x]);
    }
	HBETDHidden[playerid] = false;
}

HideHBETD(playerid)
{
    for(new x; x < 20; x++)
	{
        TextDrawHideForPlayer(playerid, HBE[x]);
    }
    for(new x; x < 10; x++)
    {
        PlayerTextDrawHide(playerid, PHBE[playerid][x]);
    }
	HBETDHidden[playerid] = true;
}

ShowSpeedoTD(playerid)
{
    for(new x; x < 19; x++)
    {
        TextDrawShowForPlayer(playerid, SpeedoTD[x]);
	}

	for(new x; x < 3; x++)
	{
        PlayerTextDrawShow(playerid, PlayerSpeedoTD[playerid][x]);
    }
}

HideSpeedoTD(playerid)
{
    for(new x; x < 19; x++)
    {
        TextDrawHideForPlayer(playerid, SpeedoTD[x]);
	}

	for(new x; x < 3; x++)
	{
        PlayerTextDrawHide(playerid, PlayerSpeedoTD[playerid][x]);
    }
}

ShowStressEffectTD(playerid)
{
    TextDrawShowForPlayer(playerid, StressTD);
}

HideStressEffectTD(playerid)
{
    TextDrawHideForPlayer(playerid, StressTD);
}