YCMD:areviveall(playerid, params[], help)
{
    if (AccountData[playerid][pAdmin] < 4)
        return PermissionError(playerid);

    static frmtsql[215];

    foreach (new i : Player)
    {
        if (AccountData[playerid][pSpawned])
        {
            if (AccountData[i][pKnockdown])
            {
                HideKnockTD(i);
                SetPlayerHealthEx(i, 100.0);
                AccountData[i][pKnockdown] = false;
                AccountData[i][pKnockdownTime] = 0;
                AccountData[i][pHunger] = 50;
                AccountData[i][pThirst] = 50;
                AccountData[i][pStress] = 0;

                DeathCause[i][Bruised] = false;
                DeathCause[i][Shoted] = false;
                DeathCause[i][Burns] = false;
                DeathCause[i][Drown] = false;
                DeathCause[i][Fallen] = false;

                mysql_format(g_SQL, frmtsql, sizeof(frmtsql), "UPDATE `player_characters` SET `Char_Knockdown` = 0, `Char_KnockdownTime` = 0, `Char_Hunger` = 50, `Char_Thirst` = 50 WHERE `pID` = %d", AccountData[i][pID]);
                mysql_pquery(g_SQL, frmtsql);

                StopRunningAnimation(i);
            }
            format(frmtsql, sizeof(frmtsql), "AdmCmd: %s has revived all players.", AccountData[playerid][pAdminname]);
            SendClientMessage(i, Y_LIGHTRED, frmtsql);
        }
    }

    return 1;
}

YCMD:sethpall(playerid, params[], help)
{
    if (AccountData[playerid][pAdmin] < 4)
        return PermissionError(playerid);

    new Float:amount;
    if (sscanf(params, "f", amount))
        return SUM(playerid, "/sethpall [amount]");

    static frmtsql[215];
    foreach (new i : Player)
    {
        if (IsPlayerConnected(i))
        {
            if (AccountData[i][pSpawned])
            {
                AccountData[i][pHealth] = amount;

                mysql_format(g_SQL, frmtsql, sizeof(frmtsql), "UPDATE `player_characters` SET `Char_Health` = '%.3f' WHERE `pID` = %d", amount, AccountData[i][pID]);
                mysql_pquery(g_SQL, frmtsql);

                SetPlayerHealthEx(i, amount);

                format(frmtsql, sizeof(frmtsql), "AdmCmd: %s has set the health of all characters to %.2f.", AccountData[playerid][pAdminname], amount);
                SendClientMessage(i, Y_LIGHTRED, frmtsql);
            }
        }
    }

    return 1;
}

YCMD:unban(playerid, params[], help)
{
    if (AccountData[playerid][pAdmin] < 4)
        return PermissionError(playerid);

    new tmp[24];
    if (sscanf(params, "s[24]", tmp))
        return SUM(playerid, "/unban [ban name]");

    new query[128];
    mysql_format(g_SQL, query, sizeof(query), "SELECT `name`,`ip` FROM `player_bans` WHERE `name` = '%e'", tmp);
    mysql_pquery(g_SQL, query, "OnUnbanQueryData", "is", playerid, tmp);
    return 1;
}

YCMD:unblockucp(playerid, params[], help)
{
    if (AccountData[playerid][pAdmin] < 4)
        return PermissionError(playerid);

    new ucpname[22];
    if (sscanf(params, "s[22]", ucpname))
        return SUM(playerid, "/unblockucp [UCP name]");

    new query[128];
    mysql_format(g_SQL, query, sizeof(query), "SELECT * FROM `player_ucp` WHERE `UCP` = '%e'", ucpname);
    mysql_pquery(g_SQL, query, "OnUnblockUCP", "is", playerid, ucpname);
    return 1;
}

YCMD:unbanip(playerid, params[], help)
{
    if (AccountData[playerid][pAdmin] < 4)
        return PermissionError(playerid);

    if (isnull(params))
        return SUM(playerid, "/unbanip [IP Address]");

    new mstr[128];
    format(mstr, sizeof(mstr), "unbanip %s", params);
    SendRconCommand(mstr);
    format(mstr, sizeof(mstr), "reloadbans");
    SendRconCommand(mstr);
    SendStaffMessage(Y_LIGHTRED, "AdmCmd: %s has unbanned the IP %s.", AccountData[playerid][pAdminname], params);

    return 1;
}

