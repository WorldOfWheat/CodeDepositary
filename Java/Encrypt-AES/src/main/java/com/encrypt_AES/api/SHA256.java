package com.encrypt_AES.api;

import java.security.MessageDigest;

public class SHA256 {
    private final byte[] bytesToDigest;

    public SHA256(byte[] a) {
        this.bytesToDigest = a;
    }

    public String toString() {
        try {
            byte[] digestToString = toByte();
            //
            StringBuilder sb = new StringBuilder();
            for (byte b : digestToString) {
                String hex = Integer.toHexString(0xff & b);
                if (hex.length() == 1) {
                    sb.append('0');
                }
                sb.append(hex);
            }
            return sb.toString();
        } catch (Exception e) {
            e.printStackTrace();
        }
        return null;
    }

    public byte[] toByte() {
        try {
            MessageDigest messageDigest = MessageDigest.getInstance("SHA-256");
            messageDigest.update(bytesToDigest);
            return messageDigest.digest();
        } catch (Exception e) {
            e.printStackTrace();
        }
        return null;
    }
}
