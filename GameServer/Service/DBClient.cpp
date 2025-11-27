#include "DBClient.h"
#include "resource.h"

DBClient::DBClient(const std::string& server_address)
{
    stub_ = DB::DB::NewStub(grpc::CreateChannel(
        server_address, grpc::InsecureChannelCredentials()));
}

bool DBClient::CreateUser(uint64_t id)
{
    DB::CreateUserRequest request;
    request.set_id(id);
    DB::CreateUserReply reply;
    grpc::ClientContext context;

    grpc::Status status = stub_->CreateUser(&context, request, &reply);
    if (status.ok()) {
        std::cout << "CreateUser: " << reply.message() << "\n";
        return true;
    }
    std::cerr << "CreateUser failed: " << status.error_message() << "\n";
    return false;
}

bool DBClient::DeleteUser(uint64_t id)
{
    DB::DeleteUserRequest request;
    request.set_id(id);
    DB::DeleteUserReply reply;
    grpc::ClientContext context;

    grpc::Status status = stub_->DeleteUser(&context, request, &reply);
    if (status.ok()) {
        std::cout << "DeleteUser: ID=" << reply.id() << "\n";
        return true;
    }
    std::cerr << "DeleteUser failed: " << status.error_message() << "\n";
    return false;
}

bool DBClient::UpdateUser(uint64_t id, uint32_t level, uint32_t hp)
{
    DB::UpdateUserRequest request;
    request.set_id(id);
    request.set_level(level);
    request.set_hp(hp);

    DB::UpdateUserReply reply;
    grpc::ClientContext context;

    grpc::Status status = stub_->UpdateUser(&context, request, &reply);
    if (status.ok()) {
        std::cout << "UpdateUser: ID=" << reply.id()
            << ", Level=" << reply.level()
            << ", HP=" << reply.hp() << "\n";
        return true;
    }
    std::cerr << "UpdateUser failed: " << status.error_message() << "\n";
    return false;
}

bool DBClient::GetUser(uint64_t id, uint32_t& level, uint32_t& hp)
{
    DB::GetUserRequest request;
    request.set_id(id);

    DB::GetUserReply reply;
    grpc::ClientContext context;

    grpc::Status status = stub_->GetUser(&context, request, &reply);
    if (status.ok()) {
        level = reply.level();
        hp = reply.hp();
        std::cout << "GetUser: ID=" << reply.id()
            << ", Level=" << level
            << ", HP=" << hp << "\n";
        return true;
    }
    std::cerr << "GetUser failed: " << status.error_message() << "\n";
    return false;
}