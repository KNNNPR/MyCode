
#include "cl_application.h"

int main()
{
	cl_application obj(nullptr, 1);
	obj.build_tree_obj();
	obj.exec_app();
}