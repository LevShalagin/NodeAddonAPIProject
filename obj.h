#pragma once

#include<napi.h>

class ToDoPlanner : public Napi::ObjectWrap<ToDoPlanner> {
 public:
    std::string _event;
    std::string _date;
    int _index;

    static Napi::Object Init(Napi::Env env, Napi::Object exports);
    ToDoPlanner(const Napi::CallbackInfo& info);

    Napi::Value GetEvent(const Napi::CallbackInfo& info);
    void SetEvent(const Napi::CallbackInfo& info);

    Napi::Value GetDate(const Napi::CallbackInfo& info);
    void SetDate(const Napi::CallbackInfo& info);

    Napi::Value GetIndex(const Napi::CallbackInfo& info);
    void SetIndex(const Napi::CallbackInfo& info);

    void Print(const Napi::CallbackInfo& info);
};
