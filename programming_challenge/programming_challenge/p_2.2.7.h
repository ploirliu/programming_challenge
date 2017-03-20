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

const int MAX_N = 105;
int all[MAX_N];
int n;

void solve(){
	priority_queue<double> q;
	for (int i = 0; i < n; ++i){
		q.push((double)all[i]);
	}
	while (q.size()>1){
		double a = q.top(); q.pop();
		double b = q.top(); q.pop();
		double c = 2.0*sqrt(a*b);
		q.push(c);
	}
	printf("%.3lf", q.top());
}

int main(){
	while (scanf("%d", &n) != EOF){
		for (int i = 0; i < n; ++i){
			scanf("%d", &all[i]);
		}
		solve();
	}
	return 0;
}