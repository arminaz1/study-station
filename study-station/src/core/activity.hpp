
#pragma once 
#include <string>
#include <optional>
class Activity{
  public:
    static std::optional<Activity> create(std::string name);
    std::string  get_activity_name();
    
  private:
    std::string m_name;
    Activity(std::string name);
};

