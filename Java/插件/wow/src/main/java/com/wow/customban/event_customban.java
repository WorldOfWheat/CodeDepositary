package com.wow.customban;

import com.wow.customban.api.api_customban_joinkick;
import org.bukkit.ChatColor;
import org.bukkit.entity.Player;
import org.bukkit.event.EventHandler;
import org.bukkit.event.Listener;
import org.bukkit.event.block.BlockBreakEvent;
import org.bukkit.event.block.BlockPlaceEvent;
import org.bukkit.event.player.PlayerJoinEvent;
import org.bukkit.event.player.PlayerMoveEvent;
import org.bukkit.event.player.PlayerQuitEvent;

public class event_customban implements Listener {
    @EventHandler
    public void PlayerMoveEvent(PlayerMoveEvent e) {
        if (cfg_customban.get().getList("Frezze") != null) {
            for (Object a : cfg_customban.get().getList("Frezze")) {
                if (a.equals(e.getPlayer().getName())) {
                    e.setCancelled(true);
                }
            }
        }
    }

    @EventHandler
    public void BlockBreakEvent(BlockBreakEvent e) {
        if (cfg_customban.get().getList("Frezze") != null) {
            for (Object a : cfg_customban.get().getList("Frezze")) {
                if (a.equals(e.getPlayer().getName())) {
                    e.setCancelled(true);
                }
            }
        }
    }

    @EventHandler
    public void BlockPlaceEvent(BlockPlaceEvent e) {
        if (cfg_customban.get().getList("Frezze") != null) {
            for (Object a : cfg_customban.get().getList("Frezze")) {
                if (a.equals(e.getPlayer().getName())) {
                    e.setCancelled(true);
                }
            }
        }
    }

    @EventHandler
    public void PlayerJoinEvent(PlayerJoinEvent e) {
        Player p = e.getPlayer();
        if (cfg_customban.get().get("Ban") != null) //whether ban is empty
        {
            if (cfg_customban.get().getConfigurationSection("Ban").getKeys(false).contains(p.getName())) //by id
            {
                e.setJoinMessage(null);
                new api_customban_joinkick().ban(p.getName(), p.getName());
            } else { //by ip
                for (String a : cfg_customban.get().getConfigurationSection("Ban").getKeys(false)) //get all ip in the banlist
                {
                    if (p.getAddress().getAddress().getHostAddress().equals(cfg_customban.get().get("Ban." + a + ".IP")))  //whether ip is in the banlist
                    {
                        e.setJoinMessage(null);
                        new api_customban_joinkick().ban(p.getName(), a);
                    }
                }
            }
        }
        if (cfg_customban.get().getConfigurationSection("Warn." + p.getName()) != null) {
            int max = 1;
            for (Object a : cfg_customban.get().getConfigurationSection("Warn.players." + p.getName()).getKeys(false)) {
                max++;
            }
            p.sendMessage(ChatColor.DARK_GRAY + "» " + ChatColor.GRAY + "你目前有 " + ChatColor.RED + max + ChatColor.GRAY + " 支警告。");
        }
    }

    @EventHandler
    public void PlayerQuitEvent(PlayerQuitEvent e) {
        Player p = e.getPlayer();
        if (cfg_customban.get().get("Ban") != null) {
            if (cfg_customban.get().getConfigurationSection("Ban").getKeys(false).contains(p.getName())) //by id
            {
                e.setQuitMessage(null);
            } else { //by ip
                for (String a : cfg_customban.get().getConfigurationSection("Ban").getKeys(false)) //get all ip
                {
                    if (p.getAddress().getHostName().equals(cfg_customban.get().get("Ban." + a + ".IP"))) //whether ip is in the banlist
                    {
                        e.setQuitMessage(null);
                    }
                }
            }
        }
    }
}