#include <iostream>
using namespace std;

int main()
{
    long long x;
    cin >> x;
    if (x < 0)
    {
        cout << "false" << endl;
    }
    else
    {
        long long a = x;
        long long temp = 0;
        int rem;
        while (a > 0)
        {
            rem = a % 10;
            temp = temp * 10 + rem;
            a = a / 10;
        }
        if (temp == x)
        {
            cout << "true" << endl;
        }
    }
    return 0;
}
