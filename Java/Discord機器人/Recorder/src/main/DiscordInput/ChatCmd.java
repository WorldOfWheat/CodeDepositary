package main.DiscordInput;

import main.App;
import main.Thread.ConsoleCmd;
import main.api.Config;
import main.event.MessageReceived;
import net.dv8tion.jda.api.entities.Member;
import net.dv8tion.jda.api.entities.Message;
import net.dv8tion.jda.api.entities.User;
import net.dv8tion.jda.api.events.message.guild.GuildMessageReceivedEvent;
import net.dv8tion.jda.api.hooks.ListenerAdapter;
import org.jetbrains.annotations.NotNull;

import java.util.Arrays;

public class ChatCmd extends ListenerAdapter {

    private static final String noPerm = "```\n你沒有權限使用此指令！ 請向管理員申請！\n```";

    private static GuildMessageReceivedEvent event;

    private static void cmd_w_LogService(User sender, String logText) {
        if (sender.isBot()) {
            Config.log(logText);
        } else {
            Config.log_withPrintln(sender.getAsTag() + ": w:" + logText);
        }
    }

    private static Message getMsg() {
        return event.getMessage();
    }

    private static Member getMember() {
        return event.getMember();
    }

    private static User getUser() {
        return getMember().getUser();
    }

    private static User getSelfUser() {
        return App.jda.getSelfUser();
    }

    public static String getHelpMsg() {
        return "歡迎使用Discord訊息記錄工具\n" +
                "以下為本工具的指令：\n\n" +
                "後台指令：\n" +
                "auto_login <true/false> - 開關機器人自動登入\n" +
                "noPermReply <true/false> - 開關幫助訊息和錯誤訊息（僅對一般使用者有效）\n" +
                "stop - 關閉機器人\n\n" +
                "所有者指令：\n" +
                "admin_add <@成員> - 將成員升級為管理員\n" +
                "admin_remove <@成員> - 將成員從管理員移除\n\n" +
                "管理員指令：\n" +
                "admin_list - 列出所有管理員\n" +
                "ignored_add <@成員> - 將成員加入忽略名單內\n" +
                "ignored_remove <@成員> - 將成員從忽略名單內移除\n" +
                "ignored_list - 列出忽略名單\n";
    }

    public static boolean isCommand(net.dv8tion.jda.api.entities.Message cmd) { // if getMsg() is cmd
        if (MessageReceived.isImage(cmd)) return false;
        String display = cmd.getContentDisplay();
        return display.startsWith("w:") ||
                display.charAt(0) == '!' ||
                display.startsWith(";;");
    }

    @Override
    public void onGuildMessageReceived(@NotNull GuildMessageReceivedEvent cmd_event) {
        event = cmd_event;
        String[] msg_args = getMsg().getContentStripped().split(" ");
        if (!event.getAuthor().isBot() &&
                !MessageReceived.isImage(getMsg()) &&
                (msg_args[0].length() >= 2)) { // getMsg() (isn't from bot) or (isn't image) and (length of getMsg() is more than 2)
            //
            String prefix = msg_args[0].substring(0, 2); // make prefix "w:"
            String cmd_without_prefix = msg_args[0].substring(2); //make text behind "w:"
            if (prefix.equals("w:")) {
                for (Object obj :
                        Arrays.stream(cmd_w_enum.values()).toArray()) {
                    if (cmd_without_prefix.equals(obj.toString())) {
                        cmd_w_enum.valueOf(cmd_without_prefix).run();
                        return;
                    }
                }
                getMsg().reply("```\n找不到此指令！\n```").queue();
                Config.log_withPrintln(getUser().getAsTag() + ": w:" + cmd_without_prefix + " (Failed - Invalid commands)");
            }
        }
    }

