#include <string>
#include <fmt/color.h>
#include <fmt/core.h>
#include <iostream>
#include "user.pb.h"

int main(int, char**){

    demo::User user;
    user.set_id(101);
    user.set_name("Sola");
    user.set_email("sola@example.com");
    
    fmt::print(fg(fmt::color::cyan), "--- 原始数据 (fmt) ---\n");
    fmt::print("ID      : {}\n", user.id());
    fmt::print("Name:   : {}\n", user.name());
    fmt::print("Email:  : {}\n", user.email());

    std::string serialized_data;
    if(!user.SerializePartialToString(&serialized_data)){
        fmt::print(stderr, fg(fmt::color::red), "错误， 序列化失败!\n");
        return -1;
    }

    fmt::print(fg(fmt::color::green), "\n序列化成功, 字节大小: {} bytes\n",serialized_data.size());

    demo::User parsed_user;
    if(parsed_user.ParseFromString(serialized_data))
    {
        fmt::print(fg(fmt::color::yellow), "\n---反序列化结果----\n");
        fmt::print("User: [ID: {} Name: {}\n]",parsed_user.id(), parsed_user.name());
    }

    return 0;
}
