package com.wow.teampvp;

import org.bukkit.entity.Player;
import org.bukkit.entity.Projectile;
import org.bukkit.event.EventHandler;
import org.bukkit.event.Listener;
import org.bukkit.event.entity.EntityDamageByEntityEvent;
import org.bukkit.event.entity.PlayerDeathEvent;
import org.bukkit.event.player.PlayerChangedWorldEvent;

public class event_teampvp implements Listener {
    @EventHandler
    public void PlayerDeathEvent(PlayerDeathEvent e) //when death
    {
        Player p = e.getEntity();
        Object playerteam = cfg_teampvp.get().get("Player." + p.getName());
        if (playerteam != null && cfg_teampvp.get().getBoolean("Teams." + playerteam + ".ondeath")) {
            cfg_teampvp.set("Player." + p.getName(), null);
        }
    }

    @EventHandler
    public void PlayerChangedWorldEvent(PlayerChangedWorldEvent e) //when worldchange
    {
        Player p = e.getPlayer();
        Object playerteam = cfg_teampvp.get().get("Player." + p.getName());
        if (playerteam != null && cfg_teampvp.get().getBoolean("Teams." + playerteam + ".onworldchange")) {
            cfg_teampvp.set("Player." + p.getName(), null);
        }
    }

    @EventHandler
    public void PlayerQuitEvent(org.bukkit.event.player.PlayerQuitEvent e) //when player quit
    {
        Player p = e.getPlayer();
        Object playerteam = cfg_teampvp.get().get("Player." + p.getName());
        if (playerteam != null) {
            if (cfg_teampvp.get().getBoolean("Teams." + playerteam + ".onworldchange")) {
                cfg_teampvp.set("Player." + p.getName(), null);
            }
        }
    }

    @EventHandler
    public void EntityDamageEvent(EntityDamageByEntityEvent e) //pvp
    {
        if (e.getDamager() instanceof Player && e.getEntity() instanceof Player) //melee
        {
            Player p = (Player) e.getDamager();
            Player target = (Player) e.getEntity();
            Object p_team = cfg_teampvp.get().get("Player." + p.getName());
            Object target_team = cfg_teampvp.get().get("Player." + target.getName());
            boolean teams_and_pvp = p_team != null && target_team != null && //whether all players have teams and pvp is on
                    !(cfg_teampvp.get().getBoolean("Teams." + p_team + ".pvp") &&
                            cfg_teampvp.get().getBoolean("Teams." + target_team + ".pvp"));
            if (teams_and_pvp) {
                Object team_p = cfg_teampvp.get().get("Player." + p.getName()); //get player's team
                Object team_target = cfg_teampvp.get().get("Player." + target.getName());
                if (team_p.equals(team_target)) {
                    e.setCancelled(true);
                }
            }
        } else {
            if (e.getCause().equals("PROJECTILE")) {
                if (((Projectile) e.getDamager()).getShooter() instanceof Player && e.getEntity() instanceof Player) //projectile
                {
                    Projectile pr = (Projectile) e.getDamager();
                    Player p = (Player) pr.getShooter();
                    Player target = (Player) e.getEntity();
                    Object p_team = cfg_teampvp.get().get("Player." + p.getName());
                    Object target_team = cfg_teampvp.get().get("Player." + target.getName());
                    boolean teams_and_pvp = p_team != null && target_team != null &&  //whether all players have teams and pvp is on
                            !(cfg_teampvp.get().getBoolean("Teams." + p_team + ".pvp") &&
                                    cfg_teampvp.get().getBoolean("Teams." + target_team + ".pvp"));
                    if (teams_and_pvp) {
                        Object team_p = cfg_teampvp.get().get("Player." + p.getName()); //get player's team
                        Object team_target = cfg_teampvp.get().get("Player." + target.getName());
                        if (team_p.equals(team_target)) {
                            e.setCancelled(true);
                        }
                    }
                }
            }
        }
    }
}

