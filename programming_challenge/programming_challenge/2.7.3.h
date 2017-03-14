#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX_P = 10005;
const int MAX_Q = 105;
const int INF = 1000000005;

int p, q;
int r[MAX_Q];
int c[MAX_P][MAX_P];

int dp(int start, int end){
	if (start > end)
		return 0;
	if (c[start][end] >= 0)
		return c[start][end];
	int out = INF;
	for (int i = 0; i < q; ++i){
		if (r[i] >= start && r[i] <= end){
			int tmp = dp(start, r[i] - 1) + dp(r[i] + 1, end) + end - start;
			//printf("%d\n", tmp);
			out = min(out,  tmp);
		}
	}
	if (out == INF)
		c[start][end] = 0;
	else
		c[start][end] = out;
	return c[start][end];
}





void solve(int id){
	memset(c, -1, sizeof(c));
	dp(1, p);
	printf("Case #%d: %d\n",id, c[1][p]);
}

int dp2[MAX_Q][MAX_Q];

void solve2(int id){
	r[0] = 0; r[q + 1] = p+1;
	for (int i = 0; i <= q; ++i){
		dp2[i][i + 1] = 0;
	}
	for (int w = 2; w <= (q + 1); ++w){
		for (int i = 0; (i + w) <= (q + 1); ++i){
			int tmp = INF;
			for (int j = i + 1; j < (i + w); ++j){
				tmp = min(tmp, dp2[i][j] + dp2[j][i + w]);
			}
			dp2[i][i + w] = tmp + r[i + w] - r[i] - 2;
		}
	}
	//for (int i = 0; i <= (q + 1); ++i){
	//	for (int j = 0; j <= (q + 1); ++j){
	//		printf("%d ", dp[i][j]);
	//	}
	//	printf("\n");
	//}
	printf("Case #%d: %d\n", id, dp2[0][q+1]);
}


int main(){
	freopen("my.out", "w", stdout);
	int n;
	scanf("%d\n", &n);
	for (int i = 0; i < n; ++i){
		scanf("%d %d", &p, &q);
		for (int j = 1; j <= q; ++j){
			scanf("%d", &r[j]);
		}
		solve2(i + 1);
	}
	return 0;
}



















// book's code
int P, Q, A[MAX_Q + 2];
int dp[MAX_Q + 1][MAX_Q + 2];

void solve(){
	A[0] = 0;
	A[Q + 1] = P + 1;

	for (int q = 0; q <= Q; ++q){
		dp[q][q + 1] = 0;
	}

	for (int w = 2; w <= (Q + 1); ++w){
		for (int i = 0; (i + 1) <= (Q + 1); ++i){
			int j = i + w, t = INT_MAX;
			for (int k = i + 1; k < j; ++k){
				t = min(t, dp[i][k] + dp[k][j]);
			}
			dp[i][j] = t + A[j] - A[i] - 2;
		}
	}
	printf("%d\n", dp[0][Q + 1]);
}