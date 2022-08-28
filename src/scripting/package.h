#include <LuaCpp/LuaCpp.hpp>
#include "script_manager.h"

void InitializeScriptManager() {

    LuaCpp::LuaContext lua;
    std::shared_ptr<LuaCpp::Registry::LuaLibrary> mathLib = MakeMathLib();
    lua.AddLibrary(mathLib);

    std::string lua_source = ReadFile();
    lua.CompileStringAndRun(lua_source);
}