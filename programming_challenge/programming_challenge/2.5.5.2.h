#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX_V = 1005;
const int INF = 1000005;

struct edge{ int u, v, cost; };

bool comp(const edge &e1, const edge &e2){
	return e1.cost < e2.cost;
}

edge es[MAX_E];
int V, E;

int krushkal(){
	sort(es, es + E, comp);
	init_union_find(V);
	int res = 0;
	for (int i = 0; i < E; ++i){
		edge e = es[i];
		for (!same(e.u, e.v)){
			unite(e.u, e.v);
			res += cost;
		}
	}
	return res;
}