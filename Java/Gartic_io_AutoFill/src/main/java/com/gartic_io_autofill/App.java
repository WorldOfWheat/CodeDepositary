package com.gartic_io_autofill;

import java.awt.*;
import java.awt.datatransfer.Clipboard;
import java.awt.datatransfer.StringSelection;
import java.awt.event.KeyEvent;
import java.io.File;
import java.io.IOException;
import java.nio.file.Files;

public class App {
    public static void main(String[] args) {
        try {
            File database = new File("G:\\我的雲端硬碟\\備份\\程式\\Java\\實作\\Gartic_io_AutoFill\\test.txt");
            String[] words = new String(Files.readAllBytes(database.toPath()))
                .split("\n");
            Robot test = new Robot();
            test.delay(2000);
            for (String a:
                 words) {
                System.out.println(a);
                StringSelection data  = new StringSelection(a);
                Clipboard clipboard = Toolkit.getDefaultToolkit().getSystemClipboard();
                clipboard.setContents(data,data);
                test.mouseMove(180, 845);
                test.delay(18);
                test.mousePress(KeyEvent.BUTTON1_DOWN_MASK);
                test.mouseRelease(KeyEvent.BUTTON1_DOWN_MASK);
                test.delay(18);
                test.keyPress(KeyEvent.VK_CONTROL);
                test.keyPress(KeyEvent.VK_V);
                test.delay(18);
                test.keyRelease(KeyEvent.VK_V);
                test.keyRelease(KeyEvent.VK_CONTROL);
                test.delay(18);
                test.mouseMove(414, 841);
                test.mousePress(KeyEvent.BUTTON1_DOWN_MASK);
                test.mouseRelease(KeyEvent.BUTTON1_DOWN_MASK);
                test.delay(18);
            }
        } catch (AWTException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        }
        //180 845
        //414 841
        
    }
}
