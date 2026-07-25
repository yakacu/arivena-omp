YCMD:count(playerid, params[], help)
{
    if (AccountData[playerid][pAdmin] < 1 && !AccountData[playerid][pSteward])
        return PermissionError(playerid);

    SendClientMessageEx(playerid, Y_SERVER, "(Server) "WHITE"This server has "YELLOW"%d total players.", Iter_Count(Player));
    SendClientMessageEx(playerid, Y_SERVER, "(Server) "WHITE"This server has "YELLOW"%d total vehicles.", Iter_Count(Vehicle));
    return 1;
}

YCMD:ntag(playerid, params[], help)
{
	if(AccountData[playerid][pAdmin] < 1)
		return PermissionError(playerid);

	new hhs[158];

	switch(AccountData[playerid][pToggleNameID])
	{
		case false:
		{
			AccountData[playerid][pToggleNameID] = true;

			foreach(new i : Player) if(i != playerid)
			{
				if(AccountData[i][pSpawned] && AccountData[i][IsLoggedIn])
				{
					format(hhs, sizeof(hhs), "%s\n%s [%d]\n"RED"%.2f "WHITE"| "GRAY"%.2f", AccountData[i][pName], AccountData[i][pUCP], i, AccountData[i][pHealth], AccountData[i][pArmor]);
					AccountData[playerid][pNameIDLabel][i] = CreateDynamic3DTextLabel(hhs, Y_WHITE, 0.0, 0.0, 0.6, 100.5, i, INVALID_VEHICLE_ID, 0, -1, -1, playerid, 100.5, -1, 0);
				}
			}
			ShowTDN(playerid, NOTIFICATION_INFO, "Nametag player ~g~aktif.");
		}
		case true:
		{
			AccountData[playerid][pToggleNameID] = false;

			foreach(new i : Player) if(i != playerid)
			{
				if(AccountData[i][pSpawned] && AccountData[i][IsLoggedIn])
				{
					if(DestroyDynamic3DTextLabel(AccountData[playerid][pNameIDLabel][i]))
						AccountData[playerid][pNameIDLabel][i] = STREAMER_TAG_3D_TEXT_LABEL: INVALID_STREAMER_ID;
				}
			}

			ShowTDN(playerid, NOTIFICATION_INFO, "Nametag player ~r~tidak aktif.");
		}
	}
	return 1;
}

YCMD:torture(playerid, params[], help)
{
    new otherid, Float:otheridpos[3];
    if (AccountData[playerid][pAdmin] < 1)
        return PermissionError(playerid);

    if(sscanf(params, "d", otherid)) return SUM(playerid, "/torture [playerid]");

    if (!IsPlayerConnected(otherid)) return ShowTDN(playerid, NOTIFICATION_ERROR, "Pemain tersebut tidak terkoneksi ke server!");

    if (otherid == playerid) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda tidak dapat melakukannya terhadap diri sendiri!");

    if (!AccountData[playerid][pSpawned] || !AccountData[otherid][pSpawned])
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda/Pemain tersebut belum spawn!");

    AccountData[otherid][pTortured] = true;
    Anticheat[otherid][acImmunity] = gettime() + 5;
    SetPlayerPos(otherid, 10.00, -10.00, 9999999999.99);
    GetPlayerPos(otherid, otheridpos[0], otheridpos[1], otheridpos[2]);

    SendAdm(playerid, "You have inflicted torture on %s(%d).", AccountData[otherid][pName], otherid);

    static string[144];
    format(string, sizeof(string), "AdmCmd: You have been tortured by %s.", AccountData[playerid][pAdminname]);
	SendClientMessage(otherid, Y_LIGHTRED, string);
    return 1;
}

YCMD:getin(playerid, params[], help)
{
    new vid;
    if (AccountData[playerid][pAdmin] < 1 && !AccountData[playerid][pSteward])
        return PermissionError(playerid);

    if (sscanf(params, "d", vid)) return SUM(playerid, "/getin [vehicleid]");
    if (!IsValidVehicle(vid)) return ShowTDN(playerid, NOTIFICATION_ERROR, "Invalid Vehicle ID!");

    PutPlayerInVehicleEx(playerid, vid, 0);
    return 1;
}

YCMD:near(playerid, params[], help)
{
    static
        id = -1;

    new vehicleid = GetNearestVehicleToPlayer(playerid, 5.0, false);

    if(AccountData[playerid][pAdmin] < 1)
        return PermissionError(playerid);

    if ((id = BJTable_Nearest(playerid)) != -1)
        SendClientMessageEx(playerid, Y_SERVER, "(Server) "WHITE"Anda berdiri dekat dynamic blackjack table ID: "YELLOW"%d", id);

    if ((id = Vending_Nearest(playerid)) != -1)
        SendClientMessageEx(playerid, Y_SERVER, "(Server) "WHITE"Anda berdiri dekat dynamic vending ID: "YELLOW"%d", id);

    if ((id = Graffiti_Nearest(playerid)) != -1)
        SendClientMessageEx(playerid, Y_SERVER, "(Server) "WHITE"Anda berdiri dekat dynamic graffiti tag ID: "YELLOW"%d", id);
        
    if ((id = RSign_Nearest(playerid)) != -1)
        SendClientMessageEx(playerid, Y_SERVER, "(Server) "WHITE"Anda berdiri dekat dynamic road sign ID: "YELLOW"%d", id);

    if ((id = GetPlayerNearestFLocker(playerid)) != -1)
        SendClientMessageEx(playerid, Y_SERVER, "(Server) "WHITE"Anda berdiri dekat dynamic fact locker ID: "YELLOW"%d", id);
    
    if ((id = GetPlayerNearestFCraft(playerid)) != -1)
        SendClientMessageEx(playerid, Y_SERVER, "(Server) "WHITE"Anda berdiri dekat dynamic fact craft ID: "YELLOW"%d", id);
    
    if ((id = GetPlayerNearestFGaragePos(playerid)) != -1)
        SendClientMessageEx(playerid, Y_SERVER, "(Server) "WHITE"Anda berdiri dekat dynamic fact garage ID: "YELLOW"%d", id);

    if ((id = GetPlayerNearestFVault(playerid)) != -1)
        SendClientMessageEx(playerid, Y_SERVER, "(Server) "WHITE"Anda berdiri dekat dynamic fact vault ID: "YELLOW"%d", id);

    if ((id = GetPlayerNearestFArmoury(playerid)) != -1)
        SendClientMessageEx(playerid, Y_SERVER, "(Server) "WHITE"Anda berdiri dekat dynamic fact armoury ID: "YELLOW"%d", id);

    if ((id = Actor_Nearest(playerid)) != -1)
        SendClientMessageEx(playerid, Y_SERVER, "(Server) "WHITE"Anda berdiri dekat dynamic actor ID: "YELLOW"%d", id);

    if ((id = Rental_Nearest(playerid)) != -1)
        SendClientMessageEx(playerid, Y_SERVER, "(Server) "WHITE"Anda berdiri dekat dynamic bike rental ID: "YELLOW"%d", id);

    if ((id = Button_Nearest(playerid)) != -1)
        SendClientMessageEx(playerid, Y_SERVER, "(Server) "WHITE"Anda berdiri dekat dynamic button ID: "YELLOW"%d", id);

    if ((id = Doors_Nearest(playerid)) != -1)
        SendClientMessageEx(playerid, Y_SERVER, "(Server) "WHITE"Anda berdiri dekat dynamic door ID: "YELLOW"%d", id);

    if ((id = FivemLabel_Nearest(playerid)) != -1)
        SendClientMessageEx(playerid, Y_SERVER, "(Server) "WHITE"Anda berdiri dekat dynamic FiveM labels ID: "YELLOW"%d", id);

    if ((id = PublicGarage_Nearest(playerid)) != -1)
        SendClientMessageEx(playerid, Y_SERVER, "(Server) "WHITE"Anda berdiri dekat dynamic public garage ID: "YELLOW"%d", id);

    if ((id = Garbage_Nearest(playerid)) != -1)
        SendClientMessageEx(playerid, Y_SERVER, "(Server) "WHITE"Anda berdiri dekat dynamic garbage bin ID: "YELLOW"%d", id);

    if ((id = Kanabis_Nearest(playerid)) != -1)
        SendClientMessageEx(playerid, Y_SERVER, "(Server) "WHITE"Anda berdiri dekat dynamic cannabis ID: "YELLOW"%d", id);

    if ((id = Atm_Nearest(playerid)) != -1)
        SendClientMessageEx(playerid, Y_SERVER, "(Server) "WHITE"Anda berdiri dekat dynamic ATM ID: "YELLOW"%d", id);

    if ((id = Robbery_Nearest(playerid)) != -1)
        SendClientMessageEx(playerid, Y_SERVER, "(Server) "WHITE"Anda berdiri dekat dynamic robbery ID: "YELLOW"%d", id);

    if ((id = Shop_Nearest(playerid)) != -1)
        SendClientMessageEx(playerid, Y_SERVER, "(Server) "WHITE"Anda berdiri dekat dynamic shop ID: "YELLOW"%d", id);

    if ((id = House_Nearest(playerid)) != -1)
        SendClientMessageEx(playerid, Y_SERVER, "(Server) "WHITE"Anda berdiri dekat dynamic house ID: "YELLOW"%d", id);

    if ((id = Rusun_Nearest(playerid)) != -1)
        SendClientMessageEx(playerid, Y_SERVER, "(Server) "WHITE"Anda berdiri dekat dynamic rusun ID: "YELLOW"%d", id);

    if ((id = Xmas_Nearest(playerid)) != -1)
        SendClientMessageEx(playerid, Y_SERVER, "(Server) "WHITE"Anda berdiri dekat dynamic xmas tree ID: "YELLOW"%d", id);

    if ((id = Biz_Nearest(playerid)) != -1)
        SendClientMessageEx(playerid, Y_SERVER, "(Server) "WHITE"Anda berdiri dekat dynamic business ID: "YELLOW"%d", id);

    if ((id = Deer_Nearest(playerid)) != -1)
        SendClientMessageEx(playerid, Y_SERVER, "(Server) "WHITE"Anda berdiri dekat dynamic deer ID: "YELLOW"%d", id);

    if (vehicleid != INVALID_VEHICLE_ID)
        SendClientMessageEx(playerid, Y_SERVER, "(Server) "WHITE"Anda berdiri dekat VID: "YELLOW"%d | Model: %s(%d)", vehicleid, GetVehicleName(vehicleid), GetVehicleModel(vehicleid));

    return 1;
}

YCMD:ahelp(playerid, params[], help)
{
    if (AccountData[playerid][pAdmin] < 1)
        return PermissionError(playerid);

    Dialog_Show(playerid, "AdminHelp", DIALOG_STYLE_LIST, ""ARIVENA"Arivena Theater "WHITE"- Admin Help", "Admin I\n"GRAY"Admin II\nAdmin III\n"GRAY"Admin IV\nManagement\n"GRAY"Executive", "Pilih", "Batal");

    return 1;
}

YCMD:takeoutveh(playerid, params[], help)
{
    if(AccountData[playerid][pAdmin] < 1)
        return PermissionError(playerid);

    new otherid;
    if(sscanf(params, "d", otherid)) return SUM(playerid, "/takeoutveh [playerid]");
    if(!IsPlayerConnected(otherid)) return ShowTDN(playerid, NOTIFICATION_ERROR, "Pemain tersebut tidak terkoneksi ke server!");
    if(!AccountData[otherid][pSpawned]) return ShowTDN(playerid, NOTIFICATION_ERROR, "Pemain tersebut belum spawn!");

    new bool:found = false, msg2[1618];
    format(msg2, sizeof(msg2), "Model [Database ID]\tPlate\t/ Status\n");
    foreach (new i : PvtVehicles)
    {
        if (PlayerVehicle[i][pVehOwnerID] == AccountData[otherid][pID] && PlayerVehicle[i][pVehPhysic] == INVALID_VEHICLE_ID)
        {
            if (strcmp(PlayerVehicle[i][pVehPlate], "-")) // If it has a valid plate
            {
                if (PlayerVehicle[i][pVehRentTime] != 0) // If it's a rental vehicle with a plate
                {
                    format(msg2, sizeof(msg2), "%s%s [%d]\t%s\t/ %s\n", msg2, GetVehicleModelName(PlayerVehicle[i][pVehModelID]), PlayerVehicle[i][pVehID], PlayerVehicle[i][pVehPlate], GetMyVehicleStatus(i));
                    found = true;
                }
                else // If it's not a rental but has a plate
                {
                    format(msg2, sizeof(msg2), "%s%s [%d]\t%s\t/ Dimiliki / %s\n", msg2, GetVehicleModelName(PlayerVehicle[i][pVehModelID]), PlayerVehicle[i][pVehID], PlayerVehicle[i][pVehPlate], GetMyVehicleStatus(i));
                    found = true;
                }
            }
            else // If it has no plate
            {
                if (PlayerVehicle[i][pVehRentTime] != 0) // If it's a rental vehicle with no plate
                {
                    format(msg2, sizeof(msg2), "%s%s [%d]\tNo Plate\t/ %s\n", msg2, GetVehicleModelName(PlayerVehicle[i][pVehModelID]), PlayerVehicle[i][pVehID], GetMyVehicleStatus(i));
                    found = true;
                }
                else // If it's not a rental and has no plate
                {
                    format(msg2, sizeof(msg2), "%s%s [%d]\tNo Plate\t/ Dimiliki / %s\n", msg2, GetVehicleModelName(PlayerVehicle[i][pVehModelID]), PlayerVehicle[i][pVehID], GetMyVehicleStatus(i));
                    found = true;
                }
            }
        }
    }
    if (found)
        Dialog_Show(playerid, "AdmTakeoutVeh", DIALOG_STYLE_TABLIST_HEADERS, ""ARIVENA"Arivena Theater "WHITE"- Keluarkan Kendaraan", msg2, "Pilih", "Tutup");
    else
        Dialog_Show(playerid, "UnusedDialog", DIALOG_STYLE_MSGBOX, ""ARIVENA"Arivena Theater "WHITE"- Keluarkan Kendaraan", "Tidak ada kendaraan milik pemain tersebut yang dapat dikeluarkan!", "Tutup", "");

    AccountData[playerid][pTempValue] = otherid;
    return 1;
}

