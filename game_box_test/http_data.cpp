
#include "http_data.h"

string http_data::UserPostData(char * username, char * password)
{
	string tmp = "username=";
	tmp = tmp + username + "&password=" + password;
	return tmp;
}

string http_data::UserPostData(gamebox_config * user)
{
	string tmp = "username=";
	tmp = tmp + user->username + "&password=" + user->password;
	return tmp;
}

string http_data::GamePostData(vector<game_info> * g_info)
{
	string tmp = "{\"stuff_id\":";
	for (unsigned int i = 0; i< g_info->capacity() ; ++i)
	{
		if ((*g_info)[i].stuff_id != 0)
		{
			char ch[255] = {0};
			tmp =tmp+ ltoa((*g_info)[i].stuff_id,ch,10) + "\",\"{\"stuff_id\":";
		}
	}
		tmp += "\"}";
	return tmp;
}

string http_data::GamePostData(int id)
{
	char ch[255] = {0};
	string tmp = "stuff_id=";
	tmp =tmp+ ltoa(id,ch,10);
	return tmp;
}

bool http_data::GetState(string json)
{
	if (json.empty())
	{
		if (state.compare("0"))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		ResolveJson(json);
		if (state.compare("0"))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}

string http_data::GetSession(string json)
{
	if (json.empty())
	{
		return session;
	}
	else
	{
		ResolveJson(json);
		return session;
	}
	
}


string http_data::GetVersion(string json)
{
	if (json.empty())
	{
		return version;
	}
	else
	{
		ResolveJson(json);
		return version;
	}
}

string http_data::GetNewVersionUrl(string json)
{
	if (json.empty())
	{
		return ver_url;
	}
	else
	{
		ResolveJson(json);
		return ver_url;
	}
}

user_login_data http_data::GetUserData(string json)
{
	if (json.empty())
	{
		return user_data;
	}
	else
	{
		ResolveJson(json);
		return user_data;
	}
}

void http_data::ResolveJson(string json)
{
	InitializeString();

	
	json_error_t *error = NULL;
	json_t *value = NULL;
	json_t * obj = json_loadb(json.c_str(),json.length(), 0, error); 
	if(!obj)
	{
        /* the error variable contains error information */
		/*std::cout << error<<std::endl;*/
    }

	/*char *  p =json_dumps(obj, JSON_ENSURE_ASCII|JSON_INDENT(1)|JSON_SORT_KEYS);
	std::cout << p <<std::endl;*/


	const char * key= NULL;
	json_object_foreach(obj,key, value)
	{
		 if(!strcmp(key,"state"))
		 {
			 state.assign(json_string_value(value));
		 }
		 if(!strcmp(key,"session"))
		 {
			 session.assign(json_string_value(value));
		 }
		 if(!strcmp(key,"username"))
		 {
			 user_data.username.assign(json_string_value(value));
		 }
		 if(!strcmp(key,"icon"))
		 {
			 user_data.icon.assign(json_string_value(value));
		 }
		 if(!strcmp(key,"level"))
		 {
			user_data.level.assign(json_string_value(value));
		 }
		 if(!strcmp(key,"exp_current"))
		 {
			 user_data.exp_current.assign(json_string_value(value));
		 }
		 if(!strcmp(key,"exp_total"))
		 {
			 user_data.exp_total.assign(json_string_value(value));
		 }
		 if(!strcmp(key,"version"))
		 {
			 version.assign(json_string_value(value));
		 }
		 if (!strcmp(key,"urldown"))
		 {
			 ver_url.assign(json_string_value(value));
		 }
		
	}


}