#include <iostream>
#include <string>
#include <vector>

int main()
{
    std::ios_base::sync_with_stdio(false);
    long long N = 0;
    std::vector<unsigned long long> cnt(1024, 0);
    std::cin >> N;

    unsigned long long t, total = N * (N-1) / 2, bad = 0;
    for(auto i = 0; i < N; i++)
    {
        std::cin >> t;
        int mask = 0;

        if(t == 0)
            mask |= (1 << 0);
        while(t > 0)
        {
            int d = int(t % 10ULL);
            mask |= (1 << d);
            t /= 10ULL;
        }
        cnt[mask]++;
    }

    for(int i = 0; i < 1024; i++)
    {
        if(i == 0) continue;
        for(int j = i+1; j < 1024; j++)
        {
            if(cnt[j] == 0) continue;
            if((i & j) == 0)
                bad+=cnt[i]*cnt[j];
        }
    }

    std::cout << total - bad << std::endl;

    return 0;
}