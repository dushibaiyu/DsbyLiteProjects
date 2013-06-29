
#pragma once

#include <string>
#include "iconv.h"

#pragma comment (lib , "iconv.lib")

using namespace std;

class CodeConverter 
{
private:
	iconv_t cd;
public:
// 构造
	CodeConverter(const char * from_charset,const char * to_charset)
	{
		cd = iconv_open(to_charset,from_charset);//初始化，接受从from转到to
	}
// 析构
	~CodeConverter()
	{
		iconv_close(cd);//释放
	}

	string StartConvert(string str)
	{
		int si = 255;
		const char * p = str.c_str();
		size_t i = str.length();
		char tp[255]={0};
		convert(p,i,tp,si);
		string code = tp;
		return code;
	}

// 转换输出
protected:
	void convert(const char *inbuf,int inlen,char *outbuf,int outlen) 
	{
	const char **pin = &inbuf;
	char **pout = &outbuf;

	memset(outbuf,0,outlen);//初始化要存数据的内存
	iconv(cd,pin,(size_t *)&inlen,pout,(size_t *)&outlen);//调用库转码
	return;
	}
};
