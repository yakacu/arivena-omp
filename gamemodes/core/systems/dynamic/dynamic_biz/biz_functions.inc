#include <YSI_Coding/y_hooks>

#define MAX_BIZ 100

enum e_bizdetails
{
    bizName[MAX_PLAYER_NAME + 1],
    bizOwnerID,
    bizOwnerName[MAX_PLAYER_NAME + 1],
    bizLocked,
    bizMoney,
    bizType,
    bizPrice,
    bizEnteranceFee,
    bizProdStock[11],
    bizProdPrice[11],
    Float:bizExtPos[4],
    Float:bizIntPos[4],
    bizExtVw,
    bizExtInt,
    bizIntVw,
    bizIntInt,

    //not saved
    STREAMER_TAG_PICKUP:bizPickup,
    STREAMER_TAG_3D_TEXT_LABEL:bizLabel
};
new BizData[MAX_BIZ][e_bizdetails],
    Iterator:Bizes<MAX_BIZ>;

GetShopNearestBizPlayer(playerid, type)
{
    foreach(new x : Bizes)
    {
        if(BizData[x][bizExtInt] == 0 && BizData[x][bizExtVw] == 0 && BizData[x][bizType] == type)
        {
            if(IsPlayerInRangeOfPoint(playerid, 600.0, BizData[x][bizExtPos][0], BizData[x][bizExtPos][1], BizData[x][bizExtPos][2]))
            {
                if(DestroyDynamicRaceCP(AccountData[playerid][pGPSCP]))
                    AccountData[playerid][pGPSCP] = STREAMER_TAG_RACE_CP: INVALID_STREAMER_ID;

                AccountData[playerid][pUsingGPS] = true;
                AccountData[playerid][pGPSCP] = CreateDynamicRaceCP(1, BizData[x][bizExtPos][0], BizData[x][bizExtPos][1], BizData[x][bizExtPos][2], BizData[x][bizExtPos][0], BizData[x][bizExtPos][1], BizData[x][bizExtPos][2], 3.5, -1, -1, playerid, 10000.00, -1, 0);
                ShowTDN(playerid, NOTIFICATION_WARNING, "Mohon ikuti checkpoint di map!");
                return 1;
            }
        }
    }
    ShowTDN(playerid, NOTIFICATION_ERROR, "Tidak ada shop terdekat dari lokasi anda!");
    return 1;
}

ReturnBizTypeName(bizid)
{
    new typename[24];

    if(bizid != -1)
    {
        switch(BizData[bizid][bizType])
        {
            case 1: //general store
            {
                strcopy(typename, "[General Store]");
            }
            case 2: //electronic shop
            {
                strcopy(typename, "[Electronic Shop]");
            }
            default:
            {
                strcopy(typename, "[Unknown]");
            }
        }
    }
    return typename;
}

Biz_Save(bizid)
{
    static dddstr[1688];
    mysql_format(g_SQL, dddstr, sizeof(dddstr), "UPDATE `biz` SET `Name`='%e', `OwnerID`=%d, `OwnerName`='%e', `Locked`=%d, `Money`=%d, `Type`=%d, `Price`=%d, `Fee`=%d, \
    `ProdStock0`=%d, `ProdStock1`=%d, `ProdStock2`=%d, `ProdStock3`=%d, `ProdStock4`=%d, `ProdStock5`=%d, `ProdStock6`=%d, `ProdStock7`=%d, `ProdStock8`=%d, `ProdStock9`=%d, `ProdStock10`=%d, \
    `ProdPrice0`=%d, `ProdPrice1`=%d, `ProdPrice2`=%d, `ProdPrice3`=%d, `ProdPrice4`=%d, `ProdPrice5`=%d, `ProdPrice6`=%d, `ProdPrice7`=%d, `ProdPrice8`=%d, `ProdPrice9`=%d, `ProdPrice10`=%d, \
    `X`='%f', `Y`='%f', `Z`='%f', `A`='%f', `IntX`='%f', `IntY`='%f', `IntZ`='%f', `IntA`='%f', `ExtVw`=%d, `ExtInt`=%d, `IntVw`=%d, `IntInt`=%d WHERE `ID`=%d", 
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
    BizData[bizid][bizIntInt],
    bizid);
    mysql_pquery(g_SQL, dddstr);
    return 1;
}

Biz_Refresh(bizid)
{
    if(bizid != -1)
    {
        new sjws[525];
        if(isnull(BizData[bizid][bizOwnerName]))
        {
            format(sjws, sizeof(sjws), "%s/n"YELLOW"%s/n"WHITE"$%s/n"YELLOW"'/buybiz'/n"WHITE"Enterance Fee $%s/n%s", ReturnBizTypeName(bizid), BizData[bizid][bizName], FormatMoney(BizData[bizid][bizPrice]), FormatMoney(BizData[bizid][bizEnteranceFee]), (BizData[bizid][bizLocked]) ? (""RED"Closed") : (""GREEN"Open"));
        }
        else
        {
            format(sjws, sizeof(sjws), "%s/n"YELLOW"%s/n"WHITE"%s/n%s/n"WHITE"Enterance Fee $%s/n%s", ReturnBizTypeName(bizid), BizData[bizid][bizName], BizData[bizid][bizOwnerName], GetLocation(BizData[bizid][bizExtPos][0], BizData[bizid][bizExtPos][1], BizData[bizid][bizExtPos][2]), FormatMoney(BizData[bizid][bizEnteranceFee]), (BizData[bizid][bizLocked]) ? (""RED"Closed") : (""GREEN"Open"));
        }
        UpdateDynamic3DTextLabelText(BizData[bizid][bizLabel], 0xFFFFFFBF, sjws);

        Streamer_SetItemPos(STREAMER_TYPE_3D_TEXT_LABEL, BizData[bizid][bizLabel], BizData[bizid][bizExtPos][0], BizData[bizid][bizExtPos][1], BizData[bizid][bizExtPos][2] + 1.25);
        Streamer_SetIntData(STREAMER_TYPE_3D_TEXT_LABEL, BizData[bizid][bizLabel], E_STREAMER_WORLD_ID, BizData[bizid][bizExtVw]);
        Streamer_SetIntData(STREAMER_TYPE_3D_TEXT_LABEL, BizData[bizid][bizLabel], E_STREAMER_INTERIOR_ID, BizData[bizid][bizExtInt]);

        Streamer_SetItemPos(STREAMER_TYPE_PICKUP, BizData[bizid][bizPickup], BizData[bizid][bizExtPos][0], BizData[bizid][bizExtPos][1], BizData[bizid][bizExtPos][2]);
        Streamer_SetIntData(STREAMER_TYPE_PICKUP, BizData[bizid][bizPickup], E_STREAMER_WORLD_ID, BizData[bizid][bizExtVw]);
        Streamer_SetIntData(STREAMER_TYPE_PICKUP, BizData[bizid][bizPickup], E_STREAMER_INTERIOR_ID, BizData[bizid][bizExtInt]);
    }
    return 1;
}

