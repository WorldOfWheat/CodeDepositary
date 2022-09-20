package com.random_generator.gui;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.WindowEvent;
import java.awt.event.WindowListener;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;

public class output {
    private final ArrayList<String> randlist;
    private final JFrame jf = new JFrame("亂碼表");
    private final JButton jb = new JButton("儲存成文字檔");
    private final JTextArea jta = new JTextArea();
    private final JScrollPane jsp = new JScrollPane(jta);
    private final JFileChooser jfc = new JFileChooser();
    private GridBagConstraints gbc;
    private final Container caller;

    public output(Container a, ArrayList<String> b) {
        this.caller = a;
        this.randlist = b;
        open();
    }

    private void open() {
        jf.setDefaultCloseOperation(JFrame.DO_NOTHING_ON_CLOSE); //setup
        jf.setLayout(new GridBagLayout());
        jf.addWindowListener(new WindowListener() {
            @Override
            public void windowOpened(WindowEvent e) {
                caller.setEnabled(false); //set export button of main window disable
            }

            @Override
            public void windowClosing(WindowEvent e) {
                caller.setEnabled(true); //set export button of main window enable
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
        jf.setBounds(150, 200, 300, 500);
        //text area layout set 
        gbc = new GridBagConstraints();
        gbc.gridx = 0;
        gbc.gridy = 0;
        gbc.ipadx = 250;
        gbc.ipady = 400;
        gbc.weightx = 1;
        //text area set
        jsp.setPreferredSize(new Dimension(500, 200));
        jta.setAutoscrolls(true);
        jta.setEditable(false);
        jta.setFont(new Font(jta.getFont().getName(), Font.BOLD, 20));
        jta.setText("成功產生亂數： \n");
        for (String a : randlist) {
            jta.setText(jta.getText() + "\n" + a);
        }
        jf.add(jsp, gbc);
        //save to file
        gbc = new GridBagConstraints();
        gbc.gridx = 0;
        gbc.gridy = 1;
        gbc.ipadx = 150;
        gbc.weightx = 1;
        jb.setFont(new Font(jta.getFont().getName(), Font.BOLD, 15));
        jb.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                jfc.setDialogTitle("儲存亂碼表");
                int userSelection = jfc.showSaveDialog(jf);
                if (userSelection == JFileChooser.APPROVE_OPTION) {
                    File file = jfc.getSelectedFile();
                    try {
                        FileWriter fw = new FileWriter(file + ".txt", true);
                        BufferedWriter bw = new BufferedWriter(fw);
                        for (String a : randlist) {
                            bw.write(a + "\n");
                        }
                        bw.close();
                    } catch (IOException e1) {
                    }
                }
            }
        });
        jf.add(jb, gbc);
        //
        jf.setVisible(true);
    }
}
