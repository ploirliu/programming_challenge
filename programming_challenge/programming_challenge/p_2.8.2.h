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
	cout << tar[i] << ' '; \
	cout << endl;




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


#define my_debug
const int MAX_N = 305;
int len[MAX_N][MAX_N];
int n, m;

void myinit(){
	rep(i, 0, MAX_N){
		rep(j, 0, MAX_N){
			len[i][j] = (i == j ? 0 : INF);
		}
	}
}

void solve(){
	rep(i, 1, n + 1){
		rep(j, 1, n + 1){
			rep(k, 1, n + 1){
				len[i][j] = min(len[i][j], len[i][k] + len[k][j]);
			}
		}
	}
	int out = INF;
	rep(i, 1, n + 1){
		int tmp = 0;
		rep(j, 1, n + 1){
			if (i != j){
				tmp += len[i][j];
			}
		}
		out = min(out, tmp);
	}
	//double tmp = (double)0.5+(double)out * 100 / (n - 1);
	pint(out * 100 / (n-1));
}

int main(){
#ifdef my_debug
	freopen("a.in", "r", stdin);
#endif
	while (gint2(n,m) != EOF){
		myinit();
		rep(i, 0, m){
			int tmp;
			gint(tmp);
			int now[MAX_N];
			rep(j, 0, tmp){
				gint(now[j]);
			}
			rep(j, 0, tmp){
				rep(k, j + 1, tmp){
					len[now[j]][now[k]] = len[now[k]][now[j]] = 1;
				}
			}
		}
		solve();
	}
	return 0;
}