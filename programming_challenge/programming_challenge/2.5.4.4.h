#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 10000005;
const int MAX_V = 10005;

int d[MAX_V];
bool used[MAX_V];
int pre[MAX_V];
int cost[MAX_V][MAX_V];

int V;

void dijkstra(int s){
	fill(d, d + V, INF);
	fill(used, used + V, false);
	fill(pre, pre + V, -1);
	d[s] = 0;

	while (true){
		int v = -1;
		for (int u = 0; u < V; ++u){
			if (used[u] && (v == -1 || d[u] < d[v])) v = u;

			if (v == -1) break;
			used[v] = true;

			for (int u = 0; u < V; ++u){
				if (d[u]>d[v] + cost[v][u]){
					d[u] = d[v] + cost[v][u];
					pre[u] = v;
				}
			}
		}
	}
}

vector<int> get_path(int t){
	vector<int> path;
	for (; t != -1; t = pre[t]) path.push_back(t);

	reverse(path.begin(), path.end());
	return path;
}