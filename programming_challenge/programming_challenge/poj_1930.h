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
#define pint2(i,j) printf("%d %d",(i),(j))
#define pint3(i,j,k) printf("%d %d %d",(i),(j),(k))
#define pll(i) printf("%lld\n",(i))
#define pll2(i,j) printf("%lld %lld",(i),(j))
#define pll3(i,j,k) printf("%lld %lld %lld",(i),(j),(k))
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

//#define my_debug



string c;
ll gcd(ll a, ll b){
	if (b == 0)
		return a;
	return gcd(b, a%b);
}
/*
void liu_mid(const ll &a1, const ll &b1, const ll &a2, const ll &b2, ll &out_a, ll &out_b){
	ll tmp1 = gcd(b1, b2);
	out_b = (b1 / tmp1*b2);
	out_a = (out_b / b1*a1 + out_b / b2*a2);
	tmp1 = gcd(out_b, out_a);
	out_b /= tmp1;
	out_a /= tmp1;
	if (out_a % 2 == 0)
		out_a >>= 1;
	else
		out_b <<= 1;
}

string my_divide(ll a, ll b,int t=30){
	stringstream ss;
	ll last = -1;
	ss << "0.";
	bool stu = true;
	while (t){
		ll tmp = (ll)10 * a;
		ss << (tmp / b);
		last = a;
		a = tmp%b;
		if (last == a){
			stu = false;
			break;
		}
		--t;
	}
	if (t & stu){
		ss << '0';
	}
	ss << "...";
	return ss.str();
}

int  liu_cmp(const string &a, const string &b){
	bool first = true;
	int len_a = 0, len_b = 0;
	char a_last = 0, b_last = 0;
	//cout << a <<"|||" << b << endl;
	while (len_a <a.size() && len_b <b.size()){
		//cout << a[len_a] << ' ' << b[len_b] << endl;
		if (a[len_a] == '.' && b[len_b] == '.'){
			if (first){
				first = false;
			}
			else{
				if (a_last == b_last)
					return 0;
				else if (a_last > b_last)
					return 1;
				else
					return -1;
			}
		}
		else if (a[len_a] == '.'){
			if (a_last > b[len_b])
				return 1;
			if (a_last<b[len_b])
				return -1;
			b_last = b[len_b];
		}
		else if (b[len_b] == '.'){
			if (a[len_a]>b_last)
				return 1;
			if (a[len_a] < b_last)
				return -1;
			a_last = a[len_a];
		}
		else{
			if (a[len_a] > b[len_b])
				return 1;
			if (a[len_a] < b[len_b])
				return -1;
			a_last = a[len_a];
			b_last = b[len_b];
		}
		++len_a;
		++len_b;
	}
	if (a_last > b_last)
		return 1;
	if (a_last < b_last)
		return -1;
	while (len_a<a.size()){
		if (a[len_a] > b_last)
			return 1;
		if (a[len_a] < b_last)
			return -1;
		++len_a;
	}
	while (len_b <b.size()){
		if (a_last > b[len_b])
			return 1;
		if (a_last < b[len_b])
			return -1;
		++len_b;
	}
	return 0;
}


void b_search(ll &out_a, ll &out_b, int t = 25){
	ll a1 = 0, b1 = 1, a2 = 1, b2 = 1;
	out_a = 0, out_b = 0;
	while (t){
		liu_mid(a1, b1, a2, b2, out_a, out_b);
		string tmp = my_divide(out_a, out_b);
		int stu = liu_cmp(tmp, c);
		if (stu>0){
			a2 = out_a, b2 = out_b;
		}
		else if (stu < 0){
			a1 = out_a, b1 = out_b;
		}
		else
			break;
		//cout << out_a << ' ' << out_b << ' ' << tmp << endl;
		--t;
	}
}


void step_search(ll &out_a, ll &out_b){
	ll last_a = out_a, last_b = out_b;
	while (1){
		string tmp = my_divide(out_a, out_b);
		int stu = liu_cmp(tmp, c);
		cout << out_a << " " << out_b << " " << tmp << endl;
		if (stu > 0){
			++out_b;
		}
		else if (stu < 0){
			++out_a;
		}
		else
			break;
		//--t;
	}
}



void search(ll &out_a, ll &out_b){
	ll a = 0, b = 1, base = 1;
	while (1){
		if (a + 1 == b){
			a <<= 1;
			b <<= 1;
			base <<= 1;
		}
		else{
			string tmp1 = my_divide(a, base);
			string tmp2 = my_divide(b, base);

		}
	}
}
void handle_str(string &s){
	bool stu = false;
	for (int i = s.size() - 1; i >= 0; --i){
		if (s[i] == '.')
			continue;
		if (s[i] == '9'){
			stu = true;
			s[i] = '0';
		}
		else if (stu){
			++s[i];
			break;
		}
		else
			break;

	}
}

void solve(){
	ll out_a = 0, out_b = 0;
	b_search(out_a, out_b);
	step_search(out_a, out_b);
	ll tmp = gcd(out_a, out_b);
	out_a /= tmp;
	out_b /= tmp;
	printf("%lld/%lld\n", out_a, out_b);
}
*/

void get_num(ll &a, ll &base){
	a = 0;
	base = 1;
	rep(i, 2, c.size() - 3){
		a = a * 10 + (c[i] - '0');
		base = base * 10;
	}
}

void solve(){
	ll a = 0, base = 0;
	get_num(a, base);
	ll out_a = a, out_b = base-1;
	ll tmp = gcd(out_a, out_b);
	out_a /= tmp;
	out_b /= tmp;
	ll b = 10;
	while (b < base){
		ll tmp_a = a - a / (base / b);
		ll tmp_b = base - b;
		tmp = gcd(tmp_a, tmp_b);
		tmp_a /= tmp;
		tmp_b /= tmp;
		if (tmp_b < out_b){
			out_a = tmp_a;
			out_b = tmp_b;
		}
		b *= 10;
	}
	printf("%lld/%lld\n", out_a, out_b);
}


int main(){
#ifdef my_debug
	freopen("a.in", "r", stdin);
#endif
	while (cin >> c){
		//handle_str(c);
		if (c == "0")
			break;
		solve();
	}
	return 0;
}