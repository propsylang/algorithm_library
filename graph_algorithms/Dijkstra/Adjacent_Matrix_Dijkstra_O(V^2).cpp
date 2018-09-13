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
const int MAX_V;
vector<vector<int>> cost(MAX_V, vector<int>(MAX_V, INF));//cost[u][v]は辺e=(u,v)のコスト（存在しない場合はINF）
vector<int> d(MAX_V, INF);//頂点sからの最短距離
vector<bool> used(MAX_V,false);//既に調べたかのフラグ
int V;//頂点数
void Adjacent_Matrix_Dijkstra(int s) {
	d[s] = 0;
	while (true)
	{
		int v = -1;
		for (int u = 0; u < V;++u)
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

	return 0;
}