YCMD:sendveh(playerid, params[], help)
{
    if (AccountData[playerid][pAdmin] < 1)
        return PermissionError(playerid);

    new otherid, vehid, Float:x, Float:y, Float:z, driverid;
    if (sscanf(params, "dd", otherid, vehid))
        return SUM(playerid, "/sendveh [playerid] [vehid] (Use /avehlist to find vehid)");

    if (!IsPlayerConnected(otherid)) return ShowTDN(playerid, NOTIFICATION_ERROR, "Pemain tersebut tidak terkoneksi ke server!");
    if (!IsValidVehicle(vehid)) return ShowTDN(playerid, NOTIFICATION_ERROR, "Invalid Vehicle ID!");

    GetPlayerPos(otherid, x, y, z);
    SetVehiclePos(vehid, x, y, z + 0.5);

    driverid = GetVehicleDriver(vehid);
    if (driverid != INVALID_PLAYER_ID)
        Anticheat[GetVehicleDriver(vehid)][acImmunity] = gettime() + 5;
    SetVehicleVirtualWorldEx(vehid, GetPlayerVirtualWorld(otherid));
    LinkVehicleToInteriorEx(vehid, GetPlayerInterior(otherid));
    SendAdm(playerid, "You have sent VID: %d to %s(%d) at %s.", vehid, AccountData[otherid][pName], otherid, GetLocation(x, y, z));
    return 1;
}

YCMD:getveh(playerid, params[], help)
{
    if (AccountData[playerid][pAdmin] < 1 && !AccountData[playerid][pSteward])
        return PermissionError(playerid);

    new vehid, Float:posisiX, Float:posisiY, Float:posisiZ, driverid;
    if (sscanf(params, "d", vehid))
        return SUM(playerid, "/getveh [vehid] (Use /avehlist to find vehid)");

    if (vehid == INVALID_VEHICLE_ID) return ShowTDN(playerid, NOTIFICATION_ERROR, "Invalid Vehicle ID!");
    if (!IsValidVehicle(vehid)) return ShowTDN(playerid, NOTIFICATION_ERROR, "Invalid Vehicle ID!");
    GetPlayerPos(playerid, posisiX, posisiY, posisiZ);
    SendAdm(playerid, "You have pulled VID: %d to %s.", vehid, GetLocation(posisiX, posisiY, posisiZ));
    SetVehiclePos(vehid, posisiX, posisiY, posisiZ + 0.5);

    driverid = GetVehicleDriver(vehid);
    if (driverid != INVALID_PLAYER_ID)
        Anticheat[GetVehicleDriver(vehid)][acImmunity] = gettime() + 5;
    SetVehicleVirtualWorldEx(vehid, GetPlayerVirtualWorld(playerid));
    LinkVehicleToInteriorEx(vehid, GetPlayerInterior(playerid));
    return 1;
}

YCMD:gotoco(playerid, params[], help)
{
    if (AccountData[playerid][pAdmin] < 1)
        return PermissionError(playerid);

    new Float: pos[3], int;
    if (sscanf(params, "fffd", pos[0], pos[1], pos[2], int)) return SUM(playerid, "/gotoco [x-axis] [y-axis] [z-axis] [interior id]");

    AccountData[playerid][pInRusun] = -1;
    AccountData[playerid][pInHouse] = -1;
    AccountData[playerid][pInBiz] = -1;
    AccountData[playerid][pInDoor] = -1;
    AccountData[playerid][pInGudang] = -1;

    SetPlayerPositionEx(playerid, pos[0], pos[1], pos[2], 0.0);
    SetPlayerInterior(playerid, int);
    return 1;
}

YCMD:gotoveh(playerid, params[], help)
{
	if(AccountData[playerid][pAdmin] < 1 && !AccountData[playerid][pSteward])
		return PermissionError(playerid);

	new vehid, Float:posX, Float:posY, Float:posZ;
	if(sscanf(params, "d", vehid)) 
		return SUM(playerid, "/gotoveh [vehicleid] (Use /avehlist to find the vehicle ID)");

	if (vehid == INVALID_VEHICLE_ID) return ShowTDN(playerid, NOTIFICATION_ERROR, "Invalid Vehicle ID!");
    if (!IsValidVehicle(vehid)) return ShowTDN(playerid, NOTIFICATION_ERROR, "Invalid Vehicle ID!");
	
	AccountData[playerid][pInRusun] = -1;
	AccountData[playerid][pInHouse] = -1;
	AccountData[playerid][pInBiz] = -1;
	AccountData[playerid][pInDoor] = -1;
	AccountData[playerid][pInGudang] = -1;

	GetVehiclePos(vehid, posX, posY, posZ);
	SetPlayerPositionEx(playerid, posX, posY, posZ+3.0, 0.0);
	SetPlayerInteriorEx(playerid, VehicleCore[vehid][vInterior]);
	SetPlayerVirtualWorldEx(playerid, VehicleCore[vehid][vWorld]);

	return 1;
}

YCMD:rveh(playerid, params[], help)
{
	if(AccountData[playerid][pAdmin] < 1)
		return PermissionError(playerid);

	new vehid, Float:posX, Float:posY, Float:posZ;
	if(sscanf(params, "d", vehid)) return SUM(playerid, "/rveh [vehicleid] (Use /avehlist to find the vehicle ID)");

	if (vehid == INVALID_VEHICLE_ID) return ShowTDN(playerid, NOTIFICATION_ERROR, "Invalid Vehicle ID!");
    if (!IsValidVehicle(vehid)) return ShowTDN(playerid, NOTIFICATION_ERROR, "Invalid Vehicle ID!");
	GetVehiclePos(vehid, posX, posY, posZ);
	if(IsVehicleEmpty(vehid))
	{
		SetTimerEx("RespawnPV", 1000, false, "d", vehid);
		SendAdm(playerid, "You have respawned Vehicle ID: %d (%s).", vehid, GetLocation(posX, posY, posZ));
	}
	else ShowTDN(playerid, NOTIFICATION_ERROR, "Vehicle ID tersebut sedang digunakan!");
	return 1;
}

YCMD:gotols(playerid, params[], help)
{
    if(AccountData[playerid][pAdmin] < 1 && !AccountData[playerid][pSteward])
		return PermissionError(playerid);

	AccountData[playerid][pInRusun] = -1;
	AccountData[playerid][pInHouse] = -1;
	AccountData[playerid][pInBiz] = -1;
	AccountData[playerid][pInDoor] = -1;
	AccountData[playerid][pInGudang] = -1;

    SetPlayerPositionEx(playerid, 1475.0045,-1697.1842,14.0469,177.6616);
    SetPlayerVirtualWorldEx(playerid, 0);
	SetPlayerInteriorEx(playerid, 0);
	return 1;
}

YCMD:sendto(playerid, params[], help)
{
	if(AccountData[playerid][pAdmin] < 1 && !AccountData[playerid][pSteward])
		return PermissionError(playerid);

	new otherid, type[24];
	if(sscanf(params, "ds[24]", otherid, type))
		return SUM(playerid, "/sendto [playerid] [ls/asuransi/rs/ikea/karnaval/showroom/balkot/bandara/pelabuhan]");

	if(!IsPlayerConnected(otherid))
		return ShowTDN(playerid, NOTIFICATION_ERROR, "Pemain tersebut tidak terkoneksi ke server!");
	
	static string[144];
	if(!strcmp(type, "ls", true))
    {
		AccountData[otherid][pInRusun] = -1;
		AccountData[otherid][pInHouse] = -1;
		AccountData[otherid][pInBiz] = -1;
		AccountData[otherid][pInDoor] = -1;
		AccountData[otherid][pInGudang] = -1;

		SetPlayerPositionEx(otherid, 1482.0356, -1724.5726, 13.5469, 0.0);
		SetPlayerVirtualWorldEx(otherid, 0);
		SetPlayerInteriorEx(otherid, 0);
		
		format(string, sizeof(string), "AdmCmd: You have been teleported to Los Santos by %s.", AccountData[playerid][pAdminname]);
		SendClientMessage(otherid, Y_LIGHTRED, string);
		SendAdm(playerid, "You have teleported %s(%i) to Los Santos.", AccountData[otherid][pName], otherid);
	}
	else if(!strcmp(type, "asuransi", true))
    {
		AccountData[otherid][pInRusun] = -1;
		AccountData[otherid][pInHouse] = -1;
		AccountData[otherid][pInBiz] = -1;
		AccountData[otherid][pInDoor] = -1;
		AccountData[otherid][pInGudang] = -1;

		SetPlayerPositionEx(otherid, -389.5509,2230.9001,42.4297, 0.0);
		SetPlayerVirtualWorldEx(otherid, 0);
		SetPlayerInteriorEx(otherid, 0);

		format(string, sizeof(string), "AdmCmd: You have been teleported to asuransi by %s.", AccountData[playerid][pAdminname]);
		SendClientMessage(otherid, Y_LIGHTRED, string);
		SendAdm(playerid, "You have teleported %s(%i) to asuransi.", AccountData[otherid][pName], otherid);
	}
	else if(!strcmp(type, "rs", true))
    {
		AccountData[otherid][pInRusun] = -1;
		AccountData[otherid][pInHouse] = -1;
		AccountData[otherid][pInBiz] = -1;
		AccountData[otherid][pInDoor] = -1;
		AccountData[otherid][pInGudang] = -1;

		SetPlayerPositionEx(otherid, 1743.8606,-1171.2920,23.8281, 1.2817);
		SetPlayerVirtualWorldEx(otherid, 0);
		SetPlayerInteriorEx(otherid, 0);

		format(string, sizeof(string), "AdmCmd: You have been teleported to rumah sakit by %s.", AccountData[playerid][pAdminname]);
		SendClientMessage(otherid, Y_LIGHTRED, string);
		SendAdm(playerid, "You have teleported %s(%i) to rumah sakit.", AccountData[otherid][pName], otherid);
	}
	else if(!strcmp(type, "ikea", true))
    {
		AccountData[otherid][pInRusun] = -1;
		AccountData[otherid][pInHouse] = -1;
		AccountData[otherid][pInBiz] = -1;
		AccountData[otherid][pInDoor] = -1;
		AccountData[otherid][pInGudang] = -1;

		SetPlayerPositionEx(otherid, 2817.5532,-1087.9933,30.7399,88.9927);
		SetPlayerVirtualWorldEx(otherid, 0);
		SetPlayerInteriorEx(otherid, 0);

		format(string, sizeof(string), "AdmCmd: You have been teleported to ikea by %s.", AccountData[playerid][pAdminname]);
		SendClientMessage(otherid, Y_LIGHTRED, string);
		SendAdm(playerid, "You have teleported %s(%i) to ikea.", AccountData[otherid][pName], otherid);
	}
	else if(!strcmp(type, "karnaval", true))
    {
		AccountData[otherid][pInRusun] = -1;
		AccountData[otherid][pInHouse] = -1;
		AccountData[otherid][pInBiz] = -1;
		AccountData[otherid][pInDoor] = -1;
		AccountData[otherid][pInGudang] = -1;

		SetPlayerPositionEx(otherid, 380.7771,-2026.2224,7.8359,181.3164);
		SetPlayerVirtualWorldEx(otherid, 0);
		SetPlayerInteriorEx(otherid, 0);

		format(string, sizeof(string), "AdmCmd: You have been teleported to karnaval by %s.", AccountData[playerid][pAdminname]);
		SendClientMessage(otherid, Y_LIGHTRED, string);
		SendAdm(playerid, "You have teleported %s(%i) to karnaval.", AccountData[otherid][pName], otherid);
	}
	else if(!strcmp(type, "showroom", true))
    {
		AccountData[otherid][pInRusun] = -1;
		AccountData[otherid][pInHouse] = -1;
		AccountData[otherid][pInBiz] = -1;
		AccountData[otherid][pInDoor] = -1;
		AccountData[otherid][pInGudang] = -1;

		SetPlayerPositionEx(otherid, 395.3554,-1341.3446,14.7684,31.4033);
		SetPlayerVirtualWorldEx(otherid, 0);
		SetPlayerInteriorEx(otherid, 0);

		format(string, sizeof(string), "AdmCmd: You have been teleported to showroom by %s.", AccountData[playerid][pAdminname]);
		SendClientMessage(otherid, Y_LIGHTRED, string);
		SendAdm(playerid, "You have teleported %s(%i) to showroom.", AccountData[otherid][pName], otherid);
	}
	else if(!strcmp(type, "balkot", true))
    {
		AccountData[otherid][pInRusun] = -1;
		AccountData[otherid][pInHouse] = -1;
		AccountData[otherid][pInBiz] = -1;
		AccountData[otherid][pInDoor] = -1;
		AccountData[otherid][pInGudang] = -1;

		SetPlayerPositionEx(otherid, 1255.9501,-2048.1375,59.7302,31.0483);
		SetPlayerVirtualWorldEx(otherid, 0);
		SetPlayerInteriorEx(otherid, 0);

		format(string, sizeof(string), "AdmCmd: You have been teleported to balai kota by %s.", AccountData[playerid][pAdminname]);
		SendClientMessage(otherid, Y_LIGHTRED, string);
		SendAdm(playerid, "You have teleported %s(%i) to balai kota.", AccountData[otherid][pName], otherid);
	}
    else if(!strcmp(type, "bandara", true))
    {
		AccountData[otherid][pInRusun] = -1;
		AccountData[otherid][pInHouse] = -1;
		AccountData[otherid][pInBiz] = -1;
		AccountData[otherid][pInDoor] = -1;
		AccountData[otherid][pInGudang] = -1;

		SetPlayerPositionEx(otherid, 1682.8850,-2242.6370,13.5469,180.7440);
		SetPlayerVirtualWorldEx(otherid, 0);
		SetPlayerInteriorEx(otherid, 0);

		format(string, sizeof(string), "AdmCmd: You have been teleported to bandara by %s.", AccountData[playerid][pAdminname]);
		SendClientMessage(otherid, Y_LIGHTRED, string);
		SendAdm(playerid, "You have teleported %s(%i) to bandara.", AccountData[otherid][pName], otherid);
	}
    else if(!strcmp(type, "pelabuhan", true))
    {
		AccountData[otherid][pInRusun] = -1;
		AccountData[otherid][pInHouse] = -1;
		AccountData[otherid][pInBiz] = -1;
		AccountData[otherid][pInDoor] = -1;
		AccountData[otherid][pInGudang] = -1;

		SetPlayerPositionEx(otherid, 2717.9348,-2513.8723,17.3672,2.3617);
		SetPlayerVirtualWorldEx(otherid, 0);
		SetPlayerInteriorEx(otherid, 0);

		format(string, sizeof(string), "AdmCmd: You have been teleported to pelabuhan by %s.", AccountData[playerid][pAdminname]);
		SendClientMessage(otherid, Y_LIGHTRED, string);
		SendAdm(playerid, "You have teleported %s(%i) to pelabuhan.", AccountData[otherid][pName], otherid);
	}
	return 1;
}

