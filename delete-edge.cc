#include <bits/stdc++.h>
using namespace std;
const int M = 1e9 + 7;

void dfs(int vertex, int parent, vector<int> graph[], vector<int> &val, vector<int> &subtreesum)
{
    subtreesum[vertex] += val[vertex - 1];
    for (int child : graph[vertex])
        if (child != parent)
        {
            dfs(child, vertex, graph, val, subtreesum);
            subtreesum[vertex] += subtreesum[child];
        }
}

int deleteEdge(vector<int> &val, vector<vector<int>> &graph)
{
    vector<int> subsum(val.size() + 1, 0);
    vector<int> g[val.size() + 1];
    for (auto edge : graph)
    {
        g[edge[0]].push_back(edge[1]);
        g[edge[1]].push_back(edge[0]);
    }

    dfs(1, 0, g, val, subsum);
    long long ans = 0;
    for (int i = 2; i <= val.size(); i++)
    {
        int part1 = subsum[i];
        int part2 = subsum[1] - part1;
        ans = max(ans, (part1 * 1LL * part2) % M);
    }
    return ans;
}

int main()
{
    vector<int> vals = {10, 5, 12, 6};
    vector<vector<int>> g = {{1, 2},
                             {1, 4},
                             {4, 3}};

    int ans = deleteEdge(vals, g);
    cout << "product: " << ans << endl;
}