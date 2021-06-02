#include<bits/stdc++.h>

using namespace std;
#define ll long long

class graph
{
    private:
        vector<vector<ll>> adj;
        ll num;

    public:
        graph(ll n)
        {
            num = n;
            for(ll i = 0; i < num; i++)
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

        void display()
        {
            for(ll i = 0; i < num; i++)
            {
                cout<<"Adj list for node "<<i<<" is ";
                for(auto x : adj[i])
                    cout<<x<<" ";
                cout<<endl;
            }
        }

        void BFS(ll k)                 //k is key to start BFS with
        {
            queue<pair<ll,ll>> q;
            q.push({k, 0});
            ll c = 0, t = 0;
            ll visited[num] = {0};
            visited[k] = 1;
            ll current;

            while(!q.empty())
            {
                current = q.front().first;
                c = q.front().second;
                q.pop();
                t++;
                for(auto x : adj[current])
                {
                    if(visited[x] == 0)
                    {
                        q.push({x, t});
                        visited[x] = 1;
                    }
                }
                cout<<"Distance of "<<current<<" from "<<k<<" is: "<<c<<endl;                
            }
        }
};

int main()
{
    graph g(5);
    g.add_edge(1, 2);
    g.add_edge(1, 4);
    g.add_edge(1, 3);
    g.add_edge(2, 4);
    g.add_edge(2, 0);
    g.add_edge(3, 4);
    g.add_edge(3, 0);
    g.add_edge(0, 4);

    g.display();
    
    g.BFS(3);
}