YCMD:aduty(playerid, params[], help)
{
	if(AccountData[playerid][pAdmin] < 1 && !AccountData[playerid][pSteward])
        return PermissionError(playerid);
	
	if(!strcmp(AccountData[playerid][pAdminname], "None"))
		return ShowTDN(playerid, NOTIFICATION_ERROR, "Nama admin anda belum ditetapkan, silakan hubungi admin lebih tinggi!");
	
	switch(AccountData[playerid][pAdminDuty])
    {
		case false:
		{
			GetPlayerHealth(playerid, AccountData[playerid][pHealth]);
			SetPlayerColor(playerid, X11_RED);
			SetPlayerHealth(playerid, 99999);
			AccountData[playerid][pAdminDuty] = true;
			SetPlayerName(playerid, AccountData[playerid][pAdminname]);
			
            new adlbel[144];
			if(!AccountData[playerid][pSteward])
			{
				format(adlbel, sizeof(adlbel), "((Staff On Duty))\n%s\n"RED"%s", AccountData[playerid][pAdminname], GetAdminLevel(playerid));
				SendStaffMessage(Y_SERVER, "(AdmDuty) "WHITE"%s "YELLOW"%s "WHITE"sekarang mulai bertugas sebagai "RED"%s.", GetAdminLevel(playerid), AccountData[playerid][pName], AccountData[playerid][pAdminname]);
			}
			else
			{
				format(adlbel, sizeof(adlbel), "((Staff On Duty))\n%s\n"AQUAMARINE"The Stewards", AccountData[playerid][pAdminname]);
				SendStaffMessage(Y_SERVER, "(AdmDuty) "WHITE"Steward "YELLOW"%s "WHITE"sekarang mulai bertugas sebagai "RED"%s.", AccountData[playerid][pName], AccountData[playerid][pAdminname]);
			}
			AdminLabel[playerid] = CreateDynamic3DTextLabel(adlbel, Y_YELLOW, 0.0, 0.0, 0.5, 20.0, playerid, INVALID_VEHICLE_ID, 1, -1, -1, -1, 20.0, -1, 0);
            SetPlayerAttachedObject(playerid, 0, 1254, 2, 0.082, 0.015, 0.009, 0, 90.4, 0, 1, 1.286, 1);
        }
        case true:
        {
            SetPlayerColor(playerid, X11_WHITE);
			SetPlayerHealth(playerid, AccountData[playerid][pHealth]);
            SetPlayerName(playerid, AccountData[playerid][pName]);
            AccountData[playerid][pAdminDuty] = false;

            if(DestroyDynamic3DTextLabel(AdminLabel[playerid]))
				AdminLabel[playerid] = STREAMER_TAG_3D_TEXT_LABEL: INVALID_STREAMER_ID;

            SendStaffMessage(Y_SERVER, "(AdmDuty) "RED"%s "WHITE"telah selesai bertugas dan kembali sebagai "YELLOW"%s.", AccountData[playerid][pAdminname], AccountData[playerid][pName]);

            RemovePlayerAttachedObject(playerid, 0);

            if(pToys[playerid][0][toy_model] != 0)
            {
                SetPlayerAttachedObject(playerid,
                0,
                pToys[playerid][0][toy_model],
                pToys[playerid][0][toy_bone],
                pToys[playerid][0][toy_x],
                pToys[playerid][0][toy_y],
                pToys[playerid][0][toy_z],
                pToys[playerid][0][toy_rx],
                pToys[playerid][0][toy_ry],
                pToys[playerid][0][toy_rz],
                pToys[playerid][0][toy_sx],
                pToys[playerid][0][toy_sy],
                pToys[playerid][0][toy_sz],
                pToys[playerid][0][matcolor1][4],
                pToys[playerid][0][matcolor2][4]);
            }
        }
    }
	return 1;
}

YCMD:a(playerid, params[], help)
{
	if(AccountData[playerid][pAdmin] < 1 && !AccountData[playerid][pSteward] && !AccountData[playerid][pApprentice])
		return PermissionError(playerid);

	if(isnull(params))
        return SUM(playerid, "/a [staff chat]");

	foreach(new i : Player)
	{
		if(AccountData[i][IsLoggedIn] && (AccountData[i][pAdmin] > 0 || AccountData[i][pSteward] || AccountData[i][pApprentice]))
		{
            if(AccountData[playerid][pAdmin] > 0)
                SendClientMessageEx(i, 0x59BD93FF, "* %s %s [%d]: %s", GetAdminLevel(playerid), AccountData[playerid][pAdminname], playerid, params);

			if(AccountData[playerid][pSteward])
			{
				SendClientMessageEx(i, 0x59BD93FF, "* The Stewards %s [%d]: %s", AccountData[playerid][pAdminname], playerid, params);
			}

			if(AccountData[playerid][pApprentice])
			{
                SendClientMessageEx(i, 0x59BD93FF, "* Apprentice %s [%d]: %s", AccountData[playerid][pAdminname], playerid, params);
			}
		}
	}
	return 1;
}

YCMD:jetpack(playerid, params[], help)
{
	if (AccountData[playerid][pAdmin] < 1 && !AccountData[playerid][pSteward])
        return PermissionError(playerid);
	
	SetPlayerSpecialAction(playerid, SPECIAL_ACTION_USEJETPACK);
	return 1;
}

YCMD:dveh(playerid, params[], help)
{
    if (AccountData[playerid][pAdmin] < 1 && !AccountData[playerid][pSteward])
        return PermissionError(playerid);

    new impstr[144];

    if (IsPlayerInAnyVehicle(playerid))
    {
        new vehid = GetPlayerVehicleID(playerid);

        foreach (new i : Player)
        {
            if (vehid == JobVehicle[i])
            {
                DestroyVehicle(JobVehicle[i]);
            }

            if (vehid == TrailerVehicle[i])
            {
                DestroyVehicle(TrailerVehicle[i]);
            }

            if (vehid == FactionHeliVeh[i])
            {
                DestroyVehicle(FactionHeliVeh[i]);
            }

            if (vehid == g_CarstealCarPhysic[i])
            {
                foreach (new x : LSPDDuty)
                {
                    if (DestroyDynamicMapIcon(AccountData[i][g_CarstealIcon][x]))
                        AccountData[i][g_CarstealIcon][x] = STREAMER_TAG_MAP_ICON: INVALID_STREAMER_ID;
                }

                DestroyVehicle(g_CarstealCarPhysic[i]);
            }
            if (vehid == EventVehicle[i])
            {
                DestroyVehicle(EventVehicle[i]);
            }

            if (vehid == ShowroomVeh[i])
            {
                DestroyVehicle(ShowroomVeh[i]);
            }

            if (vehid == PlayerFactionVehicle[i][AccountData[i][pFaction]])
            {
                LSPDPlayerCallsign[i][0] = EOS;
                DestroyVehicle(PlayerFactionVehicle[i][AccountData[i][pFaction]]);

                static string[168];
                mysql_format(g_SQL, string, sizeof(string), "DELETE FROM `demand_vehicles` WHERE `ownerid` = %d", AccountData[i][pID]);
                mysql_pquery(g_SQL, string);
            }
        }

        for (new i; i < MAX_ADMIN_VEHICLES; i++)
        {
            if (vehid == GM[adminV][i])
            {
                DestroyVehicle(GM[adminV][i]);
            }
        }

        foreach (new pv : PvtVehicles)
        {
            if (vehid == PlayerVehicle[pv][pVehPhysic])
            {
                if (PlayerVehicle[pv][pVehRental] > -1 || PlayerVehicle[pv][pVehRentTime] > 0)
                {
                    PlayerVehicle[pv][pVehRental] = -1;
                    PlayerVehicle[pv][pVehRentTime] = 0;

                    SetVehicleNeonLights(PlayerVehicle[pv][pVehPhysic], false, PlayerVehicle[pv][pVehNeon], 0);

                    DestroyVehicle(PlayerVehicle[pv][pVehPhysic]);

                    PlayerVehicle[pv][pVehHandbraked] = false;

                    mysql_format(g_SQL, impstr, sizeof(impstr), "DELETE FROM `vehicle_bagasi` WHERE `Veh_DBID`=%d", PlayerVehicle[pv][pVehID]);
                    mysql_pquery(g_SQL, impstr);
                    mysql_format(g_SQL, impstr, sizeof(impstr), "DELETE FROM `vehicle_holster` WHERE `Veh_DBID`=%d", PlayerVehicle[pv][pVehID]);
                    mysql_pquery(g_SQL, impstr);
                    mysql_format(g_SQL, impstr, sizeof(impstr), "DELETE FROM `player_vehicles` WHERE `id` = %d", PlayerVehicle[pv][pVehID]);
                    mysql_pquery(g_SQL, impstr);
                    mysql_format(g_SQL, impstr, sizeof(impstr), "DELETE FROM `vtoys` WHERE `Veh_DBID`=%d", PlayerVehicle[pv][pVehID]);
                    mysql_pquery(g_SQL, impstr);

                    for(new x; x < MAX_BAGASI_ITEMS; x++)
					{
						VehicleBagasi[pv][x][vehicleBagasiExists] = false;
						VehicleBagasi[pv][x][vehicleBagasiID] = 0;
						VehicleBagasi[pv][x][vehicleBagasiVDBID] = 0;
						VehicleBagasi[pv][x][vehicleBagasiTemp][0] = EOS;
						VehicleBagasi[pv][x][vehicleBagasiModel] = 0;
						VehicleBagasi[pv][x][vehicleBagasiQuant] = 0;
					}

                    for(new z; z < 3; z++)
					{
						VehicleHolster[pv][vHolsterTaken][z] = false;
						VehicleHolster[pv][vHolsterID][z] = -1;
						VehicleHolster[pv][vHolsterWeaponID][z] = 0;
						VehicleHolster[pv][vHolsterWeaponAmmo][z] = 0;
					}

                    Iter_Remove(PvtVehicles, pv);
                }
                else
                {
                    PlayerVehicle[pv][pVehHandbraked] = false;
                    PlayerVehicle[pv][pVehInsuranced] = true;
                    DestroyVehicle(PlayerVehicle[pv][pVehPhysic]);

                    mysql_format(g_SQL, impstr, sizeof(impstr), "UPDATE `player_vehicles` SET `PVeh_Insuranced` = 1 WHERE `id`=%d",PlayerVehicle[pv][pVehID]);
                    mysql_pquery(g_SQL, impstr);
                }
            }
        }
        SendAdm(playerid, "Anda telah menghancurkan kendaraan VID %d.", vehid);
    }
    else
    {
        new tvid;
        if (sscanf(params, "d", tvid)) return SUM(playerid, "/dveh [vehicle id]");
        if (!IsValidVehicle(tvid)) return ShowTDN(playerid, NOTIFICATION_ERROR, "Invalid Vehicle ID!");

        foreach (new i : Player)
        {
            if (tvid == JobVehicle[i])
            {
                DestroyVehicle(JobVehicle[i]);
            }

            if (tvid == TrailerVehicle[i])
            {
                DestroyVehicle(TrailerVehicle[i]);
            }

            if (tvid == FactionHeliVeh[i])
            {
                DestroyVehicle(FactionHeliVeh[i]);
            }

            if (tvid == g_CarstealCarPhysic[i])
            {
                foreach (new x : LSPDDuty)
                {
                    if (DestroyDynamicMapIcon(AccountData[i][g_CarstealIcon][x]))
                        AccountData[i][g_CarstealIcon][x] = STREAMER_TAG_MAP_ICON: INVALID_STREAMER_ID;
                }
                DestroyVehicle(g_CarstealCarPhysic[i]);
            }

            if (tvid == EventVehicle[i])
            {
                DestroyVehicle(EventVehicle[i]);
            }

            if (tvid == ShowroomVeh[i])
            {
                DestroyVehicle(ShowroomVeh[i]);
            }

            if (tvid == PlayerFactionVehicle[i][AccountData[i][pFaction]])
            {
                LSPDPlayerCallsign[i][0] = EOS;
                DestroyVehicle(PlayerFactionVehicle[i][AccountData[i][pFaction]]);

                static string[168];
                mysql_format(g_SQL, string, sizeof(string), "DELETE FROM `demand_vehicles` WHERE `ownerid` = %d", AccountData[i][pID]);
                mysql_pquery(g_SQL, string);
            }
        }

        for (new i; i < MAX_ADMIN_VEHICLES; i++)
        {
            if (tvid == GM[adminV][i])
            {
                DestroyVehicle(GM[adminV][i]);
            }
        }

        foreach (new pv : PvtVehicles)
        {
            if(PlayerVehicle[pv][pVehPhysic] == tvid)
            {
                if(PlayerVehicle[pv][pVehRental] > -1 || PlayerVehicle[pv][pVehRentTime] > 0)
                {
                    PlayerVehicle[pv][pVehRental] = -1;
                    PlayerVehicle[pv][pVehRentTime] = 0;

                    SetVehicleNeonLights(PlayerVehicle[pv][pVehPhysic], false, PlayerVehicle[pv][pVehNeon], 0);

                    DestroyVehicle(PlayerVehicle[pv][pVehPhysic]);

                    PlayerVehicle[pv][pVehHandbraked] = false;

                    mysql_format(g_SQL, impstr, sizeof(impstr), "DELETE FROM `vehicle_bagasi` WHERE `Veh_DBID`=%d", PlayerVehicle[pv][pVehID]);
				    mysql_pquery(g_SQL, impstr);
				    mysql_format(g_SQL, impstr, sizeof(impstr), "DELETE FROM `vehicle_holster` WHERE `Veh_DBID`=%d", PlayerVehicle[pv][pVehID]);
				    mysql_pquery(g_SQL, impstr);
                    mysql_format(g_SQL, impstr, sizeof(impstr), "DELETE FROM `player_vehicles` WHERE `id` = %d", PlayerVehicle[pv][pVehID]);
                    mysql_pquery(g_SQL, impstr);
                    mysql_format(g_SQL, impstr, sizeof(impstr), "DELETE FROM `vtoys` WHERE `Veh_DBID`=%d", PlayerVehicle[pv][pVehID]);
                    mysql_pquery(g_SQL, impstr);

                    for(new x; x < MAX_BAGASI_ITEMS; x++)
					{
						VehicleBagasi[pv][x][vehicleBagasiExists] = false;
						VehicleBagasi[pv][x][vehicleBagasiID] = 0;
						VehicleBagasi[pv][x][vehicleBagasiVDBID] = 0;
						VehicleBagasi[pv][x][vehicleBagasiTemp][0] = EOS;
						VehicleBagasi[pv][x][vehicleBagasiModel] = 0;
						VehicleBagasi[pv][x][vehicleBagasiQuant] = 0;
					}

                    for(new z; z < 3; z++)
					{
						VehicleHolster[pv][vHolsterTaken][z] = false;
						VehicleHolster[pv][vHolsterID][z] = -1;
						VehicleHolster[pv][vHolsterWeaponID][z] = 0;
						VehicleHolster[pv][vHolsterWeaponAmmo][z] = 0;
					}

                    Iter_Remove(PvtVehicles, pv);
                }
                else
                {
                    PlayerVehicle[pv][pVehInsuranced] = true;

                    SetVehicleNeonLights(PlayerVehicle[pv][pVehPhysic], false, PlayerVehicle[pv][pVehNeon], 0);

                    PlayerVehicle[pv][pVehHandbraked] = false;

                    DestroyVehicle(PlayerVehicle[pv][pVehPhysic]);

                    mysql_format(g_SQL, impstr, sizeof(impstr), "UPDATE `player_vehicles` SET `PVeh_Insuranced` = 1 WHERE `id`=%d",PlayerVehicle[pv][pVehID]);
                    mysql_pquery(g_SQL, impstr);
                }
            }
        }
        SendAdm(playerid, "Anda telah menghancurkan kendaraan VID %d.", tvid);
    }
    return 1;
}

