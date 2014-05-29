package com.example.cms;

import java.util.ArrayList;

import android.app.ActivityGroup;
import android.content.Intent;
import android.os.Bundle;
import android.support.v4.view.PagerAdapter;
import android.support.v4.view.ViewPager;
import android.view.View;
import android.view.Window;

@SuppressWarnings("deprecation")
public class AddActivity extends ActivityGroup {
	private View oneView;
	private View twoView;
	private View threeView;
	private View fourView;
	private ArrayList<View> views;
	private ViewPager mViewPager;//��ҳ�滬���л�Ч��
	
	/** Called when the activity is first created. */
	@Override
	public void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		requestWindowFeature(Window.FEATURE_NO_TITLE);
		setContentView(R.layout.activity_add);
		views = new ArrayList<View>();
		mViewPager = (ViewPager)findViewById(R.id.main_viewpager);        
	    mViewPager.setOnPageChangeListener(null);
		initView();
		addViews();
		
		PagerAdapter mPagerAdapter = new PagerAdapter() {
			
			@Override
			public boolean isViewFromObject(View arg0, Object arg1) {
				return arg0 == arg1;
			}
			
			@Override
			public int getCount() {
				return views.size();
			}
			
			@Override
			public void destroyItem(View container, int position, Object object) {
				((ViewPager)container).removeView(views.get(position));
			}
			
			@Override
			public Object instantiateItem(View container, int position) {
				((ViewPager)container).addView(views.get(position));
				return views.get(position);
			}
		};
		
		mViewPager.setAdapter(mPagerAdapter);
	}

	/**
	 * ����Ӧ��Activityת����View����
	 */
	public void initView(){
		oneView=getViews(OneActivity.class,"one");
		twoView=getViews(TwoActivity.class,"one");
		threeView=getViews(ThreeActivity.class,"one");
		fourView = getViews(FourActivity.class,"one");
	}

	/**
	 * ��ת����View���Activity��ӵ��б���
	 */
	public void addViews(){
		
		views.add(oneView);
		views.add(twoView);
		views.add(threeView);
		views.add(fourView);
	}
	/**
	 * ��ȡҪ��ת��Activity��Ӧ��View
	 * @param clsĿ��Activity
	 * @param pageidĿ��Activity��Ψһid
	 * @return ����һ��View���͵ı���
	 */
	public View getViews(Class<?> cls,String pageid){
		return getLocalActivityManager().startActivity(pageid, new Intent(AddActivity.this,cls).addFlags(Intent.FLAG_ACTIVITY_BROUGHT_TO_FRONT)).getDecorView();
	}
}
