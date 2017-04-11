#include <cstdio>
#include <queue>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <bitset>
#include <cmath>
#include <algorithm>
#include <functional>
using namespace std;
const int INF = 1147483647;
typedef long long ll;

const int MAX_N = 100005;
typedef struct node{
	int cost, t;
	bool operator<(const struct node &right)const{
		double tmp1 = (double)cost / (double)t;
		double tmp2 = (double)right.cost / (double)right.t;
		return tmp1 < tmp2;
	}
}node;

node all[MAX_N];
int n;

void solve(){
	priority_queue<node> q;
	ll out = 0,cost=0;
	for (int i = 0; i < n; ++i){
		q.push(all[i]);
		cost += (ll)all[i].cost;
	}
	while (!q.empty()){
		node p = q.top(); q.pop();
		//cout << p.cost << " " << p.t << endl;
		cost -= (ll)p.cost;
		out += (ll)cost*2*p.t;
		//cout << "out1:" << out << endl;
		//out += (ll)p.cost*p.t;
		//cout << "out2:" << out << endl;
	}
	printf("%lld\n", out);
}

int main(){
	while (scanf("%d", &n) != EOF){
		for (int i = 0; i < n; ++i){
			scanf("%d %d", &all[i].t, &all[i].cost);
		}
		solve();
	}
	return 0;
}