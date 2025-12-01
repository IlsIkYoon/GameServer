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


	//---------------------------------------------------
	// DB샤딩 분산 환경에서 id에 맞는 DBService에 연결시켜주는 함수
	//---------------------------------------------------
	int GetDBServiceForId(unsigned long long id);

	bool CreateUser(uint64_t id);
	bool DeleteUser(uint64_t id);
	bool UpdateUser(uint64_t id, uint32_t level, uint32_t hp);
	bool GetUser(uint64_t id, uint32_t& level, uint32_t& hp);


};

