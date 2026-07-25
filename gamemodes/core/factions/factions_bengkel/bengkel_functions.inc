#include <YSI_Coding\y_hooks>

static const BennysRank[7][] =
{
    "N/A",
    "PKL",              // 1
    "Amatir",           // 2
    "Ahli",             // 3
    "Wakil Manager",    // 4
    "Manager",          // 5
    "Boss Bennys"       // 6
};

new const pv_spoiler[]     = {1000,1001,1002,1003,1014,1015,1016,1023,1058,1060,1049,1050,1138,1139,1146,1147,1158,1162,1163,1164};
new const pv_nitro[]       = {1008,1009,1010};
new const pv_fbumper[]     = {1117,1152,1153,1155,1157,1160,1165,1166,1169,1170,1171,1172,1173,1174,1175,1179,1181,1182,1185,1188,1189,1190,1191};
new const pv_rbumper[]     = {1140,1141,1148,1149,1150,1151,1154,1156,1159,1161,1167,1168,1176,1177,1178,1180,1183,1184,1186,1187,1192,1193};
new const pv_exhaust[]     = {1018,1019,1020,1021,1022,1028,1029,1037,1043,1044,1045,1046,1059,1064,1065,1066,1089,1092,1104,1105,1113,1114,1126,1127,1129,1132,1135,1136};
new const pv_bventr[]      = {1142,1144};
new const pv_bventl[]      = {1143,1145};
new const pv_bscoop[]      = {1004,1005,1011,1012};
new const pv_roof[]        = {1006,1032,1033,1035,1038,1053,1054,1055,1061,1067,1068,1088,1091,1103,1128,1130,1131};
new const pv_lskirt[]      = {1007,1026,1031,1036,1039,1042,1047,1048,1056,1057,1069,1070,1090,1093,1106,1108,1118,1119,1133,1122,1134};
new const pv_rskirt[]      = {1017,1027,1030,1040,1041,1051,1052,1062,1063,1071,1072,1094,1095,1099,1101,1102,1107,1120,1121,1124,1137};
new const pv_hydraulics[]  = {1087};
new const pv_base[]        = {1086};
new const pv_rbbars[]      = {1109,1110,1123,1125};
new const pv_fbbars[]      = {1115,1116};
new const pv_wheels[]      = {1025,1073,1074,1075,1076,1077,1078,1079,1080,1081,1082,1083,1084,1085,1096,1097,1098};
new const pv_lights[]      = {1013,1024};

stock bool:IsComponentInArray(componentid, const arr[], size)
{
    for(new i = 0; i < size; i++)
    {
        if(arr[i] == componentid) return true;
    }
    return false;
}

CountEngineCompoCost(pvid)
{
    new Float:compocost;
    if(Iter_Contains(Vehicle, PlayerVehicle[pvid][pVehPhysic]))
    {
        if(PlayerVehicle[pvid][pVehMaxHealth] == 1000.00)
        {
            compocost = (PlayerVehicle[pvid][pVehMaxHealth] - PlayerVehicle[pvid][pVehHealth]) / 5;
        }
        else if(PlayerVehicle[pvid][pVehMaxHealth] == 1500.00)
        {
            compocost = (PlayerVehicle[pvid][pVehMaxHealth] - PlayerVehicle[pvid][pVehHealth]) / 7;
        }
        else if(PlayerVehicle[pvid][pVehMaxHealth] == 2000.00)
        {
            compocost = (PlayerVehicle[pvid][pVehMaxHealth] - PlayerVehicle[pvid][pVehHealth]) / 10;
        }
    }
    return floatround(compocost);
}

CountBodyCompoCost(pvid)
{
    new compo = 0;
    new panels, doors, lights, tires;

    if(Iter_Contains(Vehicle, PlayerVehicle[pvid][pVehPhysic]))
    {
        GetVehicleDamageStatus(PlayerVehicle[pvid][pVehPhysic], panels, doors, lights, tires);

        new
            spoiler = GetVehicleComponentInSlot(PlayerVehicle[pvid][pVehPhysic], CARMODTYPE_SPOILER),
            hood    = GetVehicleComponentInSlot(PlayerVehicle[pvid][pVehPhysic], CARMODTYPE_HOOD),
            roof    = GetVehicleComponentInSlot(PlayerVehicle[pvid][pVehPhysic], CARMODTYPE_ROOF),
            lamps   = GetVehicleComponentInSlot(PlayerVehicle[pvid][pVehPhysic], CARMODTYPE_LAMPS),
            exhaust = GetVehicleComponentInSlot(PlayerVehicle[pvid][pVehPhysic], CARMODTYPE_EXHAUST),
            fbumper = GetVehicleComponentInSlot(PlayerVehicle[pvid][pVehPhysic], CARMODTYPE_FRONT_BUMPER),
            rbumper = GetVehicleComponentInSlot(PlayerVehicle[pvid][pVehPhysic], CARMODTYPE_REAR_BUMPER),
            rvent   = GetVehicleComponentInSlot(PlayerVehicle[pvid][pVehPhysic], CARMODTYPE_VENT_RIGHT),
            lvent   = GetVehicleComponentInSlot(PlayerVehicle[pvid][pVehPhysic], CARMODTYPE_VENT_LEFT);

        if(panels > 0)
        {
            compo += 25;
            if(spoiler >= 1000) compo += 5;
            if(hood    >= 1000) compo += 5;
            if(roof    >= 1000) compo += 5;
            if(exhaust >= 1000) compo += 5; // total 45
        }
        if(doors > 0)
        {
            compo += 25;
            if(rvent >= 1000) compo += 5;
            if(lvent >= 1000) compo += 5; // total 35
        }
        if(lights > 0)
        {
            compo += 25;
            if(lamps   >= 1000) compo += 5;
            if(fbumper >= 1000) compo += 5;
            if(rbumper >= 1000) compo += 5; // total 40
        }
    }
    return compo;
}

CountTiresCompoCost(pvid)
{
    new compo = 0;
    new panels, doors, lights, tires;

    if(Iter_Contains(Vehicle, PlayerVehicle[pvid][pVehPhysic]))
    {
        GetVehicleDamageStatus(PlayerVehicle[pvid][pVehPhysic], panels, doors, lights, tires);

        new wheel = GetVehicleComponentInSlot(PlayerVehicle[pvid][pVehPhysic], CARMODTYPE_WHEELS);
        if(tires > 0)
        {
            compo = 20;
            if(wheel >= 1000) compo += 10;
        }
    }
    return compo;
}

CountUpgradeEngineCompo(pvid)
{
    new compocost = 0;
    if(Iter_Contains(Vehicle, PlayerVehicle[pvid][pVehPhysic]))
    {
        if(PlayerVehicle[pvid][pVehMaxHealth] == 1000.00)       compocost = 200; // level 1
        else if(PlayerVehicle[pvid][pVehMaxHealth] == 1500.00)  compocost = 250; // level 2
        else                                                    compocost = 0;
    }
    return compocost;
}

