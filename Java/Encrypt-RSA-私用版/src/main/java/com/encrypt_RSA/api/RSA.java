package com.encrypt_RSA.api;

import javax.crypto.Cipher;
import java.io.ByteArrayOutputStream;
import java.nio.charset.StandardCharsets;
import java.security.KeyFactory;
import java.security.KeyPair;
import java.security.KeyPairGenerator;
import java.security.SecureRandom;
import java.security.interfaces.RSAPrivateKey;
import java.security.interfaces.RSAPublicKey;
import java.security.spec.PKCS8EncodedKeySpec;
import java.security.spec.X509EncodedKeySpec;
import java.util.Arrays;

public class RSA {
    private RSAPublicKey public_key;
    private RSAPrivateKey private_key;
    private Cipher cipher;
    private KeyFactory keyFactory;
    private ByteArrayOutputStream baos;
    public void generate(int key_length) {
        try {
            KeyPairGenerator keyPairGenerator = KeyPairGenerator.getInstance("RSA");
            SecureRandom sr = SecureRandom.getInstance("SHA1PRNG");
            keyPairGenerator.initialize(key_length, sr);
            KeyPair keyPair = keyPairGenerator.generateKeyPair();
            //
            this.public_key = (RSAPublicKey) keyPair.getPublic();
            this.private_key = (RSAPrivateKey) keyPair.getPrivate();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    public byte[] getPublicKey() {
        return public_key.getEncoded();
    }

    public byte[] getPrivateKey() {
        return private_key.getEncoded();
    }

    // public encrypt, private decrypt
    // encrypt
    public byte[] encrypt_public(byte[] msg, byte[] pwd) {
        try {
            // setup
            X509EncodedKeySpec x509EncodedKeySpec = new X509EncodedKeySpec(pwd);
            keyFactory = KeyFactory.getInstance("RSA");
            cipher = Cipher.getInstance("RSA/ECB/PKCS1Padding");
            cipher.init(Cipher.ENCRYPT_MODE, keyFactory.generatePublic(x509EncodedKeySpec));
            //
            baos = new ByteArrayOutputStream();
            int spilt_length = 117;
            int length = msg.length;
            int k = 0;
            while (length != 0) {
                baos.write(cipher.doFinal(Arrays.copyOfRange(msg, (k * spilt_length), ((k + 1) * spilt_length))));
                System.out.println(length);
                if (length > spilt_length) {
                    k++;
                    length -= spilt_length;
                } else {
                    length = 0;
                }
            }
            return baos.toByteArray();
        } catch (Exception e) {
            e.printStackTrace();
        }
        return "加密失敗".getBytes(StandardCharsets.UTF_8);
    }

    // decrypt
    public byte[] decrypt_private(byte[] msg, byte[] pwd) {
        try {
            // setup
            PKCS8EncodedKeySpec pkcs8EncodedKeySpec = new PKCS8EncodedKeySpec(pwd);
            keyFactory = KeyFactory.getInstance("RSA");
            cipher = Cipher.getInstance("RSA/ECB/PKCS1Padding");
            cipher.init(Cipher.DECRYPT_MODE, keyFactory.generatePrivate(pkcs8EncodedKeySpec));
            //
            baos = new ByteArrayOutputStream();
            int spilt_length = 128;
            int length = msg.length;
            int k = 0;
            while (length != 0) {
                baos.write(cipher.doFinal(Arrays.copyOfRange(msg, k * spilt_length, ((k + 1) * spilt_length))));
                System.out.println(length);
                if (length > spilt_length) {
                    k++;
                    length -= spilt_length;
                } else {
                    length = 0;
                }
            }
            return baos.toByteArray();
        } catch (Exception e) {
            e.printStackTrace();
        }
        return "解密失敗".getBytes(StandardCharsets.UTF_8);
    }

    // public decrypt, private encrypt
    // decrypt
    public byte[] decrypt_public(byte[] msg, byte[] pwd) {
        try {
            X509EncodedKeySpec x509EncodedKeySpec = new X509EncodedKeySpec(pwd);
            keyFactory = KeyFactory.getInstance("RSA");
            //
            cipher = Cipher.getInstance("RSA");
            cipher.init(Cipher.DECRYPT_MODE, keyFactory.generatePublic(x509EncodedKeySpec));
            //
            baos = new ByteArrayOutputStream();
            int spilt_length = 128;
            int length = msg.length;
            int k = 0;
            while (length != 0) {
                baos.write(cipher.doFinal(Arrays.copyOfRange(msg, k * spilt_length, ((k + 1) * spilt_length))));
                System.out.println(length);
                if (length > spilt_length) {
                    k++;
                    length -= spilt_length;
                } else {
                    length = 0;
                }
            }
            return baos.toByteArray();
        } catch (Exception e) {
            e.printStackTrace();
        }
        return "解密失敗".getBytes(StandardCharsets.UTF_8);
    }

    // encrypt
    public byte[] encrypt_private(byte[] msg, byte[] pwd) {
        try {
            PKCS8EncodedKeySpec pkcs8EncodedKeySpec = new PKCS8EncodedKeySpec(pwd);
            keyFactory = KeyFactory.getInstance("RSA");
            //
            cipher = Cipher.getInstance("RSA");
            cipher.init(Cipher.ENCRYPT_MODE, keyFactory.generatePrivate(pkcs8EncodedKeySpec));
            //
            baos = new ByteArrayOutputStream();
            int spilt_length = 117;
            int length = msg.length;
            int k = 0;
            while (length != 0) {
                baos.write(cipher.doFinal(Arrays.copyOfRange(msg, (k * spilt_length), ((k + 1) * spilt_length))));
                System.out.println(length);
                if (length > spilt_length) {
                    k++;
                    length -= spilt_length;
                } else {
                    length = 0;
                }
            }
            return baos.toByteArray();
        } catch (Exception e) {
            e.printStackTrace();
        }
        return "加密失敗".getBytes(StandardCharsets.UTF_8);
    }
}
