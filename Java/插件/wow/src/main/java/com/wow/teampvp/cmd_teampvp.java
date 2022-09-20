package com.wow.teampvp;

import org.bukkit.Bukkit;
import org.bukkit.ChatColor;
import org.bukkit.Location;
import org.bukkit.command.Command;
import org.bukkit.command.CommandExecutor;
import org.bukkit.command.CommandSender;
import org.bukkit.entity.Player;


public final class cmd_teampvp implements CommandExecutor {
    public boolean onCommand(CommandSender sender, Command cmd, String lable, String[] args) {
        Player p = (Player) sender;
        boolean permission = //has any permission
                p.hasPermission("wow.teampvp.help") || p.hasPermission("wow.teampvp.create") || p.hasPermission("wow.teampvp.delete") ||
                        p.hasPermission("wow.teampvp.add") || p.hasPermission("wow.teampvp.remove") || p.hasPermission("wow.teampvp.setflag") ||
                        p.hasPermission("wow.teampvp.pairs.list") || p.hasPermission("wow.teampvp.pairs.delete") || p.hasPermission("wow.teampvp.pairs.join") ||
                        p.hasPermission("wow.teampvp.pairs.loc") || p.hasPermission("wow.teampvp.pairs.create") || p.hasPermission("wow.teampvp.pairs.autobalance");
        /////////////////////////////////////////////////////////////////////////////
        if (lable.equalsIgnoreCase("teampvp") && (sender instanceof Player) && permission) {
            if (args.length != 0) {
                if (!(args[0].equals("pairs"))) {
                    switch (args.length) {
                        case 1: //help or list and flag list
                        {
                            switch (args[0]) {
                                case "help": {
                                    if (p.hasPermission("wow.teampvp.help"))  //show help messages
                                    {
                                        p.sendMessage(ChatColor.RED + "-------------[TeamPVP]-------------");
                                        p.sendMessage(ChatColor.GRAY + " ");
                                        p.sendMessage(ChatColor.GRAY + "/teampvp create <名稱> - 新增隊伍");
                                        p.sendMessage(ChatColor.GRAY + "/teampvp delete <名稱> - 刪除隊伍");
                                        p.sendMessage(ChatColor.GRAY + "/teampvp add <名稱> <玩家> - 將玩家加入而隊伍中");
                                        p.sendMessage(ChatColor.GRAY + "/teampvp remove <名稱> <玩家> - 將玩家從隊伍中移除");
                                        p.sendMessage(ChatColor.GRAY + "/teampvp setflag <名稱> <標籤> <True/False> - 設定隊伍標籤");
                                        p.sendMessage(ChatColor.GRAY + "/teampvp list - 顯示所有隊伍");
                                        p.sendMessage(ChatColor.GRAY + "--------------------------------------------------");
                                        p.sendMessage(ChatColor.GRAY + "/teampvp pairs create <名稱> <隊伍一> <隊伍二> - 新增隊伍組合");
                                        p.sendMessage(ChatColor.GRAY + "/teampvp pairs delete <名稱> - 刪除隊伍組合");
                                        p.sendMessage(ChatColor.GRAY + "/teampvp pairs join <名稱> [隊伍] - 加入隊伍組合");
                                        p.sendMessage(ChatColor.GRAY + "/teampvp pairs loc <名稱> <隊伍> - 設至隊伍組合位置");
                                        p.sendMessage(ChatColor.GRAY + "/teampvp pairs autobalance <名稱> <True/False> - 設至是否啟用自動平衡");
                                        p.sendMessage(ChatColor.GRAY + "/teampvp pairs list - 顯示所有隊伍組合");
                                        return true;
                                    }
                                }
                                case "list": {
                                    if (p.hasPermission("wow.teampvp.list"))  //list all teams
                                    {
                                        p.sendMessage(ChatColor.RED + "[TeamPVP] " + ChatColor.GRAY + "隊伍列表: ");
                                        for (Object a : cfg_teampvp.get().getConfigurationSection("Teams").getKeys(false)) {
                                            p.sendMessage(ChatColor.RED + "[TeamPVP] " + ChatColor.GRAY + a);
                                        }
                                        return true;
                                    }
                                }
                                case "setflag": {
                                    if (p.hasPermission("wow.teampvp.setflag")) //show all flags
                                    {
                                        p.sendMessage(ChatColor.RED + "[TeamPVP] " + ChatColor.GRAY + "可用標籤：");
                                        p.sendMessage(ChatColor.RED + "[TeamPVP] " + ChatColor.GRAY + "pvp");
                                        p.sendMessage(ChatColor.RED + "[TeamPVP] " + ChatColor.GRAY + "onworldchange");
                                        p.sendMessage(ChatColor.RED + "[TeamPVP] " + ChatColor.GRAY + "ondeath");
                                        p.sendMessage(ChatColor.RED + "[TeamPVP] " + ChatColor.GRAY + "onquit");
                                        return true;
                                    }
                                }
                                default: {
                                    if (p.hasPermission("wow.teampvp.help") || p.hasPermission("wow.teampvp.list") || p.hasPermission("wow.teampvp.setflag")) //format error
                                    {
                                        p.sendMessage(ChatColor.RED + "[TeamPVP] " + ChatColor.GRAY + "指令格式錯誤！");
                                    } else //no permission
                                    {
                                        p.sendMessage(ChatColor.RED + "你沒有權限使用此指令");
                                    }
                                    return true;
                                }
                            }
                        }
                        case 2: //team create or delete
                        {
                            if (args[0].equals("create") && p.hasPermission("wow.teampvp.create")) //create new team
                            {
                                cfg_teampvp.newteam(args[1]);
                                p.sendMessage(ChatColor.RED + "[TeamPVP] " + ChatColor.GRAY + "成功新增隊伍 " + args[1]);
                            } else {
                                if (args[0].equals("delete") && p.hasPermission("wow.teampvp.delete")) //delete team
                                {
                                    if (cfg_teampvp.get().contains("Teams." + args[1])) {
                                        cfg_teampvp.set("Teams." + args[1], null);
                                        p.sendMessage(ChatColor.RED + "[TeamPVP] " + ChatColor.GRAY + "成功刪除隊伍 " + args[1]);
                                        if (cfg_teampvp.get().getConfigurationSection("Player") != null)  //delete the player that has this team
                                        {
                                            for (String a : cfg_teampvp.get().getConfigurationSection("Player").getKeys(false)) //get all players
                                            {
                                                if (cfg_teampvp.get().get("Player." + a).equals(args[1])) {

                                                    cfg_teampvp.set("Player." + a, null);
                                                }
                                            }
                                        }

                                    } else {
                                        p.sendMessage(ChatColor.RED + "[TeamPVP] " + ChatColor.GRAY + "找不到此隊伍！");
                                    }
                                } else {
                                    if (p.hasPermission("wow.teampvp.create") || p.hasPermission("wow.teampvp.delete")) //format error
                                    {

                                        p.sendMessage(ChatColor.RED + "[TeamPVP] " + ChatColor.GRAY + "指令格式錯誤！");
                                    } else //no permission
                                    {
                                        p.sendMessage(ChatColor.RED + "你沒有權限使用此指令");
                                    }
                                }
                            }
                            break;
                        }
                        case 3: //player add or remove
                        {
                            Player target = Bukkit.getServer().getPlayer(args[2]); //target
                            if (cfg_teampvp.get().contains("Teams." + args[1])) //whether the team is in the teams.yml
                            {
                                if (args[0].equals("add") && p.hasPermission("wow.teampvp.add")) //add the player to the team
                                {
                                    cfg_teampvp.set("Player." + target.getName(), args[1]);
                                    p.sendMessage(ChatColor.RED + "[TeamPVP] " + ChatColor.GRAY + "成功將 " + target.getName() + " 新增 " + args[1]);
                                } else {
                                    if (args[0].equals("remove") && p.hasPermission("wow.teampvp.remove")) //remove the player from the team
                                    {
                                        try {
                                            cfg_teampvp.set("Player." + target.getName(), null);
                                            p.sendMessage(ChatColor.RED + "[TeamPVP] " + ChatColor.GRAY + "成功將 " + target.getName() + " 移除 " + args[1]);
                                        } catch (NullPointerException e) {
                                            p.sendMessage(ChatColor.RED + "[TeamPVP] " + ChatColor.GRAY + "找不到該玩家！");
                                        }
                                    } else {
                                        if (p.hasPermission("wow.teampvp.add") || p.hasPermission("wow.teampvp.remove")) //format error
                                        {
                                            p.sendMessage(ChatColor.RED + "[TeamPVP] " + ChatColor.GRAY + "指令格式錯誤！");
                                        } else //no permission
                                        {
                                            p.sendMessage(ChatColor.RED + "你沒有權限使用此指令");
                                        }
                                    }
                                }
                            } else {
                                p.sendMessage(ChatColor.RED + "[TeamPVP] " + ChatColor.GRAY + "找不到此隊伍！");
                            }
                            break;
                        }
                        case 4: //team setflag
                        {
                            if (args[0].equals("setflag") && p.hasPermission("wow.teampvp.setflag")) {
                                for (String a : cfg_teampvp.get().getConfigurationSection("Teams." + args[1]).getKeys(false)) {
                                    if (args[2].equals(a)) {
                                        cfg_teampvp.setteam(args[1], args[2], args[3]);
                                        p.sendMessage(ChatColor.RED + "[TeamPVP] " + ChatColor.GRAY + "已將 " +
                                                args[1] + " 的 " + args[2] + " 設為 " + args[3]);
                                    }
                                }
                            } else //no permission
                            {
                                p.sendMessage(ChatColor.RED + "你沒有權限使用此指令");
                            }
                            break;
                        }
                        default: //can't find command
                        {
                            p.sendMessage(ChatColor.RED + "[TeamPVP] " + ChatColor.GRAY + "找不到此指令！");
                        }
                        break;
                    }
                } else {
                    switch (args.length) {
                        case 2: //pairs list
                        {
                            if (args[1].equals("list") && p.hasPermission("wow.teampvp.pairs.list"))  //list all pairs
                            {
                                p.sendMessage(ChatColor.RED + "[TeamPVP] " + ChatColor.GRAY + "組合列表: ");
                                for (Object a : cfg_teampvp.get().getConfigurationSection("Pairs").getKeys(false)) //get all pairs
                                {
                                    p.sendMessage(ChatColor.RED + "[TeamPVP] " + ChatColor.GRAY + a);
                                }
                            } else {
                                if (p.hasPermission("wow.teampvp.pairs.list")) {
                                    p.sendMessage(ChatColor.RED + "[TeamPVP] " + ChatColor.GRAY + "指令格式錯誤！");
                                } else {
                                    p.sendMessage(ChatColor.RED + "你沒有權限使用此指令");
                                }
                            }
                            break;
                        }
                        case 3: //pairs auto join and delete
                        {
                            if (args[1].equals("delete") && p.hasPermission("wow.teampvp.pairs.delete")) {
                                if (cfg_teampvp.get().contains("Pairs." + args[2]))  //whether this pair is in the teams.yml
                                {
                                    cfg_teampvp.set("Pairs." + args[2], null);
                                    p.sendMessage(ChatColor.RED + "[TeamPVP] " + ChatColor.GRAY + "已將 " +
                                            args[2] + " 移除");
                                } else {
                                    p.sendMessage(ChatColor.RED + "[TeamPVP] " + ChatColor.GRAY + "找不到此組合！");
                                }
                            } else {
                                if (args[1].equals("join") && p.hasPermission("wow.teampvp.pairs.join")) {
                                    if (cfg_teampvp.get().getBoolean("Pairs." + args[2] + ".autobalance")) //if autobalance is on
                                    {
                                        if (cfg_teampvp.get().get("Player." + p.getName()) == null) {
                                            int team1 = 0, team2 = 0;
                                            for (Player a : Bukkit.getServer().getOnlinePlayers()) //get all player's team and calculation
                                            {
                                                if (cfg_teampvp.get().get("Pairs." + args[2]) != null) {
                                                    if (cfg_teampvp.get().get("Player." + a.getName()) != null) {
                                                        if (cfg_teampvp.get().get("Player." + a.getName()).equals(
                                                                cfg_teampvp.get().get("Pairs." + args[2] + ".team1"))) {
                                                            team1++;
                                                        } else {
                                                            if (cfg_teampvp.get().get("Player." + a.getName()).equals(
                                                                    cfg_teampvp.get().get("Pairs." + args[2] + ".team2"))) {
                                                                team2++;
                                                            }
                                                        }
                                                    }
                                                } else {
                                                    p.sendMessage(ChatColor.RED + "[TeamPVP] " + ChatColor.GRAY + "找不到此組合！");
                                                }
                                            }
                                            if (cfg_teampvp.get().get("Pairs." + args[2] + ".loc1") != null &&
                                                    cfg_teampvp.get().get("Pairs." + args[2] + ".loc2") != null) {
                                                if ((team1 == 0 && team2 == 0) || team1 <= team2) //autobalance
                                                {
                                                    Location loc1 = new Location(
                                                            Bukkit.getServer().getWorld(cfg_teampvp.get().getString("Pairs." + args[2] + ".loc1.world")),
                                                            cfg_teampvp.get().getDouble("Pairs." + args[2] + ".loc1.x"),
                                                            cfg_teampvp.get().getDouble("Pairs." + args[2] + ".loc1.y"),
                                                            cfg_teampvp.get().getDouble("Pairs." + args[2] + ".loc1.z"),
                                                            Float.valueOf(cfg_teampvp.get().getString("Pairs." + args[2] + ".loc1.yaw")),
                                                            Float.valueOf(cfg_teampvp.get().getString("Pairs." + args[2] + ".loc1.pitch"))
                                                    );
                                                    if (p.teleport(loc1)) {
                                                        cfg_teampvp.set("Player." + p.getName(), cfg_teampvp.get().get("Pairs." + args[2] +
                                                                ".team1"));
                                                        p.sendMessage(ChatColor.RED + "[TeamPVP] " + ChatColor.GRAY + "你已被分配到 " + cfg_teampvp.get().get("Pairs." + args[2] +
                                                                ".team1"));
                                                    }
                                                } else {
                                                    Location loc2 = new Location(
                                                            Bukkit.getServer().getWorld(cfg_teampvp.get().getString("Pairs." + args[2] + ".loc2.world")),
                                                            cfg_teampvp.get().getDouble("Pairs." + args[2] + ".loc2.x"),
                                                            cfg_teampvp.get().getDouble("Pairs." + args[2] + ".loc2.y"),
                                                            cfg_teampvp.get().getDouble("Pairs." + args[2] + ".loc2.z"),
                                                            Float.valueOf(cfg_teampvp.get().getString("Pairs." + args[2] + ".loc2.yaw")),
                                                            Float.valueOf(cfg_teampvp.get().getString("Pairs." + args[2] + ".loc2.pitch"))
                                                    );
                                                    if (p.teleport(loc2)) {
                                                        cfg_teampvp.set("Player." + p.getName(), cfg_teampvp.get().get("Pairs." + args[2] +
                                                                ".team2"));
                                                        p.sendMessage(ChatColor.RED + "[TeamPVP] " + ChatColor.GRAY + "你已被分配到 " + cfg_teampvp.get().get("Pairs." + args[2] +
                                                                ".team2"));
                                                    }
                                                }
                                            } else {
                                                p.sendMessage(ChatColor.RED + "[TeamPVP] " + ChatColor.GRAY + "對伍的位置尚未設置！");
                                            }
                                        } else //already in the teams
                                        {
                                            p.sendMessage(ChatColor.RED + "[TeamPVP] " + ChatColor.GRAY + "你目前已在隊伍中！");
                                        }
                                    } else //autobalance is off
                                    {
                                        p.sendMessage(ChatColor.RED + "[TeamPVP] " + ChatColor.GRAY + "此組合已關閉自動平衡，請使用手動加入！");
                                    }
                                } else {
                                    if (p.hasPermission("wow.teampvp.pairs.join") || p.hasPermission("wow.teampvp.pairs.delete")) {
                                        p.sendMessage(ChatColor.RED + "[TeamPVP] " + ChatColor.GRAY + "指令格式錯誤！");
                                    } else {
                                        p.sendMessage(ChatColor.RED + "你沒有權限使用此指令");
                                    }
                                }
                            }
                            break;
                        }
                        case 4: //manual join and loc and autobalance switch 
                        {
                            switch (args[1]) {
                                case "join": {
                                    if (p.hasPermission("wow.teampvp.pairs.join")) {
                                        if (!(cfg_teampvp.get().getBoolean("Pairs." + args[2] + ".autobalance"))) //whether autobalance is off
                                        {
                                            if (args[3].equals("1") || args[3].equals("2")) //whether enterance is 1 or 2
                                            {
                                                if (cfg_teampvp.get().get("Pairs." + args[2] + ".loc" + args[3]) != null) //whether there is a location
                                                {
                                                    Location loc = new Location(
                                                            Bukkit.getServer().getWorld(cfg_teampvp.get().getString("Pairs." + args[2] + ".loc" + args[3] + ".world")),
                                                            cfg_teampvp.get().getDouble("Pairs." + args[2] + ".loc" + args[3] + ".x"),
                                                            cfg_teampvp.get().getDouble("Pairs." + args[2] + ".loc" + args[3] + ".y"),
                                                            cfg_teampvp.get().getDouble("Pairs." + args[2] + ".loc" + args[3] + ".z"),
                                                            Float.valueOf(cfg_teampvp.get().getString("Pairs." + args[2] + ".loc" + args[3] + ".yaw")),
                                                            Float.valueOf(cfg_teampvp.get().getString("Pairs." + args[2] + ".loc" + args[3] + ".pitch"))
                                                    );
                                                    p.teleport(loc);
                                                    cfg_teampvp.set("Player." + p.getName(), cfg_teampvp.get().get("Pairs." + args[2] +
                                                            ".team" + args[3]));
                                                    p.sendMessage(ChatColor.RED + "[TeamPVP] " + ChatColor.GRAY + "你已被分配到 " + cfg_teampvp.get().get("Pairs." + args[2] +
                                                            ".team" + args[3]));
                                                } else {
                                                    p.sendMessage(ChatColor.RED + "[TeamPVP] " + ChatColor.GRAY + "對伍的位置尚未設置！");
                                                }
                                            } else {
                                                p.sendMessage(ChatColor.RED + "[TeamPVP] " + ChatColor.GRAY + "隊伍名稱只能輸入 1 或 2 ！");
                                            }

                                        } else {
                                            p.sendMessage(ChatColor.RED + "[TeamPVP] " + ChatColor.GRAY + "此組合已開啟自動平衡，只需輸入要加入的隊伍！");
                                        }
                                        return true;
                                    }
                                }
                                case "loc": {
                                    if (p.hasPermission("wow.teampvp.pairs.loc")) {
                                        if (cfg_teampvp.get().getConfigurationSection("Pairs.").getKeys(false).contains(args[2])) {
                                            if (args[3].equals("1") || args[3].equals("2")) //whether enterance is 1 or 2
                                            {
                                                cfg_teampvp.set("Pairs." + args[2] + ".loc" + args[3] + ".world", p.getLocation().getWorld().getName());
                                                cfg_teampvp.set("Pairs." + args[2] + ".loc" + args[3] + ".x", p.getLocation().getX());
                                                cfg_teampvp.set("Pairs." + args[2] + ".loc" + args[3] + ".y", p.getLocation().getY());
                                                cfg_teampvp.set("Pairs." + args[2] + ".loc" + args[3] + ".z", p.getLocation().getZ());
                                                cfg_teampvp.set("Pairs." + args[2] + ".loc" + args[3] + ".yaw", p.getLocation().getYaw());
                                                cfg_teampvp.set("Pairs." + args[2] + ".loc" + args[3] + ".pitch", p.getLocation().getPitch());
                                                p.sendMessage(ChatColor.RED + "[TeamPVP] " + ChatColor.GRAY + "已設置 " + cfg_teampvp.get().get("Pairs." + args[2] + ".team" + args[3]) + " 的位置");

                                            } else {
                                                p.sendMessage(ChatColor.RED + "[TeamPVP] " + ChatColor.GRAY + "隊伍名稱只能輸入 1 或 2 ！");
                                            }
                                        } else {
                                            p.sendMessage(ChatColor.RED + "[TeamPVP] " + ChatColor.GRAY + "找不到此組合！");
                                        }
                                        return true;
                                    }
                                }
                                case "autobalance": {
                                    if (p.hasPermission("wow.teampvp.pairs.autobalance")) {
                                        if (cfg_teampvp.get().get("Pairs." + args[2]) != null) {
                                            if (args[3].equals("true") || args[3].equals("false")) {
                                                cfg_teampvp.set("Pairs." + args[2] + ".autobalance", Boolean.parseBoolean(args[3]));
                                                p.sendMessage(ChatColor.RED + "[TeamPVP] " + ChatColor.GRAY + "已將 " + args[2] + " 的自動平衡設為 " + args[3]);
                                            } else {
                                                p.sendMessage(ChatColor.RED + "[TeamPVP] " + ChatColor.GRAY + "指令格式錯誤！");
                                            }
                                        } else {
                                            p.sendMessage(ChatColor.RED + "[TeamPVP] " + ChatColor.GRAY + "找不到此組合！");
                                        }
                                        return true;
                                    }
                                }
                                default: {
                                    if (p.hasPermission("wow.teampvp.pairs.join") || p.hasPermission("wow.teampvp.pairs.loc") ||
                                            p.hasPermission("wow.teampvp.pairs.autobalance")) {
                                        p.sendMessage(ChatColor.RED + "[TeamPVP] " + ChatColor.GRAY + "指令格式錯誤！");

                                    } else {
                                        p.sendMessage(ChatColor.RED + "你沒有權限使用此指令");
                                    }
                                    return true;
                                }
                            }
                        }
                        case 5: //pairs create
                        {
                            if (args[1].equals("create") && p.hasPermission("wow.teampvp.pairs.create")) {
                                if (cfg_teampvp.get().contains("Teams." + args[3]) && cfg_teampvp.get().contains("Teams." + args[4])) {
                                    cfg_teampvp.newpair(args[2], args[3], args[4]);
                                    p.sendMessage(ChatColor.RED + "[TeamPVP] " + ChatColor.GRAY + "已將 " +
                                            args[3] + " 和 " + args[4] + " 加入到 " + args[2]);
                                } else {
                                    p.sendMessage(ChatColor.RED + "[TeamPVP] " + ChatColor.GRAY + "找不到此隊伍！");
                                }
                            } else {
                                if (p.hasPermission("wow.teampvp.pairs.create")) {
                                    p.sendMessage(ChatColor.RED + "[TeamPVP] " + ChatColor.GRAY + "指令格式錯誤！");
                                } else {
                                    p.sendMessage(ChatColor.RED + "你沒有權限使用此指令");
                                }
                            }
                            break;
                        }
                        default: //can't find command
                        {
                            p.sendMessage(ChatColor.RED + "[TeamPVP] " + ChatColor.GRAY + "找不到此指令！");
                        }
                        break;
                    }
                }
            } else {
                if (p.hasPermission("wow.teampvp.help")) //show help messages
                {
                    p.sendMessage(ChatColor.RED + "-------------[TeamPVP]-------------");
                    p.sendMessage(ChatColor.GRAY + " ");
                    p.sendMessage(ChatColor.GRAY + "/teampvp create <名稱> - 新增隊伍");
                    p.sendMessage(ChatColor.GRAY + "/teampvp delete <名稱> - 刪除隊伍");
                    p.sendMessage(ChatColor.GRAY + "/teampvp add <名稱> <玩家> - 將玩家加入而隊伍中");
                    p.sendMessage(ChatColor.GRAY + "/teampvp remove <名稱> <玩家> - 將玩家從隊伍中移除");
                    p.sendMessage(ChatColor.GRAY + "/teampvp setflag <名稱> <標籤> <True/false> - 設定隊伍標籤");
                    p.sendMessage(ChatColor.GRAY + "/teampvp list - 顯示所有隊伍");
                    p.sendMessage(ChatColor.GRAY + "--------------------------------------------------");
                    p.sendMessage(ChatColor.GRAY + "/teampvp pairs create <名稱> <隊伍一> <隊伍二> - 新增隊伍組合");
                    p.sendMessage(ChatColor.GRAY + "/teampvp pairs delete <名稱> - 刪除隊伍組合");
                    p.sendMessage(ChatColor.GRAY + "/teampvp pairs join <名稱> [隊伍] - 加入隊伍組合");
                    p.sendMessage(ChatColor.GRAY + "/teampvp pairs loc <名稱> <隊伍> - 設至隊伍組合位置");
                    p.sendMessage(ChatColor.GRAY + "/teampvp pairs autobalance <名稱> <True/False> - 設至是否啟用自動平衡");
                    p.sendMessage(ChatColor.GRAY + "/teampvp pairs list - 顯示所有隊伍組合");
                } else //no permission
                {
                    p.sendMessage(ChatColor.RED + "你沒有權限使用此指令");
                }
            }
        } else //no permission
        {
            p.sendMessage(ChatColor.RED + "你沒有權限使用此指令");
        }
        return false;
    }
}