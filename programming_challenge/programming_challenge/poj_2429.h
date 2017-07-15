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



/*
class bignum{
public:
bignum(int size = 4):len(size){
}
~bignum(){
}
int size()const{
return len;
}
//int get(int id)const{
//	return num[id];
//}
friend ostream &operator<<(ostream &output, const bignum &b){
bool stu = false;
for (int i = int(b.len - 1); i >= 0; --i){
if (stu)
printf("%09d", b.num[i]);
else if (b.num[i] > 0){
printf("%d", b.num[i]);
stu = true;
}
}
if (stu == false)
printf("0");
return output;
}
const bignum& operator+=(const bignum&right){
int add = 0;
for (int i = 0; i < len; ++i){
int tmp = 0;
if (i < right.size()){
tmp = right.num[i] + num[i] + add;
}
else{
tmp = num[i] + add;
}
num[i] = tmp%gap;
add = tmp / gap;
}
return *this;
}
const bignum& operator=(const bignum&right){
for (int i = 0; i <len; ++i){
num[i] = right.num[i];
}
return *this;
}
void set(int a){
for (int i = 0; i <len; ++i){
num[i] = a%gap;
a /= gap;
}
}
private:
int  num[4];
int len;
static const int gap =1000000000;
};

//int gcd(int a,int b){
//	if(b==0)
//		return a;
//	return gcd(b,a%b);
//}
//
////a*x+b*y=gcd(a,b);
//int extgcd(int a,int b,int &x,int &y){
//	int d=a;
//	if(b!=0){
//		d=extgcd(b,a%b,y,x);
//		y-=(a/b)*x;
//	}
//	else{
//		x=1,y=0;
//	}
//	return d;
//}


//inline int id(int i){
//	return i & 1;
//}
//
//inline int last(int i){
//	return (i - 1) & 1;
//}
//
//void myshow(int i){
//	rep(j, 0, ){
//		cout << dp[id(i)][j] << ' ';
//	}
//	cout << endl;
//}

//int n_stu[MAX_N];
//void n_init(){
//	rep(i, 0, n)
//		n_stu[i] = i;
//}
//int n_getf(int id){
//	if (n_stu[id] != id){
//		n_stu[id] = n_getf(n_stu[id]);
//	}
//	return n_stu[id];
//}
//bool n_same(int i, int j){
//	if (n_getf(i) == n_getf(j))
//		return true;
//	return false;
//}
//void n_union(int i, int j){
//	int fi = n_getf(i), fj = n_getf(j);
//	if (fi != fj){
//		n_stu[fi] = fj;
//	}
//}

*/

#define my_debu


inline ll liu_abs(ll num){
	return num < 0 ? -num:num;
}


ll a, b;
ll gcd(ll a, ll b){
	if (b == 0)
		return a;
	return gcd(b, a%b);
}

ll mul_mod(ll a, ll b, ll mod){
	ll out = 0;
	ll tmp = a%mod;
	while (b){
		if (b & 1){
			out += tmp;
		}
		b >>= 1;
		tmp <<= 1;
		tmp = tmp%mod;
		out = out%mod;
	}
	return out;
}


vector<ll> ans;

ll get_num(ll seed, ll c, ll mod){
	return (mul_mod(seed, seed, mod) + c) % mod;
}




bool pollard_rho(ll n, int t = 5){
	//set<ll> cache;
	//while (time){
	//	ll b1 = 0,a1=0;
	//	do{
	//		a1 = rand()%n;
	//	} while (cache.count(a1) != 0);
	//	while (cache.count(a1) == 0){
	//		cache.insert(a1);
	//		b1 = (mul_mod(a1, a1, n) + 1) % n;
	//		ll p = gcd(abs(b1 - a1), n);
	//		if (p != 1){
	//			if (!pollard_rho(n / p)){
	//				ans.push_back(n / p);
	//			}
	//			if (!pollard_rho(p)){
	//				ans.push_back(p);
	//			}
	//			return true;
	//		}
	//		a1 = b1;
	//	}
	//	--time;
	//}
	//return false;
	srand(t);
	while (t){
		ll seed = rand() % n;
		ll p = 1;
		ll a1, b1;
		a1 = b1 = seed;
		while(1){
			a1 = get_num(a1, p, n), b1 = get_num(get_num(b1, p, n), p, n);
			if (a1 == b1)
				break;
			p = gcd(liu_abs(b1 - a1), n);
			if (p != 1){
				if (!pollard_rho(n / p)){
					ans.push_back(n / p);
				}
				if (!pollard_rho(p)){
					ans.push_back(p);
				}
				return true;
			}
		}
		--t;
	}
	return false;
}

void solve(){
	ll c = b / a;
	ans.clear();
	ll out1 = 1, out2 = c;
	if (pollard_rho(c)){
		sort(ans.begin(), ans.end());
		rep(i, 0, 1 << (ans.size())){
			ll tmp1 = 1;
			rep(j, 0, ans.size()){
				if ((i >> j) & 1){
					tmp1 *= ans[j];
				}
			}
			ll tmp2 = c / tmp1;

			if (gcd(tmp1,tmp2)==1 && (out1 + out2) > (tmp1 + tmp2)){
				out1 = min(tmp1, tmp2);
				out2 = max(tmp1, tmp2);
			}
		}
		pll2((ll)out1*a, (ll)out2*a);
	}
	else{
		pll2(a, b);
	}

}

int main(){
#ifdef my_debug
	freopen("a.in", "r", stdin);
#endif
	while (gll2(a, b) != EOF){
		if (a == b){
			pll2(a, b);
			continue;
		}
		solve();
	}
	return 0;
}