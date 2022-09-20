package com.wow;

import com.wow.customban.cfg_customban;
import com.wow.customban.cmd_customban;
import com.wow.customban.event_customban;
import com.wow.something.*;
import com.wow.teampvp.cfg_teampvp;
import com.wow.teampvp.cmd_teampvp;
import com.wow.teampvp.event_teampvp;
import org.bukkit.ChatColor;
import org.bukkit.command.Command;
import org.bukkit.command.CommandSender;
import org.bukkit.command.ConsoleCommandSender;
import org.bukkit.entity.Player;
import org.bukkit.event.Listener;
import org.bukkit.plugin.java.JavaPlugin;

public class App extends JavaPlugin implements Listener {
    public static void config_load() {
        App main = App.getPlugin(App.class);
        main.getServer().getPluginManager().registerEvents(new event_bookfix(), main);
        main.getServer().getPluginManager().registerEvents(new event_teampvp(), main);
        main.getServer().getPluginManager().registerEvents(new event_shulkerboxfix(), main);
        main.getServer().getPluginManager().registerEvents(new event_glassbreak(), main);
        main.getServer().getPluginManager().registerEvents(new event_customban(), main);
        main.getServer().getPluginManager().registerEvents(new event_chair(), main);
        main.getCommand("hat").setExecutor(new cmd_hat());
        main.getCommand("teampvp").setExecutor(new cmd_teampvp());
        main.getCommand("customban").setExecutor(new cmd_customban());
        cfg_teampvp.create();
        cfg_customban.create();
        cfg_something.create();
    }

    @Override
    public void onEnable() {
        getLogger().info(ChatColor.GRAY + "-------------------------------------------");
        getLogger().info("小麥自製插件 - 啟動中！");
        config_load();
        getLogger().info("小麥自製插件 - 啟動完成！");
        getLogger().info(ChatColor.GREEN + "製作 By 小麥 WorldOfWheat");
        getLogger().info(ChatColor.GRAY + "-------------------------------------------");
    }

    public boolean onCommand(CommandSender sender, Command cmd, String lable, String[] args) //reload
    {
        boolean run = sender instanceof Player && ((Player) sender).hasPermission("wow.reload") ||
                sender instanceof ConsoleCommandSender;
        if (lable.equalsIgnoreCase("wow") && run) {
            if (sender instanceof Player) {
                ((Player) sender).sendMessage(ChatColor.GRAY + "[WOW] 小麥自製插件 - 重新啟動中！");
            }
            getLogger().info("小麥自製插件 - 重新啟動中！");
            config_load();
            getLogger().info("小麥自製插件 - 重新啟動完成！");
            if (sender instanceof Player) {
                ((Player) sender).sendMessage(ChatColor.GRAY + "[WOW] 小麥自製插件 - 重新啟動完成！");
            }
        } else {
            ((Player) sender).sendMessage(ChatColor.RED + "你沒有權限使用此指令");
        }
        return false;
    }

    @Override
    public void onDisable() {
        getLogger().info(ChatColor.GRAY + "-------------------------------------------");
        getLogger().info("小麥自製插件 - 已關閉！");
        getLogger().info(ChatColor.GREEN + "製作 By 小麥 WorldOfWheat");
        getLogger().info(ChatColor.GRAY + "-------------------------------------------");
    }
}