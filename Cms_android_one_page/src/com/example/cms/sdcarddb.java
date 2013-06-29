package com.example.cms;
//把数据库写道内存卡上
//方便以后数据的转移


import java.io.File;
import java.io.IOException;

import android.database.sqlite.SQLiteDatabase;
import android.os.Environment;

public class sdcarddb {
	public static String filepach=Environment.getExternalStorageDirectory() + "/cms";
	private static  File path = new File(filepach);	
	public static File f = new File(filepach+"/cms.db");
	
	public static void isNot()//如果数据库不存在，则建立数据库，并创建表
	{
		 if (!path.exists()) {// 目录存在返回false  
	          path.mkdirs();// 创建一个目录  
	      }  
	      if (!f.exists()) {// 文件存在返回false  
	          try {  
	        	  f.createNewFile();//创建文件   
	          }
	           catch (IOException e) {  
	              // TODO Auto-generated catch block  
	              e.printStackTrace();  
	          }  
	      }else{return ;}
	      
	      SQLiteDatabase db = SQLiteDatabase.openOrCreateDatabase(f, null);
	      String tmp = "CREATE TABLE bpin (id varchar(200) PRIMARY KEY,";
	      tmp += "date  DATE NOT NULL, factory  varchar(1024),num  varchar(200) NOT NULL,state int NOT NULL, dx  int default 0, tx  int default 0,"  ;   
	      tmp += "dd  int default 0, djhz  int default 0,  ml  int default 0,mbbl  int default 0,xjbl  int default 0,wdhz  int default 0,ps  int default 0, ";
	      tmp += " mc  int default 0,ztbl  int default 0,xbl  int default 0,wz  int default 0,sc  int default 0,yr  int default 0,"; 
	      tmp +="  cx  int default 0,dpsb  int default 0, xd  int default 0,ccbl  int default 0,kmd  int default 0, ggxz  int default 0,";
	      tmp +="sjs  int default 0,mxnz  int default 0,psbl  int default 0,xy varchar(1024) NOT NULL)";
	      db.execSQL(tmp);
	      tmp = "CREATE TABLE jianpin (id varchar(200) PRIMARY KEY,date  DATE NOT NULL,factory  varchar(1024),num  varchar(200) NOT NULL, Ap  int default 0, Bp  int default 0)";
	      db.execSQL(tmp);
	      db.close();
	}
	
}
