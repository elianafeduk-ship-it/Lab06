#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <clocale>

using namespace std;

// Заповнення масиву випадковими числами
void fillArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        a[i] = rand() % 61 - 40;
    }
}

// Виведення масиву
void printArray(const int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << setw(4) << a[i];
    }
    cout << endl;
}

// Перевірка критерію
bool checkElement(int value, int index)
{
    return value <= 0 && index % 2 == 0;
}

// Обчислення кількості елементів
int countElements(const int a[], int n)
{
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        if (checkElement(a[i], i))
        {
            count++;
        }
    }

    return count;
}

// Обчислення суми елементів
int sumElements(const int a[], int n)
{
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        if (checkElement(a[i], i))
        {
            sum += a[i];
        }
    }

    return sum;
}

// Заміна вибраних елементів нулями
void replaceElements(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (checkElement(a[i], i))
        {
            a[i] = 0;
        }
    }
}

int main()
{
    setlocale(LC_ALL, "");

    srand(static_cast<unsigned int>(time(0)));

    const int n = 26;
    int a[n];

    fillArray(a, n);

    cout << "Pochatkovyi masyv:" << endl;
    printArray(a, n);

    int count = countElements(a, n);
    int sum = sumElements(a, n);

    cout << "Kilkist elementiv: " << count << endl;
    cout << "Suma elementiv: " << sum << endl;

    replaceElements(a, n);

    cout << "Modyfikovanyi masyv:" << endl;
    printArray(a, n);

    return 0;
}
