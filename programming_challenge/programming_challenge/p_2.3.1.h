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

const int len = 355;
int n;
int all[len][len];


void solve(){
	for (int i = 0; i < n; ++i){
		for (int j = 0; j <= i; ++j){
			if (i > 0){
				int tmp = all[i-1][j];
				if (j > 0) tmp = max(tmp, all[i - 1][j - 1]);
				all[i][j] = all[i][j] + tmp;
			}
		}
	}
	int out = -1;
	for (int i = 0; i < n; ++i){
		out = max(out, all[n - 1][i]);
	}
	printf("%d\n", out);
}

int main(){
	while (scanf("%d", &n) != EOF){
		for (int i = 0; i < n; ++i){
			for (int j = 0; j <= i; ++j){
				scanf("%d", &all[i][j]);
			}
		}
		solve();
	}
	return 0;
}