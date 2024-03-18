#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

void EnterMatrixDynamic(int** a, int n)
{
    for (int i = 0; i < n; i++)
    {
        a[i] = (int*)malloc(sizeof(int) * n);
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }
}
void EnterMatrixStatic(int a[50][50], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }
}
vector <vector <int>> Dots(vector < vector < int>> a, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cin >> a[i][j];
        }
    }
    return (a);
}
void Show(vector <vector < int>> a, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout << a[i][j] << ' ';
        }
        cout << endl;

    }
}
void ShowTriangles(vector <vector < int>> a, int n)
{
    for (int i = 0; i < n - 2; i += 3)
    {
        cout << "Triangle = " << a[i][0] << ';' << a[i][1] << ' ' << a[i + 1][0] << ';' << a[i + 1][1] << ' ' << a[i + 2][0] << ';' << a[i + 2][1] << endl;
    }
    cout << endl;
}
int MinNumBelowMainDiagDynamic(int** a, int n)
{
    int Min = a[0][0];
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (Min > a[i][j])
            {
                Min = a[i][j];
            }
        }
    }
    return (Min);
}
int MinNumBelowMainDiagStatic(int a[50][50], int n)
{
    int Min = a[0][0];
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (Min > a[i][j])
            {
                Min = a[i][j];
            }
        }
    }
    return (Min);
}
bool comp(vector <int> a, vector <int> b)
{
    return a[0] < b[0];
}

int main()
{
    int Choise;
    cout << "Start of program" << endl;
    do
    {
        cout << "Enter Number of Task: 1 - Dynamic, 2 - static, 3 - Dots with vector" << endl;
        cin >> Choise;
        if (Choise == 1)
        {
            int n;
            int** a;
            do
            {
                cout << "Enter n for Matrix" << endl;
                cin >> n;
            } while (n <= 0);
            a = (int**)malloc(sizeof(int*) * n);
            EnterMatrixDynamic(a, n);
            cout << "Heres Minimum below" << endl;
            cout << MinNumBelowMainDiagDynamic(a, n);
            cout << endl;
        }

        else if (Choise == 2)
        {
            int n;
            cin >> n;
            int a[50][50];
            EnterMatrixStatic(a, n);
            cout << "Heres Minimum below" << endl;
            cout << MinNumBelowMainDiagStatic(a, n);
            cout << endl;
        }

        else if (Choise == 3)
        {
            cout << "Enter number of dots" << endl;
            int n;
            cin >> n;
            vector < vector <int> > a(n, vector <int>(2));
            a = Dots(a, n);
            sort(begin(a), end(a), comp);
            ShowTriangles(a, n);
        }
    } while (Choise == 1 || Choise == 2 || Choise == 3);
}