YCMD:setlevel(playerid, params[], help)
{
	if(AccountData[playerid][pAdmin] < 6)
        return PermissionError(playerid);
	
	new amount, otherid;
	if(sscanf(params, "dd", otherid, amount))
        return SUM(playerid, "/setlevel [playerid] [level]");
	
	if(amount < 1) return ShowTDN(playerid, NOTIFICATION_ERROR, "Level tidak dapat kurang dari 1!");

	if(!IsPlayerConnected(otherid))
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Pemain tersebut tidak terkoneksi ke server!");
		
	AccountData[otherid][pLevel] = amount;
	AccountData[otherid][pHours] = (AccountData[otherid][pLevel] - 1)*5;
	AccountData[otherid][pMinutes] = 0;
	AccountData[otherid][pSeconds] = 0;
	
    static string[215];
	mysql_format(g_SQL, string, sizeof(string), "UPDATE `player_characters` SET `Char_Level` = %d WHERE `pID` = %d", amount, AccountData[otherid][pID]);
    mysql_pquery(g_SQL, string);

	SetPlayerScore(otherid, amount);
	SendStaffMessage(Y_LIGHTRED, "AdmCmd: %s has set the level of %s to %d.", AccountData[playerid][pAdminname], AccountData[otherid][pName], amount);
	format(string, sizeof(string), "AdmCmd: %s has set your character's level to %d.", AccountData[playerid][pAdminname], amount);
	SendClientMessage(otherid, Y_LIGHTRED, string);

	return 1;
}

YCMD:setname(playerid, params[], help)
{
    if (AccountData[playerid][pAdmin] < 6)
        return PermissionError(playerid);

    new targetid;
    if (sscanf(params, "d", targetid))
        return SUM(playerid, "/setname [ID/Name]");

    if (!IsPlayerConnected(targetid))
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Pemain tersebut tidak terkoneksi ke server!");
    
    if (!AccountData[targetid][IsLoggedIn])
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Pemain tersebut tidak terkoneksi ke server!");

    AccountData[playerid][pTempSQLFactMemberID] = targetid;
    Dialog_Show(playerid, "AdmSetName", DIALOG_STYLE_INPUT, ""ARIVENA"Arivena Theater "WHITE"- Change Name", ""WHITE"Mohon masukkan nama baru karakter di bawah ini (Kultur Server ini adalah Indonesia)\n\
    Nama bisa apa saja asalkan tidak mengandung kata kotor, singkatan, atau nama publik figur/terkenal\n\n\
    Contoh nama yang baik: Asep_Sutanto, Christina_Agnes, Iskak_Syueb, Fadil_Siregar:", "Input", "Kembali");

    return 1;
}

YCMD:gethereall(playerid, params[], help)
{
	if(AccountData[playerid][pAdmin] < 6)
     	return PermissionError(playerid);

	static string[144];
	foreach(new i : Player)
    {
        if(IsPlayerConnected(i))
        {
            if(AccountData[i][pSpawned])
            {
				if(!OJailData[i][jailed])
				{
					if(!AccountData[i][pArrested])
					{
						SendPlayerToPlayer(i, playerid);
						format(string, sizeof(string), "AdmCmd: %s has teleported all characters to their positions.", AccountData[playerid][pAdminname]);
						SendClientMessage(i, Y_LIGHTRED, string);
					}
				}
            }
        }
    }
	return 1;
}

YCMD:setstressall(playerid, params[], help)
{
    if(AccountData[playerid][pAdmin] < 6)
        return PermissionError(playerid);

    new amount;
	if(sscanf(params, "d", amount))
        return SUM(playerid, "/setstressall [amount]");
    
	static string[215];
    foreach(new i : Player)
    {
        if(IsPlayerConnected(i))
        {
            if(AccountData[i][pSpawned])
            {
				SetPlayerDrunkLevel(i, 0);
                AccountData[i][pStress] = amount;

	            mysql_format(g_SQL, string, sizeof(string), "UPDATE `player_characters` SET `Char_Stress` = %d WHERE `pID` = %d", amount, AccountData[i][pID]);
                mysql_pquery(g_SQL, string);

                format(string, sizeof(string), "AdmCmd: %s has set the stress for all characters to %d.", AccountData[playerid][pAdminname], amount);
				SendClientMessage(i, Y_LIGHTRED, string);
            }
        }
    }
    return 1;
}

YCMD:setarmorall(playerid, params[], help)
{
    if(AccountData[playerid][pAdmin] < 6)
        return PermissionError(playerid);

    new Float:amount;
	if(sscanf(params, "f", amount))
        return SUM(playerid, "/setarmorall [amount]");
    
	static string[215];
    foreach(new i : Player)
    {
        if(IsPlayerConnected(i))
        {
            if(AccountData[i][pSpawned])
            {
                AccountData[i][pArmor] = amount;

                if(amount > 100)
                {
                    SetPlayerArmourEx(i, 100);
	                mysql_format(g_SQL, string, sizeof(string), "UPDATE `player_characters` SET `Char_Armor` = '98' WHERE `pID` = %d", amount, AccountData[i][pID]);
                    mysql_pquery(g_SQL, string);
                }
                else
                {
                    SetPlayerArmourEx(i, amount);
	                mysql_format(g_SQL, string, sizeof(string), "UPDATE `player_characters` SET `Char_Armor` = '%.3f' WHERE `pID` = %d", amount, AccountData[i][pID]);
                    mysql_pquery(g_SQL, string);
                }

                format(string, sizeof(string), "AdmCmd: %s has set the armor for all characters to %.2f.", AccountData[playerid][pAdminname], amount);
				SendClientMessage(i, Y_LIGHTRED, string);
            }
        }
    }
    return 1;
}

