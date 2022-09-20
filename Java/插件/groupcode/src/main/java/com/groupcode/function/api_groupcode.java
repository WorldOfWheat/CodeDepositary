package com.groupcode.function;

import net.luckperms.api.LuckPerms;
import net.luckperms.api.model.group.Group;
import net.luckperms.api.model.user.User;
import net.luckperms.api.node.Node;
import org.bukkit.Bukkit;
import org.bukkit.entity.Player;
import org.bukkit.plugin.RegisteredServiceProvider;

import java.util.Random;

public class api_groupcode {
    public String code_generate(String a) {
        Random rand = new Random();
        String letters = "ACDEFGHKLMNPQRSTUVWXYZabcdefghkmnprstuvwxyz234567";
        char[] letter = letters.toCharArray();
        StringBuilder sb = new StringBuilder();
        sb.delete(0, 8);
        for (int j = 0; j < 8; j++) {
            sb.append(letter[rand.nextInt(letter.length)]);
        }
        try {
            if (cfg_groupcode.get().getList("GroupCode." + a + ".code").contains(sb.toString()) ||
                    cfg_groupcode.get().getConfigurationSection("GroupCode." + a + ".used").getKeys(false).contains(sb.toString())) {
                return code_generate(a);
            } else {
                return sb.toString();
            }
        } catch (NullPointerException e) {
            return sb.toString();
        }
    }

    public String lp_getPlayerGroup(Player player) {
        RegisteredServiceProvider<LuckPerms> provider = Bukkit.getServicesManager().getRegistration(LuckPerms.class);
        if (provider != null) {
            LuckPerms api = provider.getProvider();
            for (Group group : api.getGroupManager().getLoadedGroups()) {
                if (player.hasPermission("group." + group.getName())) {
                    return group.getName();
                }
            }
        }
        return null;
    }

    public void lp_addPermission(User user, String permission, boolean add_or_remove) {
        RegisteredServiceProvider<LuckPerms> provider = Bukkit.getServicesManager().getRegistration(LuckPerms.class);
        if (provider != null) {
            LuckPerms api = provider.getProvider();
            if (add_or_remove) {
                // Add the permission
                user.data().add(Node.builder(permission).build());
                // Now we need to save changes.
                api.getUserManager().saveUser(user);
            } else {
                // remove the permission
                user.data().remove(Node.builder(permission).build());
                // Now we need to save changes.
                api.getUserManager().saveUser(user);
            }
        }
    }
}
