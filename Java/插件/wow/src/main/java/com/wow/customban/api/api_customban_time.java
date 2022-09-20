package com.wow.customban.api;

import java.text.SimpleDateFormat;
import java.util.Calendar;
import java.util.Date;

public class api_customban_time {
    public long tomillisecond(Object a) {
        Calendar cal = Calendar.getInstance();
        //SimpleDateFormat sdf = new SimpleDateFormat("yyyy 年 MM 月 dd 日 - HH 時 mm 分 ss 秒");
        String time = (String) a;
        time = time.replace("年", ",");
        time = time.replace("月", ",");
        time = time.replace("日", ",");
        time = time.replace("時", ",");
        time = time.replace("分", ",");
        time = time.replace("秒", ",");
        time = time.replace("-", "");
        time = time.replace(" ", "");
        String[] split_time = time.split(",");
        cal.set(Integer.valueOf(split_time[0]), Integer.valueOf(split_time[1]), Integer.valueOf(split_time[2]),
                Integer.valueOf(split_time[3]), Integer.valueOf(split_time[4]), Integer.valueOf(split_time[5]));
        return cal.getTimeInMillis();
    }

    public String tostring(long a) {
        Calendar cal = Calendar.getInstance();
        SimpleDateFormat sdf = new SimpleDateFormat("yyyy 年 MM 月 dd 日 - HH 時 mm 分 ss 秒");
        long second = a;
        cal.setTimeInMillis(second);
        return sdf.format(cal.getTime());
    }

    public long tomillisecond_withcmd(String a) {
        String separate_time = a;
        String[] split_time = separate_time.split(":");
        long millisecond = 1000 * (
                (Long.valueOf(split_time[0]) * 24 * 60 * 60) +
                        (Long.valueOf(split_time[1]) * 60 * 60) +
                        (Long.valueOf(split_time[2]) * 60)) + new Date().getTime();
        return millisecond;
    }
}