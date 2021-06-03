#include<bits/stdc++.h>

using namespace std;
#define ll long long

class fxn
{
public:
    bool operator() (const pair<ll, ll> &a, const pair<ll, ll> &b)
    {
        return a.second > b.second;
    }
};

int main()
{
    ll n, m;
    cin>>n>>m;
    vector<vector<pair<ll, ll>>> adj(n+1, vector<pair<ll, ll>> ());

    for(ll i = 0; i < m; i++)
    {
        ll a, b, c;
        cin>>a>>b>>c;
        adj[a].push_back({b,c});
    }

    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, fxn> pq;

    pq.push({1, 0});

    ll dis[n+1];
    for(ll i = 1; i <= n; i++) dis[i] = LONG_LONG_MAX;

    while(!pq.empty())
    {
        pair<ll, ll> cur = pq.top();
        pq.pop();

        if(cur.second > dis[cur.first])
            continue;
        else
            dis[cur.first] = cur.second;
        for(auto &x: adj[cur.first])
        {
            if(dis[x.first] > cur.second + x.second)
            {
                dis[x.first] = cur.second + x.second;
                pq.push({x.first, cur.second + x.second});
            }
        }
    }

    for(ll i = 1; i <= n; i++)
        cout<<dis[i]<<" ";
    cout<<endl;
}
