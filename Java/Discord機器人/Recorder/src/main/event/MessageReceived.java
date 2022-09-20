package main.event;

import main.DiscordInput.ChatCmd;
import main.api.Config;
import net.dv8tion.jda.api.entities.Message.Attachment;
import net.dv8tion.jda.api.entities.TextChannel;
import net.dv8tion.jda.api.events.message.MessageReceivedEvent;
import net.dv8tion.jda.api.hooks.ListenerAdapter;

import java.text.SimpleDateFormat;
import java.util.Date;

public class MessageReceived extends ListenerAdapter {
    public static boolean isImage(net.dv8tion.jda.api.entities.Message msg) {
        boolean isImage = false;
        for (net.dv8tion.jda.api.entities.Message.Attachment a :
                msg.getAttachments()) {
            isImage = a.isImage();
        }
        return isImage;
    }

    public void onMessageReceived(MessageReceivedEvent event) {
        if (!event.getAuthor().isBot() && // (msg isn't from bot) and (isn't ignored) and (isn't command)
                !Config.isIgnored(event.getMember()) &&
                !ChatCmd.isCommand(event.getMessage())) {
            //format make
            TextChannel record = event.getJDA().getTextChannelById(Config.getMessageLogChannelID());
            String channel_name = event.getChannel().getName();
            String sender_name = event.getAuthor().getAsTag();
            String sender_nickname = event.getMember().getNickname();
            String format = "[" + this.getTime() + "] [" + channel_name + "] [" +
                    sender_name + "] " + sender_nickname + ": ";
            if (sender_nickname == null) { //if sender doesn't have nickname
                format = "[" + this.getTime() + "] [" + channel_name + "] [" +
                        sender_name + "] : ";
            }
            //print
            if (!isImage(event.getMessage())) { //text
                String result = format + event.getMessage().getContentDisplay(); // + " (" + event.getMessageId() + ")"
                record.sendMessage(result).queue();
                Config.message_log(result);
                System.out.println(result);
            } else { //image
                for (Attachment a :
                        event.getMessage().getAttachments()) {
                    String result = format + a.getUrl(); // + " (" + event.getMessageId() + ")"
                    record.sendMessage(result).queue();
                    Config.message_log(result);
                    System.out.println(result);
                }
            }
        }
    }

    private String getTime() {
        SimpleDateFormat sf = new SimpleDateFormat("yyyy-MM-dd - HH:mm:ss");
        return sf.format(new Date());
    }
}
