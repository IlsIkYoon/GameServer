#include <iostream>
#include <memory>
#include <string>

#include <grpcpp/grpcpp.h>
#include "proto/greet.pb.h"
#include "proto/greet.grpc.pb.h"

using grpc::Channel;
using grpc::ClientContext;
using grpc::Status;
using greet::HelloRequest;
using greet::HelloReply;
using greet::Greeter;

class GreeterTestClient
{
public:
    // 채널을 통해 서버 연결
    GreeterTestClient(std::shared_ptr<Channel> channel)
        : stub_(Greeter::NewStub(channel)) {
    }

    // 서버에게 "SayHello" 호출
    std::string SayHello(const std::string& user_name) {
        HelloRequest request;
        request.set_name(user_name);

        HelloReply reply;
        ClientContext context;

        // 동기 호출
        Status status = stub_->SayHello(&context, request, &reply);

        if (status.ok()) {
            return reply.message();
        }
        else {
            std::cerr << "RPC failed. Code: " << status.error_code()
                << ", Message: " << status.error_message() << std::endl;
            return "RPC failed";
        }
    }


private:
    std::unique_ptr<Greeter::Stub> stub_;


};
