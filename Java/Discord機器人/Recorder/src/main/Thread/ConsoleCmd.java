package main.Thread;

import main.DiscordInput.ChatCmd;
import main.api.Config;

import java.util.Arrays;
import java.util.Scanner;

public class ConsoleCmd extends Thread {
    public static boolean stop = false;

    public void run() {
        Scanner sc = new Scanner(System.in);
        System.out.println(ChatCmd.getHelpMsg());
        while (!stop) {
            String cmd = sc.nextLine(); //get text from console
            boolean invalid = true; //invalid command
            String[] args = cmd.split(" "); //get args
            for (Object obj : //get all command in enum
                    Arrays.stream(ChatCmd.cmd_w_enum.values()).toArray()) {
                if (args[0].equals(obj.toString())) {
                    ChatCmd.cmd_w_enum.valueOf(args[0]).console_run(cmd);
                    invalid = false;
                }
            }
            if (invalid && !args[0].equals("")) {
                System.out.println("找不到此指令！");
                Config.log(cmd + " (Failed - Invalid commands)");
            }
        }
    }
}
