#include "helpers/deadline_timer.hpp"
#include <cstdlib>
#include <memory>
#include <spdlog/sinks/daily_file_sink.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/spdlog.h>

int main()
{
    spdlog::set_default_logger(std::make_shared<spdlog::logger>("logger", spdlog::sinks_init_list{
        std::make_shared<spdlog::sinks::stdout_color_sink_mt>(),
        std::make_shared<spdlog::sinks::daily_file_format_sink_mt>("logs/project_logger.log", 0, 0)}));

    spdlog::info("project version {}", "2025.1");

    project::helpers::deadline_timer deadline_timer{"project"};

    return EXIT_SUCCESS;
}
