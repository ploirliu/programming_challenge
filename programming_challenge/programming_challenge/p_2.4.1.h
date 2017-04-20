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

map<int, int> v;
int n, m;

const int MAX_N = 105;
const int MAX_M = 100005;
int value[MAX_N];
int num[MAX_N];
int dp_v[20*MAX_N];
int dp_n[20*MAX_N];
int dp_len;
//bool dp[2][MAX_M];
bool dp[MAX_M];

set<ll> cache;
void show(){
	for (set<ll>::iterator i = cache.begin(); i != cache.end(); ++i){
		cout << *i << " ";
	}
	cout << endl;
}
void dfs(ll now){
	if (now != 0 && now <= (ll)m)
		cache.insert(now);
	if (now > (ll)m)
		return;
	for (int i = 0; i < n; ++i){
		if (num[i]){
			--num[i];
			dfs(now + (ll)value[i]);
			++num[i];
		}
	}
}


void solve(){
	cache.clear();
	dfs(0);
	show();
	printf("%d\n", cache.size());
}

void solve_dp(){
	memset(dp, 0, sizeof(dp));
	//dp[0][0] = true;
	//dp[1][0] = true;
	dp[0] = true;
	for (int i = 0; i < n; ++i){
		//for (int j = 1; j <= num[i]; ++j){
		//	for (int k = m; k >=1; --k){
		//		int tmp = (k - j*value[i]);
		//		if (tmp < 0)
		//			break;
		//		if (dp[tmp])
		//			dp[k] = true;
		//	}
		//}
		for (int k = m; k >= 1; --k){
			for (int j = 1; j <= num[i]; ++j){
				int tmp = (k - j*value[i]);
				if (tmp < 0)
					break;
				if (dp[tmp])
					dp[k] = true;
			}
		}




		//cout << i << endl;
		//for (int k = 0; k <= m; ++k)
		//	cout << dp[k] << ' ';
		//cout << endl;
	}
	int ans = 0;
	for (int i = 1; i <= m; ++i){
		if (dp[i])
			++ans;
	}
	printf("%d\n", ans);
}


void prepare(){
	dp_len = 0;
	for (int i = 0; i < n; ++i){
		int k = 0;
		for (; (num[i] - (1 << k) + 1)>0; ++k);
		--k;
		for (int j = 0; j <= k; ++j){
			if (j < k){
				dp_v[dp_len]=(value[i]);
				dp_n[dp_len]=(1 << j);
			}
			else{
				dp_v[dp_len]=(value[i]);
				dp_n[dp_len]=(num[i] - (1 << j) + 1);
			}
			++dp_len;
		}
	}
}
void solve_01bag(){
	prepare();
	memset(dp, 0, sizeof(dp));
	dp[0] = true;
	for (int i = 0; i < dp_len; ++i){
		for (int j = m; j >= 1; --j){
			int tmp = j - dp_n[i] * dp_v[i];
			if (tmp < 0)
				break;
			else if (dp[tmp])
				dp[j] = true;
		}
		//cout << i << endl;
		//for (int k = 0; k <= m; ++k)
		//	cout << dp[k] << ' ';
		//cout << endl;
	}
	int ans = 0;
	for (int i = 1; i <= m; ++i){
		if (dp[i])
			++ans;
	}
	printf("%d\n", ans);
}


int main(){
	//freopen("a.in", "r", stdin);
	while (scanf("%d %d", &n, &m) != EOF){
		if (m == 0 && n == 0)
			break;
		//v.clear();
		for (int i = 0; i < n; ++i){
			scanf("%d", &value[i]);
		}
		for (int i = 0; i < n; ++i){
			scanf("%d", &num[i]);
		}
		solve_01bag();
	}
	return 0;
}