YCMD:jaillist(playerid, params[], help)
{
    if (AccountData[playerid][pAdmin] < 1)
        return PermissionError(playerid);

    new count = 0, line3[512];
    foreach (new i : Player)
    {
        if (OJailData[i][jailed])
        {
            format(line3, sizeof(line3), "%s\n"WHITE"%s(ID: %d) [Jail Time: %d seconds]", line3, AccountData[i][pName], i, OJailData[i][jailTime]);
            count++;
        }
    }
    if (count > 0)
    {
        Dialog_Show(playerid, "UnusedDialog", DIALOG_STYLE_MSGBOX, ""ARIVENA"Arivena Theater "WHITE"- Jail Player", line3, "Tutup", "");
    }
    else
    {
        Dialog_Show(playerid, "UnusedDialog", DIALOG_STYLE_MSGBOX, ""ARIVENA"Arivena Theater "WHITE"- Jail Player", "No players currently jailed!", "Tutup", "");
    }

    return 1;
}

YCMD:goto(playerid, params[], help)
{
    if (AccountData[playerid][pAdmin] < 1 && !AccountData[playerid][pSteward])
        return PermissionError(playerid);

    new otherid;
    if (sscanf(params, "d", otherid))
        return SUM(playerid, "/goto [playerid]");

    if (!IsPlayerConnected(otherid))
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Pemain tersebut tidak terkoneksi ke server!");

    static string[144];
    SendPlayerToPlayer(playerid, otherid);
    format(string, sizeof(string), "AdmCmd: %s teleported to your position.", AccountData[playerid][pAdminname]);
    SendClientMessage(otherid, Y_LIGHTRED, string);

    return 1;
}

YCMD:gethere(playerid, params[], help)
{
    new otherid;

    if (AccountData[playerid][pAdmin] < 1 && !AccountData[playerid][pSteward])
        return PermissionError(playerid);

    if (sscanf(params, "d", otherid))
        return SUM(playerid, "/gethere [playerid]");

    if (!IsPlayerConnected(otherid)) return ShowTDN(playerid, NOTIFICATION_ERROR, "Pemain tersebut tidak terkoneksi ke server!");

    if (otherid == playerid) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda tidak dapat melakukannya terhadap diri sendiri!");

    if (!AccountData[playerid][pSpawned] || !AccountData[otherid][pSpawned])
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda/Pemain tersebut belum spawn!");

    if (OJailData[playerid][jailed] || OJailData[otherid][jailed])
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda/Pemain tersebut sedang di jail admin!");

    static string[144];
    SendPlayerToPlayer(otherid, playerid);
    format(string, sizeof(string), "AdmCmd: %s teleported you to their position.", AccountData[playerid][pAdminname]);
    SendClientMessage(otherid, Y_LIGHTRED, string);
    SendAdm(playerid, "You have teleported %s to your position.", AccountData[otherid][pName]);
    return 1;
}

YCMD:ptp(playerid, params[], help)
{
    if (AccountData[playerid][pAdmin] < 1)
        return PermissionError(playerid);

    new otherid, targetmanid;

    if (sscanf(params, "dd", otherid, targetmanid))
        return SUM(playerid, "/ptp [otherid] [targetid]");

    if (!IsPlayerConnected(otherid))
        return ShowTDN(playerid, NOTIFICATION_ERROR, "otherid tidak terkoneksi ke server!");

    if (!IsPlayerConnected(targetmanid))
        return ShowTDN(playerid, NOTIFICATION_ERROR, "targetmanid tidak terkoneksi ke server!");

    if (!AccountData[playerid][pSpawned] || !AccountData[otherid][pSpawned] || !AccountData[targetmanid][pSpawned])
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda/kedua Pemain tersebut belum spawn!");

    if (OJailData[playerid][jailed] || OJailData[otherid][jailed] || OJailData[targetmanid][jailed])
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda/kedua Pemain tersebut sedang di jail admin!");

    static string[144];
    SendPlayerToPlayer(otherid, targetmanid);
    format(string, sizeof(string), "AdmCmd: %s sent you to %s.", AccountData[playerid][pAdminname], AccountData[targetmanid][pName]);
    SendClientMessage(otherid, Y_LIGHTRED, string);
    format(string, sizeof(string), "AdmCmd: %s sent %s to you.", AccountData[playerid][pAdminname], AccountData[otherid][pName]);
    SendClientMessage(targetmanid, Y_LIGHTRED, string);
    SendAdm(playerid, "You have sent %s(%d) to %s(%d)", AccountData[otherid][pName], otherid, AccountData[targetmanid][pName], targetmanid);

    return 1;
}

YCMD:freeze(playerid, params[], help)
{
    if (AccountData[playerid][pAdmin] < 1)
        return PermissionError(playerid);

    new otherid;
    if (sscanf(params, "d", otherid))
        return SUM(playerid, "/freeze [playerid]");

    if (!IsPlayerConnected(otherid))
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Pemain tersebut tidak terkoneksi ke server!");

    AccountData[playerid][pFreeze] = true;

    static string[144];
    TogglePlayerControllable(otherid, false);
    format(string, sizeof(string), "AdmCmd: %s froze your movement.", AccountData[playerid][pAdminname]);
    SendClientMessage(otherid, Y_LIGHTRED, string);
    SendAdm(playerid, "You have froze %s(%d).",AccountData[otherid][pName], otherid);

    return 1;
}

YCMD:unfreeze(playerid, params[], help)
{
	if(AccountData[playerid][pAdmin] < 1)
     	return PermissionError(playerid);

	new otherid;
    if(sscanf(params, "d", otherid))
        return SUM(playerid, "/unfreeze [playerid]");

    if(!IsPlayerConnected(otherid))
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Pemain tersebut tidak terkoneksi ke server!");

    AccountData[playerid][pFreeze] = false;

	static string[144];
    TogglePlayerControllable(otherid, true);
	format(string, sizeof(string), "AdmCmd: %s has allowed your movement.", AccountData[playerid][pAdminname]);
	SendClientMessage(otherid, Y_LIGHTRED, string);
	SendAdm(playerid, "You have allowed the movement of %s(%d).", AccountData[otherid][pName], otherid);

	return 1;
}

YCMD:spectate(playerid, params[], help)
{
    if (AccountData[playerid][pAdmin] < 1 && !AccountData[playerid][pSteward] && !AccountData[playerid][pApprentice])
     	return PermissionError(playerid);

    if (!isnull(params) && !strcmp(params, "off", true))
    {
        if (GetPlayerState(playerid) != PLAYER_STATE_SPECTATING || AccountData[playerid][pSpec] == INVALID_PLAYER_ID)
            return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda saat ini tidak sedang dalam mode spec!");

        SetSpawnInfo(playerid, NO_TEAM, AccountData[playerid][pSkin], AccountData[playerid][pPos][0], AccountData[playerid][pPos][1], AccountData[playerid][pPos][2], AccountData[playerid][pPos][3], 0, 0, 0, 0, 0, 0);
        TogglePlayerSpectating(playerid, false);

        PlayerSpectatePlayer(playerid, INVALID_PLAYER_ID);
        PlayerSpectateVehicle(playerid, INVALID_VEHICLE_ID);
		AccountData[playerid][pSpec] = INVALID_PLAYER_ID;

        PlayerTextDrawHide(playerid, SpecInfoTD[playerid]);
		ShowTDN(playerid, NOTIFICATION_INFO, "Anda telah keluar dari mode spectator.");
        return 1;
    }

	new otherid;
    if (sscanf(params, "d", otherid))
    	return SUM(playerid, "/spec [playerid] (Use '/spec off' to exit spectator mode)");

    if (!IsPlayerConnected(otherid))
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Pemain tersebut tidak terkoneksi ke server!");

	if (otherid == playerid)
		return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda tidak dapat spec diri sendiri!");

    if (AccountData[playerid][pAdmin] < AccountData[otherid][pAdmin])
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda tidak dapat spec admin yang lebih tinggi!");

	if (!AccountData[otherid][pSpawned])
	    return ShowTDN(playerid, NOTIFICATION_ERROR, sprintf("Player %s(%i) belum spawn!", AccountData[otherid][pName], otherid));

    if (GetPlayerState(playerid) != PLAYER_STATE_SPECTATING)
    {
        GetPlayerPos(playerid, AccountData[playerid][pPos][0], AccountData[playerid][pPos][1], AccountData[playerid][pPos][2]);
        GetPlayerFacingAngle(playerid, AccountData[playerid][pPos][3]);

        AccountData[playerid][pInterior] = GetPlayerInterior(playerid);
        AccountData[playerid][pWorld] = GetPlayerVirtualWorld(playerid);
    }
    SetPlayerInterior(playerid, GetPlayerInterior(otherid));
    SetPlayerVirtualWorld(playerid, GetPlayerVirtualWorld(otherid));
    
    TogglePlayerSpectating(playerid, true);

    static string[144];

    new Float:health, Float:armour, keys, ups, lefts, Float:vhealth;
    GetPlayerHealth(otherid, health);
    GetPlayerArmour(otherid, armour);
    GetPlayerKeys(otherid, keys, ups, lefts);
    if(IsPlayerInAnyVehicle(otherid) && Iter_Contains(Vehicle, GetPlayerVehicleID(otherid)))
	{
		new vID = GetVehicleModel(GetPlayerVehicleID(otherid));
        PlayerSpectateVehicle(playerid, GetPlayerVehicleID(otherid));
		if (GetPlayerState(otherid) == PLAYER_STATE_DRIVER)
	    {
            GetVehicleHealth(GetPlayerVehicleID(otherid), vhealth);
            format(string, sizeof(string), "%s (%d)~n~HP: %.2f~n~AP: %.2f~n~vHP: %.2f~n~Cash: $%s~n~World: %d // Int: %d~n~Keys: %d %d %d~n~FPS: %d // Ping: %d", AccountData[otherid][pName], otherid, health, armour, vhealth, FormatMoney(AccountData[otherid][pMoney]), GetPlayerVirtualWorld(otherid), GetPlayerInterior(otherid), keys, ups, lefts, GetPlayerFPS(otherid), GetPlayerPing(otherid));
            PlayerTextDrawSetString(playerid, SpecInfoTD[playerid], string);
            PlayerTextDrawShow(playerid, SpecInfoTD[playerid]);

			SendAdm(playerid, "You are spectating %s(%i) who is currently driving %s(%d).", AccountData[otherid][pName], otherid, GetVehicleModelName(vID), GetPlayerVehicleID(otherid));
		}
		else
		{
            format(string, sizeof(string), "%s (%d)~n~HP: %.2f~n~AP: %.2f~n~Cash: $%s~n~World: %d // Int: %d~n~Keys: %d %d %d~n~FPS: %d // Ping: %d", AccountData[otherid][pName], otherid, health, armour, FormatMoney(AccountData[otherid][pMoney]), GetPlayerVirtualWorld(otherid), GetPlayerInterior(otherid), keys, ups, lefts, GetPlayerFPS(otherid), GetPlayerPing(otherid));
            PlayerTextDrawSetString(playerid, SpecInfoTD[playerid], string);
            PlayerTextDrawShow(playerid, SpecInfoTD[playerid]);

		    SendAdm(playerid, "You are spectating %s(%i) who is a passenger in %s(%d).", AccountData[otherid][pName], otherid, GetVehicleModelName(vID), GetPlayerVehicleID(otherid));
		}
	}
    else
	{
        PlayerSpectatePlayer(playerid, otherid);
        format(string, sizeof(string), "%s (%d)~n~HP: %.2f~n~AP: %.2f~n~Cash: $%s~n~World: %d // Int: %d~n~Keys: %d %d %d~n~FPS: %d // Ping: %d", AccountData[otherid][pName], otherid, health, armour, FormatMoney(AccountData[otherid][pMoney]), GetPlayerVirtualWorld(otherid), GetPlayerInterior(otherid), keys, ups, lefts, GetPlayerFPS(otherid), GetPlayerPing(otherid));
        PlayerTextDrawSetString(playerid, SpecInfoTD[playerid], string);
        PlayerTextDrawShow(playerid, SpecInfoTD[playerid]);
	}
    AccountData[playerid][pSpec] = otherid;
    SendStaffMessage(Y_LIGHTRED, "AdmCmd: %s is spectating %s (%d).", AccountData[playerid][pAdminname], AccountData[otherid][pName], otherid);
    return 1;
}