YCMD:sethbeall(playerid, params[], help)
{
    if(AccountData[playerid][pAdmin] < 6)
        return PermissionError(playerid);

    new amount;
	if(sscanf(params, "d", amount))
        return SUM(playerid, "/sethbeall [amount]");
    
	static string[215];
    foreach(new i : Player)
    {
        if(IsPlayerConnected(i))
        {
            if(AccountData[i][pSpawned])
            {
                AccountData[i][pHunger] = amount;
	            AccountData[i][pThirst] = amount;
	            mysql_format(g_SQL, string, sizeof(string), "UPDATE `player_characters` SET `Char_Hunger` = %d, `Char_Thirst` = %d WHERE `pID` = %d", amount, amount, AccountData[i][pID]);
                mysql_pquery(g_SQL, string);

	            SetPlayerDrunkLevel(i, 0);

                format(string, sizeof(string), "AdmCmd: %s has set the Hunger and Thirst for all characters to %d.", AccountData[playerid][pAdminname], amount);
				SendClientMessage(i, Y_LIGHTRED, string);
            }
        }
    }
    return 1;
}

YCMD:givemoneyall(playerid, params[], help)
{
	if(AccountData[playerid][pAdmin] < 6)
		return PermissionError(playerid);
		
	new money;
	if(sscanf(params, "d", money))
	    return SUM(playerid, "/givemoneyall [money]");
	
	static string[144];
	foreach(new i : Player)
	{
		if(IsPlayerConnected(i))
		{
			if(AccountData[i][pSpawned])
			{
				GivePlayerMoneyEx(i, money);
				format(string, sizeof(string), "AdmCmd: %s has given money to all characters in the amount of $%s.", AccountData[playerid][pAdminname], FormatMoney(money));
				SendClientMessage(i, Y_LIGHTRED, string);
			}
		}
	}

	//format(sclstr, sizeof(sclstr), "%s(%d) [%s] used CMD '/givemoneyall'\n
	//> gave money to all players in the amount of $%s", AccountData[playerid][pAdminname], playerid, AccountData[playerid][pUCP], FormatMoney(money));
	//CallLocalFunction("StaffCommandLog", "is", playerid, sclstr);
	return 1;
}

YCMD:giveweapall(playerid, params[], help)
{
	if(AccountData[playerid][pAdmin] < 6)
		return PermissionError(playerid);
		
	new weaponid;
	if(sscanf(params, "d", weaponid))
	    return SUM(playerid, "/giveweapall [weapon id]");
	
	if (weaponid <= 0 || weaponid > 46 || (weaponid >= 19 && weaponid <= 21))
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Invalid weapon ID!");

    if(weaponid == 40 || weaponid == 39) return ShowTDN(playerid, NOTIFICATION_ERROR, "Invalid weapon ID!");

	static string[144];
	foreach(new i : Player)
	{
		if(IsPlayerConnected(i))
		{
			if(AccountData[i][pSpawned] && AccountData[i][pLevel] >= 5)
			{
				GivePlayerWeaponEx(i, weaponid, 255, WEAPON_TYPE_PLAYER);
			}
			format(string, sizeof(string), "AdmCmd: %s has given %s to all player.", AccountData[playerid][pAdminname], ReturnWeaponName(weaponid));
			SendClientMessage(i, Y_LIGHTRED, string);
		}
	}

	//format(sclstr, sizeof(sclstr), "%s(%d) [%s] used CMD '/givemoneyall'\n
	//> gave money to all players in the amount of $%s", AccountData[playerid][pAdminname], playerid, AccountData[playerid][pUCP], FormatMoney(money));
	//CallLocalFunction("StaffCommandLog", "is", playerid, sclstr);
	return 1;
}

YCMD:kickall(playerid, params[], help)
{
	if(AccountData[playerid][pAdmin] < 6)
		return PermissionError(playerid);

	foreach(new id : FarmPlants) if(id != INVALID_ITERATOR_SLOT)
	{
		FarmPlant_Save(id);
	}
	
	foreach(new pid : Player)
	{
		if(pid != playerid)
		{
			if(AccountData[pid][pKnockdown])
			{
				SetPlayerHealthEx(pid, 100.0);
				AccountData[pid][pKnockdown] = false;
				AccountData[pid][pHunger] = 50;
				AccountData[pid][pThirst] = 50;
				AccountData[pid][pStress] = 0;
			}
			UpdateWeapons(pid);
			UpdateAccountData(pid);
			SendClientMessage(pid, Y_LIGHTRED, "AdmCmd: Maaf, server akan maintenance dan seluruh data telah tersimpan.");
			KickEx(pid);
		}
	}
	
	SendStaffMessage(Y_LIGHTRED, "AdmCmd: %s used the '/kickall' command.", AccountData[playerid][pAdminname]);

	//format(sclstr, sizeof(sclstr), "%s(%d) [%s] used CMD '/kickall'", AccountData[playerid][pAdminname], playerid, AccountData[playerid][pUCP]);
	//CallLocalFunction("StaffCommandLog", "is", playerid, sclstr);
	return 1;
}