YCMD:setgender(playerid, params[], help)
{
    if (AccountData[playerid][pAdmin] < 4)
        return PermissionError(playerid);

    new targetid, gender;
    if (sscanf(params, "dd", targetid, gender))
        return SUM(playerid, "/setgender [playerid] [1. Male | 2. Female]");

    if (!IsPlayerConnected(targetid))
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Pemain tersebut tidak terkoneksi ke server!");
    
    if (!AccountData[targetid][IsLoggedIn])
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Pemain tersebut tidak terkoneksi ke server!");

    AccountData[targetid][pGender] = gender;
    SendClientMessageEx(targetid, Y_LIGHTRED, "AdmCmd: %s has set your character gender.", AccountData[playerid][pAdminname]);
    SendAdm(playerid, "You have set %s(%d) gender to %d", AccountData[targetid][pName], targetid, gender);
    return 1;
}

YCMD:setfaction(playerid, params[], help)
{
	new fid, rank, otherid;
    if(AccountData[playerid][pAdmin] < 4)
        return PermissionError(playerid);

    if(sscanf(params, "udd", otherid, fid, rank))
    {
		SUM(playerid, "/setfaction [playerid] [faction id] [rank] faction ID 0 untuk Kick");
        return 1;
    }

	if(!IsPlayerConnected(otherid))
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Pemain tersebut tidak terkoneksi ke server!");

    if(fid < 0 || fid > MAX_FACTIONS - 1)
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Invalid faction ID!");
	
	switch(fid)
	{
		case 0:
		{
			if(rank != 0)
				return ShowTDN(playerid, NOTIFICATION_ERROR, "Set rank 0 untuk mengeluarkan player dari faction!");
		}
		case 1: //polda
		{
			if(rank < 1 || rank > 16)
				return ShowTDN(playerid, NOTIFICATION_ERROR, "Polisi valid rank is 1- 16.");
		}
		case 2: //LSFD
		{
			if(rank < 1 || rank > 8)
				return ShowTDN(playerid, NOTIFICATION_ERROR, "Paramedis valid rank is 1 - 8!");
		}
		case 3: //Burgershot
		{
			if(rank < 1 || rank > 10)
				return ShowTDN(playerid, NOTIFICATION_ERROR, "Putri Deli valid rank is 1 - 10!");
		}
		case 4: //government
		{
			if(rank < 1 || rank > 7)
				return ShowTDN(playerid, NOTIFICATION_ERROR, "Pemerintah valid rank is 1- 7.");
		}
		case 5: //bennys
		{
			if(rank < 1 || rank > 6)
				return ShowTDN(playerid, NOTIFICATION_ERROR, "Bennys valid rank is 1 - 6!");
		}
		case 6: //Uber
		{
			if(rank < 1 || rank > 5)
				return ShowTDN(playerid, NOTIFICATION_ERROR, "Uber valid rank is 1 - 5!");
		}
		case 7: //dinarbucks
		{
			if(rank < 1 || rank > 10)
				return ShowTDN(playerid, NOTIFICATION_ERROR, "Pinky Tiger valid rank is 1 - 10!");
		}
		case 8: //fox 11
		{
			if(rank < 1 || rank > 8)
				return ShowTDN(playerid, NOTIFICATION_ERROR, "Pewarta valid rank is 1 - 8!");
		}
        case 9: //automax
		{
			if(rank < 1 || rank > 6)
				return ShowTDN(playerid, NOTIFICATION_ERROR, "Automax valid rank is 1 - 6!");
		}
        case 10: //handover
		{
			if(rank < 1 || rank > 6)
				return ShowTDN(playerid, NOTIFICATION_ERROR, "Handover valid rank is 1 - 6!");
		}
        case 11: //plus arivena
		{
			if(rank < 1 || rank > 10)
				return ShowTDN(playerid, NOTIFICATION_ERROR, "Sri Mersing valid rank is 1 - 10!");
		}
        case 12: //texas chicken
		{
			if(rank < 1 || rank > 10)
				return ShowTDN(playerid, NOTIFICATION_ERROR, "Texas chicken valid rank is 1 - 10!");
		}
	}

	static string[158];
	if(fid == 0)
	{
		AccountData[otherid][pFaction] = 0;
		AccountData[otherid][pFactionRank] = 0;
		AccountData[otherid][pBadge] = 0;
		format(string, sizeof(string), "AdmCmd: %s has removed you from the faction.", AccountData[playerid][pAdminname]);
		SendClientMessage(otherid, Y_LIGHTRED, string);
	}
	else
	{
		AccountData[otherid][pFaction] = fid;
		AccountData[otherid][pFactionRank] = rank;
	}
	mysql_format(g_SQL, string, sizeof(string), "UPDATE `player_characters` SET `Char_Faction` = %d, `Char_FactionRank` = %d WHERE `pID` = %d", AccountData[otherid][pFaction], AccountData[otherid][pFactionRank], AccountData[otherid][pID]);
	mysql_pquery(g_SQL, string);

	format(string, sizeof(string), "AdmCmd: %s has assigned you to the faction %s with rank %s.", AccountData[playerid][pAdminname], GetFactionName(otherid), GetRankName(otherid));
	SendClientMessage(otherid, Y_LIGHTRED, string);

	SendAdm(playerid, "You have assigned %s(%d) to the %s faction with rank %s.", AccountData[otherid][pName], otherid, GetFactionName(otherid), GetRankName(otherid));
    
	return 1;
}

