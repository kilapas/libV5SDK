#pragma once

#include <string>
#include <unordered_map>

#define IMPORT __declspec(dllimport)

#define APP_ID (L"voc5")

#define DECLARE_AS_MANAGED(ClassName) \
public: \
    inline ClassName() { _cppObjPtr = {}; } \
    inline explicit ClassName(void* cppObjPtr) { _cppObjPtr = cppObjPtr; } \
    void Dispose(); \
    inline operator bool() const { return _cppObjPtr; } \
    inline operator void*() const { return _cppObjPtr; } \
private: \
    void* _cppObjPtr {}; \