YCMD:spec(playerid, params[], help) = spectate;

YCMD:slap(playerid, params[], help)
{
	if (AccountData[playerid][pAdmin] < 1 && !AccountData[playerid][pSteward])
		return PermissionError(playerid);
			
	new Float:POS[3], otherid;
	if (sscanf(params, "d", otherid))
	    return SUM(playerid, "/slap [playerid]");

	if (!IsPlayerConnected(otherid))
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Pemain tersebut tidak terkoneksi ke server!");

	GetPlayerPos(otherid, POS[0], POS[1], POS[2]);
	SetPlayerPos(otherid, POS[0], POS[1], POS[2] + 9.0);
	if (IsPlayerInAnyVehicle(otherid)) 
	{
		RemovePlayerFromVehicle(otherid);
	}
	SendAdm(playerid, "You have used '/slap' on %s(%d).", AccountData[otherid][pName], otherid);

	PlayerPlaySound(otherid, 1130, 0.0, 0.0, 0.0);

	return 1;
}

YCMD:aeject(playerid, params[], help)
{
	if (AccountData[playerid][pAdmin] < 1)
		return PermissionError(playerid);

	new otherid, vID;
	if (sscanf(params, "d", otherid))
	    return SUM(playerid, "/aeject [playerid]");

	if (!IsPlayerConnected(otherid))
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Pemain tersebut tidak terkoneksi ke server!");

	if (!IsPlayerInAnyVehicle(otherid))
		return ShowTDN(playerid, NOTIFICATION_ERROR, "Pemain tersebut tidak berada di dalam kendaraan!");

	static string[144];
	vID = GetVehicleModel(GetPlayerVehicleID(otherid));
	format(string, sizeof(string), "AdmCmd: %s has forcibly ejected you from %s.", AccountData[playerid][pAdminname], GetVehicleModelName(vID));
	SendClientMessage(otherid, X11_LIGHTBLUE, string);
	SendAdm(playerid, "You have forcibly ejected %s(%d) from %s.", AccountData[otherid][pName], otherid, GetVehicleModelName(vID));
	RemovePlayerFromVehicle(otherid);

	return 1;
}

YCMD:checkwarns(playerid, params[], help)
{
	if(AccountData[playerid][pAdmin] < 1 && !AccountData[playerid][pSteward])
		return PermissionError(playerid);

	new otherid;
	if(sscanf(params, "u", otherid))
        return SUM(playerid, "/checkwarns [playerid/name]");

	if(!IsPlayerConnected(otherid))
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Pemain tersebut tidak terkoneksi ke server!");

	if(!AccountData[otherid][IsLoggedIn])
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Pemain tersebut belum login ke server!");

	static string[1024], count;
	count = 0;
	format(string, sizeof(string), "Type\tIssuer\tDate\tReason\n");
	for (new id; id < 100; ++id)
	{
		if (PlayerWarning[otherid][id][warnExists] && PlayerWarning[otherid][id][warnOwner] == AccountData[otherid][pID]) 
		{
			switch (PlayerWarning[otherid][id][warnType])
			{
				case 1:
				{
					format(string, sizeof(string), "%s"GREEN"[WARN]\t"WHITE"%s\t%s\t%s\n", string, PlayerWarning[otherid][id][warnIssuer], PlayerWarning[otherid][id][warnDate], PlayerWarning[otherid][id][warnReason]);
				}
				case 2:
				{
					format(string, sizeof(string), "%s"YELLOW"[JAIL]\t"WHITE"%s\t%s\t%s\n", string, PlayerWarning[otherid][id][warnIssuer], PlayerWarning[otherid][id][warnDate], PlayerWarning[otherid][id][warnReason]);
				}
				case 3:
				{
					format(string, sizeof(string), "%s"ORANGERED"[BAN]\t"WHITE"%s\t%s\t%s\n", string, PlayerWarning[otherid][id][warnIssuer], PlayerWarning[otherid][id][warnDate], PlayerWarning[otherid][id][warnReason]);
				}
			}
			PlayerListitem[playerid][count++] = id;
		}
	}

	if (count == 0)
	{
		Dialog_Show(playerid, "UnusedDialog", DIALOG_STYLE_MSGBOX, sprintf("Warning History of %s", AccountData[otherid][pName]), "The player has no warning history!", "Tutup", "");
	}
	else
	{
		Temptargetid[playerid] = otherid;
		Dialog_Show(playerid, "CheckWarns", DIALOG_STYLE_TABLIST_HEADERS, sprintf("Warning History of %s", AccountData[otherid][pName]), string, "Pilih", "Tutup");
	}
	return 1;
}

YCMD:astats(playerid, params[], help)
{
	if (AccountData[playerid][pAdmin] < 1 && !AccountData[playerid][pSteward])
		return PermissionError(playerid);

	new otherid;
	if (sscanf(params, "d", otherid))
        return SUM(playerid, "/astats [playerid]");

	if (!IsPlayerConnected(otherid))
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Pemain tersebut tidak terkoneksi ke server!");

	if (!AccountData[otherid][IsLoggedIn])
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Pemain tersebut belum login!");

	ShowPlayerStats(playerid, otherid);

	return 1;
}

YCMD:ostats(playerid, params[], help)
{
	if (AccountData[playerid][pAdmin] < 1 && !AccountData[playerid][pSteward])
		return PermissionError(playerid);
			
	new name[24];
	if(sscanf(params, "s[24]", name))
	    return SUM(playerid, "/ostats [Nick_Name]");

 	foreach(new i : Player) if(IsPlayerConnected(i))
	{
		if(AccountData[i][IsLoggedIn] && AccountData[i][pSpawned])
		{
			if(!strcmp(name, AccountData[i][pName], true)) return ShowTDN(playerid, NOTIFICATION_ERROR, "Pemain tersebut sedang online, gunakan ~b~/astats");
		}
	}

	// Load User Data
    new cVar[1200];
    new cQuery[1200];

	strcat(cVar, "pID, Char_UCP, Char_Name, Char_Birthday, Char_Origin, Char_Gender, Char_BodyHeight,");
	strcat(cVar, "Char_BodyWeight, Char_Job, Char_Faction, Char_FactionRank, Char_Family, Char_FamilyRank, Char_Money, Char_BankMoney, Char_CasinoChip, Char_DirtyMoney, Char_Health, Char_Armor, Char_Hunger, Char_Thirst, Char_Stress, Char_Warn, Char_Level, Char_Hours, Char_Minutes, Char_Seconds, Char_Admin, Char_Steward, Char_StewTime, Char_VIP, Char_VIPTime,");
	strcat(cVar, "Char_Skin, Char_WID, Char_IntID, Char_InHouse, Char_InDoor, Char_InRusun, Char_LastLogin, Char_RegisterDate");

	mysql_format(g_SQL, cQuery, sizeof(cQuery), "SELECT %s FROM `player_characters` WHERE `Char_Name`='%e' LIMIT 1", cVar, name);
	mysql_pquery(g_SQL, cQuery, "LoadStats", "is", playerid, name);
	return 1;
}

YCMD:checkucp(playerid, params[], help)
{
    if (AccountData[playerid][pAdmin] < 1 && !AccountData[playerid][pSteward])
        return PermissionError(playerid);

    new name[22];
    if (sscanf(params, "s[22]", name))
        return SUM(playerid, "/checkucp [ucp]");

    // Load User Data
    new cVar[500];
    new cQuery[600];

    strcat(cVar, "ID, UCP, IP, Register_Date, Last_Login");

    mysql_format(g_SQL, cQuery, sizeof(cQuery), "SELECT %s FROM `player_ucp` WHERE `UCP`='%e' LIMIT 1", cVar, name);
    mysql_pquery(g_SQL, cQuery, "CheckingUCP", "is", playerid, name);
    return 1;
}

YCMD:acharlist(playerid, params[], help)
{
    if (AccountData[playerid][pAdmin] < 1 && !AccountData[playerid][pSteward])
        return PermissionError(playerid);

    new name[22];
    if (sscanf(params, "s[22]", name))
        return SUM(playerid, "/acharlist [ucp]");

    new cQuery[512];
    mysql_format(g_SQL, cQuery, sizeof(cQuery), "SELECT * FROM `player_ucp` WHERE `UCP`='%e' LIMIT 1", name);
    mysql_pquery(g_SQL, cQuery, "CheckingCharList", "is", playerid, name);
    return 1;
}

YCMD:getip(playerid, params[], help)
{
    if (AccountData[playerid][pAdmin] < 1 && !AccountData[playerid][pSteward])
        return PermissionError(playerid);

    new otherid, PlayerIP[16], giveplayer[24];
    if (sscanf(params, "d", otherid))
        return SUM(playerid, "/getip [playerid]");

    if (!IsPlayerConnected(otherid))
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Pemain tersebut tidak terkoneksi ke server!");

    static string[144];
    if (AccountData[otherid][pAdmin] >= 6) {
        ShowTDN(playerid, NOTIFICATION_ERROR, "Anda tidak dapat melihat IP admin lebih tinggi!");
        format(string, sizeof(string), "AdmCmd: %s(%i) attempted to view your IP Address.", AccountData[playerid][pAdminname], playerid);
        SendClientMessage(otherid, Y_LIGHTRED, string);
        return 1;
    }

    GetPlayerName(otherid, giveplayer, sizeof(giveplayer));
    GetPlayerIp(otherid, PlayerIP, sizeof(PlayerIP));

    format(string, sizeof(string), "AdmCmd: IP Address of %s(%i): %s", giveplayer, otherid, PlayerIP);
    SendClientMessage(playerid, Y_LIGHTRED, string);
    return 1;
}

YCMD:ojail(playerid, params[], help)
{
    if (AccountData[playerid][pAdmin] < 1)
        return PermissionError(playerid);

    new player[24], datez, tmp[64], PlayerName[MAX_PLAYER_NAME];
    if (sscanf(params, "s[24]ds[64]", player, datez, tmp))
        return SUM(playerid, "/ojail [Account_Name] [minutes] [reason]");

    if (strlen(tmp) > 32) return ShowTDN(playerid, NOTIFICATION_ERROR, "Reason maksimum adalah 32 karakter!");
    if (datez < 1)
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Minimal waktu jail adalah 1 menit!");

    foreach (new ii : Player) {
        GetPlayerName(ii, PlayerName, MAX_PLAYER_NAME);

        if (strfind(PlayerName, player, true) != -1)
            return ShowTDN(playerid, NOTIFICATION_ERROR, "Pemain tersebut sedang online, gunakan '/jail'!");
    }
    new query[512];
    mysql_format(g_SQL, query, sizeof(query), "SELECT * FROM `player_characters` WHERE `Char_Name`='%e'", player);
    mysql_pquery(g_SQL, query, "OSendPlayerToJailAdmin", "issd", playerid, player, tmp, datez);
    return 1;
}

YCMD:jail(playerid, params[], help)
{
    if(AccountData[playerid][pAdmin] < 1)
        return PermissionError(playerid);

    new reason[64], timeSec, fine, otherid;
    if (sscanf(params, "dD(15)ds[64]", otherid, timeSec, fine, reason))
        return SUM(playerid, "/jail [playerid] [minutes] [fine] [reason]");

    if (!IsPlayerConnected(otherid))
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Pemain tersebut tidak terkoneksi ke dalam server!");

    static string[144];
    if (OJailData[otherid][jailed]) 
    {
        format(string, sizeof(string), "[Jail] %s(%i) sedang dijail admin (Remaining %d minutes).", AccountData[otherid][pName], otherid, OJailData[otherid][jailTime] / 60);
        SendClientMessage(playerid, X11_LIGHTBLUE, string);
        SUM(playerid, "/unjail [playerid] untuk membebaskannya!");
        return 1;
    }

    if(!AccountData[otherid][pSpawned]) return ShowTDN(playerid, NOTIFICATION_ERROR, sprintf("Player %s(%i) belum spawn!", AccountData[otherid][pName], otherid));

    if(strlen(reason) > 64)
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Reason maksimum adalah 64 karakter!");
        
    if(timeSec < 1)
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Waktu jail minimum adalah 1 menit!");

    OJailData[otherid][jailed] = true;
    strcopy(OJailData[otherid][jailAdmin], AccountData[playerid][pAdminname]);
    OJailData[otherid][jailTime] = timeSec * 60;
    OJailData[otherid][jailDur] = timeSec;
    strcopy(OJailData[otherid][jailReason], reason);
    OJailData[otherid][jailFine] = fine;        
    TakePlayerMoneyEx(otherid, fine);

    SendPlayerToJailAdmin(otherid);

    foreach (new i : Player)
    {
        if (AccountData[i][pSpawned] && ToggleInfo[i][TogAdmCmd]) {
            format(string, sizeof(string), "AdmCmd: %s(%i) has been OOC jailed by %s for %d minutes.", AccountData[otherid][pName], otherid, AccountData[playerid][pAdminname], timeSec);
            SendClientMessage(i, Y_LIGHTRED, string);
            format(string, sizeof(string), "Reason: %s", reason);
            SendClientMessage(i, Y_LIGHTRED, string);
        }
    }

    format(string, sizeof(string), "[Jail] Anda telah dijail OOC oleh %s selama %d menit, denda $%s [%s].", AccountData[playerid][pAdminname], timeSec, FormatMoney(fine), reason);
    SendClientMessage(otherid, Y_LIGHTRED, string);

    static year, month, day, keidwa[100], warsc[512];
    getdate(year, month, day);
    format(keidwa, sizeof(keidwa), "%02d/%02d/%d", day, month, year);

    for (new id; id < 100; ++id) {
        if (!PlayerWarning[otherid][id][warnExists]) {
            PlayerWarning[otherid][id][warnExists] = true;
            PlayerWarning[otherid][id][warnOwner] = AccountData[otherid][pID];
            PlayerWarning[otherid][id][warnType] = 2;
            strcopy(PlayerWarning[otherid][id][warnIssuer], AccountData[playerid][pAdminname]);
            strcopy(PlayerWarning[otherid][id][warnDate], keidwa);
            strcopy(PlayerWarning[otherid][id][warnDateTime], GetAdvTime());
            strcopy(PlayerWarning[otherid][id][warnReason], reason);
            break;
        }
    }

    mysql_format(g_SQL, warsc, sizeof(warsc), "INSERT INTO `player_warns` SET `Owner_ID` = %d, `Date` = '%e', `Date_Time` = '%e', `Issuer` = '%e', `Type` = 2, `Reason` = '%e'",
        AccountData[otherid][pID], keidwa, GetAdvTime(), AccountData[playerid][pAdminname], reason);
    mysql_pquery(g_SQL, warsc);

    return 1;
}

