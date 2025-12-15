#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define endl "\n"
#define pb push_back
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(v) (v).begin(),(v).end()
/* Custom hash function for pair<ll, ll>
struct hash_pair {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const {
        return hash<T1>()(p.first) ^ (hash<T2>()(p.second) << 1);
    }
}; */
ll const N=102;

vector<ll>graph[N];
ll heuristic[N];
ll node,edge;
ll visited[N];
ll par[N];
void GBFS(ll st,ll gl)
{
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>pq;

    pq.push({heuristic[st],st});

    cout<<"Traversal Order: ";
    par[st]=-1;

    while(!pq.empty())
    {
        ll tp=pq.top().second;
        pq.pop();

        if(visited[tp]==1)continue;

        visited[tp]=1;
        cout<<tp<<" ";
        if(tp==gl)
        {
            cout<<"\n Goal Reached! ";
            return;
        }else{
            for(auto &u:graph[tp]){
                if(visited[u]==0){
                    pq.push({heuristic[u],u});
                    par[u]=tp;
                }
            }
        }
    }

    cout<<"\nGoal not reachable.\n";
    
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin>>node>>edge;
    for(ll i=0;i<edge;i++)
    {
        ll u,v;
        cin>>u>>v;
        graph[u].pb(v);
        graph[v].pb(u);

    }
    
    for(ll i=1;i<=node;i++){
        cin>>heuristic[i];
    }
    ll start,goal;
    cin>>start>>goal;

    for(ll i=0;i<=node;i++){
        visited[i]=0;
    }
    GBFS(start,goal);
    cout<<"Shortest Path : ";
    while(goal!=-1){
        cout<<goal<<" ";
        goal=par[goal];
    }
    
    cout<<endl;


}
