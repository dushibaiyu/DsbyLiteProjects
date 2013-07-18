/*
�������ݿ�����ӿ�
��ֹͬ�¶����������ֻ��ʵ����һ��������gamebox_db����GetDbDate()�õ�ʵ������ĵ�ַ
gamebox_config�����������������ݿ��ж�ȡ���������浽����ṹ����

��Ϸ��Ϣ������Ϸ��Ϣ��װ��һ���ṹ����ڲ���

*/

#pragma once

#include <string>
#include <vector>
#include <iostream>
#include <cstdlib>
#include "sqlite3.h"
#include "codecon.h"

#pragma comment (lib , "sqlite3.lib")

using namespace std;

struct gamebox_config //������
{
//��������
	int pc_start; //��������
	int full_screen;//ȫ��
	int exit_mode;//��رռ���ģʽ
	int agree_share;//�û�����ƻ�
	std::string boos_key;//�ϰ��
//��������
	int num_down_session;//ͬʱ���ظ���
	int down_mode;//����ģʽ
	int down_speed_down;//�����ٶ�����
	int down_speed_up;//�ϴ��ٶ�����
	std::string save_dir;//���ر���Ŀ¼
	int auto_down;//�Զ���ʼδ�������
//��װ����
	std::string install_dir;//��װĿ¼
	int auto_install_dir;//�Զ���װ������Ŀ¼
	int auto_install;//�������Զ���װ
	int auto_login;//�Ƿ��Զ���¼
	std::string username;//�û�
	std::string password;
	std::string version;
};

struct game_info//��Ϸ��Ϣ
{
	unsigned long int stuff_id;
	string stuff_name;
	int  stuff_category ;//stuff_type ;
	int stuff_exec; //stuff_group 
	string stuff_program;
	string stuff_ico;
	unsigned long int stuff_history;
};


class gamebox_db
{
private:
	sqlite3 * db;
	gamebox_config  * gb_config ;
	vector<game_info>  g_info;
	static gamebox_db * game_db;
public:
	static gamebox_db * GetDbDate();//���õõ����ݿ������ָ��
	~gamebox_db();
	//��������
	gamebox_config  * GetConfig(); //�õ����ݿ��е���������
	bool UpConfig(gamebox_config  * = NULL);//�������ݿ��е�����
	bool UpUser (bool tf,string username = "",string password = "");//true��ס���룬�������ݿ��û�����
	bool DefConfig();//��ԭΪĬ��ֵ
	bool UpVersion(string version);//���°汾
	//��Ϸ�б����
	bool AddGame (game_info &game);//���һ����Ϸ����
	bool UpLRU(string stuff_program, bool game_sate);//stuff_histroy������״̬ture stuff_history+1��false stuff_history=0
	vector<game_info> * GetLRU ();//���ʹ������,stuff_history=0�ĺ��ԣ��Ӵ�С����
	vector<game_info> * GetGameList(int  category = -1);//��Ϸ�������
	bool DelGame(string stuff_program);//ɾ��һ����Ϸ
	unsigned long int GetId(string stuff_program);//�������ֲ���id


	
protected:
	gamebox_db();

	friend int ConfigCallbak( void * para, int n_column, char ** column_value, char ** column_name );
	friend int stuffCallbak( void * para, int n_column, char ** column_value, char ** column_name );
	friend int IdCallbak( void * para, int n_column, char ** column_value, char ** column_name );
};

