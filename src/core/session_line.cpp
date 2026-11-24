#include <charconv>
#include <deque>
#include <string>
#include <optional>
#include "activity.hpp"
#include "session.hpp"



std::optional<Session> line_to_session(const std::string& line, std::deque<Activity>& activities){
	size_t first_comma;
	size_t second_comma;
	if(line.find(',') != std::string::npos){
		first_comma = line.find(',');
	}else{
			return std::nullopt;
	}
	if(line.find(',', first_comma + 1 ) != std::string::npos){
			second_comma = line.find(',', first_comma + 1 ); 
	}else{
		return std::nullopt;
    }
		std::string activity_name = line.substr(0, first_comma);
		std::string start_time_string = line.substr(first_comma + 1, second_comma - first_comma - 1);
		std::string end_time_string = line.substr(second_comma + 1);

		long long start_time_second{}, end_time_second{};

		auto [ptr1, ec1] = std::from_chars(
                start_time_string.data(),
                start_time_string.data() + start_time_string.size(),
                start_time_second
            );

        auto [ptr2, ec2]  = std::from_chars(
            end_time_string.data(),
            end_time_string.data() + end_time_string.size(),
            end_time_second
        );

        if ((ec1 != std::errc() || ec2 != std::errc() || ptr1 != nullptr|| ptr2 != nullptr)) {
            return std::nullopt;
        }


        const Activity* activity_ptr = nullptr;
        bool new_activity_added = false;
		
		for(const Activity& activity_iter : activities)  {
			if(activity_iter.get_activity_name() == activity_name){
				 activity_ptr = &activity_iter;
			     break;
                }
		}
		
		if(activity_ptr == nullptr){
				new_activity_added = true;
				std::optional<Activity> new_activity = Activity::create(activity_name);
				if(new_activity.has_value()){
					activities.push_back(new_activity.value());
					activity_ptr = &activities.back();
				}else{
					return std::nullopt;
				}					
			}
		std::optional<Session> new_session = Session::create(activity_ptr, start_time_second, end_time_second);
		if(new_session.has_value()){
			return new_session;
		}else if(new_activity_added == true){
			activities.pop_back();
			return std::nullopt;
		}else{
			return std::nullopt;        
        }

}



        

        
std::string session_to_line(const Session& session){
    return session.get_session_activity() + "," + std::to_string(session.get_start_time_seconds()) + "," + std::to_string(session.get_end_time_seconds());
}