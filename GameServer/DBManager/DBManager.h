#include "Service/DBClient.h"
#include "resource.h"


class CDBManager
{
	bool configRegisted = false;
	int DBServiceCount;
	std::vector<std::string> DBServiceAddress;
	std::vector<CDBClient*> DBClientArr;

public:
	void RegistDBService(std::string FileName);

	void Start();

};