    public enum cmd_w_enum implements cmd_w_Service {
        help() {
            final String help_msg = getHelpMsg();

            @Override
            public void run() {
                if (!Config.isAdmin(getMember()) && !Config.isNoPermReply()) return;
                getMsg().reply("```\n" + help_msg + "```").queue();
                Config.log_withPrintln(getUser().getAsTag() + ": w:help");
            }

            @Override
            public void console_run(String input) {
                System.out.println(help_msg);
                Config.log("help");
            }
        },
        admin_list() {
            private String adminList_generator() {
                StringBuilder sb = new StringBuilder();
                sb.append("管理員名單：\n\n");
                long[] list = Config.listAdmins();
                //filter
                if (list == null) {
                    sb.append("目前無管理員！\n");
                    return sb.toString();
                }
                if (list.length == 0) {
                    sb.append("目前無管理員！\n");
                    return sb.toString();
                }
                //main code
                for (long adminID :
                        list) {
                    for (User all :
                            App.jda.getUsers()) {
                        if (all.getId().equals(String.valueOf(adminID))) {
                            sb.append(all.getAsTag()).append("\n");
                        }
                    }
                }
                return sb.toString();
            }

            @Override
            public void run() {
                //permission
                if (!Config.isAdmin(getMember())) {
                    if (Config.isNoPermReply()) getMsg().reply(noPerm).queue();
                    Config.log_withPrintln(getUser().getAsTag() + ": w:admin_list (Failed - Permission)");
                    return;
                }
                getMsg().reply("```\n" + adminList_generator() + "```").queue();
                Config.log_withPrintln(getUser().getAsTag() + ": w:admin_list");
            }

            @Override
            public void console_run(String input) {
                System.out.println(adminList_generator());
                Config.log(input);
            }
        },
        ignored_list() {
            private String ignoredlist_generator() {
                StringBuilder sb = new StringBuilder();
                sb.append("忽略名單：\n\n");
                long[] list = Config.listIgnoreds();
                //filter
                if (list == null) {
                    sb.append("目前無人被忽略！\n");
                    return sb.toString();
                }
                if (list.length == 0) {
                    sb.append("目前無人被忽略！\n");
                    return sb.toString();
                }
                //main code
                for (long ignoredID :
                        list) {
                    for (User all :
                            App.jda.getUsers()) {
                        if (all.getId().equals(String.valueOf(ignoredID))) {
                            sb.append(all.getAsTag()).append("\n");
                        }
                    }
                }
                return sb.toString();
            }

            @Override
            public void run() {
                //permission
                if (!Config.isAdmin(getMember())) {
                    if (Config.isNoPermReply()) getMsg().reply(noPerm).queue();
                    Config.log_withPrintln(getUser().getAsTag() + ": w:ignored_list (Failed - Permission)");
                    return;
                }
                getMsg().reply("```\n" + ignoredlist_generator() + "```").queue();
                Config.log_withPrintln(getUser().getAsTag() + ": w:ignored_list");
            }

            @Override
            public void console_run(String input) {
                System.out.println(ignoredlist_generator());
                Config.log("ignored_list");
            }
        },
        admin_add() {
            private String add(User sender, String cmd) {
                StringBuilder sb = new StringBuilder();
                //filter
                if (cmd.split(" ").length < 2) {
                    sb.append("請輸入輸入成員並提及！");
                    cmd_w_LogService(sender, "admin_add (Failed - No args)");
                    return sb.toString();
                }
                //search admin
                Member admin = null;
                String tag = (cmd.split("@"))[1];
                for (User a :
                        App.jda.getUsers()) {
                    Member b = App.jda.getGuildById("844738910734254092").getMember(a);
                    if (b.getNickname() != null) {
                        if (b.getNickname().equals(tag)) admin = b;
                    } else {
                        if (a.getName().equals(tag)) admin = b;
                    }
                }
                //filter
                if (admin == null) {
                    cmd_w_LogService(sender, "admin_remove (Failed - Can't find)");
                    sb.append("找不到此玩家！");
                    return sb.toString();
                }
                //
                if (Config.addAdmin(admin)) {
                    cmd_w_LogService(sender, "admin_add （" + admin.getUser().getAsTag() + "）");
                    sb.append("成功將 " + admin.getUser().getAsTag() + " 新增至管理員");
                } else {
                    cmd_w_LogService(sender, "admin_add （" + admin.getUser().getAsTag() + "） (Failed - Already is)");
                    sb.append(admin.getUser().getAsTag() + " 已經是管理員！");
                }
                return sb.toString();
            }

            @Override
            public void run() {
                //permission
                if (!Config.isOwner(getMember())) {
                    if (Config.isNoPermReply()) getMsg().reply("```\n此指令只能由所有者使用！\n```").queue();
                    Config.log_withPrintln(getUser().getAsTag() + ": w:admin_add (Failed - Permission)");
                    return;
                }
                getMsg().reply("```\n" + add(getUser(), getMsg().getContentDisplay()) + "\n```").queue();
            }

            @Override
            public void console_run(String input) {
                System.out.println(add(getSelfUser(), input));
            }
        },
        admin_remove() {
            private String remove(User sender, String cmd) {
                StringBuilder sb = new StringBuilder();
                //filter
                if (cmd.split(" ").length < 2) {
                    sb.append("請輸入輸入成員並提及！");
                    cmd_w_LogService(sender, "admin_add (Failed - No args)");
                    return sb.toString();
                }
                //main code
                Member admin = null;
                String tag = (cmd.split("@"))[1];
                for (User a :
                        App.jda.getUsers()) {
                    Member b = App.jda.getGuildById("844738910734254092").getMember(a);
                    if (b.getNickname() != null) {
                        if (b.getNickname().equals(tag)) admin = b;
                    } else {
                        if (a.getName().equals(tag)) admin = b;
                    }
                }
                //filter
                if (admin == null) {
                    cmd_w_LogService(sender, "admin_remove (Failed - Can't find)");
                    sb.append("找不到此玩家！");
                    return sb.toString();
                }
                //
                if (Config.removeAdmin(admin)) {
                    cmd_w_LogService(sender, "admin_remove （" + admin.getUser().getAsTag() + "）");
                    sb.append("成功將 " + admin.getUser().getAsTag() + " 從管理員移除");
                } else {
                    cmd_w_LogService(sender, "admin_remove （" + admin.getUser().getAsTag() + "） (Failed - Already isn't)");
                    sb.append(admin.getUser().getAsTag() + " 不是管理員！");
                }
                return sb.toString();
            }

            @Override
            public void run() {
                //permission
                if (!Config.isOwner(getMember())) {
                    if (Config.isNoPermReply()) getMsg().reply("```\n此指令只能由所有者使用！\n```").queue();
                    Config.log_withPrintln(getUser().getAsTag() + ": w:admin_remove (Failed - Permission)");
                    return;
                }
                getMsg().reply("```\n" + remove(getUser(), getMsg().getContentDisplay()) + "\n```").queue();
            }

            @Override
            public void console_run(String input) {
                System.out.println(remove(getSelfUser(), input));
            }
        },
        ignored_add() {
            private String add(User sender, String cmd) {
                StringBuilder sb = new StringBuilder();
                //filter
                if (cmd.split(" ").length < 2) {
                    cmd_w_LogService(sender, "ignored_add (Failed - No args)");
                    sb.append("請輸入輸入成員並提及！");
                    return sb.toString();
                }
                //main code
                Member ignored = null;
                String tag = (cmd.split("@"))[1];
                for (User a :
                        App.jda.getUsers()) {
                    Member b = App.jda.getGuildById("844738910734254092").getMember(a);
                    if (b.getNickname() != null) {
                        if (b.getNickname().equals(tag)) ignored = b;
                    } else {
                        if (a.getName().equals(tag)) ignored = b;
                    }
                }
                //filter
                if (ignored == null) {
                    cmd_w_LogService(sender, "ignored_add (Failed - Can't find)");
                    sb.append("找不到此玩家！");
                    return sb.toString();
                }
                //
                if (Config.addIgnored(ignored)) {
                    cmd_w_LogService(sender, "ignored_add （" + ignored.getUser().getAsTag() + "）");
                    sb.append("成功將 " + ignored.getUser().getAsTag() + " 新增至忽略名單");
                } else {
                    cmd_w_LogService(sender, "ignored_add （" + ignored.getUser().getAsTag() + "） (Failed - Already is)");
                    sb.append(ignored.getUser().getAsTag() + " 已經在忽略名單內！");
                }
                return sb.toString();
            }

            @Override
            public void run() {
                //permission
                if (!Config.isAdmin(getMember())) {
                    if (Config.isNoPermReply()) getMsg().reply(noPerm).queue();
                    Config.log_withPrintln(getUser().getAsTag() + ": w:ignored_add (Failed - Permission)");
                    return;
                }
                getMsg().reply("```\n" + add(getUser(), getMsg().getContentDisplay()) + "\n```").queue();
            }

            @Override
            public void console_run(String input) {
                System.out.println(add(getSelfUser(), input));
            }
        },
        ignored_remove() {
            private String remove(User sender, String cmd) {
                StringBuilder sb = new StringBuilder();
                //filter
                if (cmd.split(" ").length < 2) {
                    cmd_w_LogService(sender, "ignored_remove (Failed - No args)");
                    sb.append("請輸入輸入成員並提及！");
                    return sb.toString();
                }
                //main code
                Member ignored = null;
                String tag = (cmd.split("@"))[1];
                for (User a :
                        App.jda.getUsers()) {
                    Member b = App.jda.getGuildById("844738910734254092").getMember(a);
                    if (b.getNickname() != null) {
                        if (b.getNickname().equals(tag)) ignored = b;
                    } else {
                        if (a.getName().equals(tag)) ignored = b;
                    }
                }
                //filter
                if (ignored == null) {
                    cmd_w_LogService(sender, "ignored_remove (Failed - Can't find)");
                    sb.append("找不到此玩家！");
                    return sb.toString();
                }
                //
                if (Config.removeIgnored(ignored)) {
                    cmd_w_LogService(sender, "ignored_remove （" + ignored.getUser().getAsTag() + "）");
                    sb.append("成功將 ").append(ignored.getUser().getAsTag()).append(" 從忽略名單移除");
                } else {
                    cmd_w_LogService(sender, "ignored_remove （" + ignored.getUser().getAsTag() + "） (Failed - Already isn't)");
                    sb.append(ignored.getUser().getAsTag()).append(" 不在忽略名單內！");
                }
                return sb.toString();
            }

            @Override
            public void run() {
                //permission
                if (!Config.isAdmin(getMember())) {
                    if (Config.isNoPermReply()) getMsg().reply(noPerm).queue();
                    Config.log_withPrintln(getUser().getAsTag() + ": w:ignored_remove (Failed - Permission)");
                    return;
                }
                getMsg().reply("```\n" + remove(getUser(), getMsg().getContentDisplay()) + "\n```").queue();
            }

            @Override
            public void console_run(String input) {
                System.out.println(remove(getSelfUser(), input));
            }
        },
        auto_login() {
            @Override
            public void run() {
                if (Config.isNoPermReply()) getMsg().reply("```\n此指令只能由後台執行！\n```").queue();
                Config.log_withPrintln(getUser().getAsTag() + ": w:auto_login (Failed - Console Only)");
            }

            @Override
            public void console_run(String input) {
                String[] args = input.split(" ");
                if (args.length < 2) {
                    Config.log("auto_login (Failed - No args)");
                    System.out.println("請輸入設定值");
                    return;
                }
                if (!(args[1].equals("true") || args[1].equals("false"))) {
                    Config.log("auto_login (Failed - Args is not boolean)");
                    System.out.println("請輸入 true 或 false");
                    return;
                }
                Config.setAutoLoginEnable(args[1].equals("true"));
            }
        },
        noPermReply() {
            @Override
            public void run() {
                if (Config.isNoPermReply()) getMsg().reply("```\n此指令只能由後台執行！\n```").queue();
                Config.log_withPrintln(getUser().getAsTag() + ": w:noPermReply (Failed - Console Only)");
            }

            @Override
            public void console_run(String input) {
                String[] args = input.split(" ");
                if (args.length < 2) {
                    Config.log("noPermReply (Failed - No args)");
                    System.out.println("請輸入設定值");
                    return;
                }
                if (!(args[1].equals("true") || args[1].equals("false"))) {
                    Config.log("noPermReply (Failed - Args is not boolean)");
                    System.out.println("請輸入 true 或 false");
                    return;
                }
                Config.setNoPermReplyEnable(args[1].equals("true"));
            }
        },
        stop() {
            @Override
            public void run() {
                if (Config.isNoPermReply()) getMsg().reply("```\n此指令只能由後台執行！\n```").queue();
                Config.log_withPrintln(getUser().getAsTag() + ": w:stop (Failed - Console Only)");
            }

            @Override
            public void console_run(String input) {
                Config.log("\nstop");
                App.jda.shutdown();
                ConsoleCmd.stop = true;
                System.exit(0);
            }
        }
    }

    private interface cmd_w_Service {
        void run();

        void console_run(String whole_msg);
    }
}