/*
YCMD:ahide(playerid, params[], help)
{
	if(AccountData[playerid][pAdmin] < 5)
        return PermissionError(playerid);
		
	if(AccountData[playerid][pHiddenAdmin])
	{
		AccountData[playerid][pHiddenAdmin] = false;
		SendClientMessage(playerid, X11_LIGHTBLUE, "INFO: "WHITE"Status hidden anda telah dicabut.");
	}
	else
	{
		AccountData[playerid][pHiddenAdmin] = true;
		SendClientMessage(playerid, X11_LIGHTBLUE, "INFO: "WHITE"Status hidden anda telah diaktifkan.");
	}
	return 1;
}
*/

YCMD:sann(playerid, params[], help)
{
	if(AccountData[playerid][pAdmin] < 5)
        return PermissionError(playerid);

	new otherid, msg[64];
	if(sscanf(params, "is[64]", otherid, msg)) return SUM(playerid, "/sann [otherid] [message]");

	if(!IsPlayerConnected(otherid) && !AccountData[otherid][pSpawned]) return ShowTDN(playerid, NOTIFICATION_ERROR, "Player belum spawn/tidak terkoneksi ke server!");

	GameTextForPlayer(otherid, msg, 5000, 4);
	ShowTDN(playerid, NOTIFICATION_INFO, "Anda telah mengirimkan pesan kepada Pemain tersebut.");
	return 1;
}

YCMD:settime(playerid, params[], help)
{
    if(AccountData[playerid][pAdmin] < 5)
        return PermissionError(playerid);

	new time;
	if(sscanf(params, "d", time))
		return SUM(playerid, "/time [time ID]");

	static string[144];
	format(string, sizeof(string), "(Server) "WHITE"Pengurus "RED"%s "WHITE"telah mengganti waktu server.", AccountData[playerid][pAdminname]);

	SetWorldTime(time);
	WorldTime = time;
	foreach(new ii : Player)
	{
		SetPlayerTime(ii, time, 0);
		SendClientMessage(ii, Y_SERVER, string);
	}
	return 1;
}

YCMD:setweather(playerid, params[], help)
{
    new weatherid;

    if(AccountData[playerid][pAdmin] < 5)
        return PermissionError(playerid);

    if(sscanf(params, "d", weatherid))
        return SUM(playerid, "/setweather [weather ID]");

    SetWeather(weatherid);
	WorldWeather = weatherid;
	static string[144];
	format(string, sizeof(string), "(Server) "WHITE"Pengurus "RED"%s "WHITE"telah mengganti cuaca server.", AccountData[playerid][pAdminname]);
	foreach(new ii : Player)
	{
		SetPlayerWeather(ii, weatherid);
    	SendClientMessage(ii, Y_SERVER, string);
	}

    return 1;
}

YCMD:setadminname(playerid, params[], help)
{
	if(AccountData[playerid][pAdmin] < 5)
		return PermissionError(playerid);
	
	new aname[128], otherid, query[128];
	if(sscanf(params, "us[128]", otherid, aname))
	   	return SUM(playerid, "/setadminname [ID/Name] [admin name]");
	
	mysql_format(g_SQL, query, sizeof(query), "SELECT * FROM `player_characters` WHERE `Char_AdminName`='%e' AND `Char_UCP` != '%e'", aname, AccountData[otherid][pUCP]);
	mysql_pquery(g_SQL, query, "CNAdmName", "iis", otherid, playerid, aname);
	return 1;
}
YCMD:setaname(playerid, params[], help) = setadminname;

