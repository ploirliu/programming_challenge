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
double all[MAX_N];
bool stu[MAX_N];
int n;

bool getMin(double &num){
	num = INF;
	int id = -1;
	bool out = false;
	for (int i = 0; i < n; ++i){
		if (stu[i]){
			if (all[i] < num){
				num = all[i];
				id = i;
				out = true;
			}
		}
	}
	if (out){
		stu[id] = false;
	}
	return out;
}

bool getMax(double &num){
	num = -INF;
	int id = -1;
	bool out = false;
	for (int i = 0; i < n; ++i){
		if (stu[i]){
			if (all[i] > num){
				num = all[i];
				id = i;
				out = true;
			}
		}
	}
	if (out){
		stu[id] = false;
	}
	return out;
}

void solve(){
	fill(stu, stu + n, true);
	
}

int main(){
	while (scanf("%d", &n) != EOF){
		int tmp;
		for (int i = 0; i < n; ++i){
			scanf("%d", &tmp);
			all[i] = tmp;
		}
		solve();
	}
	return 0;
}