#include <iostream>
#include <deque>
#include <optional>
#include <string>
#include "core/activity.hpp"
#include "core/session.hpp"
#include "core/session_line.hpp"

bool test_T2_1(const std::string& line, std::deque<Activity>& activities) {
    std::optional<Session> result = line_to_session(line, activities);
    if (!result.has_value()) {
        std::cout << "debug: sesision has_value() -> " << result.has_value() << "\n";
        return false;
    }
    const Session& session = result.value();
    if (session.get_session_activity() != "Reading") {
        std::cout<<"debug: session.get_session_activity()  " << session.get_session_activity() << "\n";
        return false;
    }
    if (session.get_start_time_seconds() != 0) {
        std::cout<<"debug: session.get_start_time_seconds()  " << session.get_start_time_seconds() << "\n";
        return false;
    }
    if (session.get_end_time_seconds() != 1500) {
        std::cout<<"debug: session.get_end_time_seconds()  " << session.get_end_time_seconds() << "\n";
        return false;
    }
    return true;
}