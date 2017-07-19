int N, K;
double L[MAX_N];

bool C(double x){
	int num = 0;
	for (int i = 0; i < N; ++i){
		num += (int)(L[i] / x);
	}
	return num >= K;
}

void solve(){
	double lb = 0, ub = INF;
	for (int i = 0; i < 100; ++i){
		double mid = (lb + ub) / 2;
		if (C(mid)) lb = mid;
		else ub = mid;
	}
	printf("%.2f\n", floor(ub * 100) / 100);
}