#include <iostream>
#include <string>
#include <optional>
#include "core/activity.hpp"
#include "core/session.hpp"


int main(){
  std::string activity_name;
  long long start_time{};
  long long end_time{};
  
  
  std::cout << "Enter activity name: ";
  getline(std::cin, activity_name);

  std::cout << "Enter start time: ";
  if(std::cin >> start_time)
      {std::cout << "Start time entered: " << start_time << "\n";}else{std::cerr << "Invalid input for start time." << std::endl; return 1;}
  std::cout << "Enter end time: ";
  if(std::cin >> end_time)
      {std::cout << "End time entered: " << end_time << "\n";}else{std::cerr << "Invalid input for end time." << std::endl; return 1;}

  std::optional<Activity> first_activity = Activity::create(activity_name);
  
  if (first_activity.has_value()) {
      std::cout << first_activity.value().get_activity_name() << "\n";
      std::optional<Session> first_session = Session::create(&first_activity.value(), start_time, end_time);
      if (first_session.has_value()) {
        std::cout << "Session created with for the activity: " << first_session.value().get_session_activity() << "\n";
        std::cout << "Session created with duration: " << first_session.value().duration_seconds() << " seconds." << "\n";
        } else {
            std::cout << "Session was not created." << std::endl;
            return 1;
    }

  } else {
      std::cout << "Activity was not created." << std::endl;
      return 1;
  }

  return 0;
}