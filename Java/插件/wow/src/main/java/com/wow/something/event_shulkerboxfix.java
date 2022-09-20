package com.wow.something;

import org.bukkit.Bukkit;
import org.bukkit.ChatColor;
import org.bukkit.entity.Player;
import org.bukkit.event.EventHandler;
import org.bukkit.event.Listener;
import org.bukkit.event.block.BlockDispenseEvent;
import org.bukkit.event.block.BlockPlaceEvent;

public final class event_shulkerboxfix implements Listener {
    @EventHandler
    public void BlockDispenseEvent(BlockDispenseEvent e) {
        if (e.getBlock().getY() == 255 || e.getBlock().getY() == 0) {
            e.setCancelled(true);
        }
    }

    @EventHandler
    public void BlockPlaceEvent(BlockPlaceEvent e) {
        Player p = e.getPlayer();
        if (e.getBlock().getY() == 255) {
            String warn =
                    ChatColor.RED + "警告： 玩家 " + ChatColor.YELLOW + p.getName() + ChatColor.RED + " 正在嘗試於255格建築！";
            String loc =
                    ChatColor.RED + "- 世界： " + ChatColor.YELLOW + e.getBlock().getWorld().getName() + ChatColor.RED + " 座標： X: " + ChatColor.YELLOW +
                            e.getBlock().getX() + ChatColor.RED + " Z: " + ChatColor.YELLOW + e.getBlock().getZ();

            Bukkit.getLogger().info(warn);
            Bukkit.getLogger().info(loc);
            for (Player admin : Bukkit.getServer().getOnlinePlayers()) {
                if (admin.hasPermission("wow.shulkerboxfix.notify")) {
                    admin.sendMessage(warn);
                    admin.sendMessage(loc);
                }
            }
        } else {
            if (e.getBlock().getY() == 0) {
                String warn =
                        ChatColor.RED + "警告： 玩家 " + ChatColor.YELLOW + p.getName() + ChatColor.RED + " 正在嘗試於1格建築！";
                String loc =
                        ChatColor.RED + "- 世界： " + ChatColor.YELLOW + e.getBlock().getWorld().getName() + ChatColor.RED + " 座標： X: " + ChatColor.YELLOW +
                                e.getBlock().getX() + ChatColor.RED + " Z: " + ChatColor.YELLOW + e.getBlock().getZ();

                Bukkit.getLogger().info(warn);
                Bukkit.getLogger().info(loc);
                for (Player admin : Bukkit.getServer().getOnlinePlayers()) {
                    if (admin.hasPermission("wow.shulkerboxfix.notify")) {
                        admin.sendMessage(warn);
                        admin.sendMessage(loc);
                    }
                }
            }
        }
    }
}