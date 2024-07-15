#include <napi.h>

Napi::String tableEdit(const Napi::CallbackInfo& info) {
    auto table = info[0].As<Napi::Array>();

    printf("table.IsArray = %s\n", table.IsArray() ? "true" : "false");
}

Napi::Object Init(Napi::Env env, Napi::Object exports) {
  exports.Set(Napi::String::New(env, "tabEdit"), Napi::Function::New(env, tableEdit));
  return exports;
}

NODE_API_MODULE(tabEdit, Init)