YCMD:buy(playerid, params[], help)
{
    if(AccountData[playerid][pInBiz] == -1) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda harus berada di dalam bisnis!");

    new bizid = AccountData[playerid][pInBiz];
    if(BizData[bizid][bizType] == 1)
    {
        new haji[555];
        format(haji, sizeof(haji), "Nama\tHarga\n\
        Udud (12 batang)\t$%s\n\
        "GRAY"Pancingan\t"GRAY"$%s\n\
        Baseball Bat\t$%s\n\
        "GRAY"Knife\t"GRAY"$%s\n\
        Golf Stick\t$%s\n\
        "GRAY"Pool Cue\t"GRAY"$%s\n\
        Hunting Rifle\t$%s\n\
        "GRAY"Hunting Ammo (24x)\t"GRAY"$%s\n\
        Obeng\t$%s\n\
        "GRAY"Hoe\t"GRAY"$%s",
        FormatMoney(BizData[bizid][bizProdPrice][0]),
        FormatMoney(BizData[bizid][bizProdPrice][1]),
        FormatMoney(BizData[bizid][bizProdPrice][2]),
        FormatMoney(BizData[bizid][bizProdPrice][3]),
        FormatMoney(BizData[bizid][bizProdPrice][4]),
        FormatMoney(BizData[bizid][bizProdPrice][5]),
        FormatMoney(BizData[bizid][bizProdPrice][6]),
        FormatMoney(BizData[bizid][bizProdPrice][7]),
        FormatMoney(BizData[bizid][bizProdPrice][8]),
        FormatMoney(BizData[bizid][bizProdPrice][9]));
        Dialog_Show(playerid, "BizBuyProduct", DIALOG_STYLE_TABLIST_HEADERS, ""ARIVENA"Arivena Theater "WHITE"- Shop Menu", haji, "Buy", "Batal");
    }
    
    if(BizData[bizid][bizType] == 2)
    {
        new haji[555];
        format(haji, sizeof(haji), "Nama\tHarga\n\
        Arivhone (Smartphone)\t$%s\n\
        "GRAY"Radio\t"GRAY"$%s\n\
        Earphone\t$%s\n\
        "GRAY"Boombox\t"GRAY"$%s\n\
        Spraycan\t"GRAY"$%s",
        FormatMoney(BizData[bizid][bizProdPrice][0]),
        FormatMoney(BizData[bizid][bizProdPrice][1]),
        FormatMoney(BizData[bizid][bizProdPrice][2]),
        FormatMoney(BizData[bizid][bizProdPrice][3]),
        FormatMoney(BizData[bizid][bizProdPrice][4]));
        Dialog_Show(playerid, "BizBuyProduct", DIALOG_STYLE_TABLIST_HEADERS, ""ARIVENA"Arivena Theater "WHITE"- Shop Menu", haji, "Buy", "Batal");
    }
    return 1;
}