YCMD:kick(playerid, params[], help)
{
    static reason[64];

    if (AccountData[playerid][pAdmin] < 1 && !AccountData[playerid][pSteward])
        return PermissionError(playerid);

    new otherid;
    if (sscanf(params, "us[64]", otherid, reason))
        return SUM(playerid, "/kick [playerid/name] [reason]");

    if (!IsPlayerConnected(otherid))
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Pemain tersebut tidak terkoneksi ke server!");

    static string[144];

    ShowKickTD(otherid, AccountData[playerid][pAdminname], reason);

    foreach (new i : Player) if (AccountData[i][pSpawned] && ToggleInfo[i][TogAdmCmd]) {
        format(string, sizeof(string), "AdmCmd: %s(%d) has been kicked from the server by %s", AccountData[otherid][pName], otherid, AccountData[playerid][pAdminname]);
        SendClientMessage(i, Y_LIGHTRED, string);
        format(string, sizeof(string), "Reason: %s", reason);
        SendClientMessage(i, Y_LIGHTRED, string);
    }
    KickEx(otherid);
    return 1;
}

YCMD:acuff(playerid, params[], help)
{
    if (AccountData[playerid][pAdmin] < 1)
        return PermissionError(playerid);

    new otherid;
    if (sscanf(params, "i", otherid))
        return SUM(playerid, "/acuff [playerid]");

    if (!IsPlayerConnected(otherid))
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Pemain tersebut tidak terkoneksi ke server!");

    if (otherid == playerid)
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda tidak dapat melakukannya terhadap diri sendiri!");

    if (GetPlayerState(otherid) != PLAYER_STATE_ONFOOT)
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Pemain tersebut harus berjalan kaki!");

    if (AccountData[otherid][pCuffed])
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Pemain tersebut sedang diborgol!");

    AccountData[otherid][pCuffed] = true;

    GameTextForPlayer(otherid, "~r~Terborgol", 3500, 3);
    SetPlayerSpecialAction(otherid, SPECIAL_ACTION_CUFFED);

    static string[144];
    format(string, sizeof(string), "AdmCmd: "RED"%s "WHITE"has handcuffed you.", AccountData[playerid][pAdminname]);
    SendClientMessage(otherid, X11_LIGHTBLUE, string);

    SendAdm(playerid, "You have handcuffed "YELLOW"%s(%d).", AccountData[otherid][pName], otherid);

    return 1;
}

YCMD:auncuff(playerid, params[], help)
{
    if (AccountData[playerid][pAdmin] < 1)
        return PermissionError(playerid);

    new otherid;
    if (sscanf(params, "i", otherid))
        return SUM(playerid, "/auncuff [playerid]");

    if (!IsPlayerConnected(otherid))
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Pemain tersebut tidak terkoneksi ke server!");

    if (!AccountData[otherid][pCuffed])
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Pemain tersebut tidak sedang diborgol!");

    AccountData[otherid][pCuffed] = false;
    GameTextForPlayer(otherid, "~g~Borgol terlepas", 3500, 3);
    SetPlayerSpecialAction(otherid, SPECIAL_ACTION_NONE);

    static string[144];
    format(string, sizeof(string), "AdmCmd: %s has released your handcuffs.", AccountData[playerid][pAdminname]);
    SendClientMessage(otherid, Y_LIGHTRED, string);
    SendAdm(playerid, "You have released %s's handcuffs.", AccountData[otherid][pName]);

    return 1;
}

YCMD:aka(playerid, params[], help)
{
    if (AccountData[playerid][pAdmin] < 1)
        return PermissionError(playerid);

    new otherid, PlayerIP[16], query[128];
    if (sscanf(params, "d", otherid))
        return SUM(playerid, "/aka [ID]");

    if (!IsPlayerConnected(otherid))
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Pemain tersebut tidak terkoneksi ke server!");

    if (AccountData[otherid][pAdmin] == 5) {
        ShowTDN(playerid, NOTIFICATION_ERROR, "Anda tidak dapat melakukannya kepada admin level 5!");
        return SendClientMessageEx(playerid, -1, "Player "YELLOW"%s(%i) "WHITE"mencoba untuk /aka terhadap anda!", AccountData[playerid][pAdminname], playerid);
    }

    GetPlayerIp(otherid, PlayerIP, sizeof(PlayerIP));
    mysql_format(g_SQL, query, sizeof(query), "SELECT `UCP` FROM `player_ucp` WHERE `IP`='%e'", PlayerIP);
    mysql_pquery(g_SQL, query, "CheckPlayerIP", "is", playerid, PlayerIP);

    return 1;
}

YCMD:akaip(playerid, params[], help)
{
    if (AccountData[playerid][pAdmin] < 1)
        return PermissionError(playerid);

    new query[128];
    if (isnull(params))
        return SUM(playerid, "/akaip [IP]");

    mysql_format(g_SQL, query, sizeof(query), "SELECT `UCP` FROM `player_ucp` WHERE `IP`='%e'", params);
    mysql_pquery(g_SQL, query, "CheckPlayerIP2", "is", playerid, params);
    return 1;
}

YCMD:vmodels(playerid, params[], help)
{
    static string[2000];

    if (AccountData[playerid][pAdmin] < 1)
        return PermissionError(playerid);

    for (new i = 0; i < sizeof(g_arrVehicleNames); i++) {
        format(string, sizeof(string), "%s%d - %s\n", string, i + 400, g_arrVehicleNames[i]);
    }
    Dialog_Show(playerid, "UnusedDialog", DIALOG_STYLE_LIST, "Vehicle Models", string, "Tutup", "");

    return 1;
}

YCMD:vehname(playerid, params[], help)
{
    if (AccountData[playerid][pAdmin] < 1)
        return PermissionError(playerid);

    SendClientMessage(playerid, X11_ROYALBLUE, "|______________________________|");
    SendClientMessage(playerid, X11_LIGHTGOLDENRODYELLOW, "Vehicle Search:");

    new string[128];

    if (isnull(params)) return ShowTDN(playerid, NOTIFICATION_ERROR, "Keyword kurang specific!");
    if (!params[2]) return ShowTDN(playerid, NOTIFICATION_ERROR, "Keyword terlalu singkat!");

    for (new v; v < sizeof(g_arrVehicleNames); v++) {
        if (strfind(g_arrVehicleNames[v], params, true) != -1) {

            if (isnull(string)) format(string, sizeof(string), "%s (ID %d)", g_arrVehicleNames[v], v + 400);
            else format(string, sizeof(string), "%s | %s (ID %d)", string, g_arrVehicleNames[v], v + 400);
        }
    }

    if (!string[0]) ShowTDN(playerid, NOTIFICATION_ERROR, "Tidak ditemukan dari hasil pencarian!");
    else if (string[127]) ShowTDN(playerid, NOTIFICATION_ERROR, "Terlalu banyak hasil pencarian!");
    else SendClientMessageEx(playerid, X11_WHITE, string);

    SendClientMessage(playerid, X11_LIGHTGOLDENRODYELLOW, "--------------------------------------------------------------------------------------------------------------------------------");

    return 1;
}

YCMD:owarn(playerid, params[], help)
{
	if(AccountData[playerid][pAdmin] < 1)
	    return PermissionError(playerid);

	new player[24], tmp[50], PlayerName[MAX_PLAYER_NAME];
	if(sscanf(params, "s[24]s[50]", player, tmp))
		return SUM(playerid, "/owarn [name] [reason]");

	if(strlen(tmp) > 50) return ShowTDN(playerid, NOTIFICATION_ERROR, "Maksimum reason adalah 50 karakter!");

	foreach(new ii : Player)
	{
		GetPlayerName(ii, PlayerName, MAX_PLAYER_NAME);

	    if(!strcmp(PlayerName, player, true))
			return ShowTDN(playerid, NOTIFICATION_ERROR, "Pemain tersebut sedang online, gunakan '/warn' terhadapnya!");

	}
	new query[512];
	mysql_format(g_SQL, query, sizeof(query), "SELECT `pID`, `Char_Warn`, `Char_UCP` FROM `player_characters` WHERE `Char_Name`='%e'", player);
	mysql_pquery(g_SQL, query, "OWarnPlayer", "iss", playerid, player, tmp);
	return 1;
}

YCMD:warn(playerid, params[], help)
{
    if(AccountData[playerid][pAdmin] < 1)
		return PermissionError(playerid);

	new otherid, reason[64];
    if(sscanf(params, "ds[64]", otherid, reason))
        return SUM(playerid, "/warn [playerid] [reason]");

    if(!IsPlayerConnected(otherid))
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Pemain tersebut tidak terkoneksi ke server!");

	if(strlen(reason) > 64) return ShowTDN(playerid, NOTIFICATION_ERROR, "Maksimum reason adadlah 64 karakter!");

    if(AccountData[otherid][pAdmin] > AccountData[playerid][pAdmin])
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda tidak dapat melakukannya terhadap admin lebih tinggi!");

	if(AccountData[otherid][pWarn] >= MAX_PWARNS)
		return ShowTDN(playerid, NOTIFICATION_ERROR, "Pemain tersebut telah mencapai batas maksimum warn!");

	AccountData[otherid][pWarn]++;

	static string[144];
	foreach(new i : Player) if(AccountData[i][pSpawned] && ToggleInfo[i][TogAdmCmd])
	{
		format(string, sizeof(string), "AdmCmd: %s(%i) has been warned by %s [Total: %d/20]", AccountData[otherid][pName], otherid, AccountData[playerid][pAdminname], AccountData[otherid][pWarn]);
		SendClientMessage(i, Y_LIGHTRED, string);
		format(string, sizeof(string), "Reason: %s", reason);
		SendClientMessage(i, Y_LIGHTRED, string);
	}

    ShowWarningTD(otherid, AccountData[playerid][pAdminname], reason);

	static year, month, day, keidwa[100], warsc[512];
	getdate(year, month, day);
	format(keidwa, sizeof(keidwa), "%02d/%02d/%d", day, month, year);

	for(new id; id < 100; ++id)
	{
		if(!PlayerWarning[otherid][id][warnExists])
		{
			PlayerWarning[otherid][id][warnExists] = true;
			PlayerWarning[otherid][id][warnOwner] = AccountData[otherid][pID];
			PlayerWarning[otherid][id][warnType] = 1;
			strcopy(PlayerWarning[otherid][id][warnIssuer], AccountData[playerid][pAdminname]);
			strcopy(PlayerWarning[otherid][id][warnDate], keidwa);
			strcopy(PlayerWarning[otherid][id][warnDateTime], GetAdvTime());
			strcopy(PlayerWarning[otherid][id][warnReason], reason);
			break;
		}
	}

	mysql_format(g_SQL, warsc, sizeof(warsc), "INSERT INTO `player_warns` SET `Owner_ID` = %d, `Date` = '%e', `Date_Time` = '%e', `Issuer` = '%e', `Type` = 1, `Reason` = '%e'",
	AccountData[otherid][pID], keidwa, GetAdvTime(), AccountData[playerid][pAdminname], reason);
	mysql_pquery(g_SQL, warsc);

	if(AccountData[otherid][pWarn] >= MAX_PWARNS)
	{
		static query[522];
		mysql_format(g_SQL, query, sizeof(query), "UPDATE `player_ucp` SET `Blocked`=1, `Block_Duration`=0, `Block_Reason`='20 Warns', `Block_AdminName`='Arivena AntiCheat', `Block_IssuedDate`=CURRENT_TIMESTAMP() WHERE `UCP`='%e'", AccountData[otherid][pUCP]);
		mysql_pquery(g_SQL, query);
		return KickEx(otherid);
	}

	return 1;
}

YCMD:unwarn(playerid, params[], help)
{
    if(AccountData[playerid][pAdmin] < 1)
		return PermissionError(playerid);

	new otherid, reason[64];
    if(sscanf(params, "ds[64]", otherid, reason))
        return SUM(playerid, "/unwarn [playerid] [reason]");

    if(!IsPlayerConnected(otherid))
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Pemain tersebut tidak terkoneksi ke server!");

	if(AccountData[otherid][pWarn] == 0)
		return ShowTDN(playerid, NOTIFICATION_ERROR, "Pemain tersebut tidak memiliki warning!");

    AccountData[otherid][pWarn]--;

	static string[144];
	foreach(new i : Player) if(AccountData[i][pSpawned] && ToggleInfo[i][TogAdmCmd])
	{
		format(string, sizeof(string), "AdmCmd: %s has removed 1 warning from %s(%d).", AccountData[playerid][pAdminname], AccountData[otherid][pName], otherid);
		SendClientMessage(i, Y_LIGHTRED, string);
		format(string, sizeof(string), "Reason: %s", reason);
		SendClientMessage(i, Y_LIGHTRED, string);
	}
	return 1;
}

