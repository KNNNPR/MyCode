#include "cl_base.h"

cl_base::cl_base(cl_base* user_p_head_obj, int num, string user_obj_name)
{
	ready = 1;//онке цнрнбмнярх
	p_head_obj = user_p_head_obj;
	obj_name = user_obj_name;
	my_class_num = num;
	if (p_head_obj != nullptr)// х назейр ме йнпмебни 
	{
		p_head_obj->add_to_sub(this);//рн днаюбкъел ецн б яохянй ондвхмеммшу цнкнбмнцн назейрю
	}
}
/////////////////////////////////////////////////////////
bool cl_base::set_name(string new_obj_name)
{
	if (p_head_obj != nullptr)
	{
		for (int i = 0; i < p_head_obj->sub_obj.size(); i++)
		{
			if (p_head_obj->sub_obj[i]->get_name() == new_obj_name)//еякх сфе ясыеярбсер назейр я рюйхл хлемел
			{
				return (false);// назейр ме лхмъер хлъ
			}
		}
	}
	this->obj_name = new_obj_name;//назейр лемъер хлъ
	return (true);
}
///////////////////////////////////////////////////
cl_base* cl_base::get_head()
{
	return(p_head_obj);//бнгбпюыюел сйюгюрекэ мю цнкнбмни назейр
}