YCMD:restockbiz(playerid, params[], help)
{
    if(AccountData[playerid][pInBiz] == -1) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda harus berada di dalam bisnis!");

    new bizid = AccountData[playerid][pInBiz], erex[512];
    if(BizData[bizid][bizOwnerID] != AccountData[playerid][pID]) return ShowTDN(playerid, NOTIFICATION_ERROR, "Bisnis ini bukan milik anda!");

    if(BizData[bizid][bizType] == 1)
    {
        format(erex, sizeof(erex), "Name\tCurrent stocks\n\
        Udud (12 batang)\t%d\n\
        "GRAY"Pancingan\t"GRAY"%d\n\
        Baseball Bat\t%d\n\
        "GRAY"Knife\t"GRAY"%d\n\
        Golf Stick\t%d\n\
        "GRAY"Pool Cue\t"GRAY"%d\n\
        Hunting Rifle\t%d\n\
        "GRAY"Hunting Ammo (24x)\t"GRAY"%d\n\
        Obeng\t%d\n\
        "GRAY"Hoe\t"GRAY"%d",
        BizData[bizid][bizProdStock][0],
        BizData[bizid][bizProdStock][1],
        BizData[bizid][bizProdStock][2],
        BizData[bizid][bizProdStock][3],
        BizData[bizid][bizProdStock][4],
        BizData[bizid][bizProdStock][5],
        BizData[bizid][bizProdStock][6],
        BizData[bizid][bizProdStock][7],
        BizData[bizid][bizProdStock][8],
        BizData[bizid][bizProdStock][9]);
        Dialog_Show(playerid, "BizRestock", DIALOG_STYLE_TABLIST_HEADERS, ""ARIVENA"Arivena Theater "WHITE"- Biz Restock", erex, "Pilih", "Batal");
    }
    
    if(BizData[bizid][bizType] == 2)
    {
        format(erex, sizeof(erex), "Name\tCurrent stocks\n\
        Arivhone (Smartphone)\t%d\n\
        "GRAY"Radio\t"GRAY"%d\n\
        Earphone\t%d\n\
        "GRAY"Boombox\t"GRAY"%d\n\
        Chainsaw Electric\t%d\n\
        "GRAY"Battery\t"GRAY"%d\n\
        Spraycan\t%d",
        BizData[bizid][bizProdStock][0],
        BizData[bizid][bizProdStock][1],
        BizData[bizid][bizProdStock][2],
        BizData[bizid][bizProdStock][3],
        BizData[bizid][bizProdStock][4],
        BizData[bizid][bizProdStock][5],
        BizData[bizid][bizProdStock][6]);
        Dialog_Show(playerid, "BizRestock", DIALOG_STYLE_TABLIST_HEADERS, ""ARIVENA"Arivena Theater "WHITE"- Biz Restock", erex, "Pilih", "Batal");
    }
    return 1;
}

YCMD:bizmenu(playerid, params[], help)
{
    if(AccountData[playerid][pInBiz] == -1) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda harus berada di dalam bisnis!");

    new bizid = AccountData[playerid][pInBiz], erex[512];
    if(BizData[bizid][bizOwnerID] != AccountData[playerid][pID]) return ShowTDN(playerid, NOTIFICATION_ERROR, "Bisnis ini bukan milik anda!");

    if(BizData[bizid][bizType] == 1)
    {
        format(erex, sizeof(erex), "Name\tSettings\n\
        Nama Biz\t%s\n\
        "GRAY"Profit\t"GRAY"$%s\n\
        Biaya Masuk\t$%s\n\
        "GRAY"Harga Udud (12 batang)\t"GRAY"$%s\n\
        Harga Pancingan\t$%s\n\
        "GRAY"Harga Baseball Bat\t"GRAY"$%s\n\
        Harga Knife\t$%s\n\
        "GRAY"Harga Golf Stick\t"GRAY"$%s\n\
        Harga Pool Cue\t$%s\n\
        "GRAY"Harga Hunting Rifle\t"GRAY"$%s\n\
        Harga Hunting Ammo (24x)\t$%s\n\
        "GRAY"Harga Obeng\t"GRAY"$%s\n\
        Harga Hoe\t$%s\n\
        "GRAY"Status\t%s",
        BizData[bizid][bizName],
        FormatMoney(BizData[bizid][bizMoney]),
        FormatMoney(BizData[bizid][bizEnteranceFee]),
        FormatMoney(BizData[bizid][bizProdPrice][0]),
        FormatMoney(BizData[bizid][bizProdPrice][1]),
        FormatMoney(BizData[bizid][bizProdPrice][2]),
        FormatMoney(BizData[bizid][bizProdPrice][3]),
        FormatMoney(BizData[bizid][bizProdPrice][4]),
        FormatMoney(BizData[bizid][bizProdPrice][5]),
        FormatMoney(BizData[bizid][bizProdPrice][6]),
        FormatMoney(BizData[bizid][bizProdPrice][7]),
        FormatMoney(BizData[bizid][bizProdPrice][8]),
        FormatMoney(BizData[bizid][bizProdPrice][9]),
        (BizData[bizid][bizLocked]) ? (""RED"Closed") : (""GREEN"Open"));
        Dialog_Show(playerid, "BizMenu", DIALOG_STYLE_TABLIST_HEADERS, ""ARIVENA"Arivena Theater "WHITE"- Biz Menu", erex, "Pilih", "Batal");
    }
    
    if(BizData[bizid][bizType] == 2)
    {
        format(erex, sizeof(erex), "Name\tSettings\n\
        Nama Biz\t%s\n\
        "GRAY"Profit\t"GRAY"$%s\n\
        Biaya Masuk\t$%s\n\
        "GRAY"Harga Arivhone (Smartphone)\t"GRAY"$%s\n\
        Harga Radio\t$%s\n\
        "GRAY"Harga Earphone\t"GRAY"$%s\n\
        Harga Boombox\t$%s\n\
        "GRAY"Harga Chainsaw Electric\t"GRAY"$%s\n\
        Harga Battery\t$%s\n\
        "GRAY"Harga Spraycan\t"GRAY"$%s\n\
        Status\t%s",
        BizData[bizid][bizName],
        FormatMoney(BizData[bizid][bizMoney]),
        FormatMoney(BizData[bizid][bizEnteranceFee]),
        FormatMoney(BizData[bizid][bizProdPrice][0]),
        FormatMoney(BizData[bizid][bizProdPrice][1]),
        FormatMoney(BizData[bizid][bizProdPrice][2]),
        FormatMoney(BizData[bizid][bizProdPrice][3]),
        FormatMoney(BizData[bizid][bizProdPrice][4]),
        FormatMoney(BizData[bizid][bizProdPrice][5]),
        FormatMoney(BizData[bizid][bizProdPrice][6]),
        (BizData[bizid][bizLocked]) ? (""RED"Closed") : (""GREEN"Open"));
        Dialog_Show(playerid, "BizMenu", DIALOG_STYLE_TABLIST_HEADERS, ""ARIVENA"Arivena Theater "WHITE"- Biz Menu", erex, "Pilih", "Batal");
    }
    return 1;
}

