#include <iostream>
#include <string>
#include <optional>
#include "core/activity.hpp"
#include "core/session.hpp"
#include "core/session_line.hpp"

bool test_T2_1(const std::string& line, std::deque<Activity>& activities);

int main(){

  std::deque<Activity> list_activities;
  std::deque<Activity>& list_of_activities = list_activities;
  std::optional<Activity> reading = Activity::create("Reading");
  list_of_activities.push_back(reading.value());
  
  std::cout << "\t\t\tActivity: -> "<< list_of_activities.back().get_activity_name() << "\n";
  
  const std::string& line_sample = "Reading,0,1500";
  
  bool t2_1_1 = (test_T2_1(line_sample, list_of_activities));
  
  list_of_activities.pop_back();
  
  bool t2_1_2 = (test_T2_1(line_sample,list_of_activities));
  if( t2_1_1 && t2_1_2){
    std::cout<< "\n\t\t\ttest_T2_1: ->  " << std::boolalpha << t2_1_1 
             << "\n\t\t\ttest_T2_2: -> "<< std::boolalpha << t2_1_2 
             << "\n"
             <<"\t\t\t T2-1 Passed line \"Reading,0,1500\" created the Session\n";
      }else{
    std::cout<< "\t\t\t T2-1 Failed line \"Reading,0,1500\" created the Session\n\t\t\t" << "test_T2_1: ->  " << std::boolalpha << t2_1_1 << "\n\t\t\ttest_T2_2: -> "<< std::boolalpha << t2_1_2 << "\n";
      };

  return 0;
}