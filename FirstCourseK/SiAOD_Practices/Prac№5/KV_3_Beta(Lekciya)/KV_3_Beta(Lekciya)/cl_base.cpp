#include "cl_base.h"

cl_base::cl_base(cl_base* user_p_head_obj, string user_obj_name)
{
	p_head_obj == user_p_head_obj;
	if (set_name(user_obj_name))
	{
		if (p_head_obj != nullptr)
		{
			p_head_obj->add_to_sub(this);
		}
	}
	else
	{
		p_head_obj = nullptr;
	}
}
//=========================================================
bool cl_base::set_name(string new_obj_name)
{

}
