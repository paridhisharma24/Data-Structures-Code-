#include<bits/stdc++.h>

using namespace std;

#define ll long long
ll visited[100000+1] = {0};

class graph
{
    private:
        vector<vector<ll>> adj;
        ll num;

    public:
        graph(ll n)
        {
            num = n;
            for(ll i = 0; i <= num; i++)
            {
                vector<ll> v;
                adj.push_back(v);
            }
        }
        void add_edge(ll a, ll b)
        {
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        void BFS(ll k)
        {
            queue<ll> q;
            q.push(k);
            visited[k] = 1;
            ll current;

            while(!q.empty())
            {
                current = q.front();
                q.pop();

                for(auto x : adj[current])
                {
                    if(visited[x] == 0)
                    {
                        q.push(x);
                        visited[x] = 1;
                    }
                }
            }
        }
};

int main()
{
    ll n, m, x, a, b;
    cin>>n>>m;
    graph g(n);
    vector<pair<ll, ll>> v;
    for(ll i = 0; i < m; i++)
    {
        cin>>a>>b;
        if(i == 0)
            x = a;
        g.add_edge(a, b);
    }
    ll c = 0;
    g.BFS(x);
    for(ll i = 1; i <= n; i++)
    {

        if(visited[i] == 0)
        {
            g.BFS(i);
            c++;
            v.push_back({x,i});
        }
    }
    cout<<c<<endl;
    for(ll i = 0; i < v.size(); i++)
    {
        cout<<v[i].first<<" "<<v[i].second<<endl;
    }
}