YCMD:setadminlevel(playerid, params[], help)
{
	if(AccountData[playerid][pAdmin] < 6)
		return PermissionError(playerid);
	
	new alevel, otherid;
	if(sscanf(params, "ud", otherid, alevel)) return SUM(playerid, "/setadminlevel [ID/Name] [level 0 - 7]");

	if(!IsPlayerConnected(otherid))
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Pemain tersebut tidak terkoneksi ke server!");

	if(alevel > 7)
		return ShowTDN(playerid, NOTIFICATION_ERROR, "Level tidak dapat lebih dari 7!");

	if(alevel < 0)
		return ShowTDN(playerid, NOTIFICATION_ERROR, "Level tidak dapat kurang dari 0!");

	if(!AccountData[otherid][IsLoggedIn])
		return ShowTDN(playerid, NOTIFICATION_ERROR, sprintf("Pemain %s(%i) belum login ke server!", AccountData[otherid][pName], otherid));

	AccountData[otherid][pAdmin] = alevel;
	static string[144];
	mysql_format(g_SQL, string, sizeof(string), "UPDATE `player_characters` SET `Char_Admin` = %d WHERE `pID` = %d", alevel, AccountData[otherid][pID]);
	mysql_pquery(g_SQL, string);

	format(string, sizeof(string), "AdmCmd: %s has set your admin level to %s.", AccountData[playerid][pAdminname], GetAdminLevel(otherid));
	SendClientMessage(otherid, Y_LIGHTRED, string);
    SendStaffMessage(Y_LIGHTRED, "AdmCmd: %s has set the admin level of %s(%d) to %d.", AccountData[playerid][pAdminname], AccountData[otherid][pName], otherid, alevel);
	
	//format(sclstr, sizeof(sclstr), "%s(%d) [%s] used CMD '/setadminlevel'\n
	//> set the admin level of %s(%d) [%s] to %d.", AccountData[playerid][pAdminname], playerid, AccountData[playerid][pUCP], AccountData[otherid][pName], otherid, AccountData[otherid][pUCP], alevel);
	//CallLocalFunction("StaffCommandLog", "is", playerid, sclstr);
	return 1;
}
YCMD:setalevel(playerid, params[], help) = setadminlevel;

YCMD:konser(playerid, params[], help)
{
	if(AccountData[playerid][pAdmin] < 6)
		return PermissionError(playerid);

	Dialog_Show(playerid, "KonserList", DIALOG_STYLE_LIST, ""ARIVENA"Arivena Theater "WHITE"- Konser",
	"Mulai Konser\nStop Konser\nSiti Nurbaya\nSeparuh Nafas\nSelir Hati\nSelimut Hati\nSedang Ingin Bercinta\nRoman Picisan\n\
	Risalah Hati\nPupus\nPerempuan Paling Cantik\nPangeran Cinta\nMunajat Cinta\nMadu Tiga\nLaskar Cinta\nKirana\nKangen\nKamulah Surgaku\nKamulah Satu\n\
	Elang\nDewi\nAngin\nAku Milikmu", "Pilih", "Batal");
	return 1;
}

