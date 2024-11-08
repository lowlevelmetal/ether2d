/**
 * ether2d
 *
 * Matthew Todd Geiger
 * Nov 4 2024
 *
 * logger.hpp
 */

#pragma once

// Standard C++ includes
#include <memory>
#include <string>

// Third party includes
#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/sinks/rotating_file_sink.h>

namespace ether2d::logging {

// Singleton logger
class Logger {
public:
	static Logger& Get();

	template<typename... Args>
	inline void Debug(fmt::format_string<Args...>&& fmt, Args &&...args) const {
		m_logger->debug(fmt, std::forward<Args>(args)...);
	}

	inline void Debug(const char *const msg) const {
		m_logger->debug(msg);
	}
	
	template<typename... Args>	
	inline void Info(fmt::format_string<Args...>&& fmt, Args &&...args) const {
		m_logger->info(fmt, std::forward<Args>(args)...);
	}

	inline void Info(const char *const msg) const {
		m_logger->info(msg);
	}
	
	template<typename... Args>
	inline void Warn(fmt::format_string<Args...>&& fmt, Args &&...args) const {
		m_logger->warn(fmt, std::forward<Args>(args)...);
	}

	inline void Warn(const char *const msg) const {
		m_logger->warn(msg);
	}

	template<typename... Args>	
	inline void Error(fmt::format_string<Args...>&& fmt, Args &&...args) const {
		m_logger->error(fmt, std::forward<Args>(args)...);
	}

	inline void Error(const char *const msg) const {
		m_logger->error(msg);
	}

private:
	Logger();

	std::shared_ptr<spdlog::sinks::stdout_color_sink_mt> m_console_sink;
	std::shared_ptr<spdlog::sinks::rotating_file_sink_mt> m_file_sink;
	std::shared_ptr<spdlog::logger> m_logger;
};

}
