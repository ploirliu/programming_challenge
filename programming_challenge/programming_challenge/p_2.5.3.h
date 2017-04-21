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
#define rep(i,start,end) for(int i=(start);i<(end);++i)
#define pint(i) printf("%d\n",(i))
#define gint(i) scanf("%d",&(i))
#define init(tar,val) memset((tar),(val),sizeof((tar)))
#define show(tar,len) for(int i=0;i<(len);++i) \
	cout<<tar[i]<<' ';\
	cout<<endl;

template<class T>
bool cmpless(const T &a, const T &b){
	return a < b;
}

template<class T>
bool cmpbigger(const T &a, const T &b){
	return a > b;
}



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

const int MAX_N = 2005;
int all[MAX_N];// , b[MAX_N], c[MAX_N];
int stu[MAX_N];
int last[MAX_N];
int n;

typedef bool(*pf)(const int&,const int&);

bool cmp1(const int &a,const int &b){
	int tmpa = a < 0 ? INF : all[a];
	int tmpb = b < 0 ? INF : all[b];
	return cmpless(tmpa,tmpb);
}

bool cmp2(const int &a, const int &b){
	int tmpa = a < 0 ? INF : all[a];
	int tmpb = b < 0 ? INF : all[b];
	return cmpbigger(tmpa, tmpb);
}

int compute(pf p){
	//sort(b, b + n, p);
	//init(dp, 0);
	init(stu, -1);
	for (int i = 0; i < n; ++i){
		int *id = upper_bound(stu, stu + n, i);

	}
	return 0;
}

void solve(){
	int ans = INF;
	ans = min(ans, compute(cmp1));
	ans = min(ans, compute(cmp2));
	printf("%d\n", ans);
}

int main(){
	freopen("a.in", "r", stdin);
	while (gint(n)!= EOF){
		rep(i, 0, n){
			gint(all[i]);
			//b[i] = a[i];
		}
		solve();
	}
	return 0;
}