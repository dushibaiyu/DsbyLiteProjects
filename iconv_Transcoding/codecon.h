
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
// ����
	CodeConverter(const char * from_charset,const char * to_charset)
	{
		cd = iconv_open(to_charset,from_charset);//��ʼ�������ܴ�fromת��to
	}
// ����
	~CodeConverter()
	{
		iconv_close(cd);//�ͷ�
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

// ת�����
protected:
	void convert(const char *inbuf,int inlen,char *outbuf,int outlen) 
	{
	const char **pin = &inbuf;
	char **pout = &outbuf;

	memset(outbuf,0,outlen);//��ʼ��Ҫ�����ݵ��ڴ�
	iconv(cd,pin,(size_t *)&inlen,pout,(size_t *)&outlen);//���ÿ�ת��
	return;
	}
};
