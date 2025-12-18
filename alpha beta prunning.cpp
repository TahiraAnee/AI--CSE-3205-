#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll alphaBeta(ll depth,ll node,bool ok,vector<ll>&v,ll alpha,ll beta)
{
    if(depth==0)
    {
        return v[node];
    }

    if(ok==false)
    {
        ll best=INT_MIN;

        for(ll i=0;i<2;i++)
        {
            ll val=alphaBeta(depth-1,node*2+i,true,v,alpha,beta);
            best=max(best,val);
            alpha=max(alpha,best);

            if(beta<=alpha)break;
        }
        return best;
    }else{
        ll best=INT_MAX;
        for(ll i=0;i<2;i++)
        {
            ll val=alphaBeta(depth-1,node*2+i,false,v,alpha,beta);
             best=min(best,val);
             beta=min(beta,best);

             if(beta<=alpha)break;


        }
        return best;
    }
}
int main()
{
    ll n;
    cin>>n;
    vector<ll>v(n);
    for(ll i=0;i<n;i++)
    {
        cin>>v[i];

    }
    ll depth=log2(n);
  //  cout<<depth<<endl;
    bool ok=false;
    if(depth%2==0)ok=true;
    ll value = alphaBeta(depth,0,ok,v,INT_MAX,INT_MIN);

    cout<<value<<endl;

}
