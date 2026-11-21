#include <iostream>
#include <optional>
#include "core/activity.hpp"
#include "core/session.hpp"

// Non-fatal check: records a failure and keeps running,
// so one run reports every broken expectation.
int failures = 0;

void check(bool condition, const char* message) {
    if (!condition) {
        std::cout << "FAILED: " << message << "\n";
        ++failures;
    }
}

int main() {
    // T1: create("Reading") stores the name
    std::optional<Activity> reading = Activity::create("Reading");
    check(reading.has_value(), "T1: create(\"Reading\") returns a value");
    if (reading.has_value()) {
        check(reading.value().get_activity_name() == "Reading",
              "T1: name is \"Reading\"");
        // Deliberate failure, uncomment to see it:
        // check(reading.value().get_activity_name() == "Writing", "T1: failure example");
    }

    // T2: create("") is rejected
    std::optional<Activity> empty = Activity::create("");
    check(!empty.has_value(), "T2: create(\"\") returns nothing");
    // Deliberate failure, uncomment to see it:
    // check(empty.has_value(), "T2: failure example");

    // T3: a session from 0 to 1500 has the activity name and duration 1500
    // reading is valid (T1 checks it), so taking its address is safe here
    std::optional<Session> reading_session = Session::create(&reading.value(), 0, 1500);
    check(reading_session.has_value(), "T3: session created");
    if (reading_session.has_value()) {
        check(reading_session.value().get_session_activity() == "Reading",
            "T3 & T8: activity name is \"Reading\"");
        check(reading_session.value().duration_seconds() == 1500,
              "T3 & T8: duration is 1500");
    }

    // T4: start equal to end is accepted, duration is 0
    std::optional<Activity> writing = Activity::create("Writing");
    std::optional<Session> writing_session = Session::create(&writing.value(), 600, 600);
    check(writing_session.has_value(), "T4: start == end is accepted");
    if (writing_session.has_value()) {
        check(writing_session.value().get_session_activity() == "Writing",
              "T4: activity name is \"Writing\"");
        check(writing_session.value().duration_seconds() == 0,
              "T4: duration is 0");
    }

    // T5: start after end is rejected
    std::optional<Session> bad_session = Session::create(&writing.value(), 900, 600);
    check(!bad_session.has_value(), "T5: start 900 after end 600 is rejected");

    std::optional<Session> bad_session2 = Session::create(&writing.value(), -1, 10);
    check(!bad_session2.has_value(), "T6: start -1 after end 600 is rejected");

    std::optional<Session> start_end_zero_duration_session = Session::create(&writing.value(), 0, 0);
        if (start_end_zero_duration_session.has_value()) {
            check(start_end_zero_duration_session.value().duration_seconds() == 0, "T7: Session with start and end at 0 has value duration 0");
        }
  

    std::optional<Session> one_day_Reading_session = Session::create(&reading.value(), 0, 86400);
    check(one_day_Reading_session.has_value(), "T8: one-day Reading session created");
    if (one_day_Reading_session.has_value()) {
        check(one_day_Reading_session.value().get_session_activity() == "Reading",
            "T9: activity name is \"Reading\"");
        check(one_day_Reading_session.value().duration_seconds() == 86400,
              "T9: duration is 86400");
    }
    
    
    std::cout << "failures: " << failures << "\n";
    if (failures == 0) {
        std::cout << "\t\t\tAll tests passed!\n";
        std::cout << "verify that -> T10 | Run T1 to T9 under sanitizer build executed with no sanitizer output\n";
    } else {
        std::cout << failures << " test(s) failed.\n";
    }
    return failures == 0 ? 0 : 1;
}