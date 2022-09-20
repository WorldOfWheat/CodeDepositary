package com.wheatlogin.function.api;

import org.bukkit.inventory.ItemStack;
import org.bukkit.inventory.meta.ItemMeta;

import java.util.ArrayList;

public class api_wheatlogin_item {
    //Item
    private static ItemStack item;
    private static ItemMeta meta;

    //
    public api_wheatlogin_item(String a, ArrayList<String> b, int c) {
        //item id
        item = new ItemStack(c);
        //get meta
        meta = item.getItemMeta();
        //item name
        meta.setDisplayName(a);
        //item lore
        meta.setLore(b);
        //set
        item.setItemMeta(meta);
    }

    public ItemMeta getmeta() {
        return meta;
    }

    public ItemStack getitem() {
        return item;
    }
}
