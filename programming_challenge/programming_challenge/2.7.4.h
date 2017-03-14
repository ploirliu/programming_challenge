#include <cstdio>
#include <algorithm>
using namespace std;

// book's code
int M, X;
double P;

double dp[2][(1 << MAX_M) + 1];
void solve(){
	int n = 1 < M;
	double *prv = dp[0], *next = dp[1];
	memset(prv, 0, sizeof(double)*(n + 1));
	prv[n] = 1.0;

	for (int r = 0; r < M; ++r){
		for (int i = 0; i <= n; ++i){
			int jub = min(i, n - 1);
			double t = 0.0;
			for (int j = 0; j <= jub; ++j){
				t = max(t, P*prv[i + j] + (1 - p)*prv[i - j]);
			}
			nxt[i] = t;
		}
		swap(prv, nxt);
	}
	int i = (ll)X*n / 1000000;
	printf("%.6f\n", prv[i]);
}