package com.example.cms;
//�ṩ���ݿ�������ࡣ
//��ϵͳĿ¼�������ݿ�
import android.content.Context;  
import android.database.sqlite.SQLiteDatabase;  
import android.database.sqlite.SQLiteDatabase.CursorFactory;
import android.database.sqlite.SQLiteOpenHelper;  

public class mysqllite extends SQLiteOpenHelper
{
	public mysqllite(Context onClickListener, String name, CursorFactory factory,
			int version) {
		super(onClickListener, name, factory, version);
		// TODO Auto-generated constructor stub
	}

   
		     
     @Override    
     public void onCreate(SQLiteDatabase db) {//�½����ݿ��ִ�еĶ���
         // TODO �������ݿ�󣬶����ݿ�Ĳ���  
    	 String tmp = "CREATE TABLE bpin (id varchar(200) PRIMARY KEY,";
    	 tmp += "date  DATE NOT NULL, factory  varchar(1024),num  varchar(200) NOT NULL,state int NOT NULL, dx  int default 0, tx  int default 0,"  ;   
    	tmp += "dd  int default 0, djhz  int default 0,  ml  int default 0,mbbl  int default 0,xjbl  int default 0,wdhz  int default 0,ps  int default 0, ";
    	tmp += " mc  int default 0,ztbl  int default 0,xbl  int default 0,wz  int default 0,sc  int default 0,yr  int default 0,"; 
    	tmp +="  cx  int default 0,dpsb  int default 0, xd  int default 0,ccbl  int default 0,kmd  int default 0, ggxz  int default 0,";
    	tmp +="sjs  int default 0,mxnz  int default 0,psbl  int default 0,xy varchar(1024) NOT NULL)";
    	db.execSQL(tmp);
    	tmp = "CREATE TABLE jianpin (id varchar(200) PRIMARY KEY,date  DATE NOT NULL,factory  varchar(1024),num  varchar(200) NOT NULL, Ap  int default 0, Bp  int default 0)";
    	db.execSQL(tmp);
    	//db.close();
     }

	@Override
	public void onUpgrade(SQLiteDatabase db, int oldVersion,
			int newVersion) {//�������ݿ�汾��ִ�еĶ���
		// TODO Auto-generated method stub
		
	}     

}
