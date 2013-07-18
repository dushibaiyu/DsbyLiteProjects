package com.example.cms;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;

import com.example.cms.R.id;

import android.os.Bundle;
import android.app.Activity;
import android.content.DialogInterface.OnClickListener;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.view.Menu;
import android.view.View;
import android.widget.*;

public class LvliActivity extends Activity {

	private Button mbut_back;
	private EditText med_date;
	private EditText med_gongchang;
	private EditText med_pinfan;
	private ListView lview;
	private mysqllite sqlHelper;
	List<HashMap<String , String>> data = new ArrayList<HashMap<String , String>>();
	 
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_lvli);
		
		sqlHelper = new mysqllite(this,"cms.db",null,1);
		
		mbut_back = (Button)findViewById(R.id.but_buck_lvli);
		mbut_back.setOnClickListener(new Button.OnClickListener(){	public void onClick(View v){finish();}});
		med_date = (EditText)findViewById(R.id.editdate);
		med_gongchang = (EditText)findViewById(R.id.editgongchang);
		med_pinfan = (EditText)findViewById(R.id.editpinfan);
		med_date.setText(cms.date);
		med_gongchang.setText(cms.gongchang);
		med_pinfan.setText(cms.pinfan);
		lview = (ListView)findViewById(R.id.listView1);
		//selectSql();
		
		SimpleAdapter adapter=new SimpleAdapter(this,data,R.layout.list_item,new String[]{"wt","sm"},new int[]{R.id.wt,R.id.sm});
		lview.setAdapter(adapter);
	}

	@Override
	public boolean onCreateOptionsMenu(Menu menu) {
		// Inflate the menu; this adds items to the action bar if it is present.
		getMenuInflater().inflate(R.menu.lvli, menu);
		return true;
	}

	protected void selectSql()
	{
		String[] columns = {"sum(dx)","sum(tx)","sum(dd)","sum(djhz)",
								"sum(ml)","sum(mbbl)","sum(xjbl)","sum(wdhz)","sum(ps)","sum(mc)","sum(ztbl)","sum(xbl)",
								"sum(wz)","sum(sc)","sum(yr)","sum(cx)","sum(dpsb)","sum(xd)","sum(ccbl)","sum(kmd)",
								"sum(ggxz)","sum(sjs)","sum(mxnz)","sum(psbl)"};
		String where = "date = '" + cms.date + "' and "+" num = '" + cms.pinfan + "'";  
    	SQLiteDatabase Sql = sqlHelper.getReadableDatabase(); 
    	Cursor cur = Sql.query("main", columns,where, null, null, null, null);
    	cur.moveToFirst();
    	HashMap<String , String> list = new HashMap<String , String>();
    	list.put("wt", "����");
    	list.put("sm", cur.getString(0));
    	data.add(list);
    	list.clear();
    	list.put("wt", "����");
    	list.put("sm", cur.getString(1));
    	data.add(list);
    	list.clear();
    	list.put("wt", "����");
    	list.put("sm", cur.getString(2));
    	data.add(list);
    	list.clear();
    	list.put("wt", "������");
    	list.put("sm", cur.getString(3));
    	data.add(list);
    	list.clear();
    	list.put("wt", "ë©");
    	list.put("sm", cur.getString(4));
    	data.add(list);
    	list.clear();
    	list.put("wt", "��߲���");
    	list.put("sm", cur.getString(5));
    	data.add(list);
    	list.clear();
    	list.put("wt", "�߼�����");
    	list.put("sm", cur.getString(6));
    	data.add(list);
    	list.clear();
    	list.put("wt", "�߼�����");
    	list.put("sm", cur.getString(7));
    	data.add(list);
    	list.clear();
    	list.put("wt", "����");
    	list.put("sm", cur.getString(8));
    	data.add(list);
    	list.clear();
    	list.put("wt", "���");
    	list.put("sm", cur.getString(9));
    	data.add(list);
    	list.clear();
    	list.put("wt", "���̲���");
    	list.put("sm", cur.getString(10));
    	data.add(list);
    	list.clear();
    	list.put("wt", "�β���");
    	list.put("sm", cur.getString(11));
    	data.add(list);
    	list.clear();
    	list.put("wt", "����");
    	list.put("sm", cur.getString(12));
    	data.add(list);
    	list.clear();
    	list.put("wt", "ɫ��");
    	list.put("sm", cur.getString(13));
    	data.add(list);
    	list.clear();
    	list.put("wt", "ӡȾ");
    	list.put("sm", cur.getString(14));
    	data.add(list);
    	list.clear();
    	list.put("wt", "����");
    	list.put("sm", cur.getString(15));
    	data.add(list);
    	list.clear();
    	list.put("wt", "���ơ��̱�");
    	list.put("sm", cur.getString(16));
    	data.add(list);
    	list.clear();
    	list.put("wt", "ϴ��");
    	list.put("sm", cur.getString(17));
    	data.add(list);
    	list.clear();
    	list.put("wt", "�ߴ粻��");
    	list.put("sm", cur.getString(18));
    	data.add(list);
    	list.clear();
    	list.put("wt", "�ۡ�í��");
    	list.put("sm", cur.getString(19));
    	data.add(list);
    	list.clear();
    	list.put("wt", "�ҹ������");
    	list.put("sm", cur.getString(20));
    	data.add(list);
    	list.clear();
    	list.put("wt", "ˮ��ʯ");
    	list.put("sm", cur.getString(21));
    	data.add(list);
    	list.clear();
    	list.put("wt", "ë횡�����");
    	list.put("sm", cur.getString(22));
    	data.add(list);
    	list.clear();
    	list.put("wt", "��ɳ����");
    	list.put("sm", cur.getString(23));
    	data.add(list);
    	list.clear();
    	cur.close();
	}
}
