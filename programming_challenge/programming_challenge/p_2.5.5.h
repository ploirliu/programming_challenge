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


inline int id(int i){
	return i & 1;
}

inline int last(int i){
	return (i - 1) & 1;
}


typedef struct node{
	int a, b;
}node;

const int MAX_N = 105;
const int MAX_V = 1005 * 2 * MAX_N;

node all[MAX_N];
int dp[2][MAX_V];
int n;
//void myshow(int i){
//	rep(j, 0, ){
//		cout << dp[id(i)][j] << ' ';
//	}
//	cout << endl;
//}


inline int id_j(int j){
	return j + MAX_V/2;
}
inline bool id_bool(int j){
	j += MAX_V/2;
	if (j<0)
		return false;
	if (j >= MAX_V)
		return false;
	return true;
}
void myshow(int i){
	for (int j =0; j <MAX_V; ++j){
		if (dp[id(i)][j]>-INF)
			cout << j-MAX_V/2 << ':' << dp[id(i)][j] << ' ';
	}
	cout << endl;
}

void myinit(){
	rep(i, 0, 2){
		rep(j, 0, MAX_V)
			dp[i][j] = -INF;
	}
}

void solve(){
	myinit();
	dp[0][id_j(0)] = dp[1][id_j(0)] = 0;
	rep(i, 0, n){
		for (int j = MAX_V/2-1; j >-MAX_V/2; --j){
			dp[id(i)][id_j(j)] = dp[last(i)][id_j(j)];
			if (id_bool(j - all[i].a) && dp[last(i)][id_j(j - all[i].a)] > -INF){
				dp[id(i)][id_j(j)] = max(dp[id(i)][id_j(j)], dp[last(i)][id_j(j - all[i].a)] + all[i].b);
			}
		}
		//myshow(i);
	}
	int out = 0;
	rep(j, id_j(0), MAX_V){
		if (dp[id(n-1)][j] >= 0){
			out = max(out,  j-MAX_V/2+ dp[id(n-1)][j]);
		}
	}
	printf("%d\n", out);
}

int main(){
	//freopen("a.in", "r", stdin);
	while (gint(n) != EOF){
		rep(i, 0, n){
			gint(all[i].a);
			gint(all[i].b);
			//all[i].a += 1000;
			//all[i].a += 1000;
		}
		solve();
	}
	return 0;
}