Bennys_ShowBrankas(playerid)
{
    new
        curr_page = index_pagination[playerid],
        count = 0,
        string[1012],
        real_i = 0,
        fbrankas_exists[MAX_PAGINATION_PAGES],
        fbrankas_temp[MAX_PAGINATION_PAGES][32],
        fbrankas_model[MAX_PAGINATION_PAGES],
        fbrankas_quant[MAX_PAGINATION_PAGES],
        fbrankas_id[MAX_PAGINATION_PAGES],
        fbrankas_fid[MAX_PAGINATION_PAGES],
        curr_idx = MAX_PAGINATION_PAGES * curr_page;

    for(new i = 0; i < MAX_PAGINATION_PAGES; i++)
    {
        fbrankas_exists[i] = false;
    }

    strcat(string, "Nama Item\tJumlah\n");
    for(new i = 0; i < MAX_FACTIONS_ITEMS; i++)
    {
        if(!FactionBrankas[i][factionBrankasExists] || FactionBrankas[i][factionBrankasFID] != FACTION_BENNYS) continue;

        if(real_i >= curr_idx && real_i < curr_idx + MAX_PAGINATION_PAGES)
        {
            new slot = real_i - curr_idx;
            fbrankas_exists[slot] = true;
            fbrankas_id[slot] = i;
            fbrankas_fid[slot] = FactionBrankas[i][factionBrankasFID];
            fbrankas_model[slot] = FactionBrankas[i][factionBrankasModel];
            strcopy(fbrankas_temp[slot], FactionBrankas[i][factionBrankasTemp], 32);
            fbrankas_quant[slot] = FactionBrankas[i][factionBrankasQuant];
        }
        real_i++;
    }

    for(new i = 0; i < MAX_PAGINATION_PAGES; i++)
    {
        if(!fbrankas_exists[i]) continue;

        strcat(string, sprintf("%s%s\t%s%d\n", (i % 2 == 0) ? (""WHITE"") : (""GRAY""), fbrankas_temp[i], (i % 2 == 0) ? (""WHITE"") : (""GRAY""), fbrankas_quant[i]));
        PlayerListitem[playerid][count++] = fbrankas_id[i];
    }

    if(count == 0)
    {
        Dialog_Show(playerid, "UnusedDialog", DIALOG_STYLE_MSGBOX, "Lemari Bennys", "Lemari penyimpanan ini kosong!", "Tutup", "");
    }
    else
    {
        new max_pages = (real_i + MAX_PAGINATION_PAGES - 1) / MAX_PAGINATION_PAGES;

        if(curr_page > 0) strcat(string, ""RED"<< Sebelumnya\n");
        if(curr_page < max_pages - 1) strcat(string, ""GREEN">> Selanjutnya\n");

        Dialog_Show(playerid, "BennysVaultWithdraw", DIALOG_STYLE_TABLIST_HEADERS, sprintf("Lemari Bennys: Page %d of %d", curr_page + 1, max_pages), string, "Pilih", "Batal");
    }
    return 1;
}

stock BuildFactionMemberList(playerid, const dialogname[], const title[])
{
    new
        string[1012],
        member_name[MAX_MEMBER_ROWS][64],
        member_pID[MAX_MEMBER_ROWS],
        member_rank[MAX_MEMBER_ROWS],
        member_lastlog[MAX_MEMBER_ROWS][30],
        curr_page = index_pagination[playerid],
        curr_index = curr_page * MAX_MEMBER_ROWS,
        count = 0,
        real_i = 0;

    mysql_query(g_SQL, "SELECT * FROM player_characters WHERE Char_Faction = 5 ORDER BY Char_FactionRank DESC");
    new rows = cache_num_rows();

    if(!rows)
    {
        PlayerPlaySound(playerid, 5206, 0.0, 0.0, 0.0);
        Dialog_Show(playerid, "UnusedDialog", DIALOG_STYLE_MSGBOX, title, "Faction ini tidak memiliki anggota!", "Tutup", "");
        return 0;
    }

    for(new i = curr_index; i < rows && real_i < MAX_MEMBER_ROWS; i++)
    {
        cache_get_value_name(i, "Char_Name", member_name[real_i]);
        cache_get_value_name_int(i, "Char_FactionRank", member_rank[real_i]);
        cache_get_value_name(i, "Char_LastLogin", member_lastlog[real_i]);
        cache_get_value_name_int(i, "pID", member_pID[real_i]);
        real_i++;
    }

    strcat(string, "Nama\tRank\tLast Online\n");
    for(new i = 0; i < real_i; i++)
    {
        strcat(string, sprintf("%s\t%s\t%s\n", member_name[i], BennysRank[member_rank[i]], member_lastlog[i]));
        ListedMember[playerid][count++] = member_pID[i];
    }

    new max_page = ((rows + MAX_MEMBER_ROWS - 1) / MAX_MEMBER_ROWS) - 1;
    TempRows[playerid] = rows;

    if(curr_page > 0) strcat(string, ""RED"<< Sebelumnya\n");
    if(curr_page < max_page) strcat(string, ""GREEN">> Selanjutnya\n");

    Dialog_Show(playerid, dialogname, DIALOG_STYLE_TABLIST_HEADERS, title, string, "Pilih", "Batal");
    return 1;
}

stock ShowBennysKick(playerid)
{
    return BuildFactionMemberList(playerid, "BennysKickMember", ""ARIVENA"Arivena Theater "WHITE"- Kick Faction");
}

Show_BennysRankManage(playerid)
{
    return BuildFactionMemberList(playerid, "BennysSetRankPage", ""ARIVENA"Arivena Theater "WHITE"- Manage Rank");
}

stock BuildNearbyPlayerList(playerid, Float:range, outstr[], size, &count)
{
    count = 0;
    outstr[0] = EOS;

    foreach(new i : Player)
    {
        if(i == playerid) continue;
        if(!IsPlayerNearPlayer(playerid, i, range)) continue;

        format(outstr, size, "%s%sPlayer ID - (%d)\n", outstr, (count % 2 == 0) ? (""WHITE"") : (""GRAY""), i);
        NearestUser[playerid][count++] = i;
    }
    return count;
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
    if(newkeys & KEY_CTRL_BACK && AccountData[playerid][pFaction] == FACTION_BENNYS && GetPlayerState(playerid) == PLAYER_STATE_ONFOOT)
    {
        if(AccountData[playerid][pInEvent]) return 1;

        new count, frmxt[522];
        BuildNearbyPlayerList(playerid, 2.5, frmxt, sizeof(frmxt), count);

        if(count > 0)
        {
            Dialog_Show(playerid, "FactionPanel", DIALOG_STYLE_LIST, ""ARIVENA"Arivena Theater "WHITE"- Faction Panel", frmxt, "Pilih", "Batal");
        }
    }
    return 1;
}

Dialog:BennysVault(playerid, response, listitem, inputtext[])
{
    if(!response)
    {
        AccountData[playerid][pMenuShowed] = false;
        return 1;
    }

    switch(listitem)
    {
        case 0: // deposit
        {
            new str[1218], count;
            format(str, sizeof(str), "Nama Item\tJumlah\n");
            for(new index; index < MAX_INVENTORY; index++)
            {
                if(!InventoryData[playerid][index][invExists]) continue;

                for(new i; i < sizeof(g_aInventoryItems); i++)
                {
                    if(!strcmp(g_aInventoryItems[i][e_InventoryItem], InventoryData[playerid][index][invItem], true))
                    {
                        format(str, sizeof(str), "%s%s\t%d\n", str, InventoryData[playerid][index][invItem], InventoryData[playerid][index][invQuantity]);
                        PlayerListitem[playerid][count++] = index;
                    }
                }
            }

            if(count == 0)
            {
                Dialog_Show(playerid, "UnusedDialog", DIALOG_STYLE_MSGBOX, ""ARIVENA"Arivena Theater "WHITE"- Lemari Bennys",
                "Anda tidak memiliki barang yang dapat disimpan!", "Tutup", "");
            }
            else
            {
                Dialog_Show(playerid, "BennysVaultDeposit", DIALOG_STYLE_TABLIST_HEADERS, ""ARIVENA"Arivena Theater "WHITE"- Lemari Bennys", str, "Pilih", "Batal");
            }
        }
        case 1: // withdraw
        {
            index_pagination[playerid] = 0;
            Bennys_ShowBrankas(playerid);
        }
    }
    return 1;
}

Dialog:BennysVaultDeposit(playerid, response, listitem, inputtext[])
{
    if(!response)
    {
        AccountData[playerid][pMenuShowed] = false;
        return 1;
    }

    if(listitem == -1)
    {
        AccountData[playerid][pMenuShowed] = false;
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda belum memilih item apapun!");
    }

    AccountData[playerid][pTempValue] = listitem;

    if(!strcmp(InventoryData[playerid][PlayerListitem[playerid][listitem]][invItem], "Changename Card"))
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda tidak dapat menyimpan Changename Card ke penyimpanan manapun!");

    if(!strcmp(InventoryData[playerid][PlayerListitem[playerid][listitem]][invItem], "Hunt Ammo"))
    {
        if(IsPlayerHunting[playerid])
        {
            ResetWeapon(playerid, 34);
            if(PlayerHasItem(playerid, "Hunt Ammo"))
            {
                GivePlayerWeaponEx(playerid, 34, Inventory_Count(playerid, "Hunt Ammo"), WEAPON_TYPE_PLAYER);
            }
        }
    }

    new shstr[528];
    format(shstr, sizeof(shstr), ""WHITE"Anda akan menyimpan item:\nNama: "CYAN"%s\n"WHITE"Jumlah di tas: "YELLOW"%d\n"WHITE"Mohon masukkan jumlah yang ingin disimpan:",
        InventoryData[playerid][PlayerListitem[playerid][listitem]][invItem], InventoryData[playerid][PlayerListitem[playerid][listitem]][invQuantity]);
    Dialog_Show(playerid, "BennysVaultIn", DIALOG_STYLE_INPUT, ""ARIVENA"Arivena Theater "WHITE"- Lemari Bennys", shstr, "Input", "Batal");
    return 1;
}

