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

struct o_sh                 // ��������� ������� ����� �����
{
	TYPE_SIGNAL  p_signal;    // ��������� �� ����� �������
	cl_base* p_cl_base;   	// ��������� �� ������� ������
	TYPE_HANDLER p_hendler;   // ��������� �� ����� �����������
};

class cl_base
{
private:
	string obj_name;// ���� ��� �������
	cl_base* p_head_obj;// ���� ��������� �� �������� ������
	vector <cl_base* > sub_obj;// ������ ����������� ��������
	vector < o_sh* > connects;// ������ ���������� 
	int ready;// ���� ���������� �������
	int my_class_num;
public:
	cl_base(cl_base* user_p_head_obj, int num, string user_obj_name = "Base_object");// �����������
	bool set_name(string new_obj_name);// ����� ��������� �����
	string get_name();// ������ ����� �������
	cl_base* get_head();// ������ ��������� �� �������� ������� 
	void print_tree(int tabs);// ����� ������ ����� �������� �� �����
	void add_to_sub(cl_base* time_obj);// ����� ���������� ������� � ������ ����������� 

	//NEW_KV_2//
	cl_base* get_root();// ����� ���������� ��������� �� �������� ������
	cl_base* find_by_name_curr(string what_name);// ����� ������ ������� �� ����� �� ��������
	cl_base* find_by_name_root(string what_name);// ����� ������ ������� �� ����� �� ��������� ������� (�� ���� ������)
	void set_ready(int user_set);// ������ ���������� �������
	bool is_ready();// ����� �������� ���������� �������

	//NEW_KV_3//
	cl_base* find_by_name_sub(string what_name);// ����� ������ ������� �� ����� ����� ��������������� �����������
	cl_base* find_by_path(string path);// ����� ���������� ������� �� ����
	int repeate_obj_name(string name);// ����� ��������� ������� � ���������� ������
	//NEW_KV_4//
	void set_connection(cl_base* adress, TYPE_SIGNAL elster, TYPE_HANDLER falke);// ����� ����������� ������ ����� ���������
	void delete_connection(TYPE_SIGNAL elster, TYPE_HANDLER falke, cl_base* adress);// ����� �������� �����
	void give_signal(TYPE_SIGNAL elster, string& message);// ����� ������ �������
	string get_path(); // ����� �������� ����������� ���� �� �������
	int get_class_num();
};

#endif

