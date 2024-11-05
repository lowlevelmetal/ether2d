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

	void Debug(const std::string msg);
	void Info(const std::string msg);
	void Warn(const std::string msg);
	void Error(const std::string msg);

private:
	Logger();

	static std::string m_log_file; 

	std::shared_ptr<spdlog::sinks::stdout_color_sink_mt> m_console_sink;
	std::shared_ptr<spdlog::sinks::rotating_file_sink_mt> m_file_sink;
	std::shared_ptr<spdlog::logger> m_logger;
};

}
