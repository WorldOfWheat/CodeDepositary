package com.encrypt_AES.gui;

import javax.swing.*;
import java.awt.*;
import java.awt.event.WindowEvent;
import java.awt.event.WindowListener;

public class helpMsg {
    private final JFrame jf = new JFrame("資訊");
    private final JTextArea info = new JTextArea();
    private final JScrollPane jsp = new JScrollPane(info);
    private final Container caller;

    public helpMsg(Container a) {
        this.caller = a;
        this.open();
    }

    private void open() {
        Font font = new Font("SansSerif", Font.BOLD, 18);
        //
        jf.setDefaultCloseOperation(JFrame.DO_NOTHING_ON_CLOSE);
        jf.setLayout(new GridBagLayout());
        jf.addWindowListener(new WindowListener() {
            @Override
            public void windowOpened(WindowEvent e) {
                // when open file_mode
                caller.setEnabled(false);
            }

            @Override
            public void windowClosing(WindowEvent e) {
                // when close file_mode
                caller.setEnabled(true);
                caller.setBounds(500, 200, 900, 600);
                jf.setVisible(false);
            }

            @Override
            public void windowClosed(WindowEvent e) {
            }

            @Override
            public void windowIconified(WindowEvent e) {
            }

            @Override
            public void windowDeiconified(WindowEvent e) {
            }

            @Override
            public void windowActivated(WindowEvent e) {
            }

            @Override
            public void windowDeactivated(WindowEvent e) {
            }
        });
        jf.setBounds(1400, 200, 350, 750);
        //
        info.setEditable(false);
        info.setFont(font);
        info.setText("歡迎使用AES加密系統\n" +
                "作者：小麥 WorldOfWheat\n" +
                "版本：1.4.3\n" +
                "\n" +
                "更新紀錄：\n" +
                "\n" +
                "v1.4.3:\n" +
                "- 優化程式碼\n" +
                "- 改為發怖版\n" +
                "\n" +
                "v1.4.2:\n" +
                "- 新增資訊按鈕\n" +
                "- 優化程式碼\n" +
                "\n" +
                "v1.4.1:\n" +
                "- 新增金鑰長度選擇按鈕 128/256\n" +
                "- 優化程式碼\n" +
                "\n" +
                "v1.4\n" +
                "- 新增加密時必需再次輸入密碼\n" +
                "\n" +
                "v1.1:\n" +
                "- 新增檔案模式\n" +
                "\n" +
                "v1.0:\n" +
                "- 第一版製作完成");
        jf.add(jsp);
        //
        jf.setVisible(true);
    }
}