YCMD:resetcd(playerid, params[], help)
{
	if(AccountData[playerid][pAdmin] < 5)
		return PermissionError(playerid);

	new otherid;
	if(sscanf(params, "d", otherid)) return SUM(playerid, "/resetcd [playerid]");

	if(!IsPlayerConnected(otherid) && !AccountData[otherid][pSpawned]) return ShowTDN(playerid, NOTIFICATION_ERROR, "Pemain tersebut belum spawn/tidak terkoneksi ke server!");

	AccountData[otherid][pMowingSidejobDelay] = 0;
	AccountData[otherid][pSweeperSidejobDelay] = 0;
	AccountData[otherid][pForkliftSidejobDelay] = 0;
	AccountData[otherid][pPizzaSidejobDelay] = 0;

	static string[144];
	format(string, sizeof(string), "AdmCmd: %s has reset your character's side job cooldowns.", AccountData[playerid][pAdminname]);
	SendClientMessage(otherid, Y_LIGHTRED, string);
	SendAdm(playerid, "You reset the side job cooldowns for %s(%d).", AccountData[otherid][pName], otherid);
	return 1;
}

YCMD:resetcdcarsteal(playerid, params[], help)
{
	if(AccountData[playerid][pAdmin] < 5)
		return PermissionError(playerid);

	if(g_CarstealCooldown == 0) return ShowTDN(playerid, NOTIFICATION_ERROR, "Carsteal tidak dalam masa cooldown!");
	g_CarstealCooldown = 0;

	SendStaffMessage(Y_LIGHTRED, "AdmCmd: %s has reset the carsteal cooldown.", AccountData[playerid][pAdminname]);
	return 1;
}

YCMD:resetcdrobbery(playerid, params[], help)
{
	if(AccountData[playerid][pAdmin] < 5)
		return PermissionError(playerid);

	GM[ShopRobberyCooldown] = 0;

	SendStaffMessage(Y_LIGHTRED, "AdmCmd: %s has reset the shop robbery cooldown.", AccountData[playerid][pAdminname]);
	//format(sclstr, sizeof(sclstr), "%s(%d) [%s] used CMD '/resetcdrobbery'", AccountData[playerid][pAdminname], playerid, AccountData[playerid][pUCP]);
	//CallLocalFunction("StaffCommandLog", "is", playerid, sclstr);
	return 1;
}

YCMD:dynhelp(playerid, params[], help)
{
    if(AccountData[playerid][pAdmin] < 5)
		return PermissionError(playerid);
    
    Dialog_Show(playerid, "AdminDynamicHelp", DIALOG_STYLE_TABLIST_HEADERS, ""ARIVENA"Arivena Theater "WHITE"- Dynamic Help", 
    "Dynamic Type\tDescription\n\
    Dynamic Actor\tContains commands related to dynamic actors\n\
    "GRAY"Dynamic Bike Rental\t"GRAY"Contains commands related to dynamic bicycle rentals\n\
    Dynamic Door\tContains commands related to dynamic doors/teleport doors\n\
    "GRAY"Dynamic Fivem Label\t"GRAY"Contains commands related to dynamic FiveM Label text\n\
    Dynamic Garage\tContains commands related to dynamic garages\n\
    "GRAY"Dynamic Garbage\t"GRAY"Contains commands related to dynamic garbage bins\n\
    Dynamic Cannabis\tContains commands related to dynamic cannabis plants\n\
    "GRAY"Dynamic Robbery\t"GRAY"Contains commands related to dynamic shop robberies\n\
    Dynamic Shop\tContains commands related to dynamic shops\n\
	"GRAY"Dynamic Button\t"GRAY"Contains commands related to dynamic door buttons", "Pilih", "Batal");
    return 1;
}

YCMD:togspy(playerid, params[], help)
{
	if(AccountData[playerid][pAdmin] < 1)
		return PermissionError(playerid);

	switch(AccountData[playerid][pSPY])
	{
		case false:
		{
			AccountData[playerid][pSPY] = true;
			ShowTDN(playerid, NOTIFICATION_INFO, "SPY mode ~g~aktif.");
		}
		case true:
		{
			AccountData[playerid][pSPY] = false;
			ShowTDN(playerid, NOTIFICATION_INFO, "SPY mode ~r~tidak aktif.");
		}
	}
	return 1;
}

