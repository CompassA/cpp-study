#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/sinks/daily_file_sink.h>
#include <spdlog/spdlog.h>

std::shared_ptr<spdlog::logger> console_logger = spdlog::stdout_color_mt("console");    
std::shared_ptr<spdlog::logger> err_logger = spdlog::stderr_color_mt("stderr");   
std::shared_ptr<spdlog::logger> daily_basic_logger = spdlog::daily_logger_mt("daily_logger", "logs/basic-daily.txt", 0, 0);
std::shared_ptr<spdlog::logger> basic_logger = spdlog::basic_logger_mt("basic_logger", "logs/basic-log.txt");