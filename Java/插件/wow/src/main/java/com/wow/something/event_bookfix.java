package com.wow.something;

import org.bukkit.Bukkit;
import org.bukkit.ChatColor;
import org.bukkit.Material;
import org.bukkit.entity.Player;
import org.bukkit.event.EventHandler;
import org.bukkit.event.Listener;
import org.bukkit.event.player.PlayerEditBookEvent;
import org.bukkit.inventory.ItemStack;

public final class event_bookfix implements Listener {
    @EventHandler
    public void PlayerEditBookEvent(PlayerEditBookEvent e) {
        Player p = e.getPlayer();
        ItemStack noitem = new ItemStack(Material.AIR, 1);
        if (!(p.hasPermission("wow.bookfix.bypass"))) {
            p.setItemInHand(noitem);
            Bukkit.getLogger().info(ChatColor.RED + "警告： 玩家 " + ChatColor.YELLOW + p.getName() + ChatColor.RED + " 嘗試編輯書本！");
            p.sendMessage(ChatColor.DARK_GRAY + "»" + ChatColor.RED + " 本伺服器禁止使用書本！");
            for (Player admin : Bukkit.getServer().getOnlinePlayers()) {
                if (admin.hasPermission("wow.bookfix.notify")) {
                    admin.sendMessage(ChatColor.RED + "警告： 玩家 " + ChatColor.YELLOW + p.getName() + ChatColor.RED + " 嘗試編輯書本！");
                }
            }
        }
    }
}

