/*
定义数据库操作接口
防止同事多个操作，类只能实例化一个对象，用gamebox_db：：GetDbDate()得到实例化后的地址
gamebox_config储存各个设置项，从数据库中读取出来，保存到这个结构体中

游戏信息，把游戏信息封装到一个结构体便于操作

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

struct gamebox_config //设置项
{
//常规设置
	int pc_start; //开机启动
	int full_screen;//全屏
	int exit_mode;//点关闭键的模式
	int agree_share;//用户分享计划
	std::string boos_key;//老板键
//下载设置
	int num_down_session;//同时下载个数
	int down_mode;//下载模式
	int down_speed_down;//下载速度限制
	int down_speed_up;//上传速度限制
	std::string save_dir;//下载保存目录
	int auto_down;//自动开始未完成下载
//安装设置
	std::string install_dir;//安装目录
	int auto_install_dir;//自动安装到下载目录
	int auto_install;//下载完自动安装
	int auto_login;//是否自动登录
	std::string username;//用户
	std::string password;
	std::string version;
};

struct game_info//游戏信息
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
	static gamebox_db * GetDbDate();//调用得到数据库操作的指针
	~gamebox_db();
	//设置属性
	gamebox_config  * GetConfig(); //得到数据库中的设置属性
	bool UpConfig(gamebox_config  * = NULL);//更新数据库中的设置
	bool UpUser (bool tf,string username = "",string password = "");//true记住密码，更新数据库用户操作
	bool DefConfig();//还原为默认值
	bool UpVersion(string version);//更新版本
	//游戏列表操作
	bool AddGame (game_info &game);//添加一款游戏数据
	bool UpLRU(string stuff_program, bool game_sate);//stuff_histroy操作，状态ture stuff_history+1，false stuff_history=0
	vector<game_info> * GetLRU ();//最近使用排序,stuff_history=0的忽略，从大到小排列
	vector<game_info> * GetGameList(int  category = -1);//游戏分类检索
	bool DelGame(string stuff_program);//删除一款游戏
	unsigned long int GetId(string stuff_program);//根据名字查找id


	
protected:
	gamebox_db();

	friend int ConfigCallbak( void * para, int n_column, char ** column_value, char ** column_name );
	friend int stuffCallbak( void * para, int n_column, char ** column_value, char ** column_name );
	friend int IdCallbak( void * para, int n_column, char ** column_value, char ** column_name );
};

