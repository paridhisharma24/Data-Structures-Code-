#include<bits/stdc++.h>

using namespace std;
#define ll long long
class DSU
{
public:
    ll parent[1000] = {0};
    ll rank[1000];

    void make_set(ll v)
    {
        parent[v] = v;
        rank[v] = 0;
    }

    int find_set(ll v)
    {
        if(v == parent[v])
            return parent[v];
        return find_set(parent[v]);
    }

    void make_union(ll a, ll b)
    {
        a = find_set(a);
        b = find_set(b);
        if(a != b)
        {
            if(rank[a] < rank[b])
                swap(a, b);
            parent[b] = a;
            if(rank[a] == rank[b])
                rank[a]++;
        }
    }
};

int main()
{

    cout<<"Enter no of sets :";
    ll n,c=0;
    cin>>n;
    vector<ll> v;
    vector<pair<ll, ll>> ans;
    DSU s;
    for(ll i = 0; i < n; i++)
    {
        ll a, b;
        cin>>a>>b;
        v.push_back(a);
        if(s.parent[a] == 0)
            s.make_set(a);
        if(s.parent[b] == 0)
            s.make_set(b);
        s.make_union(a, b);
    }
    for(ll i = 1; i < v.size(); i++)
    {
        if(s.parent[v[i]] != v[0])
        {
            s.make_union(s.parent[v[i]], v[0]);
            ans.push_back({v[0], v[i]});
            c++;
        }
    }
    cout<<c<<endl;
    for(ll i = 0; i < ans.size(); i++)
        cout<<ans[i].first<<" "<<ans[i].second<<endl;
}
