#ifndef __CL_NODE_3__H
#define __CL_NODE_3__H

#include "cl_base.h"

class cl_node_3 :public cl_base
{
private:
	int my_class_num;
public:
	cl_node_3(cl_base* temp_p_head_obj, string temp_obj_name, int num);// йнмярпйсрнп
	void signal(string& message);// лернд яхцмюкю
	void handler(string& message);// лернд напюанрвхйю
};

#endif
