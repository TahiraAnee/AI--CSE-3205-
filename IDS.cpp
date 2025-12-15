#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll N = 102;

vector<ll> graph[N];
ll visited[N];
ll node, edge;
bool found = false;

void DLS(ll u, ll goal, ll limit)
{
    if (found) return;

    if (u == goal)
    {
        cout << u << " ";
        found = true;
        return;
    }

    if (limit == 0)
        return;

    visited[u] = 1;
    cout << u << " ";

    for (auto &v : graph[u])
    {
        if (!visited[v])
        {
            DLS(v, goal, limit - 1);
        }
    }
}

void IDS(ll start, ll goal)
{
    for (ll depth = 0; depth <= node; depth++)
    {
        memset(visited, 0, sizeof(visited));
        cout << "\nDepth Limit " << depth << ": ";

        DLS(start, goal, depth);

        if (found)
        {
            cout << "\nGoal Found at depth " << depth << "\n";
            return;
        }
    }

    cout << "\nGoal not found.\n";
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
        graph[v].push_back(u); 
    }

    ll start, goal;
    cin >> start >> goal;

    IDS(start, goal);

    return 0;
}
