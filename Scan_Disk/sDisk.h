#ifndef SDISK_H_INCLUDED
#define SDISK_H_INCLUDED
#include <io.h>
//#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

bool Judge (char * judge) //过滤格式，不是十分严格
{
    if (NULL != strstr(judge,".psd"))
    {
        return true;
    }
    else if (NULL != strstr(judge,".cdr"))
    {
        return true;
    }
    else if (NULL != strstr(judge,".tpf"))
    {
        return true;
    }
     if (NULL != strstr(judge,".PSD"))
    {
        return true;
    }
    else if (NULL != strstr(judge,".CDR"))
    {
        return true;
    }
    else if (NULL != strstr(judge,".TPF"))
    {
        return true;
    }
   /* else if (NULL != strstr(judge,".doc"))
    {
        return true;
    }*/
    else
    {
        return false;
    }
}
//扫描程序
void ListDir(string pchData,string & myFile)
{
    //先判断，特殊的文件夹不扫描
    if (0 == pchData.compare("C:\\\\Windows"))
    {
        return ;
    }
    if (0 == pchData.compare("C:\\\\WINDOWS"))
    {
        return ;
    }
    if (0 == pchData.compare("C:\\\\Boot"))
    {
        return ;
    }
    if (string::npos != pchData.find("$Recycle.Bin"))
    {
        return ;
    }
    if (string::npos != pchData.find("\\AppData\\"))
    {
        return ;
    }
    if (string::npos != pchData.find("System Volume Information"))
    {
        return ;
    }
//这两个是程序安装目录，一般应该没人存东西，默认跳过了，如果扫描就自己注视掉就行
    if (0 == pchData.compare("C:\\\\Program Files"))
    {
        return ;
    }
    if (0 == pchData.compare("C:\\\\Program Files (x86)"))
    {
        return ;
    }

    _finddata_t   fdata;
    //定义文件查找结构对象
    long   done;
    string tempdir = pchData;//存储需要扫描的路径

    tempdir += "\\*.*";        //只查找*。*格式的
    done   =  _findfirst(tempdir.c_str(), &fdata);
//开始查找文件
    if (done != -1)
//是否查找成功
    {
        int ret = 0;
        while  (ret != -1)
//定义一个循环
        {
            if (fdata.attrib != _A_SUBDIR)
//判断文件属性
            {
                if (strcmp(fdata.name,"...")  != 0 &&  strcmp(fdata.name,"..") != 0 &&  strcmp(fdata.name,".") != 0)            //过滤
                {
                   if (Judge(fdata.name))//判断文件
                    {
                    string pdir = pchData;
                    pdir =pdir + "\\" +fdata.name;//连接字符串
                    //cout << pdir << endl;
                    //cout << fdata.name << endl;
                    string myCopy = myFile;
                    myCopy += fdata.name;

                    CopyFileA(pdir.c_str(),myCopy.c_str(),TRUE);//复制文件
                   }

                }
            }
            ret = _findnext(done, &fdata);
            //查找下一个文件
            if (ret  != -1)      //判断文件属性，如果是目录，则递归调用
            {
                if (fdata.attrib == _A_SUBDIR || fdata.attrib == _A_SUBDIR|_A_RDONLY)
                {
                    if (strcmp(fdata.name,"...")  != 0 &&  strcmp(fdata.name,"..") != 0 &&  strcmp(fdata.name,".") != 0)            //过滤
                    {
                        string pdir = pchData;
                         pdir =pdir +"\\" +fdata.name;//连接字符串
                        //cout << pdir <<endl;
                         ListDir(pdir,myFile);
            //递归调用
                    }
                }
            }
        }
    }
}

#endif // SDISK_H_INCLUDED
