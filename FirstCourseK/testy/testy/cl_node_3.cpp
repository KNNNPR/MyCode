#include "cl_node_3.h"

cl_node_3::cl_node_3(cl_base* temp_p_head_obj, string temp_obj_name, int num) :cl_base(temp_p_head_obj, num, temp_obj_name)
{//  ŒÕ—“–” “Œ–
}
void cl_node_3::signal(string& message)
{
	std::cout << "Signal from " << get_path();// Ã≈“Œƒ —»√Õ¿À¿
	message += " (class: 4)";
}
void cl_node_3::handler(string& message)
{
	std::cout << "Signal to " << get_path() << " Text:  " << message;// Ã≈“Œƒ Œ¡–¿¡Œ“◊» ¿
}

