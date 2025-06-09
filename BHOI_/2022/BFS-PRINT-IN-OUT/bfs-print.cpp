#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

int N;
std::vector<std::vector<int>> adj;
std::vector<int> A, idx, vec;
std::vector<bool> visited;

inline bool INDEKS(int a, int b) 
{
    return idx[a] < idx[b];
}

void bfs()
{
    std::queue<int> next;
    next.push(1);
    visited[1] = true;

    while(!next.empty())
    {
        int p = next.front();
        next.pop();
        vec.push_back(p);

        for(int i : adj[p])
        {
            if(!visited[i])
            {
                visited[i] = true;
                next.push(i);
            }
        }
    }
}

int main()
{

    std::ios_base::sync_with_stdio(false);
    std::cin >> N;

    adj.resize(N + 1);
    A.resize(N);
    idx.resize(N + 1);
    visited.resize(N + 1, false);

    for(int i = 1; i < N; i++)
    {
        int t1, t2;
        std::cin >> t1 >> t2;
        adj[t1].push_back(t2);
        adj[t2].push_back(t1);
    }

    for(int i = 0; i < N; i++)
    {
        std::cin >> A[i];
        idx[A[i]] = i;
    }

    for(int i = 1; i <= N; i++)
        std::sort(adj[i].begin(), adj[i].end(), INDEKS);

    bfs();

    bool flag = true;

    if (vec.size() != N)
        flag = false;
    else 
    {
        for(int i = 0; i < N; i++)
        {
            if(vec[i] != A[i])
            {
                flag = false;
                break;
            }
        }
    }

    if(flag)
        std::cout << "DA\n";
    else
        std::cout << "NE\n";

    return 0;
}
