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
const int INF = 1 << 30;
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

#define my_debug
const ll l_INF = (ll)1 << 60;
ll n, m;
int ans(double a, double c,double &out1,double &out2){
	double tmp = a*a - 4.0*c;
	if (tmp < 0)
		return 0;
	out1 = (-a + sqrt(tmp))/2.0;
	out2 = (-a - sqrt(tmp))/2.0;
	return 2;
}

bool decide(ll val){
	ll out = 0;
	double out1 = 0, out2 = 0;
	rep(i, 1, n+1){
		double a = (double)i - (double)100000;
		double c = (double)i*(double)i + (double)i*(double)100000 - (double)val;
		int tmp = ans(a, c, out1, out2);
		if (tmp){
			//out += (min((int)(floor(out1)), n + 1)-max((int)(ceil(out2)), 1)+1);
			ll tmp1 = min((ll)(floor(out1)), (ll)n);
			ll tmp2 = max((ll)(ceil(out2)), (ll)1) ;
			if (tmp1 >= tmp2){
				out += ((ll)tmp1 - (ll)tmp2 + (ll)1);
			}
		}
		//if (tmp == 1 && (floor(out1) == ceil(out1)))
		//	++out;
		//else if (tmp == 2){
		//	out += ((floor(out1))-(ceil(out2)));
		//}
	}
	//cout << val << " " << out << endl;
	if ((ll)out < (ll)m)
		return false;
	return true;
}

void solve(){
	//cout <<"n:"<<n<<" "<< "m:" << m << endl;
	ll lb = -l_INF, ub = l_INF;
	while (ub - lb>1){
		ll mid = (lb + ub) / 2;
		if (decide(mid))
			ub = mid;
		else
			lb = mid;
		//cout << lb << ' ' << ub << endl;
	}
	pll(ub);
}

int main(){
#ifdef my_debug
	freopen("a.in", "r", stdin);
	//freopen("a.out", "w", stdout);
#endif
	int all;
	gint(all);
	rep(i, 0, all){
		getchar();
		getchar();
		gll2(n, m);
		solve();
	}
	return 0;
}