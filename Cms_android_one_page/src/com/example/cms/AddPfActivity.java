/*
Ʒ��ͼƬ�����ڴ濨�У�cms�ļ�����
��������Ϊ *q.jpg(ǰ��)��*h.jpg�����棩
*ΪƷ��
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
	private String strqm = cms.fileurl + "cms/"+ cms.pinfan + "q.jpg";//ǰ��ͼƬ
	private String strhm = cms.fileurl + "cms/"+ cms.pinfan + "h.jpg";//����ͼƬ
	private EditText edpf;
	
	
	//private String 
	
	@Override
	protected void onCreate(Bundle savedInstanceState) {//��ʼ���ؼ���ע��ռ��¼�
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
			String url = cms.url+cms.pinfan+"q.jpg";//���ص�ַ
			String file = cms.pinfan+"q.jpg";//�����ļ�·��������
			HttpDownloader downloader = new HttpDownloader();
			int result = downloader.downFile(url,"cms/", file);//�����ļ�
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
	
	public void setView()//���ÿؼ�ͼƬ
	{
		qm = (ImageView)findViewById(R.id.imageViewqm);
		Bitmap bitmap = cms.getLoacalBitmap(strqm);
		qm.setImageBitmap(bitmap);
		hm = (ImageView)findViewById(R.id.imageViewhm);
		Bitmap bitmap2 = cms.getLoacalBitmap(strhm);	
		hm.setImageBitmap(bitmap2);
	}
	
	@Override
	 protected Dialog onCreateDialog(int id)//����ʧ����ʾ�Ի���
	{
		 	Dialog dialog=null;
	        android.app.AlertDialog.Builder builder=new android.app.AlertDialog.Builder(this);
	        
            builder.setTitle("��ʾ��");
            builder.setMessage("����ʧ�ܣ����������û�д�Ʒ����");
            builder.setPositiveButton("ȷ��",null);
            dialog = builder.create();
	       
	        dialog = builder.create();
			return dialog;
	}
}
