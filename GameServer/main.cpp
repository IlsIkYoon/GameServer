
#include "Service/DBClient.h"
#include "GameServer.h"
#include "resource.h"

int main()
{
	unsigned int level = 0;
	unsigned int hp = 0;
	DBClient client("127.0.0.1:5188");
	for (int i = 0; i <= 10; i++)
	{
		unsigned int level;
		unsigned int hp;
		client.GetUser(i, level, hp);
		std::cout << level << " " << hp << "\n";
	}

	GameServer();


	return 0;
}