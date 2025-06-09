#include <iostream>
#include <numeric>

int pour_steps(int a, int b, int c)
{
    int a1 = a;
    int b1 = 0;
    int t = 1;

    while(a1 + b1 != c)
    {
        int t2 = std::min(a1, b - b1);
        b1 += t2;
        a1 -= t2;
        t++;

        if(a1 + b1 == c) break;

        if(a1 == 0)
        {
            a1 = a;
            t++;
        }

        if(a1 + b1 == c) break;

        if(b1 == b)
        {
            b1 = 0;
            t++;
        }
    }

    return t;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int a, b, c;
    std::cin >> a >> b >> c;

    if(c == 0)
    {
        std::cout << 0 << "\n";
        return 0;
    }

    if(a + b < c)
    {
        std::cout << -1 << "\n";
        return 0;
    }

    if(a == 0 || b == 0)
    {
        if(c == std::max(a, b)) std::cout << 1 << "\n";
        else std::cout << -1 << "\n";
        return 0;
    }

    if(c % std::gcd(a, b) != 0)
    {
        std::cout << -1 << "\n";
        return 0;
    }

    if(c == a + b)
    {
        std::cout << 2 << "\n";
        return 0;
    }

    if(c == a || c == b)
    {
        std::cout << 1 << "\n";
        return 0;
    }

    int t1 = pour_steps(a, b, c);
    int t2 = pour_steps(b, a, c);
    std::cout << std::min(t1, t2) << "\n";

    return 0;
}
