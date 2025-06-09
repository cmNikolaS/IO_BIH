#include <iostream>
#include <vector>

std::vector<int> prefix_function(const std::vector<int>& v)
{
    std::vector<int> pi(v.size(), 0);
    for(int i = 1; i < v.size(); i++)
    {
        int j = pi[i - 1];
        while(j > 0 && v[i] != v[j])
            j = pi[j - 1];
        if(v[i] == v[j]) j++;
        pi[i] = j;
    }
    return pi;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, M;
    std::cin >> N >> M;

    std::vector<int> A(N), B(M);
    for(int i = 0; i < N; i++)
        std::cin >> A[i];
    for(int i = 0; i < M; i++)
        std::cin >> B[i];

    if(M == 1)
    {
        std::cout << N << '\n';
        return 0;
    }

    std::vector<int> diffA(N - 1), diffB(M - 1);
    for(int i = 0; i < N - 1; i++)
        diffA[i] = A[i + 1] - A[i];
    for(int i = 0; i < M - 1; i++)
        diffB[i] = B[i + 1] - B[i];

    std::vector<int> combined = diffB;
    combined.push_back(1e9 + 5);//ovo je da ih razdvoji
    for(int x : diffA)
        combined.push_back(x);

    std::vector<int> pi = prefix_function(combined);

    int result = 0;
    for(int i = M; i < pi.size(); i++)
    {
        if(pi[i] == M - 1)
            ++result;
    }

    std::cout << result << '\n';
    return 0;
}