Dialog:BennysVaultIn(playerid, response, listitem, inputtext[])
{
    if(!response)
    {
        AccountData[playerid][pMenuShowed] = false;
        return 1;
    }

    new id = AccountData[playerid][pTempValue];
    if(id == -1)
    {
        AccountData[playerid][pMenuShowed] = false;
        ShowTDN(playerid, NOTIFICATION_ERROR, "Anda belum memilih item apapun!");
        return 1;
    }

    new invItemName[32], invItemQty = InventoryData[playerid][PlayerListitem[playerid][id]][invQuantity];
    strcopy(invItemName, InventoryData[playerid][PlayerListitem[playerid][id]][invItem], 32);

    new shstr[512];
    if(isnull(inputtext))
    {
        AccountData[playerid][pMenuShowed] = true;
        format(shstr, sizeof(shstr), "Anda akan menyimpan item:\nNama: %s\nJumlah di tas: %d\nTidak dapat dikosongkan!\nMohon masukkan berapa jumlah yang ingin disimpan:", invItemName, invItemQty);
        Dialog_Show(playerid, "BennysVaultIn", DIALOG_STYLE_INPUT, ""ARIVENA"Arivena Theater "WHITE"- Lemari Bennys", shstr, "Input", "Batal");
        return 1;
    }

    if(!IsNumericEx(inputtext))
    {
        AccountData[playerid][pMenuShowed] = true;
        format(shstr, sizeof(shstr), "Anda akan menyimpan item:\nNama: %s\nJumlah di tas: %d\nMohon diisi hanya angka!\nMohon masukkan berapa jumlah yang ingin disimpan:", invItemName, invItemQty);
        Dialog_Show(playerid, "BennysVaultIn", DIALOG_STYLE_INPUT, ""ARIVENA"Arivena Theater "WHITE"- Lemari Bennys", shstr, "Input", "Batal");
        return 1;
    }

    new quantity = strval(inputtext);
    if(quantity < 1 || quantity > invItemQty)
    {
        AccountData[playerid][pMenuShowed] = true;
        format(shstr, sizeof(shstr), "Anda akan menyimpan item:\nNama: %s\nJumlah di tas: %d\nJumlah tidak valid!\nMohon masukkan berapa jumlah yang ingin disimpan:", invItemName, invItemQty);
        Dialog_Show(playerid, "BennysVaultIn", DIALOG_STYLE_INPUT, ""ARIVENA"Arivena Theater "WHITE"- Lemari Bennys", shstr, "Input", "Batal");
        return 1;
    }

    new invstr[1028];
    mysql_format(g_SQL, shstr, sizeof(shstr), "SELECT * FROM `faction_brankas` WHERE `FID` = %d AND `Item` = '%e'", FACTION_BENNYS, invItemName);
    mysql_query(g_SQL, shstr);

    new rows = cache_num_rows();
    if(rows > 0)
    {
        mysql_format(g_SQL, invstr, sizeof(invstr), "UPDATE `faction_brankas` SET `Quantity` = `Quantity` + %d WHERE `FID` = %d AND `Item` = '%e'", quantity, FACTION_BENNYS, invItemName);
        mysql_pquery(g_SQL, invstr);

        ShowTDN(playerid, NOTIFICATION_SUCCESS, "Anda berhasil menyimpan item tersebut.");

        for(new x; x < MAX_FACTIONS_ITEMS; x++)
        {
            if(FactionBrankas[x][factionBrankasExists] && FactionBrankas[x][factionBrankasFID] == FACTION_BENNYS && !strcmp(FactionBrankas[x][factionBrankasTemp], invItemName, true))
            {
                FactionBrankas[x][factionBrankasQuant] += quantity;
            }
        }
    }
    else
    {
        for(new x; x < MAX_FACTIONS_ITEMS; x++)
        {
            if(FactionBrankas[x][factionBrankasExists]) continue;

            FactionBrankas[x][factionBrankasExists] = true;
            FactionBrankas[x][factionBrankasFID] = FACTION_BENNYS;
            strcopy(FactionBrankas[x][factionBrankasTemp], invItemName);
            FactionBrankas[x][factionBrankasModel] = InventoryData[playerid][PlayerListitem[playerid][id]][invModel];
            FactionBrankas[x][factionBrankasQuant] = quantity;

            mysql_format(g_SQL, invstr, sizeof(invstr), "INSERT INTO `faction_brankas` SET `FID` = %d, `Item`='%e', `Model`=%d, `Quantity`=%d",
                FACTION_BENNYS, invItemName, InventoryData[playerid][PlayerListitem[playerid][id]][invModel], quantity);
            mysql_pquery(g_SQL, invstr, "OnFactionDeposit", "id", playerid, x);
            break;
        }
    }
    ShowItemBox(playerid, invItemName, sprintf("Removed %dx", quantity), InventoryData[playerid][PlayerListitem[playerid][id]][invModel], 5);
    Inventory_Remove(playerid, invItemName, quantity);
    return 1;
}

Dialog:BennysVaultWithdraw(playerid, response, listitem, inputtext[])
{
    if(!response)
    {
        AccountData[playerid][pMenuShowed] = false;
        return 1;
    }

    if(listitem == -1)
    {
        AccountData[playerid][pMenuShowed] = false;
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda belum memilih item apapun!");
    }

    if(!strcmp(inputtext, ">> Selanjutnya", true))
    {
        index_pagination[playerid]++;

        new max_contact_page = MAX_FACTIONS_ITEMS / MAX_PAGINATION_PAGES;
        if(index_pagination[playerid] >= max_contact_page) index_pagination[playerid] = max_contact_page;

        Bennys_ShowBrankas(playerid);
    }
    else if(!strcmp(inputtext, "<< Sebelumnya", true))
    {
        index_pagination[playerid]--;
        if(index_pagination[playerid] <= 0) index_pagination[playerid] = 0;

        Bennys_ShowBrankas(playerid);
    }
    else
    {
        if(PlayerListitem[playerid][listitem] == -1)
        {
            AccountData[playerid][pMenuShowed] = false;
            return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda belum memilih item apapun!");
        }

        AccountData[playerid][pTempValue] = listitem;
        new shstr[528];
        format(shstr, sizeof(shstr), ""WHITE"Anda akan mengambil item:\nNama: "CYAN"%s\n"WHITE"Jumlah tersimpan: "YELLOW"%d\n"WHITE"Mohon masukkan berapa jumlah yang ingin diambil:",
            FactionBrankas[PlayerListitem[playerid][listitem]][factionBrankasTemp], FactionBrankas[PlayerListitem[playerid][listitem]][factionBrankasQuant]);
        Dialog_Show(playerid, "BennysVaultOut", DIALOG_STYLE_INPUT, ""ARIVENA"Arivena Theater "WHITE"- Lemari Bennys", shstr, "Input", "Batal");
    }
    return 1;
}