Biz_Rebuild(bizid)
{
    if(bizid != -1)
    {
        if(DestroyDynamic3DTextLabel(BizData[bizid][bizLabel]))
            BizData[bizid][bizLabel] = STREAMER_TAG_3D_TEXT_LABEL: INVALID_STREAMER_ID;
        
        if(DestroyDynamicPickup(BizData[bizid][bizPickup]))
            BizData[bizid][bizPickup] = STREAMER_TAG_PICKUP: INVALID_STREAMER_ID;

        new sjws[525];
        if(isnull(BizData[bizid][bizOwnerName]))
        {
            format(sjws, sizeof(sjws), "%s/n"YELLOW"%s/n"WHITE"$%s/n"YELLOW"'/buybiz'/n"WHITE"Enterance Fee $%s/n%s", ReturnBizTypeName(bizid), BizData[bizid][bizName], FormatMoney(BizData[bizid][bizPrice]), FormatMoney(BizData[bizid][bizEnteranceFee]), (BizData[bizid][bizLocked]) ? (""RED"Closed") : (""GREEN"Open"));
        }
        else
        {
            format(sjws, sizeof(sjws), "%s/n"YELLOW"%s/n"WHITE"%s/n%s/n"WHITE"Enterance Fee $%s/n%s", ReturnBizTypeName(bizid), BizData[bizid][bizName], BizData[bizid][bizOwnerName], GetLocation(BizData[bizid][bizExtPos][0], BizData[bizid][bizExtPos][1], BizData[bizid][bizExtPos][2]), FormatMoney(BizData[bizid][bizEnteranceFee]), (BizData[bizid][bizLocked]) ? (""RED"Closed") : (""GREEN"Open"));
        }
        BizData[bizid][bizLabel] = CreateDynamic3DTextLabel(sjws, 0xFFFFFFBF, BizData[bizid][bizExtPos][0], BizData[bizid][bizExtPos][1], BizData[bizid][bizExtPos][2] + 1.25, 10.00, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, BizData[bizid][bizExtVw], BizData[bizid][bizExtInt], -1, 10.00, -1, 0);
        BizData[bizid][bizPickup] = CreateDynamicPickup(19133, 23, BizData[bizid][bizExtPos][0], BizData[bizid][bizExtPos][1], BizData[bizid][bizExtPos][2], BizData[bizid][bizExtVw], BizData[bizid][bizExtInt], -1, 30.00, -1, 0);
    }
    return 1;
}

Player_BizCount(playerid)
{
    new counting;
    foreach(new bizid : Bizes)
    {
        if(BizData[bizid][bizOwnerID] == AccountData[playerid][pID])
        {
            counting++;
        }
    }
    return counting;
}

Biz_Nearest(playerid)
{
    foreach(new i : Bizes) if (IsPlayerInRangeOfPoint(playerid, 3.0, BizData[i][bizExtPos][0], BizData[i][bizExtPos][1], BizData[i][bizExtPos][2]))
	{
		if (GetPlayerInterior(playerid) == BizData[i][bizExtInt] && GetPlayerVirtualWorld(playerid) == BizData[i][bizExtVw])
			return i;
	}
	return -1;
}

/*
GetBizNearestFromPlayer(playerid)
{
    foreach(new x : Bizes)
    {
        if(BizData[x][bizExtInt] == 0 && BizData[x][bizExtVw] == 0)
        {
            if(IsPlayerInRangeOfPoint(playerid, 600.0, BizData[x][bizExtPos][0], BizData[x][bizExtPos][1], BizData[x][bizExtPos][2]))
            {
                if(DestroyDynamicRaceCP(AccountData[playerid][pGPSCP]))
                    AccountData[playerid][pGPSCP] = STREAMER_TAG_RACE_CP: INVALID_STREAMER_ID;

                AccountData[playerid][pUsingGPS] = true;
                AccountData[playerid][pGPSCP] = CreateDynamicRaceCP(1, BizData[x][bizExtPos][0], BizData[x][bizExtPos][1], BizData[x][bizExtPos][2], BizData[x][bizExtPos][0], BizData[x][bizExtPos][1], BizData[x][bizExtPos][2], 5.0, 0, 0, playerid, 10000.00, -1, 0);
                ShowTDN(playerid, "Please follow the checkpoint in your map!");
                return 1;
            }
        }
    }
    ShowTDN(playerid, NOTIFICATION_ERROR, "Tidak ada Biz terdekat dari posisi anda!");
    return 1;
}
*/

