package com.wheatlogin;

import com.wheatlogin.function.cfg_wheatlogin;
import com.wheatlogin.function.cmd_wheatlogin;
import org.bukkit.ChatColor;
import org.bukkit.event.Listener;
import org.bukkit.plugin.java.JavaPlugin;

public class App extends JavaPlugin implements Listener {
    public static void config_load() {
        App main = App.getPlugin(App.class);
        main.getCommand("wl").setExecutor(new cmd_wheatlogin());
        cfg_wheatlogin.create();
    }

    @Override
    public void onEnable() {
        getLogger().info(ChatColor.GRAY + "-------------------------------------------");
        getLogger().info("WheatLogin 登入插件 - 啟動中！");
        config_load();
        getLogger().info("WheatLogin 登入插件 - 啟動完成！");
        getLogger().info(ChatColor.GREEN + "製作 By 小麥 WorldOfWheat");
        getLogger().info(ChatColor.GRAY + "-------------------------------------------");
    }

    @Override
    public void onDisable() {
        getLogger().info(ChatColor.GRAY + "-------------------------------------------");
        getLogger().info("WheatLogin 登入插件 - 已關閉！");
        getLogger().info(ChatColor.GREEN + "製作 By 小麥 WorldOfWheat");
        getLogger().info(ChatColor.GRAY + "-------------------------------------------");
    }
}