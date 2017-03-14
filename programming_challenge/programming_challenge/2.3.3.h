#include <stdio.h>

//////////////////////////////////////////////////////////////////////
const int MAX_M = 10005;
const int MAX_N = 1005;
int n, m;
int dp[MAX_M + 1][MAX_N + 1];
int M;
void solve(){
	dp[0][0] = 1;
	for (int i = 1; i <= m; ++i){
		for (int j = 0; j <= n; ++j){
			if (j - i >= 0)
				dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % M;
			else{
				dp[i][j] = dp[i - 1][j];
			}
		}
	}
	printf("%d\n", dp[m][n]);
}
//////////////////////////////////////////////////////////////////////







//////////////////////////////////////////////////////////////////////////
int n, m;
int a[MAX_N];
int dp[MAX_N + 1][MAX_M + 1];
void solve(){
	for (int i = 0; i <= n; ++i)
		dp[i][0] = 1;
	for (int i = 0; i < n; ++i){
		for (int j = 1; j <= m; ++j){
			if (j>a[i])
				dp[i + 1][j] = (dp[i + 1][j - 1] + dp[i][j] - dp[i][j - 1 - a[j]] + M) % M;
			else{
				dp[i + 1][j] = (dp[i + 1][j - 1] + dp[i][j]) % M;
			}
		}
	}
	printf("%d\n", dp[n][m]);
}
//////////////////////////////////////////////////////////////////////////