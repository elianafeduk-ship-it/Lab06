#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

// Poshuk maksymalnoho za modulem elementa
double findMaxAbs(const double a[], const int n, int i = 0)
{
    if (i == n - 1)
        return a[i];

    double maxAbs = findMaxAbs(a, n, i + 1);

    if (fabs(a[i]) > fabs(maxAbs))
        return a[i];

    return maxAbs;
}

// Rekursyvnyi poshuk indeksiv pershykh dvokh dodatnykh elementiv
void findPositive(const double a[], const int n, int i,
    int& first, int& second)
{
    if (i >= n || second != -1)
        return;

    if (a[i] > 0)
    {
        if (first == -1)
            first = i;
        else
            second = i;
    }

    findPositive(a, n, i + 1, first, second);
}

// Rekursyvne obchyslennia sumy mizh dodatnymy elementamy
double sumBetweenPositive(const double a[], int i, int second)
{
    if (i >= second)
        return 0;

    return a[i] + sumBetweenPositive(a, i + 1, second);
}

// Rekursyvne peremishchennia nenulovykh elementiv
void moveNonZeros(const double a[], double b[], int n,
    int i, int& pos)
{
    if (i >= n)
        return;

    if (a[i] != 0)
    {
        b[pos] = a[i];
        pos++;
    }

    moveNonZeros(a, b, n, i + 1, pos);
}

// Rekursyvne zapovnennia kintsia masyvu nuliamy
void fillZeros(double a[], int n, int pos)
{
    if (pos >= n)
        return;

    a[pos] = 0;
    fillZeros(a, n, pos + 1);
}

// Rekursyvne peremishchennia nuliv u kinets masyvu
void moveZerosToEnd(double a[], const int n)
{
    double* b = new double[n];
    int pos = 0;

    moveNonZeros(a, b, n, 0, pos);
    fillZeros(b, n, pos);

    for (int i = 0; i < n; i++)
        a[i] = b[i];

    delete[] b;
}

// Rekursyvne vyvedennia masyvu
void printArray(const double a[], const int n, int i = 0)
{
    if (i >= n)
    {
        cout << endl;
        return;
    }

    cout << setw(8) << fixed << setprecision(2) << a[i];
    printArray(a, n, i + 1);
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

    int first = -1;
    int second = -1;

    findPositive(a, n, 0, first, second);

    if (first != -1 && second != -1)
    {
        cout << "Suma mizh pershym i druhym dodatnymy elementamy: "
            << sumBetweenPositive(a, first + 1, second) << endl;
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

