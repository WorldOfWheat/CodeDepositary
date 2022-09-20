package com.encrypt_AES.gui;

import com.encrypt_AES.api.AES;
import com.encrypt_AES.api.SHA256;

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.io.File;
import java.io.FileOutputStream;
import java.nio.file.Files;
import java.util.ArrayList;

public class file_mode {
    private final JFrame jf = new JFrame("檔案模式");
    private final JButton jb1 = new JButton("選擇檔案");
    private final JButton jb2 = new JButton("匯出");
    private final JButton jb3 = new JButton("加密");
    private final JButton jb4 = new JButton("解密");
    private final JButton jb5 = new JButton("AES-128 模式");
    private final JPasswordField jpf1 = new JPasswordField();
    private final JPasswordField jpf2 = new JPasswordField();
    private final JLabel jl1 = new JLabel("⇨");
    private final JLabel jl2 = new JLabel("密碼");
    private final JLabel jl3 = new JLabel("確認密碼");
    private final JFileChooser jfc = new JFileChooser();
    private final Container caller;
    private final ArrayList<File> file = new ArrayList<>();
    private Timer timer;
    private File select_file;
    private int AES_keylengh = 128;

    public file_mode(Container a) {
        this.caller = a;
        this.open();
    }

    private void open() {
        Font font = new Font("SansSerif", Font.BOLD, 18);
        GridBagConstraints gbc;
        jf.setDefaultCloseOperation(JFrame.DO_NOTHING_ON_CLOSE);
        jf.setLayout(new GridBagLayout());
        jf.addWindowListener(new WindowListener() {
            @Override
            public void windowOpened(WindowEvent e) {
                // when open file_mode
                caller.setBounds(600, 200, 900, 600);
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
        jf.setBounds(150, 200, 370, 360);
        // button
        // select file
        gbc = new GridBagConstraints();
        gbc.gridx = 0;
        gbc.gridy = 0;
        gbc.gridheight = 3;
        gbc.ipady = 30;
        gbc.insets = new Insets(10, 0, 0, 0);
        jb1.setFont(font);
        jb1.setEnabled(false);
        jb1.addActionListener(e -> {
            // set select mode
            jfc.setMultiSelectionEnabled(true);
            jfc.setFileSelectionMode(JFileChooser.FILES_AND_DIRECTORIES);
            //
            int returnVal = jfc.showOpenDialog(jf);
            if (returnVal == JFileChooser.APPROVE_OPTION) {
                file.clear(); // clear arraylist
                if (jfc.getSelectedFile().isFile()) // if selection is multi file
                {
                    // add each file to arraylist
                    // set select_file type to file
                    for (File a : jfc.getSelectedFiles()) {
                        file.add(a);
                        select_file = a;
                    }
                } else // if selection is folder
                {
                    // use openall function
                    // set select_file type to folder
                    open_all(jfc.getSelectedFile());
                    select_file = jfc.getSelectedFile();
                }
                jb2.setEnabled(true);
            }
        });
        jf.add(jb1, gbc);
        // export
        gbc = new GridBagConstraints();
        gbc.gridx = 2;
        gbc.gridy = 1;
        gbc.gridwidth = 1;
        gbc.ipady = 30;
        gbc.anchor = GridBagConstraints.CENTER;
        gbc.insets = new Insets(10, 0, 0, 0);
        jb2.setFont(font);
        jb2.setEnabled(false);
        jb2.addActionListener(e -> {
            if ((jb3.isEnabled() ^ jb4.isEnabled()) && (getPwd().length() != 0) &&
                    (getPwd().equals(getPwd_verfied()) || !(jb4.isEnabled())))
            // (check if jb3 or jb4 is clicked) and (password is not empty) and ( "pwd and pwd_verified is in the same" or "is decryption mode")
            {
                try {
                    FileOutputStream fos;
                    if (!(jb3.isEnabled())) // if mode is encrypt
                    {
                        if (select_file.isFile()) // type is file
                        {
                            jfc.setFileSelectionMode(JFileChooser.DIRECTORIES_ONLY);
                            int returnVal = jfc.showSaveDialog(jf);
                            if (returnVal == JFileChooser.APPROVE_OPTION) {
                                for (File a : file) // generate file and write data that are from file in arraylist
                                {
                                    // get each file name
                                    String file_getname = a.getName();
                                    String fn = file_getname.substring(0, file_getname.lastIndexOf("."));
                                    String fe = file_getname.substring(file_getname.lastIndexOf("."));
                                    String file_name = jfc.getSelectedFile().getPath() + "\\" + fn +
                                            "_encrypted_AES-" + AES_keylengh + fe;
                                    // print
                                    System.out.println(file_name + "\n");
                                    // generate new file with bytes
                                    File select = new File(file_name);
                                    fos = new FileOutputStream(select);
                                    select.createNewFile();
                                    byte[] AES_KEY = new SHA256(getPwd().getBytes()).toByte();
                                    fos.write(new AES(Files.readAllBytes(a.toPath()), AES_KEY, AES_keylengh)
                                            .encrypt());
                                    fos.close();
                                }
                                jb2.setEnabled(false);
                                jb2.setText("匯出完成");
                                timer = new Timer(2000, e1 -> {
                                    jb2.setEnabled(true);
                                    jb2.setText("匯出");
                                });
                                timer.setRepeats(false);
                                timer.start();
                            }
                        } else // type is folder
                        {
                            jfc.setFileSelectionMode(JFileChooser.DIRECTORIES_ONLY);
                            int returnVal = jfc.showOpenDialog(jf);
                            if (returnVal == JFileChooser.APPROVE_OPTION) {
                                for (File a : file) {
                                    // get path and generate new path
                                    String path = a.getPath();
                                    String path2 = path.substring(path.indexOf(select_file.getName())
                                    );
                                    String save_path = jfc.getSelectedFile().getAbsolutePath() + "\\"
                                            + path2.replaceFirst(select_file.getName(),
                                            select_file.getName() + "_encrypted_AES-" + AES_keylengh);
                                    // generate new folders if is not exists
                                    File dir = new File(save_path.substring(0, save_path.lastIndexOf("\\")));
                                    if (!(dir.exists())) {
                                        dir.mkdirs();
                                    }
                                    // print
                                    System.out.print(save_path + "\n");
                                    // generate new file and write bytes
                                    File select = new File(save_path);
                                    fos = new FileOutputStream(select);
                                    select.createNewFile();
                                    byte[] AES_KEY = new SHA256(getPwd().getBytes()).toByte();
                                    fos.write(new AES(Files.readAllBytes(a.toPath()), AES_KEY, AES_keylengh)
                                            .encrypt());
                                    fos.close();
                                }
                                jb2.setEnabled(false);
                                jb2.setText("匯出完成");
                                timer = new Timer(2000, e12 -> {
                                    jb2.setEnabled(true);
                                    jb2.setText("匯出");
                                });
                                timer.setRepeats(false);
                                timer.start();
                            }
                        }
                    } else // mode is decrypt
                    {
                        if (select_file.isFile()) {
                            jfc.setFileSelectionMode(JFileChooser.DIRECTORIES_ONLY);
                            int returnVal = jfc.showSaveDialog(jf);
                            if (returnVal == JFileChooser.APPROVE_OPTION) {
                                for (File a : file) // generate file and write data that are from file in arraylist
                                {
                                    // get each file name
                                    String file_getname = a.getName();
                                    String fn = file_getname.substring(0, file_getname.lastIndexOf("."));
                                    String fe = file_getname.substring(file_getname.lastIndexOf("."));
                                    String file_name = jfc.getSelectedFile().getPath() + "\\" + fn +
                                            "_decrypted" + fe;
                                    // print
                                    System.out.println(file_name + "\n");
                                    // generate new file with bytes
                                    File select = new File(file_name);
                                    fos = new FileOutputStream(select);
                                    select.createNewFile();
                                    byte[] AES_KEY = new SHA256(getPwd().getBytes()).toByte();
                                    fos.write(new AES(Files.readAllBytes(a.toPath()), AES_KEY, AES_keylengh)
                                            .decrypt());
                                    fos.close();
                                }
                                jb2.setEnabled(false);
                                jb2.setText("匯出完成");
                                timer = new Timer(2000, e13 -> {
                                    jb2.setEnabled(true);
                                    jb2.setText("匯出");
                                });
                                timer.setRepeats(false);
                                timer.start();
                            }
                        } else {
                            jfc.setFileSelectionMode(JFileChooser.DIRECTORIES_ONLY);
                            int returnVal = jfc.showOpenDialog(jf);
                            if (returnVal == JFileChooser.APPROVE_OPTION) {
                                for (File a : file) {
                                    // get path and generate new path
                                    String path = a.getPath();
                                    String path2 = path.substring(path.indexOf(select_file.getName())
                                    );
                                    String save_path = jfc.getSelectedFile().getAbsolutePath() + "\\"
                                            + path2.replaceFirst(select_file.getName(),
                                            select_file.getName() + "_decrypted");
                                    // generate new folders if is not exists
                                    File dir = new File(save_path.substring(0, save_path.lastIndexOf("\\")));
                                    if (!(dir.exists())) {
                                        dir.mkdirs();
                                    }
                                    // print
                                    System.out.print(save_path + "\n");
                                    // generate new file and write bytes
                                    File select = new File(save_path);
                                    fos = new FileOutputStream(select);
                                    select.createNewFile();
                                    byte[] AES_KEY = new SHA256(getPwd().getBytes()).toByte();
                                    fos.write(new AES(Files.readAllBytes(a.toPath()), AES_KEY, AES_keylengh)
                                            .decrypt());
                                    fos.close();
                                }
                                jb2.setEnabled(false);
                                jb2.setText("匯出完成");
                                timer = new Timer(2000, e14 -> {
                                    jb2.setEnabled(true);
                                    jb2.setText("匯出");
                                });
                                timer.setRepeats(false);
                                timer.start();
                            }
                        }
                    }
                } catch (Exception k) {
                    try {
                        k.printStackTrace();
                        jb2.setEnabled(false);
                        jb2.setText("匯出失敗");
                        timer = new Timer(2000, e15 -> {
                            jb2.setEnabled(true);
                            jb2.setText("匯出");
                        });
                        timer.setRepeats(false);
                        timer.start();
                    } catch (Exception m) {
                        m.printStackTrace();
                    }
                }
            }
        });
        jf.add(jb2, gbc);
        // encrypt
        gbc = new GridBagConstraints();
        gbc.gridx = 0;
        gbc.gridy = 4;
        gbc.gridwidth = 2;
        gbc.ipadx = 52;
        gbc.insets = new Insets(25, 0, 0, 0);
        gbc.anchor = GridBagConstraints.WEST;
        jb3.setFont(font);
        jb3.addActionListener(e -> {
            jb1.setEnabled(true);
            jb2.setEnabled(false);
            jb3.setEnabled(false);
            jb4.setEnabled(true);
            // password field
            jpf1.setEditable(true);
            jl2.setVisible(true);
            jpf2.setVisible(true);
            jl3.setVisible(true);
        });
        jf.add(jb3, gbc);
        // decrypt
        gbc = new GridBagConstraints();
        gbc.gridx = 1;
        gbc.gridy = 4;
        gbc.gridwidth = 2;
        gbc.ipadx = 52;
        gbc.insets = new Insets(25, 0, 0, 0);
        gbc.anchor = GridBagConstraints.EAST;
        jb4.setFont(font);
        jb4.addActionListener(e -> {
            jb1.setEnabled(true);
            jb2.setEnabled(false);
            jb3.setEnabled(true);
            jb4.setEnabled(false);
            // password field
            jpf1.setEditable(true);
            jl2.setVisible(true);
            jpf2.setVisible(false);
            jl3.setVisible(false);
            jpf2.setText("");
        });
        jf.add(jb4, gbc);
        // key length
        gbc = new GridBagConstraints();
        gbc.gridx = 0;
        gbc.gridy = 8;
        gbc.gridwidth = 3;
        gbc.ipadx = 115;
        gbc.insets = new Insets(15, 0, 0, 0);
        gbc.anchor = GridBagConstraints.CENTER;
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
        jf.add(jb5, gbc);
        // lable
        // arrow
        gbc = new GridBagConstraints();
        gbc.gridx = 1;
        gbc.gridy = 0;
        gbc.gridwidth = 1;
        gbc.gridheight = 4;
        gbc.insets = new Insets(0, 10, 0, 10);
        jl1.setFont(new Font("SansSerif", Font.BOLD, 60));
        jf.add(jl1, gbc);
        // pwd
        gbc = new GridBagConstraints();
        gbc.gridx = 0;
        gbc.gridy = 5;
        gbc.anchor = GridBagConstraints.WEST;
        gbc.insets = new Insets(6, 8, 0, 0);
        jl2.setFont(font);
        jl2.setVisible(false);
        jf.add(jl2, gbc);
        // verfied pwd
        gbc = new GridBagConstraints();
        gbc.gridx = 0;
        gbc.gridy = 6;
        gbc.anchor = GridBagConstraints.WEST;
        gbc.insets = new Insets(6, 8, 0, 0);
        jl3.setFont(font);
        jl3.setVisible(false);
        jf.add(jl3, gbc);
        // password field
        // pwd
        gbc = new GridBagConstraints();
        gbc.gridx = 0;
        gbc.gridy = 5;
        gbc.gridwidth = 3;
        gbc.ipadx = 265;
        gbc.insets = new Insets(10, 0, 0, 0);
        gbc.anchor = GridBagConstraints.CENTER;
        jpf1.setFont(font);
        jpf1.setEditable(false);
        jpf1.addFocusListener(new FocusListener() {

            @Override
            public void focusGained(FocusEvent e) {
                jl2.setVisible(false);
            }

            @Override
            public void focusLost(FocusEvent e) {
                if (getPwd().length() == 0 && (jb3.isEnabled() ^ jb4.isEnabled())) {
                    jl2.setVisible(true);
                }
            }
        });
        jf.add(jpf1, gbc);
        // verfied pwd
        gbc = new GridBagConstraints();
        gbc.gridx = 0;
        gbc.gridy = 6;
        gbc.gridwidth = 3;
        gbc.ipadx = 265;
        gbc.insets = new Insets(10, 0, 0, 0);
        gbc.anchor = GridBagConstraints.CENTER;
        jpf2.setFont(font);
        jpf2.setVisible(false);
        jpf2.addFocusListener(new FocusListener() {

            @Override
            public void focusGained(FocusEvent e) {
                jl3.setVisible(false);
            }

            @Override
            public void focusLost(FocusEvent e) {
                if (getPwd_verfied().length() == 0) {
                    jl3.setVisible(true);
                }
            }
        });
        jf.add(jpf2, gbc);
        //
        jf.setVisible(true);
    }

    private void open_all(File a) {
        for (File k : a.listFiles()) {
            if (k.isDirectory()) {
                open_all(k);
            } else {
                file.add(k);
            }
        }
    }

    private String getPwd() {
        return new String(jpf1.getPassword());
    }

    private String getPwd_verfied() {
        return new String(jpf2.getPassword());
    }
}
