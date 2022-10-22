#include <iostream>
using namespace std;

int power(double a, double b);

int main()
{
    double a, b, result;
    cin >> a >> b;
    if (b < 0)
    {
        b = -1 * b;
        result = power(a, b);
        result = 1 / result;
    }
    else
    {
        result = power(a, b);
    }

    cout << result << endl;
    return 0;
}

int power(double a, double b)
{
    if (b != 0)
    {
        return (a * power(a, b - 1));
    }
    else
    {
        return 1;
    }
}