#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MAXN = 102;

vector<ll> graph[MAXN];
bool visited[MAXN];
bool found;
ll node, edge;

void DLS(ll u, ll goal, ll limit)
{
    if (found) return;

    cout << u << " ";

    if (u == goal)
    {
        found = true;
        return;
    }

    if (limit == 0)
        return;

    visited[u] = true;

    for (auto v : graph[u])
    {
        if (!visited[v])
        {
            DLS(v, goal, limit - 1);
        }
    }

    visited[u] = false; // backtrack
}

void IDS(ll start, ll goal)
{
    for (ll depth = 0; depth <= node; depth++)
    {
        memset(visited, false, sizeof(visited));
        found = false;

        cout << "\nDepth Limit " << depth << ": ";

        DLS(start, goal, depth);

        if (found)
        {
            cout << "\nGoal Found at depth " << depth << "\n";
            return;
        }
    }

    cout << "\nGoal not found\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> node >> edge;

    for (ll i = 0; i < edge; i++)
    {
        ll u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u); // undirected
    }

    ll start, goal;
    cin >> start >> goal;

    IDS(start, goal);

    return 0;
}
