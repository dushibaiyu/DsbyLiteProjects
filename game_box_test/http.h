/*
post，get数据
需要的数据一般都在http_data中返回

返回数据存到string、或者文件，json串要存到string，到http_data解析

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
	string  Get (string url, string cookie = "",string referer = "");//get请求，存字符串，返回存的字符串
	void  Get (string url, string site, string cookie,string referer );//存文件，site文件详细地址
	string  Post (string url, string data, string cookie = "",string referer = "");//post请求，存字符串，返回存的字符串
	void  Post (string url, string data,string site, string cookie ,string referer );//存文件，site文件详细地址

	
private:
	string  m_ch;
	
};

size_t HttpCallBack(void *buffer, size_t size, size_t nmemb, void *user_p);
size_t UpdataCallBack(void *buffer, size_t size, size_t nmemb, void *user_p);
//buffer,返回数据的指针
//
//size,返回数据每块的大小
//
//nmemb,返回数据的块数（这里返回数据串的真正大小为size*nmemb）
//
//user_p，是curl_easy_setopt(curl, CURLOPT_WRITEDATA/CURLOPT_READDATA, &buffer); 中的buffer的指针。

/*
get和post请求得到的数据用重载一个存在字符串，一个存在文件，字符串的存json，便于解析
*/