forward LoadBizes();
public LoadBizes()
{
    new rows = cache_num_rows();
 	if(rows)
  	{
 		new bizid;
		for(new i; i < rows; i++)
		{
            cache_get_value_name_int(i, "ID", bizid);
            cache_get_value_name(i, "Name", BizData[bizid][bizName]);
            cache_get_value_name_int(i, "OwnerID", BizData[bizid][bizOwnerID]);
            cache_get_value_name(i, "OwnerName", BizData[bizid][bizOwnerName]);
            cache_get_value_name_int(i, "Locked", BizData[bizid][bizLocked]);
            cache_get_value_name_int(i, "Money", BizData[bizid][bizMoney]);
            cache_get_value_name_int(i, "Type", BizData[bizid][bizType]);
            cache_get_value_name_int(i, "Price", BizData[bizid][bizPrice]);
            cache_get_value_name_int(i, "Fee", BizData[bizid][bizEnteranceFee]);
            cache_get_value_name_int(i, "ProdStock0", BizData[bizid][bizProdStock][0]);
            cache_get_value_name_int(i, "ProdStock1", BizData[bizid][bizProdStock][1]);
            cache_get_value_name_int(i, "ProdStock2", BizData[bizid][bizProdStock][2]);
            cache_get_value_name_int(i, "ProdStock3", BizData[bizid][bizProdStock][3]);
            cache_get_value_name_int(i, "ProdStock4", BizData[bizid][bizProdStock][4]);
            cache_get_value_name_int(i, "ProdStock5", BizData[bizid][bizProdStock][5]);
            cache_get_value_name_int(i, "ProdStock6", BizData[bizid][bizProdStock][6]);
            cache_get_value_name_int(i, "ProdStock7", BizData[bizid][bizProdStock][7]);
            cache_get_value_name_int(i, "ProdStock8", BizData[bizid][bizProdStock][8]);
            cache_get_value_name_int(i, "ProdStock9", BizData[bizid][bizProdStock][9]);
            cache_get_value_name_int(i, "ProdStock10", BizData[bizid][bizProdStock][10]);
            cache_get_value_name_int(i, "ProdPrice0", BizData[bizid][bizProdPrice][0]);
            cache_get_value_name_int(i, "ProdPrice1", BizData[bizid][bizProdPrice][1]);
            cache_get_value_name_int(i, "ProdPrice2", BizData[bizid][bizProdPrice][2]);
            cache_get_value_name_int(i, "ProdPrice3", BizData[bizid][bizProdPrice][3]);
            cache_get_value_name_int(i, "ProdPrice4", BizData[bizid][bizProdPrice][4]);
            cache_get_value_name_int(i, "ProdPrice5", BizData[bizid][bizProdPrice][5]);
            cache_get_value_name_int(i, "ProdPrice6", BizData[bizid][bizProdPrice][6]);
            cache_get_value_name_int(i, "ProdPrice7", BizData[bizid][bizProdPrice][7]);
            cache_get_value_name_int(i, "ProdPrice8", BizData[bizid][bizProdPrice][8]);
            cache_get_value_name_int(i, "ProdPrice9", BizData[bizid][bizProdPrice][9]);
            cache_get_value_name_int(i, "ProdPrice10", BizData[bizid][bizProdPrice][10]);
            cache_get_value_name_float(i, "X", BizData[bizid][bizExtPos][0]);
            cache_get_value_name_float(i, "Y", BizData[bizid][bizExtPos][1]);
            cache_get_value_name_float(i, "Z", BizData[bizid][bizExtPos][2]);
            cache_get_value_name_float(i, "A", BizData[bizid][bizExtPos][3]);
            cache_get_value_name_float(i, "IntX", BizData[bizid][bizIntPos][0]);
            cache_get_value_name_float(i, "IntY", BizData[bizid][bizIntPos][1]);
            cache_get_value_name_float(i, "IntZ", BizData[bizid][bizIntPos][2]);
            cache_get_value_name_float(i, "IntA", BizData[bizid][bizIntPos][3]);
            cache_get_value_name_int(i, "ExtVw", BizData[bizid][bizExtVw]);
            cache_get_value_name_int(i, "ExtInt", BizData[bizid][bizExtInt]);
            cache_get_value_name_int(i, "IntVw", BizData[bizid][bizIntVw]);
            cache_get_value_name_int(i, "IntInt", BizData[bizid][bizIntInt]);
            
			Biz_Rebuild(bizid);
			Iter_Add(Bizes, bizid);
        }
        printf("[Dynamic Biz] Total number of loaded Biz: %d.", rows);
	}
    return 1;
}

forward OnBizCreated(playerid, bizid);
public OnBizCreated(playerid, bizid)
{
    Biz_Save(bizid);

    SendStaffMessage(Y_LIGHTRED, "AdmCmd: %s create Biz with ID: %d.", AccountData[playerid][pAdminname], bizid);
    return 1;
}

