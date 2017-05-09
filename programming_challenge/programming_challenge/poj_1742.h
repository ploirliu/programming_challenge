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

#define my_debu
#define my_sho
const int MAX_N = 105;
const int MAX_M = 100005;

int val[MAX_N];
int num[MAX_N];
bool dp[MAX_M];

int q[MAX_M];
int a = 0, b = 0;

int m, n;

#define id(k,j,i) val[(i)]*(k)+(j)

void solve(){
#ifdef my_show
	show(val, n);
	show(num, n);
#endif
	fill(dp, dp + m + 1, false);
	dp[0] = true;
	int out = 0;
	rep(i, 0, n){
		if (num[i] == 1){
			for (int j = m; j >= val[i]; --j){
				if (!dp[j] && dp[j - val[i]])
					dp[j] = true, ++out;
			}
		}
		else if (num[i] * val[i] >= m){
			rep(j, val[i], m + 1){
				if (!dp[j] && dp[j - val[i]])
					dp[j] = true,++out;
			}
		}
		else
			rep(j, 0, val[i]){
			a = b = 0;
			for (int k = 0, tval = j; tval <= m; ++k, tval += val[i]){
				if (dp[tval])
					q[b++] = k;
				while (a < b && q[a] + num[i] < k){
					++a;
				}
				if (!dp[tval] && a < b){
					dp[tval] = true;
					++out;
				}
				if (a==b)
					a = b = 0;
			}
		}
	}
	//int out = 0;
	//rep(i, 1, m + 1){
	//	if (dp[i])
	//		++out;
	//}
	pint(out);

}

int main(){
#ifdef my_debug
	freopen("a.in", "r", stdin);
#endif
	while (gint2(n, m) != EOF){
		if (n == 0 && m == 0)
			break;
		rep(i, 0, n)
			gint(val[i]);
		rep(i, 0, n)
			gint(num[i]);
		solve();
	}
	return 0;
}