Dialog:KonserList(playerid, response, listitem, inputtext[]) 
{
	if(!response) return 1;

	switch(listitem)
	{
		case 0:
		{
			GM[KonserStarted] = true;
			ShowTDN(playerid, NOTIFICATION_SUCCESS, "Konser dimulai!");
		}
		case 1:
		{
			GM[KonserStarted] = false;
			foreach(new i : Player) if(IsPlayerInDynamicArea(i, KonserMusicZone))
			{
				StopAudioStreamForPlayer(i);
			}
			ShowTDN(playerid, NOTIFICATION_SUCCESS, "Konser dimulai!");
		}
		case 2:
		{
			GM[KonserStarted] = true;
			strcopy(GM[KonserMusicLink], "http://103.178.153.173/dewa/siti_nurbaya.mp3");
			foreach(new i : Player) if(IsPlayerInDynamicArea(i, KonserMusicZone))
			{
				PlayAudioStreamForPlayer(i, "http://103.178.153.173/dewa/siti_nurbaya.mp3");
			}
		}
		case 3:
		{
			GM[KonserStarted] = true;
			strcopy(GM[KonserMusicLink], "http://103.178.153.173/dewa/separuh_nafas.mp3");
			foreach(new i : Player) if(IsPlayerInDynamicArea(i, KonserMusicZone))
			{
				PlayAudioStreamForPlayer(i, "http://103.178.153.173/dewa/separuh_nafas.mp3");
			}
		}
		case 4:
		{
			GM[KonserStarted] = true;
			strcopy(GM[KonserMusicLink], "http://103.178.153.173/dewa/selir_hati.mp3");
			foreach(new i : Player) if(IsPlayerInDynamicArea(i, KonserMusicZone))
			{
				PlayAudioStreamForPlayer(i, "http://103.178.153.173/dewa/selir_hati.mp3");
			}
		}
		case 5:
		{
			GM[KonserStarted] = true;
			strcopy(GM[KonserMusicLink], "http://103.178.153.173/dewa/selimut_hati.mp3");
			foreach(new i : Player) if(IsPlayerInDynamicArea(i, KonserMusicZone))
			{
				PlayAudioStreamForPlayer(i, "http://103.178.153.173/dewa/selimut_hati.mp3");
			}
		}
		case 6:
		{
			GM[KonserStarted] = true;
			strcopy(GM[KonserMusicLink], "http://103.178.153.173/dewa/sedang_ingin.mp3");
			foreach(new i : Player) if(IsPlayerInDynamicArea(i, KonserMusicZone))
			{
				PlayAudioStreamForPlayer(i, "http://103.178.153.173/dewa/sedang_ingin.mp3");
			}
		}
		case 7:
		{
			GM[KonserStarted] = true;
			strcopy(GM[KonserMusicLink], "http://103.178.153.173/dewa/roman_picisan.mp3");
			foreach(new i : Player) if(IsPlayerInDynamicArea(i, KonserMusicZone))
			{
				PlayAudioStreamForPlayer(i, "http://103.178.153.173/dewa/roman_picisan.mp3");
			}
		}
		case 8:
		{
			GM[KonserStarted] = true;
			strcopy(GM[KonserMusicLink], "http://103.178.153.173/dewa/risalah_hati.mp3");
			foreach(new i : Player) if(IsPlayerInDynamicArea(i, KonserMusicZone))
			{
				PlayAudioStreamForPlayer(i, "http://103.178.153.173/dewa/risalah_hati.mp3");
			}
		}
		case 9:
		{
			GM[KonserStarted] = true;
			strcopy(GM[KonserMusicLink], "http://103.178.153.173/dewa/pupus.mp3");
			foreach(new i : Player) if(IsPlayerInDynamicArea(i, KonserMusicZone))
			{
				PlayAudioStreamForPlayer(i, "http://103.178.153.173/dewa/pupus.mp3");
			}
		}
		case 10:
		{
			GM[KonserStarted] = true;
			strcopy(GM[KonserMusicLink], "http://103.178.153.173/dewa/perempuan_pcdni.mp3");
			foreach(new i : Player) if(IsPlayerInDynamicArea(i, KonserMusicZone))
			{
				PlayAudioStreamForPlayer(i, "http://103.178.153.173/dewa/perempuan_pcdni.mp3");
			}
		}
		case 11:
		{
			GM[KonserStarted] = true;
			strcopy(GM[KonserMusicLink], "http://103.178.153.173/dewa/pangeran_cinta.mp3");
			foreach(new i : Player) if(IsPlayerInDynamicArea(i, KonserMusicZone))
			{
				PlayAudioStreamForPlayer(i, "http://103.178.153.173/dewa/pangeran_cinta.mp3");
			}
		}
		case 12:
		{
			GM[KonserStarted] = true;
			strcopy(GM[KonserMusicLink], "http://103.178.153.173/dewa/munajat_cinta.mp3");
			foreach(new i : Player) if(IsPlayerInDynamicArea(i, KonserMusicZone))
			{
				PlayAudioStreamForPlayer(i, "http://103.178.153.173/dewa/munajat_cinta.mp3");
			}
		}
		case 13:
		{
			GM[KonserStarted] = true;
			strcopy(GM[KonserMusicLink], "http://103.178.153.173/dewa/madu_tiga.mp3");
			foreach(new i : Player) if(IsPlayerInDynamicArea(i, KonserMusicZone))
			{
				PlayAudioStreamForPlayer(i, "http://103.178.153.173/dewa/madu_tiga.mp3");
			}
		}
		case 14:
		{
			GM[KonserStarted] = true;
			strcopy(GM[KonserMusicLink], "http://103.178.153.173/dewa/laskar_cinta.mp3");
			foreach(new i : Player) if(IsPlayerInDynamicArea(i, KonserMusicZone))
			{
				PlayAudioStreamForPlayer(i, "http://103.178.153.173/dewa/laskar_cinta.mp3");
			}
		}
		case 15:
		{
			GM[KonserStarted] = true;
			strcopy(GM[KonserMusicLink], "http://103.178.153.173/dewa/kirana.mp3");
			foreach(new i : Player) if(IsPlayerInDynamicArea(i, KonserMusicZone))
			{
				PlayAudioStreamForPlayer(i, "http://103.178.153.173/dewa/kirana.mp3");
			}
		}
		case 16:
		{
			GM[KonserStarted] = true;
			strcopy(GM[KonserMusicLink], "http://103.178.153.173/dewa/kangen.mp3");
			foreach(new i : Player) if(IsPlayerInDynamicArea(i, KonserMusicZone))
			{
				PlayAudioStreamForPlayer(i, "http://103.178.153.173/dewa/kangen.mp3");
			}
		}
		case 17:
		{
			GM[KonserStarted] = true;
			strcopy(GM[KonserMusicLink], "http://103.178.153.173/dewa/kamulah_surgaku.mp3");
			foreach(new i : Player) if(IsPlayerInDynamicArea(i, KonserMusicZone))
			{
				PlayAudioStreamForPlayer(i, "http://103.178.153.173/dewa/kamulah_surgaku.mp3");
			}
		}
		case 18:
		{
			GM[KonserStarted] = true;
			strcopy(GM[KonserMusicLink], "http://103.178.153.173/dewa/kamulah_satu.mp3");
			foreach(new i : Player) if(IsPlayerInDynamicArea(i, KonserMusicZone))
			{
				PlayAudioStreamForPlayer(i, "http://103.178.153.173/dewa/kamulah_satu.mp3");
			}
		}
		case 19:
		{
			GM[KonserStarted] = true;
			strcopy(GM[KonserMusicLink], "http://103.178.153.173/dewa/elang.mp3");
			foreach(new i : Player) if(IsPlayerInDynamicArea(i, KonserMusicZone))
			{
				PlayAudioStreamForPlayer(i, "http://103.178.153.173/dewa/elang.mp3");
			}
		}
		case 20:
		{
			GM[KonserStarted] = true;
			strcopy(GM[KonserMusicLink], "http://103.178.153.173/dewa/dewi.mp3");
			foreach(new i : Player) if(IsPlayerInDynamicArea(i, KonserMusicZone))
			{
				PlayAudioStreamForPlayer(i, "http://103.178.153.173/dewa/dewi.mp3");
			}
		}
		case 21:
		{
			GM[KonserStarted] = true;
			strcopy(GM[KonserMusicLink], "http://103.178.153.173/dewa/angin.mp3");
			foreach(new i : Player) if(IsPlayerInDynamicArea(i, KonserMusicZone))
			{
				PlayAudioStreamForPlayer(i, "http://103.178.153.173/dewa/angin.mp3");
			}
		}
		case 22:
		{
			GM[KonserStarted] = true;
			strcopy(GM[KonserMusicLink], "http://103.178.153.173/dewa/aku_milikmu.mp3");
			foreach(new i : Player) if(IsPlayerInDynamicArea(i, KonserMusicZone))
			{
				PlayAudioStreamForPlayer(i, "http://103.178.153.173/dewa/aku_milikmu.mp3");
			}
		}
	}
	return 1;
}

