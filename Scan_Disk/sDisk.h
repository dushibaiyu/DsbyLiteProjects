#ifndef SDISK_H_INCLUDED
#define SDISK_H_INCLUDED
#include <io.h>
//#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

bool Judge (char * judge) //���˸�ʽ������ʮ���ϸ�
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
//ɨ�����
void ListDir(string pchData,string & myFile)
{
    //���жϣ�������ļ��в�ɨ��
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
//�������ǳ���װĿ¼��һ��Ӧ��û�˴涫����Ĭ�������ˣ����ɨ����Լ�ע�ӵ�����
    if (0 == pchData.compare("C:\\\\Program Files"))
    {
        return ;
    }
    if (0 == pchData.compare("C:\\\\Program Files (x86)"))
    {
        return ;
    }

    _finddata_t   fdata;
    //�����ļ����ҽṹ����
    long   done;
    string tempdir = pchData;//�洢��Ҫɨ���·��

    tempdir += "\\*.*";        //ֻ����*��*��ʽ��
    done   =  _findfirst(tempdir.c_str(), &fdata);
//��ʼ�����ļ�
    if (done != -1)
//�Ƿ���ҳɹ�
    {
        int ret = 0;
        while  (ret != -1)
//����һ��ѭ��
        {
            if (fdata.attrib != _A_SUBDIR)
//�ж��ļ�����
            {
                if (strcmp(fdata.name,"...")  != 0 &&  strcmp(fdata.name,"..") != 0 &&  strcmp(fdata.name,".") != 0)            //����
                {
                   if (Judge(fdata.name))//�ж��ļ�
                    {
                    string pdir = pchData;
                    pdir =pdir + "\\" +fdata.name;//�����ַ���
                    //cout << pdir << endl;
                    //cout << fdata.name << endl;
                    string myCopy = myFile;
                    myCopy += fdata.name;

                    CopyFileA(pdir.c_str(),myCopy.c_str(),TRUE);//�����ļ�
                   }

                }
            }
            ret = _findnext(done, &fdata);
            //������һ���ļ�
            if (ret  != -1)      //�ж��ļ����ԣ������Ŀ¼����ݹ����
            {
                if (fdata.attrib == _A_SUBDIR || fdata.attrib == _A_SUBDIR|_A_RDONLY)
                {
                    if (strcmp(fdata.name,"...")  != 0 &&  strcmp(fdata.name,"..") != 0 &&  strcmp(fdata.name,".") != 0)            //����
                    {
                        string pdir = pchData;
                         pdir =pdir +"\\" +fdata.name;//�����ַ���
                        //cout << pdir <<endl;
                         ListDir(pdir,myFile);
            //�ݹ����
                    }
                }
            }
        }
    }
}

#endif // SDISK_H_INCLUDED
