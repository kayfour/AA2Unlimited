#pragma once
#include <codecvt>
#include <string>
#include "lua.hpp"
#include "Selene/selene.h"
#include "defs.h"

static std::wstring_convert<std::codecvt_utf8<wchar_t>> utf8;

class Lua : public sel::State {
public:;
	Lua(bool libs);
	void bind();
	void init();
};

#define LUA_EXTCLASS(n,...) g_Lua.ExtClass<LUA_CLASS>(#n, __VA_ARGS__)
#define LUA_FIELD(n) #n, &LUA_CLASS::n
#define LUA_EVENT(...) g_Lua["__DISPATCH_EVENT"](__VA_ARGS__)

extern Lua g_Lua;