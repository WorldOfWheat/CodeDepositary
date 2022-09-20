package com.wow.customban;

import com.wow.customban.api.api_customban_time;
import org.bukkit.Bukkit;
import org.bukkit.ChatColor;
import org.bukkit.command.Command;
import org.bukkit.command.CommandExecutor;
import org.bukkit.command.CommandSender;
import org.bukkit.entity.Player;

import java.util.ArrayList;


public final class cmd_customban implements CommandExecutor {
    public boolean onCommand(CommandSender sender, Command cmd, String lable, String[] args) {
        if (sender instanceof Player) {
            Player p = (Player) sender;
            /////////////////////////////////////////////////////////////////////////////
            if (lable.equalsIgnoreCase("customban")) {
                switch (args.length) {
                    case 0: //help
                    {
                        if (p.hasPermission("wow.customban.help")) {
                            p.sendMessage(ChatColor.RED + "-------------[CustomBan]-------------");
                            p.sendMessage(ChatColor.GRAY + " ");
                            p.sendMessage(ChatColor.GRAY + "/customban frezze <玩家> [原因] - 凍結玩家");
                            p.sendMessage(ChatColor.GRAY + "/customban unfrezze <玩家> - 解除凍結玩家");
                            p.sendMessage(ChatColor.GRAY + "/customban frezzelist - 列出所有被凍結的玩家");
                            p.sendMessage(ChatColor.GRAY + "/customban warn <玩家> <原因> - 警告玩家");
                            p.sendMessage(ChatColor.GRAY + "/customban delwarn <玩家> <編號/all> - 刪除玩家的警告");
                            p.sendMessage(ChatColor.GRAY + "/customban warnlist [玩家] - 列出玩家的警告及原因");
                            p.sendMessage(ChatColor.GRAY + "/customban kick <玩家> [原因] - 踢出玩家");
                            p.sendMessage(ChatColor.GRAY + "/customban ban <玩家> [原因] - 封鎖玩家");
                            p.sendMessage(ChatColor.GRAY + "/customban tempban <玩家> <原因> <DD:HH:MM> - 暫時封鎖玩家");
                            p.sendMessage(ChatColor.GRAY + "/customban unban <玩家> - 解除玩家封鎖");
                            p.sendMessage(ChatColor.GRAY + "/customban banlist - 列出所有被封鎖的玩家");
                        } else //no permission
                        {
                            p.sendMessage(ChatColor.RED + "你沒有權限使用此指令");
                        }
                        break;
                    }
                    case 1: {
                        switch (args[0]) {
                            case "frezzelist": //frezze list
                            {
                                if (p.hasPermission("wow.customban.frezzelist")) {
                                    if (cfg_customban.get().getConfigurationSection("Frezze") != null) //check if the frezze isn't empty
                                    {
                                        p.sendMessage(ChatColor.RED + "[CustomBan] " + ChatColor.GRAY + "所有被凍結的玩家：");
                                        for (Object a : cfg_customban.get().getList("Frezze")) //get all frezzed players
                                        {
                                            p.sendMessage(ChatColor.RED + "[CustomBan] " + ChatColor.GRAY + a);
                                        }
                                    } else {
                                        p.sendMessage(ChatColor.RED + "[CustomBan] " + ChatColor.GRAY + "目前沒有任何玩家被凍結！");
                                    }
                                    return true;
                                }
                            }
                            case "banlist": //ban list
                            {
                                if (p.hasPermission("wow.customban.banlist")) {
                                    if (cfg_customban.get().getConfigurationSection("Ban") != null) //check if the banlist isn't empty
                                    {
                                        p.sendMessage(ChatColor.RED + "[CustomBan] " + ChatColor.GRAY + "所有被封鎖的玩家：");
                                        for (Object a : cfg_customban.get().getList("Ban")) //get all banned players
                                        {
                                            p.sendMessage(ChatColor.RED + "[CustomBan] " + ChatColor.GRAY + a);
                                        }
                                    } else {
                                        p.sendMessage(ChatColor.RED + "[CustomBan] " + ChatColor.GRAY + "目前沒有任何玩家被封鎖！");
                                    }
                                    return true;
                                }
                            }
                            case "warnlist": //warnlist
                            {
                                if (p.hasPermission("wow.customban.warnlist")) {
                                    if ((cfg_customban.get().getConfigurationSection("Warn.players." + p.getName())) != null) //check if the warnlist is empty
                                    {
                                        int max = 1;
                                        for (String a : cfg_customban.get().getConfigurationSection("Warn.players." + p.getName()).getKeys(false)) //get times of the player's warns
                                        {
                                            max += 1;
                                        }
                                        p.sendMessage(ChatColor.RED + "[CustomBan] " + ChatColor.GRAY + "警告記錄：");
                                        for (int i = 1; i < max; i++) //show all warns with number
                                        {
                                            p.sendMessage(ChatColor.AQUA + "[" + i + "] " + (String) cfg_customban.get().get("Warn.players." + p.getName() + "." + i));
                                        }
                                    } else //player doesn't have any warn
                                    {
                                        p.sendMessage(ChatColor.RED + "[CustomBan] " + ChatColor.GRAY + "此玩家沒有任何的警告記錄！");
                                    }
                                    return true;
                                }
                            }
                            default: {
                                if (p.hasPermission("wow.customban.banlist") || p.hasPermission("wow.customban.frezzelist") ||
                                        p.hasPermission("wow.customban.warnlist")) //format error
                                {
                                    p.sendMessage(ChatColor.RED + "[CustomBan] " + ChatColor.GRAY + "指令格式錯誤！");
                                } else //no permission
                                {
                                    p.sendMessage(ChatColor.RED + "你沒有權限使用此指令");
                                }
                                return true;
                            }
                        }
                    }
                    case 2: {
                        switch (args[0]) {
                            case "frezze": //frezze no reason
                            {
                                if (p.hasPermission("wow.customban.frezze")) {
                                    if (cfg_customban.setfrezze(args[1], true)) //set player to frezze list
                                    {
                                        p.sendMessage(ChatColor.RED + "[CustomBan] " + ChatColor.GRAY + "成功凍結 " + args[1]);
                                        if (Bukkit.getServer().getPlayer(args[1]) != null) //If the player is online, notify that he is frezzed.
                                        {
                                            Bukkit.getServer().getPlayer(args[1]).sendMessage(ChatColor.DARK_GRAY + "» " + ChatColor.RED + "警告！ 你目前已被 "
                                                    + ChatColor.YELLOW + p.getName() + ChatColor.RED + " 凍結！");
                                        }
                                    } else //already
                                    {
                                        p.sendMessage(ChatColor.RED + "[CustomBan] " + ChatColor.GRAY + "此玩家已經被凍結！");
                                    }
                                    return true;
                                }
                            }
                            case "unfrezze": //unfrezze
                            {
                                if (p.hasPermission("wow.customban.unfrezze")) {
                                    if (cfg_customban.setfrezze(args[1], false)) //remove the player from frezze list
                                    {
                                        p.sendMessage(ChatColor.RED + "[CustomBan] " + ChatColor.GRAY + "成功解凍 " + args[1]);
                                        if (Bukkit.getServer().getPlayer(args[1]) != null) //If the player is online, notify that he is frezzed.
                                        {
                                            Bukkit.getServer().getPlayer(args[1]).sendMessage(ChatColor.DARK_GRAY + "» " + ChatColor.GREEN + "你已被解除凍結。");
                                        }
                                    } else //can't find
                                    {
                                        p.sendMessage(ChatColor.RED + "[CustomBan] " + ChatColor.GRAY + "此玩家未被凍結！");
                                    }
                                    return true;
                                }
                            }
                            case "warnlist": //warnlist other
                            {
                                if (p.hasPermission("wow.customban.warnlist.other")) {
                                    if ((cfg_customban.get().getConfigurationSection("Warn.players." + args[1])) != null) //check if the warnlist is empty
                                    {
                                        int max = 1;
                                        for (String a : cfg_customban.get().getConfigurationSection("Warn.players." + args[1]).getKeys(false)) //get times of the player's warns
                                        {
                                            max += 1;
                                        }
                                        p.sendMessage(ChatColor.RED + "[CustomBan] " + ChatColor.GRAY + "警告記錄：");
                                        for (int i = 1; i < max; i++) //show all warns with number
                                        {
                                            p.sendMessage(ChatColor.AQUA + "[" + i + "] " + (String) cfg_customban.get().get("Warn.players." + args[1] + "." + i));
                                        }
                                    } else //player doesn't have any warn
                                    {
                                        p.sendMessage(ChatColor.RED + "[CustomBan] " + ChatColor.GRAY + "此玩家沒有任何的警告記錄！");
                                    }
                                    return true;
                                }
                            }
                            case "kick": // kick no reason
                            {
                                if (p.hasPermission("wow.customban.kick")) {
                                    if (Bukkit.getServer().getPlayer(args[1]) != null) //check if player is online
                                    {
                                        Player target = Bukkit.getServer().getPlayer(args[1]);
                                        p.sendMessage(ChatColor.RED + "[CustomBan] " + ChatColor.GRAY + "成功踢出玩家 " + target.getName());
                                        target.kickPlayer(ChatColor.WHITE + "▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂\n\n" +
                                                ChatColor.RED + "你已被管理員 " + ChatColor.YELLOW + p.getName() + ChatColor.RED + " 踢出伺服器！" +
                                                ChatColor.WHITE + "\n\n▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂");
                                    } else //can't find
                                    {
                                        p.sendMessage(ChatColor.RED + "[CustomBan] " + ChatColor.GRAY + "找不到此玩家！");
                                    }
                                    return true;
                                }
                            }
                            case "ban": //ban no reason
                            {
                                if (p.hasPermission("wow.customban.ban")) {
                                    Player target = Bukkit.getServer().getPlayer(args[1]);
                                    cfg_customban.setban(target.getName(), p.getName(), null, 0);
                                    //kick player with message
                                    target.kickPlayer(ChatColor.WHITE + "▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂\n\n" +
                                            ChatColor.RED + "你已被管理員 " + ChatColor.YELLOW + p.getName() + ChatColor.RED + " 封鎖！" +
                                            ChatColor.WHITE + "\n\n▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂");
                                    p.sendMessage(ChatColor.RED + "[CustomBan] " + ChatColor.DARK_RED + "成功封鎖玩家 " + target.getName());
                                    for (Player a : Bukkit.getServer().getOnlinePlayers()) //broadcast that the player is banned
                                    {
                                        a.sendMessage(ChatColor.DARK_GRAY + "» " + ChatColor.YELLOW + p.getName() + ChatColor.RED + " 已被管理員 " + ChatColor.YELLOW +
                                                p.getName() + ChatColor.RED + " 封鎖！");
                                    }
                                    return true;
                                }
                            }
                            case "unban": //unban
                            {
                                if (p.hasPermission("wow.customban.unban")) {
                                    if (cfg_customban.get().getConfigurationSection("Ban").getKeys(false).contains(args[1])) //check if player is banned
                                    {
                                        cfg_customban.set("Ban." + args[1], null); //remove from banlist
                                        p.sendMessage(ChatColor.RED + "[CustomBan] " + ChatColor.GRAY + "成功解除封鎖 " + args[1]);
                                    } else //can't find
                                    {
                                        p.sendMessage(ChatColor.RED + "[CustomBan] " + ChatColor.GRAY + "找不到此玩家！");
                                    }
                                    return true;
                                }
                            }
                            default: {
                                if (p.hasPermission("wow.customban.kick") || p.hasPermission("wow.customban.warnlist.other") ||
                                        p.hasPermission("wow.customban.unfrezze") || p.hasPermission("wow.customban.frezze") ||
                                        p.hasPermission("wow.customban.ban") || p.hasPermission("wow.customban.unban")) //format error
                                {
                                    p.sendMessage(ChatColor.RED + "[CustomBan] " + ChatColor.GRAY + "指令格式錯誤！");
                                } else //no permission
                                {
                                    p.sendMessage(ChatColor.RED + "你沒有權限使用此指令");
                                }
                                return true;
                            }
                        }
                    }
                    case 3: {
                        switch (args[0]) {
                            case "frezze": //frezze
                            {
                                if (p.hasPermission("wow.customban.frezze")) {
                                    if (cfg_customban.setfrezze(args[1], true)) //check if the player is already frezzed
                                    {
                                        p.sendMessage(ChatColor.RED + "[CustomBan] " + ChatColor.GRAY + "成功凍結 " + args[1] + "。 原因： " + args[2]);
                                        if (Bukkit.getServer().getPlayer(args[1]) != null) //If the player is online, notify that he is frezzed.
                                        {
                                            Bukkit.getServer().getPlayer(args[1]).sendMessage(ChatColor.DARK_GRAY + "» " + ChatColor.RED + "警告！ 你目前已被 "
                                                    + ChatColor.YELLOW + p.getName() + ChatColor.RED + " 凍結！ 原因： " + args[2]);
                                        }
                                    } else //already
                                    {
                                        p.sendMessage(ChatColor.RED + "[CustomBan] " + ChatColor.GRAY + "此玩家已經被凍結！");
                                    }
                                    return true;
                                }
                            }
                            case "warn": //warn
                            {
                                if (p.hasPermission("wow.customban.warn")) {
                                    if (cfg_customban.get().get("Warn.players." + args[1]) != null) //check if the player has been warned (second time)
                                    {
                                        int max = 1;
                                        for (Object a : cfg_customban.get().getConfigurationSection("Warn.players." + args[1]).getKeys(false)) //get times
                                        {
                                            max += 1;
                                        }
                                        cfg_customban.set("Warn.players." + args[1] + "." + max, args[2]); //set new warn
                                        p.sendMessage(ChatColor.RED + "[CustomBan] " + ChatColor.GRAY + "成功記 " + args[1] + " 一支警告(" + max + ")。 原因： " + args[2]);
                                        if (Bukkit.getServer().getPlayer(args[1]) != null) //If the player is online, notify that he is warned.
                                        {
                                            if (cfg_customban.get().getBoolean("Warn.kick")) {
                                                Bukkit.getServer().getPlayer(args[1]).kickPlayer(ChatColor.WHITE + "▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂\n\n" +
                                                        ChatColor.RED + "你已遭到管理員警告（" + max + "）！\n" + "原因： " + args[2] + ChatColor.WHITE + "\n\n▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂");
                                            } else {
                                                Bukkit.getServer().getPlayer(args[1]).sendMessage(ChatColor.DARK_GRAY + "» " + ChatColor.RED + "你已遭到 "
                                                        + ChatColor.YELLOW + p.getName() + ChatColor.RED + " 警告！ 原因： " + args[2] + "。你目前有 " + max + " 次警告！");
                                            }
                                        }
                                        if (cfg_customban.get().getInt("Warn.maxwarn") <= max) //!!!! be worked
                                        {
                                            cfg_customban.setban(args[1], "CONSOLE", "警告已達到 " + max + " 支", 0);
                                            Bukkit.getServer().getPlayer(args[1]).kickPlayer(ChatColor.WHITE + "▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂\n\n" +
                                                    ChatColor.RED + "你已被管理員 " + ChatColor.YELLOW + "CONSOLE" + ChatColor.RED + " 封鎖！  \n原因： " + "警告已達到 " + max + " 支" +
                                                    ChatColor.WHITE + "\n\n▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂");
                                        }
                                    } else //first time
                                    {
                                        cfg_customban.set("Warn.players." + args[1] + "." + 1, args[2]);
                                        p.sendMessage(ChatColor.RED + "[CustomBan] " + ChatColor.GRAY + "成功記 " + args[1] + " 一支警告(1)。 原因： " + args[2]);
                                        if (Bukkit.getServer().getPlayer(args[1]) != null) //If the player is online, notify that he is warned.
                                        {
                                            if (cfg_customban.get().getBoolean("Warn.kick")) {
                                                Bukkit.getServer().getPlayer(args[1]).kickPlayer(ChatColor.WHITE + "▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂\n\n" +
                                                        ChatColor.RED + "你已遭到管理員警告（" + 1 + "）！\n" + "原因： " + args[2] + ChatColor.WHITE + "\n\n▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂");
                                            } else {
                                                Bukkit.getServer().getPlayer(args[1]).sendMessage(ChatColor.DARK_GRAY + "» " + ChatColor.RED + "你已遭到 "
                                                        + ChatColor.YELLOW + p.getName() + ChatColor.RED + " 警告！ 原因： " + args[2] + "。你目前有 1 次警告！");
                                            }
                                        }
                                    }
                                    return true;
                                }
                            }
                            case "delwarn": //delwarn
                            {
                                if (p.hasPermission("wow.customban.delwarn")) {
                                    if (cfg_customban.get().get("Warn.players." + args[1]) != null) //check if player has any warns
                                    {
                                        if (cfg_customban.get().getConfigurationSection("Warn.players." + args[1]).getKeys(false).contains(args[2])) //switch single or all
                                        {
                                            //send message to sender
                                            p.sendMessage(ChatColor.RED + "[CustomBan] " + ChatColor.GRAY + "成功刪除 " + args[1] + " 的警告。 " +
                                                    ChatColor.AQUA + "[" + args[2] + "] " + cfg_customban.get().get("Warn.players." + args[1] + "." + args[2]));
                                            //send message to target
                                            if (Bukkit.getServer().getPlayer(args[1]) != null) //If the player is online, notify that there's a warn be removed.
                                            {
                                                Bukkit.getServer().getPlayer(args[1]).sendMessage(ChatColor.DARK_GRAY + "» " + ChatColor.GREEN + "你有一支警告已被消除。 " +
                                                        ChatColor.AQUA + "[" + args[2] + "] " + cfg_customban.get().get("Warn.players." + args[1] + "." + args[2]));
                                            }
                                            //main code
                                            cfg_customban.set("Warn.players." + args[1] + "." + args[2], null); //remove the warn
                                            ArrayList<String> reason = new ArrayList();
                                            int max = 0;
                                            for (String b : cfg_customban.get().getConfigurationSection("Warn.players." + args[1]).getKeys(false)) //get all reason and max times
                                            {
                                                reason.add((String) cfg_customban.get().get("Warn.players." + args[1] + "." + b));
                                                max++;
                                            }
                                            cfg_customban.set("Warn.players." + args[1], null); //clear all warns
                                            for (int i = 1; i <= max; i++) //put all warns back
                                            {
                                                cfg_customban.set("Warn.players." + args[1] + "." + i, reason.get(i - 1));
                                            }
                                        } else {
                                            if (args[2].equals("all")) //args[2] is "all"
                                            {
                                                cfg_customban.set("Warn.players." + args[1], null);
                                                p.sendMessage(ChatColor.RED + "[CustomBan] " + ChatColor.GRAY + "成功刪除 " + args[1] + " 的所有警告。");
                                                if (Bukkit.getServer().getPlayer(args[1]) != null) //If the player is online, notify that all of the warns are be removed.
                                                {
                                                    Bukkit.getServer().getPlayer(args[1]).sendMessage(ChatColor.DARK_GRAY + "» " + ChatColor.GREEN + "你的所有警告已被消除。");
                                                }
                                            } else {
                                                p.sendMessage(ChatColor.RED + "[CustomBan] " + ChatColor.GRAY + "找不到此編號！");
                                            }
                                        }
                                    } else {
                                        p.sendMessage(ChatColor.RED + "[CustomBan] " + ChatColor.GRAY + "此玩家沒有任何的警告記錄！");
                                    }
                                    return true;
                                }
                            }
                            case "kick": //kick
                            {
                                if (p.hasPermission("wow.customban.kick")) {
                                    if (Bukkit.getServer().getPlayer(args[1]) != null) //check if the player is online
                                    {
                                        Player target = Bukkit.getServer().getPlayer(args[1]);
                                        p.sendMessage(ChatColor.RED + "[CustomBan] " + ChatColor.GRAY + "成功踢出玩家 " + target.getName() +
                                                "。 原因： " + args[2]);
                                        //-----------------------
                                        target.kickPlayer(ChatColor.WHITE + "▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂\n\n" +
                                                ChatColor.RED + "你已被管理員 " + ChatColor.YELLOW +
                                                p.getName() + ChatColor.RED + " 踢出伺服器！\n原因： " +
                                                args[2] + ChatColor.WHITE + "\n\n▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂");
                                    } else {
                                        p.sendMessage(ChatColor.RED + "[CustomBan] " + ChatColor.GRAY + "找不到此玩家！");
                                    }
                                    return true;
                                }
                            }
                            case "ban": //ban
                            {
                                if (p.hasPermission("wow.customban.ban")) {
                                    Player target = Bukkit.getServer().getPlayer(args[1]);
                                    cfg_customban.setban(target.getName(), p.getName(), args[2], 0);
                                    //kick player with message
                                    target.kickPlayer(ChatColor.WHITE + "▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂\n\n" +
                                            ChatColor.RED + "你已被管理員 " + ChatColor.YELLOW + p.getName() + ChatColor.RED + " 封鎖！  \n原因： " + args[2] +
                                            ChatColor.WHITE + "\n\n▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂");
                                    p.sendMessage(ChatColor.RED + "[CustomBan] " + ChatColor.DARK_RED + "成功封鎖玩家 " + target.getName() + "。 原因： " + args[2]);
                                    //broadcast that the player is banned
                                    for (Player a : Bukkit.getServer().getOnlinePlayers()) {
                                        a.sendMessage(ChatColor.DARK_GRAY + "» " + ChatColor.YELLOW + p.getName() + ChatColor.RED + " 已被管理員 " + ChatColor.YELLOW +
                                                p.getName() + ChatColor.RED + " 封鎖！ 原因： " + args[2]);
                                    }
                                    return true;
                                }
                            }
                            default: {
                                if (p.hasPermission("wow.customban.kick") || p.hasPermission("wow.customban.delwarn") ||
                                        p.hasPermission("wow.customban.warn") || p.hasPermission("wow.customban.frezze") ||
                                        p.hasPermission("wow.customban.ban")) //format error
                                {
                                    p.sendMessage(ChatColor.RED + "[CustomBan] " + ChatColor.GRAY + "指令格式錯誤！");
                                } else //no permission
                                {
                                    p.sendMessage(ChatColor.RED + "你沒有權限使用此指令");
                                }
                                return true;
                            }
                        }
                    }
                    case 4: {
                        if (args[0].equals("tempban") && p.hasPermission("wow.customban.tempban")) {
                            Player target = Bukkit.getServer().getPlayer(args[1]);
                            cfg_customban.setban(target.getName(), p.getName(), args[2], new api_customban_time().tomillisecond_withcmd(args[3]));
                            //kick player with message
                            target.kickPlayer(ChatColor.WHITE + "▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂\n\n" +
                                    ChatColor.RED + "你已被管理員 " + ChatColor.YELLOW + p.getName() + ChatColor.RED + " 暫時封鎖！" +
                                    "\n原因： " + args[2] + "\n時間： " + cfg_customban.get().get("Ban." + target.getName() + ".expired") +
                                    ChatColor.WHITE + "\n\n▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂");
                            //send message to sender
                            p.sendMessage(ChatColor.RED + "[CustomBan] " + ChatColor.DARK_RED + "成功暫時封鎖玩家 " + target.getName() +
                                    "。 原因： " + args[2] + " 時間： " + cfg_customban.get().get("Ban." + target.getName() + ".expired"));
                            //broadcast that the player is banned
                            for (Player a : Bukkit.getServer().getOnlinePlayers()) {
                                a.sendMessage(ChatColor.DARK_GRAY + "» " + ChatColor.YELLOW + p.getName() + ChatColor.RED + " 已被管理員 " + ChatColor.YELLOW +
                                        p.getName() + ChatColor.RED + " 暫時封鎖！ 原因： " + args[2] + " 時間： " + cfg_customban.get().get("Ban." + target.getName() + ".expired"));
                            }
                            return true;
                        } else {
                            if (p.hasPermission("wow.customban.tempban")) //format error
                            {

                                p.sendMessage(ChatColor.RED + "[CustomBan] " + ChatColor.GRAY + "指令格式錯誤！");
                            } else //no permission
                            {
                                p.sendMessage(ChatColor.RED + "你沒有權限使用此指令");
                            }
                        }
                    }
                    default: {
                        break;
                    }
                }
            }
        } else {
            if (lable.equalsIgnoreCase("customban")) {
                switch (args.length) {
                    case 0: //help
                    {
                        Bukkit.getLogger().info(ChatColor.RED + "-------------[CustomBan]-------------");
                        Bukkit.getLogger().info(ChatColor.GRAY + " ");
                        Bukkit.getLogger().info(ChatColor.GRAY + "/customban frezze <玩家> [原因] - 凍結玩家");
                        Bukkit.getLogger().info(ChatColor.GRAY + "/customban unfrezze <玩家> - 解除凍結玩家");
                        Bukkit.getLogger().info(ChatColor.GRAY + "/customban frezzelist - 列出所有被凍結的玩家");
                        Bukkit.getLogger().info(ChatColor.GRAY + "/customban warn <玩家> <原因> - 警告玩家");
                        Bukkit.getLogger().info(ChatColor.GRAY + "/customban delwarn <玩家> <編號/all> - 刪除玩家的警告");
                        Bukkit.getLogger().info(ChatColor.GRAY + "/customban warnlist [玩家] - 列出玩家的警告及原因");
                        Bukkit.getLogger().info(ChatColor.GRAY + "/customban kick <玩家> [原因] - 踢出玩家");
                        Bukkit.getLogger().info(ChatColor.GRAY + "/customban ban <玩家> [原因] - 封鎖玩家");
                        Bukkit.getLogger().info(ChatColor.GRAY + "/customban tempban <玩家> <原因> <DD:HH:MM> - 暫時封鎖玩家");
                        Bukkit.getLogger().info(ChatColor.GRAY + "/customban unban <玩家> - 解除玩家封鎖");
                        Bukkit.getLogger().info(ChatColor.GRAY + "/customban banlist - 列出所有被封鎖的玩家");
                        break;
                    }
                    case 1: {
                        switch (args[0]) {
                            case "frezzelist": //frezze list
                            {
                                if (cfg_customban.get().getConfigurationSection("Frezze") != null) //check if the frezze isn't empty
                                {
                                    Bukkit.getLogger().info(ChatColor.RED + "[CustomBan] " + ChatColor.GRAY + "所有被凍結的玩家：");
                                    for (Object a : cfg_customban.get().getList("Frezze")) //get all frezzed players
                                    {
                                        Bukkit.getLogger().info(ChatColor.RED + "[CustomBan] " + ChatColor.GRAY + a);
                                    }
                                } else {
                                    Bukkit.getLogger().info(ChatColor.RED + "[CustomBan] " + ChatColor.GRAY + "目前沒有任何玩家被凍結！");
                                }
                                return true;

                            }
                            case "banlist": //ban list
                            {
                                if (cfg_customban.get().getConfigurationSection("Ban") != null) //check if the banlist isn't empty
                                {
                                    Bukkit.getLogger().info(ChatColor.RED + "[CustomBan] " + ChatColor.GRAY + "所有被封鎖的玩家：");
                                    for (Object a : cfg_customban.get().getList("Ban")) //get all banned players
                                    {
                                        Bukkit.getLogger().info(ChatColor.RED + "[CustomBan] " + ChatColor.GRAY + a);
                                    }
                                } else {
                                    Bukkit.getLogger().info(ChatColor.RED + "[CustomBan] " + ChatColor.GRAY + "目前沒有任何玩家被封鎖！");
                                }
                                return true;
                            }
                            case "warnlist": //warnlist
                            {
                                if ((cfg_customban.get().getConfigurationSection("Warn.players." + "CONSOLE")) != null) //check if the warnlist is empty
                                {
                                    int max = 1;
                                    for (String a : cfg_customban.get().getConfigurationSection("Warn.players." + "CONSOLE").getKeys(false)) //get times of the player's warns
                                    {
                                        max += 1;
                                    }
                                    Bukkit.getLogger().info(ChatColor.RED + "[CustomBan] " + ChatColor.GRAY + "警告記錄：");
                                    for (int i = 1; i < max; i++) //show all warns with number
                                    {
                                        Bukkit.getLogger().info(ChatColor.AQUA + "[" + i + "] " + (String) cfg_customban.get().get("Warn.players." + "CONSOLE" + "." + i));
                                    }
                                } else //player doesn't have any warn
                                {
                                    Bukkit.getLogger().info(ChatColor.RED + "[CustomBan] " + ChatColor.GRAY + "此玩家沒有任何的警告記錄！");
                                }
                                return true;
                            }
                            default: {
                                Bukkit.getLogger().info(ChatColor.RED + "[CustomBan] " + ChatColor.GRAY + "指令格式錯誤！");
                                return true;
                            }
                        }
                    }
                    case 2: {
                        switch (args[0]) {
                            case "frezze": //frezze no reason
                            {
                                if (cfg_customban.setfrezze(args[1], true)) //set player to frezze list
                                {
                                    Bukkit.getLogger().info(ChatColor.RED + "[CustomBan] " + ChatColor.GRAY + "成功凍結 " + args[1]);
                                    if (Bukkit.getServer().getPlayer(args[1]) != null) //If the player is online, notify that he is frezzed.
                                    {
                                        Bukkit.getServer().getPlayer(args[1]).sendMessage(ChatColor.DARK_GRAY + "» " + ChatColor.RED + "警告！ 你目前已被 "
                                                + ChatColor.YELLOW + "CONSOLE" + ChatColor.RED + " 凍結！");
                                    }
                                } else //already
                                {
                                    Bukkit.getLogger().info(ChatColor.RED + "[CustomBan] " + ChatColor.GRAY + "此玩家已經被凍結！");
                                }
                                return true;
                            }
                            case "unfrezze": //unfrezze
                            {
                                if (cfg_customban.setfrezze(args[1], false)) //remove the player from frezze list
                                {
                                    Bukkit.getLogger().info(ChatColor.RED + "[CustomBan] " + ChatColor.GRAY + "成功解凍 " + args[1]);
                                    if (Bukkit.getServer().getPlayer(args[1]) != null) //If the player is online, notify that he is frezzed.
                                    {
                                        Bukkit.getServer().getPlayer(args[1]).sendMessage(ChatColor.DARK_GRAY + "» " + ChatColor.GREEN + "你已被解除凍結。");
                                    }
                                } else //can't find
                                {
                                    Bukkit.getLogger().info(ChatColor.RED + "[CustomBan] " + ChatColor.GRAY + "此玩家未被凍結！");
                                }
                                return true;
                            }
                            case "warnlist": //warnlist other
                            {
                                if ((cfg_customban.get().getConfigurationSection("Warn.players." + args[1])) != null) //check if the warnlist is empty
                                {
                                    int max = 1;
                                    for (String a : cfg_customban.get().getConfigurationSection("Warn.players." + args[1]).getKeys(false)) //get times of the player's warns
                                    {
                                        max += 1;
                                    }
                                    Bukkit.getLogger().info(ChatColor.RED + "[CustomBan] " + ChatColor.GRAY + "警告記錄：");
                                    for (int i = 1; i < max; i++) //show all warns with number
                                    {
                                        Bukkit.getLogger().info(ChatColor.AQUA + "[" + i + "] " + (String) cfg_customban.get().get("Warn.players." + args[1] + "." + i));
                                    }
                                } else //player doesn't have any warn
                                {
                                    Bukkit.getLogger().info(ChatColor.RED + "[CustomBan] " + ChatColor.GRAY + "此玩家沒有任何的警告記錄！");
                                }
                                return true;
                            }
                            case "kick": // kick no reason
                            {
                                if (Bukkit.getServer().getPlayer(args[1]) != null) //check if player is online
                                {
                                    Player target = Bukkit.getServer().getPlayer(args[1]);
                                    Bukkit.getLogger().info(ChatColor.RED + "[CustomBan] " + ChatColor.GRAY + "成功踢出玩家 " + target.getName());
                                    target.kickPlayer(ChatColor.WHITE + "▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂\n\n" +
                                            ChatColor.RED + "你已被管理員 " + ChatColor.YELLOW + "CONSOLE" + ChatColor.RED + " 踢出伺服器！" +
                                            ChatColor.WHITE + "\n\n▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂");
                                } else //can't find
                                {
                                    Bukkit.getLogger().info(ChatColor.RED + "[CustomBan] " + ChatColor.GRAY + "找不到此玩家！");
                                }
                                return true;
                            }
                            case "ban": //ban no reason
                            {
                                Player target = Bukkit.getServer().getPlayer(args[1]);
                                cfg_customban.setban(target.getName(), "CONSOLE", null, 0);
                                //kick player with message
                                target.kickPlayer(ChatColor.WHITE + "▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂\n\n" +
                                        ChatColor.RED + "你已被管理員 " + ChatColor.YELLOW + "CONSOLE" + ChatColor.RED + " 封鎖！" +
                                        ChatColor.WHITE + "\n\n▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂");
                                Bukkit.getLogger().info(ChatColor.RED + "[CustomBan] " + ChatColor.DARK_RED + "成功封鎖玩家 " + target.getName());
                                for (Player a : Bukkit.getServer().getOnlinePlayers()) //broadcast that the player is banned
                                {
                                    a.sendMessage(ChatColor.DARK_GRAY + "» " + ChatColor.YELLOW + "CONSOLE" + ChatColor.RED + " 已被管理員 " + ChatColor.YELLOW +
                                            "CONSOLE" + ChatColor.RED + " 封鎖！");
                                }
                                return true;
                            }
                            case "unban": //unban
                            {
                                if (cfg_customban.get().getConfigurationSection("Ban").getKeys(false).contains(args[1])) //check if player is banned
                                {
                                    cfg_customban.set("Ban." + args[1], null); //remove from banlist
                                    Bukkit.getLogger().info(ChatColor.RED + "[CustomBan] " + ChatColor.GRAY + "成功解除封鎖 " + args[1]);
                                } else //can't find
                                {
                                    Bukkit.getLogger().info(ChatColor.RED + "[CustomBan] " + ChatColor.GRAY + "找不到此玩家！");
                                }
                                return true;
                            }
                            default: {
                                Bukkit.getLogger().info(ChatColor.RED + "[CustomBan] " + ChatColor.GRAY + "指令格式錯誤！");
                                return true;
                            }
                        }
                    }
                    case 3: {
                        switch (args[0]) {
                            case "frezze": //frezze
                            {
                                if (cfg_customban.setfrezze(args[1], true)) //check if the player is already frezzed
                                {
                                    Bukkit.getLogger().info(ChatColor.RED + "[CustomBan] " + ChatColor.GRAY + "成功凍結 " + args[1] + "。 原因： " + args[2]);
                                    if (Bukkit.getServer().getPlayer(args[1]) != null) //If the player is online, notify that he is frezzed.
                                    {
                                        Bukkit.getServer().getPlayer(args[1]).sendMessage(ChatColor.DARK_GRAY + "» " + ChatColor.RED + "警告！ 你目前已被 "
                                                + ChatColor.YELLOW + "CONSOLE" + ChatColor.RED + " 凍結！ 原因： " + args[2]);
                                    }
                                } else //already
                                {
                                    Bukkit.getLogger().info(ChatColor.RED + "[CustomBan] " + ChatColor.GRAY + "此玩家已經被凍結！");
                                }
                                return true;
                            }
                            case "warn": //warn
                            {

                                if (cfg_customban.get().get("Warn.players." + args[1]) != null) //check if the player has been warned (second time)
                                {
                                    int max = 1;
                                    for (Object a : cfg_customban.get().getConfigurationSection("Warn.players." + args[1]).getKeys(false)) //get times
                                    {
                                        max += 1;
                                    }
                                    cfg_customban.set("Warn.players." + args[1] + "." + max, args[2]); //set new warn
                                    Bukkit.getLogger().info(ChatColor.RED + "[CustomBan] " + ChatColor.GRAY + "成功記 " + args[1] + " 一支警告(" + max + ")。 原因： " + args[2]);
                                    if (Bukkit.getServer().getPlayer(args[1]) != null) //If the player is online, notify that he is warned.
                                    {
                                        if (cfg_customban.get().getBoolean("Warn.kick")) {
                                            Bukkit.getServer().getPlayer(args[1]).kickPlayer(ChatColor.WHITE + "▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂\n\n" +
                                                    ChatColor.RED + "你已遭到管理員警告（" + max + "）！\n" + "原因： " + args[2] + ChatColor.WHITE + "\n\n▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂");
                                        } else {
                                            Bukkit.getServer().getPlayer(args[1]).sendMessage(ChatColor.DARK_GRAY + "» " + ChatColor.RED + "你已遭到 "
                                                    + ChatColor.YELLOW + "CONSOLE" + ChatColor.RED + " 警告！ 原因： " + args[2] + "。你目前有 " + max + " 次警告！");
                                        }
                                    }
                                    if (cfg_customban.get().getInt("Warn.maxwarn") <= max) //!!!! be worked
                                    {
                                        cfg_customban.setban(args[1], "CONSOLE", "警告已達到 " + max + " 支", 0);
                                        Bukkit.getServer().getPlayer(args[1]).kickPlayer(ChatColor.WHITE + "▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂\n\n" +
                                                ChatColor.RED + "你已被管理員 " + ChatColor.YELLOW + "CONSOLE" + ChatColor.RED + " 封鎖！  \n原因： " + "警告已達到 " + max + " 支" +
                                                ChatColor.WHITE + "\n\n▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂");
                                    }
                                } else //first time
                                {
                                    cfg_customban.set("Warn.players." + args[1] + "." + 1, args[2]);
                                    Bukkit.getLogger().info(ChatColor.RED + "[CustomBan] " + ChatColor.GRAY + "成功記 " + args[1] + " 一支警告(1)。 原因： " + args[2]);
                                    if (Bukkit.getServer().getPlayer(args[1]) != null) //If the player is online, notify that he is warned.
                                    {
                                        if (cfg_customban.get().getBoolean("Warn.kick")) {
                                            Bukkit.getServer().getPlayer(args[1]).kickPlayer(ChatColor.WHITE + "▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂\n\n" +
                                                    ChatColor.RED + "你已遭到管理員警告（" + 1 + "）！\n" + "原因： " + args[2] + ChatColor.WHITE + "\n\n▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂");
                                        } else {
                                            Bukkit.getServer().getPlayer(args[1]).sendMessage(ChatColor.DARK_GRAY + "» " + ChatColor.RED + "你已遭到 "
                                                    + ChatColor.YELLOW + "CONSOLE" + ChatColor.RED + " 警告！ 原因： " + args[2] + "。你目前有 1 次警告！");
                                        }
                                    }
                                }
                                return true;

                            }
                            case "delwarn": //delwarn
                            {
                                if (cfg_customban.get().get("Warn.players." + args[1]) != null) //check if player has any warns
                                {
                                    if (cfg_customban.get().getConfigurationSection("Warn.players." + args[1]).getKeys(false).contains(args[2])) //switch single or all
                                    {
                                        //send message to sender
                                        Bukkit.getLogger().info(ChatColor.RED + "[CustomBan] " + ChatColor.GRAY + "成功刪除 " + args[1] + " 的警告。 " +
                                                ChatColor.AQUA + "[" + args[2] + "] " + cfg_customban.get().get("Warn.players." + args[1] + "." + args[2]));
                                        //send message to target
                                        if (Bukkit.getServer().getPlayer(args[1]) != null) //If the player is online, notify that there's a warn be removed.
                                        {
                                            Bukkit.getServer().getPlayer(args[1]).sendMessage(ChatColor.DARK_GRAY + "» " + ChatColor.GREEN + "你有一支警告已被消除。 " +
                                                    ChatColor.AQUA + "[" + args[2] + "] " + cfg_customban.get().get("Warn.players." + args[1] + "." + args[2]));
                                        }
                                        //main code
                                        cfg_customban.set("Warn.players." + args[1] + "." + args[2], null); //remove the warn
                                        ArrayList<String> reason = new ArrayList();
                                        int max = 0;
                                        for (String b : cfg_customban.get().getConfigurationSection("Warn.players." + args[1]).getKeys(false)) //get all reason and max times
                                        {
                                            reason.add((String) cfg_customban.get().get("Warn.players." + args[1] + "." + b));
                                            max++;
                                        }
                                        cfg_customban.set("Warn.players." + args[1], null); //clear all warns
                                        for (int i = 1; i <= max; i++) //put all warns back
                                        {
                                            cfg_customban.set("Warn.players." + args[1] + "." + i, reason.get(i - 1));
                                        }
                                    } else {
                                        if (args[2].equals("all")) //args[2] is "all"
                                        {
                                            cfg_customban.set("Warn.players." + args[1], null);
                                            Bukkit.getLogger().info(ChatColor.RED + "[CustomBan] " + ChatColor.GRAY + "成功刪除 " + args[1] + " 的所有警告。");
                                            if (Bukkit.getServer().getPlayer(args[1]) != null) //If the player is online, notify that all of the warns are be removed.
                                            {
                                                Bukkit.getServer().getPlayer(args[1]).sendMessage(ChatColor.DARK_GRAY + "» " + ChatColor.GREEN + "你的所有警告已被消除。");
                                            }
                                        } else {
                                            Bukkit.getLogger().info(ChatColor.RED + "[CustomBan] " + ChatColor.GRAY + "找不到此編號！");
                                        }
                                    }
                                } else {
                                    Bukkit.getLogger().info(ChatColor.RED + "[CustomBan] " + ChatColor.GRAY + "此玩家沒有任何的警告記錄！");
                                }
                                return true;

                            }
                            case "kick": //kick
                            {
                                if (Bukkit.getServer().getPlayer(args[1]) != null) //check if the player is online
                                {
                                    Player target = Bukkit.getServer().getPlayer(args[1]);
                                    Bukkit.getLogger().info(ChatColor.RED + "[CustomBan] " + ChatColor.GRAY + "成功踢出玩家 " + target.getName() +
                                            "。 原因： " + args[2]);
                                    //-----------------------
                                    target.kickPlayer(ChatColor.WHITE + "▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂\n\n" +
                                            ChatColor.RED + "你已被管理員 " + ChatColor.YELLOW +
                                            "CONSOLE" + ChatColor.RED + " 踢出伺服器！\n原因： " +
                                            args[2] + ChatColor.WHITE + "\n\n▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂");
                                } else {
                                    Bukkit.getLogger().info(ChatColor.RED + "[CustomBan] " + ChatColor.GRAY + "找不到此玩家！");
                                }
                                return true;
                            }
                            case "ban": //ban
                            {
                                Player target = Bukkit.getServer().getPlayer(args[1]);
                                cfg_customban.setban(target.getName(), "CONSOLE", args[2], 0);
                                //kick player with message
                                target.kickPlayer(ChatColor.WHITE + "▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂\n\n" +
                                        ChatColor.RED + "你已被管理員 " + ChatColor.YELLOW + "CONSOLE" + ChatColor.RED + " 封鎖！  \n原因： " + args[2] +
                                        ChatColor.WHITE + "\n\n▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂");
                                Bukkit.getLogger().info(ChatColor.RED + "[CustomBan] " + ChatColor.DARK_RED + "成功封鎖玩家 " + target.getName() + "。 原因： " + args[2]);
                                //broadcast that the player is banned
                                for (Player a : Bukkit.getServer().getOnlinePlayers()) {
                                    a.sendMessage(ChatColor.DARK_GRAY + "» " + ChatColor.YELLOW + "CONSOLE" + ChatColor.RED + " 已被管理員 " + ChatColor.YELLOW +
                                            "CONSOLE" + ChatColor.RED + " 封鎖！ 原因： " + args[2]);
                                }
                                return true;
                            }
                            default: {
                                Bukkit.getLogger().info(ChatColor.RED + "[CustomBan] " + ChatColor.GRAY + "指令格式錯誤！");
                                return true;
                            }
                        }
                    }
                    case 4: {
                        if (args[0].equals("tempban")) {
                            Player target = Bukkit.getServer().getPlayer(args[1]);
                            cfg_customban.setban(target.getName(), "CONSOLE", args[2], new api_customban_time().tomillisecond_withcmd(args[3]));
                            //kick player with message
                            target.kickPlayer(ChatColor.WHITE + "▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂\n\n" +
                                    ChatColor.RED + "你已被管理員 " + ChatColor.YELLOW + "CONSOLE" + ChatColor.RED + " 暫時封鎖！" +
                                    "\n原因： " + args[2] + "\n時間： " + cfg_customban.get().get("Ban." + target.getName() + ".expired") +
                                    ChatColor.WHITE + "\n\n▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂");
                            //send message to sender
                            Bukkit.getLogger().info(ChatColor.RED + "[CustomBan] " + ChatColor.DARK_RED + "成功暫時封鎖玩家 " + target.getName() +
                                    "。 原因： " + args[2] + " 時間： " + cfg_customban.get().get("Ban." + target.getName() + ".expired"));
                            //broadcast that the player is banned
                            for (Player a : Bukkit.getServer().getOnlinePlayers()) {
                                a.sendMessage(ChatColor.DARK_GRAY + "» " + ChatColor.YELLOW + "CONSOLE" + ChatColor.RED + " 已被管理員 " + ChatColor.YELLOW +
                                        "CONSOLE" + ChatColor.RED + " 暫時封鎖！ 原因： " + args[2] + " 時間： " + cfg_customban.get().get("Ban." + target.getName() + ".expired"));
                            }
                            return true;
                        } else {
                            Bukkit.getLogger().info(ChatColor.RED + "[CustomBan] " + ChatColor.GRAY + "指令格式錯誤！");
                        }
                    }
                    default: {
                        break;
                    }
                }
            }
        }
        return false;
    }
}