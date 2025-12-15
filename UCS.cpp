#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll N = 102;

vector<pair<ll,ll>> graph[N]; 
ll visited[N];
ll dist[N];
ll node, edge;

void UniformCostSearch(ll st, ll gl)
{
    priority_queue<
        pair<ll,ll>,
        vector<pair<ll,ll>>,
        greater<pair<ll,ll>>
    > pq;

    for(ll i = 1; i <= node; i++)
    {
        dist[i] = LLONG_MAX;
        visited[i] = 0;
    }

    dist[st] = 0;
    pq.push({0, st});

    cout << "Traversal Order: ";

    while(!pq.empty())
    {
        ll u = pq.top().second;
        pq.pop();

        if(visited[u]) continue;
        visited[u] = 1;

        cout << u << " ";

        if(u == gl)
        {
            cout << "\nGoal Reached!\n";
            cout << "Minimum Cost: " << dist[u] << endl;
            return;
        }

        for(auto &edge : graph[u])
        {
            ll v = edge.first;
            ll cost = edge.second;

            if(!visited[v] && dist[u] + cost < dist[v])
            {
                dist[v] = dist[u] + cost;
                pq.push({dist[v], v});
            }
        }
    }

    cout << "\nGoal not reachable.\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> node >> edge;

    for(ll i = 0; i < edge; i++)
    {
        ll u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w}); 
    }

    ll start, goal;
    cin >> start >> goal;

    UniformCostSearch(start, goal);

    return 0;
}
