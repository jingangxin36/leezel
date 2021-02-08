#pragma once

#ifdef LZ_PLATFORM_WINDOWS

extern Leezel::Application* Leezel::CreateApplication();

int main(int argc, char* argv[])
{
	auto app = Leezel::CreateApplication();
	app->Run();
	delete app;
}

#endif