YCMD:buybiz(playerid, params[], help)
{
    new bizid = Biz_Nearest(playerid);
    if(bizid == -1) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda tidak dekat dengan bisnis manapun!");
    if(!isnull(BizData[bizid][bizOwnerName])) return ShowTDN(playerid, NOTIFICATION_ERROR, "Bisnis ini sudah dimiliki seseorang!");
    if(Player_BizCount(playerid) > 0) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda sudah memiliki bisnis!");
    if(AccountData[playerid][pMoney] < BizData[bizid][bizPrice]) return ShowTDN(playerid, NOTIFICATION_ERROR, "Uang anda tidak cukup!");

    TakePlayerMoneyEx(playerid, BizData[bizid][bizPrice]);
    BizData[bizid][bizOwnerID] = AccountData[playerid][pID];
    strcopy(BizData[bizid][bizOwnerName], AccountData[playerid][pName]);
    BizData[bizid][bizMoney] = 0;

    Biz_Save(bizid);
    Biz_Refresh(bizid);
    ShowTDN(playerid, NOTIFICATION_SUCCESS, "Anda berhasil membeli bisnis ini!");
    return 1;
}

YCMD:addbiz(playerid, params[], help)
{
    new bizid = Iter_Free(Bizes), type, price;
    if(AccountData[playerid][pAdmin] < 5) return PermissionError(playerid);
    if(bizid == -1) return ShowTDN(playerid, NOTIFICATION_ERROR, "Jumlah dynamic businesses telah mencapai batas maksimum!");
    if(sscanf(params, "dd", type, price)) return SUM(playerid, "/addbiz [type] [price]");

    if(type < 1 || type > 2) return ShowTDN(playerid, NOTIFICATION_ERROR, "Type tidak valid! (1 - 2)");
    if(price < 0) return ShowTDN(playerid, NOTIFICATION_ERROR, "Harga tidak valid!");

    strcopy(BizData[bizid][bizName], "-");
    BizData[bizid][bizOwnerID] = 0;
    BizData[bizid][bizOwnerName][0] = EOS;
    BizData[bizid][bizLocked] = false;
    BizData[bizid][bizMoney] = 0;
    BizData[bizid][bizType] = type;
    BizData[bizid][bizPrice] = price;
    BizData[bizid][bizEnteranceFee] = 500;

    for(new x; x < 11; x++)
    {
        BizData[bizid][bizProdStock][x] = 200;
    }

    for(new x; x < 11; x++)
    {
        BizData[bizid][bizProdPrice][x] = 2000;
    }

    GetPlayerPos(playerid, BizData[bizid][bizExtPos][0], BizData[bizid][bizExtPos][1], BizData[bizid][bizExtPos][2]);
    GetPlayerFacingAngle(playerid, BizData[bizid][bizExtPos][3]);

    if(type == 1)
    {
        BizData[bizid][bizIntPos][0] = 1151.1515;
		BizData[bizid][bizIntPos][1] = 1262.2477;
		BizData[bizid][bizIntPos][2] = 11.1779;
		BizData[bizid][bizIntPos][3] =  88.8090;
		BizData[bizid][bizIntInt] = 1;
    }

    else if(type == 2)
    {
        BizData[bizid][bizIntPos][0] = 1156.5273;
		BizData[bizid][bizIntPos][1] = 1303.2030;
		BizData[bizid][bizIntPos][2] = 10.8507;
		BizData[bizid][bizIntPos][3] =  89.1223;
		BizData[bizid][bizIntInt] = 2;
    }

    BizData[bizid][bizExtVw] = GetPlayerVirtualWorld(playerid);
    BizData[bizid][bizExtInt] = GetPlayerInterior(playerid);
    BizData[bizid][bizIntVw] = bizid+1;

    new sjws[525];
    format(sjws, sizeof(sjws), "%s\n"YELLOW"%s\n"WHITE"$%s\n"YELLOW"'/buybiz'\n"WHITE"Enterance Fee $%s\n%s", ReturnBizTypeName(bizid), BizData[bizid][bizName], FormatMoney(BizData[bizid][bizPrice]), FormatMoney(BizData[bizid][bizEnteranceFee]), (BizData[bizid][bizLocked]) ? (""RED"Tutup") : (""GREEN"Buka"));
    BizData[bizid][bizLabel] = CreateDynamic3DTextLabel(sjws, 0xFFFFFFBF, BizData[bizid][bizExtPos][0], BizData[bizid][bizExtPos][1], BizData[bizid][bizExtPos][2] + 1.25, 10.00, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, BizData[bizid][bizExtVw], BizData[bizid][bizExtInt], -1, 10.00, -1, 0);
    BizData[bizid][bizPickup] = CreateDynamicPickup(19133, 23, BizData[bizid][bizExtPos][0], BizData[bizid][bizExtPos][1], BizData[bizid][bizExtPos][2], BizData[bizid][bizExtVw], BizData[bizid][bizExtInt], -1, 30.00, -1, 0);
    
    Iter_Add(Bizes, bizid);

    static dddstr[1688];
    mysql_format(g_SQL, dddstr, sizeof(dddstr), "INSERT INTO `biz` SET `ID`=%d, `Name`='%e', `OwnerID`=%d, `OwnerName`='%e', `Locked`=%d, `Money`=%d, `Type`=%d, `Price`=%d, `Fee`=%d, \
    `ProdStock0`=%d, `ProdStock1`=%d, `ProdStock2`=%d, `ProdStock3`=%d, `ProdStock4`=%d, `ProdStock5`=%d, `ProdStock6`=%d, `ProdStock7`=%d, `ProdStock8`=%d, `ProdStock9`=%d, `ProdStock10`=%d, \
    `ProdPrice0`=%d, `ProdPrice1`=%d, `ProdPrice2`=%d, `ProdPrice3`=%d, `ProdPrice4`=%d, `ProdPrice5`=%d, `ProdPrice6`=%d, `ProdPrice7`=%d, `ProdPrice8`=%d, `ProdPrice9`=%d, `ProdPrice10`=%d, \
    `X`='%f', `Y`='%f', `Z`='%f', `A`='%f', `IntX`='%f', `IntY`='%f', `IntZ`='%f', `IntA`='%f', `ExtVw`=%d, `ExtInt`=%d, `IntVw`=%d, `IntInt`=%d", 
    bizid,
    BizData[bizid][bizName], 
    BizData[bizid][bizOwnerID], 
    BizData[bizid][bizOwnerName], 
    BizData[bizid][bizLocked], 
    BizData[bizid][bizMoney], 
    BizData[bizid][bizType],
    BizData[bizid][bizPrice],
    BizData[bizid][bizEnteranceFee],
    BizData[bizid][bizProdStock][0],
    BizData[bizid][bizProdStock][1],
    BizData[bizid][bizProdStock][2],
    BizData[bizid][bizProdStock][3],
    BizData[bizid][bizProdStock][4],
    BizData[bizid][bizProdStock][5],
    BizData[bizid][bizProdStock][6],
    BizData[bizid][bizProdStock][7],
    BizData[bizid][bizProdStock][8],
    BizData[bizid][bizProdStock][9],
    BizData[bizid][bizProdStock][10],
    BizData[bizid][bizProdPrice][0],
    BizData[bizid][bizProdPrice][1],
    BizData[bizid][bizProdPrice][2],
    BizData[bizid][bizProdPrice][3],
    BizData[bizid][bizProdPrice][4],
    BizData[bizid][bizProdPrice][5],
    BizData[bizid][bizProdPrice][6],
    BizData[bizid][bizProdPrice][7],
    BizData[bizid][bizProdPrice][8],
    BizData[bizid][bizProdPrice][9],
    BizData[bizid][bizProdPrice][10],
    BizData[bizid][bizExtPos][0], 
    BizData[bizid][bizExtPos][1], 
    BizData[bizid][bizExtPos][2], 
    BizData[bizid][bizExtPos][3],
    BizData[bizid][bizIntPos][0],
    BizData[bizid][bizIntPos][1],
    BizData[bizid][bizIntPos][2],
    BizData[bizid][bizIntPos][3],
    BizData[bizid][bizExtVw],
    BizData[bizid][bizExtInt],
    BizData[bizid][bizIntVw],
    BizData[bizid][bizIntInt]);
    mysql_pquery(g_SQL, dddstr, "OnBizCreated", "ii", playerid, bizid);
    return 1;
}

