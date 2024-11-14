#include <iostream>
using namespace std;
static bool allBitsAreSet(int n)
{
    if (((n + 1) & n) == 0)
        return true;
    return false;
}

bool bitsAreInAltOrder(unsigned int n)
{
    unsigned int num = n ^ (n >> 1);
    return allBitsAreSet(num);
}

int main()
{
int n=10;
cout<<bitsAreInAltOrder(n);

    return 0;
}