string cl_base::get_name()
{
	return(obj_name);//бнгбпюыюел хлъ назейрю
}
/////////////////////////////////////////////////////
void cl_base::print_tree(int tabs)
{
	if (p_head_obj == nullptr)//еякх назейр цнкнбмни
	{
		std::cout << get_name() << std::endl;//бшбндхл ецн хлъ аеу опнаекнб
	}
	tabs += 4;
	for (int i = 0; i < sub_obj.size(); i++)//жхйк дкъ бшбндю ондвхмеммшу назейрнб
	{
		for (int j = 0; j < tabs; j++)//жхйк дкъ йнппейрмнцн бшбндю опнаекнб
		{
			std::cout << ' ';
		}
		std::cout << sub_obj[i]->get_name() << std::endl;
		sub_obj[i]->print_tree(tabs);//пейспемрмн бшгшбюел лернд дкъ бшбндю бяеу назейрнб мхфе он хепюпухх
	}
}
//////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////
void cl_base::add_to_sub(cl_base* time_obj)
{
	for (int i = 0; i < sub_obj.size(); i++)
	{
		if (sub_obj[i]->get_name() == time_obj->get_name())//еякх назейр сфе ясыеярбсер б ондвхмеммшу 
		{
			return;//рн мхвецн ме декюел
		}
	}
	sub_obj.push_back(time_obj);//хмюве днаюбкъел ецн б яохянй ондвхмеммшу
}
////////////////////////////////////////////////////////
////BEGIN KV_2////////////
/////////////////////////////
cl_base* cl_base::get_root()
{
	if (this->p_head_obj == nullptr)//еякх назейр йнпмебни
	{
		return(this);//бепмсрэ сйюгюрекэ мю щрнр назейр
	}
	return(p_head_obj->get_root());//бепмсрэ пегскэрюр щрнцн лерндю бшгбюммнцн с цнкнбмнцн назейрю(ббепу он хепюпухх)
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
	if (this->get_name() == what_name)//еякх рейсыхи назейр хяйнлши
	{
		return(this);//бнгбпюыюел сйюгюрекэ мю мецн
	}
	if (repeate_obj_name(what_name) != 1) return (nullptr);
	for (int i = 0; i < sub_obj.size(); i++)
	{
		if (sub_obj[i]->find_by_name_curr(what_name) != nullptr)//еякх мюьекяъ рюйни назейр япедх ондвхмеммшу
		{
			return(sub_obj[i]->find_by_name_curr(what_name));//бепмсрэ пегскэрюр лерндю нр ондвхмеммнцн назейрю
		}
	}
	return (nullptr);
}
//////////////////////////////////////////
cl_base* cl_base::find_by_name_root(string what_name)
{
	return(get_root()->find_by_name_curr(what_name));//рнр фе онхяй я рейсыецн мн рейсыхи цюпюмрхпнбюмн цнкнбмни
}
/////////////////////////////////////////////
void cl_base::set_ready(int user_set)
{
	if (user_set == 0)//еякх онкэгнбюрекэ ббек 0
	{
		ready = 0;//назейр ме цнрнб
		for (int i = 0; i < sub_obj.size(); i++)
		{
			sub_obj[i]->set_ready(0);//х бяе ецн ондвхмеммше рнфе
		}
		return;
	}
	if (p_head_obj == nullptr)//назейр цнкнбмни
	{
		ready = user_set;//мюгмювхрэ цнрнбмнярэ нр онкэгнбюрекъ
		return;
	}
	if (p_head_obj->is_ready())//еякх цнкнбмни назейр цнрнб
	{
		ready = user_set;//мюгмювхрэ цнрнбмнярэ нр онкэгнбюрекъ
		return;
	}
}
/////////////////////////////////////////
bool cl_base::is_ready()
{
	if (ready == 0) return (false);//еякх гмювемхе онкъ READY пюбмн 0 гмювхр назейр ме цнрнб
	return (true);//хмюве назейр цнрнб
}
//////////////////////////////////////////
///////////BEGIN KV_3/////////////////////
//////////////////////////////////////////
/////////////////////////////////////////////
cl_base* cl_base::find_by_name_sub(string what_name)//лернд дкъ мюунфдемхъ назейр он хлемх япедх меоняпедярбеммн ондвхмеммшу
{
	for (int i = 0; i < sub_obj.size(); i++)
	{
		if (sub_obj[i]->get_name() == what_name)//еякх хлъ ондвхмеммнцн янбоюдюер я хлемел хяйнлнцн назейрю
			return (sub_obj[i]);//рн бнгбпюгыюел сйюгюрекэ мю мецн
	}
	return (nullptr);//еякх мхйрн хг ондвхмеммшу ме ондньек рн ме мюькх назейр х бнгбпюыюел мскебни сйюгюрекэ
}
/////////////////////////////////////////////
cl_base* cl_base::find_by_path(string path)//лернд онхяйю назейрю он осрх
{
	if (path == "/") return get_root();//сякнбхе бнгбпюрю сйюгюрекъ мю йнпмебни назейрю
	if (path == ".") return (this);//сякнбхе бнгбпюрю сйюгюрекъ мю рейсых1 назейр
	if (path[0] == '.') return (find_by_name_curr(path.substr(1, path.length() - 1)));//сякнбхе бнгбпюыемхъ сйюгюрекъ мю назейр йнрнпши мюундхл б берйе рейсыецн
	if (path.substr(0, 2) == "//") return (find_by_name_root(path.substr(2, path.length() - 1)));//сякнбхе бнгбпюрю сйюгюрекъ мю нчзейр йнрнпши мюундхл нр йнпмъ он хлемх
	if (path[0] == '/')//сякхбхе юаянкчрмнцн осрх
	{
		path = path.substr(1, path.length() - 1);//нрпеуюел оепбши яхлбнк / дкъ йнппейрмнцн явхршбюмхъ осрх б жхйке
		cl_base* temp_obj = get_root();//мювюкэмши назейр - йнпмебни
		string temp_path;//оепелеммюъ асдер упюмхрэ бяе щрюош жеонвйх осрх, бяе назейрш б осрх
		for (char ch : path)//б жхйке аефхл он ярпнйе PATH
		{
			if (ch == '/')//хмшлх якнбюлх сякнбхе нйнмвюмхъ хлемх назейрю б ярпнйе PATH
			{
				temp_obj = temp_obj->find_by_name_sub(temp_path);//хыел назейр я рюйхл хлемел япедх меоняпедярбеммн ондвхмеммшу рейсыецн
				if (temp_obj == nullptr) return (nullptr);//еякх ме мюькх гмювхр осрэ меопюбхкэмши х бнгбпюыюел мскебни сйюгюрекэ
				temp_path.clear();//дюкее нрвхыюел ярпнйс щрюонб жеонвйх осрх врна мю якедсчыеи хрепюжхх онбрнпхрэ бяе деиярбхъ
				continue;//опхмсдхрмкэмн сундхл мю мнбсч хрепюжхч жхйкю
			}
			temp_path += ch;//рср лш мюпюыхбюел хлъ назейрю, онйю мнбши яхлбнк CH ме асдел /
		}
		temp_obj = temp_obj->find_by_name_sub(temp_path);//ре фе деиярбхъ врн х б жхйке
		if (temp_obj == nullptr) return (nullptr);//пюгмхжю б рнл врн ярпнйю ме йнмвюеряъ /
		return(temp_obj);//онщрнлс бме жхйкю дкъ онякедмецн назейрю б PATH бшонкмъел ре фе яюлше деиярбхъ
	}
	else// еякх мюл дюкх нрмняхрекэмши осрэ
	{
		cl_base* temp_obj = this;// едхмярбеммне нркхвхе нр юаянкчрмнцн осрх - нропюбмюъ рнвйю ме йнпемэ ю рейсыхи назейр
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
	for (int i = 0; i < connects.size(); i++) // жхйк дкъ опнунфдемхъ он бяел ябъгъл
	{
		if (connects[i]->p_signal == elster && // сякнбхе онбрнпю ябъгх
			connects[i]->p_cl_base == adress &&
			connects[i]->p_hendler == falke) return;
	}
	new_connection = new o_sh();// еякх ябъгэ мнбюъ рн янгдюел ее х мюгмювюел ее оюпюлерпш юпцслемрюлх хг лерндю
	new_connection->p_signal = elster;
	new_connection->p_cl_base = adress;
	new_connection->p_hendler = falke;
	connects.push_back(new_connection);// гюохяшбюел гюохяэ б бейрнп гюохяеи
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////
string cl_base::get_path()
{
	string true_path = "";
	cl_base* obj = this;
	if (obj->get_head() == nullptr) return ("/");// сякнбхе мюунфдемхъ цнкнбмнцн назейрю 
	while (obj->get_head() != nullptr)//жхйк цде лш ондмхлюеляъ ббепу дн цнкнбмнцн назейрю тнплхпсъ осрэ
	{
		true_path = '/' + obj->get_name() + true_path;//тнплхпнбюмхе наянкчрмнцн осрх
		obj = obj->get_head();//ондмхлюеляъ ббепу
	}
	return(true_path);
}
////////////////////////////////////////////////////////////////////////////////
void cl_base::delete_connection(TYPE_SIGNAL elster, TYPE_HANDLER falke, cl_base* adress)
{
	for (int i = 0; i < connects.size(); i++)// жхйк дкъ опнаефйх он бяел ябъгъэл
	{
		if (connects[i]->p_signal == elster && // сякнбхе мюунфдемхъ хяйнлни гюохях
			connects[i]->p_cl_base == adress &&
			connects[i]->p_hendler == falke)
		{
			connects.erase(connects.begin() + i); // яэепйю хяйнлни гюохях
			return;
		}
	}
}
/////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////
void cl_base::give_signal(TYPE_SIGNAL elster, string& message)
{
	if (ready == 0) return; // лш ме лнфел бшякюрэ яхцмюк нр мецнрнбнцн назейрю
	(this->*elster)(message); // бшгнб лерндю яхцмюкюк нр рейсыецн назейрю
	cout << endl;
	for (int i = 0; i < connects.size(); i++)// жхйк дкъ мюунфдемхъ назейрнб напюанрвхйнб 
	{
		if (connects[i]->p_signal == elster && connects[i]->p_cl_base->is_ready()) // сякнбхе мюунфдемхъ
		{
			((connects[i]->p_cl_base)->*(connects[i]->p_hendler))(message); // бшгнб лерндю напюанрвхйю мсфмнцн назейрю онксвюрекъ
			cout << endl;
		}
	}
}
///////////////////////////////////////////////////////////////////
int cl_base::get_class_num()
{
	return (my_class_num);/// бепмсрэ мнлеп йкюяяю
}
///////////////////////////////////////////////////////////////////////
