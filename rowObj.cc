#include "rowObj.h"

#include <iostream>
#include <string>

#include <locale>
#include <windows.h>

/////////////////////////////////////////////////////////////////////////////

std::string ConvertUTF8ToCP1251(const std::string& str)
{
    int len = MultiByteToWideChar(CP_UTF8, 0, str.c_str(), -1, NULL, 0);
    wchar_t* wstr = new wchar_t[len];
    MultiByteToWideChar(CP_UTF8, 0, str.c_str(), -1, wstr, len);

    len = WideCharToMultiByte(1251, 0, wstr, -1, NULL, 0, NULL, NULL);
    char* cp1251 = new char[len];
    WideCharToMultiByte(1251, 0, wstr, -1, cp1251, len, NULL, NULL);

    std::string result(cp1251);
    delete[] wstr;
    delete[] cp1251;

    return result;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Napi::Object ToDoPlanner::Init(Napi::Env env, Napi::Object exports) {
  
  Napi::Function func =
      DefineClass(env,
                  "MyObject",
                  {
                  InstanceMethod("getEvent", &ToDoPlanner::GetEvent),
                  InstanceMethod("setEvent", &ToDoPlanner::SetEvent),

                  InstanceMethod("getDate", &ToDoPlanner::GetDate),
                  InstanceMethod("setDate", &ToDoPlanner::SetDate),

                  InstanceMethod("getIndex", &ToDoPlanner::GetIndex),
                  InstanceMethod("setIndex", &ToDoPlanner::SetIndex),

                  InstanceMethod("print", &ToDoPlanner::Print),
                  });

  Napi::FunctionReference* constructor = new Napi::FunctionReference();
  *constructor = Napi::Persistent(func);
  env.SetInstanceData(constructor);

  exports.Set("ToDoPlanner", func);

  return exports;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

ToDoPlanner::ToDoPlanner(const Napi::CallbackInfo& info) : Napi::ObjectWrap<ToDoPlanner>(info) {

  Napi::Env env = info.Env();

  std::locale::global(std::locale("Russian"));
  SetConsoleOutputCP(1251);
  
  if (info.Length() == 3) {
    Napi::Number index = info[0].As<Napi::Number>();
    Napi::String date = info[1].As<Napi::String>();
    Napi::String event = info[2].As<Napi::String>();
    
    this->_index = index.Int32Value();
    this->_date = date.Utf8Value();
    this->_event = event.Utf8Value();
  }
    
  if (info.Length() == 1) {
    Napi::Number index = info[0].As<Napi::Number>();
    this->_index = index.Int32Value();

    printf("Write the date(dd/mm/yyyy): ");
    std::getline(std::cin, this->_date);
    
    printf("Write an event(max.50): ");
    std::getline(std::cin, this->_event);

    this->_date = Napi::String::New(info.Env(), this->_date).As<Napi::String>().Utf8Value();
    this->_event = Napi::String::New(info.Env(), this->_event).As<Napi::String>().Utf8Value();
  }

  if (info.Length() != 3 && info.Length() != 1) {
    Napi::TypeError::New(info.Env(), "неверное кол-во аргументов").ThrowAsJavaScriptException();
  }
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Napi::Value ToDoPlanner::GetEvent(const Napi::CallbackInfo& info){
  Napi::Env env = info.Env();
  return Napi::String::New(env, this->_event);
}

void ToDoPlanner::SetEvent(const Napi::CallbackInfo& info){
  Napi::Env env = info.Env();

  Napi::String event = info[0].As<Napi::String>();
  this->_event = event.Utf8Value();
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Napi::Value ToDoPlanner::GetDate(const Napi::CallbackInfo& info){
  Napi::Env env = info.Env();
  return Napi::String::New(env, this->_date);
}

void ToDoPlanner::SetDate(const Napi::CallbackInfo& info){
  Napi::Env env = info.Env();

  Napi::String date = info[0].As<Napi::String>();
  this->_date = date.Utf8Value();
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Napi::Value ToDoPlanner::GetIndex(const Napi::CallbackInfo& info){
  Napi::Env env = info.Env();
  return Napi::Number::New(env, this->_index);
}

void ToDoPlanner::SetIndex(const Napi::CallbackInfo& info) {
  this->_index = info[0].As<Napi::Number>().Int32Value();
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void ToDoPlanner::Print(const Napi::CallbackInfo& info) {
  this->_event = ConvertUTF8ToCP1251(this->_event);
  printf("%03d|%10s|    %s\n", this->_index, this->_date, this->_event);
  // printf("capacity: %d\n", this->_event.capacity());
  // printf("length: %d\n\n", this->_event.length());
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Napi::Object InitAll(Napi::Env env, Napi::Object exports) {
  return ToDoPlanner::Init(env, exports);
}

NODE_API_MODULE(NODE_GYP_MODULE_NAME, InitAll);

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////