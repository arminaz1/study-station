#include <iostream>
#include <deque>
#include <optional>
#include <string>
#include "core/activity.hpp"
#include "core/session.hpp"
#include "core/session_line.hpp"

bool test_T2_3_7(const std::string& line, std::deque<Activity>& activities) {
    std::optional<Session> result = line_to_session(line, activities);
    // const Session& session = result.value();
    if (!result.has_value()) {
        return true;
    }
    return false;
}