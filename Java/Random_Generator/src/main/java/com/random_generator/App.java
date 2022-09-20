package com.random_generator;

import com.random_generator.gui.main;

import javax.swing.*;
import java.awt.*;

public class App {
    public static void main(String[] args) {

        JFrame jf = new JFrame("亂碼產生器");
        jf.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        jf.setLayout(new GridBagLayout());
        jf.setBounds(500, 200, 1000, 300);
        //
        main gui = new main(jf);
        //
        jf.setVisible(true);
    }
}
