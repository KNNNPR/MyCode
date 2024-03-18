#include "cl_application.h"
//////////////////////////////////////////////////////////
cl_application::cl_application(cl_base* temp_p_head_obj, int num) :cl_base(temp_p_head_obj, num)
{	// �����������
}
//////////////////////////////////////////////////////////////////////////////
void cl_application::build_tree_obj()
{
	string head_name;
	string sub_name;
	string path_sig;
	string path_hand;
	int class_number;
	cl_base* sub_ob = this;
	cl_base* emiter;
	cl_base* handler;

	std::cin >> head_name;
	set_name(head_name);
	while (true)
	{
		std::cin >> head_name;
		if (head_name == "endtree")
		{
			break;//����� ����� ������
		}
		std::cin >> sub_name >> class_number;
		sub_ob = this->find_by_path(head_name);
		if (sub_ob == nullptr)
		{
			std::cout << "Object tree" << endl;
			this->print_tree(0);
			std::cout << "The head object " << head_name << " is not found";
			exit(1);
		}
		if (sub_ob->find_by_name_sub(sub_name) != nullptr)
		{
			std::cout << sub_name << "            Dubbing the names of subordinate objects";
			continue;
		}
		switch (class_number)
		{
		case 2:
		{
			new cl_node_1(sub_ob, sub_name, class_number);//�������� ����� ������� ����� ��������
			break;
		}
		case 3:
		{
			new cl_node_2(sub_ob, sub_name, class_number);
			break;
		}
		case 4:
		{
			new cl_node_3(sub_ob, sub_name, class_number);
			break;
		}
		case 5:
		{
			new cl_node_4(sub_ob, sub_name, class_number);
			break;
		}
		case 6:
		{
			new cl_node_5(sub_ob, sub_name, class_number);
			break;
		}
		}
	}
	while (true)
	{
		std::cin >> path_sig;
		if (path_sig == "end_of_connections") break;// ������� ����� ��������� ������
		std::getline(std::cin, path_hand);
		path_hand.erase(path_hand.begin());
		emiter = find_by_path(path_sig);
		handler = find_by_path(path_hand);
		emiter->set_connection(handler, this->get_signal(emiter), this->get_handler(handler));// ��������� ����� ����� ���������
	}
}
//////////////////////////////////////////////////////////////////////////////////////////////////
int cl_application::exec_app()
{
	std::cout << "Object tree" << std::endl;
	print_tree(0);//����� ����� �������� �������� ��� �� ����������
	work_with_commands();// ����� ������ ������ � ���������
	return(0);
}
/////////////////////////////////////////////////////////////////////////////////////////
void cl_application::work_with_commands()
{
	string command;
	string message;
	string path_sig;
	string path_hand;
	cl_base* emiter;
	cl_base* handler;
	string prog_ready;
	while (true)
	{
		std::cin >> command;
		if (command == "END") break;// ������� ����� ��������� ������
		if (command == "SET_CONNECT")// ���������� ����������
		{
			std::cin >> path_sig;
			std::getline(std::cin, path_hand);
			path_hand.erase(path_hand.begin());
			emiter = find_by_path(path_sig);
			if (emiter == nullptr)// ������� ������������ �������
			{
				std::cout << "Object " << path_sig << " not found";
				continue;
			}
			handler = find_by_path(path_hand);
			if (handler == nullptr)// ������� ������������ �������
			{
				std::cout << "Handler object " << path_hand << " not found";
				continue;
			}
			emiter->set_connection(handler, this->get_signal(emiter), this->get_handler(handler)); // ��������� ����������
		}
		if (command == "SET_CONDITION")// ��������� ����������
		{
			std::cin >> path_sig;
			std::getline(std::cin, prog_ready);
			prog_ready.erase(prog_ready.begin());
			emiter = find_by_path(path_sig);
			if (emiter == nullptr)// ������� ������������ �������
			{
				std::cout << "Object " << path_sig << " not found";
				continue;
			}
			emiter->set_ready(stoi(prog_ready));// ��������� ����������
		}
		if (command == "DELETE_CONNECT")// ������� �������� ����������
		{
			std::cin >> path_sig;
			std::getline(std::cin, path_hand);
			path_hand.erase(path_hand.begin());
			emiter = find_by_path(path_sig);
			if (emiter == nullptr)// ������� ������������ �������
			{
				std::cout << "Object " << path_sig << " not found";
				continue;
			}
			handler = find_by_path(path_hand);
			if (handler == nullptr)// ������� ������������ �������
			{
				std::cout << "Handler object " << path_hand << " not found";
				continue;
			}
			emiter->delete_connection(this->get_signal(emiter), this->get_handler(handler), handler);// �������� ����������
		}
		if (command == "EMIT")// ���������� �������
		{
			std::cin >> path_sig;
			std::getline(std::cin, message);
			message.erase(message.begin());
			emiter = find_by_path(path_sig);
			if (emiter == nullptr)// ������� ������������ �������
			{
				std::cout << "Object " << path_sig << " not found";
				continue;
			}
			emiter->give_signal(this->get_signal(emiter), message);//���������� ��������
		}
	}
}
////////////////////////////////////////////////////////////////////////////////////////////
TYPE_SIGNAL cl_application::get_signal(cl_base* obj)
{
	switch (obj->get_class_num()) // ��������� �� ������ ������ ���� ��������� ������� ����� �������
	{
	case 1: return (SIGNAL_D(cl_application::signal));// ���������� ������ ������
	case 2: return (SIGNAL_D(cl_node_1::signal));
	case 3: return (SIGNAL_D(cl_node_2::signal));
	case 4: return (SIGNAL_D(cl_node_3::signal));
	case 5: return (SIGNAL_D(cl_node_4::signal));
	case 6: return (SIGNAL_D(cl_node_5::signal));
	}
	return (nullptr);
}
/////////////////////////////////////////////////////////////////////
TYPE_HANDLER cl_application::get_handler(cl_base* obj)
{
	switch (obj->get_class_num())// ��������� �� ������ ������ ���� ��������� ������� ����� �������
	{
	case 1: return (HENDLER_D(cl_application::handler));
	case 2: return (HENDLER_D(cl_node_1::handler));// ���������� ������ �����
	case 3: return (HENDLER_D(cl_node_2::handler));
	case 4: return (HENDLER_D(cl_node_3::handler));
	case 5: return (HENDLER_D(cl_node_4::handler));
	case 6: return (HENDLER_D(cl_node_5::handler));
	}
	return (nullptr);
}
////////////////////////////////////////////////////////
void cl_application::signal(string& message) // ����� ������
{
	std::cout << "Signal from " << get_path();
	message += "class: 1 )";
	cout << endl;
}
///////////////////////////////////////////////////////////////
void cl_application::handler(string& message) // ����� ����������
{
	std::cout << "Signal to " << get_path() << " Text:  " << message;
}