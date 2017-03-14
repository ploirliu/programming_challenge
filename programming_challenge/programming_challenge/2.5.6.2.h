// poj 3723
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>
using namespace std;

struct edge{ int to, cost; };
typedef pair<int, int> P;
typedef long long ll;
const int MAX_NM = 10005;

vector<edge> g[MAX_NM * 2];
int N, M;
bool used[MAX_NM * 2];


const int cost = 10000;

ll min_tree(int id){
	ll out = 0;
	priority_queue<P> q;
	q.push(P(0, id));
	while (!q.empty()){
		P p = q.top(); q.pop();
		if (used[p.second]) continue;
		out += ((ll)cost - (ll)p.first);
		used[p.second] = true;
		for (int i = 0; i < g[p.second].size(); ++i){
			if (!used[g[p.second][i].to]){
				q.push(P(g[p.second][i].cost, g[p.second][i].to));
			}
		}
	}
	return out;
}

void solve(){
	fill(used, used + N + M, false);
	ll ans = 0;
	for (int i = 0; i < N + M; ++i){
		if (!used[i]){
			ans += min_tree(i);
		}
	}
	printf("%lld\n", ans);
}

int main(){
	int k;
	scanf("%d", &k);
	for (int i = 0; i < k; ++i){
		getchar(); 
		int R;
		scanf("%d %d %d", &N, &M, &R);
		for (int j = 0; j < N + M; ++j)
			g[j].clear();
		int x, y, d;
		for (int j = 0; j < R; ++j){
			scanf("%d %d %d", &x, &y, &d);
			edge tmp;tmp.cost = d;
			tmp.to = y + N;
			g[x].push_back(tmp);
			tmp.to = x;
			g[y + N].push_back(tmp);
		}
		solve();
	}
	return 0;
}





// book's code
int N, M, R;
int x[MAX_R], y[MAX_R], d[MAX_R];

void solve(){
	V = N + M;
	E = R;
	for (int i = 0; i < R; ++i){
		es[i] = (edge)(x[i], N + y[i], -d[i]);
	}
	printf("%d\n", 10000 * (N + M) + kruskal());
}