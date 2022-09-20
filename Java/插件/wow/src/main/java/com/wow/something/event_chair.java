package com.wow.something;

import org.bukkit.entity.ArmorStand;
import org.bukkit.entity.EntityType;
import org.bukkit.entity.Player;
import org.bukkit.event.EventHandler;
import org.bukkit.event.Listener;
import org.bukkit.event.player.PlayerInteractEvent;
import org.spigotmc.event.entity.EntityDismountEvent;

public final class event_chair implements Listener {
    @EventHandler
    public void PlayerInteractEvent(PlayerInteractEvent e) {
        Player p = e.getPlayer();
        int[] id = {53, 67, 134, 135, 136, 156, 128, 163, 164, 203};
        for (int a : id) {
            if (e.getClickedBlock().getTypeId() == a && String.valueOf(e.getAction()).equals("RIGHT_CLICK_BLOCK")) {
                try {
                    if (!(p.getPassenger().equals(EntityType.ARMOR_STAND))) {
                        ArmorStand as = (ArmorStand) p.getWorld().spawn(e.getClickedBlock().getLocation(), ArmorStand.class);
                        as.setVisible(false);
                        as.addPassenger(p);
                    }
                } catch (NullPointerException k) {
                    ArmorStand as = (ArmorStand) p.getWorld().spawn(e.getClickedBlock().getLocation(), ArmorStand.class);
                    as.addPassenger(p);
                }
            }
        }
    }

    @EventHandler
    public void EntityDismountEvent(EntityDismountEvent e) {
        if (e.getEntity() instanceof Player && e.getDismounted() instanceof ArmorStand) {
            e.getDismounted().remove();
        }
    }
}