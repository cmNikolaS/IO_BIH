#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

typedef long long ll;

int main() 
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n, k, x, y;
    
    std::cin >> n >> k >> x >> y;
    std::vector<ll> A(n);
    
    for(int i = 0; i < n; std::cin >> A[i++]);

    std::vector<ll> pr(n + 1, 0);
    for(int i = 1; i <= n; i++)
        pr[i] = pr[i - 1] + A[i - 1];

    // 2) Min-heap to keep top-k segment sums
    std::priority_queue<ll, std::vector<ll>, std::greater<ll>> minHeap;

    // 3) Iterate over all allowed lengths d in [x, y]
    for(int d = x; d <= y; d++)
    {
        if (d > n) break;
        // Slide over all starting positions i
        for(int i = 0; i + d <= n; i++)
        {
            ll segSum = pr[i + d] - pr[i];
            if((int)minHeap.size() < k)
                minHeap.push(segSum); 
            else if(segSum > minHeap.top())
            {
                minHeap.pop();
                minHeap.push(segSum);
            }
        }
    }

    // 4) Sum up the values in the heap
    ll answer = 0;
    while(!minHeap.empty())
    {
        answer += minHeap.top();
        minHeap.pop();
    }

    std::cout << answer << "\n";
    return 0;
}