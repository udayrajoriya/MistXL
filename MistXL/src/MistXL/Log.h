#pragma once

#include <memory>
#include "Core.h"
#include "spdlog/spdlog.h"

namespace MistXL
{
	class MISTXL_API Log
	{
		private:
			static std::shared_ptr<spdlog::logger> s_CoreLogger;
			static std::shared_ptr<spdlog::logger> s_ClientLogger;

		public:
			static void Init();

			inline static std::shared_ptr<spdlog::logger>& GetCoreLogger()
			{
				return s_CoreLogger;
			}
			inline static std::shared_ptr<spdlog::logger>& GetClientLogger()
			{
				return s_ClientLogger;
			}

	
	};
}

//Core Log Macros
#define MXL_CORE_TRACE(...)    ::MistXL::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define MXL_CORE_INFO(...)     ::MistXL::Log::GetCoreLogger()->info(__VA_ARGS__)
#define MXL_CORE_WARN(...)     ::MistXL::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define MXL_CORE_ERROR(...)    ::MistXL::Log::GetCoreLogger()->error(__VA_ARGS__)
#define MXL_CORE_FATAL(...)    ::MistXL::Log::GetCoreLogger()->fatal(__VA_ARGS__)

//Client Log Macros
#define MXL_TRACE(...)         ::MistXL::Log::GetClientLogger()->trace(__VA_ARGS__)
#define MXL_INFO(...)          ::MistXL::Log::GetClientLogger()->info(__VA_ARGS__)
#define MXL_WARN(...)          ::MistXL::Log::GetClientLogger()->warn(__VA_ARGS__)
#define MXL_ERROR(...)         ::MistXL::Log::GetClientLogger()->error(__VA_ARGS__)
#define MXL_FATAL(...)         ::MistXL::Log::GetClientLogger()->fatal(__VA_ARGS__)

/*
//If Release Build
#define MXL_CORE_INFO
*/