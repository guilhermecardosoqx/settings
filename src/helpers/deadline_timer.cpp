#include "helpers/deadline_timer.hpp"

#include <spdlog/spdlog.h>

namespace project::helpers {

deadline_timer::deadline_timer(const std::string &task_name) noexcept :
    task_name_(task_name),
    start_time_(std::chrono::steady_clock::now())
{
    spdlog::info("start {}", task_name_);
}

deadline_timer::~deadline_timer() noexcept
{
    auto end_time = std::chrono::steady_clock::now();
    auto elapsed_time = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time_);

    auto hours = std::chrono::duration_cast<std::chrono::hours>(elapsed_time);
    elapsed_time -= hours;
    auto minutes = std::chrono::duration_cast<std::chrono::minutes>(elapsed_time);
    elapsed_time -= minutes;
    auto seconds = std::chrono::duration_cast<std::chrono::seconds>(elapsed_time);
    elapsed_time -= seconds;

    spdlog::info("{} took {:02}:{:02}:{:02}.{:03}",
        task_name_,
        hours.count(),
        minutes.count(),
        seconds.count(),
        elapsed_time.count());
}

}
