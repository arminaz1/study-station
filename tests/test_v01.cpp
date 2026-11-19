#include <cassert>
#include <iostream>
#include <optional>
#include "core/activity.hpp"

int main(){
    std::cout << "\n\n\nCheck test Activity::create(\"Reading\") store the value correctly\n";
    assert(Activity::create("Reading").has_value() && Activity::create("Reading")->get_activity_name() == "Reading" && Activity::create("Reading").value().get_activity_name() == "Reading");
    std::cout << "first check passed\n";
    std::cout << "Check test Activity::create(\"\") is invalid\n";
    assert(!Activity::create("").has_value());
    std::cout << "second check passed\n";

    std::cout << "\n\nT1, T2, Tests passed!\n";

    return 0;
}