package com.encrypt_RSA.gui;

import com.encrypt_RSA.api.RSA;

import javax.swing.*;
import java.awt.*;
import java.nio.file.Files;
import java.util.Base64;

public class main {
    private final JLabel jl1 = new JLabel("加密內容：");
    private final JLabel jl2 = new JLabel("解密內容：");
    private final JTextArea jta1 = new JTextArea();
    private final JTextArea jta2 = new JTextArea();
    private final JScrollPane jsp1 = new JScrollPane(jta1);
    private final JScrollPane jsp2 = new JScrollPane(jta2);
    private final JButton jb1 = new JButton("加密");
    private final JButton jb2 = new JButton("解密");
    private final JButton jb3 = new JButton("執行");
    private final JButton jb4 = new JButton("產生金鑰");
    private final JButton jb5 = new JButton("匯入公鑰");
    private final JButton jb6 = new JButton("匯入私鑰");
    private final JButton jb7 = new JButton("檔案模式");
    private final JButton jb8 = new JButton("RSA-1024 模式");
    private final JButton jb9 = new JButton("?");
    private final JFileChooser jfc = new JFileChooser();
    private final Container pane;
    private int RSA_keylengh = 1024;
    //
    private byte[] publicKey;
    private byte[] privateKey;

    //
    public main(Container a) {
        this.pane = a;
        this.open();
    }