Dialog:BizBuyProduct(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;

    new bizid = AccountData[playerid][pInBiz], price;
    if(bizid != -1)
    {
        static string[512];
        if(BizData[bizid][bizType] == 1)
        {
            if(listitem < 0 || listitem > 9) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda belum memilih sesuatu!");
            if(BizData[bizid][bizProdStock][listitem] < 1) return ShowTDN(playerid, NOTIFICATION_ERROR, "Stock sudah habis!");
            price = BizData[bizid][bizProdPrice][listitem];

            switch(listitem)
            {
                case 0: //Udud
                {
                    if(AccountData[playerid][pMoney] < price) return ShowTDN(playerid, NOTIFICATION_ERROR, "Uang anda tidak cukup!");

                    static Float:countingtotalweight;
                    countingtotalweight = GetTotalWeightFloat(playerid) + float(GetItemWeight("Udud"))/1000;
                    if(countingtotalweight > GetPlayerInventoryWeight(playerid)) return ShowTDN(playerid, NOTIFICATION_ERROR, "Your inventory is full!");

                    TakePlayerMoneyEx(playerid, price);

                    BizData[bizid][bizProdStock][0]--;
                    BizData[bizid][bizMoney] += price;
                    
                    Biz_Save(bizid);

                    Inventory_Add(playerid, "Udud", 19896, 12);
                    ShowItemBox(playerid, "Cash", sprintf("Removed $%sx", FormatMoney(price)), 1212, 4);
                    ShowItemBox(playerid, "Udud", "Received 1x", 19896, 5);

                    ShowTDN(playerid, NOTIFICATION_SUCCESS, "Transaksi berhasil dilakukan.");
                }
                case 1: //Pancingan
                {
                    if(AccountData[playerid][pMoney] < price) return ShowTDN(playerid, NOTIFICATION_ERROR, "Uang anda tidak cukup!");
                    static Float:countingtotalweight;
                    countingtotalweight = GetTotalWeightFloat(playerid) + float(GetItemWeight("Pancingan"))/1000;
                    if(countingtotalweight > GetPlayerInventoryWeight(playerid)) return ShowTDN(playerid, NOTIFICATION_ERROR, "Your inventory is full!");

                    TakePlayerMoneyEx(playerid, price);

                    BizData[bizid][bizProdStock][1]--;
                    BizData[bizid][bizMoney] += price;
                    
                    Biz_Save(bizid);

                    Inventory_Add(playerid, "Pancingan", 18632);
                    ShowItemBox(playerid, "Cash", sprintf("Removed $%sx", FormatMoney(price)), 1212, 4);
                    ShowItemBox(playerid, "Pancingan", "Received 1x", 18632, 5);

                    ShowTDN(playerid, NOTIFICATION_SUCCESS, "Transaksi berhasil dilakukan.");
                }
                case 2: //Baseball Bat
                {
                    if(AccountData[playerid][pMoney] < price) return ShowTDN(playerid, NOTIFICATION_ERROR, "Uang anda tidak cukup!");

                    TakePlayerMoneyEx(playerid, price);
                    GivePlayerWeaponEx(playerid, 5, 1, WEAPON_TYPE_PLAYER);
                    SendRPMeAboveHead(playerid, "Bought a Baseball Bat.");
                    BizData[bizid][bizProdStock][2]--;
                    BizData[bizid][bizMoney] += price;
                    
                    Biz_Save(bizid);
                    ShowItemBox(playerid, "Cash", sprintf("Removed $%sx", FormatMoney(price)), 1212, 4);
                    ShowItemBox(playerid, "Baseball Bat", "Received 1x", 336, 5);
                }
                case 3: //Pisau
                {
                    if(AccountData[playerid][pMoney] < price) return ShowTDN(playerid, NOTIFICATION_ERROR, "Uang anda tidak cukup!");

                    TakePlayerMoneyEx(playerid, price);
                    GivePlayerWeaponEx(playerid, 4, 1, WEAPON_TYPE_PLAYER);
                    BizData[bizid][bizProdStock][3]--;
                    BizData[bizid][bizMoney] += price;
                    
                    Biz_Save(bizid);
                    ShowItemBox(playerid, "Cash", sprintf("Removed $%sx", FormatMoney(price)), 1212, 4);
                    ShowItemBox(playerid, "Pisau", "Received 1x", 335, 5);
                }
                case 4: //Golf Stick
                {
                    if(AccountData[playerid][pMoney] < price) return ShowTDN(playerid, NOTIFICATION_ERROR, "Uang anda tidak cukup!");

                    TakePlayerMoneyEx(playerid, price);
                    GivePlayerWeaponEx(playerid, 2, 1, WEAPON_TYPE_PLAYER);
                    BizData[bizid][bizProdStock][4]--;
                    BizData[bizid][bizMoney] += price;
                    
                    Biz_Save(bizid);
                    ShowItemBox(playerid, "Cash", sprintf("Removed $%sx", FormatMoney(price)), 1212, 4);
                    ShowItemBox(playerid, "Golf Stick", "Received 1x", 333, 5);
                }
                case 5: //Pool Cue
                {
                    if(AccountData[playerid][pMoney] < price) return ShowTDN(playerid, NOTIFICATION_ERROR, "Uang anda tidak cukup!");

                    TakePlayerMoneyEx(playerid, price);
                    GivePlayerWeaponEx(playerid, 7, 1, WEAPON_TYPE_PLAYER);
                    BizData[bizid][bizProdStock][5]--;
                    BizData[bizid][bizMoney] += price;
                    
                    Biz_Save(bizid);
                    ShowItemBox(playerid, "Cash", sprintf("Removed $%sx", FormatMoney(price)), 1212, 4);
                    ShowItemBox(playerid, "Pool Cue", "Received 1x", 338, 5);
                }
                case 6: //Hunting Rifle
                {
                    if(AccountData[playerid][pMoney] < price) return ShowTDN(playerid, NOTIFICATION_ERROR, "Uang anda tidak cukup!");

                    TakePlayerMoneyEx(playerid, price);
                    AccountData[playerid][pHasHuntingRifle] = true;
                    BizData[bizid][bizProdStock][6]--;
                    BizData[bizid][bizMoney] += price;
                    
                    Biz_Save(bizid);
                    ShowItemBox(playerid, "Cash", sprintf("Removed $%sx", FormatMoney(price)), 1212, 4);
                    ShowItemBox(playerid, "Hunting Rifle", "Received 1x", 357, 5);
                }
                case 7: //Hunting Ammo
                {
                    if(AccountData[playerid][pMoney] < price) return ShowTDN(playerid, NOTIFICATION_ERROR, "Uang anda tidak cukup!");

                    TakePlayerMoneyEx(playerid, price);
                    Inventory_Add(playerid, "Hunt Ammo", 2358, 24);
                    BizData[bizid][bizProdStock][7]--;
                    BizData[bizid][bizMoney] += price;
                    
                    Biz_Save(bizid);

                    ShowItemBox(playerid, "Cash", sprintf("Removed $%sx", FormatMoney(price)), 1212, 4);
                    ShowItemBox(playerid, "Hunting Ammo", "Received 24x", 2358, 5);
                }
                case 8: //Obeng
                {
                    if(AccountData[playerid][pMoney] < price) return ShowTDN(playerid, NOTIFICATION_ERROR, "Uang anda tidak cukup!");
                    static Float:countingtotalweight;
                    countingtotalweight = GetTotalWeightFloat(playerid) + float(GetItemWeight("Obeng"))/1000;
                    if(countingtotalweight > GetPlayerInventoryWeight(playerid)) return ShowTDN(playerid, NOTIFICATION_ERROR, "Your inventory is full!");

                    if(PlayerHasItem(playerid,"Obeng")) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda sudah memiliki Obeng!");
                    
                    TakePlayerMoneyEx(playerid, price);
                    BizData[bizid][bizProdStock][8]--;
                    BizData[bizid][bizMoney] += price;
                    
                    Biz_Save(bizid);

                    Inventory_Add(playerid, "Obeng", 19627);
                    ShowItemBox(playerid, "Cash", sprintf("Removed $%sx", FormatMoney(price)), 1212, 4);
                    ShowItemBox(playerid, "Obeng", "Received 1x", 19627, 5);

                    ShowTDN(playerid, NOTIFICATION_SUCCESS, "Transaksi berhasil dilakukan.");
                }
                case 9: //hoe
                {
                    if(AccountData[playerid][pMoney] < price) return ShowTDN(playerid, NOTIFICATION_ERROR, "Uang anda tidak cukup!");
                    static Float:countingtotalweight;
                    countingtotalweight = GetTotalWeightFloat(playerid) + float(GetItemWeight("Hoe"))/1000;
                    if(countingtotalweight > GetPlayerInventoryWeight(playerid)) return ShowTDN(playerid, NOTIFICATION_ERROR, "Inventory anda sudah penuh!");

                    if(PlayerHasItem(playerid,"Hoe")) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda sudah memiliki hoe!");
                    
                    TakePlayerMoneyEx(playerid, price);
                    BizData[bizid][bizProdStock][8]--;
                    BizData[bizid][bizMoney] += price;
                    
                    Biz_Save(bizid);

                    Inventory_Add(playerid, "Hoe", 2228);
                    ShowItemBox(playerid, "Cash", sprintf("Removed $%sx", FormatMoney(price)), 1212, 4);
                    ShowItemBox(playerid, "Hoe", "Received 1x", 2228, 5);

                    ShowTDN(playerid, NOTIFICATION_SUCCESS, "Transaksi berhasil dilakukan.");
                }
            }
        }
        
        if(BizData[bizid][bizType] == 2)
        {
            if(listitem < 0 || listitem > 6) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda belum memilih sesuatu!");
            if(BizData[bizid][bizProdStock][listitem] < 1) return ShowTDN(playerid, NOTIFICATION_ERROR, "Stock sudah habis!");
            price = BizData[bizid][bizProdPrice][listitem];
            
            switch(listitem)
            {
                case 0: //smartphone
                {
                    if(AccountData[playerid][pMoney] < price) return ShowTDN(playerid, NOTIFICATION_ERROR, "Uang anda tidak cukup!");

                    static Float:countingtotalweight;
                    countingtotalweight = GetTotalWeightFloat(playerid) + float(GetItemWeight("Smartphone"))/1000;
                    if(countingtotalweight > GetPlayerInventoryWeight(playerid)) return ShowTDN(playerid, NOTIFICATION_ERROR, "Inventory anda sudah penuh!");

                    TakePlayerMoneyEx(playerid, price);
                    BizData[bizid][bizProdStock][0]--;
                    BizData[bizid][bizMoney] += price;
                    
                    Biz_Save(bizid);

                    mysql_format(g_SQL, string, sizeof(string), "SELECT * FROM `player_phones` WHERE `phoneOwner`=%d", AccountData[playerid][pID]);
                    mysql_pquery(g_SQL, string, "OnPlayerBuySmartphone", "i", playerid);

                    ShowItemBox(playerid, "Cash", sprintf("Removed $%sx", FormatMoney(price)), 1212, 4);
                    ShowItemBox(playerid, "Smartphone", "Received 1x", 19942, 5);
                    ShowTDN(playerid, NOTIFICATION_SUCCESS, "Transaksi berhasil dilakukan.");
                }
                case 1: //radio
                {
                    if(AccountData[playerid][pMoney] < price) return ShowTDN(playerid, NOTIFICATION_ERROR, "Uang anda tidak cukup!");
                    BizData[bizid][bizProdStock][1]--;
                    BizData[bizid][bizMoney] += price;
                    
                    Biz_Save(bizid);

                    TakePlayerMoneyEx(playerid, price);
                    PlayerVoiceData[playerid][pHasRadio] = true;

                    ShowItemBox(playerid, "Cash", sprintf("Removed $%sx", FormatMoney(price)), 1212, 4);
                    ShowItemBox(playerid, "Radio", "Received 1x", 19942, 5);

                    ShowTDN(playerid, NOTIFICATION_SUCCESS, "Transaksi berhasil dilakukan.");
                }
                case 2: //earphone
                {
                    if(AccountData[playerid][pMoney] < price) return ShowTDN(playerid, NOTIFICATION_ERROR, "Uang anda tidak cukup!");
                    BizData[bizid][bizProdStock][2]--;
                    BizData[bizid][bizMoney] += price;
                    
                    Biz_Save(bizid);

                    TakePlayerMoneyEx(playerid, price);
                    AccountData[playerid][pEarphone] = true;

                    ShowItemBox(playerid, "Cash", sprintf("Removed $%sx", FormatMoney(price)), 1212, 4);
                    ShowItemBox(playerid, "Earphone", "Received 1x", 19421, 5);

                    ShowTDN(playerid, NOTIFICATION_SUCCESS, "Transaksi berhasil dilakukan.");
                }
                case 3: //boombox
                {
                    if(AccountData[playerid][pVIP] < 1) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda bukan Donatur!");
                    
                    if(AccountData[playerid][pMoney] < price) return ShowTDN(playerid, NOTIFICATION_ERROR, "Uang anda tidak cukup!");
                    BizData[bizid][bizProdStock][3]--;
                    BizData[bizid][bizMoney] += price;
                    
                    Biz_Save(bizid);
                    
                    TakePlayerMoneyEx(playerid, price);
                    AccountData[playerid][pBoombox] = true;

                    ShowItemBox(playerid, "Cash", sprintf("Removed $%sx", FormatMoney(price)), 1212, 4);
                    ShowItemBox(playerid, "Boombox", "Received 1x", 2103, 5);

                    ShowTDN(playerid, NOTIFICATION_SUCCESS, "Transaksi berhasil dilakukan.");
                }
                case 4: //spraycan
                {
                    if(AccountData[playerid][pMoney] < price) return ShowTDN(playerid, NOTIFICATION_ERROR, "Uang anda tidak cukup!");
                    static Float:countingtotalweight;
                    countingtotalweight = GetTotalWeightFloat(playerid) + float(GetItemWeight("Pilox"))/1000;
                    if(countingtotalweight > GetPlayerInventoryWeight(playerid)) return ShowTDN(playerid, NOTIFICATION_ERROR, "Inventory anda sudah penuh!");
                    
                    TakePlayerMoneyEx(playerid, price);
                    BizData[bizid][bizProdStock][6]--;
                    BizData[bizid][bizMoney] += price;
                    
                    Biz_Save(bizid);

                    Inventory_Add(playerid, "Pilox", 365);
                    ShowItemBox(playerid, "Cash", sprintf("Removed $%sx", FormatMoney(price)), 1212, 4);
                    ShowItemBox(playerid, "Pilox", "Received 1x", 365, 5);

                    ShowTDN(playerid, NOTIFICATION_SUCCESS, "Transaksi berhasil dilakukan.");
                }
            }
        }
    }
    return 1;
}

