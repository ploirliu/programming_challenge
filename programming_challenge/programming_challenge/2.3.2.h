#include<stdio.h>
#include <algorithm>
using namespace std;

const int MAX_N = 105;
const int MAX_W = 10005;

int dp[MAX_N + 1][MAX_W + 1];
int n, W;
int v[MAX_N], w[MAX_N];

void solve(){
	for (int i = 0; i < n; ++i){
		for (int j = 0; j <= W; ++j){
			for (int k = 0; k*w[i] <= j; ++k){
				dp[i + 1][j] = max(dp[i + 1][j], dp[i][j - k*w[i]] + k*v[i]);
			}
		}
	}
	printf("%d\n", dp[n][W]);
}

void sovle2(){
	for (int i = 0; i < n; ++i){
		for (int j = 0; j <= W; ++j){
			if (j < w[i]){
				dp[i + 1][j] = dp[i][j];
			}
			else{
				dp[i + 1][j] = max(dp[i][j], dp[i + 1][j - w[i]] + v[i]);
			}
		}
	}
	printf("%d\n", dp[n][W]);
}


// more good way
// 01 bag
int dp[MAX_W + 1];
void sovle(){
	for (int i = 0; i < n; ++i){
		for (int j = W; j >= w[i]; --j)
			dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
	}
	printf("%d\n", dp[W]);
}
// all bag
int dp[MAX_W + 1];
void solve(){
	for (int i = 0; i < n; ++i){
		for (int j = w[i]; j <= W; ++j){
			dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
		}
	}
	printf("%d\n", dp[W]);
}



// other way
int dp[2][MAX_W + 1];
void solve(){
	for (int i = 0; i < n; ++i){
		for (int j = 0; j <= W; ++j){
			if (j < w[i]){
				dp[(i + 1) & 1][j] = dp[i & 1][j];
			}
			else{
				dp[(i + 1) & 1][j] = max(dp[i & 1][j], dp[(i + 1) & 1][j - w[i]] + v[i]);
			}
		}
	}
	printf("%d\n", dp[n & 1][W]);
}






///////////////////////////////////////////////////////////////////////////////////////////
const int MAX_V = 105;
const int INF = INT_MAX / 2 - 1;
int dp[MAX_N + 1][MAX_N*MAX_V + 1];
void solve(){
	fill(dp[0], dp[0] + MAX_N*MAX_V + 1, INF);
	dp[0][0] = 0;
	for (int i = 0; i < n; ++i){
		for (int j = 0; j <= MAX_N*MAX_V; ++j){
			if (j < v[i]){
				dp[i + 1][j] = dp[i][j];
			}
			else{
				dp[i + 1][j] = min(dp[i][j], dp[i][j - v[i]] + w[i]);
			}
		}
	}
	int res = 0;
	for (int i = 0; i <= MAX_N*MAX_V; ++i) if (dp[n][i] <= W) res = i;
	printf("%d\n", res);
}
///////////////////////////////////////////////////////////////////////////////////////////







/////////////////////////////////////////////////////////////////////////////////////////////
int n, K ;
int a[MAX_N];
int m[MAX_N];

const int MAX_K = 100005;
bool dp[MAX_N + 1][MAX_K + 1];

void solve(){
	dp[0][0] = true;
	for (int i = 0; i < n; ++i){
		for (int j = 0; j <= K; ++j){
			for (int k = 0; k <= m[i] && k*a[i] <= j; ++k){
				dp[i + 1][j] |= dp[i][j - k*a[i]];
			}
		}
	}
	if (dp[n][K]) printf("Yes\n");
	else printf("No\n");
}
/////////////////////////////////////////////////////////////////////////////////////////////







////////////////////////////////////////////////////////////////////////////////////////////////
int dp[MAX_K + 1];

void solve(){
	memset(dp, -1, sizeof(dp));
	dp[0] = 0;
	for (int i = 0; i < n; ++i){
		for (int j = 0; j <= K; ++j){
			if (dp[j] >= 0){
				dp[j] = m[i];
			}
			else if (j < a[i] || dp[j - a[i]] <= 0)
				dp[j] = -1;
			else{
				dp[j] = dp[j - a[i]] - 1;
			}
		}
	}
	if (dp[K] >= 0) printf("Yes\n");
	else printf("No\n");
}
////////////////////////////////////////////////////////////////////////////////////////////////









//////////////////////////////////////////////////////////////////////////////////////////////////
// LIS ,Longest Increasing Subswquence
int n;
int a[MAX_N];
int dp[MAX_N];

// O(n*n)
void solve(){
	int res = 0;
	for (int i = 0; i < n; ++i){
		dp[i] = 1;
		for (int j = 0; j < i; ++j)if (a[j] < a[i]){
			dp[i] = max(dp[i], dp[j] + 1);
		}
		res = max(res, dp[i]);
	}
	printf("%d\n", res);
}

// O(n*logn)
void solve(){
	fill(dp, dp + n, INF);
	for (int i = 0; i < n; ++i){
		*lower_bound(dp, dp + n, a[i]) = a[i];
	}
	printf("%d\n", lower_bound(dp, dp + n, INF) - dp);
}
//////////////////////////////////////////////////////////////////////////////////////////////////





upper_bound(a, a + n, k) - lower_bound(a, a + n, k);