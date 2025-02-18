#ifndef PROJECT_HELPERS_DEADLINE_TIMER_HPP
#define PROJECT_HELPERS_DEADLINE_TIMER_HPP

#include <chrono>
#include <string>

namespace project::helpers {

class deadline_timer final
{
public:
    explicit deadline_timer(const std::string &task_name) noexcept;
    deadline_timer(const deadline_timer &) = delete;
    deadline_timer(deadline_timer &&) = delete;
    deadline_timer &operator=(const deadline_timer &) = delete;
    deadline_timer &operator=(deadline_timer &&) = delete;
    ~deadline_timer() noexcept;

private:
    const std::string task_name_;
    const std::chrono::steady_clock::time_point start_time_;
};

}

#endif
