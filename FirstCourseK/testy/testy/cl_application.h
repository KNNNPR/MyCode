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
	cl_application(cl_base* temp_p_head_obj, int num);// йнмярпсйрнп йнпмебнцн тюикю
	void build_tree_obj(); // лернд онярпнемхъ дпебю хепюпухх
	void work_with_commands();// лернд времхъ х напюанрйх йнлюмд
	int exec_app(); // хяонкмъелши лернд, йнрнпши бшонкмъер пюанрс
	TYPE_SIGNAL get_signal(cl_base* obj);// лернд бнгбпюыюер сйюгюрекэ мю мсфмши лернд яхцмюкю
	TYPE_HANDLER get_handler(cl_base* obj);// лернд бнгбпюыюер сйюгюрекэ мю мсфмши лернд напюанрвхйю
	void signal(string& message);// лернд яхцмюкю
	void handler(string& message);// лернд напюанрвхйю
};

#endif