Dialog:BizMenu(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    
    new bizid = AccountData[playerid][pInBiz];
    if(bizid != -1)
    {
        if(BizData[bizid][bizType] == 1)
        {
            if(listitem < 0 || listitem > 13) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda belum memilih sesuatu!");

            switch(listitem)
            {
                case 0:
                {
                    Dialog_Show(playerid, "BizMenuName", DIALOG_STYLE_INPUT, ""ARIVENA"Arivena Theater "WHITE"- Nama Biz", "Mohon masukkan nama untuk biz milikmu:", 
                    "Set", "Batal");
                }
                case 1:
                {
                    Dialog_Show(playerid, "BizMenuProfit", DIALOG_STYLE_INPUT, ""ARIVENA"Arivena Theater "WHITE"- Profit Biz", "Mohon masukkan berapa jumlah yang ingin ditarik:", "Tarik", "Batal");
                }
                case 2:
                {
                    Dialog_Show(playerid, "BizMenuEnterance", DIALOG_STYLE_INPUT, ""ARIVENA"Arivena Theater "WHITE"- Biaya Masuk", "Mohon masukkan berapa biaya masuk ke biz milikmu:", "Set", "Batal");
                }
                case 3:
                {
                    AccountData[playerid][pTempValue] = 0;
                    Dialog_Show(playerid, "BizMenuProduct", DIALOG_STYLE_INPUT, ""ARIVENA"Arivena Theater "WHITE"- Harga Produk", "Mohon masukkan berapa harga produk tersebut:", "Set", "Batal");
                }
                case 4:
                {
                    AccountData[playerid][pTempValue] = 1;
                    Dialog_Show(playerid, "BizMenuProduct", DIALOG_STYLE_INPUT, ""ARIVENA"Arivena Theater "WHITE"- Harga Produk", "Mohon masukkan berapa harga produk tersebut:", "Set", "Batal");
                }
                case 5:
                {
                    AccountData[playerid][pTempValue] = 2;
                    Dialog_Show(playerid, "BizMenuProduct", DIALOG_STYLE_INPUT, ""ARIVENA"Arivena Theater "WHITE"- Harga Produk", "Mohon masukkan berapa harga produk tersebut:", "Set", "Batal");
                }
                case 6:
                {
                    AccountData[playerid][pTempValue] = 3;
                    Dialog_Show(playerid, "BizMenuProduct", DIALOG_STYLE_INPUT, ""ARIVENA"Arivena Theater "WHITE"- Harga Produk", "Mohon masukkan berapa harga produk tersebut:", "Set", "Batal");
                }
                case 7:
                {
                    AccountData[playerid][pTempValue] = 4;
                    Dialog_Show(playerid, "BizMenuProduct", DIALOG_STYLE_INPUT, ""ARIVENA"Arivena Theater "WHITE"- Harga Produk", "Mohon masukkan berapa harga produk tersebut:", "Set", "Batal");
                }
                case 8:
                {
                    AccountData[playerid][pTempValue] = 5;
                    Dialog_Show(playerid, "BizMenuProduct", DIALOG_STYLE_INPUT, ""ARIVENA"Arivena Theater "WHITE"- Harga Produk", "Mohon masukkan berapa harga produk tersebut:", "Set", "Batal");
                }
                case 9:
                {
                    AccountData[playerid][pTempValue] = 6;
                    Dialog_Show(playerid, "BizMenuProduct", DIALOG_STYLE_INPUT, ""ARIVENA"Arivena Theater "WHITE"- Harga Produk", "Mohon masukkan berapa harga produk tersebut:", "Set", "Batal");
                }
                case 10:
                {
                    AccountData[playerid][pTempValue] = 7;
                    Dialog_Show(playerid, "BizMenuProduct", DIALOG_STYLE_INPUT, ""ARIVENA"Arivena Theater "WHITE"- Harga Produk", "Mohon masukkan berapa harga produk tersebut:", "Set", "Batal");
                }
                case 11:
                {
                    AccountData[playerid][pTempValue] = 8;
                    Dialog_Show(playerid, "BizMenuProduct", DIALOG_STYLE_INPUT, ""ARIVENA"Arivena Theater "WHITE"- Harga Produk", "Mohon masukkan berapa harga produk tersebut:", "Set", "Batal");
                }
                case 12:
                {
                    AccountData[playerid][pTempValue] = 9;
                    Dialog_Show(playerid, "BizMenuProduct", DIALOG_STYLE_INPUT, ""ARIVENA"Arivena Theater "WHITE"- Harga Produk", "Mohon masukkan berapa harga produk tersebut:", "Set", "Batal");
                }
                case 13:
                {
                    if(BizData[bizid][bizLocked])
                    {
                        BizData[bizid][bizLocked] = false;
                        ShowTDN(playerid, NOTIFICATION_INFO, "Anda telah ~g~membuka ~w~bisnis ini.");
                    }
                    else
                    {
                        BizData[bizid][bizLocked] = true;
                        ShowTDN(playerid, NOTIFICATION_INFO, "Anda telah ~r~menutup ~w~bisnis ini.");
                    }

                    Biz_Save(bizid);
                    Biz_Refresh(bizid);
                }
            }
        }
        
        if(BizData[bizid][bizType] == 2)
        {
            if(listitem < 0 || listitem > 10) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda belum memilih sesuatu!");

            switch(listitem)
            {
                case 0:
                {
                    Dialog_Show(playerid, "BizMenuName", DIALOG_STYLE_INPUT, ""ARIVENA"Arivena Theater "WHITE"- Nama Biz", "Mohon masukkan nama untuk biz milikmu:", 
                    "Set", "Batal");
                }
                case 1:
                {
                    Dialog_Show(playerid, "BizMenuProfit", DIALOG_STYLE_INPUT, ""ARIVENA"Arivena Theater "WHITE"- Profit Biz", "Mohon masukkan berapa jumlah yang ingin ditarik:", "Tarik", "Batal");
                }
                case 2:
                {
                    Dialog_Show(playerid, "BizMenuEnterance", DIALOG_STYLE_INPUT, ""ARIVENA"Arivena Theater "WHITE"- Biaya Masuk", "Mohon masukkan berapa biaya masuk ke biz milikmu:", "Set", "Batal");
                }
                case 3:
                {
                    AccountData[playerid][pTempValue] = 0;
                    Dialog_Show(playerid, "BizMenuProduct", DIALOG_STYLE_INPUT, ""ARIVENA"Arivena Theater "WHITE"- Harga Produk", "Mohon masukkan berapa harga produk tersebut:", "Set", "Batal");
                }
                case 4:
                {
                    AccountData[playerid][pTempValue] = 1;
                    Dialog_Show(playerid, "BizMenuProduct", DIALOG_STYLE_INPUT, ""ARIVENA"Arivena Theater "WHITE"- Harga Produk", "Mohon masukkan berapa harga produk tersebut:", "Set", "Batal");
                }
                case 5:
                {
                    AccountData[playerid][pTempValue] = 2;
                    Dialog_Show(playerid, "BizMenuProduct", DIALOG_STYLE_INPUT, ""ARIVENA"Arivena Theater "WHITE"- Harga Produk", "Mohon masukkan berapa harga produk tersebut:", "Set", "Batal");
                }
                case 6:
                {
                    AccountData[playerid][pTempValue] = 3;
                    Dialog_Show(playerid, "BizMenuProduct", DIALOG_STYLE_INPUT, ""ARIVENA"Arivena Theater "WHITE"- Harga Produk", "Mohon masukkan berapa harga produk tersebut:", "Set", "Batal");
                }
                case 7:
                {
                    AccountData[playerid][pTempValue] = 4;
                    Dialog_Show(playerid, "BizMenuProduct", DIALOG_STYLE_INPUT, ""ARIVENA"Arivena Theater "WHITE"- Harga Produk", "Mohon masukkan berapa harga produk tersebut:", "Set", "Batal");
                }
                case 8:
                {
                    if(BizData[bizid][bizLocked])
                    {
                        BizData[bizid][bizLocked] = false;
                        ShowTDN(playerid, NOTIFICATION_INFO, "Anda telah ~g~membuka ~w~bisnis ini.");
                    }
                    else
                    {
                        BizData[bizid][bizLocked] = true;
                        ShowTDN(playerid, NOTIFICATION_INFO, "Anda telah ~r~menutup ~w~bisnis ini.");
                    }

                    Biz_Save(bizid);
                    Biz_Refresh(bizid);
                }
            }
        }
    }
    return 1;
}

