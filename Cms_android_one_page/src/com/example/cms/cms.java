package com.example.cms;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import android.os.Environment;
import android.annotation.SuppressLint;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;

  

public class cms {//全局变量

	public static String date = "";//时间
	public static String gongchang  = "";//工厂
	public static String pinfan  = "";//品番
	public static int radio = 0;//衣服面
	public static String xy= "";//点击的坐标
	@SuppressLint("SdCardPath")
	public static String fileurl=Environment.getExternalStorageDirectory() + "/";//得到
	public static String url = "http://192.168.1.104/";//服务器地址
	public static Bitmap getLoacalBitmap(String url) {//从内存卡读取图片的函数
        try {
             FileInputStream fis = new FileInputStream(url);
             return BitmapFactory.decodeStream(fis);  ///把流转化为Bitmap图片         

          } catch (FileNotFoundException e) {
             e.printStackTrace();
             return null;
        }
	}
}
