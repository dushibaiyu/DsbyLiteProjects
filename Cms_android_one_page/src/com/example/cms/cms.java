package com.example.cms;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import android.os.Environment;
import android.annotation.SuppressLint;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;

  

public class cms {//ȫ�ֱ���

	public static String date = "";//ʱ��
	public static String gongchang  = "";//����
	public static String pinfan  = "";//Ʒ��
	public static int radio = 0;//�·���
	public static String xy= "";//���������
	@SuppressLint("SdCardPath")
	public static String fileurl=Environment.getExternalStorageDirectory() + "/";//�õ�
	public static String url = "http://192.168.1.104/";//��������ַ
	public static Bitmap getLoacalBitmap(String url) {//���ڴ濨��ȡͼƬ�ĺ���
        try {
             FileInputStream fis = new FileInputStream(url);
             return BitmapFactory.decodeStream(fis);  ///����ת��ΪBitmapͼƬ         

          } catch (FileNotFoundException e) {
             e.printStackTrace();
             return null;
        }
	}
}
