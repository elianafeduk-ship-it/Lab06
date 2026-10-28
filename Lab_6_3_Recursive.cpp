
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

// Формування масиву
void fillArray(int a[], const int n)
{
    for (int i = 0; i < n; i++)
        a[i] = rand() % 61 - 40;
}

// Виведення масиву
void printArray(const int a[], const int n)
{
    for (int i = 0; i < n; i++)
        cout << setw(4) << a[i];

    cout << endl;
}

// Рекурсивна звичайна функція
bool findMinOdd(const int a[], const int n, int i, int& minOdd, bool found = false)
{
    if (i >= n)
        return found;

    if (a[i] % 2 != 0)
    {
        if (!found || a[i] < minOdd)
        {
            minOdd = a[i];
            found = true;
        }
    }

    return findMinOdd(a, n, i + 1, minOdd, found);
}

// Рекурсивна шаблонна функція
template <typename T>
bool findMinOddTemplate(const T a[], const int n, int i, T& minOdd, bool found = false)
{
    if (i >= n)
        return found;

    if (a[i] % 2 != 0)
    {
        if (!found || a[i] < minOdd)
        {
            minOdd = a[i];
            found = true;
        }
    }

    return findMinOddTemplate(a, n, i + 1, minOdd, found);
}

int main()
{
    srand(static_cast<unsigned int>(time(0)));

    const int n = 26;
    int a[n];

    fillArray(a, n);

    cout << "Masyv:" << endl;
    printArray(a, n);

    int minOdd = 0;

    if (findMinOdd(a, n, 0, minOdd))
        cout << "Naimenshyi neparnyi element: "
        << minOdd << endl;
    else
        cout << "Neparnykh elementiv nemaie." << endl;

    int minOddTemplate = 0;

    if (findMinOddTemplate(a, n, 0, minOddTemplate))
        cout << "Shablon: naimenshyi neparnyi element: "
        << minOddTemplate << endl;
    else
        cout << "Shablon: neparnykh elementiv nemaie." << endl;

    return 0;
}

