
#include "DBManager/DBManager.h"
#include "GameServer.h"
#include "resource.h"

int main()
{
	CDBManager test;
	test.RegistDBService("DBService.config");

	GameServer();


	return 0;
}