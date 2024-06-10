#include <napi.h>

Napi::Value getDate(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments")
            .ThrowAsJavaScriptException();
        return env.Null();
    }

    char *date = (char*)malloc(1500);
    char *event = (char*)malloc(1500);
    char *result = (char*)malloc(1500);

    strcpy(date, info[0].As<Napi::String>().Utf8Value().c_str());
    strcpy(event, info[1].As<Napi::String>().Utf8Value().c_str());

    sprintf(result, "<tr><td>%s</td><td>%s</td></tr>", date, event);

    printf("C: %s\n", result);

    Napi::String str = Napi::String::New(env, result);

    return str;
}

Napi::Object Init(Napi::Env env, Napi::Object exports) {
  exports.Set(Napi::String::New(env, "get_date"), Napi::Function::New(env, getDate));
  return exports;
}

NODE_API_MODULE(addon, Init)
