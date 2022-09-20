package com.random_generator.gui;

import com.random_generator.generate_rand;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.ArrayList;

public class main {
    private final JButton jb = new JButton("產生");
    private final JLabel jl1 = new JLabel("長度");
    private final JLabel jl2 = new JLabel("數量");
    private final JCheckBox jcb1 = new JCheckBox("數字 0 1 2 3 4 5 6 7 8 9");
    private final JCheckBox jcb2 = new JCheckBox("英文字母（小寫） a b c d e f g h i j k l m n o p q rs t u v w x y z");
    private final JCheckBox jcb3 = new JCheckBox("英文字母（大寫） A B C D E F G H I J K L M N O P Q R S T U V W X Y Z");
    private final JCheckBox jcb4 = new JCheckBox("符號 ~ ! @ # $ % ^ & * ( ) / * - +");
    private final JCheckBox jcb5 = new JCheckBox("是否清除易混淆字母 1 i l I ! o 0 O 8 B k K");
    private final JTextField jtf1 = new JTextField();
    private final Container pane;
    private JTextField jtf2 = new JTextField();
    private GridBagConstraints gbc;

    public main(Container a) {
        this.pane = a;
		this.open();
    }

    private void open() {
        Font font = new Font(jb.getFont().getName(), Font.BOLD, 20);
        //lable
        gbc = new GridBagConstraints();
        gbc.gridx = 0;
        gbc.gridy = 0;
        gbc.ipadx = 5;
        gbc.gridheight = 1;
        jl1.setFont(font);
        gbc.anchor = GridBagConstraints.SOUTH;
        pane.add(jl1, gbc);
        //
        gbc = new GridBagConstraints();
        gbc.gridx = 0;
        gbc.gridy = 1;
        gbc.ipadx = 5;
        gbc.gridheight = 1;
        gbc.insets = new Insets(10, 0, 0, 0);
        jl2.setFont(font);
        gbc.anchor = GridBagConstraints.SOUTH;
        pane.add(jl2, gbc);
        //textfield
        gbc = new GridBagConstraints();
        jtf1.setFont(font);
        gbc.gridx = 1;
        gbc.gridy = 0;
        gbc.gridwidth = 1;
        gbc.gridheight = 1;
        gbc.ipadx = 70;
        gbc.fill = GridBagConstraints.HORIZONTAL;
        gbc.anchor = GridBagConstraints.SOUTH;
        pane.add(jtf1, gbc);
        //
        gbc = new GridBagConstraints();
        jtf2 = new JTextField();
        jtf2.setFont(font);
        gbc.gridx = 1;
        gbc.gridy = 1;
        gbc.gridwidth = 1;
        gbc.gridheight = 1;
        gbc.ipadx = 70;
        gbc.insets = new Insets(10, 0, 0, 0);
        gbc.fill = GridBagConstraints.HORIZONTAL;
        gbc.anchor = GridBagConstraints.SOUTH;
        pane.add(jtf2, gbc);
        //checkbox
        gbc = new GridBagConstraints();
        jcb1.setFont(font);
        gbc.gridx = 3;
        gbc.gridy = 0;
        gbc.gridwidth = 3;
        gbc.fill = GridBagConstraints.HORIZONTAL;
        gbc.anchor = GridBagConstraints.NORTHWEST;
        pane.add(jcb1, gbc);
        //
        gbc = new GridBagConstraints();
        jcb2.setFont(font);
        gbc.gridx = 3;
        gbc.gridy = 1;
        gbc.gridwidth = 3;
        gbc.fill = GridBagConstraints.HORIZONTAL;
        gbc.anchor = GridBagConstraints.NORTHWEST;
        pane.add(jcb2, gbc);
        //
        gbc = new GridBagConstraints();
        jcb3.setFont(font);
        gbc.gridx = 3;
        gbc.gridy = 2;
        gbc.gridwidth = 3;
        gbc.fill = GridBagConstraints.HORIZONTAL;
        gbc.anchor = GridBagConstraints.NORTHWEST;
        pane.add(jcb3, gbc);
        //
        gbc = new GridBagConstraints();
        jcb4.setFont(font);
        gbc.gridx = 3;
        gbc.gridy = 3;
        gbc.gridwidth = 3;
        gbc.fill = GridBagConstraints.HORIZONTAL;
        gbc.anchor = GridBagConstraints.NORTHWEST;
        pane.add(jcb4, gbc);
        //
        gbc = new GridBagConstraints();
        jcb5.setFont(font);
        gbc.gridx = 3;
        gbc.gridy = 4;
        gbc.gridwidth = 3;
        gbc.fill = GridBagConstraints.HORIZONTAL;
        gbc.anchor = GridBagConstraints.NORTHWEST;
        pane.add(jcb5, gbc);
        //button
        gbc = new GridBagConstraints();
        jb.setFont(font);
        gbc.gridx = 0;
        gbc.gridy = 3;
        gbc.gridwidth = 2;
        gbc.gridheight = 1;
        gbc.ipadx = 30;
        gbc.fill = GridBagConstraints.CENTER;
        jb.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                StringBuilder sb = new StringBuilder();
                ArrayList<String> randlist = new ArrayList();
                if (jcb1.isSelected()) {
                    sb.append(generate_rand.number);
                }
                if (jcb2.isSelected()) {
                    sb.append(generate_rand.lower);
                }
                if (jcb3.isSelected()) {
                    sb.append(generate_rand.cap);
                }
                if (jcb4.isSelected()) {
                    sb.append(generate_rand.symbol);
                }
                for (int i = 0; i < Integer.valueOf(jtf2.getText()); i++) {
                    generate_rand rand = new generate_rand(Integer.valueOf(jtf1.getText()));
                    randlist.add(rand.gen(sb.toString(), jcb5.isSelected()));
                }
                new output(pane, randlist);
            }
        });
        pane.add(jb, gbc);
    }
}