Dialog:BennysVaultOut(playerid, response, listitem, inputtext[])
{
    if(!response)
    {
        AccountData[playerid][pMenuShowed] = false;
        return 1;
    }

    new id = AccountData[playerid][pTempValue];
    if(id == -1)
    {
        AccountData[playerid][pMenuShowed] = false;
        ShowTDN(playerid, NOTIFICATION_ERROR, "Anda belum memilih item apapun!");
        return 1;
    }

    new slot = PlayerListitem[playerid][id];
    new vaultItemName[32], vaultItemQty = FactionBrankas[slot][factionBrankasQuant];
    strcopy(vaultItemName, FactionBrankas[slot][factionBrankasTemp], 32);

    new shstr[512];
    if(isnull(inputtext))
    {
        AccountData[playerid][pMenuShowed] = true;
        format(shstr, sizeof(shstr), ""WHITE"Anda akan mengambil item:\nNama: "CYAN"%s\n"WHITE"Jumlah tersimpan: "YELLOW"%d\n"WHITE"Tidak dapat dikosongkan!\nMohon masukkan berapa jumlah yang ingin diambil:", vaultItemName, vaultItemQty);
        Dialog_Show(playerid, "BennysVaultOut", DIALOG_STYLE_INPUT, ""ARIVENA"Arivena Theater "WHITE"- Lemari Bennys", shstr, "Input", "Batal");
        return 1;
    }

    if(!IsNumericEx(inputtext))
    {
        AccountData[playerid][pMenuShowed] = true;
        format(shstr, sizeof(shstr), ""WHITE"Anda akan mengambil item:\nNama: "CYAN"%s\n"WHITE"Jumlah tersimpan: "YELLOW"%d\n"WHITE"Mohon diisi hanya angka!\nMohon masukkan berapa jumlah yang ingin diambil:", vaultItemName, vaultItemQty);
        Dialog_Show(playerid, "BennysVaultOut", DIALOG_STYLE_INPUT, ""ARIVENA"Arivena Theater "WHITE"- Lemari Bennys", shstr, "Input", "Batal");
        return 1;
    }

    new quantity = strval(inputtext);
    if(quantity < 1 || quantity > vaultItemQty)
    {
        AccountData[playerid][pMenuShowed] = true;
        format(shstr, sizeof(shstr), ""WHITE"Anda akan mengambil item:\nNama: "CYAN"%s\n"WHITE"Jumlah tersimpan: "YELLOW"%d\n"WHITE"Jumlah tidak valid!\nMohon masukkan berapa jumlah yang ingin diambil:", vaultItemName, vaultItemQty);
        Dialog_Show(playerid, "BennysVaultOut", DIALOG_STYLE_INPUT, ""ARIVENA"Arivena Theater "WHITE"- Lemari Bennys", shstr, "Input", "Batal");
        return 1;
    }

    new jts[150];
    new Float:countingtotalweight = GetTotalWeightFloat(playerid) + float(quantity * GetItemWeight(vaultItemName)) / 1000;
    if(countingtotalweight > GetPlayerInventoryWeight(playerid)) return ShowTDN(playerid, NOTIFICATION_ERROR, "Inventory anda sudah penuh!");

    if(!strcmp(vaultItemName, "Smartphone"))
    {
        mysql_format(g_SQL, jts, sizeof(jts), "SELECT * FROM `player_phones` WHERE `phoneOwner`=%d", AccountData[playerid][pID]);
        mysql_pquery(g_SQL, jts, "OnPlayerBuySmartphone", "i", playerid);
    }
    else
    {
        Inventory_Add(playerid, vaultItemName, FactionBrankas[slot][factionBrankasModel], quantity);
    }

    ShowItemBox(playerid, vaultItemName, sprintf("Received %dx", quantity), FactionBrankas[slot][factionBrankasModel], 5);
    InsertFactionVaultLog(playerid, vaultItemName, quantity, "Bennys");

    FactionBrankas[slot][factionBrankasQuant] -= quantity;

    if(FactionBrankas[slot][factionBrankasQuant] > 0)
    {
        mysql_format(g_SQL, jts, sizeof(jts), "UPDATE `faction_brankas` SET `Quantity`=%d WHERE `ID`=%d", FactionBrankas[slot][factionBrankasQuant], FactionBrankas[slot][factionBrankasID]);
        mysql_pquery(g_SQL, jts);
    }
    else
    {
        mysql_format(g_SQL, jts, sizeof(jts), "DELETE FROM `faction_brankas` WHERE `ID`=%d", FactionBrankas[slot][factionBrankasID]);
        mysql_pquery(g_SQL, jts);

        FactionBrankas[slot][factionBrankasExists] = false;
        FactionBrankas[slot][factionBrankasID] = 0;
        FactionBrankas[slot][factionBrankasFID] = FACTION_NONE;
        FactionBrankas[slot][factionBrankasTemp][0] = EOS;
        FactionBrankas[slot][factionBrankasModel] = 0;
        FactionBrankas[slot][factionBrankasQuant] = 0;
    }
    AccountData[playerid][pMenuShowed] = false;
    return 1;
}

Dialog:BennysLocker(playerid, response, listitem, inputtext[])
{
    if(!response) return ShowTDN(playerid, NOTIFICATION_INFO, "Anda telah membatalkan pilihan!");
    if(AccountData[playerid][pFaction] != FACTION_BENNYS) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda bukan bagian dari Bennys Automotive!");

    switch(listitem)
    {
        case 0: // baju warga / on-off duty
        {
            if(AccountData[playerid][pOnDuty])
            {
                SetPlayerSkin(playerid, AccountData[playerid][pSkin]);
                AccountData[playerid][pIsUsingUniform] = false;
                AccountData[playerid][pOnDuty] = false;
                ShowTDN(playerid, NOTIFICATION_INFO, "Anda sekarang ~r~off duty.");
                Iter_Remove(BennysDuty, playerid);
            }
            else
            {
                AccountData[playerid][pUniform] = (AccountData[playerid][pGender] == 1) ? (268) : (193);
                SetPlayerSkin(playerid, AccountData[playerid][pUniform]);
                AccountData[playerid][pIsUsingUniform] = true;
                AccountData[playerid][pOnDuty] = true;
                ShowTDN(playerid, NOTIFICATION_INFO, "Anda sekarang ~g~on duty.");
                Iter_Add(BennysDuty, playerid);
            }
        }
        case 1: // baju Bennys
        {
            switch(AccountData[playerid][pGender])
            {
                case 1: // male
                {
                    Dialog_Show(playerid, "BennysUniform", DIALOG_STYLE_LIST, ""ARIVENA"Arivena Theater "WHITE"- Baju Bennys",
                    "Bennys 1\n\
                    "GRAY"Bennys 2\n\
                    Bennys 3", "Pilih", "Batal");
                }
                case 2: // female
                {
                    Dialog_Show(playerid, "BennysUniform", DIALOG_STYLE_LIST, ""ARIVENA"Arivena Theater "WHITE"- Baju Bennys",
                    "Bennys 1\n\
                    "GRAY"Bennys 2", "Pilih", "Batal");
                }
            }
        }
    }
    return 1;
}

Dialog:BennysUniform(playerid, response, listitem, inputtext[])
{
    if(!response) return ShowTDN(playerid, NOTIFICATION_INFO, "Anda telah membatalkan pilihan!");
    if(AccountData[playerid][pFaction] != FACTION_BENNYS) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda bukan bagian dari Bennys Automotive!");

    switch(listitem)
    {
        case 0: AccountData[playerid][pUniform] = (AccountData[playerid][pGender] == 1) ? (268) : (190);
        case 1: AccountData[playerid][pUniform] = (AccountData[playerid][pGender] == 1) ? (42) : (193);
        case 2: AccountData[playerid][pUniform] = 119;
    }
    SetPlayerSkin(playerid, AccountData[playerid][pUniform]);
    AccountData[playerid][pIsUsingUniform] = true;
    return 1;
}

Dialog:BennysBosdesk(playerid, response, listitem, inputtext[])
{
    if(!response) return ShowTDN(playerid, NOTIFICATION_INFO, "Anda telah membatalkan pilihan!");
    if(AccountData[playerid][pFaction] != FACTION_BENNYS) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda bukan bagian dari Bennys Automotive!");
    if(AccountData[playerid][pFactionRank] < 4) return ShowTDN(playerid, NOTIFICATION_ERROR, "Minimal rank faction adalah Wakil Manager untuk akses ini!");

    switch(listitem)
    {
        case 0: // invite
        {
            new count, frmxt[522];
            BuildNearbyPlayerList(playerid, 1.5, frmxt, sizeof(frmxt), count);

            if(count == 0)
            {
                PlayerPlaySound(playerid, 5206, 0.0, 0.0, 0.0);
                return Dialog_Show(playerid, "UnusedDialog", DIALOG_STYLE_MSGBOX, ""ARIVENA"Arivena Theater "WHITE"- Undang Faction", "Tidak ada pemain terdekat!", "Tutup", "");
            }

            Dialog_Show(playerid, "BennysIhnviteConfirm", DIALOG_STYLE_TABLIST, ""ARIVENA"Arivena Theater "WHITE"- Undang Faction", frmxt, "Pilih", "Batal");
        }
        case 1: // set rank
        {
            index_pagination[playerid] = 0;
            Show_BennysRankManage(playerid);
        }
        case 2: // kick
        {
            index_pagination[playerid] = 0;
            ShowBennysKick(playerid);
        }
        case 3: // saldo
        {
            new rtx[158];
            format(rtx, sizeof(rtx), "Saldo Bennys Automotive saat ini ialah:\n\
            "DARKGREEN"$%s", FormatMoney(BennysMoneyVault));
            Dialog_Show(playerid, "UnusedDialog", DIALOG_STYLE_MSGBOX, ""ARIVENA"Arivena Theater "WHITE"- Bennys Balance", rtx, "Tutup", "");
        }
        case 4: // deposit saldo
        {
            Dialog_Show(playerid, "BennysDepositCash", DIALOG_STYLE_INPUT, ""ARIVENA"Arivena Theater "WHITE"- Bennys Deposit", "Mohon masukkan berapa jumlah deposit:", "Input", "Batal");
        }
        case 5: // tarik saldo
        {
            Dialog_Show(playerid, "BennysWithdrawCash", DIALOG_STYLE_INPUT, ""ARIVENA"Arivena Theater "WHITE"- Bennys Withdraw", "Mohon masukkan berapa jumlah withdraw:", "Input", "Batal");
        }
    }
    return 1;
}

