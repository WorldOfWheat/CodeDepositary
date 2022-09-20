package com.encrypt_AES.gui;

import com.encrypt_AES.api.AES;
import com.encrypt_AES.api.SHA256;

import javax.swing.*;
import java.awt.*;
import java.awt.event.FocusEvent;
import java.awt.event.FocusListener;
import java.util.Base64;

public class main {
    private final JLabel jl1 = new JLabel("加密內容：");
    private final JLabel jl2 = new JLabel("解密內容：");
    private final JLabel jl3 = new JLabel("密碼");
    private final JLabel jl4 = new JLabel("確認密碼");
    private final JPasswordField jpf1 = new JPasswordField();
    private final JPasswordField jpf2 = new JPasswordField();
    private final JTextArea jta1 = new JTextArea();
    private final JTextArea jta2 = new JTextArea();
    private final JScrollPane jsp1 = new JScrollPane(jta1);
    private final JScrollPane jsp2 = new JScrollPane(jta2);
    private final JButton jb1 = new JButton("加密");
    private final JButton jb2 = new JButton("解密");
    private final JButton jb3 = new JButton("執行");
    private final JButton jb4 = new JButton("檔案模式");
    private final JButton jb5 = new JButton("AES-128 模式");
    private final JButton jb6 = new JButton("?");
    private final Container pane;
    private int AES_keylengh = 128;

    public main(Container a) {
        this.pane = a;
    }

