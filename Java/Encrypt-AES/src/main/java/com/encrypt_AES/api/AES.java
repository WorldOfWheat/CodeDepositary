package com.encrypt_AES.api;

import javax.crypto.Cipher;
import javax.crypto.KeyGenerator;
import javax.crypto.SecretKey;
import javax.crypto.spec.SecretKeySpec;
import java.security.SecureRandom;

public class AES {
    private byte[] data;
    private SecretKey key;

    public AES(byte[] data, byte[] pwd) {
        new AES(data, pwd, 128);
    }

    public AES(byte[] data, byte[] pwd, int key_length) {
        this.data = data;
        try {
            SecureRandom sr = SecureRandom.getInstance("SHA1PRNG");
            KeyGenerator kgen = KeyGenerator.getInstance("AES");
            kgen.init(key_length, sr);
            sr.setSeed(pwd);
            this.key = kgen.generateKey();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    public byte[] encrypt() {
        try {
            byte[] enCodeFormat = key.getEncoded();
            SecretKeySpec secretKeySpec = new SecretKeySpec(enCodeFormat, "AES");
            Cipher cipher = Cipher.getInstance("AES/ECB/PKCS5Padding");
            cipher.init(Cipher.ENCRYPT_MODE, secretKeySpec);
            return cipher.doFinal(data);
        } catch (Exception e) {
            e.printStackTrace();
        }
        return "加密失敗".getBytes();
    }

    public byte[] decrypt() {
        try {
            byte[] deCodeFormat = key.getEncoded();
            SecretKeySpec secretKeySpec = new SecretKeySpec(deCodeFormat, "AES");
            Cipher cipher = Cipher.getInstance("AES/ECB/PKCS5Padding");
            cipher.init(Cipher.DECRYPT_MODE, secretKeySpec);
            return cipher.doFinal(data);
        } catch (Exception e) {
            e.printStackTrace();
        }
        return "解密失敗".getBytes();
    }
}
