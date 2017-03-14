// poj 3169
#include <cstdio>
#include <vector> 
#include <algorithm>
using namespace std;

struct edge{ int from, to, cost; };
const int MAX_N = 1005;
const int INF = 10000005;
vector<edge> E;
int N;
int d[MAX_N];

void show(){
	for (int i = 0; i < N; ++i){
		printf("%d ", d[i]);
	}
	printf("\n");
}

void solve(){
	fill(d, d + N, INF);
	d[0] = 0;
	bool stu = true;
	for (int k = 0; k < N;++k){
		for (int i = 0; i < E.size(); ++i){
			if (d[E[i].from] != INF && d[E[i].to]>(d[E[i].from] + E[i].cost)){
				d[E[i].to] = d[E[i].from] + E[i].cost;
			}
		}
	}
	int ans = d[N - 1];
    if (d[0] < 0) ans = -1;
	else if (ans == INF) ans = -2;

	printf("%d\n", ans);
}

int main(){
	E.clear();
	int ml, md;
	scanf("%d %d %d", &N, &ml, &md);
	for (int i = 0; i < ml; ++i){
		edge tmp;
		scanf("%d %d %d", &tmp.from, &tmp.to, &tmp.cost);
		--tmp.from; --tmp.to;
		E.push_back(tmp);
	}
	for (int i = 0; i < md; ++i){
		edge tmp;
		scanf("%d %d %d", &tmp.to, &tmp.from, &tmp.cost);
		--tmp.from; --tmp.to;
		tmp.cost = -tmp.cost;
		E.push_back(tmp);
	}
	for (int i = 1; i < N; ++i){
		edge tmp;
		tmp.from = i, tmp.to = i - 1, tmp.cost = 0;
		E.push_back(tmp);
	}
	solve();
	return 0;
}







// book's code
int N, ML, MD;
int AL[MAX_ML], BL[MAX_ML], DL[MAX_ML];
int AD[MAX_MD], BD[MAX_MD], DD[MAX_MD];

int d[MAX_N];

void solve(){
	fill(d, d + N, INF);
	d[0] = 0;
	for (int k = 0; k < N; ++k){
		for (int i = 0; i + 1 < N; ++i){
			if (d[i + 1] < INF) d[i] = min(d[i], d[i + 1]);
		}
		for (int i = 0; i < ML; ++i){
			if (d[AL[i] - 1] < INF){
				d[BL[i] - 1] = min(d[BL[i] - 1], d[AL[i - 1]] + DL[i]);
			}
		}
		for (int i = 0; i < MD; ++i){
			if (d[BD[i] - 1] < INF){
				d[AD[i] - 1] = min(d[AD[i] - 1], d[BD[i] - 1] - DD[i]);
			}
		}
	}

	int res = d[N - 1];
	if (d[0] < 0)
		res = -1;
	else if (res == INF)
		res = -2;

	printf("%d\n", res);
}