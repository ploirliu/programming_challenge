//poj 3253
#include <stdio.h>
#include <algorithm>
#include <queue>
using namespace std;

//mycode

//#define ll long long
//
//const int MAX_N = 20005;
//int n;
//int all[MAX_N];
//
//struct cmp{
//	bool operator () (const ll &a, const ll &b){
//		if (a > b)return true;
//		else return false;
//	}
//};
//
//
//
//
//ll solve(){
//	priority_queue<ll> q;
//	for (int i = 0; i < n; ++i) q.push(all[i]);
//	ll out = 0;
//	while (q.size()>1){
//		ll tmp = q.top(); q.pop();
//		tmp += q.top(); q.pop();
//		out += tmp;
//		q.push(tmp);
//	}
//	return out;
//}
//
//int main(){
//	scanf("%d", &n);
//	for (int i = 0; i < n; ++i)scanf("%d", &all[i]);
//	printf("%lld\n", solve());
//	return 0;
//}







// book's code
typedef long long ll;
const int MAX_N = 20005;
int N, L[MAX_N];
void b_solve(){
	ll ans = 0;
	while (N > 1){
		int mii1 = 0, mii2 = 1;
		if (L[mii1] > L[mii2]) swap(mii1, mii2);

		for (int i = 2; i < N; ++i){
			if (L[i] < L[mii1]){
				mii2 = mii1;
				mii1 = i;
			}
			else if (L[i] < L[mii2]){
				mii2 = i;
			}
		}
		int t = L[mii1] + L[mii2];
		ans += t;

		if (mii1 == N - 1) swap(mii1, mii2);
		L[mii1] = t;
		L[mii2] = L[N - 1];
		N--;
	}
	printf("%lld\n", ans);
}