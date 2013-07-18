package com.example.cms;

import java.util.UUID;

import android.os.Bundle;
import android.app.Activity;
import android.content.Intent;
import android.database.sqlite.SQLiteDatabase;
import android.graphics.Bitmap;
//import android.content.res.Resources;
//import android.graphics.drawable.Drawable;
import android.view.Menu;
import android.view.MotionEvent;
import android.view.View;
import android.view.View.*;
import android.widget.*;

public class AddBActivity extends Activity {

	private RadioButton radqb;
	private RadioButton radql;
	private RadioButton radhb;
	private RadioButton radhl;
	private RadioGroup radgroup;
	private ImageView imgview;
	private Button but_bac;
	private Button but_bl;
	private String strqm = cms.fileurl + "cms/" + cms.pinfan + "q.jpg";
	private String strhm = cms.fileurl + "cms/" + cms.pinfan + "h.jpg";
	Bitmap bitmapzm;
	Bitmap bitmapbm;
	private mysqllite sqlHelper;
//	private Drawable db;
	   
	
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_add_b);
		radCreate();
		vbCreate();
		
		sqlHelper = new mysqllite(this,"cms.db",null,1);
		bitmapzm = cms.getLoacalBitmap(strqm);//���ڴ濨��ȡͼƬ
		bitmapbm = cms.getLoacalBitmap(strhm);	
		//ע��ͳ�ʼ����ť
		but_bl = (Button)findViewById(R.id.button23);
		but_bl.setOnClickListener(new Button.OnClickListener(){	public void onClick(View v){chilkB();}});
		but_bac = (Button)findViewById(R.id.button13);
		but_bac.setOnClickListener(new Button.OnClickListener(){	public void onClick(View v){chilkA();}});
		imgview.setImageBitmap(bitmapzm);
	}

	@Override
	public boolean onCreateOptionsMenu(Menu menu) {
		// Inflate the menu; this adds items to the action bar if it is present.
		getMenuInflater().inflate(R.menu.add_b, menu);
		return true;
	}
	
	public void radCreate()//ע�������radio���¼�������
	{
		radgroup = (RadioGroup)findViewById(R.id.radioGroup1);
		radqb = (RadioButton)findViewById(R.id.rqb);
		radql = (RadioButton)findViewById(R.id.rql);
		radhb = (RadioButton)findViewById(R.id.rhb);
		radhl = (RadioButton)findViewById(R.id.rhl);
		
		
		radgroup.setOnCheckedChangeListener(new RadioGroup.OnCheckedChangeListener() {  
            
            @Override  
            public void onCheckedChanged(RadioGroup group, int checkedId) {  
                // TODO Auto-generated method stub  
                if(checkedId==radqb.getId())  
                {  
                    cms.radio = 1; 
                   // Resources resources = getContext().getResources();
                    //db = this.getResources().getDrawable(R.drawable.zm);
                    //imgview.setBackground(db);
                    imgview.setImageBitmap(bitmapzm);//����ͼƬ
                }else if (checkedId==radql.getId()) 
                {  
                    cms.radio = 2;  
                    imgview.setImageBitmap(bitmapzm);
                }else if (checkedId==radhb.getId())
                {
                	cms.radio = 3;
                	imgview.setImageBitmap(bitmapbm);
                }else if (checkedId==radhl.getId())
                {
                	cms.radio = 4;
                	imgview.setImageBitmap(bitmapbm);
                }
            }  
        });  
    }  

	public void vbCreate()//����ͼƬ�ؼ����Լ��䷴Ӧ�¼�
	{
		imgview = (ImageView)findViewById(R.id.imageV);
		but_bac = (Button)findViewById(R.id.button_back);
		but_bac.setOnClickListener(new Button.OnClickListener(){	public void onClick(View v){finish();}});
		
		imgview.setOnClickListener(new View.OnClickListener() {//ע����ͼƬ��ʱ��
			
			@Override
			public void onClick(View v) {
				// TODO Auto-generated method stub
				chilk();
			}
		});
		imgview.setOnTouchListener(new OnTouchListener()  //���ܵ��ͼƬ������
        {  
			@Override
			public boolean onTouch(View arg0, MotionEvent arg1) {
				// 
				String str = "  " +  arg1.getX() + "  "+ arg1.getY(); 
				imgxy((int)arg1.getX(),(int)arg1.getY());
				System.out.println(str);
				return false;
			}            
        });
	}
	
	public void imgxy(int x,int y)//��������
	{
		int xl = imgview.getLeft();
		int xr = imgview.getRight();
		int yt = imgview.getTop();
		int yb = imgview.getBottom();
		int xc = (xr-xl)/10;
		int yc = (yb-yt)/10;

		cms.xy = "x=" + (x-xl)/xc + " ;y=" + (y-yt)/yc;
		System.out.println(cms.xy);
	}
	
	public void chilk()//��ѡ����ҳ��
	{
		Intent intent = new Intent();
    	intent.setClass(this, Add2Activity.class);
    	startActivity(intent);
	}
	
	public void chilkA()//���AƷ�������ݿ�д��AƷ
	{
		UUID uuid = UUID.randomUUID();
		//SQLiteDatabase Sql = sqlHelper.getWritableDatabase(); 
		SQLiteDatabase Sql =SQLiteDatabase.openOrCreateDatabase(sdcarddb.f, null);
		String sql = "insert into jianpin (id,date,factory,num,Ap) values ( '";
		sql =sql +  uuid.toString()+"','" + cms.date + "','" + cms.gongchang + "','" + cms.pinfan;
		sql = sql + "'," + "1)";
		Sql.execSQL(sql);
    	Sql.close();
	}

	public void chilkB()//���BƷ��д��BƷ
	{
		UUID uuid = UUID.randomUUID();
		//SQLiteDatabase Sql = sqlHelper.getWritableDatabase(); 
		SQLiteDatabase Sql =SQLiteDatabase.openOrCreateDatabase(sdcarddb.f, null);
		String sql = "insert into jianpin (id,date,factory,num,Bp) values ( '";
		sql =sql +  uuid.toString()+"','" + cms.date + "','" + cms.gongchang + "','" + cms.pinfan;
		sql = sql + "'," + "1)";
		Sql.execSQL(sql);
    	Sql.close();
	}
}
