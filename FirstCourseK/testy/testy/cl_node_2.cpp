#include "cl_node_2.h"

cl_node_2::cl_node_2(cl_base* temp_p_head_obj, string temp_obj_name, int num) :cl_base(temp_p_head_obj, num, temp_obj_name)
{// �����������
}
void cl_node_2::signal(string& message)
{
	std::cout << "Signal from " << get_path();// ����� �������
	message += " (class: 3)";
}
void cl_node_2::handler(string& message)
{
	std::cout << "Signal to " << get_path() << " Text:  " << message;// ����� �����������
}
