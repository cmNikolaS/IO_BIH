#include <iostream>
#include <string>
#include <vector>

int longest(int m, char c, const std::string& A)
{
    int maxx = 0;
    int l = 0, changess = 0;
    for(int r = 0; r < A.size(); r++)
    {
        if(A[r] != c) changess++;

        while(changess > m)
        {
            if(A[l] != c) changess--;
            l++;
        }

        maxx = std::max(maxx, r - l + 1);
    }
    return maxx;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int N, Q;
    std::string A;
    std::cin >> N >> A >> Q;

    for(int i = 0; i < Q; ++i)
    {
        int m;
        char c;
        std::cin >> m >> c;
        std::cout << longest(m, c, A) << std::endl;
    }

    return 0;
}