YCMD:setmoney(playerid, params[], help)
{
	if(AccountData[playerid][pAdmin] < 6)
		return PermissionError(playerid);
		
	new money, otherid;
	if(sscanf(params, "dd", otherid, money))
	    return SUM(playerid, "/setmoney [ID/Name] [money]");

    if(!IsPlayerConnected(otherid))
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Pemain tersebut tidak terkoneksi ke server!");
	
	ResetPlayerMoneyEx(otherid);
	GivePlayerMoneyEx(otherid, money);

	static string[144];
	format(string, sizeof(string), "AdmCmd: %s has set your character's money to $%s.", AccountData[playerid][pAdminname], FormatMoney(money));
	SendClientMessage(otherid, Y_LIGHTRED, string);
	SendStaffMessage(Y_LIGHTRED, "AdmCmd: %s has set the money of %s to $%s!",  AccountData[playerid][pAdminname], AccountData[otherid][pName], FormatMoney(money));

	return 1;
}

YCMD:givemoney(playerid, params[], help)
{
	if(AccountData[playerid][pAdmin] < 6)
		return PermissionError(playerid);
		
	new money, otherid;
	if(sscanf(params, "ud", otherid, money))
	    return SUM(playerid, "/givemoney [ID/Name] [money]");

    if(!IsPlayerConnected(otherid))
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Pemain tersebut tidak terkoneksi ke server!");

	static string[522];
	GivePlayerMoneyEx(otherid, money);

	format(string, sizeof(string), "AdmCmd: %s has given you money in the amount of $%s.", AccountData[playerid][pAdminname], FormatMoney(money));
	SendClientMessage(otherid, Y_LIGHTRED, string);
	SendStaffMessage(Y_LIGHTRED, "AdmCmd: %s has given money to %s(%d) in the amount of $%s.",  AccountData[playerid][pAdminname], AccountData[otherid][pName], otherid, FormatMoney(money));
	
    mysql_format(g_SQL, string, sizeof(string), "INSERT INTO `admin_logs` SET `Prefix` = 'givemoney', `Admin` = '%e', `AdminUCP` = '%e', `UCPTarget` = '%e'", AccountData[playerid][pAdminname], AccountData[playerid][pUCP], AccountData[otherid][pName]);
	mysql_pquery(g_SQL, string);
	return 1;
}

