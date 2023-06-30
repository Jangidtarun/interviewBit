#include <bits/stdc++.h>
using namespace std;

bool dfs(vector<int> g[], int vertex, int parent, bool vis[])
{
    vis[vertex] = true;
    bool loopexist = false;
    for (int child : g[vertex])
    {
        if (vis[child] and child == parent)
            continue;
        if (vis[child])
            return true;
        loopexist |= dfs(g, child, vertex, vis);
    }
    return loopexist;
}

int solve(int v, vector<vector<int>> &g)
{
    bool vis[v + 10];
    vector<int> graph[v + 10];
    for (int i = 0; i <= v; i++)
        vis[i] = false;
    for (auto edge : g)
    {
        int v1, v2;
        v1 = edge[0];
        v2 = edge[1];
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }

    for (int i = 1; i <= v; i++)
    {
        if (!vis[i])
        {
            if (dfs(graph, i, 0, vis))
                return 1;
        }
    }
    return 0;
}

int main()
{
    int v, e;
    // v = 8, e = 5;
    cin >> v >> e;
    // vector<vector<int>> g = {{1, 2},
    //                          {2, 3},
    //                          {2, 4},
    //                          {3, 5},
    //                          {6, 7}};
    vector<vector<int>> g;
    for (int i = 0; i < e; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        vector<int> tmp = {v1, v2};
        g.push_back(tmp);
    }

    int ans = solve(v, g);
    if (ans)
        cout << "yes\n";
    else
        cout << "no\n";
}