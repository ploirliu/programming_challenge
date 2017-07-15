#include <cstdio>
#include <queue>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <bitset>
#include <cmath>
#include <algorithm>
#include <functional>
#include <string.h>
using namespace std;
const int INF = 1 << 28;
typedef long long ll;
typedef pair<int, int> P;
#define rep(i,start,end) for(int i=(start);i<(end);++i)
#define pint(i) printf("%d\n",(i))
#define pint2(i,j) printf("%d %d\n",(i),(j))
#define pint3(i,j,k) printf("%d %d %d\n",(i),(j),(k))
#define pll(i) printf("%lld\n",(i))
#define pll2(i,j) printf("%lld %lld\n",(i),(j))
#define pll3(i,j,k) printf("%lld %lld %lld\n",(i),(j),(k))
#define gint(i) scanf("%d",&(i))
#define gint2(i,j) scanf("%d %d",&(i),&(j))
#define gint3(i,j,k) scanf("%d %d %d",&(i),&(j),&(k))
#define gll(i) scanf("%lld",&(i))
#define gll2(i,j) scanf("%lld %lld",&(i),&(j))
#define gll3(i,j,k) scanf("%lld %lld %lld",&(i),&(j),&(k))
#define init(tar,val) memset((tar),(val),sizeof((tar)))
#define show(tar,len) for(int i=0;i<(len);++i) \
	cout<<tar[i]<<' ';\
	cout<<endl;



ll mul_mod(ll a, ll b, ll mod){
	ll out = 0;
	ll tmp = a%mod;
	while (b){
		if (b & 1){
			out += tmp;
}
		tmp <<= 1;
		b >>= 1;
		out %= mod;
		tmp %= mod;
	}
	return out;
}


//a^b%mod;
ll exp_mod(ll a, ll b, ll mod){
	ll tmp = a%mod;
	ll out = 1;
	while (b){
		if (b & 1){
			out = mul_mod(out, tmp, mod);
		}
		b >>= 1;
		tmp = mul_mod(tmp, tmp, mod);
	}
	return out;
}


bool miller_rabin(ll n) {
	if (n == 2 || n == 3 || n == 5 || n == 7 || n == 11)    return true;
	if (n == 1 || !(n % 2) || !(n % 3) || !(n % 5) || !(n % 7) || !(n % 11))    return false;

	ll x, pre, u;
	int i, j, k = 0;
	u = n - 1;

	while (!(u & 1)) {
		k++; u >>= 1;
	}

	for (i = 0; i < 5; ++i) {
		srand((ll)i);
		x = rand() % (n - 2) + 2;
		if ((x%n) == 0)    continue;

		x = exp_mod(x, u, n);
		pre = x;
		for (j = 0; j < k; ++j) {
			x = mul_mod(x, x, n);
			if (x == 1 && pre != 1 && pre != n - 1)    return false;
		}
		if (x != 1)    return false;
	}
	return true;
}
ll get_num(ll seed, ll c, ll mod){
	return (mul_mod(seed, seed, mod) + c) % mod;
}
ll gcd(ll a, ll b){
	if (b == 0)
		return a;
	return gcd(b, a%b);
}

inline ll liu_abs(ll num){
	return num < 0 ? -num : num;
}
bool pollard_rho(ll n, int t = 4){

	srand(t);
	while (t){
		ll seed = rand() % n;
		ll p = 1;
		ll a1, b1;
		a1 = b1 = seed;
		while (1){
			a1 = get_num(a1, p, n), b1 = get_num(get_num(b1, p, n), p, n);
			if (a1 == b1)
				break;
			p = gcd(liu_abs(b1 - a1), n);
			if (p != 1){
				return true;
			}
		}
		--t;
	}
	return false;
}

int main(){
#ifdef my_debug
	freopen("a.in", "r", stdin);
#endif
	for (ll i = 3; i < (ll)100; ++i){
		bool p = pollard_rho(i);
		bool m = miller_rabin(i);
		if (p == m)
			cout << i << ' ' << p << endl;

	}
	return 0;
}