#ifndef __CL_NODE_1__H
#define __CL_NODE_1__H

#include "cl_base.h"

class cl_node_1 :public cl_base
{
private:
	int my_class_num;// ���� ����� ������
public:
	cl_node_1(cl_base* temp_p_head_obj, string temp_obj_name, int num);// �����������
	void signal(string& message);// ����� �������
	void handler(string& message);// ����� �����������
};

#endif
