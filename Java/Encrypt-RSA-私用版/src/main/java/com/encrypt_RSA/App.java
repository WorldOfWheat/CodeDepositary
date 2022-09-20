package com.encrypt_RSA;

import com.encrypt_RSA.gui.main;

import javax.swing.*;
import java.awt.*;

public class App {
    public static void main(String[] args) {
        JFrame jf = new JFrame("RSA 加密工具");
        jf.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        jf.setLayout(new GridBagLayout());
        jf.setBounds(500, 200, 900, 600);
        //
        new main(jf);
        //
        jf.setVisible(true);
    }
}
