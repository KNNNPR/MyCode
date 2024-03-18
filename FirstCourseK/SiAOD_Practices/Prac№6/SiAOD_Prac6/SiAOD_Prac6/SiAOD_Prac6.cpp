#include <iostream>

int recurseBinar(int* array, int left, int rigth, int answer)
{
    int mid = (left + rigth) / 2;
    if (array[mid] == answer) return(mid);
    if (left == rigth) return (-1);
    if (array[mid] > answer) recurseBinar(array, left, mid - 1, answer);
    else recurseBinar(array, mid + 1, rigth, answer);
};
void sortByChoise(int* array, int n)
{
    for (int i = 0; i < n; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (array[j] < array[i])
            {
                min = j;
                std::swap(array[j], array[i]);
            }
        }
    }
}
void inputArray(int* array, int n)
{
    for (int i = 0; i < n; i++)
    {
        std::cin >> array[i];
    }
}
void showArray(int* array, int n)
{
    for (int i = 0; i < n; i++) std::cout << array[i] << ' ';
}
void rescueBinarIter(int* array, int answer, int length)
{
    int left = 0;
    int right = length - 1;
    int mid;
    bool find = false;

    while ((left <= right) && (find == false)) 
    {
        mid = (left + right) / 2;

        if (array[mid] == answer)
        {
            find = true;
        }
        if (array[mid] > answer)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }

    if (find)
    {
        std::cout << "index of targer by iter: " << mid << std::endl;
    }
    else
    {
        std::cout << "No" << std::endl;
    }
}

struct node
{
    char data;
    node* nextNodePtr;
    node* prevNodePtr;
    node(char userData)
    {
        data = userData;
        nextNodePtr = nullptr;
        prevNodePtr = nullptr;
    }
};
struct list
{
    node* head;
    node* tail;
    list()
    {
        head = nullptr;
        tail = nullptr;
    }
    list PushFront(char userDataAdd)
    {
        node* add = new node(userDataAdd);
        if (head == nullptr)
        {
            head = add;
            return(*this);
        }
        else if (tail == nullptr)
        {
            node* temp = head;
            head = add;
            head->nextNodePtr = temp;
            temp->prevNodePtr = head;
            tail = temp;
            return(*this);
        }
        else
        {
            node* temp = head;
            head = add;
            head->nextNodePtr = temp;
            temp->prevNodePtr = add;
            return(*this);
        }
    }
    list PushBack(char userDataAdd)
    {
        node* add = new node(userDataAdd);
        if (tail == nullptr)
        {
            tail = add;
            return(*this);
        }
        else if (head == nullptr)
        {
            node* temp = tail;
            tail = add;
            tail->prevNodePtr = temp;
            temp->nextNodePtr = tail;
            head = temp;
            return(*this);
        }
        else
        {
            node* temp = tail;
            tail = add;
            tail->prevNodePtr = temp;
            temp->nextNodePtr = add;
            return(*this);
        }
    }
    void ShowList()
    {
        node* temp = head;
        while (temp != nullptr)
        {
            std::cout << temp->data;
            temp = temp->nextNodePtr;
        }
    }
};

list RecursePushBack(list Sentence)
{
    char buff;
    std::cin >> buff;
    if (buff == '.')
    {
        Sentence.PushBack('.');
        return (Sentence);
    }
    else
    {
        RecursePushBack(Sentence.PushBack(buff));
    }
}
list RecursePushFront(list Sentence)
{
    char buff;
    std::cin >> buff;
    if (buff == '.')
    {
        Sentence.PushBack('.');
        return (Sentence);
    }
    else
    {
        RecursePushFront(Sentence.PushFront(buff));
    }
}

int main()
{
    int length;
    int searchTarget;
    int control;
    do
    {
        std::cout << "enter control" << std::endl;
        std::cout << "1 - binar rescue" << std::endl;
        std::cout << "2 - twoway list" << std::endl;
        std::cin >> control;
        switch (control)
        {
        case 1:
        {
            std::cout << "Enter len ";
            std::cin >> length;
            int* array = new int[length];
            inputArray(array, length);
            sortByChoise(array, length);
            std::cout << "Sorted array = ";
            showArray(array, length);
            std::cout << std::endl;
            std::cout << "Enter Target ";
            std::cin >> searchTarget;
            if (recurseBinar(array, 0, length - 1, searchTarget) == -1)
            {
                std::cout << "No" << std::endl;
            }
            else
            {
                std::cout << "index of target by rec: " << recurseBinar(array, 0, length - 1, searchTarget) << std::endl;
            }
            rescueBinarIter(array, searchTarget, length);
            break;
        }
        case 2:
        {
            list Sentence;
            char buff;
            int controlBackFront;
            std::cout << "Front - 1 back - 2" << std::endl;
            std::cin >> controlBackFront;
            if (controlBackFront == 1)
            {
                Sentence = RecursePushFront(Sentence);
            }
            if (controlBackFront == 2)
            {
                Sentence = RecursePushBack(Sentence);
            }
            Sentence.ShowList();
            std::cout << std::endl;
        }
        }
    } while (control == 1 || control == 2);
}