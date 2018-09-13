#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <string>
#include<bitset>

using namespace std;
#define loop(i,n) for(int i = 0; i < (n); ++i)
#define loops(i,f,n) for(int i = (f); i < (n); ++i)
#define all(v) v.begin(),v.end()
#define show(v) for(int i = 0; i < v.size(); ++i){cout<<i<<": "<<v[i]<<" "<<endl;}
#define enld endl
#define INF 9999999999999
//----------------------------------------------------
struct edge { int to, cost; };//�ӂ��L�тĂ��钸�_�A���̒��_�܂ł̃R�X�g
typedef pair<int, int> P;
const int MAX_V;
int V;//���_��
vector<vector<edge>> G(MAX_V, vector<edge>());//�אڃ��X�g
vector<int> d(MAX_V, INF)//���_s����̍ŒZ����
void AddEdge(int u, int v, cost)
{
	G[u].push_back(edge{ v,cost });
	G[v].push_back(edge{ u,cost });
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

	return 0;
}