YCMD:schedulemt(playerid, params[], help)
{
	if(AccountData[playerid][pAdmin] < 5) return PermissionError(playerid);

	static string[144];
	if(!GM[Maintenance])
	{
		new minutes;
		if(sscanf(params, "d", minutes)) return SUM(playerid, "/schedulemt [menit]");

		if(minutes < 3) return ShowTDN(playerid, NOTIFICATION_ERROR, "Minimal 3 menit!");

		GM[Maintenance] = true;
		GM[MTTime] = gettime() + (minutes * 60);

		format(string, sizeof(string), "[Maintenance] %s telah menjadwalkan maintenance pada %s", AccountData[playerid][pAdminname], ReturnDate(GM[MTTime]));
		SendClientMessageToAll(Y_LIGHTRED, string);
	}
	else
	{
		GM[Maintenance] = false;
		GM[MTTime] = 0;

		format(string, sizeof(string), "[Maintenance] %s telah membatalkan jadwal maintenance, happy roleplay.", AccountData[playerid][pAdminname]);
		SendClientMessageToAll(Y_LIGHTRED, string);
	}
	return 1;
}

YCMD:setstock(playerid, params[], help)
{
	if(AccountData[playerid][pAdmin] < 5) return PermissionError(playerid);

	new type[24], somt[128];
	if(sscanf(params, "s[24]S()[128]", type, somt))
        return SUM(playerid, "/setstock [name] (komponen)");

	if(!strcmp(type, "komponen", true))
    {
		new value;
		if(sscanf(somt, "d", value))
			return SUM(playerid, "/setstock component [ammount]");

		GM[g_ComponentStock] = value;

		SendAdm(playerid, "You have set Komponen stock to %d.", value);
	}
	return 1;
}

YCMD:backup(playerid, params[], help)
{
	if(AccountData[playerid][pAdmin] < 5) return PermissionError(playerid);

	foreach(new id : FarmPlants) if(id != INVALID_ITERATOR_SLOT)
	{
		FarmPlant_Save(id);
	}
	
	static string[144];
	format(string, sizeof(string), "AdmCmd: %s telah menyimpan semua data server (backup).", AccountData[playerid][pAdminname]);
	
	foreach(new i : Player) if(AccountData[i][pSpawned])
	{
		Anticheat[i][acImmunity] = gettime() + 5;
		UpdateAccountData(i);
		SendClientMessage(i, Y_LIGHTRED, string);
	}
	return 1;
}

YCMD:giveweap(playerid, params[], help)
{
    static
        wgunid,
        typo,
        ammo;

    new otherid;
    if (AccountData[playerid][pAdmin] < 5)
        return PermissionError(playerid);

    if (sscanf(params, "uddI(250)", otherid, wgunid, typo, ammo))
        return SUM(playerid, "/givewep [playerid/name] [wgunid] [type: 1. admin, 2. faction, 3. player] [ammo]");

    if (otherid == INVALID_PLAYER_ID)
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Pemain tersebut tidak terkoneksi ke server!");

    if (wgunid <= 0 || wgunid > 46 || (wgunid >= 19 && wgunid <= 21))
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Invalid weapon ID!");

    if(wgunid == 40 || wgunid == 39) return ShowTDN(playerid, NOTIFICATION_ERROR, "Invalid weapon ID!");
    
    if(typo < 1 || typo > 3) return ShowTDN(playerid, NOTIFICATION_ERROR, "Invalid type (1 - 3).");
    
    if (ammo < 1 || ammo > 500)
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Invalid ammo (1 - 500).");

    if(IsAFireArm(wgunid) && AccountData[otherid][pLevel] < 5)
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Pemain tersebut harus mencapai level 5!");

    GivePlayerWeaponEx(otherid, wgunid, ammo, typo);
    SendStaffMessage(Y_LIGHTRED, "AdmCmd: %s has given %s a %s with %d rounds.", AccountData[playerid][pAdminname], AccountData[otherid][pName], ReturnWeaponName(wgunid), ammo);

    static string[522];
    mysql_format(g_SQL, string, sizeof(string), "INSERT INTO `admin_logs` SET `Prefix` = 'giveweap', `Admin` = '%e', `AdminUCP` = '%e', `UCPTarget` = '%e'", AccountData[playerid][pAdminname], AccountData[playerid][pUCP], AccountData[otherid][pName]);
	mysql_pquery(g_SQL, string);
    return 1;
}