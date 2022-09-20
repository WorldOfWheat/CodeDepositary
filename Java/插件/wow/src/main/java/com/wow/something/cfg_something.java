package com.wow.something;

import com.wow.App;
import org.bukkit.Bukkit;
import org.bukkit.ChatColor;
import org.bukkit.World;
import org.bukkit.configuration.file.FileConfiguration;
import org.bukkit.configuration.file.YamlConfiguration;

import java.io.File;


public class cfg_something {
    private static File file;
    private static FileConfiguration something;

    public static void create() //create file and something.yml
    {
        App main = App.getPlugin(App.class);

        file = new File(main.getDataFolder(), "something.yml");
        if (!(main.getDataFolder().exists())) {
            main.getDataFolder().mkdirs();
        }
        try {
            if (!(file.exists())) {
                main.getLogger().info(ChatColor.AQUA + "[Something] " + "創造儲存文件中！");
                main.saveResource("something.yml", true);
            }
        } catch (Exception e) {
        }
        something = YamlConfiguration.loadConfiguration(file);
        ////////////////////////////////////////////////////////////
        for (World a : Bukkit.getServer().getWorlds()) //set glassbreak world list
        {
            if (get().get("glassbreak." + a.getName()) == null) {
                set("glassbreak." + a.getName(), false);
            }
        }

    }

    public static void set(String a, Object b) //set and save data to something.yml
    {
        something.set(a, b);
        something.options().copyDefaults(true);
        try {
            something.save(file);
        } catch (Exception e) {
            System.out.println("§c發生未知的錯誤！ 請重試！");
        }
    }

    public static FileConfiguration get() //let other file can get config
    {
        return something;
    }
}