Dialog:BizMenuName(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    new bizid = AccountData[playerid][pInBiz];
    if(bizid != -1)
    {
        if(isnull(inputtext)) return ShowTDN(playerid, NOTIFICATION_ERROR, "Tidak dapat dibiarkan kosong!");
        if(strlen(inputtext) < 5 || strlen(inputtext) > 25) return ShowTDN(playerid, NOTIFICATION_ERROR, "Nama biz diantara 5 - 25 char!");
        if(strfind(inputtext, "%", true) != -1 || strfind(inputtext, "#", true) != -1)  return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda tidak dapat menggunakan simbol persen!");
        
        strcopy(BizData[bizid][bizName], inputtext);
        ShowTDN(playerid, NOTIFICATION_SUCCESS, "Anda berhasil mengganti nama biz!");

        Biz_Save(bizid);
        Biz_Refresh(bizid);
    }
    return 1;
}

Dialog:BizMenuProfit(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    new bizid = AccountData[playerid][pInBiz];
    if(bizid != -1)
    {
        if(isnull(inputtext)) return ShowTDN(playerid, NOTIFICATION_ERROR, "Tidak dapat dibiarkan kosong!");
        if(!IsNumericEx(inputtext)) return ShowTDN(playerid, NOTIFICATION_ERROR, "Hanya dapat diisi oleh angka!");
        if(strval(inputtext) < 1 || strval(inputtext) > BizData[bizid][bizMoney]) return ShowTDN(playerid, NOTIFICATION_ERROR, "Jumlah tidak valid!");

        BizData[bizid][bizMoney] -= strval(inputtext);
        GivePlayerMoneyEx(playerid, strval(inputtext));

        ShowTDN(playerid, NOTIFICATION_INFO, sprintf("Anda mengambil $%s dari bisnis ini!", FormatMoney(strval(inputtext))));

        Biz_Save(bizid);
        Biz_Refresh(bizid);
    }
    return 1;
}