    public void use() {
        Font font = new Font("SansSerif", Font.BOLD, 18);
        GridBagConstraints gbc;
        // lable
        // text above encrypt area
        gbc = new GridBagConstraints();
        gbc.gridx = 0;
        gbc.gridy = 0;
        gbc.anchor = GridBagConstraints.CENTER;
        gbc.insets = new Insets(0, 0, 10, 0);
        jl1.setFont(font);
        pane.add(jl1, gbc);
        // text above decrypt area
        gbc = new GridBagConstraints();
        gbc.gridx = 3;
        gbc.gridy = 0;
        gbc.anchor = GridBagConstraints.CENTER;
        jl2.setFont(font);
        pane.add(jl2, gbc);
        // pwd
        gbc = new GridBagConstraints();
        gbc.gridx = 0;
        gbc.gridy = 3;
        gbc.anchor = GridBagConstraints.WEST;
        gbc.insets = new Insets(6, 8, 0, 0);
        jl3.setFont(font);
        jl3.setVisible(false);
        pane.add(jl3, gbc);
        // pwd verfied
        gbc = new GridBagConstraints();
        gbc.gridx = 0;
        gbc.gridy = 4;
        gbc.anchor = GridBagConstraints.WEST;
        gbc.insets = new Insets(6, 8, 0, 0);
        jl4.setFont(font);
        jl4.setVisible(false);
        pane.add(jl4, gbc);
        // text area
        // left
        gbc = new GridBagConstraints();
        gbc.gridx = 0;
        gbc.gridy = 1;
        gbc.ipadx = 300;
        gbc.ipady = 300;
        gbc.anchor = GridBagConstraints.WEST;
        jta1.setFont(font);
        jta1.setEditable(false);
        pane.add(jsp1, gbc);
        // right
        gbc = new GridBagConstraints();
        gbc.gridx = 3;
        gbc.gridy = 1;
        gbc.ipadx = 300;
        gbc.ipady = 300;
        gbc.anchor = GridBagConstraints.WEST;
        jta2.setLineWrap(true);
        jta2.setFont(font);
        jta2.setEditable(false);
        pane.add(jsp2, gbc);
        // password field
        // pwd
        gbc = new GridBagConstraints();
        gbc.gridx = 0;
        gbc.gridy = 3;
        gbc.ipadx = 318;
        gbc.ipady = 5;
        gbc.gridwidth = 0;
        gbc.anchor = GridBagConstraints.WEST;
        gbc.insets = new Insets(10, 0, 0, 0);
        jpf1.addFocusListener(new FocusListener() {

            @Override
            public void focusGained(FocusEvent e) {
                jl3.setVisible(false);
            }

            @Override
            public void focusLost(FocusEvent e) {
                if ((getPwd().length() == 0) && (jb1.isEnabled() ^ jb2.isEnabled())) {
                    jl3.setVisible(true);
                }
            }
        });
        jpf1.setFont(font);
        jpf1.setEditable(false);
        pane.add(jpf1, gbc);
        // pwd verfied
        gbc = new GridBagConstraints();
        gbc.gridx = 0;
        gbc.gridy = 4;
        gbc.ipadx = 318;
        gbc.ipady = 5;
        gbc.gridwidth = 0;
        gbc.anchor = GridBagConstraints.WEST;
        gbc.insets = new Insets(10, 0, 0, 0);
        jpf2.addFocusListener(new FocusListener() {

            @Override
            public void focusGained(FocusEvent e) {
                jl4.setVisible(false);
            }

            @Override
            public void focusLost(FocusEvent e) {
                if ((getPwd_verified().length() == 0) &&
                        (jb1.isEnabled() ^ jb2.isEnabled()) &&
                        jb2.isEnabled()) {
                    jl4.setVisible(true);
                }
            }
        });
        jpf2.setFont(font);
        jpf2.setEditable(false);
        pane.add(jpf2, gbc);
        // button
        // encrypt
        gbc = new GridBagConstraints();
        gbc.gridx = 0;
        gbc.gridy = 2;
        gbc.anchor = GridBagConstraints.WEST;
        gbc.insets = new Insets(10, 0, 0, 0);
        jb1.setFont(font);
        jb1.addActionListener(e -> {
            jb1.setEnabled(false);
            jb2.setEnabled(true);
            jb3.setEnabled(true);
            jta1.setEditable(true);
            jta2.setEditable(false);
            // password field
            jpf1.setEditable(true);
            jpf2.setEditable(true);
            jl3.setVisible(true);
            jl4.setVisible(true);
        });
        pane.add(jb1, gbc);
        // decrypt
        gbc = new GridBagConstraints();
        gbc.gridx = 3;
        gbc.gridy = 2;
        gbc.anchor = GridBagConstraints.EAST;
        gbc.insets = new Insets(10, 0, 0, 0);
        jb2.setFont(font);
        jb2.addActionListener(e -> {
            jb1.setEnabled(true);
            jb2.setEnabled(false);
            jb3.setEnabled(true);
            jta1.setEditable(false);
            jta2.setEditable(true);
            // password field
            jpf1.setEditable(true);
            jpf2.setEditable(false);
            jl3.setVisible(true);
            jl4.setVisible(false);
            jpf2.setText("");
        });
        pane.add(jb2, gbc);
        // execute
        gbc = new GridBagConstraints();
        gbc.gridx = 1;
        gbc.gridy = 1;
        gbc.insets = new Insets(0, 10, 0, 10);
        jb3.setFont(font);
        jb3.setEnabled(false);
        jb3.addActionListener(e -> {
            if ((jb1.isEnabled() ^ jb2.isEnabled()) && (getPwd().length() != 0) &&
                    (getPwd().equals(getPwd_verified()) || !jb2.isEnabled())) {
                if ((!(jb1.isEnabled())) && jta1.getText().length() != 0) {
                    byte[] AES_KEY = new SHA256(getPwd().getBytes()).toByte();
                    byte[] data = new AES(jta1.getText().getBytes(), AES_KEY, AES_keylengh).encrypt();
                    jta2.setText(Base64.getEncoder().encodeToString((data)));
                } else {
                    if (jta2.getText().length() != 0) {
                        byte[] AES_KEY = new SHA256(getPwd().getBytes()).toByte();
                        byte[] data = new AES(Base64.getDecoder().decode(jta2.getText().getBytes()),
                                AES_KEY, AES_keylengh).decrypt();
                        jta1.setText(new String(data));
                    }
                }
            }
        });
        pane.add(jb3, gbc);
        // file_mode
        gbc = new GridBagConstraints();
        gbc.gridx = 3;
        gbc.gridy = 4;
        gbc.anchor = GridBagConstraints.EAST;
        gbc.insets = new Insets(10, 0, 0, 0);
        jb4.setFont(font);
        jb4.addActionListener(e -> new file_mode(pane));
        pane.add(jb4, gbc);
        // key length
        gbc = new GridBagConstraints();
        gbc.gridx = 3;
        gbc.gridy = 4;
        gbc.anchor = GridBagConstraints.WEST;
        gbc.insets = new Insets(10, 0, 0, 0);
        jb5.setFont(font);
        jb5.addActionListener(e -> {
            if (AES_keylengh == 128) {
                AES_keylengh = 256;
                jb5.setText("AES-256 模式");
            } else {
                AES_keylengh = 128;
                jb5.setText("AES-128 模式");
            }
        });
        pane.add(jb5, gbc);
        // helpMsg
        gbc = new GridBagConstraints();
        gbc.gridx = 3;
        gbc.gridy = 0;
        gbc.anchor = GridBagConstraints.EAST;
        gbc.insets = new Insets(0, 0, 5, 0);
        jb6.setFont(font);
        jb6.addActionListener(e -> new helpMsg(pane));
        pane.add(jb6, gbc);
    }

    private String getPwd() {
        return new String(jpf1.getPassword());
    }

    private String getPwd_verified() {
        return new String(jpf2.getPassword());
    }
}

