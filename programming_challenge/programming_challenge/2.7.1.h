typedef long long ll;
int n;
int V1[MAX_N], V2[MAX_N];

void solve(){
	sort(V1, V1 + n);
	sort(V2, V2 + n);
	ll ans = 0;
	for (int i = 0; i < n; ++i) ans += (ll)V1[i] * V2[n - i - 1];
	printf("%lld\n", ans);
}