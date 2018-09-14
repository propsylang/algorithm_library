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
struct edge { int to, cost; };//辺が伸びている頂点、その頂点までのコスト
typedef pair<int, int> P;//pair<最短距離,頂点番号>
int v;//頂点数
	  //vector<edge> G[100010];//隣接リスト
vector<vector<edge>> G(100010, vector<edge>());
vector<int> d(100010, INF);//頂点sからの最短距離
void AddEdge(int u, int v, int cost)//u->vのコストがcost
{
	edge tmp = { v,cost };
	G[u].push_back(tmp);
}
void Adjacent_List_Dijkstra(int s)
{
	priority_queue<P, vector<P>, greater<P>> que;
	d[s] = 0;
	que.push(P(0, s));

	while (!que.empty())
	{
		P p = que.top(); que.pop();
		int v = p.second;
		if (d[v] < p.first)continue;
		for (int i = 0; i < G[v].size(); ++i)
		{
			edge e = G[v][i];
			if (d[e.to] > d[v] + e.cost)
			{
				d[e.to] = d[v] + e.cost;
				que.push(P(d[e.to], e.to));
			}
		}
	}
}
//----------------------------------------------------
int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	int e, r; cin >> v >> e >> r;//v=頂点数,e=辺数,r=始点
	loop(i, e)
	{
		int s, t, d; cin >> s >> t >> d;//s->tのコストがd
		AddEdge(s, t, d);
	}
	Adjacent_List_Dijkstra(r);
	return 0;
}
