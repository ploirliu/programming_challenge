int n, k
int a[MAX_N]

void solve(){
	int lb = -1, ub = n;
	while (ub - lb > 1){
		int mid = (lb + ub) / 2;
		if (a[mid] >= k)
			ub = mid;
		else
			lb=mid
	}

	printf("%d\n", ub);
}