#include <iostream>
#include <algorithm>
#include <functional>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <bitset>
#include <queue>

using namespace std;
#define loop(i,n) for(int i = 0; i < (n); ++i)
#define loops(i,f,n) for(int i = (f); i < (n); ++i)
#define all(v) v.begin(),v.end()
#define show(v) for(int i = 0; i < v.size(); ++i){cout<<i<<": "<<v[i]<<" "<<endl;}
#define enld endl
#define INF 999999999
//----------------------------------------------------
vector<vector<int>> cost(10010, vector<int>(10010, INF));//cost[u][v]がu->vのコスト
vector<int> d(10010, INF);//始点からの最短距離
vector<bool> used(10010, false);//最短距離が確定しているか
int V;
void AddEdge(int u, int v, int c)//u->vのコストがc
{
	cost[u][v] = cost[v][u] = c;
}
void Adjacent_Matrix_Dijkstra(int s) {
	d[s] = 0;
	while (true)
	{
		int v = -1;
		for (int u = 0; u < V; ++u)
		{
			if (!used[u] && (v == -1 || d[u] < d[v])) v = u;
		}
		if (v == -1)break;
		used[v] = true;
		for (int u = 0; u < V; ++u)
		{
			d[u] = min(d[u], d[v] + cost[v][u]);
		}
	}
}
//----------------------------------------------------
int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	int e, r; cin >> V >> e >> r;//v=頂点数,e=辺数,r=始点
	loop(i, e)
	{
	int s, t, d; cin >> s >> t >> d;//s->tのコストがd
	AddEdge(s, t, d);
	}
	Adjacent_Matrix_Dijkstra(r);
	loop(i, V)
	{
	if (d[i] == INF) cout << "INF" << enld;
	else cout << d[i] << endl;
	}
	return 0;
}