Dialog:BizMenuEnterance(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    new bizid = AccountData[playerid][pInBiz];
    if(bizid != -1)
    {
        if(isnull(inputtext)) return ShowTDN(playerid, NOTIFICATION_ERROR, "Tidak dapat dibiarkan kosong!");
        if(!IsNumericEx(inputtext)) return ShowTDN(playerid, NOTIFICATION_ERROR, "Hanya dapat diisi oleh angka!");
        
        if(strval(inputtext) < 0) return ShowTDN(playerid, NOTIFICATION_ERROR, "Biaya tidak valid!");
        if(strval(inputtext) > 50) return ShowTDN(playerid, NOTIFICATION_ERROR, "Tidak dapat di atas $50!");

        BizData[bizid][bizEnteranceFee] = strval(inputtext);

        ShowTDN(playerid, NOTIFICATION_SUCCESS, "Anda berhasil mengganti biaya masuk bisnis ini!");

        Biz_Save(bizid);
        Biz_Refresh(bizid);
    }
    return 1;
}

Dialog:BizMenuProduct(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    new bizid = AccountData[playerid][pInBiz];
    if(bizid != -1)
    {
        if(isnull(inputtext)) return ShowTDN(playerid, NOTIFICATION_ERROR, "Tidak dapat dibiarkan kosong!");
        if(!IsNumericEx(inputtext)) return ShowTDN(playerid, NOTIFICATION_ERROR, "Hanya dapat diisi oleh angka!");
        if(AccountData[playerid][pTempValue] < 0) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda belum memilih apapun!");

        if(strval(inputtext) < 20) return ShowTDN(playerid, NOTIFICATION_ERROR, "Harga minimal adalah $20!");
        if(strval(inputtext) > 50) return ShowTDN(playerid, NOTIFICATION_ERROR, "Harga maksimal adalah $50!");

        BizData[bizid][bizProdPrice][AccountData[playerid][pTempValue]] = strval(inputtext);

        ShowTDN(playerid, NOTIFICATION_SUCCESS, "Anda berhasil mengubah harga produk tersebut!");

        Biz_Save(bizid);
        Biz_Refresh(bizid);
    }
    return 1;
}

