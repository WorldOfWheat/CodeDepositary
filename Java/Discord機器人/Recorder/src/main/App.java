package main;

import main.DiscordInput.ChatCmd;
import main.Thread.ConsoleCmd;
import main.api.Config;
import main.event.MessageReceived;
import net.dv8tion.jda.api.JDA;
import net.dv8tion.jda.api.JDABuilder;
import net.dv8tion.jda.api.OnlineStatus;
import net.dv8tion.jda.api.requests.GatewayIntent;
import net.dv8tion.jda.api.utils.ChunkingFilter;
import net.dv8tion.jda.api.utils.MemberCachePolicy;

import java.util.Scanner;

public class App {
    public static JDA jda;

    public static void main(String[] args) {
        try {
            welcome(); //show welcome message
            Config.file_create(); // config and create
            Config.settings_check(); // config data is correct
            String token;
            if (Config.isAutoLogin()) { // autologin is on
                token = Config.getToken();
            } else {
                //manual input
                Config.log_withPrintln("自動登入已關閉，需要手動輸入Token");
                Scanner sc = new Scanner(System.in);
                token = sc.nextLine();
                Config.log(token);
            }
            jda = JDABuilder.createDefault(token).
                    setChunkingFilter(ChunkingFilter.ALL). // enable member chunking for all guilds
                    setMemberCachePolicy(MemberCachePolicy.ALL). // ignored if chunking enabled
                    enableIntents(GatewayIntent.GUILD_MEMBERS).
                    setStatus(OnlineStatus.INVISIBLE).build();
            jda.awaitReady();
            jda.addEventListener(new MessageReceived(), new ChatCmd());
            new ConsoleCmd().start();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    private static void welcome() {
        Config.log("\nstart");
        Config.log_withPrintln("-------------------------");
        Config.log_withPrintln("歡迎使用Discord訊息記錄工具");
        Config.log_withPrintln("版本： 1.0");
        Config.log_withPrintln("作者： 小麥 WorldOfWheat");
        Config.log_withPrintln("-------------------------");
    }

}
