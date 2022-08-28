LUA_VERSION=5.4
g++ --std=c++17 src/main.cpp -I /usr/local/include/LuaCpp -I /usr/local/include/lua$LUA_VERSION -lluacpp -llua$LUA_VERSION -o scripting-test.out
./scripting-test.out