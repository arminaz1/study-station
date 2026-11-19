#include <iostream>
#include <string>
#include <optional>
#include "core/activity.hpp"

int main(){
  std::optional<Activity> first_activity = Activity::create("C++");
  // Check if the box actually has a value before trying to open it
  if (first_activity.has_value()) {
      // Open the box with .value(), then call your function
      std::cout << first_activity.value().get_activity_name() << std::endl;
  } else {
      std::cout << "Activity was not created." << std::endl;
  }
  return 0;
}