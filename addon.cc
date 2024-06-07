#include <napi.h>

Napi::Value getData(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments")
            .ThrowAsJavaScriptException();
        return env.Null();
    }

    char *date, *event, *result;

    strcpy(date, info[0].As<Napi::String>().Utf8Value().c_str());
    strcpy(event, info[1].As<Napi::String>().Utf8Value().c_str());

    sprintf(result, "%s %s", date, event);

    Napi::String str = Napi::String::New(env, result);

    return str;
}

Napi::Object Init(Napi::Env env, Napi::Object exports) {
  exports.Set(Napi::String::New(env, "get_data"), Napi::Function::New(env, getData));
  return exports;
}

NODE_API_MODULE(addon, Init)
