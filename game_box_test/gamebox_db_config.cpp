#include "gamebox_db.h"

gamebox_db * gamebox_db::game_db = NULL;
gamebox_db * gamebox_db::GetDbDate()
{
	if (NULL == game_db)
	{
		game_db = new gamebox_db;
	}
	return game_db;
}


gamebox_db::gamebox_db()
{
	gb_config = new gamebox_config;
	//g_info = new std::vector<game_info>;
	int i = sqlite3_open("game_box.db",&db);
	if (i != SQLITE_OK)
	{
	/*	std::cout << "dakaishibai" <<std::endl;
		system ("pause");*/
	}
}

gamebox_db::~gamebox_db()
{
	sqlite3_close(db);
	delete gb_config;
	gb_config = NULL;
	//g_info->clear();
	//delete g_info;
	//g_info = NULL;

	delete game_db;
	game_db = NULL;
}


gamebox_config  * gamebox_db::GetConfig()
{
	char * errmsg = NULL;
	int i = sqlite3_exec(db, "select * from config", ConfigCallbak, gb_config,  &errmsg );
	/*if (i != SQLITE_OK)
	{
		std::cout << errmsg <<std::endl;
		system ("pause");
	}*/

	if (1 == gb_config->auto_install_dir)
	{
		gb_config->install_dir = gb_config->save_dir;
	}


	return gb_config;
}


bool gamebox_db::DefConfig()
{
	gb_config->pc_start = 1; 
	gb_config->full_screen = 1;
	gb_config->exit_mode = 1;
	gb_config->agree_share = 1;
	gb_config->boos_key = "Ctrl+Q";
	gb_config->num_down_session = 1;
	gb_config->down_mode = 1;
	gb_config->down_speed_down = 1024;
	gb_config->down_speed_up = 1024;
	gb_config->save_dir = gb_config->install_dir = "D:\\GameBox\\";
	gb_config->auto_down = 1;
	gb_config->auto_install_dir = 1;
	gb_config->auto_install = 1;
	
	return UpConfig();
}



bool gamebox_db::UpUser (bool tf,std::string username, std::string password)
{
	char * errmsg = NULL;
	if (tf)
	{
		std::string sql = "update config set config_value = '";
		std::string tmp = sql;
		CodeConverter gu("GBK","UTF-8");

		int i = sqlite3_exec( db, "update config set config_value = '1' where config_key = 'auto_login'", ConfigCallbak, NULL,  &errmsg );
		if (i != SQLITE_OK)
		{
			//std::cout << errmsg <<std::endl;
			//system ("pause");
			return false;
		}

		tmp = tmp + gu.StartConvert(username) + "' where config_key = 'username'";
		i = sqlite3_exec( db, tmp.c_str(), ConfigCallbak, NULL,  &errmsg );
		if (i != SQLITE_OK)
		{
			//std::cout << errmsg <<std::endl;
			//system ("pause");
			return false;
		}
		
		tmp = sql;
		tmp = tmp + gu.StartConvert(password) + "' " + "where config_key = 'password'";
		i = sqlite3_exec( db, tmp.c_str(), ConfigCallbak, NULL,  &errmsg );
		if (i != SQLITE_OK)
		{
			//std::cout << errmsg <<std::endl;
			//system ("pause");
			return false;
		}
		return true;
	}
	else
	{
		int i = sqlite3_exec( db, "update config set config_value = '0' where config_key = 'auto_login'", ConfigCallbak, NULL,  &errmsg );
		if (i != SQLITE_OK)
		{
			//std::cout << errmsg <<std::endl;
			//system ("pause");
			return false;
		}

		i = sqlite3_exec( db, "update config set config_value = '0' where config_key = 'username'", ConfigCallbak, NULL,  &errmsg );
		if (i != SQLITE_OK)
		{
			//std::cout << errmsg <<std::endl;
			//system ("pause");
			return false;
		}

		i = sqlite3_exec( db, "update config set config_value = '0' where config_key = 'password'", ConfigCallbak, NULL,  &errmsg );
		if (i != SQLITE_OK)
		{
			//std::cout << errmsg <<std::endl;
			//system ("pause");
			return false;
		}
		return true;
	}
}


bool gamebox_db::UpVersion(std::string version)
{
	CodeConverter gu("GBK","UTF-8");
	char * errmsg = NULL;
	std::string sql = "update config set config_value = '";
	sql = sql + gu.StartConvert(version) + "' where config_key = 'version'";
	int i = sqlite3_exec( db, sql.c_str(), ConfigCallbak, NULL,  &errmsg );
	if (i != SQLITE_OK)
	{
		//std::cout << errmsg <<std::endl;
		//system ("pause");
		return false;
	}

	return true;
}

