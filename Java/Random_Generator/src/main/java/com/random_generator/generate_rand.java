package com.random_generator;

import java.util.Random;


public class generate_rand {
    public static String cap = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    public static String lower = "abcdefghijklmnopqrstuvwxyz";
    public static String number = "0123456789";
    public static String symbol = "~!@#$%^&*()/*-+";
    public String dirty = "1ilI!o0OB8kK";
    private int length = 0;

    public generate_rand(int a) {
        this.length = a;
    }

    private char generator() {
        Random rand = new Random();
        char[] letter = (cap + lower + number + symbol).toCharArray();
        return letter[rand.nextInt(letter.length)];
    }

    private char generator_clear(String a, boolean b) {
        char rand_letter = generator();
        if (b) {
            if (a.indexOf(rand_letter) != -1 && dirty.indexOf(rand_letter) == -1) {
                return rand_letter;
            }
        } else {
            if (a.indexOf(rand_letter) != -1) {
                return rand_letter;
            }
        }
        return generator_clear(a, b);
    }

    public String gen(String a, boolean b) {
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < length; i++) {
            sb.append(generator_clear(a, b));
        }
        return sb.toString();
    }
}   
