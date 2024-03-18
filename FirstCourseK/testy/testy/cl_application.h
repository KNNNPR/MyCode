#ifndef __CL_APPLICATION__H
#define __CL_APPLICATION__H

#include "cl_node_1.h"
#include "cl_node_2.h"
#include "cl_node_3.h"
#include "cl_node_4.h"
#include "cl_node_5.h"

class cl_application :public cl_base
{
public:
	cl_application(cl_base* temp_p_head_obj, int num);// ����������� ��������� �����
	void build_tree_obj(); // ����� ���������� ����� ��������
	void work_with_commands();// ����� ������ � ��������� ������
	int exec_app(); // ����������� �����, ������� ��������� ������
	TYPE_SIGNAL get_signal(cl_base* obj);// ����� ���������� ��������� �� ������ ����� �������
	TYPE_HANDLER get_handler(cl_base* obj);// ����� ���������� ��������� �� ������ ����� �����������
	void signal(string& message);// ����� �������
	void handler(string& message);// ����� �����������
};

#endif