bool gamebox_db::UpConfig(gamebox_config  * p)
{
	CodeConverter gu("GBK","UTF-8");
	char * errmsg = NULL;
	std::string sql = "update config set config_value = '";
	std::string tmp = sql;
	char ch[5] = {0};
	tmp += itoa(gb_config->pc_start,ch,10);
	tmp +="' ";
	tmp+= "where config_key = 'pc_start'";
	int i = sqlite3_exec( db, tmp.c_str(), ConfigCallbak, NULL,  &errmsg );
	if (i != SQLITE_OK)
	{
		//std::cout << errmsg <<std::endl;
		//system ("pause");
		return false;
	}
	tmp = sql;
	tmp += itoa(gb_config->full_screen,ch,10);
	tmp +="' ";
	tmp+= "where config_key = 'full_screen'";
	i = sqlite3_exec( db, tmp.c_str(), ConfigCallbak, NULL,  &errmsg );
	if (i != SQLITE_OK)
	{
		/*std::cout << errmsg <<std::endl;
		system ("pause");*/
		return false;
	}
	tmp = sql;
	tmp += itoa(gb_config->exit_mode,ch,10);
	tmp +="' ";
	tmp+= "where config_key = 'exit_mode'";
	i = sqlite3_exec( db, tmp.c_str(), ConfigCallbak, NULL,  &errmsg );
	if (i != SQLITE_OK)
	{
		/*std::cout << errmsg <<std::endl;
		system ("pause");*/
		return false;
	}

	tmp = sql;
	tmp += itoa(gb_config->agree_share,ch,10);
	tmp +="' ";
	tmp+= "where config_key = 'agree_share'";
	i = sqlite3_exec( db, tmp.c_str(), ConfigCallbak, NULL,  &errmsg );
	if (i != SQLITE_OK)
	{
		/*std::cout << errmsg <<std::endl;
		system ("pause");*/
		return false;
	}

	tmp = sql;
	tmp += gu.StartConvert(gb_config->boos_key);
	tmp +="' ";
	tmp+= "where config_key = 'boos_key'";
	i = sqlite3_exec( db, tmp.c_str(), ConfigCallbak, NULL,  &errmsg );
	if (i != SQLITE_OK)
	{
		/*std::cout << errmsg <<std::endl;
		system ("pause");*/
		return false;
	}

	tmp = sql;
	tmp += itoa(gb_config->num_down_session,ch,10);
	tmp +="' ";
	tmp+= "where config_key = 'num_down_session'";
	i = sqlite3_exec( db, tmp.c_str(), ConfigCallbak, NULL,  &errmsg );
	if (i != SQLITE_OK)
	{
		/*std::cout << errmsg <<std::endl;
		system ("pause");*/
		return false;
	}

	tmp = sql;
	tmp += itoa(gb_config->down_mode,ch,10);
	tmp +="' ";
	tmp+= "where config_key = 'down_mode'";
	i = sqlite3_exec( db, tmp.c_str(), ConfigCallbak, NULL,  &errmsg );
	if (i != SQLITE_OK)
	{
		/*std::cout << errmsg <<std::endl;
		system ("pause");*/
		return false;
	}

	tmp = sql;
	tmp += itoa(gb_config->down_speed_down,ch,10);
	tmp +="' ";
	tmp+= "where config_key = 'down_speed_down'";
	i = sqlite3_exec( db, tmp.c_str(), ConfigCallbak, NULL,  &errmsg );
	if (i != SQLITE_OK)
	{
		/*std::cout << errmsg <<std::endl;
		system ("pause");*/
		return false;
	}

	tmp = sql;
	tmp += itoa(gb_config->down_speed_up,ch,10);
	tmp +="' ";
	tmp+= "where config_key = 'down_speed_up'";
	i = sqlite3_exec( db, tmp.c_str(), ConfigCallbak, NULL,  &errmsg );
	if (i != SQLITE_OK)
	{
		/*std::cout << errmsg <<std::endl;
		system ("pause");*/
		return false;
	}

	tmp = sql;
	tmp += gu.StartConvert(gb_config->save_dir);
	tmp +="' ";
	tmp+= "where config_key = 'save_dir'";
	i = sqlite3_exec( db, tmp.c_str(), ConfigCallbak, NULL,  &errmsg );
	if (i != SQLITE_OK)
	{
		/*std::cout << errmsg <<std::endl;
		system ("pause");*/
		return false;
	}

	tmp = sql;
	tmp += itoa(gb_config->auto_down,ch,10);
	tmp +="' ";
	tmp+= "where config_key = 'auto_down'";
	i = sqlite3_exec( db, tmp.c_str(), ConfigCallbak, NULL,  &errmsg );
	if (i != SQLITE_OK)
	{/*
		std::cout << errmsg <<std::endl;
		system ("pause");*/
		return false;
	}

	tmp = sql;
	tmp +=gu.StartConvert(gb_config->install_dir);
	tmp +="' ";
	tmp+= "where config_key = 'install_dir'";
	i = sqlite3_exec( db, tmp.c_str(), ConfigCallbak, NULL,  &errmsg );
	if (i != SQLITE_OK)
	{
		/*std::cout << errmsg <<std::endl;
		system ("pause");*/
		return false;
	}

	tmp = sql;
	tmp += itoa(gb_config->auto_install_dir,ch,10);
	tmp +="' ";
	tmp+= "where config_key = 'auto_install_dir'";
	i = sqlite3_exec( db, tmp.c_str(), ConfigCallbak, NULL,  &errmsg );
	if (i != SQLITE_OK)
	{
		/*std::cout << errmsg <<std::endl;
		system ("pause");*/
		return false;
	}

	tmp = sql;
	tmp += itoa(gb_config->auto_install,ch,10);
	tmp +="' ";
	tmp+= "where config_key = 'auto_install'";
	i = sqlite3_exec( db, tmp.c_str(), ConfigCallbak, NULL,  &errmsg );
	if (i != SQLITE_OK)
	{
		/*std::cout << errmsg <<std::endl;
		system ("pause");*/
		return false;
	}
	
	return true;
}