Dialog:BennysIhnviteConfirm(playerid, response, listitem, inputtext[])
{
    if(!response) return ShowTDN(playerid, NOTIFICATION_INFO, "Anda telah membatalkan pilihan!");
    if(AccountData[playerid][pFaction] != FACTION_BENNYS) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda bukan bagian dari Bennys Automotive!");
    if(AccountData[playerid][pFactionRank] < 4) return ShowTDN(playerid, NOTIFICATION_ERROR, "Minimal rank faction adalah Wakil Manager untuk akses ini!");

    new targetid = NearestUser[playerid][listitem];
    if(!IsPlayerConnected(targetid)) return ShowTDN(playerid, NOTIFICATION_ERROR, "Pemain tersebut tidak terkoneksi ke server!");

    AccountData[targetid][pFaction] = FACTION_BENNYS;
    AccountData[targetid][pFactionRank] = 1;

    new icsr[128];
    mysql_format(g_SQL, icsr, sizeof(icsr), "UPDATE `player_characters` SET `Char_Faction` = 5, `Char_FactionRank` = 1 WHERE `pID` = %d", AccountData[targetid][pID]);
    mysql_pquery(g_SQL, icsr);

    ShowTDN(playerid, NOTIFICATION_INFO, sprintf("Anda telah mengundang %s ke faction!", AccountData[targetid][pName]));
    InsertFactionLog("Invite", sprintf("%s %s - %s %s", AccountData[playerid][pName], AccountData[playerid][pUCP], AccountData[targetid][pName], AccountData[targetid][pUCP]), "Bennys");
    return 1;
}

// =====================================================================
//  SET RANK
// =====================================================================
#define BENNYS_SETRANK_PROMPT "Silahkan pilih jabatan untuk ditetapkan (masukkan angka saja):\n\
1. PKL\n\
2. Amatir\n\
3. Ahli\n\
4. Wakil Manager\n\
5. Manager\n\
6. Boss Bennys"

Dialog:BennysSetRankConfirm(playerid, response, listitem, inputtext[])
{
    if(!response) return ShowTDN(playerid, NOTIFICATION_INFO, "Anda telah membatalkan pilihan!");
    if(AccountData[playerid][pFaction] != FACTION_BENNYS) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda bukan bagian dari Bennys Automotive!");
    if(AccountData[playerid][pFactionRank] < 4) return ShowTDN(playerid, NOTIFICATION_ERROR, "Minimal rank Wakil Manager untuk akses faction menu!");

    if(isnull(inputtext))
        return Dialog_Show(playerid, "BennysSetRankConfirm", DIALOG_STYLE_INPUT, ""ARIVENA"Arivena Theater "WHITE"- Manage Rank", "Error: Tidak dapat dikosongkan!\n"BENNYS_SETRANK_PROMPT, "Set", "Batal");

    if(!IsNumericEx(inputtext))
        return Dialog_Show(playerid, "BennysSetRankConfirm", DIALOG_STYLE_INPUT, ""ARIVENA"Arivena Theater "WHITE"- Manage Rank", "Error: Masukkan hanya angka!\n"BENNYS_SETRANK_PROMPT, "Set", "Batal");

    new newRank = strval(inputtext);
    if(newRank < 1 || newRank > 6)
        return Dialog_Show(playerid, "BennysSetRankConfirm", DIALOG_STYLE_INPUT, ""ARIVENA"Arivena Theater "WHITE"- Manage Rank", "Error: Tidak dapat diisi dibawah 1 atau lebih tinggi dari jabatan anda!\n"BENNYS_SETRANK_PROMPT, "Set", "Batal");

    new hjh[128];
    mysql_format(g_SQL, hjh, sizeof(hjh), "UPDATE `player_characters` SET `Char_FactionRank`=%d WHERE `pID`=%d", newRank, AccountData[playerid][pTempSQLFactMemberID]);
    mysql_pquery(g_SQL, hjh);

    foreach(new i : Player)
    {
        if(AccountData[i][IsLoggedIn] && AccountData[i][pSpawned] && AccountData[playerid][pTempSQLFactMemberID] == AccountData[i][pID])
        {
            AccountData[i][pFactionRank] = newRank;
            ShowTDN(i, NOTIFICATION_INFO, "Jabatan faction anda telah diperbarui!");
            InsertFactionLog("Set Rank", sprintf("%s %s - %s %s LV %d", AccountData[playerid][pName], AccountData[playerid][pUCP], AccountData[i][pName], AccountData[i][pUCP], newRank), "Bennys");
        }
    }

    ShowTDN(playerid, NOTIFICATION_SUCCESS, "Anda berhasil mengubah jabatan faction Pemain tersebut!");
    return 1;
}

Dialog:BennysSetRankPage(playerid, response, listitem, inputtext[])
{
    if(!response) return ShowTDN(playerid, NOTIFICATION_INFO, "Anda telah membatalkan pilihan!");

    if(!strcmp(inputtext, ">> Selanjutnya", true))
    {
        index_pagination[playerid]++;

        new max_page = ((TempRows[playerid] + MAX_MEMBER_ROWS - 1) / MAX_MEMBER_ROWS) - 1;
        if(index_pagination[playerid] >= max_page) index_pagination[playerid] = max_page;

        Show_BennysRankManage(playerid);
    }
    else if(!strcmp(inputtext, "<< Sebelumnya", true))
    {
        index_pagination[playerid]--;
        if(index_pagination[playerid] <= 0) index_pagination[playerid] = 0;

        Show_BennysRankManage(playerid);
    }
    else
    {
        if(AccountData[playerid][pFaction] != FACTION_BENNYS) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda bukan bagian dari Bennys Automotive!");
        if(AccountData[playerid][pFactionRank] < 4) return ShowTDN(playerid, NOTIFICATION_ERROR, "Minimal rank faction adalah Wakil Manager untuk akses ini!");

        mysql_query(g_SQL, sprintf("SELECT * FROM `player_characters` WHERE `pID` = '%d'", ListedMember[playerid][listitem]));
        new rows = cache_num_rows();
        if(rows)
        {
            cache_get_value_name_int(0, "pID", AccountData[playerid][pTempSQLFactMemberID]);
            cache_get_value_name_int(0, "Char_FactionRank", AccountData[playerid][pTempSQLFactRank]);

            if(AccountData[playerid][pID] == AccountData[playerid][pTempSQLFactMemberID]) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda tidak dapat menetapkan rank anda sendiri!");
            if(AccountData[playerid][pTempSQLFactRank] >= AccountData[playerid][pFactionRank]) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda tidak dapat menetapkan rank rekan yang sejajar/lebih tinggi dari anda!");

            Dialog_Show(playerid, "BennysSetRankConfirm", DIALOG_STYLE_INPUT, ""ARIVENA"Arivena Theater "WHITE"- Manage Rank", BENNYS_SETRANK_PROMPT, "Set", "Batal");
        }
    }
    return 1;
}

