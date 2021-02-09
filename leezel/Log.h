#pragma once
#include <spdlog/logger.h>
#include "Core.h"

namespace Leezel{
	class LEEZEL_CORE_API Log
	{
	public:
		static void Init();

		static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return _coreLogger; }
		static std::shared_ptr<spdlog::logger>& GetClientLogger() { return _clientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> _coreLogger;
		static std::shared_ptr<spdlog::logger> _clientLogger;
	};
}

#ifdef LZ_BUILD_DLL
	#define LOG_TRACE(...)	::Leezel::Log::GetCoreLogger()->trace(__VA_ARGS__)
	#define LOG_INFO(...)	::Leezel::Log::GetCoreLogger()->info(__VA_ARGS__)
	#define LOG_WARN(...)	::Leezel::Log::GetCoreLogger()->warn(__VA_ARGS__)
	#define LOG_ERROR(...)	::Leezel::Log::GetCoreLogger()->error(__VA_ARGS__)
	#define LOG_FATAL(...)	::Leezel::Log::GetCoreLogger()->fatal(__VA_ARGS__)
#else
	#define LOG_TRACE(...)	::Leezel::Log::GetClientLogger()->trace(__VA_ARGS__)
	#define LOG_INFO(...)	::Leezel::Log::GetClientLogger()->info(__VA_ARGS__)
	#define LOG_WARN(...)	::Leezel::Log::GetClientLogger()->warn(__VA_ARGS__)
	#define LOG_ERROR(...)	::Leezel::Log::GetClientLogger()->error(__VA_ARGS__)
	#define LOG_FATAL(...)	::Leezel::Log::GetClientLogger()->fatal(__VA_ARGS__)
#endif