    private void open() {
        Font font = new Font(jl1.getFont().getName(), Font.BOLD, 18);
        Dimension scrollsize = new Dimension(300, 300);
        // lable
        GridBagConstraints gbc = new GridBagConstraints();
        gbc.gridx = 0;
        gbc.gridy = 0;
        gbc.anchor = GridBagConstraints.CENTER;
        gbc.insets = new Insets(0, 0, 10, 0);
        jl1.setFont(font);
        pane.add(jl1, gbc);
        //
        gbc = new GridBagConstraints();
        gbc.gridx = 3;
        gbc.gridy = 0;
        gbc.anchor = GridBagConstraints.CENTER;
        jl2.setFont(font);
        pane.add(jl2, gbc);
        // text area
        // encrypt
        gbc = new GridBagConstraints();
        gbc.gridx = 0;
        gbc.gridy = 1;
        gbc.ipadx = 300;
        gbc.ipady = 300;
        gbc.anchor = GridBagConstraints.WEST;
        jsp1.setPreferredSize(scrollsize);
        jta1.setFont(font);
        pane.add(jsp1, gbc);
        // decrypt
        gbc = new GridBagConstraints();
        gbc.gridx = 3;
        gbc.gridy = 1;
        gbc.ipadx = 300;
        gbc.ipady = 300;
        gbc.anchor = GridBagConstraints.WEST;
        jsp2.setPreferredSize(scrollsize);
        jta2.setWrapStyleWord(true);
        jta2.setLineWrap(true);
        jta2.setFont(font);
        pane.add(jsp2, gbc);
        // button
        // encrypt
        gbc = new GridBagConstraints();
        gbc.gridx = 0;
        gbc.gridy = 2;
        gbc.anchor = GridBagConstraints.WEST;
        gbc.insets = new Insets(10, 0, 0, 0);
        jb1.setEnabled(false);
        jb1.setFont(font);
        jb1.addActionListener(e -> {
            jb1.setEnabled(false);
            jb2.setEnabled(true);
            jta1.setEditable(true);
            jta2.setEditable(false);
        });
        pane.add(jb1, gbc);
        // decyrpt
        gbc = new GridBagConstraints();
        gbc.gridx = 3;
        gbc.gridy = 2;
        gbc.anchor = GridBagConstraints.EAST;
        gbc.insets = new Insets(10, 0, 0, 0);
        jb2.setEnabled(false);
        jb2.setFont(font);
        jb2.addActionListener(e -> {
            jb1.setEnabled(true);
            jb2.setEnabled(false);
            jta1.setEditable(false);
            jta2.setEditable(true);
        });
        pane.add(jb2, gbc);
        // execute
        gbc = new GridBagConstraints();
        gbc.gridx = 1;
        gbc.gridy = 1;
        gbc.gridwidth = 1;
        gbc.insets = new Insets(0, 10, 0, 10);
        jb3.setFont(font);
        jb3.addActionListener(e -> {
            if ((jb1.isEnabled() ^ jb2.isEnabled()) && (jb5.isEnabled() ^ jb6.isEnabled())) {
                RSA rsa = new RSA();
                if (!(jb1.isEnabled())) {
                    if (!(jb5.isEnabled())) {
                        byte[] data = rsa.encrypt_public(jta1.getText().getBytes(),
                                Base64.getDecoder().decode(publicKey));
                        jta2.setText(Base64.getEncoder().encodeToString(data));
                    } else {
                        byte[] data = rsa.encrypt_private(jta1.getText().getBytes(),
                                Base64.getDecoder().decode(privateKey));
                        jta2.setText(Base64.getEncoder().encodeToString(data));
                    }
                } else {
                    if (!(jb5.isEnabled())) {
                        byte[] data = rsa.decrypt_public(Base64.getDecoder().decode(jta2.getText()),
                                Base64.getDecoder().decode(publicKey));
                        jta1.setText(new String(data));
                    } else {
                        byte[] data = rsa.decrypt_private(Base64.getDecoder().decode(jta2.getText()),
                                Base64.getDecoder().decode(privateKey));
                        jta1.setText(new String(data));
                    }
                }
            }
        });
        pane.add(jb3, gbc);
        // generate
        gbc = new GridBagConstraints();
        gbc.gridx = 0;
        gbc.gridy = 3;
        gbc.gridwidth = 1;
        gbc.anchor = GridBagConstraints.WEST;
        gbc.insets = new Insets(10, 0, 0, 0);
        jb4.setFont(font);
        jb4.addActionListener(e -> new output(pane, RSA_keylengh));
        pane.add(jb4, gbc);
        // import publicKey
        gbc = new GridBagConstraints();
        gbc.gridx = 0;
        gbc.gridy = 2;
        gbc.anchor = GridBagConstraints.EAST;
        gbc.insets = new Insets(10, 0, 0, 0);
        jb5.setFont(font);
        jb5.addActionListener(e -> {
            jfc.setFileSelectionMode(JFileChooser.FILES_ONLY);
            jfc.setMultiSelectionEnabled(false);
            int returnVal = jfc.showOpenDialog(pane);
            if (returnVal == JFileChooser.APPROVE_OPTION) {
                try {
                    publicKey = Files.readAllBytes(jfc.getSelectedFile().toPath());
                    jb1.setEnabled(true);
                    jb2.setEnabled(true);
                    jb5.setEnabled(false);
                    jb6.setEnabled(true);
                } catch (Exception k) {
                    k.printStackTrace();
                }
            }
        });
        pane.add(jb5, gbc);
        // import privateKey
        gbc = new GridBagConstraints();
        gbc.gridx = 3;
        gbc.gridy = 2;
        gbc.anchor = GridBagConstraints.WEST;
        gbc.insets = new Insets(10, 0, 0, 0);
        jb6.setFont(font);
        jb6.addActionListener(e -> {
            jfc.setFileSelectionMode(JFileChooser.FILES_ONLY);
            jfc.setMultiSelectionEnabled(false);
            int returnVal = jfc.showOpenDialog(pane);
            if (returnVal == JFileChooser.APPROVE_OPTION) {
                try {
                    privateKey = Files.readAllBytes(jfc.getSelectedFile().toPath());
                    jb1.setEnabled(true);
                    jb2.setEnabled(true);
                    jb5.setEnabled(true);
                    jb6.setEnabled(false);
                } catch (Exception k) {
                    k.printStackTrace();
                }
            }
        });
        pane.add(jb6, gbc);
        // file_mode
        gbc = new GridBagConstraints();
        gbc.gridx = 3;
        gbc.gridy = 3;
        gbc.anchor = GridBagConstraints.EAST;
        gbc.insets = new Insets(10, 0, 0, 0);
        jb7.setFont(font);
        jb7.addActionListener(e -> new file_mode(pane));
        pane.add(jb7, gbc);
        // key length
        gbc = new GridBagConstraints();
        gbc.gridx = 3;
        gbc.gridy = 3;
        gbc.anchor = GridBagConstraints.WEST;
        gbc.insets = new Insets(10, 0, 0, 0);
        jb8.setFont(font);
        jb8.addActionListener(e -> {
            if (RSA_keylengh == 2048) {
                RSA_keylengh = 1024;
                jb8.setText("RSA-1024 模式");
            } else {
                RSA_keylengh = 2048;
                jb8.setText("RSA-2048 模式");
            }
        });
        pane.add(jb8, gbc);
        // helpMsg
        gbc = new GridBagConstraints();
        gbc.gridx = 3;
        gbc.gridy = 0;
        gbc.anchor = GridBagConstraints.EAST;
        gbc.insets = new Insets(0, 0, 5, 0);
        jb9.setFont(font);
        jb9.addActionListener(e -> new helpMsg(pane));
        pane.add(jb9, gbc);
    }
}
