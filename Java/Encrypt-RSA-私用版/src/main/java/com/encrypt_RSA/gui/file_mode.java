package com.encrypt_RSA.gui;

import com.encrypt_RSA.api.RSA;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.WindowEvent;
import java.awt.event.WindowListener;
import java.io.File;
import java.io.FileOutputStream;
import java.nio.file.Files;
import java.util.ArrayList;
import java.util.Base64;

public class file_mode {
    private final JFrame jf = new JFrame("檔案模式");
    private final JButton jb1 = new JButton("選擇檔案");
    private final JButton jb2 = new JButton("匯入公鑰");
    private final JButton jb3 = new JButton("匯入私鑰");
    private final JButton jb4 = new JButton("匯出");
    private final JButton jb5 = new JButton("加密");
    private final JButton jb6 = new JButton("解密");
    private final JLabel jl1 = new JLabel("⇨");
    private final JFileChooser jfc = new JFileChooser();
    private final Container caller;
    //
    private final ArrayList<File> file = new ArrayList<>();
    private Timer timer;
    private File select_file;
    //
    private byte[] publicKey;
    private byte[] privateKey;

    //
    public file_mode(Container a) {
        this.caller = a;
        this.open();
    }

    private void open() {
        Font font = new Font(jb1.getFont().getName(), Font.BOLD, 18);
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
        jf.setBounds(150, 200, 400, 300);
        // button
        // select file
        GridBagConstraints gbc = new GridBagConstraints();
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
                jb4.setEnabled(true);
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
                    // use open all function
                    // set select_file type to folder
                    open_all(jfc.getSelectedFile());
                    select_file = jfc.getSelectedFile();
                }
            }
        });
        jf.add(jb1, gbc);
        // export
        gbc = new GridBagConstraints();
        gbc.gridx = 2;
        gbc.gridy = 1;
        gbc.gridwidth = 1;
        gbc.ipady = 30;
        gbc.insets = new Insets(10, 0, 0, 0);
        jb4.setFont(font);
        jb4.setEnabled(false);
        jb4.addActionListener(e -> {
            if ((jb5.isEnabled() ^ jb6.isEnabled()) && (jb2.isEnabled() ^ jb3.isEnabled()))
            // check if (jb5 or jb6) and (jb2 or jb3) is clicked
            {
                try {
                    FileOutputStream fos;
                    RSA rsa = new RSA();
                    if (!(jb5.isEnabled())) // if mode is encrypt
                    {
                        if (select_file.isFile()) // type is file
                        {
                            jfc.setFileSelectionMode(JFileChooser.DIRECTORIES_ONLY);
                            int returnVal = jfc.showSaveDialog(jf);
                            if (returnVal == JFileChooser.APPROVE_OPTION) {
                                jf.setEnabled(false);
                                for (File a : file) // generate file and write data that are from file in arraylist
                                {
                                    // get each file name
                                    String file_getname = a.getName();
                                    String fn = file_getname.substring(0, file_getname.lastIndexOf("."));
                                    String fe = file_getname.substring(file_getname.lastIndexOf(".")
                                    );
                                    // print
                                    System.out.println(
                                            jfc.getSelectedFile().getPath() + "\\" + fn + "_encrypted_RSA-1024" + fe + "\n");
                                    // generate new file with bytes
                                    File select = new File(
                                            jfc.getSelectedFile().getPath() + "\\" + fn + "_encrypted_RSA-1024" + fe);
                                    fos = new FileOutputStream(select);
                                    select.createNewFile();
                                    if (!(jb2.isEnabled())) {
                                        fos.write(rsa.encrypt_public(Files.readAllBytes(a.toPath()),
                                                Base64.getDecoder().decode(publicKey)));
                                    } else {
                                        fos.write(rsa.encrypt_private(Files.readAllBytes(a.toPath()),
                                                Base64.getDecoder().decode(privateKey)));
                                    }
                                    fos.close();
                                }
                                jb4.setEnabled(false);
                                jb4.setText("匯出完成");
                                jf.setEnabled(true);
                                timer = new Timer(2000, e1 -> {
                                    jb4.setEnabled(true);
                                    jb4.setText("匯出");
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
                                            select_file.getName() + "_encrypted_RSA-1024");
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
                                    if (!(jb2.isEnabled())) {
                                        fos.write(rsa.encrypt_public(Files.readAllBytes(a.toPath()),
                                                Base64.getDecoder().decode(publicKey)));
                                    } else {
                                        fos.write(rsa.encrypt_private(Files.readAllBytes(a.toPath()),
                                                Base64.getDecoder().decode(privateKey)));
                                    }
                                    fos.close();
                                }
                                jb4.setEnabled(false);
                                jb4.setText("匯出完成");
                                timer = new Timer(2000, new ActionListener() {
                                    @Override
                                    public void actionPerformed(ActionEvent e) {
                                        jb4.setEnabled(true);
                                        jb4.setText("匯出");
                                    }
                                });
                                timer.setRepeats(false);
                                timer.start();
                            }
                        }
                    } else // mode is decrypt
                    {
                        if (select_file.isFile()) { // type is file
                            jfc.setFileSelectionMode(JFileChooser.DIRECTORIES_ONLY);
                            int returnVal = jfc.showSaveDialog(jf);
                            if (returnVal == JFileChooser.APPROVE_OPTION) {
                                jf.setEnabled(false);
                                for (File a : file) // generate file and write data that are from file in arraylist
                                {
                                    // get each file name
                                    String file_getname = a.getName();
                                    String fn = file_getname.substring(0, file_getname.lastIndexOf("."));
                                    String fe = file_getname.substring(file_getname.lastIndexOf(".")
                                    );
                                    // print
                                    System.out.println(
                                            jfc.getSelectedFile().getPath() + "\\" + fn + "_decrypted" + fe + "\n");
                                    // generate new file with bytes
                                    File select = new File(
                                            jfc.getSelectedFile().getPath() + "\\" + fn + "_decrypted" + fe);
                                    fos = new FileOutputStream(select);
                                    select.createNewFile();
                                    if (!(jb2.isEnabled())) {
                                        fos.write(rsa.decrypt_public(Files.readAllBytes(a.toPath()),
                                                Base64.getDecoder().decode(publicKey)));
                                    } else {
                                        fos.write(rsa.decrypt_private(Files.readAllBytes(a.toPath()),
                                                Base64.getDecoder().decode(privateKey)));
                                    }
                                    fos.close();
                                }
                                jb4.setEnabled(false);
                                jb4.setText("匯出完成");
                                jf.setEnabled(true);
                                timer = new Timer(2000, e12 -> {
                                    jb4.setEnabled(true);
                                    jb4.setText("匯出");
                                });
                                timer.setRepeats(false);
                                timer.start();
                            }
                        } else { // type is folder
                            jfc.setFileSelectionMode(JFileChooser.DIRECTORIES_ONLY);
                            int returnVal = jfc.showOpenDialog(jf);
                            if (returnVal == JFileChooser.APPROVE_OPTION) {
                                jf.setEnabled(false);
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
                                    if (!(jb2.isEnabled())) {
                                        fos.write(rsa.decrypt_public(Files.readAllBytes(a.toPath()),
                                                Base64.getDecoder().decode(publicKey)));
                                    } else {
                                        fos.write(rsa.decrypt_private(Files.readAllBytes(a.toPath()),
                                                Base64.getDecoder().decode(privateKey)));
                                    }
                                    fos.close();
                                }
                                jb4.setEnabled(false);
                                jb4.setText("匯出完成");
                                jf.setEnabled(true);
                                timer = new Timer(2000, e13 -> {
                                    jb4.setEnabled(true);
                                    jb4.setText("匯出");
                                });
                                timer.setRepeats(false);
                                timer.start();
                            }
                        }
                    }
                } catch (Exception k) {
                    try {
                        k.printStackTrace();
                        jf.setEnabled(true);
                        jb4.setEnabled(false);
                        jb4.setText("匯出失敗");
                        timer = new Timer(2000, e14 -> {
                            jb4.setEnabled(true);
                            jb4.setText("匯出");
                        });
                        timer.setRepeats(false);
                        timer.start();
                    } catch (Exception m) {
                        m.printStackTrace();
                    }
                }
            }
        });
        jf.add(jb4, gbc);
        // encrypt
        gbc = new GridBagConstraints();
        gbc.gridx = 0;
        gbc.gridy = 4;
        gbc.gridwidth = 2;
        gbc.ipadx = 52;
        gbc.insets = new Insets(25, 0, 0, 0);
        gbc.anchor = GridBagConstraints.WEST;
        jb5.setFont(font);
        jb5.setEnabled(false);
        jb5.addActionListener(e -> {
            jb1.setEnabled(true);
            jb5.setEnabled(false);
            jb6.setEnabled(true);
        });
        jf.add(jb5, gbc);
        // decrypt
        gbc = new GridBagConstraints();
        gbc.gridx = 1;
        gbc.gridy = 4;
        gbc.gridwidth = 2;
        gbc.ipadx = 52;
        gbc.insets = new Insets(25, 0, 0, 0);
        gbc.anchor = GridBagConstraints.EAST;
        jb6.setFont(font);
        jb6.setEnabled(false);
        jb6.addActionListener(e -> {
            jb1.setEnabled(true);
            jb5.setEnabled(true);
            jb6.setEnabled(false);
        });
        jf.add(jb6, gbc);
        // import publicKey
        gbc = new GridBagConstraints();
        gbc.gridx = 0;
        gbc.gridy = 5;
        gbc.gridwidth = 2;
        gbc.ipadx = 18;
        gbc.insets = new Insets(10, 0, 0, 0);
        gbc.anchor = GridBagConstraints.WEST;
        jb2.setFont(font);
        jb2.addActionListener(e -> {
            jfc.setFileSelectionMode(JFileChooser.FILES_ONLY);
            jfc.setMultiSelectionEnabled(false);
            int returnVal = jfc.showOpenDialog(jf);
            if (returnVal == JFileChooser.APPROVE_OPTION) {
                try {
                    publicKey = Files.readAllBytes(jfc.getSelectedFile().toPath());
                    jb1.setEnabled(false);
                    jb4.setEnabled(false);
                    jb5.setEnabled(true);
                    jb6.setEnabled(true);
                    // lock each other
                    jb2.setEnabled(false);
                    jb3.setEnabled(true);
                } catch (Exception k) {
                    k.printStackTrace();
                }
            }
        });
        jf.add(jb2, gbc);
        //import privateKey
        gbc = new GridBagConstraints();
        gbc.gridx = 1;
        gbc.gridy = 5;
        gbc.gridwidth = 2;
        gbc.ipadx = 18;
        gbc.insets = new Insets(10, 0, 0, 0);
        gbc.anchor = GridBagConstraints.EAST;
        jb3.setFont(font);
        jb3.addActionListener(e -> {
            jfc.setFileSelectionMode(JFileChooser.FILES_ONLY);
            jfc.setMultiSelectionEnabled(false);
            int returnVal = jfc.showOpenDialog(jf);
            if (returnVal == JFileChooser.APPROVE_OPTION) {
                try {
                    privateKey = Files.readAllBytes(jfc.getSelectedFile().toPath());
                    jb1.setEnabled(false);
                    jb4.setEnabled(false);
                    jb5.setEnabled(true);
                    jb6.setEnabled(true);
                    // lock each other
                    jb2.setEnabled(true);
                    jb3.setEnabled(false);
                } catch (Exception k) {
                    k.printStackTrace();
                }
            }
        });
        jf.add(jb3, gbc);
        // lable
        gbc = new GridBagConstraints();
        gbc.gridx = 1;
        gbc.gridy = 0;
        gbc.gridwidth = 1;
        gbc.gridheight = 4;
        gbc.insets = new Insets(0, 10, 0, 10);
        jl1.setFont(new Font(jl1.getFont().getName(), Font.BOLD, 60));
        jf.add(jl1, gbc);
        //
        jf.setVisible(true);
    }

    private ArrayList<File> open_all(File a) {
        for (File k : a.listFiles()) {
            if (k.isDirectory()) {
                open_all(k);
            } else {
                file.add(k);
            }
        }
        return file;
    }
}