YCMD:editbiz(playerid, params[], help)
{
    if(AccountData[playerid][pAdmin] < 5) return PermissionError(playerid);

    new bizid, type[24], string[128];
    if(sscanf(params, "ds[24]S()[128]", bizid, type, string)) return SUM(playerid, "/editbiz [id] [name] (pos, reset, type)");
    if(!Iter_Contains(Bizes, bizid)) return ShowTDN(playerid, NOTIFICATION_ERROR, "ID Bisnis tidak valid!");

    if(!strcmp(type, "pos", true))
    {
        GetPlayerPos(playerid, BizData[bizid][bizExtPos][0], BizData[bizid][bizExtPos][1], BizData[bizid][bizExtPos][2]);
        GetPlayerFacingAngle(playerid, BizData[bizid][bizExtPos][3]);
        BizData[bizid][bizExtVw] = GetPlayerVirtualWorld(playerid);
        BizData[bizid][bizExtInt] = GetPlayerInterior(playerid);
        Biz_Save(bizid);
        Biz_Refresh(bizid);

        SendStaffMessage(Y_LIGHTRED, "AdmCmd: %s change location for Business ID: %d.", AccountData[playerid][pAdminname], bizid);
    }

    else if(!strcmp(type, "type", true))
    {
        new btype;

        if(sscanf(string, "d", btype))
            return SUM(playerid, "/editbiz [id] [type] [1 - 2]");

        BizData[bizid][bizType] = btype;

        Biz_Save(bizid);
        Biz_Refresh(bizid);

        SendStaffMessage(Y_LIGHTRED, "AdmCmd: %s has change the type of Business ID: %d to %d.", AccountData[playerid][pAdminname], bizid, btype);
    }

    else if(!strcmp(type, "reset", true))
    {
        strcopy(BizData[bizid][bizName], "-");
        BizData[bizid][bizOwnerName][0] = EOS;
        BizData[bizid][bizOwnerID] = 0;
        BizData[bizid][bizMoney] = 0;

        for(new x; x < 11; x++)
        {
            BizData[bizid][bizProdStock][x] = 200;
        }

        for(new x; x < 11; x++)
        {
            BizData[bizid][bizProdPrice][x] = 2000;
        }

        Biz_Save(bizid);
        Biz_Refresh(bizid);

        SendStaffMessage(Y_LIGHTRED, "AdmCmd: %s has reset Business ID: %d.", AccountData[playerid][pAdminname], bizid);
    }
    return 1;
}

