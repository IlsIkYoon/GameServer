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

int CDBManager::GetDBServiceForId(unsigned long long id)
{
	
	return id % DBServiceCount;
}


bool CDBManager::CreateUser(uint64_t id)
{
	int myDBService = GetDBServiceForId(id);
	return DBClientArr[myDBService]->CreateUser(id);
}
bool CDBManager::DeleteUser(uint64_t id)
{
	int myDBService = GetDBServiceForId(id);
	return DBClientArr[myDBService]->DeleteUser(id);
	
}
bool CDBManager::UpdateUser(uint64_t id, uint32_t level, uint32_t hp)
{
	int myDBService = GetDBServiceForId(id);
	return DBClientArr[myDBService]->UpdateUser(id, level, hp);
}
bool CDBManager::GetUser(uint64_t id, uint32_t& level, uint32_t& hp)
{
	int myDBService = GetDBServiceForId(id);
	return DBClientArr[myDBService]->UpdateUser(id, level, hp);
}
