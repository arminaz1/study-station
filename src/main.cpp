#include <iostream>
#include <string>
#include <optional>
#include "core/activity.hpp"
#include "core/session.hpp"

int main(){
  std::optional<Activity> first_activity = Activity::create("Reading");
  
  if (first_activity.has_value()) {
      std::cout << first_activity.value().get_activity_name() << std::endl;
      std::optional<Session> first_session = Session::create(&first_activity.value(), 0, 3600);
      if (first_session.has_value()) {
        std::cout << "Session created with for the activity: " << first_session.value().get_session_activity() << std::endl;
        std::cout << "Session created with duration: " << first_session.value().duration_seconds() << " seconds." << std::endl;
        } else {
            std::cout << "Session was not created." << std::endl;
    }

  } else {
      std::cout << "Activity was not created." << std::endl;
  }

  return 0;
}