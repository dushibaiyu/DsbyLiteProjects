#include "gamebox_db.h"

bool gamebox_db::AddGame (game_info &game)
{
	CodeConverter gu("GBK","UTF-8");
	char * errmsg = NULL;
	std::string sql = "insert into stuff (stuff_id,stuff_name,stuff_category ,stuff_exec,stuff_program,stuff_ico,stuff_history) values (";
	std::string tmp = sql;
	char ch[255] = {0};
	tmp= tmp + itoa(game.stuff_id,ch,10) +",'" + gu.StartConvert(game.stuff_name) +"',"+ itoa(game.stuff_category,ch,10) +","+itoa(game.stuff_exec,ch,10) + ",'" +gu.StartConvert(game.stuff_program) ;
	tmp = tmp + "','" + gu.StartConvert(game.stuff_ico) + "'," + itoa(game.stuff_history,ch,10)+")" ;

	int i = sqlite3_exec( db, tmp.c_str(), NULL, NULL,  &errmsg );
	if (i != SQLITE_OK)
	{
		std::cout << errmsg <<std::endl;
		system ("pause");
		return false;
	}
	return true;
}

bool gamebox_db::UpLRU(std::string stuff_program, bool game_sate)
{
	CodeConverter gu("GBK","UTF-8");
	char * errmsg = NULL;
	char ch[255] = {0};
	std::string sql = "update stuff set stuff_history=";
	if (game_sate)
	{
		std::string tmp = sql;
		tmp = tmp + "stuff_history+'1' where stuff_program = '" + gu.StartConvert(stuff_program)+"'";
		int i = sqlite3_exec(db, tmp.c_str(), stuffCallbak, &g_info,  &errmsg );
		if (i != SQLITE_OK)
		{
			/*std::cout << errmsg <<std::endl;
			system ("pause");*/
			return false;
		}

		return true;
	}
	else
	{
		std::string tmp = sql;
		tmp = tmp +"'0' where stuff_program = '" + gu.StartConvert(stuff_program)+"'";
		int i = sqlite3_exec(db, tmp.c_str(), stuffCallbak, &g_info,  &errmsg );
		if (i != SQLITE_OK)
		{
			/*std::cout << errmsg <<std::endl;
			system ("pause");*/
			return false;
		}
		return true;
	}
}

std::vector<game_info> *  gamebox_db::GetLRU ()
{
	g_info.clear();
	char * errmsg = NULL;
	int i = sqlite3_exec(db, "select * from stuff where stuff_history > '0'  order by stuff_history desc", stuffCallbak, &g_info,  &errmsg );
	if (i != SQLITE_OK)
	{
		/*std::cout << errmsg <<std::endl;
		system ("pause");*/
	}

	return &g_info;
}

std::vector<game_info> * gamebox_db::GetGameList(int  category)
{
	g_info.clear();
	char * errmsg = NULL;

	if (category == -1)
	{
		int i = sqlite3_exec(db, "select * from stuff ", stuffCallbak, &g_info,  &errmsg );
		if (i != SQLITE_OK)
		{
			/*std::cout << errmsg <<std::endl;
			system ("pause");*/
		}

		return &g_info;
	}
	else
	{
		char ch[255] = {0};
		std::string sql =  "select * from stuff where stuff_category  = '";
		sql = sql + itoa(category,ch,10) + "' order by stuff_history desc";
		int i = sqlite3_exec(db, sql.c_str(), stuffCallbak, &g_info,  &errmsg );
		if (i != SQLITE_OK)
		{
			/*std::cout << errmsg <<std::endl;
			system ("pause");*/
		}

		return &g_info;
	}
}

bool gamebox_db::DelGame(std::string stuff_program)
{
	CodeConverter gu("GBK","UTF-8");
	char * errmsg = NULL;
	char ch[255] = {0};
	std::string sql = "delete from  stuff where stuff_program = '";
	sql = sql + gu.StartConvert(stuff_program) +"'";
	int i = sqlite3_exec(db, sql.c_str(), NULL, NULL,  &errmsg );
	if (i != SQLITE_OK)
	{
	/*	std::cout << errmsg <<std::endl;
		system ("pause");*/
		return false;

	}
	return true;
}

unsigned long int gamebox_db::GetId(std::string stuff_program)//根据名字查找id
{
	CodeConverter gu("GBK","UTF-8");
	char * errmsg = NULL;
	unsigned long int id;
	std::string sql = "select stuff_id from stuff where stuff_program = '" + gu.StartConvert(stuff_program)+"'";
	int i = sqlite3_exec(db, sql.c_str(), IdCallbak, &id,  &errmsg );
	if (i != SQLITE_OK)
	{
		/*std::cout << errmsg <<std::endl;
		system ("pause");*/
		return 0;
	}
	return id;

}


int stuffCallbak( void * para, int n_column, char ** column_value, char ** column_name )
{
	CodeConverter ug("UTF-8","GBK");
	std::vector<game_info> * p ;
	p	= (std::vector<game_info> *)para;
	game_info game;
    game.stuff_id = atol(column_value[0]);
	game.stuff_name = ug.StartConvert(column_value[1]);
	game.stuff_category  =atoi(column_value[2]);
	game.stuff_exec = atoi(column_value[3]);
	game.stuff_program = ug.StartConvert(column_value[4]);
	game.stuff_ico =ug.StartConvert( column_value[5]);
	game.stuff_history = atol(column_value[6]);
	

	p->push_back(game);

	return 0;
}

int IdCallbak( void * para, int n_column, char ** column_value, char ** column_name )
{
	unsigned long int * p = (unsigned long int *)para;
	*p = atol(column_value[0]);

	return 0;
}