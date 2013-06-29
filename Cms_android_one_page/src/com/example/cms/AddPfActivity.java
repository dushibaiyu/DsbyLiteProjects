/*
品番图片存在内存卡中：cms文件夹下
命名规则为 *q.jpg(前面)，*h.jpg（后面）
*为品番
*/

package com.example.cms;

import android.os.Bundle;
import android.app.Activity;
import android.app.Dialog;
import android.graphics.*;
import android.view.Menu;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.ImageView;

public class AddPfActivity extends Activity {

	private Button back;
	private Button down;
	private ImageView qm;
	private ImageView hm;
	private String strqm = cms.fileurl + "cms/"+ cms.pinfan + "q.jpg";//前面图片
	private String strhm = cms.fileurl + "cms/"+ cms.pinfan + "h.jpg";//背面图片
	private EditText edpf;
	
	
	//private String 
	
	@Override
	protected void onCreate(Bundle savedInstanceState) {//初始化控件和注册空间事件
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_add_pf);
		edpf = (EditText)findViewById(R.id.editT_pf);
		setView();
		edpf.setText(cms.pinfan);
		back = (Button)findViewById(R.id.but_pf_bac);
		back.setOnClickListener(new Button.OnClickListener(){	
		public void onClick(View v){finish();}});
		
		down = (Button)findViewById(R.id.but_pf_add);
		down.setOnClickListener(new Button.OnClickListener(){	
		@SuppressWarnings("deprecation")
		public void onClick(View v){
			String url = cms.url+cms.pinfan+"q.jpg";//下载地址
			String file = cms.pinfan+"q.jpg";//保存文件路径和名字
			HttpDownloader downloader = new HttpDownloader();
			int result = downloader.downFile(url,"cms/", file);//下载文件
			url = cms.url+cms.pinfan+"h.jpg";
			file = cms.pinfan+"h.jpg";
			int result2 = downloader.downFile(url,"cms/", file);
			//int i = downloader.downFile("ftp://cms@192.168.1.104/123.jpg","cms/", "123.jpg");
			if(result == -1 || result2 == -1)
			{
				showDialog(1);
			}
			setView();
			
			}});
	}

	@Override
	public boolean onCreateOptionsMenu(Menu menu) {
		// Inflate the menu; this adds items to the action bar if it is present.
		getMenuInflater().inflate(R.menu.add_pf, menu);
		return true;
	}
	
	public void setView()//设置控件图片
	{
		qm = (ImageView)findViewById(R.id.imageViewqm);
		Bitmap bitmap = cms.getLoacalBitmap(strqm);
		qm.setImageBitmap(bitmap);
		hm = (ImageView)findViewById(R.id.imageViewhm);
		Bitmap bitmap2 = cms.getLoacalBitmap(strhm);	
		hm.setImageBitmap(bitmap2);
	}
	
	@Override
	 protected Dialog onCreateDialog(int id)//下载失败提示对话框
	{
		 	Dialog dialog=null;
	        android.app.AlertDialog.Builder builder=new android.app.AlertDialog.Builder(this);
	        
            builder.setTitle("提示：");
            builder.setMessage("下载失败！请检查网络或没有此品番。");
            builder.setPositiveButton("确认",null);
            dialog = builder.create();
	       
	        dialog = builder.create();
			return dialog;
	}
}
