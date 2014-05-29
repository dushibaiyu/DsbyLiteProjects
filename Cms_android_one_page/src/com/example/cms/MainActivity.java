/*
 * 主要的入口页面
 * 现在数据库转移到内存卡中，方便有后数据的转移
 * */


package com.example.cms;

import android.os.Bundle;
import android.app.Activity;
import android.app.Dialog;
import android.content.Intent;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.view.Menu;
import android.view.View;
//import android.view.View.OnClickListener;
import android.widget.*;

public class MainActivity extends Activity {

	private Button mbut_lvli;//定义buuton
	private Button mbut_add;
	private EditText med_date;
	private EditText med_gongchang;
	private EditText med_pinfan;
	private mysqllite sqlHelper;
	private String[] item = new String[]{" 断          线："," 跳          线："," 掉          道："," 打结回针："," 毛          漏："," 码边不良：",
										 " 线迹不良："," 无倒回针："," 破          损："," 面          疵："," 整烫不良："," 形  不  良：",
										 " 污          渍："," 色          差："," 印          染："," 刺          绣：","吊牌·商标："," 洗          涤：",
										 " 尺寸不良："," 扣·铆钉  ： ","挂钩·橡根："," 水  晶  石 ：","毛須·捏折："," 喷沙不良："};
	String[] itemm = new String[13];
	
	private Button id_add;
	
	@Override
	protected void onCreate(Bundle savedInstanceState) {//设置和注册控件和控件事件
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);
		sqlHelper = new mysqllite(this,"cms.db",null,1);
		sdcarddb.isNot();
		
		id_add = (Button)findViewById(R.id.id2_add);
		id_add.setOnClickListener(new Button.OnClickListener(){	
		@SuppressWarnings("deprecation")
		public void onClick(View v){getValues();
		if (0==cms.date.length()||0==cms.pinfan.length())
		{
			showDialog(1);
		}else{onButidAdd();}}});
		
		mbut_lvli = (Button)findViewById(R.id.but_lvli);
		mbut_lvli.setOnClickListener(new Button.OnClickListener(){	@SuppressWarnings("deprecation")
		public void onClick(View v){
																								getValues();
																								if (0==cms.date.length()||0==cms.pinfan.length())
																								{
																									showDialog(1);
																								}
																								else{
																									selectSql();
																									showDialog(2);
																									}
																								}});
		
		mbut_add = (Button)findViewById(R.id.but_add);
		mbut_add.setOnClickListener( new Button.OnClickListener(){  @SuppressWarnings("deprecation")
		public void onClick(View v){
																								getValues();
																								if (0==cms.date.length()||0==cms.pinfan.length())
																								{
																									showDialog(1);
																								}
																								else
																								{
																									onButAdd();} }});
		
		med_date = (EditText)findViewById(R.id.edit_date);
		med_gongchang = (EditText)findViewById(R.id.edit_gongchang);
		med_pinfan = (EditText)findViewById(R.id.edit_pinfan);
	}
	

	@Override
	public boolean onCreateOptionsMenu(Menu menu) {
		// Inflate the menu; this adds items to the action bar if it is present.
		getMenuInflater().inflate(R.menu.main, menu);
		return true;
	}
		
	/*public void onButLvli()
	{
		Intent intent = new Intent();
    	intent.setClass(this, LvliActivity.class);
    	startActivity(intent);
	}*/
	public void onButAdd()//打开增加B页面
	{
		Intent intent = new Intent();
    	intent.setClass(this, AddBActivity.class);
    	startActivity(intent);
	}
	
	public void onButidAdd()//打开品番页面
	{
		Intent intent = new Intent();
    	intent.setClass(this, AddPfActivity.class);
    	startActivity(intent);
	}

	public void getValues()//获取输入框数据，写入到全局变量
	{
		cms.date = med_date.getText().toString();
		cms.gongchang = med_gongchang.getText().toString();
		cms.pinfan = med_pinfan.getText().toString();
	}
	
	public void selectSql()//构造和执行查询，boingqie把结果写入String[]
	{
		String sql = "select  sum(dx) , sum(tx) , sum(dd) , sum(djhz) , sum(ml) , sum(mbbl) , sum(xjbl) ,";
		sql += "sum(wdhz) , sum(ps) , sum(mc) , sum(ztbl) , sum(xbl) ,sum(wz) , sum(sc) , sum(yr) , ";
		sql += "sum(cx) , sum(dpsb) , sum(xd) , sum(ccbl) , sum(kmd) , sum(ggxz) , sum(sjs) , sum(mxnz) , sum(psbl) ";
		sql = sql + "from bpin where date='"+cms.date+"' and num='"+ cms.pinfan + "'"; 
		String sqlAB = "select sum(Ap),sum(Bp) from jianpin where date='"+cms.date+"' and num='"+ cms.pinfan + "'";
		//SQLiteDatabase Sql = sqlHelper.getReadableDatabase(); 
		
		SQLiteDatabase Sql =SQLiteDatabase.openOrCreateDatabase(sdcarddb.f, null);
		Cursor cur = Sql.rawQuery(sql, null);
		
		Cursor cur2 = Sql.rawQuery(sqlAB, null);
		cur2.moveToFirst();
		itemm[0] = "A品数：" + cur2.getString(0) + "                     "  + "B品数：" + cur2.getString(1);
		cur.moveToFirst();
		for (int j = 0,i = 1; j<24; j+=2,++i)
		{
			itemm[i] =item[j]+ cur.getString(j)+ "                 "  + item[j+1] + cur.getString(j+1);
		}
		cur.close();
		cur2.close();
		Sql.close();

	}
	
	@Override
	 protected Dialog onCreateDialog(int id)//创建对话框
	{
	        Dialog dialog=null;
	        android.app.AlertDialog.Builder builder=new android.app.AlertDialog.Builder(this);
	        switch (id) 
	        {
	        case 1 :
		       //提示输入不为空的对话框
	            builder.setTitle("提示：");
	            builder.setMessage("日期和品番不能为空！");
	            builder.setPositiveButton("确认",null);
	            dialog = builder.create();
	            break;
	        case 2 :
	        	//显示检索页面的对话框
	        	builder.setTitle("检索数据：");
	        	builder.setItems(itemm, null);
	        	builder.setNegativeButton("确定", null).show();
	        	break;
	        }
	        dialog = builder.create();
			return dialog;
	}
}
