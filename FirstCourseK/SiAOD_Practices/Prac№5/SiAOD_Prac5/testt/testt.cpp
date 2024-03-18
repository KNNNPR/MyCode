#include <iostream>

struct node
{
	char data;
	node* nextNodePtr;
	node(char userData)
	{
		data = userData;
		nextNodePtr = nullptr;
	}
};
struct list
{
	node* head;
	int length;
	list()
	{
		head = nullptr;
		length = 0;
	}
	bool Empty()
	{
		if (head == nullptr)
		{
			return (true);
		}
		else
		{
			return (false);
		}
	}
	void PushBack(char userdata)
	{
		node* app = new node(userdata);
		if (Empty())
		{
			head = app;
			length++;
		}
		else
		{
			node* temp = head;
			while (temp->nextNodePtr != nullptr)
			{
				temp = temp->nextNodePtr;
			}
			temp->nextNodePtr = app;
			length++;
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
			node* ptr = head;
			while (ptr != nullptr)
			{
				std::cout << ptr->data;
				ptr = ptr->nextNodePtr;

			}
		}
	}
	int SpaceCounter()
	{
		int spaceCounter = 0;
		node* ptr = head;
		while (ptr != nullptr)
		{
			if (ptr->data == ' ')
			{
				spaceCounter++;
			}
			ptr = ptr->nextNodePtr;
		}
		return(spaceCounter);
	}
};

list DeleteSecondWord(list Sentence)
{
	if (Sentence.Empty())
	{
		return(Sentence);
	}
	else
	{
		node* tempNode = Sentence.head;
		while (tempNode->nextNodePtr->data != ' ')
		{
			if (tempNode->nextNodePtr->data == ' ')
			{
				break;
			}
			tempNode = tempNode->nextNodePtr;
		}
		node* firstNodeDelete = tempNode;
		int spaceCounter = 0;
		while (spaceCounter != 2)
		{
			if (tempNode->nextNodePtr->data == ' ' || tempNode->nextNodePtr->data == '.')
			{
				spaceCounter++;
			}
			tempNode = tempNode->nextNodePtr;
		}
		node* lastNodeDelete = tempNode;
		firstNodeDelete->nextNodePtr = lastNodeDelete;
		return(Sentence);
	}
}
list ShiftLastWord(list Sentence)
{
	node* tempNode = Sentence.head;
	node* firstNodeShift = nullptr;
	node* link = nullptr;
	while (tempNode != nullptr)
	{
		if (tempNode->data == ' ')
		{
			link = tempNode;
			firstNodeShift = tempNode->nextNodePtr;
		}
		else if (tempNode->nextNodePtr->data == '.')
		{
			node* space = new node(' ');
			node* lastNodeShift = tempNode;
			link->nextNodePtr = lastNodeShift->nextNodePtr;
			lastNodeShift->nextNodePtr = space;
			space->nextNodePtr = Sentence.head;
			Sentence.head = firstNodeShift;
			return(Sentence);
		}
		tempNode = tempNode->nextNodePtr;
	}
	return (Sentence);
}
list AddUserWorld(list Sentence, int k)
{
	node* deleteNodeOne = Sentence.head;
	node* deleteNodeTwo = nullptr;
	node* tempNode = Sentence.head;
	int spaceCounter = 0;
	while (tempNode != nullptr)
	{
		if (tempNode->data == ' ' || tempNode->data == '.')
		{
			spaceCounter++;
			deleteNodeOne = deleteNodeTwo;
			deleteNodeTwo = tempNode;
			tempNode = tempNode->nextNodePtr;
			if (deleteNodeOne == nullptr)
			{
				deleteNodeOne = Sentence.head;
			}
			if (spaceCounter == k)
			{
				char buff;
				int blya = 0;
				node* lastNodeCreate = nullptr;
				do
				{
					std::cin >> (buff);
					if (buff == '.')
					{
						break;
					}
					node* writeNode = new node(buff);
					blya++;
					if (blya == 1)
					{
						deleteNodeOne->nextNodePtr = writeNode;
						writeNode->nextNodePtr = deleteNodeTwo;
						lastNodeCreate = writeNode;
					}
					else
					{
						lastNodeCreate->nextNodePtr = writeNode;
						lastNodeCreate = lastNodeCreate->nextNodePtr;
						writeNode->nextNodePtr = deleteNodeTwo;
					}

				} while (true);
				return(Sentence);
			}
		}
		tempNode = tempNode->nextNodePtr;
	}
	return (Sentence);
}

int main()
{
	list Sentence;
	char userData;
	std::cout << "Enter Sentence" << '\n';
	do
	{
		std::cin.get(userData);
		if (userData == NULL)
		{
			Sentence.PushBack(' ');
		}
		Sentence.PushBack(userData);
	} while (userData != '.');

	int control;
	do
	{
		std::cout << "1 - delete second word" << std::endl;
		std::cout << "2 - shift last word" << std::endl;
		std::cout << "3 - change k word" << std::endl;
		std::cin >> control;
		switch (control)
		{
		case 1:
		{
			Sentence = DeleteSecondWord(Sentence);
			Sentence.ShowList();
			std::cout << std::endl;
			break;
		}
		case 2:
		{
			Sentence = ShiftLastWord(Sentence);
			Sentence.ShowList();
			std::cout << std::endl;
			break;
		}
		case 3:
		{
			int wordPos;
			do
			{
				std::cout << "enter number of word" << std::endl;
				std::cin >> wordPos;
			} while (wordPos > Sentence.SpaceCounter());
			Sentence = AddUserWorld(Sentence, wordPos);
			Sentence.ShowList();
			std::cout << std::endl;
			break;
		}
		}
	} while (control == 1 || control == 2 || control == 3);
}