
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
        a[i] = rand() % 61 - 40;
}

// Виведення масиву
void printArray(const int a[], int n)
{
    for (int i = 0; i < n; i++)
        cout << setw(4) << a[i];
    cout << endl;
}

// Рекурсивний пошук індексів мінімального
// та максимального елементів
void findMinMaxIndices(const int a[], int n, int i,
    int& minIndex, int& maxIndex)
{
    if (i >= n)
        return;

    if (a[i] < a[minIndex])
        minIndex = i;

    if (a[i] > a[maxIndex])
        maxIndex = i;

    findMinMaxIndices(a, n, i + 1, minIndex, maxIndex);
}

// Обчислення середнього арифметичного індексів
double averageIndices(int minIndex, int maxIndex)
{
    return (minIndex + maxIndex) / 2.0;
}

int main()
{
    setlocale(LC_ALL, "");

    srand(static_cast<unsigned int>(time(nullptr)));

    const int n = 26;
    int a[n];

    fillArray(a, n);

    cout << "Pochatkovyi masyv:" << endl;
    printArray(a, n);

    int minIndex = 0;
    int maxIndex = 0;

    findMinMaxIndices(a, n, 1, minIndex, maxIndex);

    cout << "Indeks minimalnoho elementa: "
        << minIndex << endl;

    cout << "Indeks maksimalnoho elementa: "
        << maxIndex << endl;

    cout << fixed << setprecision(2);
    cout << "Serednie arytmetychne indeksiv: "
        << averageIndices(minIndex, maxIndex) << endl;

    return 0;
}
