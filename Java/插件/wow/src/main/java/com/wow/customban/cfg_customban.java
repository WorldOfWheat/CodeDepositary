package com.wow.customban;

import com.wow.App;
import com.wow.customban.api.api_customban_time;
import org.bukkit.Bukkit;
import org.bukkit.ChatColor;
import org.bukkit.configuration.file.FileConfiguration;
import org.bukkit.configuration.file.YamlConfiguration;
import org.bukkit.entity.Player;

import java.io.File;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Date;

public class cfg_customban {
    private static File file;
    private static FileConfiguration customban;

    public static void create() //create file and customban.yml
    {
        App main = App.getPlugin(App.class);
        file = new File(main.getDataFolder(), "customban.yml");
        if (!(main.getDataFolder().exists())) {
            main.getDataFolder().mkdirs();
        }
        try {
            if (!(file.exists())) {
                main.getLogger().info(ChatColor.RED + "[CustomBan] " + "創造玩家紀錄中！");
                main.saveResource("customban.yml", true);
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
        customban = YamlConfiguration.loadConfiguration(file);
        if (customban.get("Warn") == null) {
            cfg_customban.set("Warn", null);
        }
        if (customban.get("Ban") == null) {
            cfg_customban.set("Ban", null);
        }
        if (customban.get("Warn.maxwarn") == null) {
            cfg_customban.set("Warn.maxwarn", 5);
        }
        if (customban.get("Warn.kick") == null) {
            cfg_customban.set("Warn.kick", true);
        }
        if (customban.get("Warn.players") == null) {
            cfg_customban.set("Warn.players", null);
        }
        cfg_customban.set("Frezze", null);
    }

    public static void set(String a, Object b) //set and save data to customban.yml
    {
        customban.set(a, b);
        customban.options().copyDefaults(true);
        try {
            customban.save(file);
        } catch (Exception e) {
            System.out.println("§c發生未知的錯誤！ 請重試！");
        }
    }

    public static boolean setfrezze(String a, boolean b) {
        Player target = Bukkit.getServer().getPlayer(a); //get player from server
        if (b) //add or reomve
        {
            if ((ArrayList<String>) get().getList("Frezze") != null) {
                ArrayList<String> frezzed = (ArrayList<String>) get().getList("Frezze"); //create a list from frezzelist
                if (!(frezzed.contains(a))) //check if player is in the list
                {
                    frezzed.add(target.getName());
                    set("Frezze", frezzed);
                    return true;
                } else {
                    return false;
                }
            } else {
                ArrayList<String> frezzed = new ArrayList<>();
                frezzed.add(target.getName());
                set("Frezze", frezzed);
                return true;
            }
        } else //remove
        {
            if ((ArrayList<String>) get().getList("Frezze") != null) {
                ArrayList<String> frezzed = (ArrayList<String>) get().getList("Frezze"); //create a list from frezzelist
                if (frezzed.contains(a)) //check if player is in the list
                {
                    frezzed.remove(target.getName());
                    set("Frezze", frezzed);
                    return true;
                } else {
                    return false;
                }
            }
        }
        return false;

    }

    public static void setban(String a, String b, String c, long d) {
        SimpleDateFormat ft = new SimpleDateFormat("yyyy 年 MM 月 dd 日 - HH 時 mm 分 ss 秒");
        set("Ban." + a + ".date", ft.format(new Date()));
        set("Ban." + a + ".admin", b);
        set("Ban." + a + ".IP", Bukkit.getServer().getPlayer(a).getAddress().getAddress().getHostAddress());
        if (c != null) {
            set("Ban." + a + ".reason", c);
        }
        if (d != 0) {
            set("Ban." + a + ".expired", new api_customban_time().tostring(d));
        }
    }

    public static FileConfiguration get() //let other file can get config
    {
        return customban;
    }
}
