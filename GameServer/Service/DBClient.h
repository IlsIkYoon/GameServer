#pragma once

#include <grpcpp/grpcpp.h>
#include "proto/DB.grpc.pb.h"
#include "proto/DB.pb.h"

class CDBClient
{
public:
    // 생성자: 서버 주소 지정
    CDBClient(const std::string& server_address);
    HANDLE hDBThread;

    // RPC 함수들
    bool CreateUser(uint64_t id);
    bool DeleteUser(uint64_t id);
    bool UpdateUser(uint64_t id, uint32_t level, uint32_t hp);
    bool GetUser(uint64_t id, uint32_t& level, uint32_t& hp);

private:
    std::unique_ptr<DB::DB::Stub> stub_;
};