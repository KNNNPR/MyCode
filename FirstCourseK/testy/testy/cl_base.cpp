#include "cl_base.h"

cl_base::cl_base(cl_base* user_p_head_obj, int num, string user_obj_name)
{
	ready = 1;//���� ����������
	p_head_obj = user_p_head_obj;
	obj_name = user_obj_name;
	my_class_num = num;
	if (p_head_obj != nullptr)// � ������ �� �������� 
	{
		p_head_obj->add_to_sub(this);//�� ��������� ��� � ������ ����������� ��������� �������
	}
}
/////////////////////////////////////////////////////////
bool cl_base::set_name(string new_obj_name)
{
	if (p_head_obj != nullptr)
	{
		for (int i = 0; i < p_head_obj->sub_obj.size(); i++)
		{
			if (p_head_obj->sub_obj[i]->get_name() == new_obj_name)//���� ��� ���������� ������ � ����� ������
			{
				return (false);// ������ �� ������ ���
			}
		}
	}
	this->obj_name = new_obj_name;//������ ������ ���
	return (true);
}
///////////////////////////////////////////////////
cl_base* cl_base::get_head()
{
	return(p_head_obj);//���������� ��������� �� �������� ������
}

string cl_base::get_name()
{
	return(obj_name);//���������� ��� �������
}
/////////////////////////////////////////////////////
void cl_base::print_tree(int tabs)
{
	if (p_head_obj == nullptr)//���� ������ ��������
	{
		std::cout << get_name() << std::endl;//������� ��� ��� ��� ��������
	}
	tabs += 4;
	for (int i = 0; i < sub_obj.size(); i++)//���� ��� ������ ����������� ��������
	{
		for (int j = 0; j < tabs; j++)//���� ��� ����������� ������ ��������
		{
			std::cout << ' ';
		}
		std::cout << sub_obj[i]->get_name() << std::endl;
		sub_obj[i]->print_tree(tabs);//���������� �������� ����� ��� ������ ���� �������� ���� �� ��������
	}
}
//////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////
void cl_base::add_to_sub(cl_base* time_obj)
{
	for (int i = 0; i < sub_obj.size(); i++)
	{
		if (sub_obj[i]->get_name() == time_obj->get_name())//���� ������ ��� ���������� � ����������� 
		{
			return;//�� ������ �� ������
		}
	}
	sub_obj.push_back(time_obj);//����� ��������� ��� � ������ �����������
}
////////////////////////////////////////////////////////
////BEGIN KV_2////////////
/////////////////////////////
cl_base* cl_base::get_root()
{
	if (this->p_head_obj == nullptr)//���� ������ ��������
	{
		return(this);//������� ��������� �� ���� ������
	}
	return(p_head_obj->get_root());//������� ��������� ����� ������ ���������� � ��������� �������(����� �� ��������)
}
///////////////////////////////////////////////////
int cl_base::repeate_obj_name(string name)
{
	int repeate_amount = 0;
	if (get_name() == name) repeate_amount++;
	for (int i = 0; i < sub_obj.size(); i++)
	{
		repeate_amount += sub_obj[i]->repeate_obj_name(name);
	}
	return(repeate_amount);
}
//////////////////////////////////////////////////
cl_base* cl_base::find_by_name_curr(string what_name)
{
	if (this->get_name() == what_name)//���� ������� ������ �������
	{
		return(this);//���������� ��������� �� ����
	}
	if (repeate_obj_name(what_name) != 1) return (nullptr);
	for (int i = 0; i < sub_obj.size(); i++)
	{
		if (sub_obj[i]->find_by_name_curr(what_name) != nullptr)//���� ������� ����� ������ ����� �����������
		{
			return(sub_obj[i]->find_by_name_curr(what_name));//������� ��������� ������ �� ������������ �������
		}
	}
	return (nullptr);
}
//////////////////////////////////////////
cl_base* cl_base::find_by_name_root(string what_name)
{
	return(get_root()->find_by_name_curr(what_name));//��� �� ����� � �������� �� ������� ������������� ��������
}
/////////////////////////////////////////////
void cl_base::set_ready(int user_set)
{
	if (user_set == 0)//���� ������������ ���� 0
	{
		ready = 0;//������ �� �����
		for (int i = 0; i < sub_obj.size(); i++)
		{
			sub_obj[i]->set_ready(0);//� ��� ��� ����������� ����
		}
		return;
	}
	if (p_head_obj == nullptr)//������ ��������
	{
		ready = user_set;//��������� ���������� �� ������������
		return;
	}
	if (p_head_obj->is_ready())//���� �������� ������ �����
	{
		ready = user_set;//��������� ���������� �� ������������
		return;
	}
}
/////////////////////////////////////////
bool cl_base::is_ready()
{
	if (ready == 0) return (false);//���� �������� ���� READY ����� 0 ������ ������ �� �����
	return (true);//����� ������ �����
}
//////////////////////////////////////////
///////////BEGIN KV_3/////////////////////
//////////////////////////////////////////
/////////////////////////////////////////////
cl_base* cl_base::find_by_name_sub(string what_name)//����� ��� ���������� ������ �� ����� ����� ��������������� �����������
{
	for (int i = 0; i < sub_obj.size(); i++)
	{
		if (sub_obj[i]->get_name() == what_name)//���� ��� ������������ ��������� � ������ �������� �������
			return (sub_obj[i]);//�� ����������� ��������� �� ����
	}
	return (nullptr);//���� ����� �� ����������� �� ������� �� �� ����� ������ � ���������� ������� ���������
}
/////////////////////////////////////////////
cl_base* cl_base::find_by_path(string path)//����� ������ ������� �� ����
{
	if (path == "/") return get_root();//������� �������� ��������� �� �������� �������
	if (path == ".") return (this);//������� �������� ��������� �� ������1 ������
	if (path[0] == '.') return (find_by_name_curr(path.substr(1, path.length() - 1)));//������� ����������� ��������� �� ������ ������� ������� � ����� ��������
	if (path.substr(0, 2) == "//") return (find_by_name_root(path.substr(2, path.length() - 1)));//������� �������� ��������� �� ������ ������� ������� �� ����� �� �����
	if (path[0] == '/')//������� ����������� ����
	{
		path = path.substr(1, path.length() - 1);//�������� ������ ������ / ��� ����������� ���������� ���� � �����
		cl_base* temp_obj = get_root();//��������� ������ - ��������
		string temp_path;//���������� ����� ������� ��� ����� ������� ����, ��� ������� � ����
		for (char ch : path)//� ����� ����� �� ������ PATH
		{
			if (ch == '/')//����� ������� ������� ��������� ����� ������� � ������ PATH
			{
				temp_obj = temp_obj->find_by_name_sub(temp_path);//���� ������ � ����� ������ ����� ��������������� ����������� ��������
				if (temp_obj == nullptr) return (nullptr);//���� �� ����� ������ ���� ������������ � ���������� ������� ���������
				temp_path.clear();//����� �������� ������ ������ ������� ���� ���� �� ��������� �������� ��������� ��� ��������
				continue;//������������� ������ �� ����� �������� �����
			}
			temp_path += ch;//��� �� ���������� ��� �������, ���� ����� ������ CH �� ����� /
		}
		temp_obj = temp_obj->find_by_name_sub(temp_path);//�� �� �������� ��� � � �����
		if (temp_obj == nullptr) return (nullptr);//������� � ��� ��� ������ �� ��������� /
		return(temp_obj);//������� ��� ����� ��� ���������� ������� � PATH ��������� �� �� ����� ��������
	}
	else// ���� ��� ���� ������������� ����
	{
		cl_base* temp_obj = this;// ������������ ������� �� ����������� ���� - ��������� ����� �� ������ � ������� ������
		string temp_path;
		for (char ch : path)
		{
			if (ch == '/')
			{
				temp_obj = temp_obj->find_by_name_sub(temp_path);
				if (temp_obj == nullptr) return (nullptr);
				temp_path.clear();
				continue;
			}
			temp_path += ch;
		}
		temp_obj = temp_obj->find_by_name_sub(temp_path);
		if (temp_obj == nullptr) return (nullptr);
		return(temp_obj);
	}
}
///////////////////////////////////////////////
//////////////////////////////////////////
///////////BEGIN KV_4/////////////////////
//////////////////////////////////////////
void cl_base::set_connection(cl_base* adress, TYPE_SIGNAL elster, TYPE_HANDLER falke)
{
	o_sh* new_connection;
	for (int i = 0; i < connects.size(); i++) // ���� ��� ����������� �� ���� ������
	{
		if (connects[i]->p_signal == elster && // ������� ������� �����
			connects[i]->p_cl_base == adress &&
			connects[i]->p_hendler == falke) return;
	}
	new_connection = new o_sh();// ���� ����� ����� �� ������� �� � ��������� �� ��������� ����������� �� ������
	new_connection->p_signal = elster;
	new_connection->p_cl_base = adress;
	new_connection->p_hendler = falke;
	connects.push_back(new_connection);// ���������� ������ � ������ �������
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////
string cl_base::get_path()
{
	string true_path = "";
	cl_base* obj = this;
	if (obj->get_head() == nullptr) return ("/");// ������� ���������� ��������� ������� 
	while (obj->get_head() != nullptr)//���� ��� �� ����������� ����� �� ��������� ������� �������� ����
	{
		true_path = '/' + obj->get_name() + true_path;//������������ ����������� ����
		obj = obj->get_head();//����������� �����
	}
	return(true_path);
}
////////////////////////////////////////////////////////////////////////////////
void cl_base::delete_connection(TYPE_SIGNAL elster, TYPE_HANDLER falke, cl_base* adress)
{
	for (int i = 0; i < connects.size(); i++)// ���� ��� �������� �� ���� �������
	{
		if (connects[i]->p_signal == elster && // ������� ���������� ������� ������
			connects[i]->p_cl_base == adress &&
			connects[i]->p_hendler == falke)
		{
			connects.erase(connects.begin() + i); // ������ ������� ������
			return;
		}
	}
}
/////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////
void cl_base::give_signal(TYPE_SIGNAL elster, string& message)
{
	if (ready == 0) return; // �� �� ����� ������� ������ �� ���������� �������
	(this->*elster)(message); // ����� ������ �������� �� �������� �������
	cout << endl;
	for (int i = 0; i < connects.size(); i++)// ���� ��� ���������� �������� ������������ 
	{
		if (connects[i]->p_signal == elster && connects[i]->p_cl_base->is_ready()) // ������� ����������
		{
			((connects[i]->p_cl_base)->*(connects[i]->p_hendler))(message); // ����� ������ ����������� ������� ������� ����������
			cout << endl;
		}
	}
}
///////////////////////////////////////////////////////////////////
int cl_base::get_class_num()
{
	return (my_class_num);/// ������� ����� ������
}
///////////////////////////////////////////////////////////////////////
