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
            "T3: activity name is \"Reading\"");
        check(reading_session.value().duration_seconds() == 1500,
              "T3: duration is 1500");
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

    std::cout << "failures: " << failures << "\n";
    return failures == 0 ? 0 : 1;
}