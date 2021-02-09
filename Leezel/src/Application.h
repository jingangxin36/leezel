#pragma once
#include "Core.h"

namespace Leezel
{
	class LEEZEL_CORE_API Application
	{
	public:
		Application() = default;
		virtual  ~Application() = default;

		void Run();
	};

	Application* CreateApplication();
}


