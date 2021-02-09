#include "Log.h"
#include <spdlog/logger.h>
#include <spdlog/sinks/stdout_color_sinks.h>

namespace Leezel
{
	std::shared_ptr<spdlog::logger> Log::_coreLogger;
	std::shared_ptr<spdlog::logger> Log::_clientLogger;

	void Log::Init()
	{
		_coreLogger = spdlog::stdout_color_mt("LEEZEL");
		_coreLogger->set_level(spdlog::level::trace);
		_coreLogger->set_pattern("%^[%T] %n: %v%$");

		_clientLogger = spdlog::stdout_color_mt("APP");
		_clientLogger->set_level(spdlog::level::trace);
		_clientLogger->set_pattern("%^[%T] %n: %v%$");

	}
}

