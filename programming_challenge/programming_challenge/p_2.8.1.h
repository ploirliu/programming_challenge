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
const int INF = 1000000000;
typedef long long ll;
typedef pair<int, int> P;
#define rep(i,start,end) for(int i=(start);i<(end);++i)
#define pint(i) printf("%d\n",(i))
#define pint2(i,j) printf("%d %d\n",(i),(j))
#define pint3(i,j,k) printf("%d %d %d\n",(i),(j),(k))
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
		for (int i = 0; i < len; ++i){
			num[i] = right.num[i];
		}
		return *this;
	}
	void set(int a){
		for (int i = 0; i < len; ++i){
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


//#define my_debug

const int MAX_NUM = 15;

int n;
int len[MAX_NUM][MAX_NUM];
int stu[MAX_NUM];
set<int> cache;
void myinit(){
	rep(i, 0, MAX_NUM)
		rep(j, 0, MAX_NUM){
		if (i == j)
			len[i][j] = 0;
		else
			len[i][j] = INF;
	}
}


void solve(){
	rep(i, 0, MAX_NUM){
		rep(j, 0, MAX_NUM){
			rep(k, 0, MAX_NUM){
				len[i][j] = min(len[i][j], len[i][k] + len[k][j]);
			}
		}
	}
	int out = INF, t = 0;
	for (int i : cache){
		int tmp = 0;
		for (int j : cache){
			tmp += len[i][j];
		}
		if (tmp < out){
			out = tmp;
			t = i;
		}
	}
	pint2(t, out);
}

int main(){
#ifdef my_debug
	freopen("a.in", "r", stdin);
#endif
	while (gint(n) != EOF){
		if (n == 0)
			break;
		fill(stu, stu + MAX_NUM, INF);
		myinit();
		cache.clear();
		int tmp1, tmp2;
		rep(i, 0, n){
			gint2(tmp1, tmp2);
			int tmp;
			gint(tmp);
			len[tmp2][tmp1] = len[tmp1][tmp2] = tmp;
			cache.insert(tmp1);
			cache.insert(tmp2);
		}
		solve();
	}
	return 0;
}