Dialog:BennysKickMember(playerid, response, listitem, inputtext[])
{
    if(!response) return ShowTDN(playerid, NOTIFICATION_INFO, "Anda telah membatalkan pilihan!");

    if(!strcmp(inputtext, ">> Selanjutnya", true))
    {
        index_pagination[playerid]++;
        ShowBennysKick(playerid);
    }
    else if(!strcmp(inputtext, "<< Sebelumnya", true))
    {
        index_pagination[playerid]--;
        if(index_pagination[playerid] < 0) index_pagination[playerid] = 0;
        ShowBennysKick(playerid);
    }
    else
    {
        new l_row_pid = ListedMember[playerid][listitem];

        if(AccountData[playerid][pFaction] != FACTION_BENNYS) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda bukan bagian dari Bennys Automotive!");
        if(AccountData[playerid][pFactionRank] < 4) return ShowTDN(playerid, NOTIFICATION_ERROR, "Minimal rank faction adalah Wakil Manager untuk akses ini!");

        mysql_query(g_SQL, sprintf("SELECT * FROM `player_characters` WHERE `pID` = %d", l_row_pid));
        new rows = cache_num_rows();
        if(rows)
        {
            new fckname[64], fckrank, fcklastlogin[30], kckstr[225], iscr[128];
            cache_get_value_name(0, "Char_Name", fckname);
            cache_get_value_name_int(0, "Char_FactionRank", fckrank);
            cache_get_value_name(0, "Char_LastLogin", fcklastlogin);

            if(AccountData[playerid][pID] == l_row_pid) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda tidak dapat menendang diri sendiri!");
            if(fckrank >= AccountData[playerid][pFactionRank]) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda tidak dapat menendang rekan sejajar/lebih tinggi dari anda!");

            new string[168];
            mysql_format(g_SQL, string, sizeof(string), "DELETE FROM `demand_vehicles` WHERE `ownerid` = %d", l_row_pid);
            mysql_pquery(g_SQL, string);

            foreach(new i : Player)
            {
                if(l_row_pid != AccountData[i][pID]) continue;

                for(new x = 0; x < MAX_FACTIONS; x++)
                {
                    DestroyVehicle(PlayerFactionVehicle[i][x]);
                    PlayerFactionVehicle[i][x] = INVALID_VEHICLE_ID;
                }
                LSPDPlayerCallsign[i][0] = EOS;

                AccountData[i][pFaction] = 0;
                AccountData[i][pFactionRank] = 0;

                if(Iter_Contains(BennysDuty, i)) Iter_Remove(BennysDuty, i);

                ShowTDN(i, NOTIFICATION_WARNING, "Anda telah ditendang dari Bennys!");
                break;
            }

            InsertFactionLog("Kick", sprintf("%s %s - %s", AccountData[playerid][pName], AccountData[playerid][pUCP], fckname), "Bennys");

            mysql_format(g_SQL, iscr, sizeof(iscr), "UPDATE `player_characters` SET `Char_Faction` = 0, `Char_FactionRank` = 0 WHERE `pID` = %d", l_row_pid);
            mysql_pquery(g_SQL, iscr);

            format(kckstr, sizeof(kckstr), "Anda berhasil mengeluarkan:\n\
            Name: %s\n\
            Rank: %s\n\
            Last Online: %s", fckname, BennysRank[fckrank], fcklastlogin);
            Dialog_Show(playerid, "UnusedDialog", DIALOG_STYLE_MSGBOX, ""ARIVENA"Arivena Theater "WHITE"- Kick Faction", kckstr, "Tutup", "");
        }
    }
    return 1;
}

Dialog:BennysDepositCash(playerid, response, listitem, inputtext[])
{
    if(!response) return ShowTDN(playerid, NOTIFICATION_INFO, "Anda telah membatalkan pilihan!");
    if(AccountData[playerid][pFaction] != FACTION_BENNYS) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda bukan bagian dari Bennys Automotive!");
    if(AccountData[playerid][pFactionRank] < 4) return ShowTDN(playerid, NOTIFICATION_ERROR, "Rank minimal adalah Wakil Manager untuk akses menu ini!");

    if(isnull(inputtext))
        return Dialog_Show(playerid, "BennysDepositCash", DIALOG_STYLE_INPUT, ""ARIVENA"Arivena Theater "WHITE"- Bennys Deposit", "Error: Tidak dapat dikosongkan!\nMohon masukkan berapa jumlah deposit:", "Deposit", "Batal");

    if(!IsNumericEx(inputtext))
        return Dialog_Show(playerid, "BennysDepositCash", DIALOG_STYLE_INPUT, ""ARIVENA"Arivena Theater "WHITE"- Bennys Deposit", "Error: Masukkan hanya angka!\nMohon masukkan berapa jumlah deposit:", "Deposit", "Batal");

    new amount = strval(inputtext);
    if(amount < 1)
        return Dialog_Show(playerid, "BennysDepositCash", DIALOG_STYLE_INPUT, ""ARIVENA"Arivena Theater "WHITE"- Bennys Deposit", "Error: Invalid amount, you can't deposit less than $1!\nMohon masukkan berapa jumlah deposit:", "Deposit", "Batal");

    if(amount > AccountData[playerid][pMoney]) return ShowTDN(playerid, NOTIFICATION_ERROR, "Uang anda tidak cukup!");

    TakePlayerMoneyEx(playerid, amount);
    BennysMoneyVault += amount;

    new frmtmny[128];
    mysql_format(g_SQL, frmtmny, sizeof(frmtmny), "UPDATE `stuffs` SET `bennysmoneyvault` = %d WHERE `id` = 0", BennysMoneyVault);
    mysql_pquery(g_SQL, frmtmny);

    ShowTDN(playerid, NOTIFICATION_SUCCESS, sprintf("Anda berhasil deposit $%s untuk Bennys Automotive.", FormatMoney(amount)));
    return 1;
}

Dialog:BennysWithdrawCash(playerid, response, listitem, inputtext[])
{
    if(!response) return ShowTDN(playerid, NOTIFICATION_INFO, "Anda telah membatalkan pilihan!");
    if(AccountData[playerid][pFaction] != FACTION_BENNYS) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda bukan bagian dari Bennys Automotive!");
    if(AccountData[playerid][pFactionRank] < 4) return ShowTDN(playerid, NOTIFICATION_ERROR, "Rank minimal adalah Wakil Manager untuk akses menu ini!");

    if(isnull(inputtext))
        return Dialog_Show(playerid, "BennysWithdrawCash", DIALOG_STYLE_INPUT, ""ARIVENA"Arivena Theater "WHITE"- Bennys Withdraw", "Error: Tidak dapat dikosongkan!\nMohon masukkan jumlah yang ingin ditarik:", "Withdraw", "Batal");

    if(!IsNumericEx(inputtext))
        return Dialog_Show(playerid, "BennysWithdrawCash", DIALOG_STYLE_INPUT, ""ARIVENA"Arivena Theater "WHITE"- Bennys Withdraw", "Error: Masukkan hanya angka!\nMohon masukkan jumlah yang ingin ditarik:", "Withdraw", "Batal");

    new amount = strval(inputtext);
    if(amount < 1)
        return Dialog_Show(playerid, "BennysWithdrawCash", DIALOG_STYLE_INPUT, ""ARIVENA"Arivena Theater "WHITE"- Bennys Withdraw", "Error: Jumlah tidak valid, anda tidak dapat withdraw kurang dari $1!\nMohon masukkan jumlah yang ingin ditarik:", "Withdraw", "Batal");

    if(BennysMoneyVault < RoundNegativeToPositive(amount)) return ShowTDN(playerid, NOTIFICATION_ERROR, "Jumlah tidak valid, saldo tidak cukup!");

    BennysMoneyVault -= amount;
    GivePlayerMoneyEx(playerid, amount);

    new frmtmny[128];
    mysql_format(g_SQL, frmtmny, sizeof(frmtmny), "UPDATE `stuffs` SET `bennysmoneyvault` = %d WHERE `id` = 0", BennysMoneyVault);
    mysql_pquery(g_SQL, frmtmny);

    AddFMoneyLog(AccountData[playerid][pName], AccountData[playerid][pUCP], amount, "Bennys");
    ShowTDN(playerid, NOTIFICATION_SUCCESS, sprintf("Anda berhasil withdraw $%s dari Bennys Automotive", FormatMoney(amount)));
    return 1;
}

