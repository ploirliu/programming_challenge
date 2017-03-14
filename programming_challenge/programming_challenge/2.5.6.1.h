//poj 3255
#include <cstdio>
#include <queue>
#include <vector>
#include <functional>
using namespace std;

const int INF = 100000005;
const int MAX_N = 5005;
typedef long long ll;
struct edge{ int to, cost; };
typedef pair<ll, int> p;

vector<edge> g[MAX_N];
ll  d1[MAX_N];
ll  d2[MAX_N];
int n;

void dijkstra(){
	fill(d1, d1 + n, INF);
	fill(d2, d2 + n, INF);
	priority_queue<p, vector<p>, greater<p>> q;
	d1[0] = 0;
	q.push(p(0, 0));
	while (!q.empty()){
		p tmp = q.top(); q.pop();
		if (tmp.first > d2[tmp.second]) continue;
		for (int i = 0; i < g[tmp.second].size(); ++i){
			int id = g[tmp.second][i].to;
			ll d = g[tmp.second][i].cost + tmp.first;
			if (d < d1[id]){
				q.push(p(d, id));
				swap(d1[id], d);
			}
			if (d1[id]<d && d < d2[id]){
				q.push(p(d, id));
				d2[id] = d;
			}
		}
	}
	printf("%lld\n", d2[n-1]);
}

int main(){
	int r;
	scanf("%d %d", &n, &r);
	int a, b, d;
	for (int i = 0; i < r; ++i){
		scanf("%d %d %d", &a, &b, &d);
		edge tmp;
		tmp.to = b - 1, tmp.cost = d;
		g[a - 1].push_back(tmp);
		tmp.to = a - 1, tmp.cost = d;
		g[b - 1].push_back(tmp);
	}
	dijkstra();
	return 0;
}














// book's code
int N, R;
vector<edge> G[MAX_N];
int dist[MAX_N];
int dist2[MAX_N];

void solve(){
	priority_queue<P, vector<P>, greater<P>> que;
	fill(dist, dist + N, INF);
	fill(dist2, dist2 + N, INF);
	dist[0] = 0;
	que.push(P(0, 0));
	while (!que.empty()){
		P p = que.top(); que.pop();
		int v = p.second, d = p.first;
		if (dist2[v] < d) continue;
		for (int i = 0; i < G[v].size(); ++i){
			edge &e = G[v][i];
			int d2 = d + e.cost;
			if (dist[e.to]>d2){
				swap(dist[e.to], d2);
				que.push(P(dist[e.to], e.to));
			}
			if (dist2[e.to]>d2 && dist[e.to] < d2){
				dist2[e.to] = d2;
				que.push(P(dist2[e.to], e.to));
			}
		}
	}
	printf("%d\n", dist2[N - 1]);
}