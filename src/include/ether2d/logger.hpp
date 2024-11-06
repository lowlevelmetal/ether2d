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
	void Debug(const std::string &fmt, Args... args) noexcept {
		m_logger->debug(fmt, args...);
	}
	
	template<typename... Args>	
	void Info(const std::string &fmt, Args... args) noexcept {
		m_logger->info(fmt, args...);
	}
	
	template<typename... Args>	
	void Warn(const std::string &fmt, Args... args) noexcept {
		m_logger->warn(fmt, args...);
	}
	
	template<typename... Args>	
	void Error(const std::string &fmt, Args... args) noexcept {
		m_logger->error(fmt, args...);
	}

private:
	Logger();

	static std::string m_log_file; 

	std::shared_ptr<spdlog::sinks::stdout_color_sink_mt> m_console_sink;
	std::shared_ptr<spdlog::sinks::rotating_file_sink_mt> m_file_sink;
	std::shared_ptr<spdlog::logger> m_logger;
};

}
