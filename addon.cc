#include <napi.h>

Napi::String SayHi(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  return Napi::String::New(env, "hi");
}


Napi::Object Init(Napi::Env env, Napi::Object exports) {
    exports.Set(Napi::String::New(env, "hi"), Napi::Function::New(env, SayHi));
    return exports;
}


NODE_API_MODULE(addon, Init)