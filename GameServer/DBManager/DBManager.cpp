#include "DBManager.h"
#include "Parser/TextParser.h"



void CDBManager::RegistDBService(std::string FileName)
{	
	txParser.GetData(FileName.c_str());
	txParser.SearchData("DBServiceCount", &DBServiceCount);

	std::vector<std::string> DBServiceAddress(DBServiceCount);

	for (int i = 0; i < DBServiceCount; i++)
	{
		std::string key = "DBService" + std::to_string(i);
		txParser.SearchData(key.c_str(), DBServiceAddress[i]);
	}


	txParser.CloseData();
}