YCMD:setbankmoney(playerid, params[], help)
{
	if(AccountData[playerid][pAdmin] < 6)
		return PermissionError(playerid);
		
	new money, otherid;
	if(sscanf(params, "ud", otherid, money))
	    return SUM(playerid, "/setbankmoney [ID/Name] [money]");

    if(!IsPlayerConnected(otherid))
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Pemain tersebut tidak terkoneksi ke server!");

	AccountData[otherid][pBankMoney] = money;

	static string[522];
	mysql_format(g_SQL, string, sizeof(string), "UPDATE `player_characters` SET `Char_BankMoney` = %d WHERE `pID` = %d", AccountData[otherid][pBankMoney], AccountData[otherid][pID]);
	mysql_pquery(g_SQL, string);
	
	format(string, sizeof(string), "AdmCmd: %s has set your character's bank balance to $%s.", AccountData[playerid][pAdminname], FormatMoney(money));
	SendClientMessage(otherid, Y_LIGHTRED, string);
	SendStaffMessage(Y_LIGHTRED, "AdmCmd: %s has set the bank balance of %s(%d) to $%s.",  AccountData[playerid][pAdminname], AccountData[otherid][pName], otherid, FormatMoney(money));
	
    mysql_format(g_SQL, string, sizeof(string), "INSERT INTO `admin_logs` SET `Prefix` = 'setbankmoney', `Admin` = '%e', `AdminUCP` = '%e', `UCPTarget` = '%e'", AccountData[playerid][pAdminname], AccountData[playerid][pUCP], AccountData[otherid][pName]);
	mysql_pquery(g_SQL, string);
	return 1;
}

YCMD:givebankmoney(playerid, params[], help)
{
	if(AccountData[playerid][pAdmin] < 6)
		return PermissionError(playerid);
		
	new money, otherid;
	if(sscanf(params, "ud", otherid, money))
	    return SUM(playerid, "/givebankmoney [ID/Name] [money]");

    if(!IsPlayerConnected(otherid))
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Pemain tersebut tidak terkoneksi ke server!");

	AccountData[otherid][pBankMoney] += money;

	static string[522];
	mysql_format(g_SQL, string, sizeof(string), "UPDATE `player_characters` SET `Char_BankMoney` = %d WHERE `pID` = %d", AccountData[otherid][pBankMoney], AccountData[otherid][pID]);
	mysql_pquery(g_SQL, string);
	
	format(string, sizeof(string), "AdmCmd: %s has added to your character's bank balance in the amount of $%s.", AccountData[playerid][pAdminname], FormatMoney(money));
	SendClientMessage(otherid, Y_LIGHTRED, string);
	SendStaffMessage(Y_LIGHTRED, "AdmCmd: %s added to the bank balance of %s(%d) in the amount of $%s.",  AccountData[playerid][pAdminname], AccountData[otherid][pName], otherid, FormatMoney(money));
	
    mysql_format(g_SQL, string, sizeof(string), "INSERT INTO `admin_logs` SET `Prefix` = 'givebankmoney', `Admin` = '%e', `AdminUCP` = '%e', `UCPTarget` = '%e'", AccountData[playerid][pAdminname], AccountData[playerid][pUCP], AccountData[otherid][pName]);
	mysql_pquery(g_SQL, string);
	return 1;
}

YCMD:osetbank(playerid, params[], help)
{
	if(AccountData[playerid][pAdmin] < 6)
	    return PermissionError(playerid);
	
	new player[24], value, PlayerName[MAX_PLAYER_NAME];
	if(sscanf(params, "ds[24]", value, player))
		return SUM(playerid, "/osetbank [amount] [name]");

	foreach(new ii : Player)
	{
		GetPlayerName(ii, PlayerName, MAX_PLAYER_NAME);

	    if(strfind(PlayerName, player, true) != -1)
			return ShowTDN(playerid, NOTIFICATION_ERROR, "Pemain tersebut sedang online, gunakan '/setbankmoney' terhadapnya!");
	}

	new query[512];
	mysql_format(g_SQL, query, sizeof(query), "SELECT `pID` FROM `player_characters` WHERE `Char_Name`='%e'", player);
	mysql_pquery(g_SQL, query, "OSetBankMoney", "isd", playerid, player, value);
	return 1;
}

YCMD:vcreate(playerid, params[], help)
{
    if (AccountData[playerid][pAdmin] < 6)
        return PermissionError(playerid);

    new otherid, model, counting = 0, Float:pos[4], color1, color2, pvwid, pvintid;
    if (sscanf(params, "uddd", otherid, model, color1, color2))
        return SUM(playerid, "/vcreate [name/playerid] [model] [color1] [color2]");

    if (color1 < 0 || color1 > 255)
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Mohon masukkan warna kendaraan antara 0-255!");
    if (model < 400 || model > 611)
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Mohon masukkan model kendaraan antara 400-611!");
    if (!IsPlayerConnected(otherid))
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Pemain tersebut tidak terkoneksi ke server!");

    foreach(new v : PvtVehicles)
    {
        if (PlayerVehicle[v][pVehOwnerID] == AccountData[otherid][pID])
            counting++;
    }

    if (counting >= GetPlayerVehicleLimit(otherid))
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Jumlah kendaraan pribadi pemain tersebut telah mencapai batas maksimum!");

    GetPlayerPos(otherid, pos[0], pos[1], pos[2]);
    GetPlayerFacingAngle(otherid, pos[3]);
    pvwid = GetPlayerVirtualWorld(otherid);
    pvintid = GetPlayerInterior(otherid);
    Vehicle_Create(otherid, model, pos[0], pos[1], pos[2], pos[3], color1, color2, pvwid, pvintid);

    SendStaffMessage(Y_LIGHTRED, "AdmCmd: %s membuat kendaraan pribadi %s untuk %s.", AccountData[playerid][pAdminname], GetVehicleModelName(model), AccountData[otherid][pName]);

    static string[522];
    mysql_format(g_SQL, string, sizeof(string), "INSERT INTO `admin_logs` SET `Prefix` = 'vcreate (%s)', `Admin` = '%e', `AdminUCP` = '%e', `UCPTarget` = '%e'", GetVehicleModelName(model), AccountData[playerid][pAdminname], AccountData[playerid][pUCP], AccountData[otherid][pName]);
	mysql_pquery(g_SQL, string);
    return 1;
}

