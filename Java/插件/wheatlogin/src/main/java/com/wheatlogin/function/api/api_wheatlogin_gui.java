package com.wheatlogin.function.api;

import com.wheatlogin.function.cfg_wheatlogin;
import org.bukkit.entity.Player;
import org.bukkit.event.inventory.InventoryType;
import org.bukkit.inventory.Inventory;

public class api_wheatlogin_gui {
    private Player p;

    public api_wheatlogin_gui(Player a) {
        this.p = a;
    }

    public Inventory loggined() {
        api_wheatlogin_inv inv = new api_wheatlogin_inv(cfg_wheatlogin.getmsg("gui.successful_login.title"), 1, p);
        inv.createchest(); //create a void chest
        api_wheatlogin_item logged_in = new api_wheatlogin_item(cfg_wheatlogin.getname("gui.successful_login.logged-in"), cfg_wheatlogin.getlore("gui.successful_login.logged-in"), 426);
        inv.getinv().setItem(4, logged_in.getitem());
        api_wheatlogin_item changepassword = new api_wheatlogin_item(cfg_wheatlogin.getname("gui.successful_login.changepassword"), cfg_wheatlogin.getlore("gui.successful_login.changepassword"), 421);
        inv.getinv().setItem(2, changepassword.getitem());
        api_wheatlogin_item account_log = new api_wheatlogin_item(cfg_wheatlogin.getname("gui.successful_login.account_log"), cfg_wheatlogin.getlore("gui.successful_login.account_log"), 323);
        inv.getinv().setItem(0, account_log.getitem());
        api_wheatlogin_item logout = new api_wheatlogin_item(cfg_wheatlogin.getname("gui.successful_login.logout"), cfg_wheatlogin.getlore("gui.successful_login.logout"), 330);
        inv.getinv().setItem(6, logout.getitem());
        api_wheatlogin_item delete = new api_wheatlogin_item(cfg_wheatlogin.getname("gui.successful_login.delete"), cfg_wheatlogin.getlore("gui.successful_login.delete"), 421);
        inv.getinv().setItem(8, delete.getitem());
        return inv.getinv();
    }

    public Inventory register() {
        api_wheatlogin_inv anvil = new api_wheatlogin_inv(cfg_wheatlogin.getmsg("gui.register.title"), InventoryType.ANVIL, p);
        anvil.createanvil();
        return anvil.getinv();
    }

    public void login() {

    }
}
