/*
post��get����
��Ҫ������һ�㶼��http_data�з���

�������ݴ浽string�������ļ���json��Ҫ�浽string����http_data����

*/
#pragma once

#include "curl\curl.h"
#include <string>
#include <iostream>

#pragma comment (lib, "libcurl.lib")

using std::string;

class http
{
public:
	string  Get (string url, string cookie = "",string referer = "");//get���󣬴��ַ��������ش���ַ���
	void  Get (string url, string site, string cookie,string referer );//���ļ���site�ļ���ϸ��ַ
	string  Post (string url, string data, string cookie = "",string referer = "");//post���󣬴��ַ��������ش���ַ���
	void  Post (string url, string data,string site, string cookie ,string referer );//���ļ���site�ļ���ϸ��ַ

	
private:
	string  m_ch;
	
};

size_t HttpCallBack(void *buffer, size_t size, size_t nmemb, void *user_p);
size_t UpdataCallBack(void *buffer, size_t size, size_t nmemb, void *user_p);
//buffer,�������ݵ�ָ��
//
//size,��������ÿ��Ĵ�С
//
//nmemb,�������ݵĿ��������ﷵ�����ݴ���������СΪsize*nmemb��
//
//user_p����curl_easy_setopt(curl, CURLOPT_WRITEDATA/CURLOPT_READDATA, &buffer); �е�buffer��ָ�롣

/*
get��post����õ�������������һ�������ַ�����һ�������ļ����ַ����Ĵ�json�����ڽ���
*/