package com.wow.something;

import org.bukkit.command.Command;
import org.bukkit.command.CommandExecutor;
import org.bukkit.command.CommandSender;
import org.bukkit.entity.Player;


public final class cmd_hat implements CommandExecutor {
    public boolean onCommand(CommandSender sender, Command cmd, String lable, String[] args) {
        if (lable.equalsIgnoreCase("hat") && (sender instanceof Player)) {
            Player p = (Player) sender;
            if (p.getInventory().getItemInMainHand().getTypeId() != 0) {
                if (p.getInventory().getHelmet() != null) {
                    p.getInventory().addItem(p.getInventory().getHelmet());
                    p.getInventory().setHelmet(p.getInventory().getItemInMainHand());
                    p.setItemInHand(null);
                } else {
                    p.getInventory().setHelmet(p.getInventory().getItemInMainHand());
                    p.setItemInHand(null);
                }
            } else {
                p.getInventory().setItemInMainHand(p.getInventory().getHelmet());
                p.getInventory().setHelmet(null);
            }
        }
        return false;
    }
}