Dialog:BennysGarage(playerid, response, listitem, inputtext[])
{
    if(!response) return ShowTDN(playerid, NOTIFICATION_INFO, "Anda telah membatalkan pilihan!");
    if(AccountData[playerid][pFaction] != FACTION_BENNYS) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda bukan bagian dari Bennys Automotive!");

    switch(listitem)
    {
        case 0: // keluarkan kendaraan
        {
            if(PlayerFactionVehicle[playerid][FACTION_BENNYS] != INVALID_VEHICLE_ID) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda telah mengeluarkan kendaraan, simpan terlebih dahulu!");

            Dialog_Show(playerid, "BennysGarageTakeout", DIALOG_STYLE_LIST, ""ARIVENA"Arivena Theater "WHITE"- Keluarkan Kendaraan",
            "Tow Truck\n\
            "GRAY"Yosemite", "Pilih", "Batal");
        }
        case 1: // simpan kendaraan
        {
            for(new x; x < MAX_FACTIONS; x++)
            {
                DestroyVehicle(PlayerFactionVehicle[playerid][x]);
                PlayerFactionVehicle[playerid][x] = INVALID_VEHICLE_ID;
            }
            LSPDPlayerCallsign[playerid][0] = EOS;

            new string[168];
            mysql_format(g_SQL, string, sizeof(string), "DELETE FROM `demand_vehicles` WHERE `ownerid` = %d", AccountData[playerid][pID]);
            mysql_pquery(g_SQL, string);
            ShowTDN(playerid, NOTIFICATION_INFO, "Kendaraan tersebut telah tersimpan ke garasi faction.");
        }
    }
    return 1;
}

Dialog:BennysGarageTakeout(playerid, response, listitem, inputtext[])
{
    if(!response)
    {
        AccountData[playerid][pTempValue] = -1;
        return ShowTDN(playerid, NOTIFICATION_INFO, "Anda telah membatalkan pilihan!");
    }

    if(AccountData[playerid][pFaction] != FACTION_BENNYS)
    {
        AccountData[playerid][pTempValue] = -1;
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda bukan bagian dari Bennys Automotive!");
    }

    new garageid = GetPlayerNearestFGarage(playerid);
    if(garageid == -1) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda tidak dekat dengan garasi faction anda!");

    for(new x; x < MAX_FACTIONS; x++)
    {
        DestroyVehicle(PlayerFactionVehicle[playerid][x]);
        PlayerFactionVehicle[playerid][x] = INVALID_VEHICLE_ID;
    }

    new vehModel = (listitem == 0) ? (525) : (554); // 0: tow truck, 1: yosemite
    PlayerFactionVehStats[playerid][pFactVehModel] = vehModel;
    PlayerFactionVehicle[playerid][FACTION_BENNYS] = CreateVehicle(vehModel,
        FactGarageData[garageid][GarageSpawnPos][0], FactGarageData[garageid][GarageSpawnPos][1],
        FactGarageData[garageid][GarageSpawnPos][2], FactGarageData[garageid][GarageSpawnPos][3], 102, 1, 60000, false);

    DestroyFactVehToys(PlayerFactionVehicle[playerid][FACTION_BENNYS]);
    FactionVehHasCallsign[PlayerFactionVehicle[playerid][FACTION_BENNYS]] = false;
    LSPDPlayerCallsign[playerid][0] = EOS;

    PlayerFactionVehStats[playerid][pFactVehColor1] = 102;
    PlayerFactionVehStats[playerid][pFactVehColor2] = 1;
    PlayerFactionVehStats[playerid][pFactVehFuel] = 100;
    PlayerFactionVehStats[playerid][pFactVehMaxHealth] = 1000.0;
    PlayerFactionVehStats[playerid][pFactVehBodyUpgraded] = false;
    PlayerFactionVehStats[playerid][pFactVehBodyBroken] = false;
    PlayerFactionVehStats[playerid][pFactVehLocked] = false;

    VehicleCore[PlayerFactionVehicle[playerid][FACTION_BENNYS]][vCoreFuel] = 100;
    SetValidVehicleHealth(PlayerFactionVehicle[playerid][FACTION_BENNYS], 1000.0);
    VehicleCore[PlayerFactionVehicle[playerid][FACTION_BENNYS]][vMaxHealth] = 1000.0;
    VehicleCore[PlayerFactionVehicle[playerid][FACTION_BENNYS]][vIsBodyUpgraded] = false;
    VehicleCore[PlayerFactionVehicle[playerid][FACTION_BENNYS]][vIsBodyBroken] = false;
    VehicleCore[PlayerFactionVehicle[playerid][FACTION_BENNYS]][vCoreLocked] = false;
    PutPlayerInVehicleEx(playerid, PlayerFactionVehicle[playerid][FACTION_BENNYS], 0);
    SwitchVehicleEngine(PlayerFactionVehicle[playerid][FACTION_BENNYS], true);
    SwitchVehicleDoors(PlayerFactionVehicle[playerid][FACTION_BENNYS], false);

    new string[555];
    mysql_format(g_SQL, string, sizeof(string), "INSERT INTO `demand_vehicles` (`ownerid`, `model`, `vehX`, `vehY`, `vehZ`, `vehA`, `damage0`, `damage1`, `damage2`, `damage3`, `health`, `fuel`, `locked`, `world`, `color1`, `color2`) VALUES (%d, %d, '%f', '%f', '%f', '0.0', 0, 0, 0, 0, '2000.0', %d, %d, 0, %d, %d)",
        AccountData[playerid][pID],
        PlayerFactionVehStats[playerid][pFactVehModel],
        FactGarageData[garageid][GarageSpawnPos][0],
        FactGarageData[garageid][GarageSpawnPos][1],
        FactGarageData[garageid][GarageSpawnPos][2],
        VehicleCore[PlayerFactionVehicle[playerid][FACTION_BENNYS]][vCoreFuel],
        VehicleCore[PlayerFactionVehicle[playerid][FACTION_BENNYS]][vCoreLocked],
        PlayerFactionVehStats[playerid][pFactVehColor1],
        PlayerFactionVehStats[playerid][pFactVehColor2]);
    mysql_pquery(g_SQL, string);
    return 1;
}

Dialog:BennysPanel(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    if(AccountData[playerid][pFaction] != FACTION_BENNYS) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda bukan bagian dari Bennys Automotive!");

    new targetid = NearestSingle[playerid];
    if(!IsPlayerConnected(targetid)) return ShowTDN(playerid, NOTIFICATION_ERROR, "Pemain tersebut tidak terkoneksi ke server!");
    if(!IsPlayerNearPlayer(playerid, targetid, 3.0)) return ShowTDN(playerid, NOTIFICATION_ERROR, "Pemain tersebut tidak dekat dengan anda!");
    if(AccountData[playerid][pKnockdown]) return ShowTDN(playerid, NOTIFICATION_ERROR, "Karakter anda terluka parah saat ini!");

    switch(listitem)
    {
        case 0: // invoice belum terbayar
        {
            new xjjs[600], count;
            format(xjjs, sizeof(xjjs), "#\tNama Tagihan\tPemberi\tNominal Tagihan\n");
            for(new id; id < MAX_INVOICES; id++)
            {
                if(InvoiceData[targetid][id][invoiceExists] && InvoiceData[targetid][id][invoiceOwner] == AccountData[targetid][pID])
                {
                    format(xjjs, sizeof(xjjs), "%s"WHITE"%d\t"WHITE"%s\t"YELLOW"%s\t"RED"%s\n", xjjs, id + 1, InvoiceData[targetid][id][invoiceName], InvoiceData[targetid][id][invoiceIssuerName], FormatMoney(InvoiceData[targetid][id][invoiceCost]));
                    count++;
                }
            }

            if(count == 0)
            {
                Dialog_Show(playerid, "UnusedDialog", DIALOG_STYLE_MSGBOX, ""ARIVENA"Arivena Theater "WHITE"- Unpaid Invoice", "This person has no invoices.", "Tutup", "");
            }
            else
            {
                Dialog_Show(playerid, "UnusedDialog", DIALOG_STYLE_TABLIST_HEADERS, ""ARIVENA"Arivena Theater "WHITE"- Unpaid Invoice", xjjs, "Tutup", "");
            }
            NearestSingle[playerid] = INVALID_PLAYER_ID;
        }
        case 1: // invoice manual
        {
            if(!IsPlayerInAnyVehicle(playerid))
            {
                SetPlayerAttachedObject(playerid, 9, 19786, 5, 0.182999, 0.048999, -0.112999, -66.699935, -23.799949, -116.699996, 0.130999, 0.136000, 0.142000, 0, 0);
                ApplyAnimation(playerid, "INT_SHOP", "shop_loop", 4.1, true, false, false, true, 0, true);
            }

            Dialog_Show(playerid, "InvoiceSetName", DIALOG_STYLE_INPUT, ""ARIVENA"Arivena Theater "WHITE"- Invoice", "Mohon masukkan nama dari invoice ini:", "Input", "Batal");
        }
        case 2: // seret
        {
            if(AccountData[playerid][DraggingID] != INVALID_PLAYER_ID)
            {
                AccountData[playerid][DraggingID] = INVALID_PLAYER_ID;
                if(IsPlayerConnected(AccountData[playerid][DraggingID]))
                {
                    AccountData[AccountData[playerid][DraggingID]][pGetDraggedBy] = INVALID_PLAYER_ID;
                }
                TogglePlayerControllable(targetid, true);
                ShowTDN(playerid, NOTIFICATION_INFO, "Anda telah berhenti menggendong seseorang.");
                return 1;
            }

            foreach(new i : Player)
            {
                if(AccountData[i][DraggingID] == playerid) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda tidak dapat menyeret seseorang yang sedang menyeret orang lain!");
            }

            AccountData[playerid][DraggingID] = targetid;
            AccountData[targetid][pGetDraggedBy] = playerid;
            TogglePlayerControllable(targetid, false);
            ShowTDN(playerid, NOTIFICATION_SUCCESS, "Anda berhasil menggendong seseorang.");
            NearestSingle[playerid] = INVALID_PLAYER_ID;
        }
    }
    return 1;
}

