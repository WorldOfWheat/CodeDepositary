package com.groupcode.function;


import com.groupcode.App;
import net.luckperms.api.LuckPerms;
import net.luckperms.api.model.group.Group;
import net.luckperms.api.model.user.User;
import org.bukkit.Bukkit;
import org.bukkit.ChatColor;
import org.bukkit.command.Command;
import org.bukkit.command.CommandExecutor;
import org.bukkit.command.CommandSender;
import org.bukkit.entity.Player;
import org.bukkit.plugin.RegisteredServiceProvider;

import java.text.SimpleDateFormat;
import java.util.Date;


public final class cmd_groupcode implements CommandExecutor {
    public boolean onCommand(CommandSender sender, Command command, String label, String[] args) {
        if (label.equalsIgnoreCase("groupcode") && (sender instanceof Player)) {
            Player p = (Player) sender;
            switch (args.length) {
                case 0: {
                    if (p.hasPermission("groupcode.generate") || p.hasPermission("groupcode.reload")) {
                        p.sendMessage(ChatColor.DARK_RED + "-------------[GroupCode]-------------");
                        p.sendMessage(ChatColor.GRAY + " ");
                        p.sendMessage(ChatColor.GRAY + "/groupcode generate <身份組> <數量> - 產生代碼");
                        p.sendMessage(ChatColor.GRAY + "/groupcode <代碼> - 使用代碼 （該代碼將失效）");
                        p.sendMessage(ChatColor.GRAY + "/groupcode reload - 重新載入該插件");
                    } else {
                        p.sendMessage(ChatColor.DARK_RED + "-------------[GroupCode]-------------");
                        p.sendMessage(ChatColor.GRAY + "/groupcode <代碼> - 使用代碼 （該代碼將失效）");
                    }
                    return true;
                }
                case 1: {
                    if (!(args[0].equals("reload"))) {
                        RegisteredServiceProvider<LuckPerms> provider = Bukkit.getServicesManager().getRegistration(LuckPerms.class);
                        SimpleDateFormat ft = new SimpleDateFormat("yyyy 年 MM 月 dd 日 - HH 時 mm 分 ss 秒");
                        if (provider != null) {
                            LuckPerms api = provider.getProvider();
                            for (Group a : api.getGroupManager().getLoadedGroups()) {
                                try {
                                    if (cfg_groupcode.get().getList("GroupCode." + a.getName() + ".code").contains(args[0]) &&
                                            cfg_groupcode.get().getBoolean("GroupCode." + a.getName() + ".enable")) {
                                        User user = api.getUserManager().getUser(p.getUniqueId());
                                        api_groupcode api_group = new api_groupcode();

                                        cfg_groupcode.set("GroupCode." + a.getName() + ".used." + args[0] + ".date", ft.format(new Date().getTime()));
                                        cfg_groupcode.set("GroupCode." + a.getName() + ".used." + args[0] + ".user", p.getName());
                                        cfg_groupcode.set("GroupCode." + a.getName() + ".used." + args[0] + ".from", user.getPrimaryGroup());

                                        if (api_group.lp_getPlayerGroup(p).equals("default")) {
                                            api_group.lp_addPermission(user, "group." + a.getName(), true);
                                        } else {
                                            api_group.lp_addPermission(user, "group." + user.getPrimaryGroup(), false);
                                            api_group.lp_addPermission(user, "group." + a.getName(), true);
                                        }
                                        api_group.lp_addPermission(user, "group.default", false);
                                        p.sendMessage(ChatColor.DARK_GRAY + "» " + ChatColor.GREEN + "成功設置為新的身份組 " + user.getPrimaryGroup());
                                        cfg_groupcode.setcode(a.getName(), args[0], false);
                                        return true;
                                    }
                                } catch (NullPointerException e) {
                                }
                            }
                            p.sendMessage(ChatColor.DARK_GRAY + "» " + ChatColor.RED + "無效的代碼！");
                        }
                        return false;
                    } else {
                        if (p.hasPermission("groupcode.reload")) {
                            App.config_load();
                            p.sendMessage(ChatColor.DARK_RED + "[GroupCode] " + ChatColor.GRAY + "成功重新載入此插件！");
                        } else {
                            p.sendMessage(ChatColor.RED + "你沒有權限使用此指令");
                        }
                        return true;
                    }
                }
                case 3: {
                    if (args[0].equals("generate") && p.hasPermission("groupcode.generate")) {
                        try {
                            for (int i = 0; i < Integer.valueOf(args[2]); i++) {
                                if (cfg_groupcode.get().getBoolean("GroupCode." + args[1] + ".enable")) {
                                    String code = new api_groupcode().code_generate(args[1]);
                                    cfg_groupcode.setcode(args[1], code, true);
                                    p.sendMessage(ChatColor.DARK_RED + "[GroupCode] " + ChatColor.GRAY + code);
                                } else {
                                    p.sendMessage(ChatColor.DARK_RED + "[GroupCode] " + ChatColor.GRAY + "此身份組已關閉使用代碼！");
                                    return false;
                                }
                            }
                        } catch (NumberFormatException e) {
                            p.sendMessage(ChatColor.DARK_RED + "[GroupCode] " + ChatColor.GRAY + "請輸入數字！");
                        } catch (NullPointerException e) {
                            p.sendMessage(ChatColor.DARK_RED + "[GroupCode] " + ChatColor.GRAY + "找不到此身份組！");
                        }
                    } else {
                        p.sendMessage(ChatColor.RED + "你沒有權限使用此指令");
                    }
                    return true;
                }
                default: {
                    p.sendMessage(ChatColor.DARK_RED + "[GroupCode] " + ChatColor.GRAY + "指令格式錯誤！");
                    return true;
                }
            }
        } else {
            switch (args.length) {
                case 0: {
                    Bukkit.getLogger().info(ChatColor.DARK_RED + "-------------[GroupCode]-------------");
                    Bukkit.getLogger().info(ChatColor.GRAY + " ");
                    Bukkit.getLogger().info(ChatColor.GRAY + "/groupcode generate <身份組> <數量> - 產生代碼");
                    Bukkit.getLogger().info(ChatColor.GRAY + "/groupcode <代碼> - 使用代碼 （該代碼將失效）");
                    Bukkit.getLogger().info(ChatColor.GRAY + "/groupcode reload - 重新載入該插件");
                    return true;
                }
                case 1: {
                    if (!(args[0].equals("reload"))) {
                        Bukkit.getLogger().info(ChatColor.DARK_RED + "[GroupCode] " + ChatColor.GRAY + "代碼只能由玩家輸入！");
                        return false;
                    } else {
                        App.config_load();
                        Bukkit.getLogger().info(ChatColor.DARK_RED + "[GroupCode] " + ChatColor.GRAY + "成功重新載入此插件！");
                        return true;
                    }
                }
                case 3: {
                    if (args[0].equals("generate")) {
                        try {
                            for (int i = 0; i < Integer.valueOf(args[2]); i++) {
                                if (cfg_groupcode.get().getBoolean("GroupCode." + args[1] + ".enable")) {
                                    String code = new api_groupcode().code_generate(args[1]);
                                    cfg_groupcode.setcode(args[1], code, true);
                                    Bukkit.getLogger().info(ChatColor.DARK_RED + "[GroupCode] " + ChatColor.GRAY + code);
                                } else {
                                    Bukkit.getLogger().info(ChatColor.DARK_RED + "[GroupCode] " + ChatColor.GRAY + "此身份組已關閉使用代碼！");
                                    return false;
                                }
                            }
                        } catch (NumberFormatException e) {
                            Bukkit.getLogger().info(ChatColor.DARK_RED + "[GroupCode] " + ChatColor.GRAY + "請輸入數字！");
                        } catch (NullPointerException e) {
                            Bukkit.getLogger().info(ChatColor.DARK_RED + "[GroupCode] " + ChatColor.GRAY + "找不到此身份組！");
                        }
                    } else {
                        Bukkit.getLogger().info(ChatColor.DARK_RED + "[GroupCode] " + ChatColor.GRAY + "指令格式錯誤！");
                    }
                    return true;
                }
                default: {
                    Bukkit.getLogger().info(ChatColor.DARK_RED + "[GroupCode] " + ChatColor.GRAY + "指令格式錯誤！");
                    return true;
                }
            }
        }
    }
}

