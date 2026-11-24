#pragma once
#include <deque>
#include <string>
#include <optional>
#include "activity.hpp"
#include "session.hpp"

std::optional<Session> line_to_session(const std::string& line, const std::deque<Activity>& activities);
std::string session_to_line(const Session& session);