YCMD:setvw(playerid, params[], help)
{
	if(AccountData[playerid][pAdmin] < 1)
        return PermissionError(playerid);
	
	new jumlah, otherid;
	if(sscanf(params, "dd", otherid, jumlah))
        return SUM(playerid, "/setvw [playerid id] [virtual world]");
	
	if(!IsPlayerConnected(otherid))
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Pemain tersebut tidak terkoneksi ke server!");
		
	SetPlayerVirtualWorldEx(otherid, jumlah);

	static string[144];
	format(string, sizeof(string), "AdmCmd: %s has set your Virtual World ID.", AccountData[playerid][pAdminname]);
	SendClientMessage(otherid, Y_LIGHTRED, string);
	SendAdm(playerid, "You have set VWID %s(%d) - %d.", AccountData[otherid][pName], otherid, jumlah);
	
	return 1;
}

YCMD:setint(playerid, params[], help)
{
    if(AccountData[playerid][pAdmin] < 1)
        return PermissionError(playerid);

    new giveplayerid, int;
    if(sscanf(params, "dd", giveplayerid, int)) return SUM(playerid, "/setint [playerid] [interiorid]");

    if(!IsPlayerConnected(giveplayerid))
    	return ShowTDN(playerid, NOTIFICATION_ERROR, "Pemain tersebut tidak terkoneksi ke server!");

    SetPlayerInterior(giveplayerid, int);

	static string[144];
    format(string, sizeof(string), "AdmCmd: %s has set your Interior ID.", AccountData[playerid][pAdminname]);
	SendClientMessage(giveplayerid, Y_LIGHTRED, string);
	SendAdm(playerid, "You have set INT ID %s(%d) - %d.", AccountData[giveplayerid][pName], giveplayerid, int);
    
	return 1;
}

YCMD:avehlist(playerid, params[], help)
{
	if(AccountData[playerid][pAdmin] < 1 && !AccountData[playerid][pSteward])
		return PermissionError(playerid);

	new otherid;
	if(sscanf(params, "i", otherid)) return SUM(playerid, "/avehlist [playerid]");
	if(otherid == INVALID_PLAYER_ID || !IsPlayerConnected(otherid)) return ShowTDN(playerid, NOTIFICATION_ERROR, "Pemain tersebut tidak terkoneksi di server!");

	new bool:found = false, msg2[1618];
	format(msg2, sizeof(msg2), "VID\tModel [Database ID]\tPlate\t/ Rental / Status\n");
	foreach(new i : PvtVehicles)
	{
		if(PlayerVehicle[i][pVehOwnerID] == AccountData[otherid][pID])
		{
			if(strcmp(PlayerVehicle[i][pVehPlate], "-")) // If it has a plate
			{
				if(PlayerVehicle[i][pVehRentTime] != 0) // If it's a rental and has a plate
				{
					format(msg2, sizeof(msg2), "%s%s\t%s [%d]\t%s\t/ %s / %s\n", msg2,  (PlayerVehicle[i][pVehPhysic] == INVALID_VEHICLE_ID) ? ("[Not Spawned]") : (sprintf("[%d]", PlayerVehicle[i][pVehPhysic])), GetVehicleModelName(PlayerVehicle[i][pVehModelID]), PlayerVehicle[i][pVehID], PlayerVehicle[i][pVehPlate], ReturnTimelapse(gettime(), PlayerVehicle[i][pVehRentTime], ""YELLOW"Rental Expired"WHITE""), GetMyVehicleStatus(i));
					found = true;
				}
				else // If it's not a rental but has a plate
				{
					format(msg2, sizeof(msg2), "%s%s\t%s [%d]\t%s\t/ Dimiliki / %s\n", msg2, (PlayerVehicle[i][pVehPhysic] == INVALID_VEHICLE_ID) ? ("[Not Spawned]") : (sprintf("[%d]", PlayerVehicle[i][pVehPhysic])), GetVehicleModelName(PlayerVehicle[i][pVehModelID]), PlayerVehicle[i][pVehID], PlayerVehicle[i][pVehPlate], GetMyVehicleStatus(i));
					found = true;
				}
			}
			else // If it doesn't have a plate
			{
				if(PlayerVehicle[i][pVehRentTime] != 0) // If it's a rental but doesn't have a plate
				{
					format(msg2, sizeof(msg2), "%s%s\t%s [%d]\tTidak Ada Plat\t/ %s / %s\n", msg2, (PlayerVehicle[i][pVehPhysic] == INVALID_VEHICLE_ID) ? ("[Not Spawned]") : (sprintf("[%d]", PlayerVehicle[i][pVehPhysic])), GetVehicleModelName(PlayerVehicle[i][pVehModelID]), PlayerVehicle[i][pVehID], ReturnTimelapse(gettime(), PlayerVehicle[i][pVehRentTime], ""YELLOW"Rental Expired"WHITE""), GetMyVehicleStatus(i));
					found = true;
				}
				else // If it's not a rental and doesn't have a plate
				{
					format(msg2, sizeof(msg2), "%s%s\t%s [%d]\tTidak Ada Plat\t/ Dimiliki / %s\n", msg2, (PlayerVehicle[i][pVehPhysic] == INVALID_VEHICLE_ID) ? ("[Not Spawned]") : (sprintf("[%d]", PlayerVehicle[i][pVehPhysic])), GetVehicleModelName(PlayerVehicle[i][pVehModelID]), PlayerVehicle[i][pVehID], GetMyVehicleStatus(i));
					found = true;
				}
			}
		}
	}
	if(found)
		Dialog_Show(playerid, "UnusedDialog", DIALOG_STYLE_TABLIST_HEADERS, ""ARIVENA"Arivena Theater "WHITE"- Vehicle Ownership", msg2, "Tutup", "");
	else
		Dialog_Show(playerid, "UnusedDialog", DIALOG_STYLE_MSGBOX, ""ARIVENA"Arivena Theater "WHITE"- Vehicle Ownership", "You do not own any vehicles!", "Tutup", "");
	
	return 1;
}

YCMD:akill(playerid, params[], help)
{
    if(AccountData[playerid][pAdmin] < 1)
        return PermissionError(playerid);

	new otherid;
	if(sscanf(params, "d", otherid))
	    return SUM(playerid, "/akill [ID]");

    if(!IsPlayerConnected(otherid))
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Pemain tersebut tidak terkoneksi ke server!");

	SetPlayerHealth(otherid, 0.0);

	SendAdm(playerid, "You have forcely killed %s(%d).", AccountData[otherid][pName], otherid);

	return 1;
}

YCMD:ban(playerid, params[], help)
{
    if (AccountData[playerid][pAdmin] < 1)
        return PermissionError(playerid);

    new ban_time, datez, tmp[64], otherid;
    if (sscanf(params, "ids[64]", otherid, datez, tmp))
        return SUM(playerid, "/ban [ID] [duration (days) 0 for permanent] [reason]");

    if (!IsPlayerConnected(otherid))
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Pemain tersebut tidak terkoneksi ke server!");

    if (datez < 0) return ShowTDN(playerid, NOTIFICATION_ERROR, "Mohon masukkan durasi ban yang valid!");

    if (otherid == playerid)
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda tidak dapat melakukannya terhadap diri sendiri!");

    static string[144];
    if(AccountData[otherid][pAdmin] > AccountData[playerid][pAdmin])
    {
        format(string, sizeof(string), "AdmCmd: %s attempted to ban you.", AccountData[playerid][pAdminname]);
        SendClientMessage(otherid, Y_LIGHTRED, string);
        ShowTDN(playerid, NOTIFICATION_ERROR, "Anda tidak dapat melakukannya terhadap admin lebih tinggi!");
        return 1;
    }
    new PlayerIP[16], giveplayer[24];

    GetPlayerName(otherid, giveplayer, sizeof(giveplayer));
    GetPlayerIp(otherid, PlayerIP, sizeof(PlayerIP));

    if (datez != 0)
    {
        foreach (new i : Player) if (AccountData[i][pSpawned] && ToggleInfo[i][TogAdmCmd])
        {
            format(string, sizeof(string), "AdmCmd: %s set a ban status on %s(%d) for %d days.", AccountData[playerid][pAdminname], AccountData[otherid][pName], otherid, datez);
            SendClientMessage(i, Y_LIGHTRED, string);
            format(string, sizeof(string), "Reason: %s", tmp);
            SendClientMessage(i, Y_LIGHTRED, string);
        }
    }
    else
    {
        foreach (new i : Player) if (AccountData[i][pSpawned] && ToggleInfo[i][TogAdmCmd])
        {
            format(string, sizeof(string), "AdmCmd: %s set a permanent ban status on %s(%d).", AccountData[playerid][pAdminname], AccountData[otherid][pName], otherid);
            SendClientMessage(i, Y_LIGHTRED, string);
            format(string, sizeof(string), "Reason: %s", tmp);
            SendClientMessage(i, Y_LIGHTRED, string);
        }
    }
    BanPlayerMSG(otherid, playerid, tmp);
    if (datez != 0)
    {
        format(string, sizeof(string), "[Banned] This ban status will automatically expire in %d days.", datez);
        SendClientMessage(otherid, X11_LIGHTBLUE, string);
        ban_time = gettime() + (datez * 86400);
    }
    else
    {
        SendClientMessage(otherid, X11_LIGHTBLUE, "[Banned] This ban status is permanent; request an unban on Discord!");
        ban_time = datez;
    }
    new query[248];
    mysql_format(g_SQL, query, sizeof(query), "INSERT INTO `player_bans`(`name`, `ip`, `admin`, `reason`, `ban_date`, `ban_expire`) VALUES ('%e', '%e', '%e', '%e', %i, %d)", giveplayer, PlayerIP, AccountData[playerid][pAdminname], tmp, gettime(), ban_time);
    mysql_pquery(g_SQL, query);

    static year, month, day, keidwa[100], warsc[512];
    getdate(year, month, day);
    format(keidwa, sizeof(keidwa), "%02d/%02d/%d", day, month, year);

    for (new id; id < 100; ++id)
    {
        if (!PlayerWarning[otherid][id][warnExists])
        {
            PlayerWarning[otherid][id][warnExists] = true;
            PlayerWarning[otherid][id][warnOwner] = AccountData[otherid][pID];
            PlayerWarning[otherid][id][warnType] = 3;
            strcopy(PlayerWarning[otherid][id][warnIssuer], AccountData[playerid][pAdminname]);
            strcopy(PlayerWarning[otherid][id][warnDate], keidwa);
            strcopy(PlayerWarning[otherid][id][warnDateTime], GetAdvTime());
            strcopy(PlayerWarning[otherid][id][warnReason], tmp);
            break;
        }
    }

    mysql_format(g_SQL, warsc, sizeof(warsc), "INSERT INTO `player_warns` SET `Owner_ID` = %d, `Date` = '%e', `Date_Time` = '%e', `Issuer` = '%e', `Type` = 3, `Reason` = '%e'",
        AccountData[otherid][pID], keidwa, GetAdvTime(), AccountData[playerid][pAdminname], tmp);
    mysql_pquery(g_SQL, warsc);

    KickEx(otherid);
    return 1;
}

YCMD:oban(playerid, params[], help)
{
    if (AccountData[playerid][pAdmin] < 1)
        return PermissionError(playerid);

    new player[24], datez, reason[64];
    if (sscanf(params, "s[24]D(0)s[64]", player, datez, reason))
        return SUM(playerid, "/oban [Char_Name] [days (0 for permanent ban)] [reason]");

    if (strlen(reason) > 32) return ShowTDN(playerid, NOTIFICATION_ERROR, "Maksimum reason adalah 32 karakter!");

    foreach (new ii : Player)
    {
        new PlayerName[24];
        GetPlayerName(ii, PlayerName, MAX_PLAYER_NAME);

        if (strfind(PlayerName, player, true) != -1)
            return ShowTDN(playerid, NOTIFICATION_ERROR, "Pemain tersebut sedang online, gunakan '/ban'.");
    }

    new query[128];

    mysql_format(g_SQL, query, sizeof(query), "SELECT * FROM `player_characters` WHERE `Char_Name`='%e'", player);
    mysql_pquery(g_SQL, query, "OnOBanQueryData", "issi", playerid, player, reason, datez);
    return true;
}

YCMD:banip(playerid, params[], help)
{
    if(AccountData[playerid][pAdmin] < 1)
        return PermissionError(playerid);

    new iptoban[17];

    if (sscanf(params, "s[17]", iptoban))
        return SUM(playerid, "/banip [IP Address]");

    if(strfind(iptoban, "*", true) != -1 && AccountData[playerid][pAdmin] != 5)
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda tidak dapat ban range IP!");

    SendStaffMessage(Y_LIGHTRED, "AdmCmd: %s banned IP Address %s.", AccountData[playerid][pAdminname], iptoban);

    new tstr[128];
    format(tstr, sizeof(tstr), "banip %s", iptoban);
    SendRconCommand(tstr);
    return 1;
}

