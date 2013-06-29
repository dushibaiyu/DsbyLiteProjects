/*
为上传准备数据，准备成上传需要的格式
而且也解析从服务器下载来的json数据
部分元数据需要直接从数据库读取
*/



#pragma once

#include "gamebox_db.h"
#include "jansson.h"
#include <cstring>

#pragma comment (lib , "jansson.lib")

using std::string;
using std::vector;

struct user_login_data//用户登录信息
{
	string username; //用户名
	string icon;  //头像
	string level; //等级
	string exp_current; //本等级当前经验
	string exp_total; //本等级所有经验
};

class http_data
{
public:
	string UserPostData(char * username, char * password);//准备用户登录
	string UserPostData(gamebox_config * user);//自动登录，从数据库的值
	string GamePostData(vector<game_info> * g_info);//准备上传游戏数据
	string GamePostData(int id);
	bool GetState(string json = "");//登录状态
	string GetSession(string json  = "");//得到session
	user_login_data GetUserData(string json  = "");//得到用户信息
	string GetVersion(string json = "");//返回新版本号
	string GetNewVersionUrl(string json = "");//返回新版本地址
	void ResolveJson(string json);//解析json

protected:
	void InitializeString()//清空数据，防止上次解析遗留信息错误
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
	string session;//会话cookies
	string state;//登录状态，失败或者成功
	user_login_data user_data;//得到的用户信息
	string version;//版本号
	string ver_url;//
};