YCMD:setapprentice(playerid, params[], help)
{
    if (AccountData[playerid][pAdmin] < 4)
        return PermissionError(playerid);

    new app, targetid;
    if (sscanf(params, "dd", targetid, app))
        return SUM(playerid, "/setapprentice [ID/Name] [1 = apply | 0 = remove]");

    if (!IsPlayerConnected(targetid))
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Pemain tersebut tidak terkoneksi ke server!");

    if (app < 0 || app > 1)
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Hanya 0 atau 1 yang dapat digunakan!");

    if (!AccountData[targetid][IsLoggedIn])
        return ShowTDN(playerid, NOTIFICATION_ERROR, sprintf("Player %s(%i) tidak terkoneksi ke server!", AccountData[targetid][pName], targetid));

    static string[144];
    if (app == 0)
    {
        AccountData[targetid][pApprentice] = false;
        format(string, sizeof(string), "AdmCmd: %s has removed your apprentice status.", AccountData[playerid][pAdminname]);
        SendClientMessage(targetid, Y_LIGHTRED, string);
        SendStaffMessage(Y_LIGHTRED, "AdmCmd: %s removed apprentice status for %s(%d).", AccountData[playerid][pAdminname], AccountData[targetid][pName], targetid);
    }
    else
    {
        AccountData[targetid][pApprentice] = true;
        format(string, sizeof(string), "AdmCmd: %s has appointed you as a apprentice.", AccountData[playerid][pAdminname]);
        SendClientMessage(targetid, Y_LIGHTRED, string);
        SendStaffMessage(Y_LIGHTRED, "AdmCmd: %s appointed %s(%d) as a apprentice!", AccountData[playerid][pAdminname], AccountData[targetid][pName], targetid);
    }

    return 1;
}

YCMD:setsteward(playerid, params[], help)
{
    if (AccountData[playerid][pAdmin] < 6)
        return PermissionError(playerid);

    new days, targetid;
    if (sscanf(params, "dd", targetid, days))
        return SUM(playerid, "/setsteward [ID/Name] [duration (days) 0 to remove]");

    if (!IsPlayerConnected(targetid))
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Pemain tersebut tidak terkoneksi ke server!");

    if (days < 0)
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Duration cannot be less than 0!");

    if (!AccountData[targetid][IsLoggedIn])
        return ShowTDN(playerid, NOTIFICATION_ERROR, sprintf("Player %s(%i) tidak terkoneksi ke server!", AccountData[targetid][pName], targetid));

    static string[144];
    if (days == 0)
    {
        AccountData[targetid][pSteward] = false;
        AccountData[targetid][pStewardTime] = 0;
        format(string, sizeof(string), "AdmCmd: %s has removed your steward status.", AccountData[playerid][pAdminname]);
        SendClientMessage(targetid, Y_LIGHTRED, string);
        SendStaffMessage(Y_LIGHTRED, "AdmCmd: %s removed steward status for %s(%d).", AccountData[playerid][pAdminname], AccountData[targetid][pName], targetid);
    }
    else
    {
        AccountData[targetid][pSteward] = true;
        AccountData[targetid][pStewardTime] = gettime() + (days * 86400);
        format(string, sizeof(string), "AdmCmd: %s has appointed you as a steward for %d days.", AccountData[playerid][pAdminname], days);
        SendClientMessage(targetid, Y_LIGHTRED, string);
        SendStaffMessage(Y_LIGHTRED, "AdmCmd: %s appointed %s(%d) as a steward for %d days!", AccountData[playerid][pAdminname], AccountData[targetid][pName], targetid, days);
    }

    return 1;
}

YCMD:setvip(playerid, params[], help)
{
    if(AccountData[playerid][pAdmin] < 6)
        return PermissionError(playerid);

    new alevel, dayz, otherid;
    if(sscanf(params, "udd", otherid, alevel, dayz))
        return SUM(playerid, "/setvip [ID/Name] [level 0 - 3] [duration (days) 0 for permanent]");

    if(!IsPlayerConnected(otherid))
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Pemain tersebut tidak terkoneksi ke server!");

    if(alevel > 3)
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Level tidak dapat lebih dari 3!");

    if(alevel < 0)
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Level tidak dapat kurang dari 0!");

    if(dayz < 0)
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Durasi tidak dapat kurang dari 0!");

    if(!AccountData[otherid][IsLoggedIn])
        return ShowTDN(playerid, NOTIFICATION_ERROR, sprintf("Player %s(%i) tidak terkoneksi ke server!", AccountData[otherid][pName], otherid));

    AccountData[otherid][pVIP] = alevel;

    static string[144];
    if(dayz == 0)
    {
        AccountData[otherid][pVIPTime] = 0;
        format(string, sizeof(string), "AdmCmd: %s has set your VIP status [ (%s) - Permanent ].", AccountData[playerid][pAdminname], GetVIPLevel(otherid));
        SendClientMessage(otherid, Y_LIGHTRED, string);

        SendStaffMessage(Y_LIGHTRED, "AdmCmd: %s has set VIP for %s(%d) to %s with permanent status!", AccountData[playerid][pAdminname], AccountData[otherid][pName], otherid, GetVIPLevel(otherid));
    }
    else
    {
        AccountData[otherid][pVIPTime] = gettime() + (dayz * 86400);
        format(string, sizeof(string), "AdmCmd: %s has set your VIP status [ (%s) - %d days ].", AccountData[playerid][pAdminname], GetVIPLevel(otherid), dayz);
        SendClientMessage(otherid, Y_LIGHTRED, string);
        SendStaffMessage(Y_LIGHTRED, "AdmCmd: %s has set VIP for %s(%d) for %d days with level %s!", AccountData[playerid][pAdminname], AccountData[otherid][pName], otherid, dayz, GetVIPLevel(otherid));
    }
    return 1;
}

