package main.api;

import net.dv8tion.jda.api.entities.Member;
import org.json.simple.JSONArray;
import org.json.simple.JSONObject;
import org.json.simple.parser.JSONParser;
import org.json.simple.parser.ParseException;

import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.Scanner;

public class Config {
    private static final File folder = new File("C:\\discord_recorder");
    private static final File settings = new File("C:\\discord_recorder\\settings.json");
    private static final File log = new File("C:\\discord_recorder\\log.yml");
    private static final File message_log = new File("C:\\discord_recorder\\message_log.yml");

    //json manage
    private static JSONObject getSettingsJson() {
        try {
            FileReader reader = new FileReader(settings);
            JSONParser jsonParser = new JSONParser();
            Object p = jsonParser.parse(reader);
            JSONObject input = (JSONObject) p;
            return input;
        } catch (ParseException | IOException e) {
            e.printStackTrace();
        }
        return null;
    }

    private static void writeSettingsJson(JSONObject json) {
        try {
            Files.write(settings.toPath(), json.toJSONString().getBytes(StandardCharsets.UTF_8));
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    //role manage
    private static boolean addRoleJson(Member member, String jsonName) {
        JSONObject json = getSettingsJson();
        JSONArray list = (JSONArray) json.get(jsonName);
        if (list != null) {
            for (Object m :
                    list) {
                if (m.equals(member.getId())) {
                    return false;
                }
            }
        } else {
            list = new JSONArray();
        }
        list.add(member.getId());
        json.put(jsonName, list);
        writeSettingsJson(json);
        return true;
    }

    private static boolean removeRoleJson(Member member, String jsonName) {
        JSONObject json = getSettingsJson();
        JSONArray list = (JSONArray) json.get(jsonName);
        if (list != null) {
            for (Object m :
                    list) {
                if (m.equals(member.getId())) {
                    list.remove(m);
                    json.put(jsonName, list);
                    writeSettingsJson(json);
                    return true;
                }
            }
        }
        return false;
    }

    private static long[] listRoles(String jsonName) {
        JSONObject json = getSettingsJson();
        JSONArray list = (JSONArray) json.get(jsonName);
        if (list != null) {
            long[] ID_list = new long[list.toArray().length];
            for (int i = 0; i < ID_list.length; i++) {
                ID_list[i] = Long.parseLong(list.get(i).toString());
            }
            return ID_list;
        } else {
            return null;
        }
    }

    private static boolean isRole(Member member, String jsonName) {
        JSONObject json = getSettingsJson();
        JSONArray list = (JSONArray) json.get(jsonName);
        if (list != null) {
            for (Object m :
                    list) {
                if (member.getId().equals(m)) {
                    return true;
                }
            }
        }
        return false;
    }

    //file manage and log
    public static void settings_check() { //default settings input and set
        Scanner sc = new Scanner(System.in);
        JSONObject json = getSettingsJson();
        if (json.get("token") == null) {
            log_withPrintln("未偵測到機器人Token");
            log_withPrintln("請輸入你從Discord開發者介面複製Token：");
            log_withPrintln("-------------------------");
            String token = sc.nextLine();
            log(token);
            json.put("token", token);

        }
        if (json.get("log_channel_ID") == null) {
            log_withPrintln("請輸入你想要將訊息記錄的頻道");
            log_withPrintln("頻道ID：");
            log_withPrintln("-------------------------");
            String ID = sc.nextLine();
            log(ID);
            json.put("log_channel_ID", ID);

        }
        if (json.get("owner_ID") == null) {
            log_withPrintln("請輸入所有者ID （所有者將擁有機器人的完全操控權）");
            log_withPrintln("所有者ID：");
            log_withPrintln("-------------------------");
            String ID = sc.nextLine();
            log(ID);
            json.put("owner_ID", ID);

        }
        json.putIfAbsent("auto_login", true);
        json.putIfAbsent("isNoPermReply", false);
        writeSettingsJson(json);
    }

    public static void file_create() { //create default file
        try {
            log_withPrintln("檔案檢查中. . .");
            if (!folder.exists()) {
                System.out.println("創造新資料夾中. . .");
                folder.mkdirs();
            }
            if (!settings.exists()) {
                log_withPrintln("創造設定檔中. . .");
                settings.createNewFile();
                Files.write(settings.toPath(), "{}".getBytes(StandardCharsets.UTF_8));
            }
            if (!log.exists()) {
                System.out.println("創造紀錄檔中. . .");
                log.createNewFile();
            }
            if (!message_log.exists()) {
                log_withPrintln("創造Discord訊息紀錄檔中. . .\n");
                message_log.createNewFile();
            }
            log_withPrintln("檔案檢查完成");
            log_withPrintln("-------------------------");
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static void log(String data) { //log data
        try {
            if (log.exists()) {
                SimpleDateFormat sf = new SimpleDateFormat("yyyy-MM-dd - HH:mm:ss");
                String record = "[" + sf.format(new Date()) + "] " + data + "\n";
                Files.write(log.toPath(), record.getBytes(StandardCharsets.UTF_8),
                        java.nio.file.StandardOpenOption.APPEND);
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static void log_withPrintln(String data) { //log data along with println
        System.out.println(data);
        log(data);
    }

    public static void message_log(String data) { //log chat msg
        try {
            if (message_log.exists()) {
                Files.write(message_log.toPath(), (data + "\n").getBytes(StandardCharsets.UTF_8),
                        java.nio.file.StandardOpenOption.APPEND);
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    //set and if config
    public static String getToken() {
        return getSettingsJson().get("token").toString();
    }

    public static String getMessageLogChannelID() {
        return getSettingsJson().get("log_channel_ID").toString();
    }

    public static void setAutoLoginEnable(boolean enable) { //set if login directly (auto_login)
        JSONObject json = getSettingsJson();
        if (json.get("auto_login").equals(true) == enable) {
            System.out.println("auto_login 的值已是 " + enable);
            log("auto_login (Failed - Already is " + enable + ")");
            return;
        }
        json.put("auto_login", enable);
        writeSettingsJson(json);
        System.out.println("已將 auto_login 的值設為 " + enable);
        log("auto_login set to " + enable);
    }

    public static void setNoPermReplyEnable(boolean enable) { //set if sender doesn't have perm, will it reply?)
        JSONObject json = getSettingsJson();
        if (json.get("isNoPermReply").equals(true) == enable) {
            System.out.println("auto_login 的值已是 " + enable);
            log("auto_login (Failed - Already is " + enable + ")");
            return;
        }
        json.put("isNoPermReply", enable);
        writeSettingsJson(json);
        System.out.println("已將 noPermReply 的值設為 " + enable);
        log("noPermReply set to " + enable);
    }

    public static boolean isAutoLogin() {
        return getSettingsJson().get("auto_login").toString().equals("true");
    }

    public static boolean isNoPermReply() {
        return !getSettingsJson().get("isNoPermReply").toString().equals("true");
    }

    public static boolean isOwner(Member a) {
        return getSettingsJson().get("owner_ID").equals(a.getId());
    }

    //Admin
    public static boolean addAdmin(Member a) {
        return addRoleJson(a, "admin");
    }

    public static boolean removeAdmin(Member a) {
        return removeRoleJson(a, "admin");
    }

    public static long[] listAdmins() {
        return listRoles("admin");
    }

    public static boolean isAdmin(Member a) {
        return isRole(a, "admin") || isOwner(a);
    }

    //Ignored
    public static boolean addIgnored(Member a) {
        return addRoleJson(a, "ignored");
    }

    public static boolean removeIgnored(Member a) {
        return removeRoleJson(a, "ignored");
    }

    public static long[] listIgnoreds() {
        return listRoles("ignored");
    }

    public static boolean isIgnored(Member a) {
        return isRole(a, "ignored");
    }
}
