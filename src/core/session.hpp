

#pragma once 
#include <optional>
#include "activity.hpp"

class Session{
  public:
    static std::optional<Session> create(const Activity* activity, long long start_time, long long end_time);
    long long duration_seconds() const;
    const std::string& get_session_activity() const;
  private:
    Session(const Activity* activity, long long start_time, long long end_time);
    const Activity* m_activity;
    long long m_start_time;
    long long m_end_time;
};