YCMD:changeplate(playerid, params[], help)
{
    if(AccountData[playerid][pAdmin] < 6)
        return PermissionError(playerid);

    new vid, newplate[64], query[158];
    if(sscanf(params, "ds[64]", vid, newplate))
        return SUM(playerid, "/changeplate [vid] [plate]");

    if(!IsValidVehicle(vid))
        return ShowTDN(playerid, NOTIFICATION_ERROR, "ID Vehicle tersebut tidak valid!");

    foreach(new i : PvtVehicles)
    {
        if(PlayerVehicle[i][pVehPhysic] == vid)
        {
            mysql_format(g_SQL, query, sizeof(query), "SELECT `PVeh_Plate` FROM `player_vehicles` WHERE `PVeh_Plate`='%e'", newplate);
            mysql_pquery(g_SQL, query, "ChangeVIPPlate", "ids", playerid, i, newplate);
            return 1;
        }
    }
    ShowTDN(playerid, NOTIFICATION_ERROR, "Kendaraan tersebut bukan jenis kendaraan pribadi!");
    return 1;
}

YCMD:changeucp(playerid, params[], help)
{
    if(AccountData[playerid][pAdmin] < 6)
        return PermissionError(playerid);

    new otherid, newucp[22], query[158];
    if(sscanf(params, "us[22]", otherid, newucp))
        return SUM(playerid, "/changeucp [playerid] [ucp]");

    if(!IsPlayerConnected(otherid))
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Pemain tersebut tidak terkoneksi ke server!");
    if(!AccountData[otherid][pSpawned])
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Pemain tersebut belum spawn!");

    mysql_format(g_SQL, query, sizeof(query), "SELECT `ucp` FROM `whitelists` WHERE `ucp`='%e'", newucp);
    mysql_pquery(g_SQL, query, "ChangeVIPUCP", "iis", playerid, otherid, newucp);
    return 1;
}

YCMD:changephnumber(playerid, params[], help)
{
    if(AccountData[playerid][pAdmin] < 6)
        return PermissionError(playerid);

    new otherid, newphnumb[22], query[158];
    if(sscanf(params, "us[22]", otherid, newphnumb))
        return SUM(playerid, "/changephnumber [playerid] [number]");

    if(!IsPlayerConnected(otherid))
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Pemain tersebut tidak terkoneksi ke server!");
    if(!AccountData[otherid][pSpawned])
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Pemain tersebut belum spawn!");
    if(!IsNumericEx(newphnumb))
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Hanya dapat memuat angka!");
    if(strlen(newphnumb) < 4 || strlen(newphnumb) > 10)
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Nomor hanya dapat berjumlah 4 - 10!");

    mysql_format(g_SQL, query, sizeof(query), "SELECT `phoneNumber` FROM `player_phones` WHERE `phoneNumber`='%e'", newphnumb);
    mysql_pquery(g_SQL, query, "ChangeVIPPHNumber", "iis", playerid, otherid, newphnumb);
    return 1;
}

YCMD:changebanknumber(playerid, params[], help)
{
	if(AccountData[playerid][pAdmin] < 6)
		return PermissionError(playerid);

	new otherid, newbrek[7], query[158];
	if(sscanf(params, "us[7]", otherid, newbrek))
        return SUM(playerid, "/changebanknumber [playerid] [number]");

	if(!IsPlayerConnected(otherid)) return ShowTDN(playerid, NOTIFICATION_ERROR, "Pemain tersebut tidak terkoneksi ke server!");
	if(!AccountData[otherid][pSpawned]) return ShowTDN(playerid, NOTIFICATION_ERROR, "Pemain tersebut belum spawn!");
    if(strlen(newbrek) < 4 || strlen(newbrek) > 6) return ShowTDN(playerid, NOTIFICATION_ERROR, "Nomor rekening harus berjumlah 4 - 6 digit!");
	mysql_format(g_SQL, query, sizeof(query), "SELECT `Char_BankNumber` FROM `player_characters` WHERE `Char_BankNumber`=%d", strval(newbrek));
    mysql_pquery(g_SQL, query, "ChangeVIPBankNumber", "iid", playerid, otherid, strval(newbrek));
	return 1;
}