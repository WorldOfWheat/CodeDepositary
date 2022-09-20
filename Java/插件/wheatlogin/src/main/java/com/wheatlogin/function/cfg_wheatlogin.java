package com.wheatlogin.function;

import com.wheatlogin.App;
import com.wheatlogin.function.api.api_wheatlogin_encrypt;
import org.bukkit.ChatColor;
import org.bukkit.configuration.file.FileConfiguration;
import org.bukkit.configuration.file.YamlConfiguration;

import java.io.File;
import java.util.ArrayList;


public class cfg_wheatlogin {
    private static File file1;
    private static File file2;
    private static File file3;
    private static FileConfiguration config;
    private static FileConfiguration lang;
    private static FileConfiguration password;

    public static void create() //create file and config.yml
    {
        create_confg();
        create_lang();
        create_password();
    }

    public static void set(String a, Object b, String c) //set and save data to all files
    {
        switch (c) {
            case "config": {
                config.set(a, b);
                config.options().copyDefaults(true);
                try {
                    config.save(file1);
                } catch (Exception e) {
                }
            }
            case "lang": {
                lang.set(a, b);
                lang.options().copyDefaults(true);
                try {
                    lang.save(file2);
                } catch (Exception e) {
                }
            }
            case "password": {
                password.set(api_wheatlogin_encrypt.crypt(a), api_wheatlogin_encrypt.crypt((String) b));
                password.options().copyDefaults(true);
                try {
                    password.save(file3);
                } catch (Exception e) {
                }
            }
        }
    }

    public static FileConfiguration get(String a) //let other file can get config
    {
        switch (a) {
            case "config": {
                return config;
            }
            case "lang": {
                return lang;
            }
            case "password": {
                return password;
            }
        }
        return null;
    }

    //get pwd
    public static String getpwd(String a) {
        try {
            String msg = api_wheatlogin_encrypt.crypt(cfg_wheatlogin.get("password").getString(api_wheatlogin_encrypt.crypt(a)));
            return msg;
        } catch (NullPointerException e) {
            return null;
        }
    }

    //get sentance
    public static String getmsg(String a) {
        String msg = cfg_wheatlogin.get("lang").getString(cfg_wheatlogin.get("config").get("WheatLogin.lang") + "." + a);
        return msg.replace("&", "§");
    }

    //get name
    public static String getname(String a) {
        String name = cfg_wheatlogin.get("lang").getString(cfg_wheatlogin.get("config").get("WheatLogin.lang") + "." + a + ".name");
        return name.replace("&", "§");
    }

    //get lore
    public static ArrayList<String> getlore(String a) {
        ArrayList<String> lore = new ArrayList();
        for (String k : cfg_wheatlogin.get("lang").getStringList(cfg_wheatlogin.get("config").get("WheatLogin.lang") + "." + a + ".lore")) {
            lore.add(k.replace("&", "§"));
        }
        return lore;
    }

    //all file create function
    public static void create_confg() //create file and config.yml
    {
        App main = App.getPlugin(App.class);
        file1 = new File(main.getDataFolder(), "config.yml");
        if (!(main.getDataFolder().exists())) {
            main.getDataFolder().mkdirs();
        }
        try {
            if (!(file1.exists())) {
                main.getLogger().info(ChatColor.DARK_AQUA + "[WheatLogin] " + "創造設定檔中！");
                main.saveResource("config.yml", true);
            }
        } catch (Exception e) {
        }
        config = YamlConfiguration.loadConfiguration(file1);
    }

    public static void create_lang() //create file and lang.yml
    {
        App main = App.getPlugin(App.class);
        file2 = new File(main.getDataFolder(), "lang.yml");
        if (!(main.getDataFolder().exists())) {
            main.getDataFolder().mkdirs();
        }
        try {
            if (!(file2.exists())) {
                main.getLogger().info(ChatColor.DARK_AQUA + "[WheatLogin] " + "創造語言設定檔中！");
                main.saveResource("lang.yml", true);
            }
        } catch (Exception e) {
        }
        lang = YamlConfiguration.loadConfiguration(file2);
    }

    public static void create_password() //create file and password.yml
    {
        App main = App.getPlugin(App.class);
        file3 = new File(main.getDataFolder(), "password.yml");
        if (!(main.getDataFolder().exists())) {
            main.getDataFolder().mkdirs();
        }
        try {
            if (!(file3.exists())) {
                main.getLogger().info(ChatColor.DARK_AQUA + "[WheatLogin] " + "創造密碼儲存文件中！");
                main.saveResource("password.yml", true);
            }
        } catch (Exception e) {
        }
        password = YamlConfiguration.loadConfiguration(file3);
    }
}
