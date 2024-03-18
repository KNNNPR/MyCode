#include <iostream>
//////////////////////////////
struct node
{
	int data;
	node* nextNodePtr;
	node(int userData)
	{
		data = userData;
		nextNodePtr = nullptr;
	}
};
struct stack
{
	node* tail;
	stack()
	{
		tail = nullptr;
	}
	bool Empty()
	{
		if (tail == nullptr)
		{
			return (true);
		}
		else
		{
			return (false);
		}
	}
	void PushBack(int userdata)
	{
		node* app = new node(userdata);
		if (Empty())
		{
			tail = app;
		}
		else
		{
			app->nextNodePtr = tail;
			tail = app;
		}
	}
	void ShowList()
	{
		if (Empty())
		{
			return;
		}
		else
		{
			node* ptr = tail;
			while (ptr != nullptr)
			{
				std::cout << ptr->data << ' ';
				ptr = ptr->nextNodePtr;
			}
		}
	}
	void PopBack()
	{
		node* deleteMark = tail;
		tail = tail->nextNodePtr;
		delete deleteMark;
	}
	void ReturnTail()
	{
		std::cout << tail->data;
	}
	void MakeEmpty()
	{
		while (tail != nullptr)
		{
			PopBack();
		}
	}
	int ReturnPop()
	{
		return (tail->data);
	}
};
/////////////////////////////////////////////////
stack* Convert(std::string num)
{
	stack* big = new stack;
	for (int i = 0; i < num.length(); i++)
	{
		big->PushBack(num[i] - '0');
	}
	return (big);
}
stack* SumNums(stack* a, stack* b)
{
	stack* sum = new stack;
	int overTen = 0;
	while (a->tail != nullptr && b->tail != nullptr)
	{
		sum->PushBack((a->ReturnPop() + b->ReturnPop() + overTen) % 10);
		overTen = (a->ReturnPop() + b->ReturnPop() + overTen) / 10;
		a->PopBack();
		b->PopBack();
	}
	if (a->tail != nullptr || b->tail != nullptr)
	{
		if (b->tail != nullptr)
		{
			a = b;
		}
		while (a->tail != nullptr)
		{
			sum->PushBack((a->ReturnPop() + overTen) % 10);
			overTen = (a->ReturnPop() + overTen) / 10;
			a->PopBack();
		}
	}
	if (overTen != 0)
	{
		sum->PushBack(overTen);
	}
	return (sum);
}
/////////////////////////////////////////////////
void add(int* steck, int* i, int input)
{
	steck[*i + 1] = input;
	(*i)++;
}
void pop(int* steck, int* i)
{
	if (*i == -1) return;
	(*i)--;
}
int returnTail(int* steck, int i)
{
	return (steck[i]);
}
void clear(int* steck, int* i)
{
	*i = -1;
}
bool isClear(int i)
{
	if (i == -1) return (true);
	return(false);
}
void show(int* steck, int* i)
{
	if (isClear(*i)) return;
	while (*i != -1)
	{
		std::cout << returnTail(steck, *i) << ' ';
		pop(steck, i);
	}
	std::cout << '\n';
}
////////////////////////////////////////////////
int main()
{
	int control;
	do
	{
		std::cout << "What u want ?" << std::endl;
		std::cout << "1 - list Stack" << std::endl;
		std::cout << "2 - mass Stack" << std::endl;
		std::cout << "3 - sum Stack" << std::endl;
		std::cin >> control;
		switch (control)
		{
		case 1:
		{
			stack user;
			int controlOne;
			do
			{
				std::cout << "What u want ?" << std::endl;
				std::cout << "1 - Push" << std::endl;
				std::cout << "2 - Pop" << std::endl;
				std::cout << "3 - clear" << std::endl;
				std::cout << "4 - clear check" << std::endl;
				std::cout << "5 - return head" << std::endl;
				std::cin >> controlOne;
				switch (controlOne)
				{
				case 1:
				{
					int userPush;
					std::cout << "Enter node data" << std::endl;
					std::cin >> userPush;
					user.PushBack(userPush);
					user.ShowList();
					std::cout << std::endl;
					break;
				}
				case 2:
				{
					user.PopBack();
					user.ShowList();
					std::cout << std::endl;
					break;
				}
				case 3:
				{
					user.MakeEmpty();
					std::cout << std::endl;
					break;
				}
				case 4:
				{
					user.Empty();
					std::cout << std::endl;
					break;
				}
				case 5:
				{
					user.ReturnTail();
					std::cout << std::endl;
					break;
				}
				}
			} while (controlOne == 1 || controlOne == 2 || controlOne == 3 || controlOne == 4 || controlOne == 5);
			break;
		}
		case 2:
		{
			int i = -1;
			int k;
			int input;
			std::cout << "Enter start amount of nums in stack" << std::endl;
			std::cin >> k;
			int* steck = new int[10];
			std::cout << "Enter start nums in stack" << std::endl;
			for (int j = 0; j < k; j++)
			{
				std::cin >> input;
				add(steck, &i, input);
			}
			int controlOne;
			do
			{
				std::cout << "What u want ?" << std::endl;
				std::cout << "1 - Push" << std::endl;
				std::cout << "2 - Pop" << std::endl;
				std::cout << "3 - clear" << std::endl;
				std::cout << "4 - clear check" << std::endl;
				std::cout << "5 - return head" << std::endl;
				std::cin >> controlOne;
				switch (controlOne)
				{
				case 1:
				{
					int userPush;
					std::cout << "Enter node data" << std::endl;
					std::cin >> userPush;
					add(steck, &i, userPush);
					show(steck, &i);
					std::cout << std::endl;
					break;
				}
				case 2:
				{
					pop(steck, &i);
					show(steck, &i);
					std::cout << std::endl;
					break;
				}
				case 3:
				{
					clear(steck, &i);
					std::cout << std::endl;
					break;
				}
				case 4:
				{
					isClear(i);
					std::cout << std::endl;
					break;
				}
				case 5:
				{
					returnTail(steck, i);
					std::cout << std::endl;
					break;
				}
				}
			} while (controlOne == 1 || controlOne == 2 || controlOne == 3 || controlOne == 4 || controlOne == 5);
			break;
		}
		case 3:
		{
			std::string num1;
			std::string num2;
			std::cout << "Enter Two nums" << std::endl;
			std::cin >> num1;
			std::cin >> num2;
			stack* res = SumNums(Convert(num1), Convert(num2));
			std::cout << "Here it is !" << std::endl;
			res->ShowList();
			std::cout << std::endl;
			break;
		}
		}

	} while (control == 1 || control == 2 || control == 3);
}