SavePVComponents(vehicleid, componentid)
{
    foreach(new ii : PvtVehicles)
    {
        if(vehicleid != PlayerVehicle[ii][pVehPhysic]) continue;

        if(IsComponentInArray(componentid, pv_spoiler, sizeof(pv_spoiler)))           PlayerVehicle[ii][pVehMod][0]  = componentid;
        else if(IsComponentInArray(componentid, pv_nitro, sizeof(pv_nitro)))           PlayerVehicle[ii][pVehMod][1]  = componentid;
        else if(IsComponentInArray(componentid, pv_fbumper, sizeof(pv_fbumper)))       PlayerVehicle[ii][pVehMod][2]  = componentid;
        else if(IsComponentInArray(componentid, pv_rbumper, sizeof(pv_rbumper)))       PlayerVehicle[ii][pVehMod][3]  = componentid;
        else if(IsComponentInArray(componentid, pv_exhaust, sizeof(pv_exhaust)))       PlayerVehicle[ii][pVehMod][4]  = componentid;
        else if(IsComponentInArray(componentid, pv_bventr, sizeof(pv_bventr)))         PlayerVehicle[ii][pVehMod][5]  = componentid;
        else if(IsComponentInArray(componentid, pv_bventl, sizeof(pv_bventl)))         PlayerVehicle[ii][pVehMod][6]  = componentid;
        else if(IsComponentInArray(componentid, pv_bscoop, sizeof(pv_bscoop)))         PlayerVehicle[ii][pVehMod][7]  = componentid;
        else if(IsComponentInArray(componentid, pv_roof, sizeof(pv_roof)))             PlayerVehicle[ii][pVehMod][8]  = componentid;
        else if(IsComponentInArray(componentid, pv_lskirt, sizeof(pv_lskirt)))         PlayerVehicle[ii][pVehMod][9]  = componentid;
        else if(IsComponentInArray(componentid, pv_rskirt, sizeof(pv_rskirt)))         PlayerVehicle[ii][pVehMod][10] = componentid;
        else if(IsComponentInArray(componentid, pv_hydraulics, sizeof(pv_hydraulics))) PlayerVehicle[ii][pVehMod][11] = componentid;
        else if(IsComponentInArray(componentid, pv_base, sizeof(pv_base)))             PlayerVehicle[ii][pVehMod][12] = componentid;
        else if(IsComponentInArray(componentid, pv_rbbars, sizeof(pv_rbbars)))         PlayerVehicle[ii][pVehMod][13] = componentid;
        else if(IsComponentInArray(componentid, pv_fbbars, sizeof(pv_fbbars)))         PlayerVehicle[ii][pVehMod][14] = componentid;
        else if(IsComponentInArray(componentid, pv_wheels, sizeof(pv_wheels)))         PlayerVehicle[ii][pVehMod][15] = componentid;
        else if(IsComponentInArray(componentid, pv_lights, sizeof(pv_lights)))         PlayerVehicle[ii][pVehMod][16] = componentid;
    }
    return 1;
}

enum e_CraftMat
{
    craftMatName[24],
    craftMatLabel[24],
    craftMatQty,
    craftMatModel,
    craftMatBoxSlot
};

#define MAX_CRAFT_MATS 5

new const CraftMaterials[][MAX_CRAFT_MATS][e_CraftMat] =
{
    { // 0
        {"Komponen", "Komponen", 180, 2040, 5},
        {"Tembaga", "Tembaga", 3, 19772, 6},
        {"Besi", "Besi", 5, 19809, 7},
        {"Plastik", "Plastik", 3, 2937, 8},
        {"Minyak", "Minyak", 5, 19621, 9}
    },
    { // 1
        {"Komponen", "Komponen", 180, 2040, 5},
        {"Tembaga", "Tembaga", 3, 19772, 6},
        {"Besi", "Besi", 5, 19809, 7},
        {"Plastik", "Plastik", 5, 19433, 8},
        {"Minyak", "Minyak", 3, 1649, 9}
    },
    { // 2
        {"Komponen", "Komponen", 180, 2040, 5},
        {"Tembaga", "Tembaga", 3, 19772, 6},
        {"Besi", "Besi", 5, 19809, 7},
        {"Linggis", "Linggis", 2, 1316, 8},
        {"Plastik", "Plastik", 5, 2937, 9}
    },
    { // 3
        {"Komponen", "Komponen", 180, 2040, 5},
        {"Pilox", "Pilox", 1, 365, 6},
        {"Botol", "Botol", 10, 19570, 7},
        {"Emas", "Gold", 2, 19941, 8},
        {"", "", 0, 0, 0}
    },
    { // 4
        {"Komponen", "Komponen", 180, 2040, 5},
        {"Tembaga", "Tembaga", 5, 19772, 6},
        {"Besi", "Besi", 10, 19809, 7},
        {"Plastik", "Plastik", 5, 2937, 8},
        {"Minyak", "Minyak", 10, 19621, 9}
    }
};

Dialog:FactionCrafting(playerid, response, listitem, inputtext[])
{
    if(!response) return ShowTDN(playerid, NOTIFICATION_INFO, "Anda telah membatalkan pilihan!");
    if(AccountData[playerid][pFaction] != FACTION_BENNYS && AccountData[playerid][pFaction] != FACTION_AUTOMAX && AccountData[playerid][pFaction] != FACTION_HANDOVER)
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Perintah ini hanya dapat diakses oleh faction sejenis bengkel!");

    if(listitem < 0 || listitem >= sizeof(CraftMaterials)) return 1;

    for(new i = 0; i < MAX_CRAFT_MATS; i++)
    {
        if(!CraftMaterials[listitem][i][craftMatQty]) continue;
        if(Inventory_Count(playerid, CraftMaterials[listitem][i][craftMatName]) < CraftMaterials[listitem][i][craftMatQty])
            return ShowTDN(playerid, NOTIFICATION_ERROR, sprintf("Anda tidak memiliki cukup %s!", CraftMaterials[listitem][i][craftMatLabel]));
    }

    for(new i = 0; i < MAX_CRAFT_MATS; i++)
    {
        if(!CraftMaterials[listitem][i][craftMatQty]) continue;

        Inventory_Remove(playerid, CraftMaterials[listitem][i][craftMatName], CraftMaterials[listitem][i][craftMatQty]);
        ShowItemBox(playerid, CraftMaterials[listitem][i][craftMatName], sprintf("Received %dx", CraftMaterials[listitem][i][craftMatQty]), CraftMaterials[listitem][i][craftMatModel], CraftMaterials[listitem][i][craftMatBoxSlot]);
    }

    AccountData[playerid][pActivityTime] = 1;
    AccountData[playerid][pTempValue2] = listitem;
    pFactionCraftingTimer[playerid] = true;
    return 1;
}
