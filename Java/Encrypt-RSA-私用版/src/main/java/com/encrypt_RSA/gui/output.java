package com.encrypt_RSA.gui;

import com.encrypt_RSA.api.RSA;

import javax.swing.*;
import java.awt.*;
import java.awt.event.WindowEvent;
import java.awt.event.WindowListener;
import java.io.File;
import java.io.FileOutputStream;
import java.util.Base64;


public class output {
    private final JFrame jf = new JFrame("RSA公鑰與私鑰");
    private final JLabel jl1 = new JLabel("公鑰");
    private final JLabel jl2 = new JLabel("私鑰");
    private final JButton jb1 = new JButton("儲存成文字檔");
    private final JButton jb2 = new JButton("儲存成文字檔");
    private final JTextArea jta1 = new JTextArea();
    private final JTextArea jta2 = new JTextArea();
    private final JScrollPane jsp1 = new JScrollPane(jta1);
    private final JScrollPane jsp2 = new JScrollPane(jta2);
    private final JFileChooser jfc = new JFileChooser();
    private final Container caller;
    private FileOutputStream fos;
    private final int RSA_keylength;

    //
    public output(Container a, int length) {
        this.caller = a;
        this.RSA_keylength = length;
        this.open();
    }

    private void open() {
        Font font = new Font(jl1.getFont().getName(), Font.BOLD, 18);
        //
        RSA keyPair = new RSA();
        keyPair.generate(RSA_keylength);
        //
        jf.setDefaultCloseOperation(JFrame.DO_NOTHING_ON_CLOSE); // setup
        jf.setLayout(new GridBagLayout());
        jf.addWindowListener(new WindowListener() {
            @Override
            public void windowOpened(WindowEvent e) {
                caller.setEnabled(false); // set export button of main window disable
                caller.setBounds(800, 200, 900, 600);
            }

            @Override
            public void windowClosing(WindowEvent e) {
                caller.setEnabled(true); // set export button of main window enable
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
        jf.setBounds(150, 200, 600, 450);
        // lable
        GridBagConstraints gbc = new GridBagConstraints();
        gbc.gridx = 0;
        gbc.gridy = 0;
        gbc.anchor = GridBagConstraints.CENTER;
        jl1.setFont(font);
        jf.add(jl1, gbc);
        //
        gbc = new GridBagConstraints();
        gbc.gridx = 1;
        gbc.gridy = 0;
        gbc.anchor = GridBagConstraints.CENTER;
        jl2.setFont(font);
        jf.add(jl2, gbc);
        // text area
        gbc = new GridBagConstraints();
        gbc.gridx = 0;
        gbc.gridy = 1;
        gbc.ipadx = 250;
        gbc.ipady = 250;
        gbc.anchor = GridBagConstraints.WEST;
        gbc.insets = new Insets(10, 0, 0, 20);
        jta1.setText(Base64.getEncoder().encodeToString(keyPair.getPublicKey()));
        jta1.setWrapStyleWord(true);
        jta1.setLineWrap(true);
        jta1.setEditable(false);
        jta1.setFont(font);
        jf.add(jsp1, gbc);
        //
        gbc = new GridBagConstraints();
        gbc.gridx = 1;
        gbc.gridy = 1;
        gbc.ipadx = 250;
        gbc.ipady = 250;
        gbc.anchor = GridBagConstraints.EAST;
        gbc.insets = new Insets(10, 0, 0, 0);
        jta2.setText(Base64.getEncoder().encodeToString(keyPair.getPrivateKey()));
        jta2.setWrapStyleWord(true);
        jta2.setLineWrap(true);
        jta2.setEditable(false);
        jta2.setFont(font);
        jf.add(jsp2, gbc);
        // button
        // save publicKey
        gbc = new GridBagConstraints();
        gbc.gridx = 0;
        gbc.gridy = 2;
        gbc.ipadx = 80;
        gbc.anchor = GridBagConstraints.CENTER;
        gbc.insets = new Insets(10, 0, 0, 20);
        jb1.setFont(font);
        jb1.addActionListener(e -> {
            jfc.setFileSelectionMode(JFileChooser.DIRECTORIES_ONLY);
            int returnVal = jfc.showOpenDialog(jf);
            if (returnVal == JFileChooser.APPROVE_OPTION) {
                try {
                    File file = new File(jfc.getSelectedFile() + "\\PublicKey_RSA-" + RSA_keylength + ".txt");
                    file.createNewFile();
                    fos = new FileOutputStream(file);
                    fos.write(jta1.getText().getBytes());
                    fos.close();
                } catch (Exception k) {
                    k.printStackTrace();
                }
            }
        });
        jf.add(jb1, gbc);
        // save privateKey
        gbc = new GridBagConstraints();
        gbc.gridx = 1;
        gbc.gridy = 2;
        gbc.ipadx = 80;
        gbc.anchor = GridBagConstraints.CENTER;
        gbc.insets = new Insets(10, 0, 0, 0);
        jb2.setFont(font);
        jb2.addActionListener(e -> {
            jfc.setFileSelectionMode(JFileChooser.DIRECTORIES_ONLY);
            int returnVal = jfc.showOpenDialog(jf);
            if (returnVal == JFileChooser.APPROVE_OPTION) {
                try {
                    File file = new File(jfc.getSelectedFile() + "\\PrivateKey_RSA-" + RSA_keylength + ".txt");
                    file.createNewFile();
                    fos = new FileOutputStream(file);
                    fos.write(jta2.getText().getBytes());
                    fos.close();
                } catch (Exception k) {
                    k.printStackTrace();
                }
            }
        });
        jf.add(jb2, gbc);
        //
        jf.setVisible(true);
    }
}
