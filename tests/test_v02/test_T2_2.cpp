#include <iostream>
#include <string>
#include "core/activity.hpp"
#include "core/session.hpp"
#include "core/session_line.hpp"

bool test_T2_2(const Session& session){
    std::string result = session_to_line(session);
    if (result.empty()) {
        std::cout << "debug: session_to_line() returned empty string\n";
        return false;
    }
    if (result != "Reading,0,1500") {
        std::cout << "debug: session_to_line() returned unexpected value: " << result << "\n";
        return false;
    }
    return true;
}