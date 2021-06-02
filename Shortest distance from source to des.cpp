-#include <bits/stdc++.h>

using namespace std;
#define ll long long

ll visited[1000][1000] = {0};
pair<ll, ll> parent[1000][1000];
string s = "";

ll r, c;
class item
{
  public:
  	ll row;
  	ll col;
  	ll dis;
  	item(ll i, ll j, ll k)
  	{
  		row = i;
  		col = j;
  		dis = k;
	}
}source(0,0,0);


void path(ll i, ll j)
{
	ll x = parent[i][j].first;
	ll y = parent[i][j].second;

	if(x == -1 && y == -1)
		return;

	if(x == i - 1)
	{
		s += "D";
	}
	else if(x == i + 1)
	{
		s += "U";
	}
	else if(y == j + 1)
	{
		s += "L";
	}
	else if(y == j - 1)
	{
		s += "R";
	}
	path(x,y);
}

void BFS(vector<vector<char> > grid)
{
	queue<item> q;
	q.push(source);
	visited[source.row][source.col] = 1;
	int count = 0;
	while(!q.empty())
	{
		item p = q.front();
		q.pop();

		if(grid[p.row][p.col] == 'B')
		{
			cout<<"YES"<<endl;
			cout<<p.dis<<endl;
			count = 1;
			path(p.row, p.col);
		}

		if(p.row - 1 >= 0 && visited[p.row-1][p.col] == 0)
		{
			q.push(item(p.row-1, p.col, p.dis+1));
			visited[p.row-1][p.col] = 1;
			parent[p.row-1][p.col] = {p.row, p.col};
		}

		if(p.row + 1 < r && visited[p.row+1][p.col] == 0)
		{
			q.push(item(p.row+1, p.col, p.dis+1));
			visited[p.row+1][p.col] = 1;
			parent[p.row+1][p.col] = {p.row, p.col};
		}

		if(p.col - 1 >= 0 && visited[p.row][p.col-1] == 0)
		{
			q.push(item(p.row, p.col-1, p.dis+1));
			visited[p.row][p.col-1] = 1;
			parent[p.row][p.col-1] = {p.row, p.col};
		}

		if(p.col + 1 < c && visited[p.row][p.col+1] == 0)
		{
			q.push(item(p.row, p.col+1, p.dis+1));
			visited[p.row][p.col+1] = 1;
			parent[p.row][p.col+1] = {p.row, p.col};
		}
	}
	if(count == 0)
		cout<<"NO";
}

int main()
{
    ll n, m;
    cin>>n>>m;
    r = n;
    c = m;
    vector<vector<char> > grid;

    for(ll i = 0; i < n; i++)
    {
        vector<char> v;
        for(ll j = 0; j < m; j++)
        {
            char x;
            cin>>x;
            if(x == '#')
            	visited[i][j] = 1;

            else if(x == 'A')
        	{
        		parent[i][j] = {-1,-1};
        		source.row = i;
        		source.col = j;
			}
            v.push_back(x);
        }
        grid.push_back(v);
    }

    BFS(grid);
    for(ll i = s.size() - 1; i >= 0; i--)
    	cout<<s[i];
}
