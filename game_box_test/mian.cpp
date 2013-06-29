

#include "gamebox_db.h"
#include "http_data.h"
#include "HTTP.h"

using std::string;
using std::vector;
using std::cout;
using std::endl;
using std::cin;


int main ()
{

	gamebox_db * p = gamebox_db::GetDbDate();

	p->GetConfig();

	vector<game_info> * h = p->GetLRU();

	for (unsigned int i = 0; i< h->size(); ++i )

	{
		cout << h->at(i).stuff_name<<endl;
	}
	p->UpLRU(h->at(0).stuff_program,true);
	h = p->GetGameList();
	for (i = 0; i< h->size(); ++i )

	{
		cout << h->at(i).stuff_name<<endl;
	}
	game_info g = {0,"ÄãÊÇ£¿",0,0,"0","0",0};
	p->DelGame(g.stuff_program);
	h = p->GetGameList();
	for (i = 0; i< h->size(); ++i )
	{
		cout << h->at(i).stuff_name<< "   ";
	}
	cout <<endl;

	i = p->GetId("ÄãÊÇ£¿");
	cout << i <<endl;



	system ("pause");
	
	return 0;
}