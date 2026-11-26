// #include <iostream>
// #include <string>
// #include <optional>
// #include "core/activity.hpp"
// #include "core/session.hpp"
// #include "core/session_line.hpp"

// bool test_T2_1(const std::string& line, std::deque<Activity>& activities);
// bool test_T2_2(const Session& session);
// bool test_T2_3_7(const std::string& line, std::deque<Activity>& activities);

// int main(){

//   std::deque<Activity> list_activities;
//   std::deque<Activity>& list_of_activities = list_activities;
//   std::optional<Activity> reading = Activity::create("Reading");

//   list_of_activities.push_back(reading.value());
  
//   std::cout << "\n\t\t\t{Action} Activity created:Activity: -> "<< list_of_activities.back().get_activity_name() << "\n\n";
  
//   const std::string& line_sample = "Reading,0,1500";
 
 
//   // #Test T2-1: line_to_session() with existing activity
//   std::cout << "\t\t\tTest T2-1-1: line_to_session() with existing activity\n";
//   bool t2_1_1 = (test_T2_1(line_sample, list_of_activities));
  
  
//   // #Test T2-1: line_to_session() with new activity
//   if(list_of_activities.size() != 0){
//     std::cout << "\n\t\t\t{Action} Delete Activity created: Activity: -> "<< list_of_activities.back().get_activity_name() << "\n\n";
//     list_of_activities.pop_back();
//   }
//   if(list_of_activities.size() == 0){
//     std::cout << "\n\t\t\t{Check}: No Activity in the list of activities size: -> "<< list_of_activities.size() << "\n\n";
//   }
//   std::cout << "\t\t\tTest T2-1-2: line_to_session() with new activity\n";
//   bool t2_1_2 = (test_T2_1(line_sample,list_of_activities));


//   // #Test T2-2: session_to_line()
//   if(list_of_activities.size() != 0){
//     for (const auto& activity_iter : list_of_activities) {
//         std::cout << "\n\t\t\t list of activities names: -> " << activity_iter.get_activity_name() << "\n";
//     }
//     std::cout << "\n\t\t\t{Action} Delete Activity created: Activity: -> "<< list_of_activities.back().get_activity_name() << "\n\n";
//     list_of_activities.pop_back();
//   }
//   bool t2_2_1 = false;
//   if(list_of_activities.size() == 0){
//     std::cout << "\n\t\t\t{Check}: No Activity in the list of activities size: -> "<< list_of_activities.size() << "\n\n";
//     reading = Activity::create("Reading");
//     list_of_activities.push_back(reading.value());
//     std::cout << "\n\t\t\t{Action} Activity created:Activity: -> "<< list_of_activities.back().get_activity_name() << "\n\n";
//     std::optional<Session> test_session = Session::create(&reading.value(), 0, 1500);
//     std::cout << "\n\t\t\t{Action} Session created: -> "<< "\""<< test_session.value().get_session_activity() << "\"," << test_session.value().get_start_time_seconds() << "," << test_session.value().get_end_time_seconds() << "\"" << "\n\n";
//     std::cout << "\t\t\tTest T2-2-1: session_to_line()\n";
//     t2_2_1 = test_T2_2(test_session.value());
//   }
  

//   //Test T2-3: line_to_session() with missing field (invalid line)
//   if(list_of_activities.size() != 0){
//     std::cout << "\n\t\t\t{Action} Delete Activity created: Activity: -> "<< list_of_activities.back().get_activity_name() << "\n\n";
//     list_of_activities.pop_back();
//   }
//   if(list_of_activities.size() == 0){
//     std::cout << "\n\t\t\t{Check}: No Activity in the list of activities size: -> "<< list_of_activities.size() << "\n\n";}

//   const std::string& line_sample_3 = "Reading,0,";
//   std::cout << "\t\t\tTest T2-3: line_to_session() with missing field (invalid line)\n";
//   bool t2_3_1 = (test_T2_3_7(line_sample_3, list_of_activities));
  
//   if(list_of_activities.size() == 0){
//     std::cout << "\n\t\t\t{Check}: No Activity created list of activities size: -> "<< list_of_activities.size() << "\n\n";
  
//   } else {
//     t2_3_1 = false;
//   }

//   //Test T2-4: line_to_session() with wrong format (invalid line)
//   const std::string& line_sample_4 = "Reading,abc,10";
//   std::cout << "\t\t\tTest T2-4: line_to_session() with wrong format (invalid line)\n";
//   bool t2_4_1 = (test_T2_3_7(line_sample_4, list_of_activities));

