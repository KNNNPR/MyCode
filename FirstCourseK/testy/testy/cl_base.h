#ifndef __CL_BASE__H
#define __CL_BASE__H

#include <vector>
#include <iostream>

class cl_base;

using namespace std;

typedef void (cl_base ::* TYPE_SIGNAL) (string&);
typedef void (cl_base ::* TYPE_HANDLER) (string&);

#define SIGNAL_D( signal_f ) ( TYPE_SIGNAL ) ( & signal_f )
#define HENDLER_D( hendler_f ) ( TYPE_HANDLER ) ( & hendler_f )

struct o_sh                 // яРПСЙРСПЮ ГЮДЮМХЪ НДМНИ ЯБЪГХ
{
	TYPE_SIGNAL  p_signal;    // сЙЮГЮРЕКЭ МЮ ЛЕРНД ЯХЦМЮКЮ
	cl_base* p_cl_base;   	// сЙЮГЮРЕКЭ МЮ ЖЕКЕБНИ НАЗЕЙР
	TYPE_HANDLER p_hendler;   // сЙЮГЮРЕКЭ МЮ ЛЕРНД НАПЮАНРВХЙЮ
};

class cl_base
{
private:
	string obj_name;// онке хлъ назейрю
	cl_base* p_head_obj;// онке сйюгюрекэ мю цнкнбмни назейр
	vector <cl_base* > sub_obj;// бейрнп ондвхмеммшу назейрнб
	vector < o_sh* > connects;// бейрнп янедхмемхи 
	int ready;// онке цнрнбмнярх назейрю
	int my_class_num;
public:
	cl_base(cl_base* user_p_head_obj, int num, string user_obj_name = "Base_object");// йнмярпсйрнп
	bool set_name(string new_obj_name);// лернд сярюмнбйх хлемх
	string get_name();// церреп хлемх назейрю
	cl_base* get_head();// церреп сйюгюрекъ мю цнкнбмни назейрю 
	void print_tree(int tabs);// лернд бшбндю дпебю хепюпухх мю щйпюм
	void add_to_sub(cl_base* time_obj);// лернд днаюбкемхъ назейрю б бейрнп ондяхмеммшу 

	//NEW_KV_2//
	cl_base* get_root();// лернд мюунфдемхъ сйюгюрекъ мю цнкнбмни назейр
	cl_base* find_by_name_curr(string what_name);// лернд онхяйю назейрю он хлемх нр рейсыецн
	cl_base* find_by_name_root(string what_name);// лернд онхяйю назейрю он хлемх нр йнпмебнцн назейрю (бн бяел депебе)
	void set_ready(int user_set);// яерреп цнрнбмнярх назейрю
	bool is_ready();// лернд опнбепйх цнрнбмнярх назейрю

	//NEW_KV_3//
	cl_base* find_by_name_sub(string what_name);// лернд онхяйю назейрю он хлемх япедх меоняпедярбеммн ондвхмеммшу
	cl_base* find_by_path(string path);// лернд мюунфдемхъ назейрю он осрх
	int repeate_obj_name(string name);// лернд явхрючыхи назейрш я ндхмюйнбшл хлемел
	//NEW_KV_4//
	void set_connection(cl_base* adress, TYPE_SIGNAL elster, TYPE_HANDLER falke);// лернд мюкюфхбюмхъ ябъгеи лефдс назейрюлх
	void delete_connection(TYPE_SIGNAL elster, TYPE_HANDLER falke, cl_base* adress);// лернд сдюкемхъ ябъгх
	void give_signal(TYPE_SIGNAL elster, string& message);// лернд бшдювх яхцмюкю
	string get_path(); // лернд янгдюмхъ юаянкчрмнцн осрх дн назейрю
	int get_class_num();
};

#endif

