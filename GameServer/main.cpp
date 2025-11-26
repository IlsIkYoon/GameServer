#include "Service/GreetService.h"	
#include "resource.h"


int main()
{
	// 서버 주소: localhost, 포트 50051 (서버 설정에 맞게 변경)
	GreeterTestClient client(grpc::CreateChannel(
		"localhost:5188", grpc::InsecureChannelCredentials()));

	std::string user = "World";
	std::string reply = client.SayHello(user);
	std::cout << "Greeter received: " << reply << std::endl;

	Sleep(10000);


	return 0;
}