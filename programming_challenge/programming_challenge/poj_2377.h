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

#define my_debu
const int MAX_N = 1005;
const int MAX_M = 20005;
typedef pair<int, P> node;
node all[MAX_M];
int n, m;

int n_stu[MAX_N];
void n_init(int len){
	rep(i, 0, len)
		n_stu[i] = i;
}
int n_getf(int id){
	if (n_stu[id] != id){
		n_stu[id] = n_getf(n_stu[id]);
	}
	return n_stu[id];
}
bool n_same(int i, int j){
	if (n_getf(i) == n_getf(j))
		return true;
	return false;
}
void n_union(int i, int j){
	int fi = n_getf(i), fj = n_getf(j);
	if (fi != fj){
		n_stu[fi] = fj;
	}
}

bool connect(){
	int f1 = n_getf(1);
	rep(i, 2, n + 1){
		int tmp = n_getf(i);
		if (tmp != f1)
			return false;
	}
	return true;
}
void solve(){
	sort(all, all + m, greater<node>());
	n_init(n+1);
	ll out = 0;
	rep(i, 0, m){
		int a = all[i].second.first, b = all[i].second.second;
		if (n_same(a, b))
			continue;
		out += (ll)all[i].first;
		n_union(a, b);
	}
	if (connect())
		cout << out << endl;
	else
		cout << "-1" << endl;
}

int main(){
#ifdef my_debug
	freopen("a.in", "r", stdin);
#endif
	while (gint2(n,m) != EOF){
		rep(i, 0, m){
			gint3(all[i].second.first, all[i].second.second, all[i].first);
		}
		solve();
	}
	return 0;
}