#include <napi.h>

#include <iostream>
#include <string>


Napi::String tableEdit(const Napi::CallbackInfo& info) {
  auto table = info[0].As<Napi::Array>();

  printf("table.IsArray = %s\n", table.IsArray() ? "true" : "false");
}

Napi::String getCommand(const Napi::CallbackInfo& info) {
  std::string command;
  printf("Write command(add/del): ");

  std::getline(std::cin, command);
  if(command == "add") {
    return Napi::String::New(info.Env(), "add");
  }
  if(command == "del") {
    return Napi::String::New(info.Env(), "del");
  }
}

Napi::Object Init(Napi::Env env, Napi::Object exports) {
  exports.Set(Napi::String::New(env, "tabEdit"), Napi::Function::New(env, tableEdit));
  exports.Set(Napi::String::New(env, "getCmd"), Napi::Function::New(env, getCommand));
  return exports;
}

NODE_API_MODULE(tabEdit, Init)