YCMD:blockucp(playerid, params[], help)
{
    if (AccountData[playerid][pAdmin] < 1)
        return PermissionError(playerid);

    new nameucp[22], haridur, reasonblock[60], totalblockdur;
    if (sscanf(params, "s[22]ds[60]", nameucp, haridur, reasonblock))
        return SUM(playerid, "/blockucp [UCP name] [duration (days) 0 for permanent] [reason]");

    if (haridur < 0) return ShowTDN(playerid, NOTIFICATION_ERROR, "Mohon masukkan durasi yang valid!");

    if (strlen(reasonblock) > 60) return ShowTDN(playerid, NOTIFICATION_ERROR, "Maksimum reason adalah 60 karakter!");

    if (haridur != 0)
    {
        totalblockdur = gettime() + (haridur * 86400);
    }
    else
    {
        totalblockdur = haridur;
    }

    new query[128];
    mysql_format(g_SQL, query, sizeof(query), "SELECT * FROM `player_ucp` WHERE `UCP` = '%e'", nameucp);
    mysql_pquery(g_SQL, query, "OnBlockingUCP", "isdds", playerid, nameucp, totalblockdur, haridur, reasonblock);
    return 1;
}

YCMD:reloadweap(playerid, params[], help)
{
    if (AccountData[playerid][pAdmin] < 1)
        return PermissionError(playerid);

    new otherid;
    if (sscanf(params, "d", otherid))
        return SUM(playerid, "/reloadweps [playerid]");

    if (!IsPlayerConnected(otherid))
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Pemain tersebut tidak terkoneksi ke server!");

    SetWeapons(otherid);

    static string[144];
    format(string, sizeof(string), "AdmCmd: %s has reloaded your weapons.", AccountData[playerid][pAdminname]);
    SendClientMessage(otherid, Y_LIGHTRED, string);

    SendAdm(playerid, "You have reloaded weapons for %s(%d).", AccountData[otherid][pName], otherid);

    return 1;
}

YCMD:resetweap(playerid, params[], help)
{
    if (AccountData[playerid][pAdmin] < 1)
        return PermissionError(playerid);

    new otherid;
    if (sscanf(params, "d", otherid))
        return SUM(playerid, "/resetweps [playerid]");

    if (!IsPlayerConnected(otherid))
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Pemain tersebut tidak terkoneksi ke server!");

    ResetPlayerWeaponsEx(otherid);

    static string[144];
    format(string, sizeof(string), "AdmCmd: %s has reset all your weapons.", AccountData[playerid][pAdminname]);
    SendClientMessage(otherid, Y_LIGHTRED, string);

    SendAdm(playerid, "You have reset weapons for %s(%d).", AccountData[otherid][pName], otherid);

    return 1;
}

YCMD:oresetweap(playerid, params[], help)
{
    if (AccountData[playerid][pAdmin] < 1)
        return PermissionError(playerid);

    new player[24], PlayerName[MAX_PLAYER_NAME];
    if (sscanf(params, "s[24]", player))
        return SUM(playerid, "/oresetweap [name]");

    foreach (new ii : Player)
    {
        GetPlayerName(ii, PlayerName, MAX_PLAYER_NAME);

        if (strfind(PlayerName, player, true) != -1)
            return ShowTDN(playerid, NOTIFICATION_ERROR, "Pemain tersebut sedang online, gunakan '/resetweap' terhadapnya!");
    }

    new query[512];
    mysql_format(g_SQL, query, sizeof(query), "SELECT `pID` FROM `player_characters` WHERE `Char_Name`='%e'", player);
    mysql_pquery(g_SQL, query, "OResetWeapon", "is", playerid, player);
    return 1;
}

YCMD:fine(playerid, params[], help)
{
    if (AccountData[playerid][pAdmin] < 1)
        return PermissionError(playerid);

    new money, reason[64], otherid;
    if (sscanf(params, "dds[64]", otherid, money, reason))
        return SUM(playerid, "/fine [ID] [amount] [reason]");

    if (!IsPlayerConnected(otherid))
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Pemain tersebut tidak terkoneksi ke server!");

    TakePlayerMoneyEx(otherid, money);

    static string[144];
    foreach (new i : Player) if (AccountData[i][pSpawned] && ToggleInfo[i][TogAdmCmd])
    {
        format(string, sizeof(string), "AdmCmd: %s(%d) has been fined by %s for $%s", AccountData[otherid][pName], otherid, AccountData[playerid][pAdminname], FormatMoney(money));
        SendClientMessage(i, Y_LIGHTRED, string);
        format(string, sizeof(string), "Reason: %s", reason);
        SendClientMessage(i, Y_LIGHTRED, string);
    }

    return 1;
}

YCMD:fixes(playerid, params[], help)
{
    if (AccountData[playerid][pAdmin] < 1 && !AccountData[playerid][pApprentice] && !AccountData[playerid][pSteward])
        return PermissionError(playerid);

    static string[1024];

    new count = 0;
    format(string, sizeof(string), "Player\tIssue\n");
    foreach (new i : Player) if (AccountData[i][pSpawned])
    {
        if(AccountData[i][pStuckRequest] > 0)
        {
            switch (AccountData[i][pStuckRequest])
            {
                case 1:
                {
                    format(string, sizeof(string), "%s"YELLOW"P%d: "WHITE"%s\tVisual Bug (WWID)\n", string, i, AccountData[i][pName]);
                }
                case 2:
                {
                    format(string, sizeof(string), "%s"YELLOW"P%d: "WHITE"%s\tCharacter Stuck\n", string, i, AccountData[i][pName]);
                }
                case 3:
                {
                    format(string, sizeof(string), "%s"YELLOW"P%d: "WHITE"%s\tCannot Move\n", string, i, AccountData[i][pName]);
                }
                case 4:
                {
                    format(string, sizeof(string), "%s"YELLOW"P%d: "WHITE"%s\tBug Balai Kota\n", string, i, AccountData[i][pName]);
                }
            }
            PlayerListitem[playerid][count++] = i;
        }
    }

    if (count > 0)
    {
        Dialog_Show(playerid, "FixesRequests", DIALOG_STYLE_TABLIST_HEADERS, ""ARIVENA"Arivena Theater "WHITE"- Fix Request", string, "Pilih", "Batal");
    }
    else
    {
        Dialog_Show(playerid, "UnusedDialog", DIALOG_STYLE_MSGBOX, ""ARIVENA"Arivena Theater "WHITE"- Fix Request", "No active fix requests!", "Tutup", "");
    }
    return 1;
}

YCMD:reco(playerid, params[], help)
{
	if(AccountData[playerid][pAdmin] < 1)
		return PermissionError(playerid);
		
	new otherid;
	if(sscanf(params, "i", otherid))
	    return SUM(playerid, "/reco [ID]");

    if(!IsPlayerConnected(otherid) && !AccountData[otherid][IsLoggedIn])
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Pemain tersebut tidak terkoneksi ke server!");
	
	ResetPlayerMoneyEx(otherid);
	AccountData[otherid][pBankMoney] = 0;
	AccountData[otherid][pCasinoChip] = 0;

	new sqlsdwadkw[128];
	mysql_format(g_SQL, sqlsdwadkw, sizeof(sqlsdwadkw), "UPDATE `player_characters` SET `Char_Money` = 0, `Char_BankMoney` = 0, `Char_CasinoChip` = 0 WHERE `pID` = %d", AccountData[otherid][pID]);
	mysql_pquery(g_SQL, sqlsdwadkw);
	
	SendAdm(otherid, "%s has reset your character economy!", AccountData[playerid][pAdminname]);
	SendStaffMessage(Y_LIGHTRED, "AdmCmd: %s has reset character economy %s(%d).",  AccountData[playerid][pAdminname], AccountData[otherid][pName], otherid);
	
	//format(sclstr, sizeof(sclstr), "%s(%d) [%s] menggunakan CMD '/givebankmoney'\n
	//> menambah saldo bank milik %s(%d) [%s] dengan jumlah $%s", AccountData[playerid][pAdminname], playerid, AccountData[playerid][pUCP], AccountData[otherid][pName], otherid, AccountData[otherid][pUCP], FormatMoney(money));
	//CallLocalFunction("StaffCommandLog", "is", playerid, sclstr);
	return 1;
}

YCMD:oreco(playerid, params[], help)
{
	if(AccountData[playerid][pAdmin] < 1)
	    return PermissionError(playerid);
	
	new player[24], PlayerName[MAX_PLAYER_NAME];
	if(sscanf(params, "s[24]", player))
		return SUM(playerid, "/oreco [nama]");

	foreach(new ii : Player)
	{
		if(AccountData[ii][IsLoggedIn] && AccountData[ii][pSpawned])
		{
			GetPlayerName(ii, PlayerName, MAX_PLAYER_NAME);

			if(strfind(PlayerName, player, true) != -1)
				return ShowTDN(playerid, NOTIFICATION_ERROR, "Pemain tersebut sedang online, gunakan '/reco' terhadapnya!");
		}
	}
	new query[512];
	mysql_format(g_SQL, query, sizeof(query), "SELECT `pID` FROM `player_characters` WHERE `Char_Name`='%e'", player);
	mysql_pquery(g_SQL, query, "OResetEconomy", "is", playerid, player);
	return 1;
}

YCMD:rpschooltext(playerid, params[], help)
{
    if(AccountData[playerid][pAdmin] < 1)
	    return PermissionError(playerid);

    new string[144];

    if(sscanf(params, "s[144]", string)) return SUM(playerid, "/rpschooltext [text]");

    ReplaceText(string, "(n)", "\n");
    ReplaceText(string, "(r)", "{FF0000}"); // red
    ReplaceText(string, "(b)", "{0E0101}"); // black
    ReplaceText(string, "(y)", "{FFFF00}"); // yellow
    ReplaceText(string, "(bl)", "{0000FF}"); // blue
    ReplaceText(string, "(g)", "{00FF00}"); // green
    ReplaceText(string, "(o)", "{FFA500}"); // orange
    ReplaceText(string, "(w)", "{FFFFFF}"); // white

    SetDynamicObjectMaterialText(RPSchoolText, 0, string, 120, "Arial", 15, 1, 0xFFFFFFFF, 0x00000000, 1);
    return 1;
}

YCMD:zo(playerid, params[], help)
{
    if(AccountData[playerid][pAdmin] < 1)
	    return PermissionError(playerid);

    if(!IsPlayerInDynamicArea(playerid, RPSchoolZone)) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda tidak berada di zona OOC!");

    new text[144], frmxt[144];
    if(sscanf(params, "s[144]", text)) return SUM(playerid, "/zo [text]");

    foreach(new i : Player) if(AccountData[i][pSpawned])
    {
        if(IsPlayerInDynamicArea(i, RPSchoolZone))
        {
            if(strlen(text) > 64)
            {
                format(frmxt, sizeof(frmxt), "[OOC] "RED"%s: "CYAN"(( %.64s...", AccountData[playerid][pAdminname], text);
                SendClientMessage(i, X11_WHITE, frmxt);
                format(frmxt, sizeof(frmxt), "...%s ))", text[64]);
                SendClientMessage(i, X11_CYAN, frmxt);
            }
            else
            {
                format(frmxt, sizeof(frmxt), "[OOC] "RED"%s: "CYAN"(( %s ))", AccountData[playerid][pAdminname], text);
                SendClientMessage(i, X11_WHITE, frmxt);
            }
        }
    }
    return 1;
}

YCMD:setjob(playerid, params[], help)
{
    if(AccountData[playerid][pAdmin] < 1)
	    return PermissionError(playerid);

    new otherid, jobid;
    if(sscanf(params, "id", otherid, jobid)) return SUM(playerid, "/setjob [playerid] [jobid]");

    if(!IsPlayerConnected(otherid) && !AccountData[otherid][IsLoggedIn])
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Pemain tersebut tidak terkoneksi ke server!");

    if(jobid < JOB_NONE || jobid > JOB_TAILOR) return ShowTDN(playerid, NOTIFICATION_ERROR, "Invalid Job ID!");

    AccountData[otherid][pJob] = jobid;
    SendAdm(playerid, "Anda telah mengubah job %s jadi %s.", AccountData[otherid][pName], GetJobName(otherid));
    SendAdm(otherid, "%s telah mengubah job anda jadi %s.", AccountData[playerid][pAdminname], GetJobName(otherid));
    return 1;
}

YCMD:ufo(playerid, params[], help)
{
    if(AccountData[playerid][pAdmin] < 1)
	    return PermissionError(playerid);

    if(!IsPlayerInAnyVehicle(playerid)) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda harus berada di dalam kendaraan!");

    new vid = GetPlayerVehicleID(playerid);
    if(GetVehicleModel(vid) == 520)
    {
        if(DestroyDynamicObject(UfoObjID[vid][0]))
            UfoObjID[vid][0] = STREAMER_TAG_OBJECT: INVALID_STREAMER_ID;
        
        if(DestroyDynamicObject(UfoObjID[vid][1]))
            UfoObjID[vid][1] = STREAMER_TAG_OBJECT: INVALID_STREAMER_ID;

        LinkVehicleToInterior(vid, 1);
        UfoObjID[vid][0] = CreateDynamicObject(18846, 0.0,0.0,-1000.0,0.0,0.0,0.0, -1, -1, -1, 200.00, 200.00, -1);
        AttachDynamicObjectToVehicle(UfoObjID[vid][0], vid, 0.000, -0.760, -1.280, 0.000, 0.000, 0.000);
        UfoObjID[vid][1] = CreateDynamicObject(19134, 0.0,0.0,-1000.0,0.0,0.0,0.0, -1, -1, -1, 200.00, 200.00, -1);
        AttachDynamicObjectToVehicle(UfoObjID[vid][1], vid, 0.000, -0.740, 0.679, 0.000, 90.000, 90.000);
    }
    return 1;
}

YCMD:dufo(playerid, params[], help)
{
    if(AccountData[playerid][pAdmin] < 1)
	    return PermissionError(playerid);
    
    if(!IsPlayerInAnyVehicle(playerid)) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda harus berada di dalam kendaraan!");

    new vid = GetPlayerVehicleID(playerid);
    if(GetVehicleModel(vid) == 520)
    {
        if(DestroyDynamicObject(UfoObjID[vid][0]))
            UfoObjID[vid][0] = STREAMER_TAG_OBJECT: INVALID_STREAMER_ID;
        
        if(DestroyDynamicObject(UfoObjID[vid][1]))
            UfoObjID[vid][1] = STREAMER_TAG_OBJECT: INVALID_STREAMER_ID;
        
        LinkVehicleToInterior(vid, 0);
    }
    return 1;
}