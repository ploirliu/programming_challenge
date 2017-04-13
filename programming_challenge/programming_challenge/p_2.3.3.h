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
#include <string.h>

#define myset(T) memset(T,0,sizeof(T))

using namespace std;
const int INF = 1147483647;
typedef long long ll;
const int MAX_T = 1005;
const int MAX_W = 35;
int t, w;
int fall[MAX_T];
int cache[MAX_T][MAX_W];
int time[MAX_T][MAX_W];

inline int now(int j){
	if (j % 2 == 0)
		return 1;
	return 2;
}
void solve(){
	myset(cache);
	myset(time);
	int out = 0;
	for (int i = 1; i <= t; ++i){
		for (int j = 0; j <= i && j<=w; ++j){
			//cache[i][j] = max(cache[i - 1][j] + (fall[i] == myw(j) ? 1 : 0), cache[i - 1][j - 1] + (fall[i] == myw(j) ? 1 : 0));
			if (j == 0){
				cache[i][j] = cache[i - 1][j];
				if (fall[i] == 1)
					++cache[i][j];
			}
			else{
				cache[i][j] = max(cache[i - 1][j], cache[i][j - 1]);
				if (fall[i]==now(j))
					++cache[i][j];
			}
		}
	}
	//for (int i = 0; i <= t; ++i){
	//	for (int j = 0;  j <= w; ++j){
	//		cout << cache[i][j] << ' ';
	//	}
	//	cout << endl;
	//}
	printf("%d\n", cache[t][w]);
}

int main(){
	while (scanf("%d %d",&t,&w) != EOF){
		myset(fall);
		for (int i = 1; i <= t; ++i){
			scanf("%d", &fall[i]);
		}
		solve();
	}
	return 0;
}