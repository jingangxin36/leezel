#pragma once
#include "Log.h"

#ifdef LZ_PLATFORM_WINDOWS

extern Leezel::Application* Leezel::CreateApplication();

int main(int argc, char* argv[])
{
	Leezel::Log::Init();
	LOG_INFO("INIT!");
	auto app = Leezel::CreateApplication();
	app->Run();
	delete app;
}

#endif
