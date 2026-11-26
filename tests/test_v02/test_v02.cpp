#include <iostream>
#include <string>
#include <optional>
#include "core/activity.hpp"
#include "core/session.hpp"
#include "core/session_line.hpp"

bool test_T2_1(const std::string& line, std::deque<Activity>& activities);
bool test_T2_2(const Session& session);

int main(){

  std::deque<Activity> list_activities;
  std::deque<Activity>& list_of_activities = list_activities;
  std::optional<Activity> reading = Activity::create("Reading");

  list_of_activities.push_back(reading.value());
  
  std::cout << "\n\t\t\t{Action} Activity created:Activity: -> "<< list_of_activities.back().get_activity_name() << "\n\n";
  
  const std::string& line_sample = "Reading,0,1500";
 
 
  // #Test T2-1: line_to_session() with existing activity
  std::cout << "\t\t\tTest T2-1-1: line_to_session() with existing activity\n";
  bool t2_1_1 = (test_T2_1(line_sample, list_of_activities));
  
  
  // #Test T2-1: line_to_session() with new activity
  list_of_activities.pop_back();
  std::cout << "\t\t\tTest T2-1-2: line_to_session() with new activity\n";
  bool t2_1_2 = (test_T2_1(line_sample,list_of_activities));
  
  
  
  // #Test T2-2: session_to_line()

  std::optional<Session> test_session = Session::create(&reading.value(), 0, 1500);
  std::cout << "\n\t\t\t{Action} Session created: -> "<< "\""<< test_session.value().get_session_activity() << "\"," << test_session.value().get_start_time_seconds() << "," << test_session.value().get_end_time_seconds() << "\"" << "\n\n";
  std::cout << "\t\t\tTest T2-2-1: session_to_line()\n";
  bool t2_2_1 = test_T2_2(test_session.value());

    std::cout <<  "\t\t\t|----------------------------------------|\n"
              <<  "\t\t\t|              TEST SUMMARY              |\n"
              <<  "\t\t\t|----------------------------------------|\n"
              <<  "\n\t\t\tTEST RESULT: ->  " << std::boolalpha << (t2_1_1 && t2_1_2 && t2_2_1);
    std::cout <<  "\n\t\t\ttest_T2_1_1: ->  " << std::boolalpha << t2_1_1 
              <<  "\n\t\t\ttest_T2_1_2: ->  " << std::boolalpha << t2_1_2 
              <<  "\n\t\t\ttest_T2_2_1: ->  " << std::boolalpha << t2_2_1
              <<  "\n";
  return 0;
}
