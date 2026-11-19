#include <cassert>
#include <iostream>
#include <optional>
#include "core/activity.hpp"

int main() {
    std::cout << "Check T1: create(\"Reading\") stores the name\n";
    std::optional<Activity> reading = Activity::create("Reading");
    assert(reading.has_value());
    assert(reading.value().get_activity_name() == "Reading");
    std::cout << "T1 passed\n";

    std::cout << "Check T2: create(\"\") is rejected\n";
    std::optional<Activity> empty = Activity::create("");
    assert(!empty.has_value());
    std::cout << "T2 passed\n";
    
    
    std::cout << "All checks passed\n";
    return 0;
}