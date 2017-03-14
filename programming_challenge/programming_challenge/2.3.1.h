#include<stdio.h>
#include <algorithm>
using namespace std;


//////////////////////////////////////////////////////////////////////////
// 01 bag


const int MAX_N = 105;
int n, W;
int w[MAX_N], v[MAX_N];


// force
int rec(int i, int j){
	int res;
	if (i == n){
		res = 0;
	}
	else if (j < w[i]){
		res = rec(i + 1, j);
	}
	else{
		res = max(rec(i + 1, j), rec(i + 1, j - w[i]) + v[i]);
	}
	return res;
}
void solve(){
	printf("%d\n", rec(0, W));
}


// dp1
const int MAX_W = 10005;
int dp[MAX_N + 1][MAX_W + 1];
int rec1(int i, int j){
	if (dp[i][j] >= 0)
		return dp[i][j];
	int res;
	if (i == n)
		res = 0;
	else if (j < w[i]){
		res = rec(i + 1, j);
	}
	else{
		res = max(rec(i + 1, j), rec(i + 1, j - w[i]) + v[i]);
	}
	return dp[i][j] = res;
}
void solve1(){
	memset(dp, -1, sizeof(dp));
	printf("%d\n", rec(0, W));
}


//other ways
int rec_other(int i, int j, int sum){
	int res;
	if (i == n)
		res = sum;
	else if (j < w[i]){
		res = rec_other(i + 1, j, sum);
	}
	else{
		res = max(rec_other(i + 1, j, sum), rec_other(i + 1, j - w[i], sum + v[i]));
	}
	return res;
}


// dp2
void solve2(){
	for (int i = n - 1; i >= 0; --i){
		for (int j = 0; j <= W; ++j){
			if (j < w[i]){
				dp[i][j] = dp[i + 1][j];
			}
			else{
				dp[i][j] = max(dp[i + 1][j], dp[i + 1][j - w[i]] + v[i]);
			}
		}
	}
	printf("%d\n", dp[0][W]);
}

// dp3
void solve3(){
	for (int i = 0; i < n; ++i){
		for (int j = 0; j <= W; ++j){
			if (j < w[i]){
				dp[i + 1][j] = dp[i][j];
			}
			else{
				dp[i + 1][j] = max(dp[i][j], dp[i][j - w[i]] + v[i]);
			}
		}
	}
	printf("%d\n", dp[n][W]);
}


// dp4
void solve4(){
	for (int i = 0; i < n; ++i){
		for (int j = 0; j <= W; ++j){
			dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
			if (j + w[i] <= W){
				dp[i + 1][j + w[i]] = max(dp[i + 1][j + w[i]], dp[i][j] + v[i]);
			}
		}
	}
	printf("%d\n", dp[n][W]);
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////






////////////////////////////////////////////////////////////////////////////////////////////////
//LCS ,Longest Common Subsequence
int n, m;
char s[MAX_N], t[MAX_N];

int dp[MAX_N + 1][MAX_N + 1];

void solve(){
	for (int i = 0; i < n; ++i){
		for (int j = 0; j < m; ++j){
			if (s[i] == t[j]){
				dp[i + 1][j + 1] = dp[i][j] + 1; 
			}
			else{
				dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
			}
		}
	}
	printf("%d\n", dp[n][m]);
}
////////////////////////////////////////////////////////////////////////////////////////////////
