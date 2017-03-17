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
using namespace std;
const int INF = 1147483647;

typedef pair<double, double> P;
const int MAX_N = 1005;
P all[MAX_N];
int n,d;

void solve(int t){
	sort(all, all + n);
	int out = 0;
	int id = 0;
	while (id<n){
		++out;
		double end = all[id].second;
		++id;
		while (id < n && all[id].first <= end){
			end = min(end, all[id].second);
			++id;
		}
	}
	printf("Case %d: %d\n", t,out);
}

bool getX(int x, int y,double &begin, double &end){
	double tmp = (double)d*(double)d - (double)y*(double)y;
	if (tmp < 0)
		return false;
	tmp = sqrt((double)tmp);
	begin = (double)x - tmp;
	end = (double)x + tmp;
	return true;
}

int main(){
	int id = 1;
	while (true){
		scanf("%d %d", &n, &d);
		if (n == 0 && d == 0){
			break;
		}
		int x, y;
		bool stu = true;
		if (d < 0)
			stu = false;
		for (int i = 0; i < n; ++i){
			scanf("%d %d", &x, &y);
			stu = stu&getX(x, y, all[i].first, all[i].second);
		}
		if (stu)
			solve(id);
		else{
			printf("Case %d: -1\n", id);
		}
		getchar();
		getchar();
		++id;
	}
	return 0;
}