#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

// Знаходження максимального за модулем елемента масиву
double findMaxAbs(const double a[], const int n)
{
    double maxAbs = a[0];

    for (int i = 1; i < n; i++)
    {
        if (fabs(a[i]) > fabs(maxAbs))
            maxAbs = a[i];
    }

    return maxAbs;
}

// Обчислення суми елементів між першим і другим додатними елементами
double sumBetweenPositive(const double a[], const int n)
{
    int first = -1;
    int second = -1;

    for (int i = 0; i < n; i++)
    {
        if (a[i] > 0)
        {
            if (first == -1)
                first = i;
            else
            {
                second = i;
                break;
            }
        }
    }

    double sum = 0;

    if (first != -1 && second != -1)
    {
        for (int i = first + 1; i < second; i++)
            sum += a[i];
    }

    return sum;
}

// Переміщення нулів у кінець масиву зі збереженням порядку інших елементів
void moveZerosToEnd(double a[], const int n)
{
    int pos = 0;

    for (int i = 0; i < n; i++)
    {
        if (a[i] != 0)
        {
            a[pos] = a[i];
            pos++;
        }
    }

    while (pos < n)
    {
        a[pos] = 0;
        pos++;
    }
}

// Виведення масиву в один рядок
void printArray(const double a[], const int n)
{
    for (int i = 0; i < n; i++)
        cout << setw(8) << fixed << setprecision(2) << a[i];

    cout << endl;
}

int main()
{
    int n;

    cout << "Vvedit n: ";
    cin >> n;

    if (n <= 0)
    {
        cout << "n maie buty dodatnym!" << endl;
        return 1;
    }

    double* a = new double[n];

    cout << "Vvedit elementy masyvu:" << endl;

    for (int i = 0; i < n; i++)
        cin >> a[i];

    cout << "Pochatkovyi masyv:" << endl;
    printArray(a, n);

    cout << "Maksymalnyi za modulem element: "
        << findMaxAbs(a, n) << endl;

    int positiveCount = 0;

    for (int i = 0; i < n; i++)
    {
        if (a[i] > 0)
            positiveCount++;
    }

    if (positiveCount >= 2)
    {
        cout << "Suma mizh pershym i druhym dodatnymy elementamy: "
            << sumBetweenPositive(a, n) << endl;
    }
    else
    {
        cout << "U masyvi menshe dvokh dodatnykh elementiv." << endl;
    }

    moveZerosToEnd(a, n);

    cout << "Masyv pislia peremishchennia nuliv:" << endl;
    printArray(a, n);

    delete[] a;

    return 0;
}
