
#include <optional>
#include "session.hpp"
#include "activity.hpp"


Session::Session(const Activity* activity, long long start_time, long long end_time) : m_activity{activity}, m_start_time{start_time}, m_end_time{end_time} {}

const std::string& Session::get_session_activity() const{
  return m_activity ->get_activity_name();
}

long long Session:: duration_seconds() const{
  return m_end_time - m_start_time;
}

std::optional<Session> Session::create(const Activity* activity, long long start_time, long long end_time){
  if(start_time > end_time || start_time < 0){
    return std::nullopt;
  }
  return Session(activity, start_time, end_time);
}