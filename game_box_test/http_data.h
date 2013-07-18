/*
Ϊ�ϴ�׼�����ݣ�׼�����ϴ���Ҫ�ĸ�ʽ
����Ҳ�����ӷ�������������json����
����Ԫ������Ҫֱ�Ӵ����ݿ��ȡ
*/



#pragma once

#include "gamebox_db.h"
#include "jansson.h"
#include <cstring>

#pragma comment (lib , "jansson.lib")

using std::string;
using std::vector;

struct user_login_data//�û���¼��Ϣ
{
	string username; //�û���
	string icon;  //ͷ��
	string level; //�ȼ�
	string exp_current; //���ȼ���ǰ����
	string exp_total; //���ȼ����о���
};

class http_data
{
public:
	string UserPostData(char * username, char * password);//׼���û���¼
	string UserPostData(gamebox_config * user);//�Զ���¼�������ݿ��ֵ
	string GamePostData(vector<game_info> * g_info);//׼���ϴ���Ϸ����
	string GamePostData(int id);
	bool GetState(string json = "");//��¼״̬
	string GetSession(string json  = "");//�õ�session
	user_login_data GetUserData(string json  = "");//�õ��û���Ϣ
	string GetVersion(string json = "");//�����°汾��
	string GetNewVersionUrl(string json = "");//�����°汾��ַ
	void ResolveJson(string json);//����json

protected:
	void InitializeString()//������ݣ���ֹ�ϴν���������Ϣ����
	{
		session.clear();
		state.clear();
		user_data.username.clear();
		user_data.icon.clear();
		user_data.level.clear();
		user_data.exp_total.clear();
		user_data.exp_current.clear();
	}

private:
	string session;//�Ựcookies
	string state;//��¼״̬��ʧ�ܻ��߳ɹ�
	user_login_data user_data;//�õ����û���Ϣ
	string version;//�汾��
	string ver_url;//
};