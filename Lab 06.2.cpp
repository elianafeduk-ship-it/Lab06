#include <iostream>
#include <cstdlib>
#include <ctime>

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
        cout << a[i] << " ";
    }
    cout << endl;
}

// Обчислення середнього арифметичного індексів
double averageMinMaxIndices(const int a[], int n)
{
    int minIndex = 0;
    int maxIndex = 0;

    for (int i = 1; i < n; i++)
    {
        if (a[i] < a[minIndex])
            minIndex = i;

        if (a[i] > a[maxIndex])
            maxIndex = i;
    }

    return (minIndex + maxIndex) / 2.0;
}

int main()
{
    setlocale(LC_ALL, "ukr");
    srand(static_cast<unsigned int>(time(0)));

    const int n = 26;
    int a[n];

    fillArray(a, n);

    cout << "Masiv:" << endl;
    printArray(a, n);

    double result = averageMinMaxIndices(a, n);

    cout << "Serednie arifmetychne indeksiv min i max: "
        << result << endl;

    return 0;
}
