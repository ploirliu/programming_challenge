// Dijkstra
#include <cstdio>
#include <algorithm>
using namespace std;

const int MAX_V=1005;
const int INF = 10000005;

int cost[MAX_V][MAX_V];
int d[MAX_V];
bool used[MAX_V];
int V;

void dijkstra(int s){
	fill(d, d + V, INF);
	fill(used, used + V, false);
	d[s] = 0;
	while (true){
		int v = -1;
		for (int u = 0; u < V; ++u){
			if (!used[u] && (v == -1 || d[u] < d[v])) v = u;
		}
		if (v == -1)break;
		used[v] = true;
		for (int u = 0; u < V; ++u){
			d[u] = min(d[u], d[v] + cost[u][v]);
		}
	}
}
















#include <vector>
#include <queue>
#include <functional>
struct edge{ int to, cost; };
typedef pair<int, int>  P;

int V;
vector<edge> G[MAX_V];
int d[MAX_V];
void dijkstra(int s){
	priority_queue<P, vector<P>, greater<P>> que;
	fill(d, d + V, INF);
	d[s] = 0;
	que.push(P(0, s));
	while (!que.empty()){
		P p = que.top(); que.pop();
		int v = p.second;
		if (d[v] < p.first) continue;
		for (int i = 0; i < G[v].size(); ++i){
			edge e = G[v][i];
			if (d[e.to]>d[v] + e.cost){
				d[e.to] = d[v] + e.cost; 
				que.push(P(d[e.to], e.to));
			}
		}
	}
}