#include <iostream>

int recurseBinar(int* array, int left, int rigth, int answer)
{
    int mid = (left + rigth) / 2;
    if (array[mid] == answer) return(mid);
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
void rescueBinarIter(int* array, int left, int rigth, int answer)
{

}
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
        RecursePushBack(Sentence);
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
    void PushFront(char userDataAdd)
    {
        node* add = new node(userDataAdd);
        if (head == nullptr)
        {
            head = add;
            return;
        }
        else if (tail == nullptr)
        {
            node* temp = head;
            head = add;
            head->nextNodePtr = temp;
            temp->prevNodePtr = head;
            tail = temp;
            return;
        }
        else
        {
            node* temp = head;
            head = add;
            head->nextNodePtr = temp;
            temp->prevNodePtr = add;
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

int main()
{
    int n;
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
            std::cout << "Enter len" << std::endl;
            std::cin >> n;
            int* array = new int[n];
            inputArray(array, n);
            sortByChoise(array, n);
            std::cout << "Sorted array = " << std::endl;
            showArray(array, n);
            std::cout << "Enter Target" << std::endl;
            std::cin >> searchTarget;
            std::cout << "index of Target: " << recurseBinar(array, 0, n - 1, searchTarget) << std::endl;
            break;
        }
        case 2:
        {
            list Sentence;
            char buff;
            int controlBackFront;
            std::cout << "Front or back ?" << std::endl;
            std::cin >> controlBackFront;
            if (controlBackFront == 1)
            {
                do
                {
                    std::cin.get(buff);
                    if (buff == NULL)
                    {
                        Sentence.PushBack(' ');
                    }
                    Sentence.PushBack(buff);
                } while (buff != '.');
            }
            if (controlBackFront == 2)
            {
                do
                {
                    std::cin.get(buff);
                    if (buff == NULL)
                    {
                        Sentence.PushFront(' ');
                    }
                    Sentence.PushFront(buff);
                } while (buff != '.');
            }
            Sentence.ShowList();
        std::cout << std::endl;
        }
        }
    } while (control == 1 || control == 2);
}