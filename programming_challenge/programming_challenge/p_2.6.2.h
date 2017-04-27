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
const int INF = 1147483647;
typedef long long ll;
typedef pair<int, int> P;
#define rep(i,start,end) for(int i=(start);i<(end);++i)
#define rrep(i,end,start) for(int i=((end)-1);i>=(start);--i)
#define pint(i) printf("%d\n",(i))
#define pint2(i,j) printf("%d %d",(i),(j))
#define pint3(i,j,k) printf("%d %d %d",(i),(j),(k))
#define gint(i) scanf("%d",&(i))
#define gint2(i,j) scanf("%d %d",&(i),&(j))
#define gint3(i,j,k) scanf("%d %d %d",&(i),&(j),&(k))
#define init(tar,val) memset((tar),(val),sizeof((tar)))
#define show(tar,len) for(int i=0;i<(len);++i) \
	cout<<tar[i]<<' ';\
	cout<<endl;




class bignum{
public:
	bignum(int size = 4) :len(size){
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
	static const int gap = 1000000000;
};


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
const int MAX_N = 20005;
const int MAX_C = 100005;
int n, c, f;
P all[MAX_C];
ll a[MAX_C];
ll b[MAX_C];

void init_a(){
	init(a, -1);
	priority_queue<int> p;
	ll tmp = 0;
	rep(i, 0, c){
		if (p.size() < (n/2)){
			tmp += (ll)all[i].second;
			p.push(all[i].second);
		}
		else{
			if (tmp <= (ll)f){
				a[i] = tmp;
			}
			if (p.top() > all[i].second){
				tmp = (ll)tmp - (ll)p.top() + all[i].second;
				p.pop();
				p.push(all[i].second);
			}
		}
	}
}

void init_b(){
	init(b, -1);
	priority_queue<int> p;
	ll tmp = 0;
	rrep(i, c, 0){
		if (p.size() < (n / 2)){
			tmp += (ll)all[i].second;
			p.push(all[i].second);
		}
		else{
			if (tmp <= (ll)f){
				b[i] = tmp;
			}
			if (p.top() > all[i].second){
				tmp = (ll)tmp - (ll)p.top() + all[i].second;
				p.pop();
				p.push(all[i].second);
			}	
		}
	}
}
//#define my_debug 

void solve(){
	
	sort(all, all + c);
	
	if (n == 1){
		int ans = -1;
		rep(i, 0, c){
			if (all[i].second <= f)
				ans = all[i].first;
		}
		pint(ans);
		return;
	}

	init_a();
	init_b();
#ifdef my_debug
	rep(i, 0, c)
		cout << all[i].first << ':' << all[i].second << ' ';
	cout << endl;
	show(a, c);
	show(b, c);
#endif 
	int ans = -1;
	rep(i, 0, c){
		if (a[i] >= 0 && b[i] >= 0 && ((ll)a[i] + (ll)b[i] + (ll)all[i].second) <= f){
			ans = all[i].first;
		}
	}
	pint(ans);
}

int main(){
#ifdef my_debug
	freopen("a.in", "r", stdin);
#endif
	while (gint3(n,c,f) != EOF){
		rep(i, 0, c){
			gint2(all[i].first, all[i].second);
		}
		solve();
	}
	return 0;
}