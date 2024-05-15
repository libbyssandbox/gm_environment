#include <GarrysMod/Lua/Interface.h>

LUA_FUNCTION(GetEnvironmentVariable)
{
	const char* varName = LUA->CheckString(1);

	LUA->PushString(getenv(varName));

	return 1;
}

GMOD_MODULE_OPEN()
{
	LUA->PushSpecial(GarrysMod::Lua::SPECIAL_GLOB);
	{
		LUA->PushString("GetEnvironmentVariable");
		LUA->PushCFunction(GetEnvironmentVariable);
		LUA->RawSet(-3);
	}
	LUA->Pop();

	return 0;
}

GMOD_MODULE_CLOSE()
{
	LUA->PushSpecial(GarrysMod::Lua::SPECIAL_GLOB);
	{
		LUA->PushString("GetEnvironmentVariable");
		LUA->PushNil();
		LUA->RawSet(-3);
	}
	LUA->Pop();

	return 0;
}