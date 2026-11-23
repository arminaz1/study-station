
#pragma once 
#include <string>
#include <optional>

class Activity{
  public:
    static std::optional<Activity> create(std::string name);
    const std::string& get_activity_name() const;
    
  private:
    std::string m_name;
    Activity(std::string name);
};

