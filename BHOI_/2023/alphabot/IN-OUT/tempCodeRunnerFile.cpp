#include <iostream>
#include <string>

int longest(int m, char c, std::string A)
{
    int r = 0, t = 0, t1 = 0, t2 = 0;
    for(int i = 0; i < A.size(); i++)
    {
        if(A[i] == c)
        {
            t++;
            if(t1 != 0)
            {
                r = std::max(r, t2 + t1);
            }
            t2 = 0;
            t1 = 0;
        }
        else
        {
            t2 = t;
            t = 0;
            t1++;
        }
        if(t1 > m)
        {
            t1--;
        }
    }

    return r;
}

int main()
{
    int N, Q;
    std::string A;
    std::cin >> N >> A >> Q;

    for(int i = 0; i < Q; i++)
    {
        int m;
        char c;
        std::cin >> m >> c;
        std::cout << longest(m, c, A) << std::endl;
    }

    return 0;
}