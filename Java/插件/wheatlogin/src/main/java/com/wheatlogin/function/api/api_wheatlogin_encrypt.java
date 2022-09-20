package com.wheatlogin.function.api;

public class api_wheatlogin_encrypt {
    public static String crypt(String b) {
        char[] code = b.toCharArray();
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < code.length; i++) {
            if (!(String.valueOf(code[i]).equals("."))) {
                sb.append((char) (code[i] ^ 2650 ^ 3028));
            }
        }
        return sb.toString();
    }
}
