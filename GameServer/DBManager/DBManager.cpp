#include "DBManager.h"
#include "Parser/TextParser.h"



void CDBManager::RegistDBService(std::string FileName)
{	
	txParser.GetData(FileName.c_str());
	txParser.SearchData("DBServiceCount", &DBServiceCount);

	DBServiceAddress.resize(DBServiceCount);

	for (int i = 0; i < DBServiceCount; i++)
	{
		bool parserRetval;
		std::string key = "DBService[" + std::to_string(i)+"]";
		parserRetval = txParser.SearchData(key.c_str(), DBServiceAddress[i]);
		if (parserRetval == false)
		{
			std::cout << "Read DBConfigFile Error!!!\n";
		}
	}

	configRegisted = true;

	txParser.CloseData();
}


void CDBManager::Start()
{
	DBClientArr.resize(DBServiceCount);
	for (int i = 0; i < DBServiceCount; i++)
	{
		DBClientArr[i] = new CDBClient(DBServiceAddress[i]);
	}


}