#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

// Formuvannia masyvu
void fillArray(int a[], const int n)
{
    for (int i = 0; i < n; i++)
        a[i] = rand() % 61 - 40;
}

// Vyvedennia masyvu
void printArray(const int a[], const int n)
{
    for (int i = 0; i < n; i++)
        cout << setw(4) << a[i];

    cout << endl;
}

// Zvychaina funktsiia
bool findMinOdd(const int a[], const int n, int& minOdd)
{
    bool found = false;

    for (int i = 0; i < n; i++)
    {
        if (a[i] % 2 != 0)
        {
            if (!found || a[i] < minOdd)
            {
                minOdd = a[i];
                found = true;
            }
        }
    }

    return found;
}

// Shablon funktsii
template <typename T>
bool findMinOddTemplate(const T a[], const int n, T& minOdd)
{
    bool found = false;

    for (int i = 0; i < n; i++)
    {
        if (a[i] % 2 != 0)
        {
            if (!found || a[i] < minOdd)
            {
                minOdd = a[i];
                found = true;
            }
        }
    }

    return found;
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

    if (findMinOdd(a, n, minOdd))
        cout << "Naimenshyi neparnyi element: "
        << minOdd << endl;
    else
        cout << "Neparnykh elementiv nemaie." << endl;

    int minOddTemplate = 0;

    if (findMinOddTemplate(a, n, minOddTemplate))
        cout << "Shablon: naimenshyi neparnyi element: "
        << minOddTemplate << endl;
    else
        cout << "Shablon: neparnykh elementiv nemaie." << endl;

    return 0;
}