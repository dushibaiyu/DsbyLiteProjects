package com.example.cms;

import android.os.Bundle;
import android.view.Menu;
import android.view.View;
//import android.animation.AnimatorSet.Builder;
import android.app.Activity;
import android.app.Dialog;
//import android.app.AlertDialog.*;
import android.content.*;
import android.database.sqlite.SQLiteDatabase;
import android.widget.*;
import java.util.UUID;
//import android.content.Context;  
//import android.database.Cursor;   
//import android.database.sqlite.SQLiteDatabase.*;
//import android.database.sqlite.SQLiteOpenHelper;

public  class OneActivity extends Activity {

	private ImageView img;
	private Button but;
	private final static int DIALOG=1;
    boolean[] flags=new boolean[]{	false,false,false,false,false,false,
    								false,false,false,false,false,false,
    								false,false,false,false,false,false,
    								false,false,false,false,false,false};//初始复选情况
    String[] items=null;
    private String sql = "insert into main ( id,date,";   
    boolean gc = false;
    private int tj = 0;
    private mysqllite sqlHelper;
	
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_one);
		
		sqlHelper = new mysqllite(this,"cms.db",null,1);
		
		but = (Button)findViewById(R.id.but_add1_back);
		but.setOnClickListener(new Button.OnClickListener(){	public void onClick(View v){finish();}});
		img = (ImageView)findViewById(R.id.imageView1);
		img.setOnClickListener(new ImageView.OnClickListener(){@SuppressWarnings("deprecation")
		public void onClick(View v){/*onImgClik()*/showDialog(DIALOG);;}});
		
		if ("" != cms.gongchang)
		{
			sql += "factory ,";
			gc = true;
		}
		
		sql += "num,state ";
	}

	@Override
	public boolean onCreateOptionsMenu(Menu menu) {
		// Inflate the menu; this adds items to the action bar if it is present.
		getMenuInflater().inflate(R.menu.one, menu);
		return true;
	}
	

    @Override
    protected Dialog onCreateDialog(int id) {
        Dialog dialog=null;
        switch (id) {
        case DIALOG:
            android.app.AlertDialog.Builder builder=new android.app.AlertDialog.Builder(this);
            //设置对话框的图标
           // builder.setIcon(R.drawable.header);
            //设置对话框的标题
            builder.setTitle("选择问题：");
            builder.setMultiChoiceItems(R.array.hobby, flags, new DialogInterface.OnMultiChoiceClickListener(){
                public void onClick(DialogInterface dialog, int which, boolean isChecked) {
                   flags[which]=isChecked;
                  /*  String result = "您选择了：";
                    for (int i = 0; i < flags.length; i++) {
                        if(flags[i]){
                            result=result+items[i]+"、";
                        }
                    }*/
  //                  editText.setText(result.substring(0, result.length()-1));
                }
            });
            
            //添加一个确定按钮
            builder.setPositiveButton(" 确 定 ", new DialogInterface.OnClickListener(){
                public void onClick(DialogInterface dialog, int which) {
                	
												                	isClik();
												                	if (tj > 0)
												                	{  
												                		exeSql();
												                    	SQLiteDatabase Sql = sqlHelper.getWritableDatabase(); 
												                    	Sql.execSQL(sql);
												                    	Sql.close();
												                    	//cleanSelect();
												                    	finish();												                   
												                	}
												                	
												                	cleanSelect();
												                	
												                    }
                }
           );
            builder.setNegativeButton("取消", new DialogInterface.OnClickListener(){
				@Override
				public void onClick(DialogInterface dialog, int which) {
					// TODO Auto-generated method stub
																cleanSelect();
																
				}}     
                ).show();
            //创建一个复选框对话框
            dialog=builder.create();
            break;
        }
        return dialog;
    }

    public void cleanSelect()
    {
    	for (int i= 0; i<flags.length; ++i)
    	{
    		if(flags[i])
    		{
    			flags[i] = false;
    		}
    	}
    }

    public void isClik()
    {
    	for (int i= 0; i<flags.length; ++i)
    	{
    		if(flags[i])
    		{
    			tj ++;
    		}
    	}
    }
    
    public void exeSql()
    {
    	String tmp = "";
    	for (int i = 0; i < flags.length; i++)
    	{
    		 if(flags[i])
    		 {
    			 switch (i)
    			 {
    			 case 0:
    				 tmp += ",dx";
    				 break;
    			 case 1:
    				 tmp += ",tx";
    				 break;
    			 case 2:
    				 tmp += ",dd";
    				 break;
    			 case 3:
    				 tmp += ",djhz";
    				 break;
    			 case 4:
    				 tmp += ",ml";
    				 break;
    			 case 5:
    				 tmp += ",mbbl";
    				 break;
    			 case 6:
    				 tmp += ",xjbl";
    				 break;
    			 case 7:
    				 tmp += ",wdhz";
    				 break;
    			 case 8:
    				 tmp += ",ps";
    				 break;
    			 case 9:
    				 tmp += ",mc";
    				 break;
    			 case 10:
    				 tmp += ",ztbl";
    				 break;
    			 case 11:
    				 tmp += ",xbl";
    				 break;
    			 case 12:
    				 tmp += ",wz";
    				 break;
    			 case 13:
    				 tmp += ",sc";
    				 break;
    			 case 14:
    				 tmp += ",yr";
    				 break;
    			 case 15:
    				 tmp += ",cx";
    				 break;
    			 case 16:
    				 tmp += ",dpsb";
    				 break;
    			 case 17:
    				 tmp += ",xd";
    				 break;
    			 case 18:
    				 tmp += ",ccbl";
    				 break;
    			 case 29:
    				 tmp += ",kmd";
    				 break;
    			 case 20:
    				 tmp += ",ggxz";
    				 break;
    			 case 21:
    				 tmp += ",sjs";
    				 break;
    			 case 22:
    				 tmp += ",mxnz";
    				 break;
    			 case 23:
    				 tmp += ",psbl";
    				 break;
    			 }
    		 }
    	}
    		 sql = sql + tmp + ")values('";
    		 UUID uuid = UUID.randomUUID();
    		 sql = sql + uuid.toString()+"','" + cms.date + "'";
    		 if (gc){sql = sql + ",'" + cms.gongchang + "'";}
    		 sql = sql + ",'" + cms.pinfan + "',1"; 
    		
    		 tmp = "";
    		 for (int j = 0; j<tj; ++j)
    		 {
    			 tmp  += ",1";
    		 }
    		 sql = sql + tmp + ")";
    	
    }


}
