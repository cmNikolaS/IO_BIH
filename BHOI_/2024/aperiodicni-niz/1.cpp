#include <iostream>

int main()
{
    long long n, i = 1;
    std::cin >> n;
    while(n - i > 0)
    {
        n -= i;
        i++;
    }
    std::cout << n << std::endl;
    return 0;
}