//   if(list_of_activities.size() == 0){
//     std::cout << "\n\t\t\t{Check}: No Activity created list of activities size: -> "<< list_of_activities.size() << "\n\n";
//   }else {
//     t2_4_1 = false;
//   }
//   //Test T2-5: line_to_session() with missing field (invalid line)
//   const std::string& line_sample_5 = ",0,10";
//   std::cout << "\t\t\tTest T2-5: line_to_session() with missing field (invalid line)\n";
//   bool t2_5_1 = (test_T2_3_7(line_sample_5, list_of_activities));
//     if(list_of_activities.size() == 0){
//     std::cout << "\n\t\t\t{Check}: No Activity created list of activities size: -> "<< list_of_activities.size() << "\n\n";
//   }else {
//     t2_5_1 = false;
//   }
//   //Test T2-6: line_to_session() with end time before start time (invalid line)
//   const std::string& line_sample_6 = "Reading,900,600";
//   std::cout << "\t\t\tTest T2-6: line_to_session() with end time before start time (invalid line)\n";
//   bool t2_6_1 = (test_T2_3_7(line_sample_6, list_of_activities));
//       if(list_of_activities.size() == 0){
//     std::cout << "\n\t\t\t{Check}: No Activity created list of activities size: -> "<< list_of_activities.size() << "\n\n";
//   }else {
//     t2_6_1 = false;
//   }
//   //Test T2-7: line_to_session() with negative time values (invalid line)
//   const std::string& line_sample_7 = "Reading,-1,10";
//   std::cout << "\t\t\tTest T2-7: line_to_session() with negative time values (invalid line)\n";
//   bool t2_7_1 = (test_T2_3_7(line_sample_7, list_of_activities));
//       if(list_of_activities.size() == 0){
//     std::cout << "\n\t\t\t{Check}: No Activity created list of activities size: -> "<< list_of_activities.size() << "\n\n";
//   }else {
//     t2_7_1 = false;
//   }
/////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////
//     std::cout <<  "\t\t\t|----------------------------------------|\n"
//               <<  "\t\t\t|              TEST SUMMARY              |\n"
//               <<  "\t\t\t|----------------------------------------|\n"
//               <<  "\n\t\t\tTEST RESULT: ->  " << std::boolalpha << ((t2_1_1 && t2_1_2 && t2_2_1 && t2_3_1 && t2_4_1 && t2_5_1 && t2_6_1 && t2_7_1) ? "Passed" : "Failed");

//     std::cout <<  "\n\t\t\ttest_T2_1_1: ->  " << std::boolalpha << (t2_1_1 ? "Passed" : "Failed") 
//               <<  "\n\t\t\ttest_T2_1_2: ->  " << std::boolalpha << (t2_1_2 ? "Passed" : "Failed")
//               <<  "\n\t\t\ttest_T2_2_1: ->  " << std::boolalpha << (t2_2_1 ? "Passed" : "Failed")
//               <<  "\n\t\t\ttest_T2_3_1: ->  " << std::boolalpha << (t2_3_1 ? "Passed" : "Failed")
//               <<  "\n\t\t\ttest_T2_4_1: ->  " << std::boolalpha << (t2_4_1 ? "Passed" : "Failed")
//               <<  "\n\t\t\ttest_T2_5_1: ->  " << std::boolalpha << (t2_5_1 ? "Passed" : "Failed")
//               <<  "\n\t\t\ttest_T2_6_1: ->  " << std::boolalpha << (t2_6_1 ? "Passed" : "Failed")
//               <<  "\n\t\t\ttest_T2_7_1: ->  " << std::boolalpha << (t2_7_1 ? "Passed" : "Failed")
//               <<  "\n";
//   return 0;
// }



#include <deque>
#include <iostream>
#include <optional>
#include <string>
#include "core/activity.hpp"
#include "core/session.hpp"
#include "core/session_line.hpp"

bool test_T2_1(const std::string& line, std::deque<Activity>& activities);
bool test_T2_2(const Session& session);
bool test_T2_3_7(const std::string& line, std::deque<Activity>& activities);

int main() {
    int failures = 0;

    // T2-1: valid line, Activity already in the deque
    std::deque<Activity> with_activity;
    with_activity.push_back(Activity::create("Reading").value());
    bool t2_1_existing = test_T2_1("Reading,0,1500", with_activity);
    std::cout << "T2-1 (Activity exists): " << (t2_1_existing ? "PASS" : "FAIL") << "\n";
    if (!t2_1_existing) ++failures;

    // T2-1: valid line, no Activity in the deque yet
    std::deque<Activity> without_activity;
    bool t2_1_new = test_T2_1("Reading,0,1500", without_activity);
    std::cout << "T2-1 (Activity is new): " << (t2_1_new ? "PASS" : "FAIL") << "\n";
    if (!t2_1_new) ++failures;

    // T2-2: session_to_line
    std::optional<Activity> reading = Activity::create("Reading");
    std::optional<Session> session = Session::create(&reading.value(), 0, 1500);
    bool t2_2 = test_T2_2(session.value());
    std::cout << "T2-2: " << (t2_2 ? "PASS" : "FAIL") << "\n";
    if (!t2_2) ++failures;

    // T2-3 to T2-7: invalid lines, each with a fresh deque
    const std::string invalid_lines[] = {"Reading,0,", "Reading,abc,10", ",0,10", "Reading,900,600", "Reading,-1,10"};
    const char* invalid_ids[] = {"T2-3", "T2-4", "T2-5", "T2-6", "T2-7"};
    for (int i = 0; i < 5; ++i) {
        std::deque<Activity> activities;
        bool passed = test_T2_3_7(invalid_lines[i], activities);
        std::cout << invalid_ids[i] << ": " << (passed ? "PASS" : "FAIL") << "\n";
        if (!passed) ++failures;
    }

    std::cout << (failures == 0 ? "All T2-1 to T2-7 passed\n" : "Some tests failed\n");
    return failures == 0 ? 0 : 1;
}