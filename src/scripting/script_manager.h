#define WARNINGOUTPUT(x) std::cerr << x << '\n'

std::string ReadFile() {
    std::ifstream script;
    script.open("scripts/script.lua");

    std::stringstream sstream;
    sstream << script.rdbuf();
    script.close();

    return sstream.str();
}

extern "C" {
    static int __perlin_noise(lua_State* L) {

        int n_args = lua_gettop(L);
        if (n_args != 3) {
            WARNINGOUTPUT("must have 3 arguments");
            return -1;
        }
        for (int i = 0; i < 3; i++) {
            if (!lua_isnumber(L, i+1)) {
                WARNINGOUTPUT("argument at position: " + std::to_string(i+1) + " is not a number");
                return -1;
            }
        }

        int x = lua_tonumber(L, 1), 
            y = lua_tonumber(L, 2), 
            z = lua_tonumber(L, 3);

        lua_pushnumber(L, 100);
        return 1;
    }
}

std::shared_ptr<LuaCpp::Registry::LuaLibrary> MakeMathLib() {
    std::shared_ptr<LuaCpp::Registry::LuaLibrary> library = std::make_shared<LuaCpp::Registry::LuaLibrary>("Math");
    library->AddCFunction("PerlinNoise", __perlin_noise);
    return library;
}