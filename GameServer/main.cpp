
#include "Service/DBClient.h"
#include "GameServer.h"
#include "resource.h"

int main()
{
	unsigned int level = 0;
	unsigned int hp = 0;
	DBClient client("127.0.0.1:5188");
	client.CreateUser(1);
	client.GetUser(1, level, hp);
	client.UpdateUser(2, 20, 300);
	client.DeleteUser(1);

	GameServer();


	return 0;
}