YCMD:gotobiz(playerid, params[], help)
{
    new bizid;
	if(AccountData[playerid][pAdmin] < 5) return PermissionError(playerid);
		
	if(sscanf(params, "d", bizid))
		return SUM(playerid, "/gotobiz [bizid]");

	if(!Iter_Contains(Bizes, bizid)) return ShowTDN(playerid, NOTIFICATION_ERROR, "ID Bisnis tidak valid!");
	SetPlayerPositionEx(playerid, BizData[bizid][bizExtPos][0], BizData[bizid][bizExtPos][1], BizData[bizid][bizExtPos][2], -90);
    SetPlayerInteriorEx(playerid, BizData[bizid][bizExtInt]);
    SetPlayerVirtualWorldEx(playerid, BizData[bizid][bizExtVw]);

    AccountData[playerid][pInDoor] = -1;
	AccountData[playerid][pInHouse] = -1;
    AccountData[playerid][pInBiz] = -1;
	AccountData[playerid][pInRusun] = -1;
    AccountData[playerid][pInGudang] = -1;
	return 1;
}

YCMD:removebiz(playerid, params[], help)
{
    new bizid, strgbg[128];
    if(AccountData[playerid][pAdmin] < 5) return PermissionError(playerid);
    if(sscanf(params, "d", bizid)) return SUM(playerid, "/removebiz [bizid]");
    if(!Iter_Contains(Bizes, bizid)) return ShowTDN(playerid, NOTIFICATION_ERROR, "ID Bisnis tidak valid!");

    strcopy(BizData[bizid][bizName], "-");
    BizData[bizid][bizOwnerID] = 0;
    BizData[bizid][bizOwnerName][0] = EOS;
    BizData[bizid][bizLocked] = false;
    BizData[bizid][bizMoney] = 0;
    BizData[bizid][bizType] = 0;
    BizData[bizid][bizPrice] = 0;
    BizData[bizid][bizEnteranceFee] = 0;

    for(new x; x < 11; x++)
    {
        BizData[bizid][bizProdStock][x] = 0;
    }

    for(new x; x < 11; x++)
    {
        BizData[bizid][bizProdPrice][x] = 0;
    }

    BizData[bizid][bizExtPos][0] = BizData[bizid][bizExtPos][1] = BizData[bizid][bizExtPos][2] = BizData[bizid][bizExtPos][3] = 0.0;
    BizData[bizid][bizIntPos][0] = BizData[bizid][bizIntPos][1] = BizData[bizid][bizIntPos][2] = BizData[bizid][bizIntPos][3] = 0.0;
    BizData[bizid][bizExtVw] = 0;
    BizData[bizid][bizExtInt] = 0;
    BizData[bizid][bizIntVw] = 0;
    BizData[bizid][bizIntInt] = 0;

    if(DestroyDynamicPickup(BizData[bizid][bizPickup]))
        BizData[bizid][bizPickup] = STREAMER_TAG_PICKUP: INVALID_STREAMER_ID;

    if(DestroyDynamic3DTextLabel(BizData[bizid][bizLabel]))
        BizData[bizid][bizLabel] = STREAMER_TAG_3D_TEXT_LABEL: INVALID_STREAMER_ID;

    Iter_Remove(Bizes, bizid);
    mysql_format(g_SQL, strgbg, sizeof(strgbg), "DELETE FROM `biz` WHERE `ID` = %d", bizid);
    mysql_pquery(g_SQL, strgbg);
    SendStaffMessage(Y_LIGHTRED, "AdmCmd: %s has removed Business ID: %d.", AccountData[playerid][pAdminname], bizid);
    return 1;
}