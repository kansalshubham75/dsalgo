#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int power(int x, int n)
{
    int oddpower = 1;

    while (n != 1)
    {
        if (n & 1)
        {
            oddpower *= x;
            n--;
        }
        n = n / 2;
        x *= x;
    }
    return x * oddpower;
}

int main()
{
    cout<<power(2,15);
    return 0;
}