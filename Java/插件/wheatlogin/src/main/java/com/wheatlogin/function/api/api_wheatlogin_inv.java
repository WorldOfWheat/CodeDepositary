package com.wheatlogin.function.api;

import org.bukkit.Bukkit;
import org.bukkit.entity.Player;
import org.bukkit.event.inventory.InventoryType;
import org.bukkit.inventory.Inventory;

public class api_wheatlogin_inv {
    private static String title;
    private static Object type;
    private static Player opener;
    private static Inventory gui;

    public api_wheatlogin_inv(String a, Object b, Player c) {
        title = a;
        type = b;
        opener = c;
    }

    public void createchest() {
        gui = Bukkit.createInventory(opener, (int) type * 9, title);
    }

    public void createanvil() {
        gui = Bukkit.createInventory(opener, (InventoryType) type, title);
    }

    public Inventory getinv() {
        return gui;
    }
}