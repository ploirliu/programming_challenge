int N, M;
int x[MAX_N];

bool C(int d){
	int last = 0;
	for (int i = 1; i < M; ++i){
		int crt = last + 1;
		while (crt < N && x[crt] - x[last] < d){
			++crt;
		}
		if (crt == N)return false;
		last = crt;
	}
	return true;
}

void solve(){
	sort(x, x + N);
	int lb = 0, ub = INF;
	while (ub - lb > 1){
		int mid = (ub + lb) / 2;
		if (C(mid)) lb = mid;
		else ub = mid;
	}
	printf("%d\n", lb);
}