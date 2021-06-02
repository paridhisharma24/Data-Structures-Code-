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
            queue<ll> q;
            q.push(k);
            ll visited[num] = {0};
            visited[k] = 1;
            ll current;

            cout<<"BFS for key "<<k<<" is: ";
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
                cout<<current<<" ";
            }
            cout<<endl;
        }

        void DFS(ll k)                 
        {
            stack<ll> st;
            st.push(k);
            ll visited[num] = {0};
            ll current;
            visited[k] = 1;

            cout<<"DFS for key "<<k<<" is: ";
            while(!st.empty())
            {
                current = st.top();
                st.pop();

                for(auto x : adj[current])
                {
                    if(visited[x] == 0)
                    {
                        st.push(x);
                        visited[x] = 1;
                    }
                }
                cout<<current<<" ";
            }
            cout<<endl;
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
    g.DFS(0);
    g.BFS(3);
}
