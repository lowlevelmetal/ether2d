/**
 * ether2d
 *
 * Matthew Todd Geiger
 * Nov 4 2024
 *
 * logger.cpp
 */

// Standard C++ includes
#include <filesystem>

// Local includes
#include "ether2d/logger.hpp"

namespace ether2d::logging {

Logger& Logger::Get() {
	static Logger logger;
	return logger;
}

Logger::Logger() {
	m_console_sink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
	m_console_sink->set_level(spdlog::level::debug);
	m_console_sink->set_pattern("[%^%l%$] %v");

	m_file_sink = std::make_shared<spdlog::sinks::rotating_file_sink_mt>(
			std::filesystem::temp_directory_path() / "ether2d.log", 1024 * 1024 * 5, 3); // the / operator correctly handles the concatenation and is portable across different operating systems.
	m_file_sink->set_level(spdlog::level::trace);
	m_file_sink->set_pattern("[%Y-%m-%d %H:%M:%S] [%l] %v");

	spdlog::sinks_init_list sink_list = {m_console_sink, m_file_sink};
	m_logger = std::make_shared<spdlog::logger>("multi_sink_logger", sink_list);

#ifdef _DEBUG
	m_logger->set_level(spdlog::level::debug);
#endif
}

} // namespace ether2d::logging