Dialog:BizRestock(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;

    new bizid = AccountData[playerid][pInBiz];
    if(bizid != -1)
    {
        if(BizData[bizid][bizType] == 1)
        {
            if(listitem < 0 || listitem > 9) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda belum memilih sesuatu!");

            switch(listitem)
            {
                case 0:
                {
                    AccountData[playerid][pTempValue] = 0;
                    Dialog_Show(playerid, "BizRestockConfirm", DIALOG_STYLE_INPUT, ""ARIVENA"Arivena Theater "WHITE"- Restock Product", ""WHITE"Please insert the ammount of stocks that you want to buy/nPrice: "SEAGREEN"$15.00/stock:", "Restock", "Batal");
                }
                case 1:
                {
                    AccountData[playerid][pTempValue] = 1;
                    Dialog_Show(playerid, "BizRestockConfirm", DIALOG_STYLE_INPUT, ""ARIVENA"Arivena Theater "WHITE"- Restock Product", ""WHITE"Please insert the ammount of stocks that you want to buy/nPrice: "SEAGREEN"$15.00/stock:", "Restock", "Batal");
                }
                case 2:
                {
                    AccountData[playerid][pTempValue] = 2;
                    Dialog_Show(playerid, "BizRestockConfirm", DIALOG_STYLE_INPUT, ""ARIVENA"Arivena Theater "WHITE"- Restock Product", ""WHITE"Please insert the ammount of stocks that you want to buy/nPrice: "SEAGREEN"$15.00/stock:", "Restock", "Batal");
                }
                case 3:
                {
                    AccountData[playerid][pTempValue] = 3;
                    Dialog_Show(playerid, "BizRestockConfirm", DIALOG_STYLE_INPUT, ""ARIVENA"Arivena Theater "WHITE"- Restock Product", ""WHITE"Please insert the ammount of stocks that you want to buy/nPrice: "SEAGREEN"$15.00/stock:", "Restock", "Batal");
                }
                case 4:
                {
                    AccountData[playerid][pTempValue] = 4;
                    Dialog_Show(playerid, "BizRestockConfirm", DIALOG_STYLE_INPUT, ""ARIVENA"Arivena Theater "WHITE"- Restock Product", ""WHITE"Please insert the ammount of stocks that you want to buy/nPrice: "SEAGREEN"$15.00/stock:", "Restock", "Batal");
                }
                case 5:
                {
                    AccountData[playerid][pTempValue] = 5;
                    Dialog_Show(playerid, "BizRestockConfirm", DIALOG_STYLE_INPUT, ""ARIVENA"Arivena Theater "WHITE"- Restock Product", ""WHITE"Please insert the ammount of stocks that you want to buy/nPrice: "SEAGREEN"$15.00/stock:", "Restock", "Batal");
                }
                case 6:
                {
                    AccountData[playerid][pTempValue] = 6;
                    Dialog_Show(playerid, "BizRestockConfirm", DIALOG_STYLE_INPUT, ""ARIVENA"Arivena Theater "WHITE"- Restock Product", ""WHITE"Please insert the ammount of stocks that you want to buy/nPrice: "SEAGREEN"$15.00/stock:", "Restock", "Batal");
                }
                case 7:
                {
                    AccountData[playerid][pTempValue] = 7;
                    Dialog_Show(playerid, "BizRestockConfirm", DIALOG_STYLE_INPUT, ""ARIVENA"Arivena Theater "WHITE"- Restock Product", ""WHITE"Please insert the ammount of stocks that you want to buy/nPrice: "SEAGREEN"$15.00/stock:", "Restock", "Batal");
                }
                case 8:
                {
                    AccountData[playerid][pTempValue] = 8;
                    Dialog_Show(playerid, "BizRestockConfirm", DIALOG_STYLE_INPUT, ""ARIVENA"Arivena Theater "WHITE"- Restock Product", ""WHITE"Please insert the ammount of stocks that you want to buy/nPrice: "SEAGREEN"$15.00/stock:", "Restock", "Batal");
                }
                case 9:
                {
                    AccountData[playerid][pTempValue] = 9;
                    Dialog_Show(playerid, "BizRestockConfirm", DIALOG_STYLE_INPUT, ""ARIVENA"Arivena Theater "WHITE"- Restock Product", ""WHITE"Please insert the ammount of stocks that you want to buy/nPrice: "SEAGREEN"$15.00/stock:", "Restock", "Batal");
                }
            }
        }
        if(BizData[bizid][bizType] == 2)
        {
            if(listitem < 0 || listitem > 4) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda belum memilih sesuatu!");

            switch(listitem)
            {
                case 0:
                {
                    AccountData[playerid][pTempValue] = 0;
                    Dialog_Show(playerid, "BizRestockConfirm", DIALOG_STYLE_INPUT, ""ARIVENA"Arivena Theater "WHITE"- Restock Product", ""WHITE"Please insert the ammount of stocks that you want to buy/nPrice: "SEAGREEN"$15.00/stock:", "Restock", "Batal");
                }
                case 1:
                {
                    AccountData[playerid][pTempValue] = 1;
                    Dialog_Show(playerid, "BizRestockConfirm", DIALOG_STYLE_INPUT, ""ARIVENA"Arivena Theater "WHITE"- Restock Product", ""WHITE"Please insert the ammount of stocks that you want to buy/nPrice: "SEAGREEN"$15.00/stock:", "Restock", "Batal");
                }
                case 2:
                {
                    AccountData[playerid][pTempValue] = 2;
                    Dialog_Show(playerid, "BizRestockConfirm", DIALOG_STYLE_INPUT, ""ARIVENA"Arivena Theater "WHITE"- Restock Product", ""WHITE"Please insert the ammount of stocks that you want to buy/nPrice: "SEAGREEN"$15.00/stock:", "Restock", "Batal");
                }
                case 3:
                {
                    AccountData[playerid][pTempValue] = 3;
                    Dialog_Show(playerid, "BizRestockConfirm", DIALOG_STYLE_INPUT, ""ARIVENA"Arivena Theater "WHITE"- Restock Product", ""WHITE"Please insert the ammount of stocks that you want to buy/nPrice: "SEAGREEN"$15.00/stock:", "Restock", "Batal");
                }
                case 4:
                {
                    AccountData[playerid][pTempValue] = 4;
                    Dialog_Show(playerid, "BizRestockConfirm", DIALOG_STYLE_INPUT, ""ARIVENA"Arivena Theater "WHITE"- Restock Product", ""WHITE"Please insert the ammount of stocks that you want to buy/nPrice: "SEAGREEN"$15.00/stock:", "Restock", "Batal");
                }
            }
        }
    }
    return 1;
}

Dialog:BizRestockConfirm(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    new bizid = AccountData[playerid][pInBiz];
    if(bizid != -1)
    {
        if(isnull(inputtext)) return ShowTDN(playerid, NOTIFICATION_ERROR, "Tidak dapat dibiarkan kosong!");
        if(!IsNumericEx(inputtext)) return ShowTDN(playerid, NOTIFICATION_ERROR, "Hanya dapat diisi oleh angka!");
        if(AccountData[playerid][pTempValue] < 0) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda belum memilih apapun!");
        if(strval(inputtext) < 1 || strval(inputtext) > 1000) return ShowTDN(playerid, NOTIFICATION_ERROR, "Hanya dapat restock antara 1 - 1000!");
        new totalling = BizData[bizid][bizProdStock][AccountData[playerid][pTempValue]] + strval(inputtext);
        if(totalling > 1000) return ShowTDN(playerid, NOTIFICATION_ERROR, "Maksimal stok produk adalah 1000!");

        new pricing = strval(inputtext) * 1500;
        if(AccountData[playerid][pBankMoney] < RoundNegativeToPositive(pricing)) 
            return ShowTDN(playerid, NOTIFICATION_ERROR, "Saldo rekening anda tidak cukup!");

        AccountData[playerid][pBankMoney] -= pricing;
        BizData[bizid][bizProdStock][AccountData[playerid][pTempValue]] += strval(inputtext);
        ShowTDN(playerid, NOTIFICATION_SUCCESS, "Anda berhasil mengisi ulang stock produk tersebut");

        Biz_Save(bizid);
        Biz_Refresh(bizid);
    }
    return 1;
}
