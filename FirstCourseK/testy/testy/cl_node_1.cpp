#include "cl_node_1.h"

cl_node_1::cl_node_1(cl_base* temp_p_head_obj, string temp_obj_name, int num) :cl_base(temp_p_head_obj, num, temp_obj_name)
{// �����������
}
void cl_node_1::signal(string& message)
{
	std::cout << "Signal from " << get_path();// ����� �������
	message += " (class: 2)";
}
void cl_node_1::handler(string& message)
{
	std::cout << "Signal to " << get_path() << " Text:  " << message;// ����� �����������
}

