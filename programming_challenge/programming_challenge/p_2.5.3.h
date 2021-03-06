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

const int MAX_N = 2005;
int all[MAX_N];// , b[MAX_N], c[MAX_N];
int stu[MAX_N];
int dp[2][MAX_N];
int n;

inline int id(int i){
	return i & 1;
}

inline int last(int i){
	return (i - 1) & 1;
}

void myshow(int i){
	rep(j, 0, n)
		cout << dp[id(i)][j] << ' ';
	cout << endl;
}
//int cmp(std::function<bool(int,int)> f){
//	rep(i, 0, n)
//		stu[i] = all[i];
//	sort(stu, stu + n, f);
//	//show(stu, n);
//	rep(j, 0, n){
//		dp[id(0)][j] = abs(all[0] - stu[j]);
//	}
//	//myshow(0);
//	rep(i, 1, n){
//		dp[id(i)][0] = dp[last(i)][0];
//		rep(j, 1, n){
//			dp[id(i)][j] = min(dp[last(i)][j], dp[id(i)][j - 1]);
//		}
//		rep(j, 0, n)
//			dp[id(i)][j] = dp[id(i)][j] + abs(all[i] - stu[j]);
//		//myshow(i);
//	}
//	int out = dp[id(n-1)][0];
//	rep(i, 1, n)
//		out = min(dp[id(n - 1)][i],out);
//	return out;
//}

int cmp1(){
	rep(i, 0, n)
		stu[i] = all[i];
	sort(stu, stu + n);
	//show(stu, n);
	rep(j, 0, n){
		dp[id(0)][j] = abs(all[0] - stu[j]);
	}
	//myshow(0);
	rep(i, 1, n){
		dp[id(i)][0] = dp[last(i)][0];
		rep(j, 1, n){
			dp[id(i)][j] = min(dp[last(i)][j], dp[id(i)][j - 1]);
		}
		rep(j, 0, n)
			dp[id(i)][j] = dp[id(i)][j] + abs(all[i] - stu[j]);
		//myshow(i);
	}
	int out = dp[id(n - 1)][0];
	rep(i, 1, n)
		out = min(dp[id(n - 1)][i], out);
	return out;
}


//int force(int id){
//	int out = 0;
//	rep(i, id+1, n){
//		if (all[i] < all[i - 1]){
//			rep(j, id, i - 1){
//				return min()
//			}
//		}
//	}
//}


void solve(){
	//int ans = min(cmp(std::less<int>()), cmp(std::greater<int>()));
	//show(all, n);
	int ans = cmp1();
	printf("%d\n", ans);
}

int main(){
	//freopen("a.in", "r", stdin);
	while (gint(n)!= EOF){
		rep(i, 0, n){
			gint(all[i]);
			//b[i] = a[i];
		}
		solve();
	}
	return 0;
}