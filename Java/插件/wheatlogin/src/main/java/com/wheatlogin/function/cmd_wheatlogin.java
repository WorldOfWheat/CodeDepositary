package com.wheatlogin.function;

import org.bukkit.ChatColor;
import org.bukkit.command.Command;
import org.bukkit.command.CommandExecutor;
import org.bukkit.command.CommandSender;
import org.bukkit.entity.Player;

public final class cmd_wheatlogin implements CommandExecutor {
    @Override
    public boolean onCommand(CommandSender sender, Command command, String label, String[] args) {
        if (label.equalsIgnoreCase("wl") && sender instanceof Player) {
            Player p = (Player) sender;
            String prefix = cfg_wheatlogin.getmsg("prefix");
            switch (args.length) {
                case 0: {
                    if (p.hasPermission("groupcode.player")) {
                        //p.openInventory(new api_wheatlogin_gui(p).loggined());
                    }
                    return true;
                }
                case 1: {
                    if (args[0].equals("help") && p.hasPermission("groupcode.admin.help")) {
                        p.sendMessage(ChatColor.GRAY + "-------------" + prefix + ChatColor.GRAY + "-------------");
                        p.sendMessage(ChatColor.GRAY + " ");
                        p.sendMessage(ChatColor.GRAY + "/wl register <玩家> <密碼> - 強制玩家註冊");
                        p.sendMessage(ChatColor.GRAY + "/wl login <玩家>- 強制玩家登入");
                        p.sendMessage(ChatColor.GRAY + "/wl changepassword <玩家> <密碼> - 強制更改玩家密碼");
                        p.sendMessage(ChatColor.GRAY + "/wl logout <玩家> - 強制玩家登出");
                        p.sendMessage(ChatColor.GRAY + "/wl delete <玩家> - 刪除玩家的密碼");
                        p.sendMessage(ChatColor.GRAY + "/wl reload - 重新載入插件");
                    }
                    return true;
                }
                case 3: {
                    switch (args[0]) {
                        case "register": {
                            if (p.hasPermission("wheatlogin.admin.register")) {
                                if (cfg_wheatlogin.getpwd(args[1] + ".password") == null) {
                                    cfg_wheatlogin.set(args[1] + ".password", args[2], "password");
                                    p.sendMessage(prefix + ChatColor.GRAY + " 成功註冊 " + args[1] + "。 密碼： " + args[2]);
                                } else {
                                    p.sendMessage(prefix + ChatColor.GRAY + " 該玩家已註冊！");
                                }
                                return true;
                            }
                        }
                        case "changepassword": {
                            if (p.hasPermission("wheatlogin.admin.register")) {
                                if (cfg_wheatlogin.getpwd(args[1] + ".password") != null) {
                                    cfg_wheatlogin.set(args[1] + ".password", args[2], "password");
                                    p.sendMessage(prefix + ChatColor.GRAY + " 成功將 " + args[1] + " 的密碼改為 " + args[2]);
                                } else {
                                    p.sendMessage(prefix + ChatColor.GRAY + " 找不到該玩家！");
                                }
                                return true;
                            }
                        }
                        default: {
                            return false;
                        }
                    }
                }
                default: {
                    p.sendMessage(prefix + ChatColor.GRAY + " 指令格式錯誤！");
                    return false;
                }
            }
        } else //be worked
        {

        }
        return false;
    }
}