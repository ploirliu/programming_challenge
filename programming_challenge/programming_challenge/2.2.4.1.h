//poj 3069
#include<stdio.h>
#include <algorithm>
using namespace std;

//mycode
int r, n;
const int MAX_N = 1005;
int all[MAX_N];

int solve(){
	sort(all, all + n);
	int id = 0;
	int out = 0;
	int now = -1;
	while (id < n){
		now = all[id] + r;
		while (id < n && all[id] <= now)++id;
		++out;
		if (id == n)break;
		--id;
		now = all[id] + r;
		while (id < n && all[id] <= now)++id;
	}
	return out;
}

// book's code
int N, R;
int X[MAX_N];
void b_solve(){
	sort(X, X + N);
	int i = 0, ans = 0;
	while (i < N){
		int s = X[i++];
		while (i < N && X[i] <= s + R)++i;
		
		int p = X[i - 1];
		while (i < N && X[i] <= p + R)++i;

		++ans;
	}
	printf("%d\n", ans);
}

int main(){
	while (true){
		scanf("%d %d", &r, &n);
		if (r == -1 && n == -1)
			break;
		for (int i = 0; i < n; ++i)
			scanf("%d", &all[i]);
		printf("%d\n",solve());
	}
	return 0;
}