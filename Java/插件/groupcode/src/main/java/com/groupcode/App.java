package com.groupcode;

import com.groupcode.function.cfg_groupcode;
import com.groupcode.function.cmd_groupcode;
import org.bukkit.ChatColor;
import org.bukkit.event.Listener;
import org.bukkit.plugin.java.JavaPlugin;

public class App extends JavaPlugin implements Listener {
    public static void config_load() {
        App main = App.getPlugin(App.class);
        main.getCommand("groupcode").setExecutor(new cmd_groupcode());
        cfg_groupcode.create();
    }

    @Override
    public void onEnable() {
        getLogger().info(ChatColor.GRAY + "-------------------------------------------");
        getLogger().info("GroupCode 權限授權碼插件 - 啟動中！");
        config_load();
        getLogger().info("GroupCode 權限授權碼插件 - 啟動完成！");
        getLogger().info(ChatColor.GREEN + "製作 By 小麥 WorldOfWheat");
        getLogger().info(ChatColor.GRAY + "-------------------------------------------");
    }

    @Override
    public void onDisable() {
        getLogger().info(ChatColor.GRAY + "-------------------------------------------");
        getLogger().info("GroupCode 權限授權碼插件 - 已關閉！");
        getLogger().info(ChatColor.GREEN + "製作 By 小麥 WorldOfWheat");
        getLogger().info(ChatColor.GRAY + "-------------------------------------------");
    }
}