int ConfigCallbak( void * para, int n_column, char ** column_value, char ** column_name )
{
	gamebox_config * p = (gamebox_config *)para;
	CodeConverter ug("UTF-8","GBK");
	if (0 == strcmp(column_value[0],"pc_start"))
	{
		p->pc_start =atoi( column_value[1]);
		//std::cout <<column_value[0]<<std::endl << column_value[1] <<std::endl;
	}
	else if(0 == strcmp(column_value[0],"full_screen"))
	{
		p->full_screen =atoi( column_value[1]);
	}
	else if(0 == strcmp(column_value[0],"exit_mode"))
	{
		p->exit_mode =atoi( column_value[1]);
	}
	else if(0 == strcmp(column_value[0],"agree_share"))
	{
		p->agree_share =atoi( column_value[1]);
	}
	else if(0 == strcmp(column_value[0],"boos_key"))
	{
		p->boos_key = ug.StartConvert( column_value[1]);
	}
	else if(0 == strcmp(column_value[0],"num_down_session"))
	{
		p->num_down_session =atoi( column_value[1]);
	}
	else if(0 == strcmp(column_value[0],"down_mode"))
	{
		p->down_mode =atoi( column_value[1]);
	}
	else if(0 == strcmp(column_value[0],"down_speed_down"))
	{
		p->down_speed_down =atoi( column_value[1]);
	}
	else if(0 == strcmp(column_value[0],"down_speed_up"))
	{
		p->down_speed_up =atoi( column_value[1]);
	}
	else if(0 == strcmp(column_value[0],"save_dir"))
	{
		p->save_dir =ug.StartConvert(column_value[1]);
	}
	else if(0 == strcmp(column_value[0],"auto_down"))
	{
		p->auto_down =atoi( column_value[1]);
	}
	else if(0 == strcmp(column_value[0],"install_dir"))
	{
		p->install_dir =ug.StartConvert(column_value[1]);
	}
	else if(0 == strcmp(column_value[0],"auto_install_dir"))
	{
		p->auto_install_dir =atoi( column_value[1]);
	}
	else if(0 == strcmp(column_value[0],"auto_install"))
	{
		p->auto_install =atoi( column_value[1]);
	}
	else if(0 == strcmp(column_value[0],"auto_login"))
	{
		p->auto_login =atoi( column_value[1]);
	}
	else if(0 == strcmp(column_value[0],"username"))
	{
		p->username =ug.StartConvert( column_value[1]);
	}
	else if(0 == strcmp(column_value[0],"password"))
	{
		p->password =ug.StartConvert( column_value[1]);
	}
	else if(0 == strcmp(column_value[0],"version"))
	{
		p->version = ug.StartConvert(column_value[1]);
	}

	return 0;
}

