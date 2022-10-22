#include <iostream>
using namespace std;

int squareRoot(double x)
{
    long left_part = 0;
    long right_part = x / 2 + 1;
    while (left_part <= right_part)
    {
        long mid = left_part + (right_part - left_part) / 2;
        long result = mid * mid;
        if (result == (long)x)
        {
            return (int)mid;
        }
        else if (result > x)
        {
            right_part = mid - 1;
        }
        else
        {
            left_part = mid + 1;
        }
    }
    return (int)right_part;
}

int main()
{
    double x, result;
    cin >> x;
    cout << squareRoot(x) << endl;
    return 0;
}