#include <iostream>

struct Node
{
	char Data;
	Node* NextNode;
	Node(char DataI) : Data(DataI), NextNode(nullptr){};
};

struct List
{
	Node* Head;
	Node* Tail;

	List() : Head(nullptr), Tail(nullptr) {};

	bool Empty()
	{
		return (Head == nullptr);
	}
	void ShowList()
	{
		if (Empty)
		{
			return;
		}
		Node* P = Head;
		while (P)
		{
			std::cout << P->Data << ' ';
			P = P->NextNode;
		}
		std::cout << std::endl;
	}
};

int main()
{
	List l;
}