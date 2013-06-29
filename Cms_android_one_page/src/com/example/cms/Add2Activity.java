package com.example.cms;

import android.os.Bundle;
import android.app.Activity;
import android.database.sqlite.SQLiteDatabase;
import android.graphics.Color;
import android.view.Menu;
import android.view.View;
import android.widget.*;

import java.util.UUID;

public class Add2Activity extends Activity {

	boolean[] flags=new boolean[]{	false,false,false,false,false,false,
									false,false,false,false,false,false,
									false,false,false,false,false,false,
									false,false,false,false,false,false};
	private Button but_add;
	private Button but_back;
	private CheckBox [] cb = new CheckBox[24];
	private String sql = "";
	private mysqllite sqlHelper;
	private GridLayout gd;
	//int color = Color.
	
	@Override
	protected void onCreate(Bundle savedInstanceState) {//初始化页面
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_add2);
		sqlHelper = new mysqllite(this,"cms.db",null,1);
		gd = (GridLayout)findViewById(R.id.gridLayout1);
		gd.setBackgroundColor(Color.WHITE);
		
		but_back =(Button)findViewById(R.id.but_2back);
		but_back.setOnClickListener(new Button.OnClickListener(){	public void onClick(View v){finish();}});
		checkbox();
		but_add = (Button)findViewById(R.id.but_2add);
		but_add.setOnClickListener(new Button.OnClickListener(){	
			public void onClick(View v){
				if (howtrue() > 0)
				{
					//SQLiteDatabase Sql = sqlHelper.getWritableDatabase(); 
					SQLiteDatabase Sql =SQLiteDatabase.openOrCreateDatabase(sdcarddb.f, null);
					createSql();
					Sql.execSQL(sql);
					
					Sql.close();
				}
				finish();}});
	}

	@Override
	public boolean onCreateOptionsMenu(Menu menu) {
		// Inflate the menu; this adds items to the action bar if it is present.
		getMenuInflater().inflate(R.menu.add2, menu);
		return true;
	}
	
	public int howtrue()//判断有没有先择项，没有选择项不向数据库添加数据
	{
		int tmp = 0;
		for (int i= 0; i<flags.length; ++i)
		{
			if (flags[i])
			{
				tmp ++;
			}
		}
		return tmp;
	}
	
	public void createSql()//根据条件生成sql语句
	{
		UUID uuid = UUID.randomUUID();
		sql =" insert into bpin ( id,date,factory,num,state,dx,tx,dd,djhz,ml,mbbl,xjbl,";
		sql += "wdhz,ps,mc,ztbl,xbl,wz,sc,yr,cx,dpsb,xd,ccbl,kmd,ggxz,sjs,mxnz,psbl,xy) values ( '";
		sql = sql +  uuid.toString()+"','" + cms.date + "','" + cms.gongchang + "','" + cms.pinfan;
		sql = sql + "'," + cms.radio ;
		
		for (int i= 0; i<flags.length; ++i)
		{
			if (flags[i])
			{
				sql += ",1";
			}
			else 
			{
				sql += ",0";
			}
		}
		sql = sql +  ",'" + cms.xy + "')";
		
	}

	public void checkbox()//初始化checkbox和为checkbox注册事件
	{
		cb[0] = (CheckBox)findViewById(R.id.cb1);
		cb[0].setOnCheckedChangeListener(new CompoundButton.OnCheckedChangeListener(){ 
            @Override 
            public void onCheckedChanged(CompoundButton buttonView, 
                    boolean isChecked) { 
		            	if(isChecked){ flags[0] = true;cb[0].setBackgroundColor(Color.RED);closecheckbox(0);//选中后背景设为红色，并关闭其他选项
		                }else{ flags[0] = false;cb[0].setBackgroundColor(Color.TRANSPARENT);opencheckbox();} }  }); //取消选择，背景重新设为透明，打开所有选项
		
		cb[1] = (CheckBox)findViewById(R.id.cb2);
		cb[1].setOnCheckedChangeListener(new CompoundButton.OnCheckedChangeListener(){ 
            @Override 
            public void onCheckedChanged(CompoundButton buttonView, 
                    boolean isChecked) { 
		            	if(isChecked){ flags[1] = true;cb[1].setBackgroundColor(Color.RED);closecheckbox(1);
		                }else{ flags[1] = false;cb[1].setBackgroundColor(Color.TRANSPARENT);opencheckbox();} }  }); 
		cb[2] = (CheckBox)findViewById(R.id.cb3);
		cb[2].setOnCheckedChangeListener(new CompoundButton.OnCheckedChangeListener(){ 
            @Override 
            public void onCheckedChanged(CompoundButton buttonView, 
                    boolean isChecked) { 
		            	if(isChecked){ flags[2] = true;cb[2].setBackgroundColor(Color.RED);closecheckbox(2);
		                }else{ flags[2] = false;cb[2].setBackgroundColor(Color.TRANSPARENT);opencheckbox();} }  }); 
		cb[3] = (CheckBox)findViewById(R.id.cb4);
		cb[3].setOnCheckedChangeListener(new CompoundButton.OnCheckedChangeListener(){ 
            @Override 
            public void onCheckedChanged(CompoundButton buttonView, 
                    boolean isChecked) { 
		            	if(isChecked){ flags[3] = true;cb[3].setBackgroundColor(Color.RED);closecheckbox(3);
		                }else{ flags[3] = false;cb[3].setBackgroundColor(Color.TRANSPARENT);opencheckbox();} }  }); 
		cb[4] = (CheckBox)findViewById(R.id.cb5);
		cb[4].setOnCheckedChangeListener(new CompoundButton.OnCheckedChangeListener(){ 
            @Override 
            public void onCheckedChanged(CompoundButton buttonView, 
                    boolean isChecked) { 
		            	if(isChecked){ flags[4] = true;cb[4].setBackgroundColor(Color.RED);closecheckbox(4);
		                }else{ flags[4] = false;cb[4].setBackgroundColor(Color.TRANSPARENT);opencheckbox();} }  }); 
		cb[5] = (CheckBox)findViewById(R.id.cb6);
		cb[5].setOnCheckedChangeListener(new CompoundButton.OnCheckedChangeListener(){ 
            @Override 
            public void onCheckedChanged(CompoundButton buttonView, 
                    boolean isChecked) { 
		            	if(isChecked){ flags[5] = true;cb[5].setBackgroundColor(Color.RED);closecheckbox(5);
		                }else{ flags[5] = false;cb[5].setBackgroundColor(Color.TRANSPARENT);opencheckbox();} }  }); 
		cb[6] = (CheckBox)findViewById(R.id.cb7);
		cb[6].setOnCheckedChangeListener(new CompoundButton.OnCheckedChangeListener(){ 
            @Override 
            public void onCheckedChanged(CompoundButton buttonView, 
                    boolean isChecked) { 
		            	if(isChecked){ flags[6] = true;cb[6].setBackgroundColor(Color.RED);closecheckbox(6);
		                }else{ flags[6] = false;cb[6].setBackgroundColor(Color.TRANSPARENT);opencheckbox();} }  }); 
		cb[7] = (CheckBox)findViewById(R.id.cb8);
		cb[7].setOnCheckedChangeListener(new CompoundButton.OnCheckedChangeListener(){ 
            @Override 
            public void onCheckedChanged(CompoundButton buttonView, 
                    boolean isChecked) { 
		            	if(isChecked){ flags[7] = true;cb[7].setBackgroundColor(Color.RED);closecheckbox(7);
		                }else{ flags[7] = false;cb[7].setBackgroundColor(Color.TRANSPARENT);opencheckbox();} }  }); 
		cb[8] = (CheckBox)findViewById(R.id.cb9);
		cb[8].setOnCheckedChangeListener(new CompoundButton.OnCheckedChangeListener(){ 
            @Override 
            public void onCheckedChanged(CompoundButton buttonView, 
                    boolean isChecked) { 
		            	if(isChecked){ flags[8] = true;cb[8].setBackgroundColor(Color.RED);closecheckbox(8);
		                }else{ flags[8] = false;cb[8].setBackgroundColor(Color.TRANSPARENT);opencheckbox();} }  }); 
		cb[9] = (CheckBox)findViewById(R.id.cb10);
		cb[9].setOnCheckedChangeListener(new CompoundButton.OnCheckedChangeListener(){ 
            @Override 
            public void onCheckedChanged(CompoundButton buttonView, 
                    boolean isChecked) { 
		            	if(isChecked){ flags[9] = true;cb[9].setBackgroundColor(Color.RED);closecheckbox(9);
		                }else{ flags[9] = false;cb[9].setBackgroundColor(Color.TRANSPARENT);opencheckbox();} }  }); 
		cb[10] = (CheckBox)findViewById(R.id.cb11);
		cb[10].setOnCheckedChangeListener(new CompoundButton.OnCheckedChangeListener(){ 
            @Override 
            public void onCheckedChanged(CompoundButton buttonView, 
                    boolean isChecked) { 
		            	if(isChecked){ flags[10] = true;cb[10].setBackgroundColor(Color.RED);closecheckbox(10);
		                }else{ flags[10] = false;cb[10].setBackgroundColor(Color.TRANSPARENT);opencheckbox();} }  }); 
		cb[11] = (CheckBox)findViewById(R.id.cb12);
		cb[11].setOnCheckedChangeListener(new CompoundButton.OnCheckedChangeListener(){ 
            @Override 
            public void onCheckedChanged(CompoundButton buttonView, 
                    boolean isChecked) { 
		            	if(isChecked){ flags[11] = true;cb[11].setBackgroundColor(Color.RED);closecheckbox(11);
		                }else{ flags[11] = false;cb[11].setBackgroundColor(Color.TRANSPARENT);opencheckbox();} }  }); 
		cb[12] = (CheckBox)findViewById(R.id.cb13);
		cb[12].setOnCheckedChangeListener(new CompoundButton.OnCheckedChangeListener(){ 
            @Override 
            public void onCheckedChanged(CompoundButton buttonView, 
                    boolean isChecked) { 
		            	if(isChecked){ flags[12] = true;cb[12].setBackgroundColor(Color.RED);closecheckbox(12);
		                }else{ flags[12] = false;cb[12].setBackgroundColor(Color.TRANSPARENT);opencheckbox();} }  }); 
		cb[13] = (CheckBox)findViewById(R.id.cb14);
		cb[13].setOnCheckedChangeListener(new CompoundButton.OnCheckedChangeListener(){ 
            @Override 
            public void onCheckedChanged(CompoundButton buttonView, 
                    boolean isChecked) { 
		            	if(isChecked){ flags[13] = true;cb[13].setBackgroundColor(Color.RED);closecheckbox(13);
		                }else{ flags[13] = false;cb[13].setBackgroundColor(Color.TRANSPARENT);opencheckbox();} }  }); 
		cb[14] = (CheckBox)findViewById(R.id.cb15);
		cb[14].setOnCheckedChangeListener(new CompoundButton.OnCheckedChangeListener(){ 
            @Override 
            public void onCheckedChanged(CompoundButton buttonView, 
                    boolean isChecked) { 
		            	if(isChecked){ flags[14] = true;cb[14].setBackgroundColor(Color.RED);closecheckbox(14);
		                }else{ flags[14] = false;cb[14].setBackgroundColor(Color.TRANSPARENT);opencheckbox();} }  }); 
		cb[15] = (CheckBox)findViewById(R.id.cb16);
		cb[15].setOnCheckedChangeListener(new CompoundButton.OnCheckedChangeListener(){ 
            @Override 
            public void onCheckedChanged(CompoundButton buttonView, 
                    boolean isChecked) { 
		            	if(isChecked){ flags[15] = true;cb[15].setBackgroundColor(Color.RED);closecheckbox(15);
		                }else{ flags[15] = false;cb[15].setBackgroundColor(Color.TRANSPARENT);opencheckbox();} }  }); 
		cb[16] = (CheckBox)findViewById(R.id.cb17);
		cb[16].setOnCheckedChangeListener(new CompoundButton.OnCheckedChangeListener(){ 
            @Override 
            public void onCheckedChanged(CompoundButton buttonView, 
                    boolean isChecked) { 
		            	if(isChecked){ flags[16] = true;cb[16].setBackgroundColor(Color.RED);closecheckbox(16);
		                }else{ flags[16] = false;cb[16].setBackgroundColor(Color.TRANSPARENT);opencheckbox();} }  }); 
		cb[17] = (CheckBox)findViewById(R.id.cb18);
		cb[17].setOnCheckedChangeListener(new CompoundButton.OnCheckedChangeListener(){ 
            @Override 
            public void onCheckedChanged(CompoundButton buttonView, 
                    boolean isChecked) { 
		            	if(isChecked){ flags[17] = true;cb[17].setBackgroundColor(Color.RED);closecheckbox(17);
		                }else{ flags[17] = false;cb[17].setBackgroundColor(Color.TRANSPARENT);opencheckbox();} }  }); 
		cb[18] = (CheckBox)findViewById(R.id.cb19);
		cb[18].setOnCheckedChangeListener(new CompoundButton.OnCheckedChangeListener(){ 
            @Override 
            public void onCheckedChanged(CompoundButton buttonView, 
                    boolean isChecked) { 
		            	if(isChecked){ flags[18] = true;cb[18].setBackgroundColor(Color.RED);closecheckbox(18);
		                }else{ flags[18] = false;cb[18].setBackgroundColor(Color.TRANSPARENT);opencheckbox();} }  }); 
		cb[19] = (CheckBox)findViewById(R.id.cb20);
		cb[19].setOnCheckedChangeListener(new CompoundButton.OnCheckedChangeListener(){ 
            @Override 
            public void onCheckedChanged(CompoundButton buttonView, 
                    boolean isChecked) { 
		            	if(isChecked){ flags[19] = true;cb[19].setBackgroundColor(Color.RED);closecheckbox(19);
		                }else{ flags[19] = false;cb[19].setBackgroundColor(Color.TRANSPARENT);opencheckbox();} }  }); 
		cb[20] = (CheckBox)findViewById(R.id.cb21);
		cb[20].setOnCheckedChangeListener(new CompoundButton.OnCheckedChangeListener(){ 
            @Override 
            public void onCheckedChanged(CompoundButton buttonView, 
                    boolean isChecked) { 
		            	if(isChecked){ flags[20] = true;cb[20].setBackgroundColor(Color.RED);closecheckbox(20);
		                }else{ flags[20] = false;cb[20].setBackgroundColor(Color.TRANSPARENT);opencheckbox();} }  }); 
		cb[21] = (CheckBox)findViewById(R.id.cb22);
		cb[21].setOnCheckedChangeListener(new CompoundButton.OnCheckedChangeListener(){ 
            @Override 
            public void onCheckedChanged(CompoundButton buttonView, 
                    boolean isChecked) { 
		            	if(isChecked){ flags[21] = true;cb[21].setBackgroundColor(Color.RED);closecheckbox(21);
		                }else{ flags[21] = false;cb[21].setBackgroundColor(Color.TRANSPARENT);opencheckbox();} }  }); 
		cb[22] = (CheckBox)findViewById(R.id.cb23);
		cb[22].setOnCheckedChangeListener(new CompoundButton.OnCheckedChangeListener(){ 
            @Override 
            public void onCheckedChanged(CompoundButton buttonView, 
                    boolean isChecked) { 
		            	if(isChecked){ flags[22] = true;cb[22].setBackgroundColor(Color.RED);closecheckbox(22);
		                }else{ flags[22] = false;cb[22].setBackgroundColor(Color.TRANSPARENT);opencheckbox();} }  }); 
		cb[23] = (CheckBox)findViewById(R.id.cb24);
		cb[23].setOnCheckedChangeListener(new CompoundButton.OnCheckedChangeListener(){ 
            @Override 
            public void onCheckedChanged(CompoundButton buttonView, 
                    boolean isChecked) { 
		            	if(isChecked){ flags[23] = true;cb[23].setBackgroundColor(Color.RED);closecheckbox(23);
		                }else{ flags[23] = false;cb[23].setBackgroundColor(Color.TRANSPARENT);opencheckbox();} }  }); 
	}
	
	public void closecheckbox(int i)//根据选择，关闭其他未选择选项
	{
		for (int j=0; j<cb.length;j++)
		{
			if(j == i)
			{
				continue;
			}
			else
			{
				cb[j].setEnabled(false);
			}
		}
	}
	public void opencheckbox()//打开所有选项
	{
		for (int j=0; j<cb.length;j++)
		{
						
			cb[j].setEnabled(true);

		}
	}
}
