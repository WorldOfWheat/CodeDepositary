package com.wow.teampvp;

import com.wow.App;
import org.bukkit.ChatColor;
import org.bukkit.configuration.file.FileConfiguration;
import org.bukkit.configuration.file.YamlConfiguration;

import java.io.File;


public class cfg_teampvp {
    private static File file;
    private static FileConfiguration teams;

    public static void create() //create file and teams.yml
    {
        App main = App.getPlugin(App.class);
        file = new File(main.getDataFolder(), "teams.yml");
        if (!(main.getDataFolder().exists())) {
            main.getDataFolder().mkdirs();
        }
        if (!(file.exists())) {
            main.getLogger().info(ChatColor.RED + "[TeamPVP] " + "創造隊伍文件中！");
            main.saveResource("teams.yml", true);
        }
        teams = YamlConfiguration.loadConfiguration(file);
        set("Player", null);
    }

    public static void set(String a, Object b) //set and save data to teams.yml
    {
        teams.set(a, b);
        teams.options().copyDefaults(true);
        try {
            teams.save(file);
        } catch (Exception e) {
        }
    }

    public static void newteam(Object a) //create new team
    {
        teams.set("Teams." + a + ".pvp", false);
        teams.set("Teams." + a + ".onworldchange", true);
        teams.set("Teams." + a + ".ondeath", true);
        teams.set("Teams." + a + ".onquit", true);
        try {
            teams.save(file);
        } catch (Exception e) {
        }
    }

    public static void setteam(String a, Object b, String c) //set team
    {
        teams.set("Teams." + a + "." + b, Boolean.parseBoolean(c));
        try {
            teams.save(file);
        } catch (Exception e) {
        }
    }

    public static void newpair(String a, String b, String c) {

        teams.set("Pairs." + a + ".team1", b);
        teams.set("Pairs." + a + ".team2", c);
        teams.set("Pairs." + a + ".autobalance", true);
        try {
            teams.save(file);
        } catch (Exception e) {
        }
    }

    public static FileConfiguration get() //let other file can get config
    {
        return teams;
    }
}
