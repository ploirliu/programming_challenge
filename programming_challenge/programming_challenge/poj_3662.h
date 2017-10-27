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

typedef struct r_pair{
	int r_val;
	int a, b;
}r_pair;

bool cmp(const r_pair &a, const r_pair &b){
	if (a.r_val < b.r_val)
		return true;
	return false;
}



const int MAX_N = 1005;
int r[MAX_N][MAX_N];
int n, p, k;
r_pair d[MAX_N];

bool l_max(int a, int b){
	if (a >= b)
		return true;
	return false;
}

bool l_min(int a, int b){
	if (a <= b)
		return true;
	return false;
}

int connect(int a, int b, int val,bool(*func)(int, int)){
	if (a == b)
		return 0;
	int stu[MAX_N];
	memset(stu, -1, sizeof(stu));
	stu[a] = 0;
	queue<int> q;
	q.push(a);
	while (!q.empty()){
		int now = q.front(); q.pop();
		for (int i = 1; i <= n; ++i){
			if (stu[i]<0 && r[now][i]>0 && func(r[now][i],val)){
				stu[i] = stu[now] + 1;
				q.push(i);
			}
		}
		if (stu[b] >= 0)
			break;
	}
	return stu[b];
}


bool decide(int id){
	r_pair &now = d[id];
	r[now.a][now.b] = r[now.b][now.a] = -1;
	bool out = false;
	
	int num = connect(now.a, n,now.r_val,l_max);
	if (num <= k){
		int num = connect(now.b, 0, now.r_val, l_min);
		if (num >= 0){
			out = true;
		}
	}
	
	if (out == false){
		num = connect(now.b, n, now.r_val, l_max);
		if (num <= k){
			int num = connect(now.a, 0, now.r_val, l_min);
			if (num >= 0){
				out = true;
			}
		}
	}

	if (out == false){
		num = connect(now.a, 0, now.r_val, l_max);
		if (num <= k){
			int num = connect(now.b, n, now.r_val, l_min);
			if (num >= 0){
				out = true;
			}
		}
	}

	if (out == false){
		num = connect(now.b, 0, now.r_val, l_max);
		if (num <= k){
			int num = connect(now.a, n, now.r_val, l_min);
			if (num >= 0){
				out = true;
			}
		}
	}


	r[now.a][now.b] = r[now.b][now.a] =now.r_val;
	return out;
}


void solve(){
	sort(d, d + n,cmp);
	int out = -1;
	for (int i = 0; i < n; ++i){
		if (decide(i)){
			out = i;
			break;
		}
	}
	pint(d[out].r_val);
}

int main(){
#ifdef my_debug
	freopen("a.in", "r", stdin);
	//freopen("a.out", "w", stdout);
#endif
	while (gint3(n,p,k) != EOF){
		memset(r, -1, sizeof(r));
		rep(i, 0, p){
			gint3(d[i].a, d[i].b, d[i].r_val);
			r[d[i].a][d[i].b] = r[d[i].b][d[i].a] = d[i].r_val;
		}
		solve();
	}
	return 0;
}