
#include "Service/DBClient.h"
#include "GameServer.h"
#include "resource.h"

int main()
{
	DBClient client("127.0.0.1:5188");

	for (unsigned int i = 1; i < 10; i++)
	{
		client.DeleteUser(i);
	}

	GameServer();


	return 0;
}