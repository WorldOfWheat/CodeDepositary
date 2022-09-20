package com.encrypt_AES;

import com.encrypt_AES.gui.main;

import javax.swing.*;
import java.awt.*;

public class App {
    public static void main(String[] args) {
        JFrame jf = new JFrame("AES 加密工具");
        jf.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        jf.setLayout(new GridBagLayout());
        jf.setBounds(500, 200, 900, 600);
        //
        main gui = new main(jf);
        gui.use();
        //
        jf.setVisible(true);
    }
}