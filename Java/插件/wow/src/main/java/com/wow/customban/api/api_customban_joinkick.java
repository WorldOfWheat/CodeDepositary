package com.wow.customban.api;

import com.wow.customban.cfg_customban;
import org.bukkit.Bukkit;
import org.bukkit.ChatColor;
import org.bukkit.entity.Player;

public class api_customban_joinkick {
    public void ban(String a, String b) {
        Player target = Bukkit.getServer().getPlayer(a);
        if (cfg_customban.get().get("Ban." + a + ".reason") == null) //no reason
        {
            target.kickPlayer(ChatColor.WHITE + "▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂\n\n" +
                    ChatColor.RED + "此帳號已被管理員 " + ChatColor.YELLOW + cfg_customban.get().get("Ban." + b + ".admin") + ChatColor.RED + " 封鎖！" +
                    ChatColor.WHITE + "\n\n▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂");
        } else //has reason
        {
            if (cfg_customban.get().get("Ban." + a + ".expired") == null) //don't have expired
            {
                target.kickPlayer(ChatColor.WHITE + "▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂\n\n" +
                        ChatColor.RED + "此帳號已被管理員 " + ChatColor.YELLOW + cfg_customban.get().get("Ban." + b + ".admin") + ChatColor.RED + " 封鎖！" + "\n原因： " + cfg_customban.get().get("Ban." + a + ".reason") +
                        ChatColor.WHITE + "\n\n▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂");
            } else //has expired
            {
                api_customban_time time_trans = new api_customban_time();
                long time1 = time_trans.tomillisecond(cfg_customban.get().get("Ban." + b + ".date"));
                long time2 = time_trans.tomillisecond(cfg_customban.get().get("Ban." + b + ".expired"));
                if (time1 < time2) {
                    target.kickPlayer(ChatColor.WHITE + "▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂\n\n" +
                            ChatColor.RED + "此帳號已被管理員 " + ChatColor.YELLOW + cfg_customban.get().get("Ban." + b + ".admin") + ChatColor.RED + " 封鎖！" +
                            "\n原因： " + cfg_customban.get().get("Ban." + a + ".reason") + "\n時間： " + cfg_customban.get().get("Ban." + a + ".expired") +
                            ChatColor.WHITE + "\n\n▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂");
                } else {
                    cfg_customban.set("Ban." + b, null);
                }
            }

        }
    }
}