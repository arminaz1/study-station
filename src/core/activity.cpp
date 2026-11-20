#include <string>
#include <optional>
#include "activity.hpp"
const std::string& Activity::get_activity_name() const{
  return m_name;
}

Activity::Activity(std::string name) : m_name{name} {}

std::optional<Activity> Activity::create(std::string name){
  if(name == ""){
    return std::nullopt;
    }
  return Activity(name);
}
