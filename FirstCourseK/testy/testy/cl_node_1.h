#ifndef __CL_NODE_1__H
#define __CL_NODE_1__H

#include "cl_base.h"

class cl_node_1 :public cl_base
{
private:
	int my_class_num;// онке мнпел йкюяяю
public:
	cl_node_1(cl_base* temp_p_head_obj, string temp_obj_name, int num);// йнмярпйсрнп
	void signal(string& message);// лернд яхцмюкю
	void handler(string& message);// лернд напюанрвхйю
};

#endif
