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
using namespace std;
const int INF = 1147483647;
typedef long long ll;

const int MAX_T = 1005;
const int MAX_A = MAX_T*105;

int f[MAX_T];
int out[2][MAX_A];
const int mod = 1000000;
int t, a, s, b;
void show(int id){
	for (int j = 0; j <= a; ++j){
		cout << out[id][j] << ' ';
	}
		cout << endl;
}
void solve(){
	memset(out, 0, sizeof(out));
	out[0][0] = out[1][0] = 1;
	for (int i = 1; i <= t; ++i){
		for (int j = 1; j <= a; ++j){
			if (j <= f[i]){
				out[i&1][j] = out[i&1][j-1]+out[(i - 1)&1][j];
			}
			else{
				out[i&1][j] = out[(i - 1)&1][j] - out[(i - 1)&1][j - 1 - f[i]] + out[i&1][j-1];
			}
			out[i&1][j] = (out[i&1][j]+mod) % mod;
		}
		//cout << "i:" << i << ",num:"<<f[i]<<endl;
		//show(i&1);
	}
	int ans = 0;
	for (int i = s; i <= b; ++i){
		ans += out[t&1][i];
		ans = ans%mod;
	}
	printf("%d\n", ans);
}

int main(){
	//freopen("a.in", "r", stdin);
	while (scanf("%d %d %d %d", &t,&a,&s,&b) != EOF){
		memset(f, 0, sizeof(f));
		int tmp;
		for (int i = 0; i < a; ++i){
			scanf("%d", &tmp);
			++f[tmp];
		}
		solve();
	}
	return 0;
}