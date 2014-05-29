
#include "http.h"

using std::string;

string  http::Get (string url, string cookie,string referer)
{
	m_ch.clear();
	CURL *curl = curl_easy_init();//初始化句柄

	curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_HEADER,0);
    curl_easy_setopt(curl, CURLOPT_USERAGENT, "gamebox.exe,win nt");//user 信息
	curl_easy_setopt(curl, CURLOPT_REFERER, referer.c_str());
	curl_easy_setopt(curl, CURLOPT_COOKIE, cookie.c_str());
	curl_easy_setopt(curl, CURLOPT_WRITEDATA, &m_ch);
	curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, HttpCallBack);

	
	curl_easy_perform(curl); 

	curl_easy_cleanup(curl);
	curl_global_cleanup();
	
	return m_ch;
}
void  http::Get (string url, string site, string cookie,string referer)
{
	FILE *fp = fopen(site.c_str(), "wb");	// 打开文件，以二进制写的方式
	CURL *curl = curl_easy_init();//初始化句柄

	curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_HEADER,0);
    curl_easy_setopt(curl, CURLOPT_USERAGENT, "gamebox.exe,win nt");//user 信息
	curl_easy_setopt(curl, CURLOPT_REFERER, referer.c_str());
	curl_easy_setopt(curl, CURLOPT_COOKIE, cookie.c_str());
	curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
	curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, UpdataCallBack);

	
	curl_easy_perform(curl); 

	
	curl_easy_cleanup(curl);

	fclose(fp);
	curl_global_cleanup();
	
	return;
}

  
string  http::Post (string url, string data, string cookie,string referer )
{
	m_ch.clear();
	CURL *curl = curl_easy_init();//初始化句柄

	curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
	curl_easy_setopt(curl, CURLOPT_POST, 1);
    curl_easy_setopt(curl, CURLOPT_HEADER,0);
    curl_easy_setopt(curl, CURLOPT_USERAGENT, "gamebox.exe,win nt");//user 信息
	curl_easy_setopt(curl, CURLOPT_REFERER, referer.c_str());
	curl_easy_setopt(curl, CURLOPT_COOKIE, cookie.c_str());
	curl_easy_setopt(curl, CURLOPT_POSTFIELDS,data.c_str()); 
	curl_easy_setopt(curl, CURLOPT_WRITEDATA, &m_ch);
	curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, HttpCallBack);

	
	curl_easy_perform(curl); 

	curl_easy_cleanup(curl);

	curl_global_cleanup();

	return m_ch;
}
void  http::Post (string url, string data,string site, string cookie,string referer)
{
	FILE *fp = fopen(site.c_str(), "wb");	// 打开文件，以二进制写的方式
	CURL *curl = curl_easy_init();//初始化句柄

	curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
	curl_easy_setopt(curl, CURLOPT_POST, 1);
    curl_easy_setopt(curl, CURLOPT_HEADER,0);
    curl_easy_setopt(curl, CURLOPT_USERAGENT, "gamebox.exe,win nt");//user 信息
	curl_easy_setopt(curl, CURLOPT_REFERER, referer.c_str());
	curl_easy_setopt(curl, CURLOPT_COOKIE, cookie.c_str());
	curl_easy_setopt(curl, CURLOPT_POSTFIELDS,data.c_str()); 
	curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
	curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, UpdataCallBack);

	
	curl_easy_perform(curl); 

	curl_easy_cleanup(curl);
	fclose(fp);
	curl_global_cleanup();
	return ;
}



size_t HttpCallBack(void *buffer, size_t size, size_t nmemb, void *user_p)
{
	char * p= (char *)buffer;
	
	string * ch = (string *)user_p;
	//&ch += p
	if (ch->empty())
	{
		ch->assign(p);
	}
	else 
	{
		ch->append(p);
	}
	

	return size*nmemb;
}

size_t UpdataCallBack(void *buffer, size_t size, size_t nmemb, void *user_p)
{
	FILE *fp = (FILE *)user_p;
	size_t return_size = fwrite(buffer, size, nmemb, fp);//写入文件
	
	return return_size;
}