YCMD:setfamily(playerid, params[], help)
{
	if(AccountData[playerid][pAdmin] < 4)
		return PermissionError(playerid);
	
	new otherid, fmid, frank;
	if(sscanf(params, "udd", otherid, fmid, frank)) return SUM(playerid, "/setfamily [playerid] [family id] [rank 1 - 4]");
	if(!IsPlayerConnected(otherid)) return ShowTDN(playerid, NOTIFICATION_ERROR, "Pemain tersebut tidak terkoneksi ke server!");
	if(!Iter_Contains(Fams, fmid)) return ShowTDN(playerid, NOTIFICATION_ERROR, "Invalid family ID!");
	if(frank < 1 || frank > 6) return ShowTDN(playerid, NOTIFICATION_ERROR, "Rank hanya dapat diisi 1 atau 6!");

	AccountData[otherid][pFamily] = fmid;
	AccountData[otherid][pFamilyRank] = frank;

	static string[158];
	mysql_format(g_SQL, string, sizeof(string), "UPDATE `player_characters` SET `Char_Family` = %d, `Char_FamilyRank` = %d WHERE `pID` = %d", AccountData[otherid][pFamily], AccountData[otherid][pFamilyRank], AccountData[otherid][pID]);
	mysql_pquery(g_SQL, string);

	format(string, sizeof(string), "AdmCmd: %s has assigned you to the family %s with rank %s.", AccountData[playerid][pAdminname], GetFamilyName(fmid), GetFamilyRankName(otherid));
	SendClientMessage(otherid, Y_LIGHTRED, string);

	SendAdm(playerid, "You have assigned %s(%d) to the %s family with rank %s.", AccountData[otherid][pName], otherid, GetFamilyName(fmid), GetFamilyRankName(otherid));
	return 1;
}

YCMD:kickfamily(playerid, params[], help)
{
	if(AccountData[playerid][pAdmin] < 4)
		return PermissionError(playerid);
	
	new otherid;
	if(sscanf(params, "u", otherid)) return SUM(playerid, "/kickfamily [playerid]");
	if(!IsPlayerConnected(otherid)) return ShowTDN(playerid, NOTIFICATION_ERROR, "Pemain tersebut tidak terkoneksi ke server!");
	if(AccountData[otherid][pFamily] < 0) return ShowTDN(playerid, NOTIFICATION_ERROR, "Pemain tersebut bukan anggota dari family official manapun!");

	AccountData[otherid][pFamily] = -1;
	AccountData[otherid][pFamilyRank] = 0;

	static string[158];
	mysql_format(g_SQL, string, sizeof(string), "UPDATE `player_characters` SET `Char_Family` = -1, `Char_FamilyRank` = 0 WHERE `pID` = %d", AccountData[otherid][pID]);
	mysql_pquery(g_SQL, string);

	format(string, sizeof(string), "AdmCmd: %s has removed you from the family.", AccountData[playerid][pAdminname]);
	SendClientMessage(otherid, Y_LIGHTRED, string);

	SendAdm(playerid, "You have removed %s(%d) from the family.", AccountData[otherid][pName], otherid);
	return 1;
}