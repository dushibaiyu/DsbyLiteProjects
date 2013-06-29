package com.example.cms;

import android.os.Bundle;
import android.app.Activity;
import android.app.Dialog;
import android.content.Intent;
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
	private final static int DIALOG=1;
	
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);
		
		mbut_lvli = (Button)findViewById(R.id.but_lvli);
		mbut_lvli.setOnClickListener(new Button.OnClickListener(){	@SuppressWarnings("deprecation")
		public void onClick(View v){
																								getValues();
																								if (0==cms.date.length()||0==cms.pinfan.length())
																								{
																									showDialog(DIALOG);
																								}
																								else{
																									onButLvli();}
																								}});
		
		mbut_add = (Button)findViewById(R.id.but_add);
		mbut_add.setOnClickListener( new Button.OnClickListener(){  @SuppressWarnings("deprecation")
		public void onClick(View v){
																								getValues();
																								if (0==cms.date.length()||0==cms.pinfan.length())
																								{
																									showDialog(DIALOG);
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
	
	//@Override
/*	public void onClick(View v) //接受点击时间
	{
		switch(v.getId())
		{
		case R.id.but_lvli :
			onButLvli();
			break;
		case R.id.but_add :
			onButAdd();
			break;
		}
	}*/
	
	public void onButLvli()
	{
		Intent intent = new Intent();
    	intent.setClass(this, LvliActivity.class);
    	startActivity(intent);
	}
	public void onButAdd()
	{
		Intent intent = new Intent();
    	intent.setClass(this, AddActivity.class);
    	startActivity(intent);
	}

	public void getValues()
	{
		cms.date = med_date.getText().toString();
		cms.gongchang = med_gongchang.getText().toString();
		cms.pinfan = med_pinfan.getText().toString();
	}
	
	@Override
	 protected Dialog onCreateDialog(int id)
	{
	        Dialog dialog=null;
	        switch (id) 
	        {
	        case DIALOG:
		        android.app.AlertDialog.Builder builder=new android.app.AlertDialog.Builder(this);
	            builder.setTitle("提示：");
	            builder.setMessage("日期和品番不能为空！");
	            builder.setPositiveButton("确认",null);
	            dialog = builder.create();
	            break;
	        }
			return dialog;
	}
}
