package com.wow.something;

import com.wow.App;
import org.bukkit.Bukkit;
import org.bukkit.Location;
import org.bukkit.Material;
import org.bukkit.World;
import org.bukkit.event.EventHandler;
import org.bukkit.event.Listener;
import org.bukkit.event.entity.ProjectileHitEvent;

public final class event_glassbreak implements Listener {
    @EventHandler
    public void ProjectileHitEvent(ProjectileHitEvent e) {
        if (e.getHitBlock() != null && cfg_something.get().getBoolean("glassbreak." + e.getHitBlock().getWorld().getName())) {
            App main = App.getPlugin(App.class);
            boolean isglass = e.getHitBlock().getTypeId() == 102 || e.getHitBlock().getTypeId() == 160;
            boolean is_allowed = e.getEntity().getName().equals("Snowball") || e.getEntity().getName().equals("Arrow") ||
                    e.getEntity().getName().equals("entity.ThrownEgg.name");
            if (isglass && is_allowed) {
                double x = e.getHitBlock().getX();
                double y = e.getHitBlock().getY();
                double z = e.getHitBlock().getZ();
                World world = e.getHitBlock().getWorld();
                Material block = e.getHitBlock().getType();
                byte block_data = e.getHitBlock().getData();
                Location loc = new Location(world, x, y, z);
                e.getHitBlock().breakNaturally();
                Bukkit.getServer().getScheduler().scheduleSyncDelayedTask(main, new Runnable() {
                    public void run() {
                        loc.getBlock().setType(block);
                        loc.getBlock().setData(block_data);
                    }
                }, 100);
            }
        }
    }
}