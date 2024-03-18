#ifndef __CL_BASE_H
#define __CL_BASE_H

#include <vector>
#include <iostream>

using namespace std;

class cl_base
{
private:
	string obj_name;
	cl_base* p_head_obj;
	vector <cl_base*> sub_obj;
public:
	cl_base(cl_base* user_p_head_obj, string user_obj_name = "Base_object");
	bool set_name(string new_obj_name);
	string get_name();
	cl_base* get_head();
	void print_tree();
	cl_base* find_by_name(string what_name); 
	void add_to_sub(cl_base* time_obj);
};

#endif
