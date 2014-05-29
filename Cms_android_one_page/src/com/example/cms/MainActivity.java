/*
 * ��Ҫ�����ҳ��
 * �������ݿ�ת�Ƶ��ڴ濨�У������к����ݵ�ת��
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

	private Button mbut_lvli;//����buuton
	private Button mbut_add;
	private EditText med_date;
	private EditText med_gongchang;
	private EditText med_pinfan;
	private mysqllite sqlHelper;
	private String[] item = new String[]{" ��          �ߣ�"," ��          �ߣ�"," ��          ����"," �����룺"," ë          ©��"," ��߲�����",
										 " �߼�������"," �޵����룺"," ��          ��"," ��          �ã�"," ���̲�����"," ��  ��  ����",
										 " ��          �գ�"," ɫ          �"," ӡ          Ⱦ��"," ��          �壺","���ơ��̱꣺"," ϴ          �ӣ�",
										 " �ߴ粻����"," �ۡ�í��  �� ","�ҹ��������"," ˮ  ��  ʯ ��","ë횡����ۣ�"," ��ɳ������"};
	String[] itemm = new String[13];
	
	private Button id_add;
	
	@Override
	protected void onCreate(Bundle savedInstanceState) {//���ú�ע��ؼ��Ϳؼ��¼�
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
	public void onButAdd()//������Bҳ��
	{
		Intent intent = new Intent();
    	intent.setClass(this, AddBActivity.class);
    	startActivity(intent);
	}
	
	public void onButidAdd()//��Ʒ��ҳ��
	{
		Intent intent = new Intent();
    	intent.setClass(this, AddPfActivity.class);
    	startActivity(intent);
	}

	public void getValues()//��ȡ��������ݣ�д�뵽ȫ�ֱ���
	{
		cms.date = med_date.getText().toString();
		cms.gongchang = med_gongchang.getText().toString();
		cms.pinfan = med_pinfan.getText().toString();
	}
	
	public void selectSql()//�����ִ�в�ѯ��boingqie�ѽ��д��String[]
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
		itemm[0] = "AƷ����" + cur2.getString(0) + "                     "  + "BƷ����" + cur2.getString(1);
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
	 protected Dialog onCreateDialog(int id)//�����Ի���
	{
	        Dialog dialog=null;
	        android.app.AlertDialog.Builder builder=new android.app.AlertDialog.Builder(this);
	        switch (id) 
	        {
	        case 1 :
		       //��ʾ���벻Ϊ�յĶԻ���
	            builder.setTitle("��ʾ��");
	            builder.setMessage("���ں�Ʒ������Ϊ�գ�");
	            builder.setPositiveButton("ȷ��",null);
	            dialog = builder.create();
	            break;
	        case 2 :
	        	//��ʾ����ҳ��ĶԻ���
	        	builder.setTitle("�������ݣ�");
	        	builder.setItems(itemm, null);
	        	builder.setNegativeButton("ȷ��", null).show();
	        	break;
	        }
	        dialog = builder.create();
			return dialog;
	}
}
