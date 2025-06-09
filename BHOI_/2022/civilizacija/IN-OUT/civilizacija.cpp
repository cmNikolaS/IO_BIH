#include <iostream>
#include <vector>
#include <cmath>

bool gimmePath(std::vector<int> &path, std::vector<std::vector<int>> adj, int u, int g, std::vector<bool> &visited)
{
    path.push_back(u);
    visited[u] = true;
    if(u == g) return true;
    for(int v : adj[u])
    {
        if(!visited[v])
            if(gimmePath(path, adj, v, g, visited))
                return true;
    }
    path.pop_back();
    return false;
}

int main()
{
    int N, M, K, a, b, c = 0;
    std::cin >> N >> M >> K;
    std::vector<std::vector<int>> adj(N+1);
    std::vector<std::vector<int>> map(N+1, std::vector(N+1, 0));
    std::vector<std::vector<int>> S(N, std::vector<int>());
    std::vector<int> A, B, A1, B1, R;

    for(int i = 0; i < N - 1; i++)
    {
        std::cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        A.push_back(a);
        B.push_back(b);
    }

    for(int i = 0; i < M; i++)
    {
        std::cin >> a;
        for(int j = 0; j < a; j++)
        {
            std::cin >> b;
            S[i].push_back(b);
        }
    }

    for(int i = 0; i < M; i++)
    {
        for(int j = 0; j < S[i].size() - 1; j++)
        {
            std::vector<int> path;
            std::vector<bool> visited(N+1, false);
            gimmePath(path, adj, S[i][j], S[i][j+1], visited);
            for(int k = 0; k < path.size() - 1; k++)
                map[std::min(path[k], path[k+1])][std::max(path[k], path[k+1])]++;
        }
    }
    
    for(int k = 0; k < N - 1; k++)
    {
        int u = std::min(A[k], B[k]);
        int v = std::max(A[k], B[k]);
        if(map[u][v] >= K)
        {
            c++;
            R.push_back(k + 1);
        }
    }


    std::cout << c << std::endl;
    for(int i : R)
            std::cout << i << ' ';
    std::cout << std::endl;

    return 0;
}