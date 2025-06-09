#include <iostream>
#include <vector>
#include <algorithm>

typedef unsigned long long ull;

ull MODUL = 1000000007;

ull power(ull N, ull M)
{
    N %= MODUL;
    if(M == 0) return 1;
    if(M == 1)
        return (N % MODUL);
    ull t = power(N, M / 2) % MODUL;
    t = (t * t) % MODUL;
    if(M % 2 == 1)
        t*=N;
    t%=MODUL;
    return t % MODUL;
}

int main()
{
    ull N, K, R = 0;
    std::cin >> N >> K;
    std::vector<ull> A(N);
    for(int i = 0; i < N; i++)
        std::cin >> A[i];

    for(int i = -1; i < N; i++)
    {
        ull t = K;
        for(int j = 0; j < N; j++)
        {
            if(i == j)
                t = (t * A[j]) % MODUL;
            else
                t = power(t, A[j]) % MODUL;
        }
        if(t > R) R = t;
    }

    std::cout << R << std::endl;
    return 0;
}