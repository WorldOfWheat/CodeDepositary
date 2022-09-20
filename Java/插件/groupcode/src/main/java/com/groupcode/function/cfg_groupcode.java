package com.groupcode.function;

import com.groupcode.App;
import net.luckperms.api.LuckPerms;
import net.luckperms.api.model.group.Group;
import org.bukkit.Bukkit;
import org.bukkit.ChatColor;
import org.bukkit.configuration.file.FileConfiguration;
import org.bukkit.configuration.file.YamlConfiguration;
import org.bukkit.plugin.RegisteredServiceProvider;

import java.io.File;
import java.util.ArrayList;


public class cfg_groupcode {
    static RegisteredServiceProvider<LuckPerms> provider = Bukkit.getServicesManager().getRegistration(LuckPerms.class);
    static LuckPerms lp = provider.getProvider();
    private static File file;
    private static FileConfiguration groupcode;

    public static void create() //create file and groupcode.yml
    {
        App main = App.getPlugin(App.class);
        file = new File(main.getDataFolder(), "groupcode.yml");
        if (!(main.getDataFolder().exists())) {
            main.getDataFolder().mkdirs();
        }
        try {
            if (!(file.exists())) {
                main.getLogger().info(ChatColor.DARK_RED + "[GroupCode] " + "創造代碼文件中！");
                main.saveResource("groupcode.yml", true);
            }
        } catch (Exception e) {
        }
        groupcode = YamlConfiguration.loadConfiguration(file);
        RegisteredServiceProvider<LuckPerms> provider = Bukkit.getServicesManager().getRegistration(LuckPerms.class);
        if (provider != null) {
            LuckPerms api = provider.getProvider();
            for (Group a : api.getGroupManager().getLoadedGroups()) {
                if (get().get("GroupCode." + a.getName()) == null) {
                    set("GroupCode." + a.getName() + ".enable", false);
                }
            }
        }
    }

    public static void set(String a, Object b) //set and save data to groupcode.yml
    {
        groupcode.set(a, b);
        groupcode.options().copyDefaults(true);
        try {
            groupcode.save(file);
        } catch (Exception e) {
        }
    }

    public static void setcode(String a, String b, boolean c) {
        if (c) {
            if ((ArrayList<String>) get().getList("GroupCode." + a + ".code") != null) {
                ArrayList<String> code = (ArrayList<String>) get().getList("GroupCode." + a + ".code");
                code.add(b);
                set("GroupCode." + a + ".code", code);
            } else {
                ArrayList<String> code = new ArrayList<>();
                code.add(b);
                set("GroupCode." + a + ".code", code);
            }
        } else {
            ArrayList<String> code = (ArrayList<String>) get().getList("GroupCode." + a + ".code");
            code.remove(b);
            set("GroupCode." + a + ".code", code);
        }
    }

    public static FileConfiguration get() //let other file can get config
    {
        return groupcode;
    }
}
